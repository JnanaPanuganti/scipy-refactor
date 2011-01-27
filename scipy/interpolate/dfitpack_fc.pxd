from fwrap_ktp cimport *

cdef extern from "dfitpack_fc.h":
    void bispeu(fwr_real_x8_t * tx, fwi_integer_t * nx, fwr_real_x8_t * ty, fwi_integer_t * ny, fwr_real_x8_t * c, fwi_integer_t * kx, fwi_integer_t * ky, fwr_real_x8_t * x, fwr_real_x8_t * y, fwr_real_x8_t * z, fwi_integer_t * m, fwr_real_x8_t * wrk, fwi_integer_t * lwrk, fwi_integer_t * ier)
    void bispev(fwr_real_x8_t * tx, fwi_integer_t * nx, fwr_real_x8_t * ty, fwi_integer_t * ny, fwr_real_x8_t * c, fwi_integer_t * kx, fwi_integer_t * ky, fwr_real_x8_t * x, fwi_integer_t * mx, fwr_real_x8_t * y, fwi_integer_t * my, fwr_real_x8_t * z, fwr_real_x8_t * wrk, fwi_integer_t * lwrk, fwi_integer_t * iwrk, fwi_integer_t * kwrk, fwi_integer_t * ier)
    void curfit(fwi_integer_t * iopt, fwi_integer_t * m, fwr_real_x8_t * x, fwr_real_x8_t * y, fwr_real_x8_t * w, fwr_real_x8_t * xb, fwr_real_x8_t * xe, fwi_integer_t * k, fwr_real_x8_t * s, fwi_integer_t * nest, fwi_integer_t * n, fwr_real_x8_t * t, fwr_real_x8_t * c, fwr_real_x8_t * fp, fwr_real_x8_t * wrk, fwi_integer_t * lwrk, fwi_integer_t * iwrk, fwi_integer_t * ier)
    fwr_real_x8_t dblint(fwr_real_x8_t * tx, fwi_integer_t * nx, fwr_real_x8_t * ty, fwi_integer_t * ny, fwr_real_x8_t * c, fwi_integer_t * kx, fwi_integer_t * ky, fwr_real_x8_t * xb, fwr_real_x8_t * xe, fwr_real_x8_t * yb, fwr_real_x8_t * ye, fwr_real_x8_t * wrk)
    void fpcurf(fwi_integer_t * iopt, fwr_real_x8_t * x, fwr_real_x8_t * y, fwr_real_x8_t * w, fwi_integer_t * m, fwr_real_x8_t * xb, fwr_real_x8_t * xe, fwi_integer_t * k, fwr_real_x8_t * s, fwi_integer_t * nest, fwr_real_x8_t * tol, fwi_integer_t * maxit, fwi_integer_t * k1, fwi_integer_t * k2, fwi_integer_t * n, fwr_real_x8_t * t, fwr_real_x8_t * c, fwr_real_x8_t * fp, fwr_real_x8_t * fpint, fwr_real_x8_t * z, fwr_real_x8_t * a, fwr_real_x8_t * b, fwr_real_x8_t * g, fwr_real_x8_t * q, fwi_integer_t * nrdata, fwi_integer_t * ier)
    void parcur(fwi_integer_t * iopt, fwi_integer_t * ipar, fwi_integer_t * idim, fwi_integer_t * m, fwr_real_x8_t * u, fwi_integer_t * mx, fwr_real_x8_t * x, fwr_real_x8_t * w, fwr_real_x8_t * ub, fwr_real_x8_t * ue, fwi_integer_t * k, fwr_real_x8_t * s, fwi_integer_t * nest, fwi_integer_t * n, fwr_real_x8_t * t, fwi_integer_t * nc, fwr_real_x8_t * c, fwr_real_x8_t * fp, fwr_real_x8_t * wrk, fwi_integer_t * lwrk, fwi_integer_t * iwrk, fwi_integer_t * ier)
    void percur(fwi_integer_t * iopt, fwi_integer_t * m, fwr_real_x8_t * x, fwr_real_x8_t * y, fwr_real_x8_t * w, fwi_integer_t * k, fwr_real_x8_t * s, fwi_integer_t * nest, fwi_integer_t * n, fwr_real_x8_t * t, fwr_real_x8_t * c, fwr_real_x8_t * fp, fwr_real_x8_t * wrk, fwi_integer_t * lwrk, fwi_integer_t * iwrk, fwi_integer_t * ier)
    void regrid(fwi_integer_t * iopt, fwi_integer_t * mx, fwr_real_x8_t * x, fwi_integer_t * my, fwr_real_x8_t * y, fwr_real_x8_t * z, fwr_real_x8_t * xb, fwr_real_x8_t * xe, fwr_real_x8_t * yb, fwr_real_x8_t * ye, fwi_integer_t * kx, fwi_integer_t * ky, fwr_real_x8_t * s, fwi_integer_t * nxest, fwi_integer_t * nyest, fwi_integer_t * nx, fwr_real_x8_t * tx, fwi_integer_t * ny, fwr_real_x8_t * ty, fwr_real_x8_t * c, fwr_real_x8_t * fp, fwr_real_x8_t * wrk, fwi_integer_t * lwrk, fwi_integer_t * iwrk, fwi_integer_t * kwrk, fwi_integer_t * ier)
    void spalde(fwr_real_x8_t * t, fwi_integer_t * n, fwr_real_x8_t * c, fwi_integer_t * k1, fwr_real_x8_t * x, fwr_real_x8_t * d, fwi_integer_t * ier)
    void splder(fwr_real_x8_t * t, fwi_integer_t * n, fwr_real_x8_t * c, fwi_integer_t * k, fwi_integer_t * nu, fwr_real_x8_t * x, fwr_real_x8_t * y, fwi_integer_t * m, fwi_integer_t * e, fwr_real_x8_t * wrk, fwi_integer_t * ier)
    void splev(fwr_real_x8_t * t, fwi_integer_t * n, fwr_real_x8_t * c, fwi_integer_t * k, fwr_real_x8_t * x, fwr_real_x8_t * y, fwi_integer_t * m, fwi_integer_t * e, fwi_integer_t * ier)
    fwr_real_x8_t splint(fwr_real_x8_t * t, fwi_integer_t * n, fwr_real_x8_t * c, fwi_integer_t * k, fwr_real_x8_t * a, fwr_real_x8_t * b, fwr_real_x8_t * wrk)
    void sproot(fwr_real_x8_t * t, fwi_integer_t * n, fwr_real_x8_t * c, fwr_real_x8_t * zero, fwi_integer_t * mest, fwi_integer_t * m, fwi_integer_t * ier)
    void surfit(fwi_integer_t * iopt, fwi_integer_t * m, fwr_real_x8_t * x, fwr_real_x8_t * y, fwr_real_x8_t * z, fwr_real_x8_t * w, fwr_real_x8_t * xb, fwr_real_x8_t * xe, fwr_real_x8_t * yb, fwr_real_x8_t * ye, fwi_integer_t * kx, fwi_integer_t * ky, fwr_real_x8_t * s, fwi_integer_t * nxest, fwi_integer_t * nyest, fwi_integer_t * nmax, fwr_real_x8_t * eps, fwi_integer_t * nx, fwr_real_x8_t * tx, fwi_integer_t * ny, fwr_real_x8_t * ty, fwr_real_x8_t * c, fwr_real_x8_t * fp, fwr_real_x8_t * wrk1, fwi_integer_t * lwrk1, fwr_real_x8_t * wrk2, fwi_integer_t * lwrk2, fwi_integer_t * iwrk, fwi_integer_t * kwrk, fwi_integer_t * ier)
