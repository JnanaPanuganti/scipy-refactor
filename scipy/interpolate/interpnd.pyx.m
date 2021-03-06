"""
Simple N-D interpolation

.. versionadded:: 0.9

"""
#
# Copyright (C)  Pauli Virtanen, 2010.
#
# Distributed under the same BSD license as Scipy.
#

#
# Note: this file should be run through the Mako template engine before
#       feeding it to Cython.
#
#       Run ``generate_qhull.py`` to regenerate the ``qhull.c`` file
#

import numpy as np
cimport numpy as np

import scipy.spatial.qhull as qhull
cimport scipy.spatial.qhull as qhull

cimport cython

import warnings

#------------------------------------------------------------------------------
# Numpy etc.
#------------------------------------------------------------------------------

cdef extern from "stdlib.h":
    void *malloc(int size) nogil
    void free(void *ptr) nogil

cdef extern from "math.h":
    double sqrt(double x) nogil
    double fabs(double a) nogil

from numpy cimport NPY_MAXDIMS

#------------------------------------------------------------------------------
# Interpolator base class
#------------------------------------------------------------------------------

class NDInterpolatorBase(object):
    """
    Common routines for interpolators.

    .. versionadded:: 0.9

    """

    def __init__(self, points, values, fill_value=np.nan, ndim=None):
        """
        Check shape of points and values arrays, and reshape values to
        (npoints, nvalues).  Ensure the `points` and values arrays are
        C-contiguous, and of correct type.
        """
        points = _ndim_coords_from_arrays(points)
        values = np.ascontiguousarray(values)

        self._check_init_shape(points, values, ndim=ndim)

        points = np.ascontiguousarray(points.astype(np.double))

        self.values_shape = values.shape[1:]
        if values.ndim == 1:
            self.values = values[:,None]
        elif values.ndim == 2:
            self.values = values
        else:
            self.values = values.reshape(values.shape[0],
                                         np.prod(values.shape[1:]))

        # Complex or real?
        self.is_complex = np.issubdtype(self.values.dtype, np.complexfloating)
        if self.is_complex:
            self.values = self.values.astype(np.complex)
            self.fill_value = complex(fill_value)
        else:
            self.values = self.values.astype(np.double)
            self.fill_value = float(fill_value)

        self.points = points

    def _check_init_shape(self, points, values, ndim=None):
        """
        Check shape of points and values arrays

        """
        if values.shape[0] != points.shape[0]:
            raise ValueError("different number of values and points")
        if points.ndim != 2:
            raise ValueError("invalid shape for input data points")
        if points.shape[1] < 2:
            raise ValueError("input data must be at least 2-D")
        if ndim is not None and points.shape[1] != ndim:
            raise ValueError("this mode of interpolation available only for "
                             "%-D data" % ndim)

    def _check_call_shape(self, xi):
        xi = np.asanyarray(xi)
        if xi.shape[-1] != self.points.shape[1]:
            raise ValueError("number of dimensions in xi does not match x")
        return xi

    def __call__(self, *args):
        """
        interpolator(xi)

        Evaluate interpolator at given points.

        Parameters
        ----------
        xi : ndarray of float, shape (..., ndim)
            Points where to interpolate data at.

        """
        xi = _ndim_coords_from_arrays(args)
        xi = self._check_call_shape(xi)
        xi = np.ascontiguousarray(xi.astype(np.double))
        shape = xi.shape
        xi = xi.reshape(np.prod(shape[:-1]), shape[-1])

        if self.is_complex:
            r = self._evaluate_complex(xi)
        else:
            r = self._evaluate_double(xi)

        return r.reshape(shape[:-1] + self.values_shape)

