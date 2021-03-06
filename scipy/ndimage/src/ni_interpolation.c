/* Copyright (C) 2003-2005 Peter J. Verveer
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above
 *    copyright notice, this list of conditions and the following
 *    disclaimer in the documentation and/or other materials provided
 *    with the distribution.
 *
 * 3. The name of the author may not be used to endorse or promote
 *    products derived from this software without specific prior
 *    written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <npy_defs.h>
#include <npy_api.h>
#include "ni_support.h"
#include "ni_interpolation.h"
#include <stdlib.h>
#include <math.h>


static void NpyErr_NoMemory(void)
{
    NpyErr_SetString(NpyExc_MemoryError, "no memory");
}


/* calculate the B-spline interpolation coefficients for given x: */
static void
spline_coefficients(double x, int order, double *result)
{
    int hh;
    double y, start;

    if (order & 1) {
        start = (int)floor(x) - order / 2;
    } else {
        start = (int)floor(x + 0.5) - order / 2;
    }

    for(hh = 0; hh <= order; hh++)  {
        y = fabs(start - x + hh);

        switch(order) {
        case 1:
            result[hh] = y > 1.0 ? 0.0 : 1.0 - y;
            break;
        case 2:
            if (y < 0.5) {
                result[hh] = 0.75 - y * y;
            } else if (y < 1.5) {
                y = 1.5 - y;
                result[hh] = 0.5 * y * y;
            } else {
                result[hh] = 0.0;
            }
            break;
        case 3:
            if (y < 1.0) {
                result[hh] =
                    (y * y * (y - 2.0) * 3.0 + 4.0) / 6.0;
            } else if (y < 2.0) {
                y = 2.0 - y;
                result[hh] = y * y * y / 6.0;
            } else {
                result[hh] = 0.0;
            }
            break;
        case 4:
            if (y < 0.5) {
                y *= y;
                result[hh] = y * (y * 0.25 - 0.625) + 115.0 / 192.0;
            } else if (y < 1.5) {
                result[hh] = y * (y * (y * (5.0 / 6.0 - y / 6.0) - 1.25) +
                                                    5.0 / 24.0) + 55.0 / 96.0;
            } else if (y < 2.5) {
                y -= 2.5;
                y *= y;
                result[hh] = y * y / 24.0;
            } else {
                result[hh] = 0.0;
            }
            break;
        case 5:
            if (y < 1.0) {
                double f = y * y;
                result[hh] =
                    f * (f * (0.25 - y / 12.0) - 0.5) + 0.55;
            } else if (y < 2.0) {
                result[hh] = y * (y * (y * (y * (y / 24.0 - 0.375)
                                                                        + 1.25) -  1.75) + 0.625) + 0.425;
            } else if (y < 3.0) {
                double f = 3.0 - y;
                y = f * f;
                result[hh] = f * y * y / 120.0;
            } else {
                result[hh] = 0.0;
            }
            break;
        }
    }
}

/* map a coordinate outside the borders, according to the requested
     boundary condition: */
static double
map_coordinate(double in, npy_intp len, int mode)
{
    if (in < 0) {
        switch (mode) {
        case NI_EXTEND_MIRROR:
            if (len <= 1) {
                in = 0;
            } else {
                npy_intp sz2 = 2 * len - 2;
                in = sz2 * (npy_intp)(-in / sz2) + in;
                in = in <= 1 - len ? in + sz2 : -in;
            }
            break;
        case NI_EXTEND_REFLECT:
            if (len <= 1) {
                in = 0;
            } else {
                npy_intp sz2 = 2 * len;
                if (in < -sz2)
                    in = sz2 * (npy_intp)(-in / sz2) + in;
                in = in < -len ? in + sz2 : -in - 1;
            }
            break;
        case NI_EXTEND_WRAP:
            if (len <= 1) {
                in = 0;
            } else {
                npy_intp sz = len - 1;
                // Integer division of -in/sz gives (-in mod sz)
                // Note that 'in' is negative
                in += sz * ((npy_intp)(-in / sz) + 1);
            }
            break;
        case NI_EXTEND_NEAREST:
            in = 0;
            break;
        case NI_EXTEND_CONSTANT:
            in = -1;
            break;
        }
    } else if (in > len-1) {
        switch (mode) {
        case NI_EXTEND_MIRROR:
            if (len <= 1) {
                in = 0;
            } else {
                npy_intp sz2 = 2 * len - 2;
                in -= sz2 * (npy_intp)(in / sz2);
                if (in >= len)
                    in = sz2 - in;
            }
            break;
        case NI_EXTEND_REFLECT:
            if (len <= 1) {
                in = 0;
            } else {
                npy_intp sz2 = 2 * len;
                in -= sz2 * (npy_intp)(in / sz2);
                if (in >= len)
                    in = sz2 - in - 1;
            }
            break;
        case NI_EXTEND_WRAP:
            if (len <= 1) {
                in = 0;
            } else {
                npy_intp sz = len - 1;
                in -= sz * (npy_intp)(in / sz);
            }
            break;
        case NI_EXTEND_NEAREST:
            in = len - 1;
            break;
        case NI_EXTEND_CONSTANT:
            in = -1;
            break;
        }
    }

    return in;
}

