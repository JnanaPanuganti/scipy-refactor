cimport numpy as np
from specfun_fc cimport *

cpdef api object lqmn(fwi_integer_t mm, fwi_integer_t m, fwi_integer_t n, fwr_dbl_t x, object qm, object qd)
cpdef api object clpmn(fwi_integer_t mm, fwi_integer_t m, fwi_integer_t n, fwr_dbl_t x, fwr_dbl_t y, object cpm, object cpd)
cpdef api object jdzo(fwi_integer_t nt, object n, object m, object p, object zo)
cpdef api object bernob(fwi_integer_t n, object bn)
cpdef api object bernoa(fwi_integer_t n, object bn)
cpdef api object csphjy(fwi_integer_t n, fwc_complex_x16_t z, fwi_integer_t nm, object csj, object cdj, object csy, object cdy)
cpdef api object lpmns(fwi_integer_t m, fwi_integer_t n, fwr_dbl_t x, object pm, object pd)
cpdef api object eulera(fwi_integer_t n, object en)
cpdef api object clqn(fwi_integer_t n, fwr_dbl_t x, fwr_dbl_t y, object cqn, object cqd)
cpdef api object airyzo(fwi_integer_t nt, fwi_integer_t kf, object xa, object xb, object xc, object xd)
cpdef api object eulerb(fwi_integer_t n, object en)
cpdef api object cva1(fwi_integer_t kd, fwi_integer_t m, fwr_dbl_t q, object cv)
cpdef api object lqnb(fwi_integer_t n, fwr_dbl_t x, object qn, object qd)
cpdef api object lamv(fwr_dbl_t v, fwr_dbl_t x, fwr_dbl_t vm, object vl, object dl)
cpdef api object lagzo(fwi_integer_t n, object x, object w)
cpdef api object legzo(fwi_integer_t n, object x, object w)
cpdef api object pbdv(fwr_dbl_t v, fwr_dbl_t x, object dv, object dp, fwr_dbl_t pdf, fwr_dbl_t pdd)
cpdef api object cerzo(fwi_integer_t nt, object zo)
cpdef api object lamn(fwi_integer_t n, fwr_dbl_t x, fwi_integer_t nm, object bl, object dl)
cpdef api object clpn(fwi_integer_t n, fwr_dbl_t x, fwr_dbl_t y, object cpn, object cpd)
cpdef api object lqmns(fwi_integer_t m, fwi_integer_t n, fwr_dbl_t x, object qm, object qd)
cpdef api object chgm(fwr_dbl_t a, fwr_dbl_t b, fwr_dbl_t x, fwr_dbl_t hg)
cpdef api object lpmn(fwi_integer_t mm, fwi_integer_t m, fwi_integer_t n, fwr_dbl_t x, object pm, object pd)
cpdef api object fcszo(fwi_integer_t kf, fwi_integer_t nt, object zo)
cpdef api object aswfb(fwi_integer_t m, fwi_integer_t n, fwr_dbl_t c, fwr_dbl_t x, fwi_integer_t kd, fwr_dbl_t cv, fwr_dbl_t s1f, fwr_dbl_t s1d)
cpdef api object lqna(fwi_integer_t n, fwr_dbl_t x, object qn, object qd)
cpdef api object cpbdn(fwi_integer_t n, fwc_complex_x16_t z, object cpb, object cpd)
cpdef api object lpn(fwi_integer_t n, fwr_dbl_t x, object pn, object pd)
cpdef api object fcoef(fwi_integer_t kd, fwi_integer_t m, fwr_dbl_t q, fwr_dbl_t a, object fc)
cpdef api object sphi(fwi_integer_t n, fwr_dbl_t x, fwi_integer_t nm, object si, object di)
cpdef api object rcty(fwi_integer_t n, fwr_dbl_t x, fwi_integer_t nm, object ry, object dy)
cpdef api object lpni(fwi_integer_t n, fwr_dbl_t x, object pn, object pd, object pl)
cpdef api object cyzo(fwi_integer_t nt, fwi_integer_t kf, fwi_integer_t kc, object zo, object zv)
cpdef api object csphik(fwi_integer_t n, fwc_complex_x16_t z, fwi_integer_t nm, object csi, object cdi, object csk, object cdk)
cpdef api object sphj(fwi_integer_t n, fwr_dbl_t x, fwi_integer_t nm, object sj, object dj)
cpdef api object othpl(fwi_integer_t kf, fwi_integer_t n, fwr_dbl_t x, object pl, object dpl)
cpdef api object klvnzo(fwi_integer_t nt, fwi_integer_t kd, object zo)
cpdef api object jyzo(fwi_integer_t n, fwi_integer_t nt, object rj0, object rj1, object ry0, object ry1)
cpdef api object rctj(fwi_integer_t n, fwr_dbl_t x, fwi_integer_t nm, object rj, object dj)
cpdef api object herzo(fwi_integer_t n, object x, object w)
cpdef api object sphk(fwi_integer_t n, fwr_dbl_t x, fwi_integer_t nm, object sk, object dk)
cpdef api object pbvv(fwr_dbl_t v, fwr_dbl_t x, object vv, object vp, fwr_dbl_t pvf, fwr_dbl_t pvd)
cpdef api object clqmn(fwi_integer_t mm, fwi_integer_t m, fwi_integer_t n, fwr_dbl_t x, fwr_dbl_t y, object cqm, object cqd)
cpdef api object segv(fwi_integer_t m, fwi_integer_t n, fwr_dbl_t c, fwi_integer_t kd, fwr_dbl_t cv, object eg)
cpdef api object sphy(fwi_integer_t n, fwr_dbl_t x, fwi_integer_t nm, object sy, object dy)