def _ndim_coords_from_arrays(points):
    """
    Convert a tuple of coordinate arrays to a (..., ndim)-shaped array.

    """
    if isinstance(points, tuple) and len(points) == 1:
        # handle argument tuple
        points = points[0]
    if isinstance(points, tuple):
        p = np.broadcast_arrays(*points)
        for j in xrange(1, len(p)):
            if p[j].shape != p[0].shape:
                raise ValueError("coordinate arrays do not have the same shape")
        points = np.empty(p[0].shape + (len(points),), dtype=float)
        for j, item in enumerate(p):
            points[...,j] = item
    else:
        points = np.asanyarray(points)
        if points.ndim == 1:
            points = points.reshape(-1, 1)
    return points

#------------------------------------------------------------------------------
# Linear interpolation in N-D
#------------------------------------------------------------------------------

class LinearNDInterpolator(NDInterpolatorBase):
    """
    LinearNDInterpolator(points, values)

    Piecewise linear interpolant in N dimensions. 

    .. versionadded:: 0.9

    Parameters
    ----------
    points : ndarray of floats, shape (npoints, ndims)
        Data point coordinates.
    values : ndarray of float or complex, shape (npoints, ...)
        Data values.
    fill_value : float, optional
        Value used to fill in for requested points outside of the
        convex hull of the input points.  If not provided, then
        the default is ``nan``.

    Notes
    -----
    The interpolant is constructed by triangulating the input data
    with Qhull [Qhull]_, and on each triangle performing linear
    barycentric interpolation.

    References
    ----------
    .. [Qhull] http://www.qhull.org/

    """

    def __init__(self, points, values, fill_value=np.nan):
        NDInterpolatorBase.__init__(self, points, values, fill_value=fill_value)
        self.tri = qhull.Delaunay(self.points)

% for DTYPE, CDTYPE in zip(["double", "complex"], ["double", "double complex"]):
    @cython.boundscheck(False)
    def _evaluate_${DTYPE}(self, np.ndarray[np.double_t, ndim=2] xi):
        cdef np.ndarray[np.${DTYPE}_t, ndim=2] values = self.values
        cdef np.ndarray[np.${DTYPE}_t, ndim=2] out
        cdef np.ndarray[np.double_t, ndim=2] points = self.points
        cdef np.ndarray[np.npy_int, ndim=2] vertices = self.tri.vertices
        cdef double c[NPY_MAXDIMS]
        cdef ${CDTYPE} fill_value
        cdef int i, j, k, m, ndim, isimplex, inside, start, nvalues
        cdef qhull.DelaunayInfo_t *info

        ndim = xi.shape[1]
        start = 0
        fill_value = self.fill_value

        info = qhull._get_delaunay_info(self.tri, 1, 0)

        out = np.zeros((xi.shape[0], self.values.shape[1]), dtype=np.${DTYPE})
        nvalues = out.shape[1]

        eps = np.finfo(np.double).eps * 100

        with nogil:
            for i in xrange(np.PyArray_DIMS(xi)[0]):

                # 1) Find the simplex

                isimplex = qhull._find_simplex(info, c,
                                               (<double*>np.PyArray_DATA(xi)) + i*ndim,
                                               &start, eps)

                # 2) Linear barycentric interpolation

                if isimplex == -1:
                    # don't extrapolate
                    for k in xrange(nvalues):
% if DTYPE == "double":
                        out[i,k] = fill_value
% else:
                        out[i,k].real = fill_value.real
                        out[i,k].imag = fill_value.imag
% endif
                    continue

                for k in xrange(nvalues):
% if DTYPE == "double":
                    out[i,k] = 0
% else:
                    out[i,k].real = 0
                    out[i,k].imag = 0
% endif

                for j in xrange(ndim+1):
                    for k in xrange(nvalues):
                        m = vertices[isimplex,j]
% if DTYPE == "double":
                        out[i,k] += c[j] * values[m,k]
% else:
                        out[i,k].real += c[j] * values[m, k].real
                        out[i,k].imag += c[j] * values[m, k].imag
% endif

        free(<void*>info)
        return out
% endfor