#define BUFFER_SIZE 256000
#define TOLERANCE 1e-15

/* one-dimensional spline filter: */
int NI_SplineFilter1D(NpyArray *input, int order, int axis,
                                            NpyArray *output)
{
    int hh, npoles = 0, more;
    npy_intp kk, ll, lines, len;
    double *buffer = NULL, weight, pole[2];
    NI_LineBuffer iline_buffer, oline_buffer;

    len = NpyArray_NDIM(input) > 0 ? NpyArray_DIM(input, axis) : 1;
    if (len < 1)
        goto exit;

    /* these are used in the spline filter calculation below: */
    switch (order) {
    case 2:
        npoles = 1;
        pole[0] = sqrt(8.0) - 3.0;
        break;
    case 3:
        npoles = 1;
        pole[0] = sqrt(3.0) - 2.0;
        break;
    case 4:
        npoles = 2;
        pole[0] = sqrt(664.0 - sqrt(438976.0)) + sqrt(304.0) - 19.0;
        pole[1] = sqrt(664.0 + sqrt(438976.0)) - sqrt(304.0) - 19.0;
        break;
    case 5:
        npoles = 2;
        pole[0] = sqrt(67.5 - sqrt(4436.25)) + sqrt(26.25) - 6.5;
        pole[1] = sqrt(67.5 + sqrt(4436.25)) - sqrt(26.25) - 6.5;
        break;
    default:
        break;
    }

    weight = 1.0;
    for(hh = 0; hh < npoles; hh++)
        weight *= (1.0 - pole[hh]) * (1.0 - 1.0 / pole[hh]);

    /* allocate an initialize the line buffer, only a single one is used,
         because the calculation is in-place: */
    lines = -1;
    if (!NI_AllocateLineBuffer(input, axis, 0, 0, &lines, BUFFER_SIZE,
                                                         &buffer))
        goto exit;
    if (!NI_InitLineBuffer(input, axis, 0, 0, lines, buffer,
                                                 NI_EXTEND_DEFAULT, 0.0, &iline_buffer))
        goto exit;
    if (!NI_InitLineBuffer(output, axis, 0, 0, lines, buffer,
                                                 NI_EXTEND_DEFAULT, 0.0, &oline_buffer))
        goto exit;

    /* iterate over all the array lines: */
    do {
        /* copy lines from array to buffer: */
        if (!NI_ArrayToLineBuffer(&iline_buffer, &lines, &more))
            goto exit;
        /* iterate over the lines in the buffer: */
        for(kk = 0; kk < lines; kk++) {
            /* get line: */
            double *ln = NI_GET_LINE(iline_buffer, kk);
            /* spline filter: */
            if (len > 1) {
                for(ll = 0; ll < len; ll++)
                    ln[ll] *= weight;
                for(hh = 0; hh < npoles; hh++) {
                    double p = pole[hh];
                    int max = (int)ceil(log(TOLERANCE) / log(fabs(p)));
                    if (max < len) {
                        double zn = p;
                        double sum = ln[0];
                        for(ll = 1; ll < max; ll++) {
                            sum += zn * ln[ll];
                            zn *= p;
                        }
                        ln[0] = sum;
                    } else {
                        double zn = p;
                        double iz = 1.0 / p;
                        double z2n = pow(p, (double)(len - 1));
                        double sum = ln[0] + z2n * ln[len - 1];
                        z2n *= z2n * iz;
                        for(ll = 1; ll <= len - 2; ll++) {
                            sum += (zn + z2n) * ln[ll];
                            zn *= p;
                            z2n *= iz;
                        }
                        ln[0] = sum / (1.0 - zn * zn);
                    }
                    for(ll = 1; ll < len; ll++)
                        ln[ll] += p * ln[ll - 1];
                    ln[len-1] = (p / (p * p - 1.0)) * (ln[len-1] + p * ln[len-2]);
                    for(ll = len - 2; ll >= 0; ll--)
                        ln[ll] = p * (ln[ll + 1] - ln[ll]);
                }
            }
        }
        /* copy lines from buffer to array: */
        if (!NI_LineBufferToArray(&oline_buffer))
            goto exit;
    } while(more);

 exit:
    if (buffer) free(buffer);
    return NpyErr_Occurred() ? 0 : 1;
}

