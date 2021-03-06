
#ifdef __cplusplus
#define GLOBALFUNC(x) ::x
#else
#define GLOBALFUNC(x) x
#endif

#ifdef __cplusplus
extern "C" {
#endif

void zfft(fwc_complex_x16_t * x, fwi_integer_t n, fwi_integer_t direction, fwi_integer_t howmany, fwi_integer_t normalize);
void drfft(fwr_real_x8_t * x, fwi_integer_t n, fwi_integer_t direction, fwi_integer_t howmany, fwi_integer_t normalize);
void zrfft(fwc_complex_x16_t * x, fwi_integer_t n, fwi_integer_t direction, fwi_integer_t howmany, fwi_integer_t normalize);
void zfftnd(fwc_complex_x16_t * x, fwi_integer_t r, fwi_integer_t * s, fwi_integer_t direction, fwi_integer_t howmany, fwi_integer_t normalize);
void destroy_zfft_cache();
void destroy_zfftnd_cache();
void destroy_drfft_cache();
void cfft(fwc_complex_x8_t * x, fwi_integer_t n, fwi_integer_t direction, fwi_integer_t howmany, fwi_integer_t normalize);
void rfft(fwr_real_x4_t * x, fwi_integer_t n, fwi_integer_t direction, fwi_integer_t howmany, fwi_integer_t normalize);
void crfft(fwc_complex_x8_t * x, fwi_integer_t n, fwi_integer_t direction, fwi_integer_t howmany, fwi_integer_t normalize);
void cfftnd(fwc_complex_x8_t * x, fwi_integer_t r, fwi_integer_t * s, fwi_integer_t direction, fwi_integer_t howmany, fwi_integer_t normalize);
void destroy_cfft_cache();
void destroy_cfftnd_cache();
void destroy_rfft_cache();
void ddct1(fwr_real_x8_t * x, fwi_integer_t n, fwi_integer_t howmany, fwi_integer_t normalize);
void ddct2(fwr_real_x8_t * x, fwi_integer_t n, fwi_integer_t howmany, fwi_integer_t normalize);
void ddct3(fwr_real_x8_t * x, fwi_integer_t n, fwi_integer_t howmany, fwi_integer_t normalize);
void dct1(fwr_real_x4_t * x, fwi_integer_t n, fwi_integer_t howmany, fwi_integer_t normalize);
void dct2(fwr_real_x4_t * x, fwi_integer_t n, fwi_integer_t howmany, fwi_integer_t normalize);
void dct3(fwr_real_x4_t * x, fwi_integer_t n, fwi_integer_t howmany, fwi_integer_t normalize);
void destroy_ddct2_cache();
void destroy_ddct1_cache();
void destroy_dct2_cache();
void destroy_dct1_cache();

#ifdef __cplusplus
}
#endif