#------------------------------------------------------------------------------
# Gradient estimation in 2D
#------------------------------------------------------------------------------

class GradientEstimationWarning(Warning):
    pass

@cython.cdivision(True)
cdef int _estimate_gradients_2d_global(qhull.DelaunayInfo_t *d, double *data,
                                       int maxiter, double tol,
                                       double *y) nogil:
    """
    Estimate gradients of a function at the vertices of a 2d triangulation.

    Parameters
    ----------
    info : input
        Triangulation in 2D
    data : input
        Function values at the vertices
    maxiter : input
        Maximum number of Gauss-Seidel iterations
    tol : input
        Absolute / relative stop tolerance
    y : output, shape (npoints, 2)
        Derivatives [F_x, F_y] at the vertices

    Returns
    -------
    num_iterations
        Number of iterations if converged, 0 if maxiter reached
        without convergence

    Notes
    -----
    This routine uses a re-implementation of the global approximate
    curvature minimization algorithm described in [Nielson83] and [Renka84].

    References
    ----------
    .. [Nielson83] G. Nielson,
       ''A method for interpolating scattered data based upon a minimum norm
       network''.
       Math. Comp., 40, 253 (1983).
    .. [Renka84] R. J. Renka and A. K. Cline.
       ''A Triangle-based C1 interpolation method.'',
       Rocky Mountain J. Math., 14, 223 (1984).

    """
    cdef double Q[2*2]
    cdef double s[2], r[2]
    cdef int ipoint, iiter, k
    cdef qhull.RidgeIter2D_t it
    cdef double f1, f2, df2, ex, ey, L, L3, det, err, change

    # initialize
    for ipoint in xrange(2*d.npoints):
        y[ipoint] = 0

    #
    # Main point:
    #
    #    Z = sum_T sum_{E in T} int_E |W''|^2 = min!
    #
    # where W'' is the second derivative of the Clough-Tocher
    # interpolant to the direction of the edge E in triangle T.
    #
    # The minimization is done iteratively: for each vertex V,
    # the sum
    #
    #    Z_V = sum_{E connected to V} int_E |W''|^2
    #
    # is minimized separately, using existing values at other V.
    #
    # Since the interpolant can be written as
    #
    #     W(x) = f(x) + w(x)^T y
    #
    # where y = [ F_x(V); F_y(V) ], it is clear that the solution to
    # the local problem is is given as a solution of the 2x2 matrix
    # equation.
    #
    # Here, we use the Clough-Tocher interpolant, which restricted to
    # a single edge is
    #
    #     w(x) = (1 - x)**3   * f1
    #          + x*(1 - x)**2 * (df1 + 3*f1)
    #          + x**2*(1 - x) * (df2 + 3*f2)
    #          + x**3         * f2
    #
    # where f1, f2 are values at the vertices, and df1 and df2 are
    # derivatives along the edge (away from the vertices).
    #
    # As a consequence, one finds
    #
    #     L^3 int_{E} |W''|^2 = y^T A y + 2 B y + C
    #
    # with
    #
    #     A   = [4, -2; -2, 4]
    #     B   = [6*(f1 - f2), 6*(f2 - f1)]
    #     y   = [df1, df2]
    #     L   = length of edge E
    #
    # and C is not needed for minimization. Since df1 = dF1.E, df2 = -dF2.E,
    # with dF1 = [F_x(V_1), F_y(V_1)], and the edge vector E = V2 - V1,
    # we have
    #
    #     Z_V = dF1^T Q dF1 + 2 s.dF1 + const.
    #
    # which is minimized by
    #
    #     dF1 = -Q^{-1} s
    #
    # where
    #
    #     Q = sum_E [A_11 E E^T]/L_E^3 = 4 sum_E [E E^T]/L_E^3
    #     s = sum_E [ B_1 + A_21 df2] E /L_E^3
    #       = sum_E [ 6*(f1 - f2) + 2*(E.dF2)] E / L_E^3
    #

    # Gauss-Seidel
    for iiter in xrange(maxiter):
        err = 0
        for ipoint in xrange(d.npoints):
            for k in xrange(2*2):
                Q[k] = 0
            for k in xrange(2):
                s[k] = 0

            # walk over neighbours of given point
            qhull._RidgeIter2D_init(&it, d, ipoint)

            while it.index != -1:
                # edge
                ex = d.points[2*it.vertex2 + 0] - d.points[2*it.vertex + 0]
                ey = d.points[2*it.vertex2 + 1] - d.points[2*it.vertex + 1]
                L = sqrt(ex**2 + ey**2)
                L3 = L*L*L

                # data at vertices
                f1 = data[it.vertex]
                f2 = data[it.vertex2]

                # scaled gradient projections on the edge
                df2 = -ex*y[it.vertex2*2 + 0] - ey*y[it.vertex2*2 + 1]

                # edge sum
                Q[0] += 4*ex*ex / L3
                Q[1] += 4*ex*ey / L3
                Q[3] += 4*ey*ey / L3

                s[0] += (6*(f1 - f2) - 2*df2) * ex / L3
                s[1] += (6*(f1 - f2) - 2*df2) * ey / L3

                # next edge
                qhull._RidgeIter2D_next(&it)

            Q[2] = Q[1]

            # solve

            det = Q[0]*Q[3] - Q[1]*Q[2]
            r[0] = ( Q[3]*s[0] - Q[1]*s[1])/det
            r[1] = (-Q[2]*s[0] + Q[0]*s[1])/det

            change = max(fabs(y[it.vertex*2 + 0] + r[0]),
                         fabs(y[it.vertex*2 + 1] + r[1]))
            
            y[it.vertex*2 + 0] = -r[0]
            y[it.vertex*2 + 1] = -r[1]

            # relative/absolute error
            change /= max(1.0, max(fabs(r[0]), fabs(r[1])))
            err = max(err, change)

        if err < tol:
            return iiter + 1

    # Didn't converge before maxiter
    return 0