#define CASE_MAP_COORDINATES(_p, _coor, _rank, _stride, _type) \
case t ## _type:                                                    \
{                                                              \
    int _hh;                                                     \
    for(_hh = 0; _hh < _rank; _hh++) {                           \
        _coor[_hh] = *(_type*)_p;                                  \
        _p += _stride;                                             \
    }                                                            \
}                                                              \
break;

#define CASE_INTERP_COEFF(_coeff, _pi, _idx, _type) \
case t ## _type:                                    \
    _coeff = *(_type*)(_pi + _idx);                   \
    break;

#define CASE_INTERP_OUT(_po, _t, _type) \
case t ## _type:                        \
    *(_type*)_po = (_type)_t;             \
    break;

#define CASE_INTERP_OUT_UINT(_po, _t, _type, type_min, type_max) \
case t ## _type:                             \
    _t = _t > 0 ? _t + 0.5 : 0;                \
    _t = _t > type_max ? type_max : t;         \
    _t = _t < type_min ? type_min : t;         \
    *(_type*)_po = (_type)_t;                  \
    break;

#define CASE_INTERP_OUT_INT(_po, _t, _type, type_min, type_max) \
case t ## _type:                            \
    _t = _t > 0 ? _t + 0.5 : _t - 0.5;        \
    _t = _t > type_max ? type_max : t;        \
    _t = _t < type_min ? type_min : t;        \
    *(_type*)_po = (_type)_t;                 \
    break;