def estimate_gradients_2d_global(tri, y, maxiter=400, tol=1e-6):
    cdef np.ndarray[np.double_t, ndim=2] data
    cdef np.ndarray[np.double_t, ndim=3] grad
    cdef qhull.DelaunayInfo_t *info
    cdef int k, ret, nvalues

    y = np.asanyarray(y)

    if y.shape[0] != tri.npoints:
        raise ValueError("'y' has a wrong number of items")

    if np.issubdtype(y.dtype, np.complexfloating):
        rg = estimate_gradients_2d_global(tri, y.real, maxiter=maxiter, tol=tol)
        ig = estimate_gradients_2d_global(tri, y.imag, maxiter=maxiter, tol=tol)
        r = np.zeros(rg.shape, dtype=complex)
        r.real = rg
        r.imag = ig
        return r

    y_shape = y.shape

    if y.ndim == 1:
        y = y[:,None]

    y = y.reshape(tri.npoints, -1).T
    y = np.ascontiguousarray(y).astype(np.double)
    yi = np.empty((y.shape[0], y.shape[1], 2))

    data = y
    grad = yi

    info = qhull._get_delaunay_info(tri, 0, 1)
    nvalues = data.shape[0]

    for k in xrange(nvalues):
        with nogil:
            ret = _estimate_gradients_2d_global(
                info,
                <double*>np.PyArray_DATA(data) + info.npoints*k,
                maxiter,
                tol,
                <double*>np.PyArray_DATA(grad) + 2*info.npoints*k)

        if ret == 0:
            warnings.warn("Gradient estimation did not converge, "
                          "the results may be inaccurate",
                          GradientEstimationWarning)

    free(info)
    return yi.transpose(1, 0, 2).reshape(y_shape + (2,))


#------------------------------------------------------------------------------
# Cubic interpolation in 2D
#------------------------------------------------------------------------------


% for DTYPE, CDTYPE in zip(["double", "complex"], ["double", "double complex"]):

@cython.cdivision(True)
cdef ${CDTYPE} _clough_tocher_2d_single_${DTYPE}(qhull.DelaunayInfo_t *d,
                                                 int isimplex,
                                                 double *b,
                                                 ${CDTYPE} *f,
                                                 ${CDTYPE} *df) nogil:
    """
    Evaluate Clough-Tocher interpolant on a 2D triangle.

    Parameters
    ----------
    d
        Delaunay info
    isimplex
        Triangle to evaluate on
    b : shape (3,)
        Barycentric coordinates of the point on the triangle
    f : shape (3,)
        Function values at vertices
    df : shape (3, 2)
        Gradient values at vertices

    Returns
    -------
    w
        Value of the interpolant at the given point

    References
    ----------
    .. [CT] See, for example,
       P. Alfeld,
       ''A trivariate Clough-Tocher scheme for tetrahedral data''.
       Computer Aided Geometric Design, 1, 169 (1984);
       G. Farin,
       ''Triangular Bernstein-Bezier patches''.
       Computer Aided Geometric Design, 3, 83 (1986).

    """
    cdef ${CDTYPE} \
         c3000, c0300, c0030, c0003, \
         c2100, c2010, c2001, c0210, c0201, c0021, \
         c1200, c1020, c1002, c0120, c0102, c0012, \
         c1101, c1011, c0111
    cdef ${CDTYPE} \
         f1, f2, f3, df12, df13, df21, df23, df31, df32
    cdef double \
         g1, g2, g3
    cdef double \
         e12x, e12y, e23x, e23y, e31x, e31y, \
         e14x, e14y, e24x, e24y, e34x, e34y
    cdef ${CDTYPE} w
    cdef double minval
    cdef double b1, b2, b3, b4
    cdef int k, itri
    cdef double c[3]
    cdef double y[2]

    # XXX: optimize + refactor this!

    e12x = (+ d.points[0 + 2*d.vertices[3*isimplex + 1]]
            - d.points[0 + 2*d.vertices[3*isimplex + 0]])
    e12y = (+ d.points[1 + 2*d.vertices[3*isimplex + 1]]
            - d.points[1 + 2*d.vertices[3*isimplex + 0]])

    e23x = (+ d.points[0 + 2*d.vertices[3*isimplex + 2]]
            - d.points[0 + 2*d.vertices[3*isimplex + 1]])
    e23y = (+ d.points[1 + 2*d.vertices[3*isimplex + 2]]
            - d.points[1 + 2*d.vertices[3*isimplex + 1]])

    e31x = (+ d.points[0 + 2*d.vertices[3*isimplex + 0]]
            - d.points[0 + 2*d.vertices[3*isimplex + 2]])
    e31y = (+ d.points[1 + 2*d.vertices[3*isimplex + 0]]
            - d.points[1 + 2*d.vertices[3*isimplex + 2]])

    e14x = (e12x - e31x)/3
    e14y = (e12y - e31y)/3

    e24x = (-e12x + e23x)/3
    e24y = (-e12y + e23y)/3

    e34x = (e31x - e23x)/3
    e34y = (e31y - e23y)/3

    f1 = f[0]
    f2 = f[1]
    f3 = f[2]

    df12 = +(df[2*0+0]*e12x + df[2*0+1]*e12y)
    df21 = -(df[2*1+0]*e12x + df[2*1+1]*e12y)
    df23 = +(df[2*1+0]*e23x + df[2*1+1]*e23y)
    df32 = -(df[2*2+0]*e23x + df[2*2+1]*e23y)
    df31 = +(df[2*2+0]*e31x + df[2*2+1]*e31y)
    df13 = -(df[2*0+0]*e31x + df[2*0+1]*e31y)

    c3000 = f1
    c2100 = (df12 + 3*c3000)/3
    c2010 = (df13 + 3*c3000)/3
    c0300 = f2
    c1200 = (df21 + 3*c0300)/3
    c0210 = (df23 + 3*c0300)/3
    c0030 = f3
    c1020 = (df31 + 3*c0030)/3
    c0120 = (df32 + 3*c0030)/3

    c2001 = (c2100 + c2010 + c3000)/3
    c0201 = (c1200 + c0300 + c0210)/3
    c0021 = (c1020 + c0120 + c0030)/3

    #
    # Now, we need to impose the condition that the gradient of the spline
    # to some direction `w` is a linear function along the edge.
    #
    # As long as two neighbouring triangles agree on the choice of the
    # direction `w`, this ensures global C1 differentiability.
    # Otherwise, the choice of the direction is arbitrary (except that
    # it should not point along the edge, of course).
    #
    # In [CT]_, it is suggested to pick `w` as the normal of the edge.
    # This choice is given by the formulas
    #
    #    w_12 = E_24 + g1 * E_23
    #    w_23 = E_34 + g2 * E_31
    #    w_31 = E_14 + g3 * E_12
    #
    #    g1 = -(e24x*e23x + e24y*e23y) / (e23x**2 + e23y**2)
    #    g2 = -(e34x*e31x + e34y*e31y) / (e31x**2 + e31y**2)
    #    g3 = -(e14x*e12x + e14y*e12y) / (e12x**2 + e12y**2)
    #
    # However, this choice gives an interpolant that is *not*
    # invariant under affine transforms. This has some bad
    # consequences: for a very narrow triangle, the spline can
    # develops huge oscillations. For instance, with the input data
    #
    #     [(0, 0), (0, 1), (eps, eps)],   eps = 0.01
    #     F  = [0, 0, 1]
    #     dF = [(0,0), (0,0), (0,0)]
    #
    # one observes that as eps -> 0, the absolute maximum value of the
    # interpolant approaches infinity.
    #
    # So below, we aim to pick affine invariant `g1`, `g2`, `g3`.
    # We choose
    #
    #     w = V_4' - V_4
    #
    # where V_4 is the centroid of the current triangle, and V_4' the
    # centroid of the neighbour. Since this quantity transforms similarly
    # as the gradient under affine transforms, the resulting interpolant
    # is affine-invariant. Moreover, two neighbouring triangles clearly
    # always agree on the choice of `w` (sign is unimportant), and so
    # this choice also makes the interpolant C1.
    #
    # The drawback here is a performance penalty, since we need to
    # peek into neighbouring triangles.
    #

    for k in xrange(3):
        itri = d.neighbors[3*isimplex + k]

        if itri == -1:
            # No neighbour.
            # Compute derivative to the centroid direction (e_12 + e_13)/2.
            if k == 0:
                g1 = -2./3
            elif k == 1:
                g2 = -2./3
            elif k == 2:
                g3 = -2./3
            continue

        # Centroid of the neighbour, in our local barycentric coordinates

        y[0] = (+ d.points[0 + 2*d.vertices[3*itri + 0]]
                + d.points[0 + 2*d.vertices[3*itri + 1]]
                + d.points[0 + 2*d.vertices[3*itri + 2]]) / 3

        y[1] = (+ d.points[1 + 2*d.vertices[3*itri + 0]]
                + d.points[1 + 2*d.vertices[3*itri + 1]]
                + d.points[1 + 2*d.vertices[3*itri + 2]]) / 3

        qhull._barycentric_coordinates(2, d.transform + isimplex*2*3, y, c)

        # Rewrite V_4'-V_4 = const*[(V_4-V_2) + g_i*(V_3 - V_2)]

        # Now, observe that the results can be written *in terms of
        # barycentric coordinates*. Barycentric coordinates stay
        # invariant under affine transformations, so we can directly
        # conclude that the choice below is affine-invariant.

        if k == 0:
            g1 = (2*c[2] + c[1] - 1) / (2 - 3*c[2] - 3*c[1])
        elif k == 1:
            g2 = (2*c[0] + c[2] - 1) / (2 - 3*c[0] - 3*c[2])
        elif k == 2:
            g3 = (2*c[1] + c[0] - 1) / (2 - 3*c[1] - 3*c[0])

    c0111 = (g1*(-c0300 + 3*c0210 - 3*c0120 + c0030)
             + (-c0300 + 2*c0210 - c0120 + c0021 + c0201))/2
    c1011 = (g2*(-c0030 + 3*c1020 - 3*c2010 + c3000)
             + (-c0030 + 2*c1020 - c2010 + c2001 + c0021))/2
    c1101 = (g3*(-c3000 + 3*c2100 - 3*c1200 + c0300)
             + (-c3000 + 2*c2100 - c1200 + c2001 + c0201))/2

    c1002 = (c1101 + c1011 + c2001)/3
    c0102 = (c1101 + c0111 + c0201)/3
    c0012 = (c1011 + c0111 + c0021)/3

    c0003 = (c1002 + c0102 + c0012)/3

    # extended barycentric coordinates
    minval = b[0]
    for k in xrange(3):
        if b[k] < minval:
            minval = b[k]

    b1 = b[0] - minval
    b2 = b[1] - minval
    b3 = b[2] - minval
    b4 = 3*minval

    # evaluate the polynomial -- the stupid and ugly way to do it,
    # one of the 4 coordinates is in fact zero
    w = (b1**3*c3000 + 3*b1**2*b2*c2100 + 3*b1**2*b3*c2010 +
         3*b1**2*b4*c2001 + 3*b1*b2**2*c1200 +
         6*b1*b2*b4*c1101 + 3*b1*b3**2*c1020 + 6*b1*b3*b4*c1011 +
         3*b1*b4**2*c1002 + b2**3*c0300 + 3*b2**2*b3*c0210 +
         3*b2**2*b4*c0201 + 3*b2*b3**2*c0120 + 6*b2*b3*b4*c0111 +
         3*b2*b4**2*c0102 + b3**3*c0030 + 3*b3**2*b4*c0021 +
         3*b3*b4**2*c0012 + b4**3*c0003)

    return w