int
NI_GeometricTransform(NpyArray *input, int (*map)(npy_intp*, double*,
                int, int, void*), void* map_data, NpyArray* matrix_ar,
                NpyArray* shift_ar, NpyArray *coordinates,
                NpyArray *output, int order, int mode, double cval)
{
    char *po, *pi, *pc = NULL;
    npy_intp **edge_offsets = NULL, **data_offsets = NULL, filter_size;
    npy_intp ftmp[MAXDIM], *fcoordinates = NULL, *foffsets = NULL;
    npy_intp cstride = 0, kk, hh, ll, jj, *idxs = NULL;
    npy_intp size;
    double **splvals = NULL, icoor[MAXDIM];
    npy_intp idimensions[MAXDIM], istrides[MAXDIM];
    NI_Iterator io, ic;
    npy_float64 *matrix = matrix_ar ? (npy_float64*)NpyArray_DATA(matrix_ar) : NULL;
    npy_float64 *shift = shift_ar ? (npy_float64*)NpyArray_DATA(shift_ar) : NULL;
    int irank = 0, orank, qq;

    for(kk = 0; kk < NpyArray_NDIM(input); kk++) {
        idimensions[kk] = NpyArray_DIM(input, kk);
        istrides[kk] = NpyArray_STRIDE(input, kk);
    }
    irank = NpyArray_NDIM(input);
    orank = NpyArray_NDIM(output);

    /* if the mapping is from array coordinates: */
    if (coordinates) {
        /* initialze a line iterator along the first axis: */
        if (!NI_InitPointIterator(coordinates, &ic))
            goto exit;
        cstride = ic.strides[0];
        if (!NI_LineIterator(&ic, 0))
            goto exit;
        pc = (void *)(NpyArray_DATA(coordinates));
    }

    /* offsets used at the borders: */
    edge_offsets = (npy_intp**)malloc(irank * sizeof(npy_intp*));
    data_offsets = (npy_intp**)malloc(irank * sizeof(npy_intp*));
    if (!edge_offsets || !data_offsets) {
        NpyErr_NoMemory();
        goto exit;
    }
    for(jj = 0; jj < irank; jj++)
        data_offsets[jj] = NULL;
    for(jj = 0; jj < irank; jj++) {
        data_offsets[jj] = (npy_intp*)malloc((order + 1) * sizeof(npy_intp));
        if (!data_offsets[jj]) {
            NpyErr_NoMemory();
            goto exit;
        }
    }
    /* will hold the spline coefficients: */
    splvals = (double**)malloc(irank * sizeof(double*));
    if (!splvals) {
        NpyErr_NoMemory();
        goto exit;
    }
    for(jj = 0; jj < irank; jj++)
        splvals[jj] = NULL;
    for(jj = 0; jj < irank; jj++) {
        splvals[jj] = (double*)malloc((order + 1) * sizeof(double));
        if (!splvals[jj]) {
            NpyErr_NoMemory();
            goto exit;
        }
    }

    filter_size = 1;
    for(jj = 0; jj < irank; jj++)
        filter_size *= order + 1;
    idxs = (npy_intp*)malloc(filter_size * sizeof(idxs));
    if (!idxs) {
        NpyErr_NoMemory();
        goto exit;
    }

    /* initialize output iterator: */
    if (!NI_InitPointIterator(output, &io))
        goto exit;

    /* get data pointers: */
    pi = (void *)NpyArray_DATA(input);
    po = (void *)NpyArray_DATA(output);

    /* make a table of all possible coordinates within the spline filter: */
    fcoordinates = (npy_intp*)malloc(irank * filter_size * sizeof(npy_intp));
    /* make a table of all offsets within the spline filter: */
    foffsets = (npy_intp*)malloc(filter_size * sizeof(npy_intp));
    if (!fcoordinates || !foffsets) {
        NpyErr_NoMemory();
        goto exit;
    }
    for(jj = 0; jj < irank; jj++)
        ftmp[jj] = 0;
    kk = 0;
    for(hh = 0; hh < filter_size; hh++) {
        for(jj = 0; jj < irank; jj++)
            fcoordinates[jj + hh * irank] = ftmp[jj];
        foffsets[hh] = kk;
        for(jj = irank - 1; jj >= 0; jj--) {
            if (ftmp[jj] < order) {
                ftmp[jj]++;
                kk += istrides[jj];
                break;
            } else {
                ftmp[jj] = 0;
                kk -= istrides[jj] * order;
            }
        }
    }

    size = 1;
    for(qq = 0; qq < NpyArray_NDIM(output); qq++)
        size *= NpyArray_DIM(output, qq);
    for(kk = 0; kk < size; kk++) {
        double t = 0.0;
        int constant = 0, edge = 0, offset = 0;
        if (map) {
            /* call mappint functions: */
            if (!map(io.coordinates, icoor, orank, irank, map_data)) {
                if (!NpyErr_Occurred())
                    NpyErr_SetString(NpyExc_RuntimeError,
                                                    "unknown error in mapping function");
                goto exit;
            }
        } else if (matrix) {
            /* do an affine transformation: */
            npy_float64 *p = matrix;
            for(hh = 0; hh < irank; hh++) {
                icoor[hh] = 0.0;
                for(ll = 0; ll < orank; ll++)
                    icoor[hh] += io.coordinates[ll] * *p++;
                icoor[hh] += shift[hh];
            }
        } else if (coordinates) {
            /* mapping is from an coordinates array: */
            char *p = pc;
            switch(NpyArray_TYPE(coordinates)) {
                CASE_MAP_COORDINATES(p, icoor, irank, cstride, npy_bool);
                CASE_MAP_COORDINATES(p, icoor, irank, cstride, npy_uint8);
                CASE_MAP_COORDINATES(p, icoor, irank, cstride, npy_uint16);
                CASE_MAP_COORDINATES(p, icoor, irank, cstride, npy_uint32);
#if HAS_UINT64
                CASE_MAP_COORDINATES(p, icoor, irank, cstride, npy_uint64);
#endif
                CASE_MAP_COORDINATES(p, icoor, irank, cstride, npy_int8);
                CASE_MAP_COORDINATES(p, icoor, irank, cstride, npy_int16);
                CASE_MAP_COORDINATES(p, icoor, irank, cstride, npy_int32);
                CASE_MAP_COORDINATES(p, icoor, irank, cstride, npy_int64);
                CASE_MAP_COORDINATES(p, icoor, irank, cstride, npy_float32);
                CASE_MAP_COORDINATES(p, icoor, irank, cstride, npy_float64);
            default:
                NpyErr_SetString(NpyExc_RuntimeError,
                                 "coordinate array data type not supported");
                goto exit;
            }
        }
        /* iterate over axes: */
        for(hh = 0; hh < irank; hh++) {
            /* if the input coordinate is outside the borders, map it: */
            double cc = map_coordinate(icoor[hh], idimensions[hh], mode);
            if (cc > -1.0) {
                /* find the filter location along this axis: */
                int start;
                if (order & 1) {
                    start = (int)floor(cc) - order / 2;
                } else {
                    start = (int)floor(cc + 0.5) - order / 2;
                }
                /* get the offset to the start of the filter: */
                offset += istrides[hh] * start;
                if (start < 0 || start + order >= idimensions[hh]) {
                    /* implement border mapping, if outside border: */
                    edge = 1;
                    edge_offsets[hh] = data_offsets[hh];
                    for(ll = 0; ll <= order; ll++) {
                        int idx = start + ll;
                        int len = idimensions[hh];
                        if (len <= 1) {
                            idx = 0;
                        } else {
                            int s2 = 2 * len - 2;
                            if (idx < 0) {
                                idx = s2 * (int)(-idx / s2) + idx;
                                idx = idx <= 1 - len ? idx + s2 : -idx;
                            } else if (idx >= len) {
                                idx -= s2 * (int)(idx / s2);
                                if (idx >= len)
                                    idx = s2 - idx;
                            }
                        }
                        /* calculate and store the offests at this edge: */
                        edge_offsets[hh][ll] = istrides[hh] * (idx - start);
                    }
                } else {
                    /* we are not at the border, use precalculated offsets: */
                    edge_offsets[hh] = NULL;
                }
                spline_coefficients(cc, order, splvals[hh]);
            } else {
                /* we use the constant border condition: */
                constant = 1;
                break;
            }
        }

        if (!constant) {
            npy_intp *ff = fcoordinates;
            for(hh = 0; hh < filter_size; hh++) {
                int idx = 0;
                if (edge) {
                    for(ll = 0; ll < irank; ll++) {
                        if (edge_offsets[ll])
                            idx += edge_offsets[ll][ff[ll]];
                        else
                            idx += ff[ll] * istrides[ll];
                    }
                } else {
                    idx = foffsets[hh];
                }
                idx += offset;
                idxs[hh] = idx;
                ff += irank;
            }
        }
        if (!constant) {
            npy_intp *ff = fcoordinates;
            t = 0.0;
            for(hh = 0; hh < filter_size; hh++) {
                double coeff = 0.0;
                switch(NpyArray_TYPE(input)) {
                    CASE_INTERP_COEFF(coeff, pi, idxs[hh], npy_bool);
                    CASE_INTERP_COEFF(coeff, pi, idxs[hh], npy_uint8);
                    CASE_INTERP_COEFF(coeff, pi, idxs[hh], npy_uint16);
                    CASE_INTERP_COEFF(coeff, pi, idxs[hh], npy_uint32);
#if HAS_UINT64
                    CASE_INTERP_COEFF(coeff, pi, idxs[hh], npy_uint64);
#endif
                    CASE_INTERP_COEFF(coeff, pi, idxs[hh], npy_int8);
                    CASE_INTERP_COEFF(coeff, pi, idxs[hh], npy_int16);
                    CASE_INTERP_COEFF(coeff, pi, idxs[hh], npy_int32);
                    CASE_INTERP_COEFF(coeff, pi, idxs[hh], npy_int64);
                    CASE_INTERP_COEFF(coeff, pi, idxs[hh], npy_float32);
                    CASE_INTERP_COEFF(coeff, pi, idxs[hh], npy_float64);
                default:
                    NpyErr_SetString(NpyExc_RuntimeError,
                                     "data type not supported");
                    goto exit;
                }
                /* calculate the interpolated value: */
                for(ll = 0; ll < irank; ll++)
                    if (order > 0)
                        coeff *= splvals[ll][ff[ll]];
                t += coeff;
                ff += irank;
            }
        } else {
            t = cval;
        }
        /* store output value: */
        switch (NpyArray_TYPE(output)) {
            CASE_INTERP_OUT(po, t, npy_bool);
            CASE_INTERP_OUT_UINT(po, t, npy_uint8, 0, NPY_MAX_UINT8);
            CASE_INTERP_OUT_UINT(po, t, npy_uint16, 0, NPY_MAX_UINT16);
            CASE_INTERP_OUT_UINT(po, t, npy_uint32, 0, NPY_MAX_UINT32);
#if HAS_UINT64
            /* FIXME */
            CASE_INTERP_OUT_UINT(po, t, npy_uint64, 0, NPY_MAX_UINT32);
#endif
            CASE_INTERP_OUT_INT(po, t, npy_int8, NPY_MIN_INT8, NPY_MAX_INT8);
            CASE_INTERP_OUT_INT(po, t, npy_int16, NPY_MIN_INT16, NPY_MAX_INT16);
            CASE_INTERP_OUT_INT(po, t, npy_int32, NPY_MIN_INT32, NPY_MAX_INT32);
            CASE_INTERP_OUT_INT(po, t, npy_int64, NPY_MIN_INT64, NPY_MAX_INT64);
            CASE_INTERP_OUT(po, t, npy_float32);
            CASE_INTERP_OUT(po, t, npy_float64);
        default:
            NpyErr_SetString(NpyExc_RuntimeError, "data type not supported");
            goto exit;
        }
        if (coordinates) {
            NI_ITERATOR_NEXT2(io, ic, po, pc);
        } else {
            NI_ITERATOR_NEXT(io, po);
        }
    }

 exit:
    if (edge_offsets)
        free(edge_offsets);
    if (data_offsets) {
        for(jj = 0; jj < irank; jj++)
            free(data_offsets[jj]);
        free(data_offsets);
    }
    if (splvals) {
        for(jj = 0; jj < irank; jj++)
            free(splvals[jj]);
        free(splvals);
    }
    if (foffsets)
        free(foffsets);
    if (fcoordinates)
        free(fcoordinates);
    if (idxs)
        free(idxs);
    return NpyErr_Occurred() ? 0 : 1;
}

int NI_ZoomShift(NpyArray *input, NpyArray* zoom_ar,
                                 NpyArray* shift_ar, NpyArray *output,
                                 int order, int mode, double cval)
{
    char *po, *pi;
    npy_intp **zeros = NULL, **offsets = NULL, ***edge_offsets = NULL;
    npy_intp ftmp[MAXDIM], *fcoordinates = NULL, *foffsets = NULL;
    npy_intp jj, hh, kk, filter_size, odimensions[MAXDIM];
    npy_intp idimensions[MAXDIM], istrides[MAXDIM], *idxs = NULL;
    npy_intp size;
    double ***splvals = NULL;
    NI_Iterator io;
    npy_float64 *zooms = zoom_ar ? (npy_float64*)NpyArray_DATA(zoom_ar) : NULL;
    npy_float64 *shifts = shift_ar ? (npy_float64*)NpyArray_DATA(shift_ar) : NULL;
    int rank = 0, qq;

    for(kk = 0; kk < NpyArray_NDIM(input); kk++) {
        idimensions[kk] = NpyArray_DIM(input, kk);
        istrides[kk] = NpyArray_STRIDE(input, kk);
        odimensions[kk] = NpyArray_DIM(output, kk);
    }
    rank = NpyArray_NDIM(input);

    /* if the mode is 'constant' we need some temps later: */
    if (mode == NI_EXTEND_CONSTANT) {
        zeros = (npy_intp**)malloc(rank * sizeof(npy_intp*));
        if (!zeros) {
            NpyErr_NoMemory();
            goto exit;
        }
        for(jj = 0; jj < rank; jj++)
            zeros[jj] = NULL;
        for(jj = 0; jj < rank; jj++) {
            zeros[jj] = (npy_intp*)malloc(odimensions[jj] * sizeof(npy_intp));
            if(!zeros[jj]) {
                NpyErr_NoMemory();
                goto exit;
            }
        }
    }

    /* store offsets, along each axis: */
    offsets = (npy_intp**)malloc(rank * sizeof(npy_intp*));
    /* store spline coefficients, along each axis: */
    splvals = (double***)malloc(rank * sizeof(double**));
    /* store offsets at all edges: */
    edge_offsets = (npy_intp***)malloc(rank * sizeof(npy_intp**));
    if (!offsets || !splvals || !edge_offsets) {
        NpyErr_NoMemory();
        goto exit;
    }
    for(jj = 0; jj < rank; jj++) {
        offsets[jj] = NULL;
        splvals[jj] = NULL;
        edge_offsets[jj] = NULL;
    }
    for(jj = 0; jj < rank; jj++) {
        offsets[jj] = (npy_intp*)malloc(odimensions[jj] * sizeof(npy_intp));
        splvals[jj] = (double**)malloc(odimensions[jj] * sizeof(double*));
        edge_offsets[jj] = (npy_intp**)malloc(odimensions[jj] * sizeof(npy_intp*));
        if (!offsets[jj] || !splvals[jj] || !edge_offsets[jj]) {
            NpyErr_NoMemory();
            goto exit;
        }
        for(hh = 0; hh < odimensions[jj]; hh++) {
            splvals[jj][hh] = NULL;
            edge_offsets[jj][hh] = NULL;
        }
    }

    /* precalculate offsets, and offsets at the edge: */
    for(jj = 0; jj < rank; jj++) {
        double shift = 0.0, zoom = 0.0;
        if (shifts)
            shift = shifts[jj];
        if (zooms)
            zoom = zooms[jj];
        for(kk = 0; kk < odimensions[jj]; kk++) {
            double cc = (double)kk;
            if (shifts)
                cc += shift;
            if (zooms)
                cc *= zoom;
            cc = map_coordinate(cc, idimensions[jj], mode);
            if (cc > -1.0) {
                int start;
                if (zeros && zeros[jj])
                    zeros[jj][kk] = 0;
                if (order & 1) {
                    start = (int)floor(cc) - order / 2;
                } else {
                    start = (int)floor(cc + 0.5) - order / 2;
                }
                offsets[jj][kk] = istrides[jj] * start;
                if (start < 0 || start + order >= idimensions[jj]) {
                    edge_offsets[jj][kk] = (npy_intp*)malloc((order + 1) * sizeof(npy_intp));
                    if (!edge_offsets[jj][kk]) {
                        NpyErr_NoMemory();
                        goto exit;
                    }
                    for(hh = 0; hh <= order; hh++) {
                        int idx = start + hh;
                         int len = idimensions[jj];
                        if (len <= 1) {
                            idx = 0;
                        } else {
                            int s2 = 2 * len - 2;
                            if (idx < 0) {
                                idx = s2 * (int)(-idx / s2) + idx;
                                idx = idx <= 1 - len ? idx + s2 : -idx;
                            } else if (idx >= len) {
                                idx -= s2 * (int)(idx / s2);
                                if (idx >= len)
                                    idx = s2 - idx;
                            }
                        }
                        edge_offsets[jj][kk][hh] = istrides[jj] * (idx - start);
                    }
                }
                if (order > 0) {
                    splvals[jj][kk] = (double*)malloc((order + 1) * sizeof(double));
                    if (!splvals[jj][kk]) {
                        NpyErr_NoMemory();
                        goto exit;
                    }
                    spline_coefficients(cc, order, splvals[jj][kk]);
                }
            } else {
                zeros[jj][kk] = 1;
            }
        }
    }

    filter_size = 1;
    for(jj = 0; jj < rank; jj++)
        filter_size *= order + 1;
    idxs = (npy_intp*)malloc(filter_size * sizeof(idxs));
    if (!idxs) {
        NpyErr_NoMemory();
        goto exit;
    }

    if (!NI_InitPointIterator(output, &io))
        goto exit;

    pi = (void *)NpyArray_DATA(input);
    po = (void *)NpyArray_DATA(output);

    /* store all coordinates and offsets with filter: */
    fcoordinates = (npy_intp*)malloc(rank * filter_size * sizeof(npy_intp));
    foffsets = (npy_intp*)malloc(filter_size * sizeof(npy_intp));
    if (!fcoordinates || !foffsets) {
        NpyErr_NoMemory();
        goto exit;
    }

    for(jj = 0; jj < rank; jj++)
        ftmp[jj] = 0;
    kk = 0;
    for(hh = 0; hh < filter_size; hh++) {
        for(jj = 0; jj < rank; jj++)
            fcoordinates[jj + hh * rank] = ftmp[jj];
        foffsets[hh] = kk;
        for(jj = rank - 1; jj >= 0; jj--) {
            if (ftmp[jj] < order) {
                ftmp[jj]++;
                kk += istrides[jj];
                break;
            } else {
                ftmp[jj] = 0;
                kk -= istrides[jj] * order;
            }
        }
    }
    size = 1;
    for(qq = 0; qq < NpyArray_NDIM(output); qq++)
        size *= NpyArray_DIM(output, qq);
    for(kk = 0; kk < size; kk++) {
        double t = 0.0;
        int edge = 0, oo = 0, zero = 0;

        for(hh = 0; hh < rank; hh++) {
            if (zeros && zeros[hh][io.coordinates[hh]]) {
                /* we use constant border condition */
                zero = 1;
                break;
            }
            oo += offsets[hh][io.coordinates[hh]];
            if (edge_offsets[hh][io.coordinates[hh]])
                edge = 1;
        }

        if (!zero) {
            npy_intp *ff = fcoordinates;
            for(hh = 0; hh < filter_size; hh++) {
                int idx = 0;
                if (edge) {
                        /* use precalculated edge offsets: */
                    for(jj = 0; jj < rank; jj++) {
                        if (edge_offsets[jj][io.coordinates[jj]])
                            idx += edge_offsets[jj][io.coordinates[jj]][ff[jj]];
                        else
                            idx += ff[jj] * istrides[jj];
                    }
                    idx += oo;
                } else {
                    /* use normal offsets: */
                    idx += oo + foffsets[hh];
                }
                idxs[hh] = idx;
                ff += rank;
            }
        }
        if (!zero) {
            npy_intp *ff = fcoordinates;
            t = 0.0;
            for(hh = 0; hh < filter_size; hh++) {
                double coeff = 0.0;
                switch(NpyArray_TYPE(input)) {
                    CASE_INTERP_COEFF(coeff, pi, idxs[hh], npy_bool);
                    CASE_INTERP_COEFF(coeff, pi, idxs[hh], npy_uint8);
                    CASE_INTERP_COEFF(coeff, pi, idxs[hh], npy_uint16);
                    CASE_INTERP_COEFF(coeff, pi, idxs[hh], npy_uint32);
#if HAS_UINT64
                    CASE_INTERP_COEFF(coeff, pi, idxs[hh], npy_uint64);
#endif
                    CASE_INTERP_COEFF(coeff, pi, idxs[hh], npy_int8);
                    CASE_INTERP_COEFF(coeff, pi, idxs[hh], npy_int16);
                    CASE_INTERP_COEFF(coeff, pi, idxs[hh], npy_int32);
                    CASE_INTERP_COEFF(coeff, pi, idxs[hh], npy_int64);
                    CASE_INTERP_COEFF(coeff, pi, idxs[hh], npy_float32);
                    CASE_INTERP_COEFF(coeff, pi, idxs[hh], npy_float64);
                default:
                    NpyErr_SetString(NpyExc_RuntimeError,
                                     "data type not supported");
                    goto exit;
                }
                /* calculate interpolated value: */
                for(jj = 0; jj < rank; jj++)
                    if (order > 0)
                        coeff *= splvals[jj][io.coordinates[jj]][ff[jj]];
                t += coeff;
                ff += rank;
            }
        } else {
            t = cval;
        }
        /* store output: */
        switch (NpyArray_TYPE(output)) {
            CASE_INTERP_OUT(po, t, npy_bool);
            CASE_INTERP_OUT_UINT(po, t, npy_uint8, 0, NPY_MAX_UINT8);
            CASE_INTERP_OUT_UINT(po, t, npy_uint16, 0, NPY_MAX_UINT16);
            CASE_INTERP_OUT_UINT(po, t, npy_uint32, 0, NPY_MAX_UINT32);
#if HAS_UINT64
            /* FIXME */
            CASE_INTERP_OUT_UINT(po, t, npy_uint64, 0, NPY_MAX_UINT32);
#endif
            CASE_INTERP_OUT_INT(po, t, npy_int8, NPY_MIN_INT8, NPY_MAX_INT8);
            CASE_INTERP_OUT_INT(po, t, npy_int16, NPY_MIN_INT16, NPY_MAX_INT16);
            CASE_INTERP_OUT_INT(po, t, npy_int32, NPY_MIN_INT32, NPY_MAX_INT32);
            CASE_INTERP_OUT_INT(po, t, npy_int64, NPY_MIN_INT64, NPY_MAX_INT64);
            CASE_INTERP_OUT(po, t, npy_float32);
            CASE_INTERP_OUT(po, t, npy_float64);
        default:
            NpyErr_SetString(NpyExc_RuntimeError, "data type not supported");
            goto exit;
        }
        NI_ITERATOR_NEXT(io, po);
    }

 exit:
    if (zeros) {
        for(jj = 0; jj < rank; jj++)
            if (zeros[jj])
                free(zeros[jj]);
        free(zeros);
    }
    if (offsets) {
        for(jj = 0; jj < rank; jj++)
            if (offsets[jj])
                free(offsets[jj]);
        free(offsets);
    }
    if (splvals) {
        for(jj = 0; jj < rank; jj++) {
            if (splvals[jj]) {
                for(hh = 0; hh < odimensions[jj]; hh++)
                    if (splvals[jj][hh])
                        free(splvals[jj][hh]);
                free(splvals[jj]);
            }
        }
        free(splvals);
    }
    if (edge_offsets) {
        for(jj = 0; jj < rank; jj++) {
            if (edge_offsets[jj]) {
                for(hh = 0; hh < odimensions[jj]; hh++)
                    if (edge_offsets[jj][hh])
                        free(edge_offsets[jj][hh]);
                free(edge_offsets[jj]);
            }
        }
        free(edge_offsets);
    }
    if (foffsets)
        free(foffsets);
    if (fcoordinates)
        free(fcoordinates);
    if (idxs)
        free(idxs);
    return NpyErr_Occurred() ? 0 : 1;
}