% endfor

class CloughTocher2DInterpolator(NDInterpolatorBase):
    """
    CloughTocher2DInterpolator(points, values, tol=1e-6)

    Piecewise cubic, C1 smooth, curvature-minimizing interpolant in 2D. 

    .. versionadded:: 0.9

    Parameters
    ----------
    points : ndarray of floats, shape (npoints, ndims)
        Data point coordinates.
    values : ndarray of float or complex, shape (npoints, ...)
        Data values.
    fill_value : float, optional
        Value used to fill in for requested points outside of the
        convex hull of the input points.  If not provided, then
        the default is ``nan``.
    tol : float, optional
        Absolute/relative tolerance for gradient estimation.
    maxiter : int, optional
        Maximum number of iterations in gradient estimation.

    Notes
    -----
    The interpolant is constructed by triangulating the input data
    with Qhull [Qhull]_, and constructing a piecewise cubic
    interpolating Bezier polynomial on each triangle, using a
    Clough-Tocher scheme [CT]_.  The interpolant is guaranteed to be
    continuously differentiable.

    The gradients of the interpolant are chosen so that the curvature
    of the interpolating surface is approximatively minimized. The
    gradients necessary for this are estimated using the global
    algorithm described in [Nielson83,Renka84]_.

    References
    ----------

    .. [Qhull] http://www.qhull.org/

    .. [CT] See, for example,
       P. Alfeld,
       ''A trivariate Clough-Tocher scheme for tetrahedral data''.
       Computer Aided Geometric Design, 1, 169 (1984);
       G. Farin,
       ''Triangular Bernstein-Bezier patches''.
       Computer Aided Geometric Design, 3, 83 (1986).

    .. [Nielson83] G. Nielson,
       ''A method for interpolating scattered data based upon a minimum norm
       network''.
       Math. Comp., 40, 253 (1983).

    .. [Renka84] R. J. Renka and A. K. Cline.
       ''A Triangle-based C1 interpolation method.'',
       Rocky Mountain J. Math., 14, 223 (1984).

    """

    def __init__(self, points, values, fill_value=np.nan,
                 tol=1e-6, maxiter=400):
        NDInterpolatorBase.__init__(self, points, values, ndim=2,
                                    fill_value=fill_value)
        self.tri = qhull.Delaunay(self.points)
        self.grad = estimate_gradients_2d_global(self.tri, self.values,
                                                 tol=tol, maxiter=maxiter)

% for DTYPE, CDTYPE in zip(["double", "complex"], ["double", "double complex"]):

    @cython.boundscheck(False)
    def _evaluate_${DTYPE}(self, np.ndarray[np.double_t, ndim=2] xi):
        cdef np.ndarray[np.${DTYPE}_t, ndim=2] values = self.values
        cdef np.ndarray[np.${DTYPE}_t, ndim=3] grad = self.grad
        cdef np.ndarray[np.${DTYPE}_t, ndim=2] out
        cdef np.ndarray[np.double_t, ndim=2] points = self.points
        cdef np.ndarray[np.npy_int, ndim=2] vertices = self.tri.vertices
        cdef double c[NPY_MAXDIMS]
        cdef ${CDTYPE} f[NPY_MAXDIMS+1]
        cdef ${CDTYPE} df[2*NPY_MAXDIMS+2]
        cdef ${CDTYPE} w
        cdef ${CDTYPE} fill_value
        cdef int i, j, k, m, ndim, isimplex, inside, start, nvalues
        cdef qhull.DelaunayInfo_t *info

        ndim = xi.shape[1]
        start = 0
        fill_value = self.fill_value

        info = qhull._get_delaunay_info(self.tri, 1, 1)

        out = np.zeros((xi.shape[0], self.values.shape[1]), dtype=np.${DTYPE})
        nvalues = out.shape[1]

        eps = np.finfo(np.double).eps * 100

        with nogil:
            for i in xrange(np.PyArray_DIMS(xi)[0]):
                # 1) Find the simplex

                isimplex = qhull._find_simplex(info, c,
                                               (<double*>np.PyArray_DATA(xi)) + i*ndim,
                                               &start, eps)

                # 2) Clough-Tocher interpolation

                if isimplex == -1:
                    # outside triangulation
                    for k in xrange(nvalues):
% if DTYPE == "double":
                        out[i,k] = fill_value
% else:
                        out[i,k].real = fill_value.real
                        out[i,k].imag = fill_value.imag
% endif
                    continue

                for k in xrange(nvalues):
                    for j in xrange(ndim+1):
% if DTYPE == "double":
                        f[j] = values[vertices[isimplex,j],k]
                        df[2*j] = grad[vertices[isimplex,j],k,0]
                        df[2*j+1] = grad[vertices[isimplex,j],k,1]
% else:
                        f[j].real = values[vertices[isimplex,j],k].real
                        f[j].imag = values[vertices[isimplex,j],k].imag
                        df[2*j].real = grad[vertices[isimplex,j],k,0].real
                        df[2*j].imag = grad[vertices[isimplex,j],k,0].imag
                        df[2*j+1].real = grad[vertices[isimplex,j],k,1].real
                        df[2*j+1].imag = grad[vertices[isimplex,j],k,1].imag
% endif

                    w = _clough_tocher_2d_single_${DTYPE}(info, isimplex, c,
                                                          f, df)
% if DTYPE == "double":
                    out[i,k] = w
% else:
                    out[i,k].real = w.real
                    out[i,k].imag = w.imag
% endif

        free(<void*>info)
        return out

% endfor
