/* Cython code section 'h_code' */


#define PY_LONG_LONG long long

using namespace System::Collections;
using namespace System::Numerics;
using namespace System::Reflection;
using namespace System::Runtime::CompilerServices;
using namespace System::Runtime;
using namespace System::Security::Permissions;
using namespace System::Linq::Expressions;
using namespace Microsoft::Scripting::Actions;
using namespace Microsoft::Scripting::Runtime;
using namespace Microsoft::Scripting;
using namespace IronPython;
using namespace IronPython::Runtime;
using namespace IronPython::Runtime::Operations;

#define Py_None nullptr
typedef int Py_ssize_t; // IronPython uses "int" for sizes even on 64-bit platforms
#define PY_SSIZE_T_MAX 2147483647

enum class Markers { Default };

static CodeContext^ mk_empty_context(CodeContext^ ctx) {
  PythonDictionary^ dict = gcnew PythonDictionary;
  dict["__module__"] = "scipy.fftpack._fftpack";
  return gcnew CodeContext(dict, ctx->ModuleContext);
}
  #define PyBUF_SIMPLE 0
  #define PyBUF_WRITABLE 0x0001
  #define PyBUF_FORMAT 0x0004
  #define PyBUF_ND 0x0008
  #define PyBUF_STRIDES (0x0010 | PyBUF_ND)
  #define PyBUF_C_CONTIGUOUS (0x0020 | PyBUF_STRIDES)
  #define PyBUF_F_CONTIGUOUS (0x0040 | PyBUF_STRIDES)
  #define PyBUF_ANY_CONTIGUOUS (0x0080 | PyBUF_STRIDES)
  #define PyBUF_INDIRECT (0x0100 | PyBUF_STRIDES)


/* inline attribute */
#ifndef CYTHON_INLINE
  #if defined(__GNUC__)
    #define CYTHON_INLINE __inline__
  #elif defined(_MSC_VER)
    #define CYTHON_INLINE __inline
  #elif defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
    #define CYTHON_INLINE inline
  #else
    #define CYTHON_INLINE 
  #endif
#endif

/* unused attribute */
#ifndef CYTHON_UNUSED
# if defined(__GNUC__)
#   if !(defined(__cplusplus)) || (__GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4))
#     define CYTHON_UNUSED __attribute__ ((__unused__)) 
#   else
#     define CYTHON_UNUSED
#   endif
# elif defined(__ICC) || defined(__INTEL_COMPILER)
#   define CYTHON_UNUSED __attribute__ ((__unused__)) 
# else
#   define CYTHON_UNUSED 
# endif
#endif
#ifdef __cplusplus
#define __PYX_EXTERN_C extern "C"
#else
#define __PYX_EXTERN_C extern
#endif

#if defined(WIN32) || defined(MS_WINDOWS)
#define _USE_MATH_DEFINES
#endif
#include <math.h>
#define __PYX_HAVE_API__scipy__fftpack___fftpack
#include "npy_defs.h"
#include "npy_arrayobject.h"
#include "npy_descriptor.h"
#include "npy_ufunc_object.h"
#include "npy_api.h"
#include "npy_ironpython.h"
#include "fwrap_ktp_header.h"
#include "_fftpack_fc.h"
#include "string.h"

#if !defined(CYTHON_CCOMPLEX)
#define CYTHON_CCOMPLEX 1
#endif


#ifdef __GNUC__
/* Test for GCC > 2.95 */
#if __GNUC__ > 2 || (__GNUC__ == 2 && (__GNUC_MINOR__ > 95)) 
#define likely(x)   __builtin_expect(!!(x), 1)
#define unlikely(x) __builtin_expect(!!(x), 0)
#else /* __GNUC__ > 2 ... */
#define likely(x)   (x)
#define unlikely(x) (x)
#endif /* __GNUC__ > 2 ... */
#else /* __GNUC__ */
#define likely(x)   (x)
#define unlikely(x) (x)
#endif /* __GNUC__ */
    
static const char * __pyx_cfilenm= __FILE__;


#if !defined(CYTHON_CCOMPLEX)
  #if defined(__cplusplus)
    #define CYTHON_CCOMPLEX 1
  #elif defined(_Complex_I)
    #define CYTHON_CCOMPLEX 1
  #else
    #define CYTHON_CCOMPLEX 0
  #endif
#endif

#if CYTHON_CCOMPLEX
  #ifdef __cplusplus
    #include <complex>
  #else
    #include <complex.h>
  #endif
#endif

#if CYTHON_CCOMPLEX && !defined(__cplusplus) && defined(__sun__) && defined(__GNUC__)
  #undef _Complex_I
  #define _Complex_I 1.0fj
#endif
/* Cython code section 'filename_table' */

static const char *__pyx_f[] = {
  0
};
/* Cython code section 'utility_code_proto_before_types' */
/* Cython code section 'numeric_typedefs' */

typedef int __pyx_t_5scipy_7fftpack_5numpy_npy_int;

typedef double __pyx_t_5scipy_7fftpack_5numpy_double_t;

typedef int __pyx_t_5scipy_7fftpack_5numpy_npy_intp;

typedef signed char __pyx_t_5scipy_7fftpack_5numpy_npy_int8;

typedef signed short __pyx_t_5scipy_7fftpack_5numpy_npy_int16;

typedef signed int __pyx_t_5scipy_7fftpack_5numpy_npy_int32;

typedef signed PY_LONG_LONG __pyx_t_5scipy_7fftpack_5numpy_npy_int64;

typedef unsigned char __pyx_t_5scipy_7fftpack_5numpy_npy_uint8;

typedef unsigned short __pyx_t_5scipy_7fftpack_5numpy_npy_uint16;

typedef unsigned int __pyx_t_5scipy_7fftpack_5numpy_npy_uint32;

typedef unsigned PY_LONG_LONG __pyx_t_5scipy_7fftpack_5numpy_npy_uint64;

typedef float __pyx_t_5scipy_7fftpack_5numpy_npy_float32;

typedef double __pyx_t_5scipy_7fftpack_5numpy_npy_float64;

typedef __pyx_t_5scipy_7fftpack_5numpy_npy_intp __pyx_t_5scipy_7fftpack_5numpy_intp_t;

typedef __pyx_t_5scipy_7fftpack_5numpy_npy_int8 __pyx_t_5scipy_7fftpack_5numpy_int8_t;

typedef __pyx_t_5scipy_7fftpack_5numpy_npy_int16 __pyx_t_5scipy_7fftpack_5numpy_int16_t;

typedef __pyx_t_5scipy_7fftpack_5numpy_npy_int32 __pyx_t_5scipy_7fftpack_5numpy_int32_t;

typedef __pyx_t_5scipy_7fftpack_5numpy_npy_int64 __pyx_t_5scipy_7fftpack_5numpy_int64_t;

typedef __pyx_t_5scipy_7fftpack_5numpy_npy_uint8 __pyx_t_5scipy_7fftpack_5numpy_uint8_t;

typedef __pyx_t_5scipy_7fftpack_5numpy_npy_uint16 __pyx_t_5scipy_7fftpack_5numpy_uint16_t;

typedef __pyx_t_5scipy_7fftpack_5numpy_npy_uint32 __pyx_t_5scipy_7fftpack_5numpy_uint32_t;

typedef __pyx_t_5scipy_7fftpack_5numpy_npy_uint64 __pyx_t_5scipy_7fftpack_5numpy_uint64_t;

typedef __pyx_t_5scipy_7fftpack_5numpy_npy_float32 __pyx_t_5scipy_7fftpack_5numpy_float32_t;

typedef __pyx_t_5scipy_7fftpack_5numpy_npy_float64 __pyx_t_5scipy_7fftpack_5numpy_float64_t;
/* Cython code section 'complex_type_declarations' */

#if CYTHON_CCOMPLEX
  #ifdef __cplusplus
    typedef ::std::complex< float > __pyx_t_float_complex;
  #else
    typedef float _Complex __pyx_t_float_complex;
  #endif
#else
    typedef struct { float real, imag; } __pyx_t_float_complex;
#endif

#if CYTHON_CCOMPLEX
  #ifdef __cplusplus
    typedef ::std::complex< double > __pyx_t_double_complex;
  #else
    typedef double _Complex __pyx_t_double_complex;
  #endif
#else
    typedef struct { double real, imag; } __pyx_t_double_complex;
#endif
/* Cython code section 'type_declarations' */

/* Type declarations */

typedef void (*__pyx_t_5scipy_7fftpack_5numpy_PyUFuncGenericFunction)(char **, __pyx_t_5scipy_7fftpack_5numpy_npy_intp *, __pyx_t_5scipy_7fftpack_5numpy_npy_intp *, void *);

typedef System::Object^ __pyx_t_5scipy_7fftpack_9fwrap_ktp_fw_bytes;

/* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pxd":5
 * cimport _fftpack_fc as fc
 * 
 * cpdef object zfft(object x, object n=*, fwi_integer_t direction=*, object normalize=*, bint overwrite_x=*)             # <<<<<<<<<<<<<<
 * cpdef object drfft(object x, object n=*, fwi_integer_t direction=*, object normalize=*, bint overwrite_x=*)
 * cpdef object zrfft(object x, object n=*, fwi_integer_t direction=*, object normalize=*, bint overwrite_x=*)
 */

public ref struct __pyx_opt_args_5scipy_7fftpack_8_fftpack_zfft {
  int __pyx_n;
  System::Object^ n;
  fwi_integer_t direction;
  System::Object^ normalize;
  int overwrite_x;
};

/* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pxd":6
 * 
 * cpdef object zfft(object x, object n=*, fwi_integer_t direction=*, object normalize=*, bint overwrite_x=*)
 * cpdef object drfft(object x, object n=*, fwi_integer_t direction=*, object normalize=*, bint overwrite_x=*)             # <<<<<<<<<<<<<<
 * cpdef object zrfft(object x, object n=*, fwi_integer_t direction=*, object normalize=*, bint overwrite_x=*)
 * cpdef object zfftnd(object x, object s=*, fwi_integer_t direction=*, object normalize=*, bint overwrite_x=*)
 */

public ref struct __pyx_opt_args_5scipy_7fftpack_8_fftpack_drfft {
  int __pyx_n;
  System::Object^ n;
  fwi_integer_t direction;
  System::Object^ normalize;
  int overwrite_x;
};

/* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pxd":7
 * cpdef object zfft(object x, object n=*, fwi_integer_t direction=*, object normalize=*, bint overwrite_x=*)
 * cpdef object drfft(object x, object n=*, fwi_integer_t direction=*, object normalize=*, bint overwrite_x=*)
 * cpdef object zrfft(object x, object n=*, fwi_integer_t direction=*, object normalize=*, bint overwrite_x=*)             # <<<<<<<<<<<<<<
 * cpdef object zfftnd(object x, object s=*, fwi_integer_t direction=*, object normalize=*, bint overwrite_x=*)
 * cpdef object destroy_zfft_cache()
 */

public ref struct __pyx_opt_args_5scipy_7fftpack_8_fftpack_zrfft {
  int __pyx_n;
  System::Object^ n;
  fwi_integer_t direction;
  System::Object^ normalize;
  int overwrite_x;
};

/* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pxd":8
 * cpdef object drfft(object x, object n=*, fwi_integer_t direction=*, object normalize=*, bint overwrite_x=*)
 * cpdef object zrfft(object x, object n=*, fwi_integer_t direction=*, object normalize=*, bint overwrite_x=*)
 * cpdef object zfftnd(object x, object s=*, fwi_integer_t direction=*, object normalize=*, bint overwrite_x=*)             # <<<<<<<<<<<<<<
 * cpdef object destroy_zfft_cache()
 * cpdef object destroy_zfftnd_cache()
 */

public ref struct __pyx_opt_args_5scipy_7fftpack_8_fftpack_zfftnd {
  int __pyx_n;
  System::Object^ s;
  fwi_integer_t direction;
  System::Object^ normalize;
  int overwrite_x;
};

/* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pxd":12
 * cpdef object destroy_zfftnd_cache()
 * cpdef object destroy_drfft_cache()
 * cpdef object cfft(object x, object n=*, fwi_integer_t direction=*, object normalize=*, bint overwrite_x=*)             # <<<<<<<<<<<<<<
 * cpdef object rfft(object x, object n=*, fwi_integer_t direction=*, object normalize=*, bint overwrite_x=*)
 * cpdef object crfft(object x, object n=*, fwi_integer_t direction=*, object normalize=*, bint overwrite_x=*)
 */

public ref struct __pyx_opt_args_5scipy_7fftpack_8_fftpack_cfft {
  int __pyx_n;
  System::Object^ n;
  fwi_integer_t direction;
  System::Object^ normalize;
  int overwrite_x;
};

/* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pxd":13
 * cpdef object destroy_drfft_cache()
 * cpdef object cfft(object x, object n=*, fwi_integer_t direction=*, object normalize=*, bint overwrite_x=*)
 * cpdef object rfft(object x, object n=*, fwi_integer_t direction=*, object normalize=*, bint overwrite_x=*)             # <<<<<<<<<<<<<<
 * cpdef object crfft(object x, object n=*, fwi_integer_t direction=*, object normalize=*, bint overwrite_x=*)
 * cpdef object cfftnd(object x, object s=*, fwi_integer_t direction=*, object normalize=*, bint overwrite_x=*)
 */

public ref struct __pyx_opt_args_5scipy_7fftpack_8_fftpack_rfft {
  int __pyx_n;
  System::Object^ n;
  fwi_integer_t direction;
  System::Object^ normalize;
  int overwrite_x;
};

/* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pxd":14
 * cpdef object cfft(object x, object n=*, fwi_integer_t direction=*, object normalize=*, bint overwrite_x=*)
 * cpdef object rfft(object x, object n=*, fwi_integer_t direction=*, object normalize=*, bint overwrite_x=*)
 * cpdef object crfft(object x, object n=*, fwi_integer_t direction=*, object normalize=*, bint overwrite_x=*)             # <<<<<<<<<<<<<<
 * cpdef object cfftnd(object x, object s=*, fwi_integer_t direction=*, object normalize=*, bint overwrite_x=*)
 * cpdef object destroy_cfft_cache()
 */

public ref struct __pyx_opt_args_5scipy_7fftpack_8_fftpack_crfft {
  int __pyx_n;
  System::Object^ n;
  fwi_integer_t direction;
  System::Object^ normalize;
  int overwrite_x;
};

/* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pxd":15
 * cpdef object rfft(object x, object n=*, fwi_integer_t direction=*, object normalize=*, bint overwrite_x=*)
 * cpdef object crfft(object x, object n=*, fwi_integer_t direction=*, object normalize=*, bint overwrite_x=*)
 * cpdef object cfftnd(object x, object s=*, fwi_integer_t direction=*, object normalize=*, bint overwrite_x=*)             # <<<<<<<<<<<<<<
 * cpdef object destroy_cfft_cache()
 * cpdef object destroy_cfftnd_cache()
 */

public ref struct __pyx_opt_args_5scipy_7fftpack_8_fftpack_cfftnd {
  int __pyx_n;
  System::Object^ s;
  fwi_integer_t direction;
  System::Object^ normalize;
  int overwrite_x;
};

/* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pxd":19
 * cpdef object destroy_cfftnd_cache()
 * cpdef object destroy_rfft_cache()
 * cpdef object ddct1(object x, object n=*, fwi_integer_t normalize=*, bint overwrite_x=*)             # <<<<<<<<<<<<<<
 * cpdef object ddct2(object x, object n=*, fwi_integer_t normalize=*, bint overwrite_x=*)
 * cpdef object ddct3(object x, object n=*, fwi_integer_t normalize=*, bint overwrite_x=*)
 */

public ref struct __pyx_opt_args_5scipy_7fftpack_8_fftpack_ddct1 {
  int __pyx_n;
  System::Object^ n;
  fwi_integer_t normalize;
  int overwrite_x;
};

/* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pxd":20
 * cpdef object destroy_rfft_cache()
 * cpdef object ddct1(object x, object n=*, fwi_integer_t normalize=*, bint overwrite_x=*)
 * cpdef object ddct2(object x, object n=*, fwi_integer_t normalize=*, bint overwrite_x=*)             # <<<<<<<<<<<<<<
 * cpdef object ddct3(object x, object n=*, fwi_integer_t normalize=*, bint overwrite_x=*)
 * cpdef object dct1(object x, object n=*, fwi_integer_t normalize=*, bint overwrite_x=*)
 */

public ref struct __pyx_opt_args_5scipy_7fftpack_8_fftpack_ddct2 {
  int __pyx_n;
  System::Object^ n;
  fwi_integer_t normalize;
  int overwrite_x;
};

/* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pxd":21
 * cpdef object ddct1(object x, object n=*, fwi_integer_t normalize=*, bint overwrite_x=*)
 * cpdef object ddct2(object x, object n=*, fwi_integer_t normalize=*, bint overwrite_x=*)
 * cpdef object ddct3(object x, object n=*, fwi_integer_t normalize=*, bint overwrite_x=*)             # <<<<<<<<<<<<<<
 * cpdef object dct1(object x, object n=*, fwi_integer_t normalize=*, bint overwrite_x=*)
 * cpdef object dct2(object x, object n=*, fwi_integer_t normalize=*, bint overwrite_x=*)
 */

public ref struct __pyx_opt_args_5scipy_7fftpack_8_fftpack_ddct3 {
  int __pyx_n;
  System::Object^ n;
  fwi_integer_t normalize;
  int overwrite_x;
};

/* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pxd":22
 * cpdef object ddct2(object x, object n=*, fwi_integer_t normalize=*, bint overwrite_x=*)
 * cpdef object ddct3(object x, object n=*, fwi_integer_t normalize=*, bint overwrite_x=*)
 * cpdef object dct1(object x, object n=*, fwi_integer_t normalize=*, bint overwrite_x=*)             # <<<<<<<<<<<<<<
 * cpdef object dct2(object x, object n=*, fwi_integer_t normalize=*, bint overwrite_x=*)
 * cpdef object dct3(object x, object n=*, fwi_integer_t normalize=*, bint overwrite_x=*)
 */

public ref struct __pyx_opt_args_5scipy_7fftpack_8_fftpack_dct1 {
  int __pyx_n;
  System::Object^ n;
  fwi_integer_t normalize;
  int overwrite_x;
};

/* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pxd":23
 * cpdef object ddct3(object x, object n=*, fwi_integer_t normalize=*, bint overwrite_x=*)
 * cpdef object dct1(object x, object n=*, fwi_integer_t normalize=*, bint overwrite_x=*)
 * cpdef object dct2(object x, object n=*, fwi_integer_t normalize=*, bint overwrite_x=*)             # <<<<<<<<<<<<<<
 * cpdef object dct3(object x, object n=*, fwi_integer_t normalize=*, bint overwrite_x=*)
 * cpdef object destroy_ddct2_cache()
 */

public ref struct __pyx_opt_args_5scipy_7fftpack_8_fftpack_dct2 {
  int __pyx_n;
  System::Object^ n;
  fwi_integer_t normalize;
  int overwrite_x;
};

/* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pxd":24
 * cpdef object dct1(object x, object n=*, fwi_integer_t normalize=*, bint overwrite_x=*)
 * cpdef object dct2(object x, object n=*, fwi_integer_t normalize=*, bint overwrite_x=*)
 * cpdef object dct3(object x, object n=*, fwi_integer_t normalize=*, bint overwrite_x=*)             # <<<<<<<<<<<<<<
 * cpdef object destroy_ddct2_cache()
 * cpdef object destroy_ddct1_cache()
 */

public ref struct __pyx_opt_args_5scipy_7fftpack_8_fftpack_dct3 {
  int __pyx_n;
  System::Object^ n;
  fwi_integer_t normalize;
  int overwrite_x;
};
/* Cython code section 'utility_code_proto' */

/* Run-time type information about structs used with buffers */
struct __Pyx_StructField_;

typedef struct {
  const char* name; /* for error messages only */
  struct __Pyx_StructField_* fields;
  size_t size;     /* sizeof(type) */
  char typegroup; /* _R_eal, _C_omplex, Signed _I_nt, _U_nsigned int, _S_truct, _P_ointer, _O_bject */
} __Pyx_TypeInfo;

typedef struct __Pyx_StructField_ {
  __Pyx_TypeInfo* type;
  const char* name;
  size_t offset;
} __Pyx_StructField;

typedef struct {
  __Pyx_StructField* field;
  size_t parent_offset;
} __Pyx_BufFmt_StackElem;


static CYTHON_INLINE void  __Pyx_GetBufferAndValidate(NumpyDotNet::IExtBufferProtocol^& buf, System::Object^ obj, __Pyx_TypeInfo* dtype, int flags, int nd, int cast, __Pyx_BufFmt_StackElem* stack);
static CYTHON_INLINE void __Pyx_SafeReleaseBuffer(NumpyDotNet::IExtBufferProtocol^ info);
static void __Pyx_RaiseBufferIndexError(int axis); /*proto*/
#define __Pyx_BufPtrCContig1d(type, buf, i0, s0) ((type)buf + i0)
static void __Pyx_GetBuffer(System::Object^ obj, NumpyDotNet::IExtBufferProtocol^& view, int flags);
static void __Pyx_ReleaseBuffer(NumpyDotNet::IExtBufferProtocol^ view);

Py_ssize_t __Pyx_zeros[] = {0};
Py_ssize_t __Pyx_minusones[] = {-1};

#if CYTHON_CCOMPLEX
  #ifdef __cplusplus
    #define __Pyx_CREAL(z) ((z).real())
    #define __Pyx_CIMAG(z) ((z).imag())
  #else
    #define __Pyx_CREAL(z) (__real__(z))
    #define __Pyx_CIMAG(z) (__imag__(z))
  #endif
#else
    #define __Pyx_CREAL(z) ((z).real)
    #define __Pyx_CIMAG(z) ((z).imag)
#endif

#if defined(_WIN32) && defined(__cplusplus) && CYTHON_CCOMPLEX
    #define __Pyx_SET_CREAL(z,x) ((z).real(x))
    #define __Pyx_SET_CIMAG(z,y) ((z).imag(y))
#else
    #define __Pyx_SET_CREAL(z,x) __Pyx_CREAL(z) = (x)
    #define __Pyx_SET_CIMAG(z,y) __Pyx_CIMAG(z) = (y)
#endif

static CYTHON_INLINE __pyx_t_float_complex __pyx_t_float_complex_from_parts(float, float);

#if CYTHON_CCOMPLEX
    #define __Pyx_c_eqf(a, b)   ((a)==(b))
    #define __Pyx_c_sumf(a, b)  ((a)+(b))
    #define __Pyx_c_difff(a, b) ((a)-(b))
    #define __Pyx_c_prodf(a, b) ((a)*(b))
    #define __Pyx_c_quotf(a, b) ((a)/(b))
    #define __Pyx_c_negf(a)     (-(a))
  #ifdef __cplusplus
    #define __Pyx_c_is_zerof(z) ((z)==(float)0)
    #define __Pyx_c_conjf(z)    (::std::conj(z))
    /*#define __Pyx_c_absf(z)     (::std::abs(z))*/
  #else
    #define __Pyx_c_is_zerof(z) ((z)==0)
    #define __Pyx_c_conjf(z)    (conjf(z))
    /*#define __Pyx_c_absf(z)     (cabsf(z))*/
 #endif
#else
    static CYTHON_INLINE int __Pyx_c_eqf(__pyx_t_float_complex, __pyx_t_float_complex);
    static CYTHON_INLINE __pyx_t_float_complex __Pyx_c_sumf(__pyx_t_float_complex, __pyx_t_float_complex);
    static CYTHON_INLINE __pyx_t_float_complex __Pyx_c_difff(__pyx_t_float_complex, __pyx_t_float_complex);
    static CYTHON_INLINE __pyx_t_float_complex __Pyx_c_prodf(__pyx_t_float_complex, __pyx_t_float_complex);
    static CYTHON_INLINE __pyx_t_float_complex __Pyx_c_quotf(__pyx_t_float_complex, __pyx_t_float_complex);
    static CYTHON_INLINE __pyx_t_float_complex __Pyx_c_negf(__pyx_t_float_complex);
    static CYTHON_INLINE int __Pyx_c_is_zerof(__pyx_t_float_complex);
    static CYTHON_INLINE __pyx_t_float_complex __Pyx_c_conjf(__pyx_t_float_complex);
    /*static CYTHON_INLINE float __Pyx_c_absf(__pyx_t_float_complex);*/
#endif

static CYTHON_INLINE __pyx_t_double_complex __pyx_t_double_complex_from_parts(double, double);

#if CYTHON_CCOMPLEX
    #define __Pyx_c_eq(a, b)   ((a)==(b))
    #define __Pyx_c_sum(a, b)  ((a)+(b))
    #define __Pyx_c_diff(a, b) ((a)-(b))
    #define __Pyx_c_prod(a, b) ((a)*(b))
    #define __Pyx_c_quot(a, b) ((a)/(b))
    #define __Pyx_c_neg(a)     (-(a))
  #ifdef __cplusplus
    #define __Pyx_c_is_zero(z) ((z)==(double)0)
    #define __Pyx_c_conj(z)    (::std::conj(z))
    /*#define __Pyx_c_abs(z)     (::std::abs(z))*/
  #else
    #define __Pyx_c_is_zero(z) ((z)==0)
    #define __Pyx_c_conj(z)    (conj(z))
    /*#define __Pyx_c_abs(z)     (cabs(z))*/
 #endif
#else
    static CYTHON_INLINE int __Pyx_c_eq(__pyx_t_double_complex, __pyx_t_double_complex);
    static CYTHON_INLINE __pyx_t_double_complex __Pyx_c_sum(__pyx_t_double_complex, __pyx_t_double_complex);
    static CYTHON_INLINE __pyx_t_double_complex __Pyx_c_diff(__pyx_t_double_complex, __pyx_t_double_complex);
    static CYTHON_INLINE __pyx_t_double_complex __Pyx_c_prod(__pyx_t_double_complex, __pyx_t_double_complex);
    static CYTHON_INLINE __pyx_t_double_complex __Pyx_c_quot(__pyx_t_double_complex, __pyx_t_double_complex);
    static CYTHON_INLINE __pyx_t_double_complex __Pyx_c_neg(__pyx_t_double_complex);
    static CYTHON_INLINE int __Pyx_c_is_zero(__pyx_t_double_complex);
    static CYTHON_INLINE __pyx_t_double_complex __Pyx_c_conj(__pyx_t_double_complex);
    /*static CYTHON_INLINE double __Pyx_c_abs(__pyx_t_double_complex);*/
#endif
/* Cython code section 'module_declarations' */
/* Module declarations from numpy */
/* Module declarations from scipy.fftpack.numpy */
/* Module declarations from scipy.fftpack.fwrap_ktp */
/* Module declarations from scipy.fftpack._fftpack_fc */
/* Module declarations from scipy.fftpack._fftpack */
/* Cython code section 'typeinfo' */
static __Pyx_TypeInfo __Pyx_TypeInfo_int = { "int", NULL, sizeof(int), 'I' };
/* Cython code section 'before_global_var' */
#define __Pyx_MODULE_NAME "scipy.fftpack._fftpack"

/* Implementation of scipy.fftpack._fftpack */
namespace clr__fftpack {
  public ref class module__fftpack sealed abstract {
/* Cython code section 'global_var' */
static  CallSite< System::Func< CallSite^, System::Object^, fwi_integer_t >^ >^ __site_cvt_31_0;
static  CallSite< System::Func< CallSite^, System::Object^, int >^ >^ __site_cvt_31_0_1;
static  CallSite< System::Func< CallSite^, System::Object^, fwi_integer_t >^ >^ __site_cvt_fwi_integer_t_51_17;
static  CallSite< System::Func< CallSite^, System::Object^, fwi_integer_t >^ >^ __site_cvt_fwi_integer_t_55_9;
static  CallSite< System::Func< CallSite^, CodeContext^, System::Object^, System::Object^, System::Object^ >^ >^ __site_call1_58_24;
static  CallSite< System::Func< CallSite^, CodeContext^, System::Object^, System::Object^, System::Object^ >^ >^ __site_call1_60_24;
static  CallSite< System::Func< CallSite^, System::Object^, fwi_integer_t >^ >^ __site_cvt_63_0;
static  CallSite< System::Func< CallSite^, System::Object^, int >^ >^ __site_cvt_63_0_1;
static  CallSite< System::Func< CallSite^, System::Object^, fwi_integer_t >^ >^ __site_cvt_fwi_integer_t_83_17;
static  CallSite< System::Func< CallSite^, System::Object^, fwi_integer_t >^ >^ __site_cvt_fwi_integer_t_87_9;
static  CallSite< System::Func< CallSite^, CodeContext^, System::Object^, System::Object^, System::Object^ >^ >^ __site_call1_90_24;
static  CallSite< System::Func< CallSite^, CodeContext^, System::Object^, System::Object^, System::Object^ >^ >^ __site_call1_92_24;
static  CallSite< System::Func< CallSite^, System::Object^, fwi_integer_t >^ >^ __site_cvt_98_0;
static  CallSite< System::Func< CallSite^, System::Object^, int >^ >^ __site_cvt_98_0_1;
static  CallSite< System::Func< CallSite^, System::Object^, fwi_integer_t >^ >^ __site_cvt_fwi_integer_t_118_17;
static  CallSite< System::Func< CallSite^, System::Object^, fwi_integer_t >^ >^ __site_cvt_fwi_integer_t_123_9;
static  CallSite< System::Func< CallSite^, CodeContext^, System::Object^, System::Object^, System::Object^ >^ >^ __site_call1_126_24;
static  CallSite< System::Func< CallSite^, CodeContext^, System::Object^, System::Object^, System::Object^ >^ >^ __site_call1_128_24;
static  CallSite< System::Func< CallSite^, System::Object^, fwi_integer_t >^ >^ __site_cvt_131_0;
static  CallSite< System::Func< CallSite^, System::Object^, int >^ >^ __site_cvt_131_0_1;
static  CallSite< System::Func< CallSite^, System::Object^, fwi_integer_t >^ >^ __site_cvt_fwi_integer_t_151_17;
static  CallSite< System::Func< CallSite^, System::Object^, fwi_integer_t >^ >^ __site_cvt_fwi_integer_t_156_9;
static  CallSite< System::Func< CallSite^, CodeContext^, System::Object^, System::Object^, System::Object^ >^ >^ __site_call1_159_24;
static  CallSite< System::Func< CallSite^, CodeContext^, System::Object^, System::Object^, System::Object^ >^ >^ __site_call1_161_24;
static  CallSite< System::Func< CallSite^, System::Object^, fwi_integer_t >^ >^ __site_cvt_164_0;
static  CallSite< System::Func< CallSite^, System::Object^, int >^ >^ __site_cvt_164_0_1;
static  CallSite< System::Func< CallSite^, System::Object^, fwi_integer_t >^ >^ __site_cvt_fwi_integer_t_184_17;
static  CallSite< System::Func< CallSite^, System::Object^, fwi_integer_t >^ >^ __site_cvt_fwi_integer_t_189_9;
static  CallSite< System::Func< CallSite^, CodeContext^, System::Object^, System::Object^, System::Object^ >^ >^ __site_call1_192_24;
static  CallSite< System::Func< CallSite^, CodeContext^, System::Object^, System::Object^, System::Object^ >^ >^ __site_call1_194_24;
static  CallSite< System::Func< CallSite^, System::Object^, fwi_integer_t >^ >^ __site_cvt_197_0;
static  CallSite< System::Func< CallSite^, System::Object^, int >^ >^ __site_cvt_197_0_1;
static  CallSite< System::Func< CallSite^, System::Object^, fwi_integer_t >^ >^ __site_cvt_fwi_integer_t_217_17;
static  CallSite< System::Func< CallSite^, System::Object^, fwi_integer_t >^ >^ __site_cvt_fwi_integer_t_222_9;
static  CallSite< System::Func< CallSite^, CodeContext^, System::Object^, System::Object^, System::Object^ >^ >^ __site_call1_225_24;
static  CallSite< System::Func< CallSite^, CodeContext^, System::Object^, System::Object^, System::Object^ >^ >^ __site_call1_227_24;
static  CallSite< System::Func< CallSite^, System::Object^, fwi_integer_t >^ >^ __site_cvt_233_0;
static  CallSite< System::Func< CallSite^, System::Object^, int >^ >^ __site_cvt_233_0_1;
static  CallSite< System::Func< CallSite^, System::Object^, fwi_integer_t >^ >^ __site_cvt_fwi_integer_t_256_17;
static  CallSite< System::Func< CallSite^, System::Object^, CodeContext^, System::Object^ >^ >^ __site_get_shape_264_24;
static  CallSite< System::Func< CallSite^, System::Object^, fwi_integer_t >^ >^ __site_cvt_fwi_integer_t_267_23;
static  CallSite< System::Func< CallSite^, CodeContext^, System::Object^, System::Object^, System::Object^ >^ >^ __site_call1_269_24;
static  CallSite< System::Func< CallSite^, CodeContext^, System::Object^, System::Object^, System::Object^ >^ >^ __site_call1_276_24;
static  CallSite< System::Func< CallSite^, System::Object^, fwi_integer_t >^ >^ __site_cvt_280_0;
static  CallSite< System::Func< CallSite^, System::Object^, int >^ >^ __site_cvt_280_0_1;
static  CallSite< System::Func< CallSite^, System::Object^, fwi_integer_t >^ >^ __site_cvt_fwi_integer_t_303_17;
static  CallSite< System::Func< CallSite^, System::Object^, CodeContext^, System::Object^ >^ >^ __site_get_shape_311_24;
static  CallSite< System::Func< CallSite^, System::Object^, fwi_integer_t >^ >^ __site_cvt_fwi_integer_t_314_23;
static  CallSite< System::Func< CallSite^, CodeContext^, System::Object^, System::Object^, System::Object^ >^ >^ __site_call1_316_24;
static  CallSite< System::Func< CallSite^, CodeContext^, System::Object^, System::Object^, System::Object^ >^ >^ __site_call1_323_24;
static  CallSite< System::Func< CallSite^, System::Object^, fwi_integer_t >^ >^ __site_cvt_423_0;
static  CallSite< System::Func< CallSite^, System::Object^, int >^ >^ __site_cvt_423_0_1;
static  CallSite< System::Func< CallSite^, System::Object^, fwi_integer_t >^ >^ __site_cvt_fwi_integer_t_444_9;
static  CallSite< System::Func< CallSite^, CodeContext^, System::Object^, System::Object^, System::Object^ >^ >^ __site_call1_447_24;
static  CallSite< System::Func< CallSite^, CodeContext^, System::Object^, System::Object^, System::Object^ >^ >^ __site_call1_449_24;
static  CallSite< System::Func< CallSite^, System::Object^, fwi_integer_t >^ >^ __site_cvt_452_0;
static  CallSite< System::Func< CallSite^, System::Object^, int >^ >^ __site_cvt_452_0_1;
static  CallSite< System::Func< CallSite^, System::Object^, fwi_integer_t >^ >^ __site_cvt_fwi_integer_t_473_9;
static  CallSite< System::Func< CallSite^, CodeContext^, System::Object^, System::Object^, System::Object^ >^ >^ __site_call1_476_24;
static  CallSite< System::Func< CallSite^, CodeContext^, System::Object^, System::Object^, System::Object^ >^ >^ __site_call1_478_24;
static  CallSite< System::Func< CallSite^, System::Object^, fwi_integer_t >^ >^ __site_cvt_481_0;
static  CallSite< System::Func< CallSite^, System::Object^, int >^ >^ __site_cvt_481_0_1;
static  CallSite< System::Func< CallSite^, System::Object^, fwi_integer_t >^ >^ __site_cvt_fwi_integer_t_502_9;
static  CallSite< System::Func< CallSite^, CodeContext^, System::Object^, System::Object^, System::Object^ >^ >^ __site_call1_505_24;
static  CallSite< System::Func< CallSite^, CodeContext^, System::Object^, System::Object^, System::Object^ >^ >^ __site_call1_507_24;
static  CallSite< System::Func< CallSite^, System::Object^, fwi_integer_t >^ >^ __site_cvt_510_0;
static  CallSite< System::Func< CallSite^, System::Object^, int >^ >^ __site_cvt_510_0_1;
static  CallSite< System::Func< CallSite^, System::Object^, fwi_integer_t >^ >^ __site_cvt_fwi_integer_t_531_9;
static  CallSite< System::Func< CallSite^, CodeContext^, System::Object^, System::Object^, System::Object^ >^ >^ __site_call1_534_24;
static  CallSite< System::Func< CallSite^, CodeContext^, System::Object^, System::Object^, System::Object^ >^ >^ __site_call1_536_24;
static  CallSite< System::Func< CallSite^, System::Object^, fwi_integer_t >^ >^ __site_cvt_539_0;
static  CallSite< System::Func< CallSite^, System::Object^, int >^ >^ __site_cvt_539_0_1;
static  CallSite< System::Func< CallSite^, System::Object^, fwi_integer_t >^ >^ __site_cvt_fwi_integer_t_560_9;
static  CallSite< System::Func< CallSite^, CodeContext^, System::Object^, System::Object^, System::Object^ >^ >^ __site_call1_563_24;
static  CallSite< System::Func< CallSite^, CodeContext^, System::Object^, System::Object^, System::Object^ >^ >^ __site_call1_565_24;
static  CallSite< System::Func< CallSite^, System::Object^, fwi_integer_t >^ >^ __site_cvt_568_0;
static  CallSite< System::Func< CallSite^, System::Object^, int >^ >^ __site_cvt_568_0_1;
static  CallSite< System::Func< CallSite^, System::Object^, fwi_integer_t >^ >^ __site_cvt_fwi_integer_t_589_9;
static  CallSite< System::Func< CallSite^, CodeContext^, System::Object^, System::Object^, System::Object^ >^ >^ __site_call1_592_24;
static  CallSite< System::Func< CallSite^, CodeContext^, System::Object^, System::Object^, System::Object^ >^ >^ __site_call1_594_24;
static  CallSite< System::Func< CallSite^, System::Object^, CodeContext^, System::Object^ >^ >^ __site_get_append_199_18;
static  CallSite< System::Func< CallSite^, CodeContext^, System::Object^, System::Object^, System::Object^ >^ >^ __site_call1_199_25;
static  CallSite< System::Func< CallSite^, System::Object^, CodeContext^, System::Object^ >^ >^ __site_get_zeros_201_16;
static  CallSite< System::Func< CallSite^, CodeContext^, System::Object^, System::Object^, System::Object^, System::Object^, System::Object^ >^ >^ __site_call3_201_22;
static  CallSite< System::Func< CallSite^, System::Object^, CodeContext^, System::Object^ >^ >^ __site_get_append_207_18;
static  CallSite< System::Func< CallSite^, CodeContext^, System::Object^, System::Object^, System::Object^ >^ >^ __site_call1_207_25;
static  CallSite< System::Func< CallSite^, System::Object^, CodeContext^, System::Object^ >^ >^ __site_get_empty_209_16;
static  CallSite< System::Func< CallSite^, CodeContext^, System::Object^, System::Object^, System::Object^, System::Object^, System::Object^ >^ >^ __site_call3_209_22;
static  CallSite< System::Func< CallSite^, System::Object^, CodeContext^, System::Object^ >^ >^ __site_get_Array_218_54;
static  CallSite< System::Func< CallSite^, System::Object^, PY_LONG_LONG >^ >^ __site_cvt_PY_LONG_LONG_218_54;
static  CallSite< System::Func< CallSite^, System::Object^, CodeContext^, System::Object^ >^ >^ __site_get_Array_222_49;
static  CallSite< System::Func< CallSite^, System::Object^, PY_LONG_LONG >^ >^ __site_cvt_PY_LONG_LONG_222_49;
static  CallSite< System::Func< CallSite^, System::Object^, CodeContext^, System::Object^ >^ >^ __site_get_Array_226_49;
static  CallSite< System::Func< CallSite^, System::Object^, PY_LONG_LONG >^ >^ __site_cvt_PY_LONG_LONG_226_49;
static  CallSite< System::Func< CallSite^, System::Object^, CodeContext^, System::Object^ >^ >^ __site_get_Array_230_49;
static  CallSite< System::Func< CallSite^, System::Object^, PY_LONG_LONG >^ >^ __site_cvt_PY_LONG_LONG_230_49;
static  CallSite< System::Func< CallSite^, System::Object^, CodeContext^, System::Object^ >^ >^ __site_get_NpyArray_235_22;
static  CallSite< System::Func< CallSite^, System::Object^, CodeContext^, System::Object^ >^ >^ __site_get_FromAny_235_31;
static  CallSite< System::Func< CallSite^, CodeContext^, System::Object^, System::Object^, System::Object^, System::Object^, System::Object^, System::Object^, System::Object^, System::Object^ >^ >^ __site_call6_235_39;
static  CallSite< System::Func< CallSite^, System::Object^, System::Object^, System::Object^ >^ >^ __site_op_and_238_13;
static  CallSite< System::Func< CallSite^, System::Object^, bool >^ >^ __site_istrue_238_13;
static  CallSite< System::Func< CallSite^, System::Object^, System::Object^, System::Object^ >^ >^ __site_op_ior_239_14;
static  CallSite< System::Func< CallSite^, System::Object^, int >^ >^ __site_cvt_int_240_77;
static  CallSite< System::Func< CallSite^, CodeContext^, System::Object^, System::Object^, System::Object^, System::Object^ >^ >^ __site_call2_243_21;
static  CallSite< System::Func< CallSite^, System::Object^, CodeContext^, System::Object^ >^ >^ __site_get_ndim_246_14;
static CodeContext^ __pyx_context;
/* Cython code section 'decls' */
static int^ __pyx_int_0;
static int^ __pyx_int_1;
/* Cython code section 'all_the_rest' */
public:
static System::String^ __module__ = __Pyx_MODULE_NAME;

/* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":31
 *     void *memcpy(void *dest, void *src, size_t n)
 * # Template for cfft, zfft
 * def cfft(object x, object n=None, fwi_integer_t direction=1, object normalize=None, bint overwrite_x=False):             # <<<<<<<<<<<<<<
 *     """cfft(x[, n, direction, normalize, overwrite_x]) -> x
 * 
 */

static System::Object^ cfft(System::Object^ x, [InteropServices::Optional]System::Object^ n, [InteropServices::Optional]System::Object^ direction, [InteropServices::Optional]System::Object^ normalize, [InteropServices::Optional]System::Object^ overwrite_x) {
  System::Object^ __pyx_v_x = nullptr;
  System::Object^ __pyx_v_n = nullptr;
  fwi_integer_t __pyx_v_direction;
  System::Object^ __pyx_v_normalize = nullptr;
  int __pyx_v_overwrite_x;
  NumpyDotNet::ndarray^ __pyx_v_x_;
  fwi_integer_t __pyx_v_n_;
  fwi_integer_t __pyx_v_normalize_;
  fwi_integer_t __pyx_v_howmany;
  System::Object^ __pyx_r = nullptr;
  System::Object^ __pyx_t_1 = nullptr;
  int __pyx_t_2;
  System::Object^ __pyx_t_3 = nullptr;
  fwi_integer_t __pyx_t_4;
  long __pyx_t_5;
  System::Object^ __pyx_t_6 = nullptr;
  fwi_integer_t __pyx_t_7;
  __pyx_v_x = x;
  if (dynamic_cast<System::Reflection::Missing^>(n) == nullptr) {
    __pyx_v_n = n;
  } else {
    __pyx_v_n = ((System::Object^)nullptr);
  }
  if (dynamic_cast<System::Reflection::Missing^>(direction) == nullptr) {
    __pyx_v_direction = __site_cvt_31_0->Target(__site_cvt_31_0, direction);
  } else {
    __pyx_v_direction = ((fwi_integer_t)1);
  }
  if (dynamic_cast<System::Reflection::Missing^>(normalize) == nullptr) {
    __pyx_v_normalize = normalize;
  } else {
    __pyx_v_normalize = ((System::Object^)nullptr);
  }
  if (dynamic_cast<System::Reflection::Missing^>(overwrite_x) == nullptr) {
    __pyx_v_overwrite_x = __site_cvt_31_0_1->Target(__site_cvt_31_0_1, overwrite_x);
  } else {
    __pyx_v_overwrite_x = ((int)0);
  }
  __pyx_v_x_ = nullptr;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":51
 *     cdef fwi_integer_t normalize_
 *     cdef fwi_integer_t howmany
 *     normalize_ = normalize if (normalize is not None) else direction < 0             # <<<<<<<<<<<<<<
 *     x_ = np.PyArray_FROMANY(x, fwc_complex_x8_t_enum, 0, 0,
 *                             np.NPY_C_CONTIGUOUS | np.NPY_FORCECAST |
 */
  __pyx_t_2 = (__pyx_v_normalize != nullptr);
  if (__pyx_t_2) {
    __pyx_t_1 = __pyx_v_normalize;
  } else {
    __pyx_t_3 = (__pyx_v_direction < 0);
    __pyx_t_1 = __pyx_t_3;
    __pyx_t_3 = nullptr;
  }
  __pyx_t_4 = __site_cvt_fwi_integer_t_51_17->Target(__site_cvt_fwi_integer_t_51_17, __pyx_t_1);
  __pyx_t_1 = nullptr;
  __pyx_v_normalize_ = __pyx_t_4;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":52
 *     cdef fwi_integer_t howmany
 *     normalize_ = normalize if (normalize is not None) else direction < 0
 *     x_ = np.PyArray_FROMANY(x, fwc_complex_x8_t_enum, 0, 0,             # <<<<<<<<<<<<<<
 *                             np.NPY_C_CONTIGUOUS | np.NPY_FORCECAST |
 *                             (0 if overwrite_x else np.NPY_ENSURECOPY))
 */
  __pyx_t_1 = (System::Object^)(long long)(NPY_CFLOAT);

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":54
 *     x_ = np.PyArray_FROMANY(x, fwc_complex_x8_t_enum, 0, 0,
 *                             np.NPY_C_CONTIGUOUS | np.NPY_FORCECAST |
 *                             (0 if overwrite_x else np.NPY_ENSURECOPY))             # <<<<<<<<<<<<<<
 *     n_ = n if (n is not None) else np.PyArray_SIZE(x_)
 *     howmany = np.PyArray_SIZE(x_) // n_
 */
  if (__pyx_v_overwrite_x) {
    __pyx_t_5 = 0;
  } else {
    __pyx_t_5 = NPY_ENSURECOPY;
  }
  __pyx_t_3 = ((NPY_C_CONTIGUOUS | NPY_FORCECAST) | __pyx_t_5);
  __pyx_t_6 = PyArray_FROMANY(__pyx_v_x, __pyx_t_1, __pyx_int_0, __pyx_int_0, __pyx_t_3); 
  __pyx_t_1 = nullptr;
  __pyx_t_3 = nullptr;
  if (__pyx_t_6 == nullptr || dynamic_cast<NumpyDotNet::ndarray^>(__pyx_t_6) == nullptr) {
    throw PythonOps::MakeException(__pyx_context, PythonOps::GetGlobal(__pyx_context, "TypeError"), "type error", nullptr);
  }
  __pyx_v_x_ = ((NumpyDotNet::ndarray^)__pyx_t_6);
  __pyx_t_6 = nullptr;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":55
 *                             np.NPY_C_CONTIGUOUS | np.NPY_FORCECAST |
 *                             (0 if overwrite_x else np.NPY_ENSURECOPY))
 *     n_ = n if (n is not None) else np.PyArray_SIZE(x_)             # <<<<<<<<<<<<<<
 *     howmany = np.PyArray_SIZE(x_) // n_
 *     if not (n_ > 0):
 */
  __pyx_t_2 = (__pyx_v_n != nullptr);
  if (__pyx_t_2) {
    __pyx_t_6 = __pyx_v_n;
  } else {
    __pyx_t_3 = PyArray_SIZE(__pyx_v_x_);
    __pyx_t_6 = __pyx_t_3;
    __pyx_t_3 = nullptr;
  }
  __pyx_t_7 = __site_cvt_fwi_integer_t_55_9->Target(__site_cvt_fwi_integer_t_55_9, __pyx_t_6);
  __pyx_t_6 = nullptr;
  __pyx_v_n_ = __pyx_t_7;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":56
 *                             (0 if overwrite_x else np.NPY_ENSURECOPY))
 *     n_ = n if (n is not None) else np.PyArray_SIZE(x_)
 *     howmany = np.PyArray_SIZE(x_) // n_             # <<<<<<<<<<<<<<
 *     if not (n_ > 0):
 *         raise ValueError('Condition on arguments not satisfied: n > 0')
 */
  __pyx_v_howmany = (PyArray_SIZE(__pyx_v_x_) / __pyx_v_n_);

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":57
 *     n_ = n if (n is not None) else np.PyArray_SIZE(x_)
 *     howmany = np.PyArray_SIZE(x_) // n_
 *     if not (n_ > 0):             # <<<<<<<<<<<<<<
 *         raise ValueError('Condition on arguments not satisfied: n > 0')
 *     if not ((n_ * howmany) == np.PyArray_SIZE(x_)):
 */
  __pyx_t_2 = (!(__pyx_v_n_ > 0));
  if (__pyx_t_2) {

    /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":58
 *     howmany = np.PyArray_SIZE(x_) // n_
 *     if not (n_ > 0):
 *         raise ValueError('Condition on arguments not satisfied: n > 0')             # <<<<<<<<<<<<<<
 *     if not ((n_ * howmany) == np.PyArray_SIZE(x_)):
 *         raise ValueError('Condition on arguments not satisfied: (n * howmany) == x.size')
 */
    __pyx_t_6 = PythonOps::GetGlobal(__pyx_context, "ValueError");
    __pyx_t_3 = __site_call1_58_24->Target(__site_call1_58_24, __pyx_context, __pyx_t_6, ((System::Object^)"Condition on arguments not satisfied: n > 0"));
    __pyx_t_6 = nullptr;
    throw PythonOps::MakeException(__pyx_context, __pyx_t_3, nullptr, nullptr);
    __pyx_t_3 = nullptr;
    goto __pyx_L5;
  }
  __pyx_L5:;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":59
 *     if not (n_ > 0):
 *         raise ValueError('Condition on arguments not satisfied: n > 0')
 *     if not ((n_ * howmany) == np.PyArray_SIZE(x_)):             # <<<<<<<<<<<<<<
 *         raise ValueError('Condition on arguments not satisfied: (n * howmany) == x.size')
 *     fc.cfft(<fwc_complex_x8_t*>np.PyArray_DATA(x_), n_, direction, howmany, normalize_)
 */
  __pyx_t_2 = (!((__pyx_v_n_ * __pyx_v_howmany) == PyArray_SIZE(__pyx_v_x_)));
  if (__pyx_t_2) {

    /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":60
 *         raise ValueError('Condition on arguments not satisfied: n > 0')
 *     if not ((n_ * howmany) == np.PyArray_SIZE(x_)):
 *         raise ValueError('Condition on arguments not satisfied: (n * howmany) == x.size')             # <<<<<<<<<<<<<<
 *     fc.cfft(<fwc_complex_x8_t*>np.PyArray_DATA(x_), n_, direction, howmany, normalize_)
 *     return x_
 */
    __pyx_t_3 = PythonOps::GetGlobal(__pyx_context, "ValueError");
    __pyx_t_6 = __site_call1_60_24->Target(__site_call1_60_24, __pyx_context, __pyx_t_3, ((System::Object^)"Condition on arguments not satisfied: (n * howmany) == x.size"));
    __pyx_t_3 = nullptr;
    throw PythonOps::MakeException(__pyx_context, __pyx_t_6, nullptr, nullptr);
    __pyx_t_6 = nullptr;
    goto __pyx_L6;
  }
  __pyx_L6:;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":61
 *     if not ((n_ * howmany) == np.PyArray_SIZE(x_)):
 *         raise ValueError('Condition on arguments not satisfied: (n * howmany) == x.size')
 *     fc.cfft(<fwc_complex_x8_t*>np.PyArray_DATA(x_), n_, direction, howmany, normalize_)             # <<<<<<<<<<<<<<
 *     return x_
 * def zfft(object x, object n=None, fwi_integer_t direction=1, object normalize=None, bint overwrite_x=False):
 */
  GLOBALFUNC(cfft)(((__pyx_t_float_complex *)PyArray_DATA(__pyx_v_x_)), __pyx_v_n_, __pyx_v_direction, __pyx_v_howmany, __pyx_v_normalize_);

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":62
 *         raise ValueError('Condition on arguments not satisfied: (n * howmany) == x.size')
 *     fc.cfft(<fwc_complex_x8_t*>np.PyArray_DATA(x_), n_, direction, howmany, normalize_)
 *     return x_             # <<<<<<<<<<<<<<
 * def zfft(object x, object n=None, fwi_integer_t direction=1, object normalize=None, bint overwrite_x=False):
 *     """zfft(x[, n, direction, normalize, overwrite_x]) -> x
 */
  __pyx_r = ((System::Object^)__pyx_v_x_);
  goto __pyx_L0;

  __pyx_r = nullptr;
  __pyx_L0:;
  return __pyx_r;
}

/* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":63
 *     fc.cfft(<fwc_complex_x8_t*>np.PyArray_DATA(x_), n_, direction, howmany, normalize_)
 *     return x_
 * def zfft(object x, object n=None, fwi_integer_t direction=1, object normalize=None, bint overwrite_x=False):             # <<<<<<<<<<<<<<
 *     """zfft(x[, n, direction, normalize, overwrite_x]) -> x
 * 
 */

static System::Object^ zfft(System::Object^ x, [InteropServices::Optional]System::Object^ n, [InteropServices::Optional]System::Object^ direction, [InteropServices::Optional]System::Object^ normalize, [InteropServices::Optional]System::Object^ overwrite_x) {
  System::Object^ __pyx_v_x = nullptr;
  System::Object^ __pyx_v_n = nullptr;
  fwi_integer_t __pyx_v_direction;
  System::Object^ __pyx_v_normalize = nullptr;
  int __pyx_v_overwrite_x;
  NumpyDotNet::ndarray^ __pyx_v_x_;
  fwi_integer_t __pyx_v_n_;
  fwi_integer_t __pyx_v_normalize_;
  fwi_integer_t __pyx_v_howmany;
  System::Object^ __pyx_r = nullptr;
  System::Object^ __pyx_t_1 = nullptr;
  int __pyx_t_2;
  System::Object^ __pyx_t_3 = nullptr;
  fwi_integer_t __pyx_t_4;
  long __pyx_t_5;
  System::Object^ __pyx_t_6 = nullptr;
  fwi_integer_t __pyx_t_7;
  __pyx_v_x = x;
  if (dynamic_cast<System::Reflection::Missing^>(n) == nullptr) {
    __pyx_v_n = n;
  } else {
    __pyx_v_n = ((System::Object^)nullptr);
  }
  if (dynamic_cast<System::Reflection::Missing^>(direction) == nullptr) {
    __pyx_v_direction = __site_cvt_63_0->Target(__site_cvt_63_0, direction);
  } else {
    __pyx_v_direction = ((fwi_integer_t)1);
  }
  if (dynamic_cast<System::Reflection::Missing^>(normalize) == nullptr) {
    __pyx_v_normalize = normalize;
  } else {
    __pyx_v_normalize = ((System::Object^)nullptr);
  }
  if (dynamic_cast<System::Reflection::Missing^>(overwrite_x) == nullptr) {
    __pyx_v_overwrite_x = __site_cvt_63_0_1->Target(__site_cvt_63_0_1, overwrite_x);
  } else {
    __pyx_v_overwrite_x = ((int)0);
  }
  __pyx_v_x_ = nullptr;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":83
 *     cdef fwi_integer_t normalize_
 *     cdef fwi_integer_t howmany
 *     normalize_ = normalize if (normalize is not None) else direction < 0             # <<<<<<<<<<<<<<
 *     x_ = np.PyArray_FROMANY(x, fwc_complex_x16_t_enum, 0, 0,
 *                             np.NPY_C_CONTIGUOUS | np.NPY_FORCECAST |
 */
  __pyx_t_2 = (__pyx_v_normalize != nullptr);
  if (__pyx_t_2) {
    __pyx_t_1 = __pyx_v_normalize;
  } else {
    __pyx_t_3 = (__pyx_v_direction < 0);
    __pyx_t_1 = __pyx_t_3;
    __pyx_t_3 = nullptr;
  }
  __pyx_t_4 = __site_cvt_fwi_integer_t_83_17->Target(__site_cvt_fwi_integer_t_83_17, __pyx_t_1);
  __pyx_t_1 = nullptr;
  __pyx_v_normalize_ = __pyx_t_4;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":84
 *     cdef fwi_integer_t howmany
 *     normalize_ = normalize if (normalize is not None) else direction < 0
 *     x_ = np.PyArray_FROMANY(x, fwc_complex_x16_t_enum, 0, 0,             # <<<<<<<<<<<<<<
 *                             np.NPY_C_CONTIGUOUS | np.NPY_FORCECAST |
 *                             (0 if overwrite_x else np.NPY_ENSURECOPY))
 */
  __pyx_t_1 = (System::Object^)(long long)(NPY_CDOUBLE);

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":86
 *     x_ = np.PyArray_FROMANY(x, fwc_complex_x16_t_enum, 0, 0,
 *                             np.NPY_C_CONTIGUOUS | np.NPY_FORCECAST |
 *                             (0 if overwrite_x else np.NPY_ENSURECOPY))             # <<<<<<<<<<<<<<
 *     n_ = n if (n is not None) else np.PyArray_SIZE(x_)
 *     howmany = np.PyArray_SIZE(x_) // n_
 */
  if (__pyx_v_overwrite_x) {
    __pyx_t_5 = 0;
  } else {
    __pyx_t_5 = NPY_ENSURECOPY;
  }
  __pyx_t_3 = ((NPY_C_CONTIGUOUS | NPY_FORCECAST) | __pyx_t_5);
  __pyx_t_6 = PyArray_FROMANY(__pyx_v_x, __pyx_t_1, __pyx_int_0, __pyx_int_0, __pyx_t_3); 
  __pyx_t_1 = nullptr;
  __pyx_t_3 = nullptr;
  if (__pyx_t_6 == nullptr || dynamic_cast<NumpyDotNet::ndarray^>(__pyx_t_6) == nullptr) {
    throw PythonOps::MakeException(__pyx_context, PythonOps::GetGlobal(__pyx_context, "TypeError"), "type error", nullptr);
  }
  __pyx_v_x_ = ((NumpyDotNet::ndarray^)__pyx_t_6);
  __pyx_t_6 = nullptr;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":87
 *                             np.NPY_C_CONTIGUOUS | np.NPY_FORCECAST |
 *                             (0 if overwrite_x else np.NPY_ENSURECOPY))
 *     n_ = n if (n is not None) else np.PyArray_SIZE(x_)             # <<<<<<<<<<<<<<
 *     howmany = np.PyArray_SIZE(x_) // n_
 *     if not (n_ > 0):
 */
  __pyx_t_2 = (__pyx_v_n != nullptr);
  if (__pyx_t_2) {
    __pyx_t_6 = __pyx_v_n;
  } else {
    __pyx_t_3 = PyArray_SIZE(__pyx_v_x_);
    __pyx_t_6 = __pyx_t_3;
    __pyx_t_3 = nullptr;
  }
  __pyx_t_7 = __site_cvt_fwi_integer_t_87_9->Target(__site_cvt_fwi_integer_t_87_9, __pyx_t_6);
  __pyx_t_6 = nullptr;
  __pyx_v_n_ = __pyx_t_7;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":88
 *                             (0 if overwrite_x else np.NPY_ENSURECOPY))
 *     n_ = n if (n is not None) else np.PyArray_SIZE(x_)
 *     howmany = np.PyArray_SIZE(x_) // n_             # <<<<<<<<<<<<<<
 *     if not (n_ > 0):
 *         raise ValueError('Condition on arguments not satisfied: n > 0')
 */
  __pyx_v_howmany = (PyArray_SIZE(__pyx_v_x_) / __pyx_v_n_);

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":89
 *     n_ = n if (n is not None) else np.PyArray_SIZE(x_)
 *     howmany = np.PyArray_SIZE(x_) // n_
 *     if not (n_ > 0):             # <<<<<<<<<<<<<<
 *         raise ValueError('Condition on arguments not satisfied: n > 0')
 *     if not ((n_ * howmany) == np.PyArray_SIZE(x_)):
 */
  __pyx_t_2 = (!(__pyx_v_n_ > 0));
  if (__pyx_t_2) {

    /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":90
 *     howmany = np.PyArray_SIZE(x_) // n_
 *     if not (n_ > 0):
 *         raise ValueError('Condition on arguments not satisfied: n > 0')             # <<<<<<<<<<<<<<
 *     if not ((n_ * howmany) == np.PyArray_SIZE(x_)):
 *         raise ValueError('Condition on arguments not satisfied: (n * howmany) == x.size')
 */
    __pyx_t_6 = PythonOps::GetGlobal(__pyx_context, "ValueError");
    __pyx_t_3 = __site_call1_90_24->Target(__site_call1_90_24, __pyx_context, __pyx_t_6, ((System::Object^)"Condition on arguments not satisfied: n > 0"));
    __pyx_t_6 = nullptr;
    throw PythonOps::MakeException(__pyx_context, __pyx_t_3, nullptr, nullptr);
    __pyx_t_3 = nullptr;
    goto __pyx_L5;
  }
  __pyx_L5:;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":91
 *     if not (n_ > 0):
 *         raise ValueError('Condition on arguments not satisfied: n > 0')
 *     if not ((n_ * howmany) == np.PyArray_SIZE(x_)):             # <<<<<<<<<<<<<<
 *         raise ValueError('Condition on arguments not satisfied: (n * howmany) == x.size')
 *     fc.zfft(<fwc_complex_x16_t*>np.PyArray_DATA(x_), n_, direction, howmany, normalize_)
 */
  __pyx_t_2 = (!((__pyx_v_n_ * __pyx_v_howmany) == PyArray_SIZE(__pyx_v_x_)));
  if (__pyx_t_2) {

    /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":92
 *         raise ValueError('Condition on arguments not satisfied: n > 0')
 *     if not ((n_ * howmany) == np.PyArray_SIZE(x_)):
 *         raise ValueError('Condition on arguments not satisfied: (n * howmany) == x.size')             # <<<<<<<<<<<<<<
 *     fc.zfft(<fwc_complex_x16_t*>np.PyArray_DATA(x_), n_, direction, howmany, normalize_)
 *     return x_
 */
    __pyx_t_3 = PythonOps::GetGlobal(__pyx_context, "ValueError");
    __pyx_t_6 = __site_call1_92_24->Target(__site_call1_92_24, __pyx_context, __pyx_t_3, ((System::Object^)"Condition on arguments not satisfied: (n * howmany) == x.size"));
    __pyx_t_3 = nullptr;
    throw PythonOps::MakeException(__pyx_context, __pyx_t_6, nullptr, nullptr);
    __pyx_t_6 = nullptr;
    goto __pyx_L6;
  }
  __pyx_L6:;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":93
 *     if not ((n_ * howmany) == np.PyArray_SIZE(x_)):
 *         raise ValueError('Condition on arguments not satisfied: (n * howmany) == x.size')
 *     fc.zfft(<fwc_complex_x16_t*>np.PyArray_DATA(x_), n_, direction, howmany, normalize_)             # <<<<<<<<<<<<<<
 *     return x_
 * 
 */
  GLOBALFUNC(zfft)(((__pyx_t_double_complex *)PyArray_DATA(__pyx_v_x_)), __pyx_v_n_, __pyx_v_direction, __pyx_v_howmany, __pyx_v_normalize_);

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":94
 *         raise ValueError('Condition on arguments not satisfied: (n * howmany) == x.size')
 *     fc.zfft(<fwc_complex_x16_t*>np.PyArray_DATA(x_), n_, direction, howmany, normalize_)
 *     return x_             # <<<<<<<<<<<<<<
 * 
 * 
 */
  __pyx_r = ((System::Object^)__pyx_v_x_);
  goto __pyx_L0;

  __pyx_r = nullptr;
  __pyx_L0:;
  return __pyx_r;
}

/* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":98
 * 
 * # Template for rfft, drfft, crfft, zrfft
 * def rfft(object x, object n=None, fwi_integer_t direction=1, object normalize=None, bint overwrite_x=False):             # <<<<<<<<<<<<<<
 *     """rfft(x[, n, direction, normalize, overwrite_x]) -> x
 * 
 */

static System::Object^ rfft(System::Object^ x, [InteropServices::Optional]System::Object^ n, [InteropServices::Optional]System::Object^ direction, [InteropServices::Optional]System::Object^ normalize, [InteropServices::Optional]System::Object^ overwrite_x) {
  System::Object^ __pyx_v_x = nullptr;
  System::Object^ __pyx_v_n = nullptr;
  fwi_integer_t __pyx_v_direction;
  System::Object^ __pyx_v_normalize = nullptr;
  int __pyx_v_overwrite_x;
  NumpyDotNet::ndarray^ __pyx_v_x_;
  fwi_integer_t __pyx_v_n_;
  fwi_integer_t __pyx_v_normalize_;
  fwi_integer_t __pyx_v_howmany;
  System::Object^ __pyx_r = nullptr;
  System::Object^ __pyx_t_1 = nullptr;
  int __pyx_t_2;
  System::Object^ __pyx_t_3 = nullptr;
  fwi_integer_t __pyx_t_4;
  long __pyx_t_5;
  System::Object^ __pyx_t_6 = nullptr;
  fwi_integer_t __pyx_t_7;
  int __pyx_t_8;
  int __pyx_t_9;
  __pyx_v_x = x;
  if (dynamic_cast<System::Reflection::Missing^>(n) == nullptr) {
    __pyx_v_n = n;
  } else {
    __pyx_v_n = ((System::Object^)nullptr);
  }
  if (dynamic_cast<System::Reflection::Missing^>(direction) == nullptr) {
    __pyx_v_direction = __site_cvt_98_0->Target(__site_cvt_98_0, direction);
  } else {
    __pyx_v_direction = ((fwi_integer_t)1);
  }
  if (dynamic_cast<System::Reflection::Missing^>(normalize) == nullptr) {
    __pyx_v_normalize = normalize;
  } else {
    __pyx_v_normalize = ((System::Object^)nullptr);
  }
  if (dynamic_cast<System::Reflection::Missing^>(overwrite_x) == nullptr) {
    __pyx_v_overwrite_x = __site_cvt_98_0_1->Target(__site_cvt_98_0_1, overwrite_x);
  } else {
    __pyx_v_overwrite_x = ((int)0);
  }
  __pyx_v_x_ = nullptr;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":118
 *     cdef fwi_integer_t normalize_
 *     cdef fwi_integer_t howmany
 *     normalize_ = normalize if (normalize is not None) else direction < 0             # <<<<<<<<<<<<<<
 *     # First, convert x to an array with arbitrary number of dimensions
 *     x_ = np.PyArray_FROMANY(x, fwr_real_x4_t_enum, 0, 0,
 */
  __pyx_t_2 = (__pyx_v_normalize != nullptr);
  if (__pyx_t_2) {
    __pyx_t_1 = __pyx_v_normalize;
  } else {
    __pyx_t_3 = (__pyx_v_direction < 0);
    __pyx_t_1 = __pyx_t_3;
    __pyx_t_3 = nullptr;
  }
  __pyx_t_4 = __site_cvt_fwi_integer_t_118_17->Target(__site_cvt_fwi_integer_t_118_17, __pyx_t_1);
  __pyx_t_1 = nullptr;
  __pyx_v_normalize_ = __pyx_t_4;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":120
 *     normalize_ = normalize if (normalize is not None) else direction < 0
 *     # First, convert x to an array with arbitrary number of dimensions
 *     x_ = np.PyArray_FROMANY(x, fwr_real_x4_t_enum, 0, 0,             # <<<<<<<<<<<<<<
 *                             np.NPY_C_CONTIGUOUS | np.NPY_FORCECAST |
 *                             (0 if overwrite_x else np.NPY_ENSURECOPY))
 */
  __pyx_t_1 = (System::Object^)(long long)(NPY_FLOAT32);

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":122
 *     x_ = np.PyArray_FROMANY(x, fwr_real_x4_t_enum, 0, 0,
 *                             np.NPY_C_CONTIGUOUS | np.NPY_FORCECAST |
 *                             (0 if overwrite_x else np.NPY_ENSURECOPY))             # <<<<<<<<<<<<<<
 *     n_ = n if (n is not None) else np.PyArray_SIZE(x_)
 *     howmany = np.PyArray_SIZE(x_) // n_
 */
  if (__pyx_v_overwrite_x) {
    __pyx_t_5 = 0;
  } else {
    __pyx_t_5 = NPY_ENSURECOPY;
  }
  __pyx_t_3 = ((NPY_C_CONTIGUOUS | NPY_FORCECAST) | __pyx_t_5);
  __pyx_t_6 = PyArray_FROMANY(__pyx_v_x, __pyx_t_1, __pyx_int_0, __pyx_int_0, __pyx_t_3); 
  __pyx_t_1 = nullptr;
  __pyx_t_3 = nullptr;
  if (__pyx_t_6 == nullptr || dynamic_cast<NumpyDotNet::ndarray^>(__pyx_t_6) == nullptr) {
    throw PythonOps::MakeException(__pyx_context, PythonOps::GetGlobal(__pyx_context, "TypeError"), "type error", nullptr);
  }
  __pyx_v_x_ = ((NumpyDotNet::ndarray^)__pyx_t_6);
  __pyx_t_6 = nullptr;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":123
 *                             np.NPY_C_CONTIGUOUS | np.NPY_FORCECAST |
 *                             (0 if overwrite_x else np.NPY_ENSURECOPY))
 *     n_ = n if (n is not None) else np.PyArray_SIZE(x_)             # <<<<<<<<<<<<<<
 *     howmany = np.PyArray_SIZE(x_) // n_
 *     if not ((n_ > 0) and (n_ <= np.PyArray_SIZE(x_))):
 */
  __pyx_t_2 = (__pyx_v_n != nullptr);
  if (__pyx_t_2) {
    __pyx_t_6 = __pyx_v_n;
  } else {
    __pyx_t_3 = PyArray_SIZE(__pyx_v_x_);
    __pyx_t_6 = __pyx_t_3;
    __pyx_t_3 = nullptr;
  }
  __pyx_t_7 = __site_cvt_fwi_integer_t_123_9->Target(__site_cvt_fwi_integer_t_123_9, __pyx_t_6);
  __pyx_t_6 = nullptr;
  __pyx_v_n_ = __pyx_t_7;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":124
 *                             (0 if overwrite_x else np.NPY_ENSURECOPY))
 *     n_ = n if (n is not None) else np.PyArray_SIZE(x_)
 *     howmany = np.PyArray_SIZE(x_) // n_             # <<<<<<<<<<<<<<
 *     if not ((n_ > 0) and (n_ <= np.PyArray_SIZE(x_))):
 *         raise ValueError('Condition on arguments not satisfied: (n > 0) and (n <= x.size)')
 */
  __pyx_v_howmany = (PyArray_SIZE(__pyx_v_x_) / __pyx_v_n_);

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":125
 *     n_ = n if (n is not None) else np.PyArray_SIZE(x_)
 *     howmany = np.PyArray_SIZE(x_) // n_
 *     if not ((n_ > 0) and (n_ <= np.PyArray_SIZE(x_))):             # <<<<<<<<<<<<<<
 *         raise ValueError('Condition on arguments not satisfied: (n > 0) and (n <= x.size)')
 *     if not ((n_ * howmany) == np.PyArray_SIZE(x_)):
 */
  __pyx_t_2 = (__pyx_v_n_ > 0);
  if (__pyx_t_2) {
    __pyx_t_8 = (__pyx_v_n_ <= PyArray_SIZE(__pyx_v_x_));
    __pyx_t_9 = __pyx_t_8;
  } else {
    __pyx_t_9 = __pyx_t_2;
  }
  __pyx_t_2 = (!__pyx_t_9);
  if (__pyx_t_2) {

    /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":126
 *     howmany = np.PyArray_SIZE(x_) // n_
 *     if not ((n_ > 0) and (n_ <= np.PyArray_SIZE(x_))):
 *         raise ValueError('Condition on arguments not satisfied: (n > 0) and (n <= x.size)')             # <<<<<<<<<<<<<<
 *     if not ((n_ * howmany) == np.PyArray_SIZE(x_)):
 *         raise ValueError('Condition on arguments not satisfied: (n * howmany) == x.size')
 */
    __pyx_t_6 = PythonOps::GetGlobal(__pyx_context, "ValueError");
    __pyx_t_3 = __site_call1_126_24->Target(__site_call1_126_24, __pyx_context, __pyx_t_6, ((System::Object^)"Condition on arguments not satisfied: (n > 0) and (n <= x.size)"));
    __pyx_t_6 = nullptr;
    throw PythonOps::MakeException(__pyx_context, __pyx_t_3, nullptr, nullptr);
    __pyx_t_3 = nullptr;
    goto __pyx_L5;
  }
  __pyx_L5:;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":127
 *     if not ((n_ > 0) and (n_ <= np.PyArray_SIZE(x_))):
 *         raise ValueError('Condition on arguments not satisfied: (n > 0) and (n <= x.size)')
 *     if not ((n_ * howmany) == np.PyArray_SIZE(x_)):             # <<<<<<<<<<<<<<
 *         raise ValueError('Condition on arguments not satisfied: (n * howmany) == x.size')
 *     fc.rfft(<fwr_real_x4_t*>np.PyArray_DATA(x_), n_, direction, howmany, normalize_)
 */
  __pyx_t_2 = (!((__pyx_v_n_ * __pyx_v_howmany) == PyArray_SIZE(__pyx_v_x_)));
  if (__pyx_t_2) {

    /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":128
 *         raise ValueError('Condition on arguments not satisfied: (n > 0) and (n <= x.size)')
 *     if not ((n_ * howmany) == np.PyArray_SIZE(x_)):
 *         raise ValueError('Condition on arguments not satisfied: (n * howmany) == x.size')             # <<<<<<<<<<<<<<
 *     fc.rfft(<fwr_real_x4_t*>np.PyArray_DATA(x_), n_, direction, howmany, normalize_)
 *     return x_
 */
    __pyx_t_3 = PythonOps::GetGlobal(__pyx_context, "ValueError");
    __pyx_t_6 = __site_call1_128_24->Target(__site_call1_128_24, __pyx_context, __pyx_t_3, ((System::Object^)"Condition on arguments not satisfied: (n * howmany) == x.size"));
    __pyx_t_3 = nullptr;
    throw PythonOps::MakeException(__pyx_context, __pyx_t_6, nullptr, nullptr);
    __pyx_t_6 = nullptr;
    goto __pyx_L6;
  }
  __pyx_L6:;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":129
 *     if not ((n_ * howmany) == np.PyArray_SIZE(x_)):
 *         raise ValueError('Condition on arguments not satisfied: (n * howmany) == x.size')
 *     fc.rfft(<fwr_real_x4_t*>np.PyArray_DATA(x_), n_, direction, howmany, normalize_)             # <<<<<<<<<<<<<<
 *     return x_
 * def drfft(object x, object n=None, fwi_integer_t direction=1, object normalize=None, bint overwrite_x=False):
 */
  GLOBALFUNC(rfft)(((fwr_real_x4_t *)PyArray_DATA(__pyx_v_x_)), __pyx_v_n_, __pyx_v_direction, __pyx_v_howmany, __pyx_v_normalize_);

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":130
 *         raise ValueError('Condition on arguments not satisfied: (n * howmany) == x.size')
 *     fc.rfft(<fwr_real_x4_t*>np.PyArray_DATA(x_), n_, direction, howmany, normalize_)
 *     return x_             # <<<<<<<<<<<<<<
 * def drfft(object x, object n=None, fwi_integer_t direction=1, object normalize=None, bint overwrite_x=False):
 *     """drfft(x[, n, direction, normalize, overwrite_x]) -> x
 */
  __pyx_r = ((System::Object^)__pyx_v_x_);
  goto __pyx_L0;

  __pyx_r = nullptr;
  __pyx_L0:;
  return __pyx_r;
}

/* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":131
 *     fc.rfft(<fwr_real_x4_t*>np.PyArray_DATA(x_), n_, direction, howmany, normalize_)
 *     return x_
 * def drfft(object x, object n=None, fwi_integer_t direction=1, object normalize=None, bint overwrite_x=False):             # <<<<<<<<<<<<<<
 *     """drfft(x[, n, direction, normalize, overwrite_x]) -> x
 * 
 */

static System::Object^ drfft(System::Object^ x, [InteropServices::Optional]System::Object^ n, [InteropServices::Optional]System::Object^ direction, [InteropServices::Optional]System::Object^ normalize, [InteropServices::Optional]System::Object^ overwrite_x) {
  System::Object^ __pyx_v_x = nullptr;
  System::Object^ __pyx_v_n = nullptr;
  fwi_integer_t __pyx_v_direction;
  System::Object^ __pyx_v_normalize = nullptr;
  int __pyx_v_overwrite_x;
  NumpyDotNet::ndarray^ __pyx_v_x_;
  fwi_integer_t __pyx_v_n_;
  fwi_integer_t __pyx_v_normalize_;
  fwi_integer_t __pyx_v_howmany;
  System::Object^ __pyx_r = nullptr;
  System::Object^ __pyx_t_1 = nullptr;
  int __pyx_t_2;
  System::Object^ __pyx_t_3 = nullptr;
  fwi_integer_t __pyx_t_4;
  long __pyx_t_5;
  System::Object^ __pyx_t_6 = nullptr;
  fwi_integer_t __pyx_t_7;
  int __pyx_t_8;
  int __pyx_t_9;
  __pyx_v_x = x;
  if (dynamic_cast<System::Reflection::Missing^>(n) == nullptr) {
    __pyx_v_n = n;
  } else {
    __pyx_v_n = ((System::Object^)nullptr);
  }
  if (dynamic_cast<System::Reflection::Missing^>(direction) == nullptr) {
    __pyx_v_direction = __site_cvt_131_0->Target(__site_cvt_131_0, direction);
  } else {
    __pyx_v_direction = ((fwi_integer_t)1);
  }
  if (dynamic_cast<System::Reflection::Missing^>(normalize) == nullptr) {
    __pyx_v_normalize = normalize;
  } else {
    __pyx_v_normalize = ((System::Object^)nullptr);
  }
  if (dynamic_cast<System::Reflection::Missing^>(overwrite_x) == nullptr) {
    __pyx_v_overwrite_x = __site_cvt_131_0_1->Target(__site_cvt_131_0_1, overwrite_x);
  } else {
    __pyx_v_overwrite_x = ((int)0);
  }
  __pyx_v_x_ = nullptr;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":151
 *     cdef fwi_integer_t normalize_
 *     cdef fwi_integer_t howmany
 *     normalize_ = normalize if (normalize is not None) else direction < 0             # <<<<<<<<<<<<<<
 *     # First, convert x to an array with arbitrary number of dimensions
 *     x_ = np.PyArray_FROMANY(x, fwr_real_x8_t_enum, 0, 0,
 */
  __pyx_t_2 = (__pyx_v_normalize != nullptr);
  if (__pyx_t_2) {
    __pyx_t_1 = __pyx_v_normalize;
  } else {
    __pyx_t_3 = (__pyx_v_direction < 0);
    __pyx_t_1 = __pyx_t_3;
    __pyx_t_3 = nullptr;
  }
  __pyx_t_4 = __site_cvt_fwi_integer_t_151_17->Target(__site_cvt_fwi_integer_t_151_17, __pyx_t_1);
  __pyx_t_1 = nullptr;
  __pyx_v_normalize_ = __pyx_t_4;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":153
 *     normalize_ = normalize if (normalize is not None) else direction < 0
 *     # First, convert x to an array with arbitrary number of dimensions
 *     x_ = np.PyArray_FROMANY(x, fwr_real_x8_t_enum, 0, 0,             # <<<<<<<<<<<<<<
 *                             np.NPY_C_CONTIGUOUS | np.NPY_FORCECAST |
 *                             (0 if overwrite_x else np.NPY_ENSURECOPY))
 */
  __pyx_t_1 = (System::Object^)(long long)(NPY_FLOAT64);

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":155
 *     x_ = np.PyArray_FROMANY(x, fwr_real_x8_t_enum, 0, 0,
 *                             np.NPY_C_CONTIGUOUS | np.NPY_FORCECAST |
 *                             (0 if overwrite_x else np.NPY_ENSURECOPY))             # <<<<<<<<<<<<<<
 *     n_ = n if (n is not None) else np.PyArray_SIZE(x_)
 *     howmany = np.PyArray_SIZE(x_) // n_
 */
  if (__pyx_v_overwrite_x) {
    __pyx_t_5 = 0;
  } else {
    __pyx_t_5 = NPY_ENSURECOPY;
  }
  __pyx_t_3 = ((NPY_C_CONTIGUOUS | NPY_FORCECAST) | __pyx_t_5);
  __pyx_t_6 = PyArray_FROMANY(__pyx_v_x, __pyx_t_1, __pyx_int_0, __pyx_int_0, __pyx_t_3); 
  __pyx_t_1 = nullptr;
  __pyx_t_3 = nullptr;
  if (__pyx_t_6 == nullptr || dynamic_cast<NumpyDotNet::ndarray^>(__pyx_t_6) == nullptr) {
    throw PythonOps::MakeException(__pyx_context, PythonOps::GetGlobal(__pyx_context, "TypeError"), "type error", nullptr);
  }
  __pyx_v_x_ = ((NumpyDotNet::ndarray^)__pyx_t_6);
  __pyx_t_6 = nullptr;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":156
 *                             np.NPY_C_CONTIGUOUS | np.NPY_FORCECAST |
 *                             (0 if overwrite_x else np.NPY_ENSURECOPY))
 *     n_ = n if (n is not None) else np.PyArray_SIZE(x_)             # <<<<<<<<<<<<<<
 *     howmany = np.PyArray_SIZE(x_) // n_
 *     if not ((n_ > 0) and (n_ <= np.PyArray_SIZE(x_))):
 */
  __pyx_t_2 = (__pyx_v_n != nullptr);
  if (__pyx_t_2) {
    __pyx_t_6 = __pyx_v_n;
  } else {
    __pyx_t_3 = PyArray_SIZE(__pyx_v_x_);
    __pyx_t_6 = __pyx_t_3;
    __pyx_t_3 = nullptr;
  }
  __pyx_t_7 = __site_cvt_fwi_integer_t_156_9->Target(__site_cvt_fwi_integer_t_156_9, __pyx_t_6);
  __pyx_t_6 = nullptr;
  __pyx_v_n_ = __pyx_t_7;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":157
 *                             (0 if overwrite_x else np.NPY_ENSURECOPY))
 *     n_ = n if (n is not None) else np.PyArray_SIZE(x_)
 *     howmany = np.PyArray_SIZE(x_) // n_             # <<<<<<<<<<<<<<
 *     if not ((n_ > 0) and (n_ <= np.PyArray_SIZE(x_))):
 *         raise ValueError('Condition on arguments not satisfied: (n > 0) and (n <= x.size)')
 */
  __pyx_v_howmany = (PyArray_SIZE(__pyx_v_x_) / __pyx_v_n_);

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":158
 *     n_ = n if (n is not None) else np.PyArray_SIZE(x_)
 *     howmany = np.PyArray_SIZE(x_) // n_
 *     if not ((n_ > 0) and (n_ <= np.PyArray_SIZE(x_))):             # <<<<<<<<<<<<<<
 *         raise ValueError('Condition on arguments not satisfied: (n > 0) and (n <= x.size)')
 *     if not ((n_ * howmany) == np.PyArray_SIZE(x_)):
 */
  __pyx_t_2 = (__pyx_v_n_ > 0);
  if (__pyx_t_2) {
    __pyx_t_8 = (__pyx_v_n_ <= PyArray_SIZE(__pyx_v_x_));
    __pyx_t_9 = __pyx_t_8;
  } else {
    __pyx_t_9 = __pyx_t_2;
  }
  __pyx_t_2 = (!__pyx_t_9);
  if (__pyx_t_2) {

    /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":159
 *     howmany = np.PyArray_SIZE(x_) // n_
 *     if not ((n_ > 0) and (n_ <= np.PyArray_SIZE(x_))):
 *         raise ValueError('Condition on arguments not satisfied: (n > 0) and (n <= x.size)')             # <<<<<<<<<<<<<<
 *     if not ((n_ * howmany) == np.PyArray_SIZE(x_)):
 *         raise ValueError('Condition on arguments not satisfied: (n * howmany) == x.size')
 */
    __pyx_t_6 = PythonOps::GetGlobal(__pyx_context, "ValueError");
    __pyx_t_3 = __site_call1_159_24->Target(__site_call1_159_24, __pyx_context, __pyx_t_6, ((System::Object^)"Condition on arguments not satisfied: (n > 0) and (n <= x.size)"));
    __pyx_t_6 = nullptr;
    throw PythonOps::MakeException(__pyx_context, __pyx_t_3, nullptr, nullptr);
    __pyx_t_3 = nullptr;
    goto __pyx_L5;
  }
  __pyx_L5:;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":160
 *     if not ((n_ > 0) and (n_ <= np.PyArray_SIZE(x_))):
 *         raise ValueError('Condition on arguments not satisfied: (n > 0) and (n <= x.size)')
 *     if not ((n_ * howmany) == np.PyArray_SIZE(x_)):             # <<<<<<<<<<<<<<
 *         raise ValueError('Condition on arguments not satisfied: (n * howmany) == x.size')
 *     fc.drfft(<fwr_real_x8_t*>np.PyArray_DATA(x_), n_, direction, howmany, normalize_)
 */
  __pyx_t_2 = (!((__pyx_v_n_ * __pyx_v_howmany) == PyArray_SIZE(__pyx_v_x_)));
  if (__pyx_t_2) {

    /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":161
 *         raise ValueError('Condition on arguments not satisfied: (n > 0) and (n <= x.size)')
 *     if not ((n_ * howmany) == np.PyArray_SIZE(x_)):
 *         raise ValueError('Condition on arguments not satisfied: (n * howmany) == x.size')             # <<<<<<<<<<<<<<
 *     fc.drfft(<fwr_real_x8_t*>np.PyArray_DATA(x_), n_, direction, howmany, normalize_)
 *     return x_
 */
    __pyx_t_3 = PythonOps::GetGlobal(__pyx_context, "ValueError");
    __pyx_t_6 = __site_call1_161_24->Target(__site_call1_161_24, __pyx_context, __pyx_t_3, ((System::Object^)"Condition on arguments not satisfied: (n * howmany) == x.size"));
    __pyx_t_3 = nullptr;
    throw PythonOps::MakeException(__pyx_context, __pyx_t_6, nullptr, nullptr);
    __pyx_t_6 = nullptr;
    goto __pyx_L6;
  }
  __pyx_L6:;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":162
 *     if not ((n_ * howmany) == np.PyArray_SIZE(x_)):
 *         raise ValueError('Condition on arguments not satisfied: (n * howmany) == x.size')
 *     fc.drfft(<fwr_real_x8_t*>np.PyArray_DATA(x_), n_, direction, howmany, normalize_)             # <<<<<<<<<<<<<<
 *     return x_
 * def crfft(object x, object n=None, fwi_integer_t direction=1, object normalize=None, bint overwrite_x=False):
 */
  GLOBALFUNC(drfft)(((fwr_real_x8_t *)PyArray_DATA(__pyx_v_x_)), __pyx_v_n_, __pyx_v_direction, __pyx_v_howmany, __pyx_v_normalize_);

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":163
 *         raise ValueError('Condition on arguments not satisfied: (n * howmany) == x.size')
 *     fc.drfft(<fwr_real_x8_t*>np.PyArray_DATA(x_), n_, direction, howmany, normalize_)
 *     return x_             # <<<<<<<<<<<<<<
 * def crfft(object x, object n=None, fwi_integer_t direction=1, object normalize=None, bint overwrite_x=False):
 *     """crfft(x[, n, direction, normalize, overwrite_x]) -> x
 */
  __pyx_r = ((System::Object^)__pyx_v_x_);
  goto __pyx_L0;

  __pyx_r = nullptr;
  __pyx_L0:;
  return __pyx_r;
}

/* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":164
 *     fc.drfft(<fwr_real_x8_t*>np.PyArray_DATA(x_), n_, direction, howmany, normalize_)
 *     return x_
 * def crfft(object x, object n=None, fwi_integer_t direction=1, object normalize=None, bint overwrite_x=False):             # <<<<<<<<<<<<<<
 *     """crfft(x[, n, direction, normalize, overwrite_x]) -> x
 * 
 */

static System::Object^ crfft(System::Object^ x, [InteropServices::Optional]System::Object^ n, [InteropServices::Optional]System::Object^ direction, [InteropServices::Optional]System::Object^ normalize, [InteropServices::Optional]System::Object^ overwrite_x) {
  System::Object^ __pyx_v_x = nullptr;
  System::Object^ __pyx_v_n = nullptr;
  fwi_integer_t __pyx_v_direction;
  System::Object^ __pyx_v_normalize = nullptr;
  int __pyx_v_overwrite_x;
  NumpyDotNet::ndarray^ __pyx_v_x_;
  fwi_integer_t __pyx_v_n_;
  fwi_integer_t __pyx_v_normalize_;
  fwi_integer_t __pyx_v_howmany;
  System::Object^ __pyx_r = nullptr;
  System::Object^ __pyx_t_1 = nullptr;
  int __pyx_t_2;
  System::Object^ __pyx_t_3 = nullptr;
  fwi_integer_t __pyx_t_4;
  long __pyx_t_5;
  System::Object^ __pyx_t_6 = nullptr;
  fwi_integer_t __pyx_t_7;
  int __pyx_t_8;
  int __pyx_t_9;
  __pyx_v_x = x;
  if (dynamic_cast<System::Reflection::Missing^>(n) == nullptr) {
    __pyx_v_n = n;
  } else {
    __pyx_v_n = ((System::Object^)nullptr);
  }
  if (dynamic_cast<System::Reflection::Missing^>(direction) == nullptr) {
    __pyx_v_direction = __site_cvt_164_0->Target(__site_cvt_164_0, direction);
  } else {
    __pyx_v_direction = ((fwi_integer_t)1);
  }
  if (dynamic_cast<System::Reflection::Missing^>(normalize) == nullptr) {
    __pyx_v_normalize = normalize;
  } else {
    __pyx_v_normalize = ((System::Object^)nullptr);
  }
  if (dynamic_cast<System::Reflection::Missing^>(overwrite_x) == nullptr) {
    __pyx_v_overwrite_x = __site_cvt_164_0_1->Target(__site_cvt_164_0_1, overwrite_x);
  } else {
    __pyx_v_overwrite_x = ((int)0);
  }
  __pyx_v_x_ = nullptr;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":184
 *     cdef fwi_integer_t normalize_
 *     cdef fwi_integer_t howmany
 *     normalize_ = normalize if (normalize is not None) else direction < 0             # <<<<<<<<<<<<<<
 *     # First, convert x to an array with arbitrary number of dimensions
 *     x_ = np.PyArray_FROMANY(x, fwc_complex_x8_t_enum, 0, 0,
 */
  __pyx_t_2 = (__pyx_v_normalize != nullptr);
  if (__pyx_t_2) {
    __pyx_t_1 = __pyx_v_normalize;
  } else {
    __pyx_t_3 = (__pyx_v_direction < 0);
    __pyx_t_1 = __pyx_t_3;
    __pyx_t_3 = nullptr;
  }
  __pyx_t_4 = __site_cvt_fwi_integer_t_184_17->Target(__site_cvt_fwi_integer_t_184_17, __pyx_t_1);
  __pyx_t_1 = nullptr;
  __pyx_v_normalize_ = __pyx_t_4;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":186
 *     normalize_ = normalize if (normalize is not None) else direction < 0
 *     # First, convert x to an array with arbitrary number of dimensions
 *     x_ = np.PyArray_FROMANY(x, fwc_complex_x8_t_enum, 0, 0,             # <<<<<<<<<<<<<<
 *                             np.NPY_C_CONTIGUOUS | np.NPY_FORCECAST |
 *                             (0 if overwrite_x else np.NPY_ENSURECOPY))
 */
  __pyx_t_1 = (System::Object^)(long long)(NPY_CFLOAT);

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":188
 *     x_ = np.PyArray_FROMANY(x, fwc_complex_x8_t_enum, 0, 0,
 *                             np.NPY_C_CONTIGUOUS | np.NPY_FORCECAST |
 *                             (0 if overwrite_x else np.NPY_ENSURECOPY))             # <<<<<<<<<<<<<<
 *     n_ = n if (n is not None) else np.PyArray_SIZE(x_)
 *     howmany = np.PyArray_SIZE(x_) // n_
 */
  if (__pyx_v_overwrite_x) {
    __pyx_t_5 = 0;
  } else {
    __pyx_t_5 = NPY_ENSURECOPY;
  }
  __pyx_t_3 = ((NPY_C_CONTIGUOUS | NPY_FORCECAST) | __pyx_t_5);
  __pyx_t_6 = PyArray_FROMANY(__pyx_v_x, __pyx_t_1, __pyx_int_0, __pyx_int_0, __pyx_t_3); 
  __pyx_t_1 = nullptr;
  __pyx_t_3 = nullptr;
  if (__pyx_t_6 == nullptr || dynamic_cast<NumpyDotNet::ndarray^>(__pyx_t_6) == nullptr) {
    throw PythonOps::MakeException(__pyx_context, PythonOps::GetGlobal(__pyx_context, "TypeError"), "type error", nullptr);
  }
  __pyx_v_x_ = ((NumpyDotNet::ndarray^)__pyx_t_6);
  __pyx_t_6 = nullptr;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":189
 *                             np.NPY_C_CONTIGUOUS | np.NPY_FORCECAST |
 *                             (0 if overwrite_x else np.NPY_ENSURECOPY))
 *     n_ = n if (n is not None) else np.PyArray_SIZE(x_)             # <<<<<<<<<<<<<<
 *     howmany = np.PyArray_SIZE(x_) // n_
 *     if not ((n_ > 0) and (n_ <= np.PyArray_SIZE(x_))):
 */
  __pyx_t_2 = (__pyx_v_n != nullptr);
  if (__pyx_t_2) {
    __pyx_t_6 = __pyx_v_n;
  } else {
    __pyx_t_3 = PyArray_SIZE(__pyx_v_x_);
    __pyx_t_6 = __pyx_t_3;
    __pyx_t_3 = nullptr;
  }
  __pyx_t_7 = __site_cvt_fwi_integer_t_189_9->Target(__site_cvt_fwi_integer_t_189_9, __pyx_t_6);
  __pyx_t_6 = nullptr;
  __pyx_v_n_ = __pyx_t_7;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":190
 *                             (0 if overwrite_x else np.NPY_ENSURECOPY))
 *     n_ = n if (n is not None) else np.PyArray_SIZE(x_)
 *     howmany = np.PyArray_SIZE(x_) // n_             # <<<<<<<<<<<<<<
 *     if not ((n_ > 0) and (n_ <= np.PyArray_SIZE(x_))):
 *         raise ValueError('Condition on arguments not satisfied: (n > 0) and (n <= x.size)')
 */
  __pyx_v_howmany = (PyArray_SIZE(__pyx_v_x_) / __pyx_v_n_);

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":191
 *     n_ = n if (n is not None) else np.PyArray_SIZE(x_)
 *     howmany = np.PyArray_SIZE(x_) // n_
 *     if not ((n_ > 0) and (n_ <= np.PyArray_SIZE(x_))):             # <<<<<<<<<<<<<<
 *         raise ValueError('Condition on arguments not satisfied: (n > 0) and (n <= x.size)')
 *     if not ((n_ * howmany) == np.PyArray_SIZE(x_)):
 */
  __pyx_t_2 = (__pyx_v_n_ > 0);
  if (__pyx_t_2) {
    __pyx_t_8 = (__pyx_v_n_ <= PyArray_SIZE(__pyx_v_x_));
    __pyx_t_9 = __pyx_t_8;
  } else {
    __pyx_t_9 = __pyx_t_2;
  }
  __pyx_t_2 = (!__pyx_t_9);
  if (__pyx_t_2) {

    /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":192
 *     howmany = np.PyArray_SIZE(x_) // n_
 *     if not ((n_ > 0) and (n_ <= np.PyArray_SIZE(x_))):
 *         raise ValueError('Condition on arguments not satisfied: (n > 0) and (n <= x.size)')             # <<<<<<<<<<<<<<
 *     if not ((n_ * howmany) == np.PyArray_SIZE(x_)):
 *         raise ValueError('Condition on arguments not satisfied: (n * howmany) == x.size')
 */
    __pyx_t_6 = PythonOps::GetGlobal(__pyx_context, "ValueError");
    __pyx_t_3 = __site_call1_192_24->Target(__site_call1_192_24, __pyx_context, __pyx_t_6, ((System::Object^)"Condition on arguments not satisfied: (n > 0) and (n <= x.size)"));
    __pyx_t_6 = nullptr;
    throw PythonOps::MakeException(__pyx_context, __pyx_t_3, nullptr, nullptr);
    __pyx_t_3 = nullptr;
    goto __pyx_L5;
  }
  __pyx_L5:;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":193
 *     if not ((n_ > 0) and (n_ <= np.PyArray_SIZE(x_))):
 *         raise ValueError('Condition on arguments not satisfied: (n > 0) and (n <= x.size)')
 *     if not ((n_ * howmany) == np.PyArray_SIZE(x_)):             # <<<<<<<<<<<<<<
 *         raise ValueError('Condition on arguments not satisfied: (n * howmany) == x.size')
 *     fc.crfft(<fwc_complex_x8_t*>np.PyArray_DATA(x_), n_, direction, howmany, normalize_)
 */
  __pyx_t_2 = (!((__pyx_v_n_ * __pyx_v_howmany) == PyArray_SIZE(__pyx_v_x_)));
  if (__pyx_t_2) {

    /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":194
 *         raise ValueError('Condition on arguments not satisfied: (n > 0) and (n <= x.size)')
 *     if not ((n_ * howmany) == np.PyArray_SIZE(x_)):
 *         raise ValueError('Condition on arguments not satisfied: (n * howmany) == x.size')             # <<<<<<<<<<<<<<
 *     fc.crfft(<fwc_complex_x8_t*>np.PyArray_DATA(x_), n_, direction, howmany, normalize_)
 *     return x_
 */
    __pyx_t_3 = PythonOps::GetGlobal(__pyx_context, "ValueError");
    __pyx_t_6 = __site_call1_194_24->Target(__site_call1_194_24, __pyx_context, __pyx_t_3, ((System::Object^)"Condition on arguments not satisfied: (n * howmany) == x.size"));
    __pyx_t_3 = nullptr;
    throw PythonOps::MakeException(__pyx_context, __pyx_t_6, nullptr, nullptr);
    __pyx_t_6 = nullptr;
    goto __pyx_L6;
  }
  __pyx_L6:;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":195
 *     if not ((n_ * howmany) == np.PyArray_SIZE(x_)):
 *         raise ValueError('Condition on arguments not satisfied: (n * howmany) == x.size')
 *     fc.crfft(<fwc_complex_x8_t*>np.PyArray_DATA(x_), n_, direction, howmany, normalize_)             # <<<<<<<<<<<<<<
 *     return x_
 * def zrfft(object x, object n=None, fwi_integer_t direction=1, object normalize=None, bint overwrite_x=False):
 */
  GLOBALFUNC(crfft)(((__pyx_t_float_complex *)PyArray_DATA(__pyx_v_x_)), __pyx_v_n_, __pyx_v_direction, __pyx_v_howmany, __pyx_v_normalize_);

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":196
 *         raise ValueError('Condition on arguments not satisfied: (n * howmany) == x.size')
 *     fc.crfft(<fwc_complex_x8_t*>np.PyArray_DATA(x_), n_, direction, howmany, normalize_)
 *     return x_             # <<<<<<<<<<<<<<
 * def zrfft(object x, object n=None, fwi_integer_t direction=1, object normalize=None, bint overwrite_x=False):
 *     """zrfft(x[, n, direction, normalize, overwrite_x]) -> x
 */
  __pyx_r = ((System::Object^)__pyx_v_x_);
  goto __pyx_L0;

  __pyx_r = nullptr;
  __pyx_L0:;
  return __pyx_r;
}

/* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":197
 *     fc.crfft(<fwc_complex_x8_t*>np.PyArray_DATA(x_), n_, direction, howmany, normalize_)
 *     return x_
 * def zrfft(object x, object n=None, fwi_integer_t direction=1, object normalize=None, bint overwrite_x=False):             # <<<<<<<<<<<<<<
 *     """zrfft(x[, n, direction, normalize, overwrite_x]) -> x
 * 
 */

static System::Object^ zrfft(System::Object^ x, [InteropServices::Optional]System::Object^ n, [InteropServices::Optional]System::Object^ direction, [InteropServices::Optional]System::Object^ normalize, [InteropServices::Optional]System::Object^ overwrite_x) {
  System::Object^ __pyx_v_x = nullptr;
  System::Object^ __pyx_v_n = nullptr;
  fwi_integer_t __pyx_v_direction;
  System::Object^ __pyx_v_normalize = nullptr;
  int __pyx_v_overwrite_x;
  NumpyDotNet::ndarray^ __pyx_v_x_;
  fwi_integer_t __pyx_v_n_;
  fwi_integer_t __pyx_v_normalize_;
  fwi_integer_t __pyx_v_howmany;
  System::Object^ __pyx_r = nullptr;
  System::Object^ __pyx_t_1 = nullptr;
  int __pyx_t_2;
  System::Object^ __pyx_t_3 = nullptr;
  fwi_integer_t __pyx_t_4;
  long __pyx_t_5;
  System::Object^ __pyx_t_6 = nullptr;
  fwi_integer_t __pyx_t_7;
  int __pyx_t_8;
  int __pyx_t_9;
  __pyx_v_x = x;
  if (dynamic_cast<System::Reflection::Missing^>(n) == nullptr) {
    __pyx_v_n = n;
  } else {
    __pyx_v_n = ((System::Object^)nullptr);
  }
  if (dynamic_cast<System::Reflection::Missing^>(direction) == nullptr) {
    __pyx_v_direction = __site_cvt_197_0->Target(__site_cvt_197_0, direction);
  } else {
    __pyx_v_direction = ((fwi_integer_t)1);
  }
  if (dynamic_cast<System::Reflection::Missing^>(normalize) == nullptr) {
    __pyx_v_normalize = normalize;
  } else {
    __pyx_v_normalize = ((System::Object^)nullptr);
  }
  if (dynamic_cast<System::Reflection::Missing^>(overwrite_x) == nullptr) {
    __pyx_v_overwrite_x = __site_cvt_197_0_1->Target(__site_cvt_197_0_1, overwrite_x);
  } else {
    __pyx_v_overwrite_x = ((int)0);
  }
  __pyx_v_x_ = nullptr;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":217
 *     cdef fwi_integer_t normalize_
 *     cdef fwi_integer_t howmany
 *     normalize_ = normalize if (normalize is not None) else direction < 0             # <<<<<<<<<<<<<<
 *     # First, convert x to an array with arbitrary number of dimensions
 *     x_ = np.PyArray_FROMANY(x, fwc_complex_x16_t_enum, 0, 0,
 */
  __pyx_t_2 = (__pyx_v_normalize != nullptr);
  if (__pyx_t_2) {
    __pyx_t_1 = __pyx_v_normalize;
  } else {
    __pyx_t_3 = (__pyx_v_direction < 0);
    __pyx_t_1 = __pyx_t_3;
    __pyx_t_3 = nullptr;
  }
  __pyx_t_4 = __site_cvt_fwi_integer_t_217_17->Target(__site_cvt_fwi_integer_t_217_17, __pyx_t_1);
  __pyx_t_1 = nullptr;
  __pyx_v_normalize_ = __pyx_t_4;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":219
 *     normalize_ = normalize if (normalize is not None) else direction < 0
 *     # First, convert x to an array with arbitrary number of dimensions
 *     x_ = np.PyArray_FROMANY(x, fwc_complex_x16_t_enum, 0, 0,             # <<<<<<<<<<<<<<
 *                             np.NPY_C_CONTIGUOUS | np.NPY_FORCECAST |
 *                             (0 if overwrite_x else np.NPY_ENSURECOPY))
 */
  __pyx_t_1 = (System::Object^)(long long)(NPY_CDOUBLE);

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":221
 *     x_ = np.PyArray_FROMANY(x, fwc_complex_x16_t_enum, 0, 0,
 *                             np.NPY_C_CONTIGUOUS | np.NPY_FORCECAST |
 *                             (0 if overwrite_x else np.NPY_ENSURECOPY))             # <<<<<<<<<<<<<<
 *     n_ = n if (n is not None) else np.PyArray_SIZE(x_)
 *     howmany = np.PyArray_SIZE(x_) // n_
 */
  if (__pyx_v_overwrite_x) {
    __pyx_t_5 = 0;
  } else {
    __pyx_t_5 = NPY_ENSURECOPY;
  }
  __pyx_t_3 = ((NPY_C_CONTIGUOUS | NPY_FORCECAST) | __pyx_t_5);
  __pyx_t_6 = PyArray_FROMANY(__pyx_v_x, __pyx_t_1, __pyx_int_0, __pyx_int_0, __pyx_t_3); 
  __pyx_t_1 = nullptr;
  __pyx_t_3 = nullptr;
  if (__pyx_t_6 == nullptr || dynamic_cast<NumpyDotNet::ndarray^>(__pyx_t_6) == nullptr) {
    throw PythonOps::MakeException(__pyx_context, PythonOps::GetGlobal(__pyx_context, "TypeError"), "type error", nullptr);
  }
  __pyx_v_x_ = ((NumpyDotNet::ndarray^)__pyx_t_6);
  __pyx_t_6 = nullptr;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":222
 *                             np.NPY_C_CONTIGUOUS | np.NPY_FORCECAST |
 *                             (0 if overwrite_x else np.NPY_ENSURECOPY))
 *     n_ = n if (n is not None) else np.PyArray_SIZE(x_)             # <<<<<<<<<<<<<<
 *     howmany = np.PyArray_SIZE(x_) // n_
 *     if not ((n_ > 0) and (n_ <= np.PyArray_SIZE(x_))):
 */
  __pyx_t_2 = (__pyx_v_n != nullptr);
  if (__pyx_t_2) {
    __pyx_t_6 = __pyx_v_n;
  } else {
    __pyx_t_3 = PyArray_SIZE(__pyx_v_x_);
    __pyx_t_6 = __pyx_t_3;
    __pyx_t_3 = nullptr;
  }
  __pyx_t_7 = __site_cvt_fwi_integer_t_222_9->Target(__site_cvt_fwi_integer_t_222_9, __pyx_t_6);
  __pyx_t_6 = nullptr;
  __pyx_v_n_ = __pyx_t_7;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":223
 *                             (0 if overwrite_x else np.NPY_ENSURECOPY))
 *     n_ = n if (n is not None) else np.PyArray_SIZE(x_)
 *     howmany = np.PyArray_SIZE(x_) // n_             # <<<<<<<<<<<<<<
 *     if not ((n_ > 0) and (n_ <= np.PyArray_SIZE(x_))):
 *         raise ValueError('Condition on arguments not satisfied: (n > 0) and (n <= x.size)')
 */
  __pyx_v_howmany = (PyArray_SIZE(__pyx_v_x_) / __pyx_v_n_);

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":224
 *     n_ = n if (n is not None) else np.PyArray_SIZE(x_)
 *     howmany = np.PyArray_SIZE(x_) // n_
 *     if not ((n_ > 0) and (n_ <= np.PyArray_SIZE(x_))):             # <<<<<<<<<<<<<<
 *         raise ValueError('Condition on arguments not satisfied: (n > 0) and (n <= x.size)')
 *     if not ((n_ * howmany) == np.PyArray_SIZE(x_)):
 */
  __pyx_t_2 = (__pyx_v_n_ > 0);
  if (__pyx_t_2) {
    __pyx_t_8 = (__pyx_v_n_ <= PyArray_SIZE(__pyx_v_x_));
    __pyx_t_9 = __pyx_t_8;
  } else {
    __pyx_t_9 = __pyx_t_2;
  }
  __pyx_t_2 = (!__pyx_t_9);
  if (__pyx_t_2) {

    /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":225
 *     howmany = np.PyArray_SIZE(x_) // n_
 *     if not ((n_ > 0) and (n_ <= np.PyArray_SIZE(x_))):
 *         raise ValueError('Condition on arguments not satisfied: (n > 0) and (n <= x.size)')             # <<<<<<<<<<<<<<
 *     if not ((n_ * howmany) == np.PyArray_SIZE(x_)):
 *         raise ValueError('Condition on arguments not satisfied: (n * howmany) == x.size')
 */
    __pyx_t_6 = PythonOps::GetGlobal(__pyx_context, "ValueError");
    __pyx_t_3 = __site_call1_225_24->Target(__site_call1_225_24, __pyx_context, __pyx_t_6, ((System::Object^)"Condition on arguments not satisfied: (n > 0) and (n <= x.size)"));
    __pyx_t_6 = nullptr;
    throw PythonOps::MakeException(__pyx_context, __pyx_t_3, nullptr, nullptr);
    __pyx_t_3 = nullptr;
    goto __pyx_L5;
  }
  __pyx_L5:;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":226
 *     if not ((n_ > 0) and (n_ <= np.PyArray_SIZE(x_))):
 *         raise ValueError('Condition on arguments not satisfied: (n > 0) and (n <= x.size)')
 *     if not ((n_ * howmany) == np.PyArray_SIZE(x_)):             # <<<<<<<<<<<<<<
 *         raise ValueError('Condition on arguments not satisfied: (n * howmany) == x.size')
 *     fc.zrfft(<fwc_complex_x16_t*>np.PyArray_DATA(x_), n_, direction, howmany, normalize_)
 */
  __pyx_t_2 = (!((__pyx_v_n_ * __pyx_v_howmany) == PyArray_SIZE(__pyx_v_x_)));
  if (__pyx_t_2) {

    /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":227
 *         raise ValueError('Condition on arguments not satisfied: (n > 0) and (n <= x.size)')
 *     if not ((n_ * howmany) == np.PyArray_SIZE(x_)):
 *         raise ValueError('Condition on arguments not satisfied: (n * howmany) == x.size')             # <<<<<<<<<<<<<<
 *     fc.zrfft(<fwc_complex_x16_t*>np.PyArray_DATA(x_), n_, direction, howmany, normalize_)
 *     return x_
 */
    __pyx_t_3 = PythonOps::GetGlobal(__pyx_context, "ValueError");
    __pyx_t_6 = __site_call1_227_24->Target(__site_call1_227_24, __pyx_context, __pyx_t_3, ((System::Object^)"Condition on arguments not satisfied: (n * howmany) == x.size"));
    __pyx_t_3 = nullptr;
    throw PythonOps::MakeException(__pyx_context, __pyx_t_6, nullptr, nullptr);
    __pyx_t_6 = nullptr;
    goto __pyx_L6;
  }
  __pyx_L6:;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":228
 *     if not ((n_ * howmany) == np.PyArray_SIZE(x_)):
 *         raise ValueError('Condition on arguments not satisfied: (n * howmany) == x.size')
 *     fc.zrfft(<fwc_complex_x16_t*>np.PyArray_DATA(x_), n_, direction, howmany, normalize_)             # <<<<<<<<<<<<<<
 *     return x_
 * 
 */
  GLOBALFUNC(zrfft)(((__pyx_t_double_complex *)PyArray_DATA(__pyx_v_x_)), __pyx_v_n_, __pyx_v_direction, __pyx_v_howmany, __pyx_v_normalize_);

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":229
 *         raise ValueError('Condition on arguments not satisfied: (n * howmany) == x.size')
 *     fc.zrfft(<fwc_complex_x16_t*>np.PyArray_DATA(x_), n_, direction, howmany, normalize_)
 *     return x_             # <<<<<<<<<<<<<<
 * 
 * 
 */
  __pyx_r = ((System::Object^)__pyx_v_x_);
  goto __pyx_L0;

  __pyx_r = nullptr;
  __pyx_L0:;
  return __pyx_r;
}

/* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":233
 * 
 * # Template for cfftnd, zfftnd
 * def cfftnd(object x, object s=None, fwi_integer_t direction=1, object normalize=None, bint overwrite_x=False):             # <<<<<<<<<<<<<<
 *     """cfftnd(x[, s, direction, normalize, overwrite_x]) -> x
 * 
 */

static System::Object^ cfftnd(System::Object^ x, [InteropServices::Optional]System::Object^ s, [InteropServices::Optional]System::Object^ direction, [InteropServices::Optional]System::Object^ normalize, [InteropServices::Optional]System::Object^ overwrite_x) {
  System::Object^ __pyx_v_x = nullptr;
  System::Object^ __pyx_v_s = nullptr;
  fwi_integer_t __pyx_v_direction;
  System::Object^ __pyx_v_normalize = nullptr;
  int __pyx_v_overwrite_x;
  NumpyDotNet::ndarray^ __pyx_v_x_;
  NumpyDotNet::ndarray^ __pyx_v_s_;
  fwi_integer_t __pyx_v_normalize_;
  fwi_integer_t __pyx_v_r;
  fwi_integer_t __pyx_v_howmany;
  fwi_integer_t __pyx_v_j;
  Py_ssize_t __pyx_v_i;
  Py_ssize_t __pyx_v_sz;
  Py_ssize_t __pyx_v_xsz;
  NumpyDotNet::IExtBufferProtocol^ __pyx_bstruct_s_;
  Py_ssize_t __pyx_bstride_0_s_ = 0;
  Py_ssize_t __pyx_bshape_0_s_ = 0;
  System::Object^ __pyx_r = nullptr;
  System::Object^ __pyx_t_1 = nullptr;
  int __pyx_t_2;
  System::Object^ __pyx_t_3 = nullptr;
  fwi_integer_t __pyx_t_4;
  long __pyx_t_5;
  System::Object^ __pyx_t_6 = nullptr;
  NumpyDotNet::ndarray^ __pyx_t_7 = nullptr;
  fwi_integer_t __pyx_t_8;
  fwi_integer_t __pyx_t_9;
  Py_ssize_t __pyx_t_10;
  Py_ssize_t __pyx_t_11;
  int __pyx_t_12;
  __pyx_v_x = x;
  if (dynamic_cast<System::Reflection::Missing^>(s) == nullptr) {
    __pyx_v_s = s;
  } else {
    __pyx_v_s = ((System::Object^)nullptr);
  }
  if (dynamic_cast<System::Reflection::Missing^>(direction) == nullptr) {
    __pyx_v_direction = __site_cvt_233_0->Target(__site_cvt_233_0, direction);
  } else {
    __pyx_v_direction = ((fwi_integer_t)1);
  }
  if (dynamic_cast<System::Reflection::Missing^>(normalize) == nullptr) {
    __pyx_v_normalize = normalize;
  } else {
    __pyx_v_normalize = ((System::Object^)nullptr);
  }
  if (dynamic_cast<System::Reflection::Missing^>(overwrite_x) == nullptr) {
    __pyx_v_overwrite_x = __site_cvt_233_0_1->Target(__site_cvt_233_0_1, overwrite_x);
  } else {
    __pyx_v_overwrite_x = ((int)0);
  }
  __pyx_v_x_ = nullptr;
  __pyx_v_s_ = nullptr;
  __pyx_bstruct_s_ = nullptr;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":256
 *     cdef fwi_integer_t j
 *     cdef Py_ssize_t i, sz, xsz
 *     normalize_ = normalize if (normalize is not None) else direction < 0             # <<<<<<<<<<<<<<
 *     j = 0
 *     x_ = np.PyArray_FROMANY(x, fwc_complex_x8_t_enum, 0, 0,
 */
  __pyx_t_2 = (__pyx_v_normalize != nullptr);
  if (__pyx_t_2) {
    __pyx_t_1 = __pyx_v_normalize;
  } else {
    __pyx_t_3 = (__pyx_v_direction < 0);
    __pyx_t_1 = __pyx_t_3;
    __pyx_t_3 = nullptr;
  }
  __pyx_t_4 = __site_cvt_fwi_integer_t_256_17->Target(__site_cvt_fwi_integer_t_256_17, __pyx_t_1);
  __pyx_t_1 = nullptr;
  __pyx_v_normalize_ = __pyx_t_4;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":257
 *     cdef Py_ssize_t i, sz, xsz
 *     normalize_ = normalize if (normalize is not None) else direction < 0
 *     j = 0             # <<<<<<<<<<<<<<
 *     x_ = np.PyArray_FROMANY(x, fwc_complex_x8_t_enum, 0, 0,
 *                             np.NPY_C_CONTIGUOUS | np.NPY_FORCECAST |
 */
  __pyx_v_j = 0;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":258
 *     normalize_ = normalize if (normalize is not None) else direction < 0
 *     j = 0
 *     x_ = np.PyArray_FROMANY(x, fwc_complex_x8_t_enum, 0, 0,             # <<<<<<<<<<<<<<
 *                             np.NPY_C_CONTIGUOUS | np.NPY_FORCECAST |
 *                             (0 if overwrite_x else np.NPY_ENSURECOPY))
 */
  __pyx_t_1 = (System::Object^)(long long)(NPY_CFLOAT);

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":260
 *     x_ = np.PyArray_FROMANY(x, fwc_complex_x8_t_enum, 0, 0,
 *                             np.NPY_C_CONTIGUOUS | np.NPY_FORCECAST |
 *                             (0 if overwrite_x else np.NPY_ENSURECOPY))             # <<<<<<<<<<<<<<
 *     # Next, let the default of s be the tuple x_.shape,
 *     # and get the array of s
 */
  if (__pyx_v_overwrite_x) {
    __pyx_t_5 = 0;
  } else {
    __pyx_t_5 = NPY_ENSURECOPY;
  }
  __pyx_t_3 = ((NPY_C_CONTIGUOUS | NPY_FORCECAST) | __pyx_t_5);
  __pyx_t_6 = PyArray_FROMANY(__pyx_v_x, __pyx_t_1, __pyx_int_0, __pyx_int_0, __pyx_t_3); 
  __pyx_t_1 = nullptr;
  __pyx_t_3 = nullptr;
  if (__pyx_t_6 == nullptr || dynamic_cast<NumpyDotNet::ndarray^>(__pyx_t_6) == nullptr) {
    throw PythonOps::MakeException(__pyx_context, PythonOps::GetGlobal(__pyx_context, "TypeError"), "type error", nullptr);
  }
  __pyx_v_x_ = ((NumpyDotNet::ndarray^)__pyx_t_6);
  __pyx_t_6 = nullptr;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":263
 *     # Next, let the default of s be the tuple x_.shape,
 *     # and get the array of s
 *     if s is None:             # <<<<<<<<<<<<<<
 *         s = (<object>x_).shape
 *     s_ = np.PyArray_FROMANY(s, fwi_integer_t_enum, 1, 1,
 */
  __pyx_t_2 = (__pyx_v_s == nullptr);
  if (__pyx_t_2) {

    /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":264
 *     # and get the array of s
 *     if s is None:
 *         s = (<object>x_).shape             # <<<<<<<<<<<<<<
 *     s_ = np.PyArray_FROMANY(s, fwi_integer_t_enum, 1, 1,
 *                             np.NPY_C_CONTIGUOUS | np.NPY_FORCECAST)
 */
    __pyx_t_6 = __site_get_shape_264_24->Target(__site_get_shape_264_24, ((System::Object^)__pyx_v_x_), __pyx_context);
    __pyx_v_s = __pyx_t_6;
    __pyx_t_6 = nullptr;
    goto __pyx_L5;
  }
  __pyx_L5:;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":265
 *     if s is None:
 *         s = (<object>x_).shape
 *     s_ = np.PyArray_FROMANY(s, fwi_integer_t_enum, 1, 1,             # <<<<<<<<<<<<<<
 *                             np.NPY_C_CONTIGUOUS | np.NPY_FORCECAST)
 *     r = np.PyArray_NDIM(x_)
 */
  __pyx_t_6 = (System::Object^)(long long)(NPY_INT);

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":266
 *         s = (<object>x_).shape
 *     s_ = np.PyArray_FROMANY(s, fwi_integer_t_enum, 1, 1,
 *                             np.NPY_C_CONTIGUOUS | np.NPY_FORCECAST)             # <<<<<<<<<<<<<<
 *     r = np.PyArray_NDIM(x_)
 *     if not (r == np.PyArray_DIMS(s_)[0]):
 */
  __pyx_t_3 = (System::Object^)(long long)((NPY_C_CONTIGUOUS | NPY_FORCECAST));
  __pyx_t_1 = PyArray_FROMANY(__pyx_v_s, __pyx_t_6, __pyx_int_1, __pyx_int_1, __pyx_t_3); 
  __pyx_t_6 = nullptr;
  __pyx_t_3 = nullptr;
  if (__pyx_t_1 == nullptr || dynamic_cast<NumpyDotNet::ndarray^>(__pyx_t_1) == nullptr) {
    throw PythonOps::MakeException(__pyx_context, PythonOps::GetGlobal(__pyx_context, "TypeError"), "type error", nullptr);
  }
  __pyx_t_7 = ((NumpyDotNet::ndarray^)__pyx_t_1);
  {
    __Pyx_BufFmt_StackElem __pyx_stack[1];
    __Pyx_SafeReleaseBuffer(__pyx_bstruct_s_);
    __Pyx_GetBufferAndValidate(__pyx_bstruct_s_, __pyx_t_7, &__Pyx_TypeInfo_int, PyBUF_FORMAT| PyBUF_C_CONTIGUOUS, 1, 0, __pyx_stack);
    __pyx_bstride_0_s_ = __pyx_bstruct_s_->Strides[0];
    __pyx_bshape_0_s_ = __pyx_bstruct_s_->Shape[0];
  }
  __pyx_t_7 = nullptr;
  __pyx_v_s_ = ((NumpyDotNet::ndarray^)__pyx_t_1);
  __pyx_t_1 = nullptr;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":267
 *     s_ = np.PyArray_FROMANY(s, fwi_integer_t_enum, 1, 1,
 *                             np.NPY_C_CONTIGUOUS | np.NPY_FORCECAST)
 *     r = np.PyArray_NDIM(x_)             # <<<<<<<<<<<<<<
 *     if not (r == np.PyArray_DIMS(s_)[0]):
 *         raise ValueError('Condition on arguments not satisfied: x.ndim == s.shape[0]')
 */
  __pyx_t_1 = PyArray_NDIM(((System::Object^)__pyx_v_x_)); 
  __pyx_t_8 = __site_cvt_fwi_integer_t_267_23->Target(__site_cvt_fwi_integer_t_267_23, __pyx_t_1);
  __pyx_t_1 = nullptr;
  __pyx_v_r = __pyx_t_8;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":268
 *                             np.NPY_C_CONTIGUOUS | np.NPY_FORCECAST)
 *     r = np.PyArray_NDIM(x_)
 *     if not (r == np.PyArray_DIMS(s_)[0]):             # <<<<<<<<<<<<<<
 *         raise ValueError('Condition on arguments not satisfied: x.ndim == s.shape[0]')
 *     xsz = np.PyArray_SIZE(x_)
 */
  __pyx_t_2 = (!(__pyx_v_r == (PyArray_DIMS(((NumpyDotNet::ndarray^)__pyx_v_s_))[0])));
  if (__pyx_t_2) {

    /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":269
 *     r = np.PyArray_NDIM(x_)
 *     if not (r == np.PyArray_DIMS(s_)[0]):
 *         raise ValueError('Condition on arguments not satisfied: x.ndim == s.shape[0]')             # <<<<<<<<<<<<<<
 *     xsz = np.PyArray_SIZE(x_)
 *     sz = 1
 */
    __pyx_t_1 = PythonOps::GetGlobal(__pyx_context, "ValueError");
    __pyx_t_3 = __site_call1_269_24->Target(__site_call1_269_24, __pyx_context, __pyx_t_1, ((System::Object^)"Condition on arguments not satisfied: x.ndim == s.shape[0]"));
    __pyx_t_1 = nullptr;
    throw PythonOps::MakeException(__pyx_context, __pyx_t_3, nullptr, nullptr);
    __pyx_t_3 = nullptr;
    goto __pyx_L6;
  }
  __pyx_L6:;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":270
 *     if not (r == np.PyArray_DIMS(s_)[0]):
 *         raise ValueError('Condition on arguments not satisfied: x.ndim == s.shape[0]')
 *     xsz = np.PyArray_SIZE(x_)             # <<<<<<<<<<<<<<
 *     sz = 1
 *     for i in range(r):
 */
  __pyx_v_xsz = PyArray_SIZE(__pyx_v_x_);

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":271
 *         raise ValueError('Condition on arguments not satisfied: x.ndim == s.shape[0]')
 *     xsz = np.PyArray_SIZE(x_)
 *     sz = 1             # <<<<<<<<<<<<<<
 *     for i in range(r):
 *         sz *= s_[i]
 */
  __pyx_v_sz = 1;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":272
 *     xsz = np.PyArray_SIZE(x_)
 *     sz = 1
 *     for i in range(r):             # <<<<<<<<<<<<<<
 *         sz *= s_[i]
 *     howmany = xsz // sz
 */
  __pyx_t_9 = __pyx_v_r;
  for (__pyx_t_10 = 0; __pyx_t_10 < __pyx_t_9; __pyx_t_10+=1) {
    __pyx_v_i = __pyx_t_10;

    /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":273
 *     sz = 1
 *     for i in range(r):
 *         sz *= s_[i]             # <<<<<<<<<<<<<<
 *     howmany = xsz // sz
 *     if sz * howmany != xsz:
 */
    __pyx_t_11 = __pyx_v_i;
    __pyx_t_12 = -1;
    if (__pyx_t_11 < 0) {
      __pyx_t_11 += __pyx_bshape_0_s_;
      if (unlikely(__pyx_t_11 < 0)) __pyx_t_12 = 0;
    } else if (unlikely(__pyx_t_11 >= __pyx_bshape_0_s_)) __pyx_t_12 = 0;
    if (unlikely(__pyx_t_12 != -1)) {
      __Pyx_RaiseBufferIndexError(__pyx_t_12);
    }
    __pyx_v_sz *= (*__Pyx_BufPtrCContig1d(int *, (int *)(long long)__pyx_bstruct_s_->UnsafeAddress, __pyx_t_11, __pyx_bstride_0_s_));
  }

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":274
 *     for i in range(r):
 *         sz *= s_[i]
 *     howmany = xsz // sz             # <<<<<<<<<<<<<<
 *     if sz * howmany != xsz:
 *         raise ValueError("inconsistency in x.shape and s argument")
 */
  __pyx_v_howmany = (__pyx_v_xsz / __pyx_v_sz);

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":275
 *         sz *= s_[i]
 *     howmany = xsz // sz
 *     if sz * howmany != xsz:             # <<<<<<<<<<<<<<
 *         raise ValueError("inconsistency in x.shape and s argument")
 *     fc.cfftnd(<fwc_complex_x8_t*>np.PyArray_DATA(x_), r, <fwi_integer_t*>np.PyArray_DATA(s_), direction, howmany, normalize_)
 */
  __pyx_t_2 = ((__pyx_v_sz * __pyx_v_howmany) != __pyx_v_xsz);
  if (__pyx_t_2) {

    /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":276
 *     howmany = xsz // sz
 *     if sz * howmany != xsz:
 *         raise ValueError("inconsistency in x.shape and s argument")             # <<<<<<<<<<<<<<
 *     fc.cfftnd(<fwc_complex_x8_t*>np.PyArray_DATA(x_), r, <fwi_integer_t*>np.PyArray_DATA(s_), direction, howmany, normalize_)
 *     # Return the non-flattened view of the buffer
 */
    __pyx_t_3 = PythonOps::GetGlobal(__pyx_context, "ValueError");
    __pyx_t_1 = __site_call1_276_24->Target(__site_call1_276_24, __pyx_context, __pyx_t_3, ((System::Object^)"inconsistency in x.shape and s argument"));
    __pyx_t_3 = nullptr;
    throw PythonOps::MakeException(__pyx_context, __pyx_t_1, nullptr, nullptr);
    __pyx_t_1 = nullptr;
    goto __pyx_L9;
  }
  __pyx_L9:;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":277
 *     if sz * howmany != xsz:
 *         raise ValueError("inconsistency in x.shape and s argument")
 *     fc.cfftnd(<fwc_complex_x8_t*>np.PyArray_DATA(x_), r, <fwi_integer_t*>np.PyArray_DATA(s_), direction, howmany, normalize_)             # <<<<<<<<<<<<<<
 *     # Return the non-flattened view of the buffer
 *     return x_
 */
  GLOBALFUNC(cfftnd)(((__pyx_t_float_complex *)PyArray_DATA(__pyx_v_x_)), __pyx_v_r, ((fwi_integer_t *)PyArray_DATA(((NumpyDotNet::ndarray^)__pyx_v_s_))), __pyx_v_direction, __pyx_v_howmany, __pyx_v_normalize_);

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":279
 *     fc.cfftnd(<fwc_complex_x8_t*>np.PyArray_DATA(x_), r, <fwi_integer_t*>np.PyArray_DATA(s_), direction, howmany, normalize_)
 *     # Return the non-flattened view of the buffer
 *     return x_             # <<<<<<<<<<<<<<
 * def zfftnd(object x, object s=None, fwi_integer_t direction=1, object normalize=None, bint overwrite_x=False):
 *     """zfftnd(x[, s, direction, normalize, overwrite_x]) -> x
 */
  __pyx_r = ((System::Object^)__pyx_v_x_);
  goto __pyx_L0;

  __pyx_r = nullptr;
  __pyx_L0:;
  __Pyx_SafeReleaseBuffer(__pyx_bstruct_s_);
  return __pyx_r;
}

/* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":280
 *     # Return the non-flattened view of the buffer
 *     return x_
 * def zfftnd(object x, object s=None, fwi_integer_t direction=1, object normalize=None, bint overwrite_x=False):             # <<<<<<<<<<<<<<
 *     """zfftnd(x[, s, direction, normalize, overwrite_x]) -> x
 * 
 */

static System::Object^ zfftnd(System::Object^ x, [InteropServices::Optional]System::Object^ s, [InteropServices::Optional]System::Object^ direction, [InteropServices::Optional]System::Object^ normalize, [InteropServices::Optional]System::Object^ overwrite_x) {
  System::Object^ __pyx_v_x = nullptr;
  System::Object^ __pyx_v_s = nullptr;
  fwi_integer_t __pyx_v_direction;
  System::Object^ __pyx_v_normalize = nullptr;
  int __pyx_v_overwrite_x;
  NumpyDotNet::ndarray^ __pyx_v_x_;
  NumpyDotNet::ndarray^ __pyx_v_s_;
  fwi_integer_t __pyx_v_normalize_;
  fwi_integer_t __pyx_v_r;
  fwi_integer_t __pyx_v_howmany;
  fwi_integer_t __pyx_v_j;
  Py_ssize_t __pyx_v_i;
  Py_ssize_t __pyx_v_sz;
  Py_ssize_t __pyx_v_xsz;
  NumpyDotNet::IExtBufferProtocol^ __pyx_bstruct_s_;
  Py_ssize_t __pyx_bstride_0_s_ = 0;
  Py_ssize_t __pyx_bshape_0_s_ = 0;
  System::Object^ __pyx_r = nullptr;
  System::Object^ __pyx_t_1 = nullptr;
  int __pyx_t_2;
  System::Object^ __pyx_t_3 = nullptr;
  fwi_integer_t __pyx_t_4;
  long __pyx_t_5;
  System::Object^ __pyx_t_6 = nullptr;
  NumpyDotNet::ndarray^ __pyx_t_7 = nullptr;
  fwi_integer_t __pyx_t_8;
  fwi_integer_t __pyx_t_9;
  Py_ssize_t __pyx_t_10;
  Py_ssize_t __pyx_t_11;
  int __pyx_t_12;
  __pyx_v_x = x;
  if (dynamic_cast<System::Reflection::Missing^>(s) == nullptr) {
    __pyx_v_s = s;
  } else {
    __pyx_v_s = ((System::Object^)nullptr);
  }
  if (dynamic_cast<System::Reflection::Missing^>(direction) == nullptr) {
    __pyx_v_direction = __site_cvt_280_0->Target(__site_cvt_280_0, direction);
  } else {
    __pyx_v_direction = ((fwi_integer_t)1);
  }
  if (dynamic_cast<System::Reflection::Missing^>(normalize) == nullptr) {
    __pyx_v_normalize = normalize;
  } else {
    __pyx_v_normalize = ((System::Object^)nullptr);
  }
  if (dynamic_cast<System::Reflection::Missing^>(overwrite_x) == nullptr) {
    __pyx_v_overwrite_x = __site_cvt_280_0_1->Target(__site_cvt_280_0_1, overwrite_x);
  } else {
    __pyx_v_overwrite_x = ((int)0);
  }
  __pyx_v_x_ = nullptr;
  __pyx_v_s_ = nullptr;
  __pyx_bstruct_s_ = nullptr;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":303
 *     cdef fwi_integer_t j
 *     cdef Py_ssize_t i, sz, xsz
 *     normalize_ = normalize if (normalize is not None) else direction < 0             # <<<<<<<<<<<<<<
 *     j = 0
 *     x_ = np.PyArray_FROMANY(x, fwc_complex_x16_t_enum, 0, 0,
 */
  __pyx_t_2 = (__pyx_v_normalize != nullptr);
  if (__pyx_t_2) {
    __pyx_t_1 = __pyx_v_normalize;
  } else {
    __pyx_t_3 = (__pyx_v_direction < 0);
    __pyx_t_1 = __pyx_t_3;
    __pyx_t_3 = nullptr;
  }
  __pyx_t_4 = __site_cvt_fwi_integer_t_303_17->Target(__site_cvt_fwi_integer_t_303_17, __pyx_t_1);
  __pyx_t_1 = nullptr;
  __pyx_v_normalize_ = __pyx_t_4;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":304
 *     cdef Py_ssize_t i, sz, xsz
 *     normalize_ = normalize if (normalize is not None) else direction < 0
 *     j = 0             # <<<<<<<<<<<<<<
 *     x_ = np.PyArray_FROMANY(x, fwc_complex_x16_t_enum, 0, 0,
 *                             np.NPY_C_CONTIGUOUS | np.NPY_FORCECAST |
 */
  __pyx_v_j = 0;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":305
 *     normalize_ = normalize if (normalize is not None) else direction < 0
 *     j = 0
 *     x_ = np.PyArray_FROMANY(x, fwc_complex_x16_t_enum, 0, 0,             # <<<<<<<<<<<<<<
 *                             np.NPY_C_CONTIGUOUS | np.NPY_FORCECAST |
 *                             (0 if overwrite_x else np.NPY_ENSURECOPY))
 */
  __pyx_t_1 = (System::Object^)(long long)(NPY_CDOUBLE);

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":307
 *     x_ = np.PyArray_FROMANY(x, fwc_complex_x16_t_enum, 0, 0,
 *                             np.NPY_C_CONTIGUOUS | np.NPY_FORCECAST |
 *                             (0 if overwrite_x else np.NPY_ENSURECOPY))             # <<<<<<<<<<<<<<
 *     # Next, let the default of s be the tuple x_.shape,
 *     # and get the array of s
 */
  if (__pyx_v_overwrite_x) {
    __pyx_t_5 = 0;
  } else {
    __pyx_t_5 = NPY_ENSURECOPY;
  }
  __pyx_t_3 = ((NPY_C_CONTIGUOUS | NPY_FORCECAST) | __pyx_t_5);
  __pyx_t_6 = PyArray_FROMANY(__pyx_v_x, __pyx_t_1, __pyx_int_0, __pyx_int_0, __pyx_t_3); 
  __pyx_t_1 = nullptr;
  __pyx_t_3 = nullptr;
  if (__pyx_t_6 == nullptr || dynamic_cast<NumpyDotNet::ndarray^>(__pyx_t_6) == nullptr) {
    throw PythonOps::MakeException(__pyx_context, PythonOps::GetGlobal(__pyx_context, "TypeError"), "type error", nullptr);
  }
  __pyx_v_x_ = ((NumpyDotNet::ndarray^)__pyx_t_6);
  __pyx_t_6 = nullptr;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":310
 *     # Next, let the default of s be the tuple x_.shape,
 *     # and get the array of s
 *     if s is None:             # <<<<<<<<<<<<<<
 *         s = (<object>x_).shape
 *     s_ = np.PyArray_FROMANY(s, fwi_integer_t_enum, 1, 1,
 */
  __pyx_t_2 = (__pyx_v_s == nullptr);
  if (__pyx_t_2) {

    /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":311
 *     # and get the array of s
 *     if s is None:
 *         s = (<object>x_).shape             # <<<<<<<<<<<<<<
 *     s_ = np.PyArray_FROMANY(s, fwi_integer_t_enum, 1, 1,
 *                             np.NPY_C_CONTIGUOUS | np.NPY_FORCECAST)
 */
    __pyx_t_6 = __site_get_shape_311_24->Target(__site_get_shape_311_24, ((System::Object^)__pyx_v_x_), __pyx_context);
    __pyx_v_s = __pyx_t_6;
    __pyx_t_6 = nullptr;
    goto __pyx_L5;
  }
  __pyx_L5:;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":312
 *     if s is None:
 *         s = (<object>x_).shape
 *     s_ = np.PyArray_FROMANY(s, fwi_integer_t_enum, 1, 1,             # <<<<<<<<<<<<<<
 *                             np.NPY_C_CONTIGUOUS | np.NPY_FORCECAST)
 *     r = np.PyArray_NDIM(x_)
 */
  __pyx_t_6 = (System::Object^)(long long)(NPY_INT);

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":313
 *         s = (<object>x_).shape
 *     s_ = np.PyArray_FROMANY(s, fwi_integer_t_enum, 1, 1,
 *                             np.NPY_C_CONTIGUOUS | np.NPY_FORCECAST)             # <<<<<<<<<<<<<<
 *     r = np.PyArray_NDIM(x_)
 *     if not (r == np.PyArray_DIMS(s_)[0]):
 */
  __pyx_t_3 = (System::Object^)(long long)((NPY_C_CONTIGUOUS | NPY_FORCECAST));
  __pyx_t_1 = PyArray_FROMANY(__pyx_v_s, __pyx_t_6, __pyx_int_1, __pyx_int_1, __pyx_t_3); 
  __pyx_t_6 = nullptr;
  __pyx_t_3 = nullptr;
  if (__pyx_t_1 == nullptr || dynamic_cast<NumpyDotNet::ndarray^>(__pyx_t_1) == nullptr) {
    throw PythonOps::MakeException(__pyx_context, PythonOps::GetGlobal(__pyx_context, "TypeError"), "type error", nullptr);
  }
  __pyx_t_7 = ((NumpyDotNet::ndarray^)__pyx_t_1);
  {
    __Pyx_BufFmt_StackElem __pyx_stack[1];
    __Pyx_SafeReleaseBuffer(__pyx_bstruct_s_);
    __Pyx_GetBufferAndValidate(__pyx_bstruct_s_, __pyx_t_7, &__Pyx_TypeInfo_int, PyBUF_FORMAT| PyBUF_C_CONTIGUOUS, 1, 0, __pyx_stack);
    __pyx_bstride_0_s_ = __pyx_bstruct_s_->Strides[0];
    __pyx_bshape_0_s_ = __pyx_bstruct_s_->Shape[0];
  }
  __pyx_t_7 = nullptr;
  __pyx_v_s_ = ((NumpyDotNet::ndarray^)__pyx_t_1);
  __pyx_t_1 = nullptr;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":314
 *     s_ = np.PyArray_FROMANY(s, fwi_integer_t_enum, 1, 1,
 *                             np.NPY_C_CONTIGUOUS | np.NPY_FORCECAST)
 *     r = np.PyArray_NDIM(x_)             # <<<<<<<<<<<<<<
 *     if not (r == np.PyArray_DIMS(s_)[0]):
 *         raise ValueError('Condition on arguments not satisfied: x.ndim == s.shape[0]')
 */
  __pyx_t_1 = PyArray_NDIM(((System::Object^)__pyx_v_x_)); 
  __pyx_t_8 = __site_cvt_fwi_integer_t_314_23->Target(__site_cvt_fwi_integer_t_314_23, __pyx_t_1);
  __pyx_t_1 = nullptr;
  __pyx_v_r = __pyx_t_8;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":315
 *                             np.NPY_C_CONTIGUOUS | np.NPY_FORCECAST)
 *     r = np.PyArray_NDIM(x_)
 *     if not (r == np.PyArray_DIMS(s_)[0]):             # <<<<<<<<<<<<<<
 *         raise ValueError('Condition on arguments not satisfied: x.ndim == s.shape[0]')
 *     xsz = np.PyArray_SIZE(x_)
 */
  __pyx_t_2 = (!(__pyx_v_r == (PyArray_DIMS(((NumpyDotNet::ndarray^)__pyx_v_s_))[0])));
  if (__pyx_t_2) {

    /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":316
 *     r = np.PyArray_NDIM(x_)
 *     if not (r == np.PyArray_DIMS(s_)[0]):
 *         raise ValueError('Condition on arguments not satisfied: x.ndim == s.shape[0]')             # <<<<<<<<<<<<<<
 *     xsz = np.PyArray_SIZE(x_)
 *     sz = 1
 */
    __pyx_t_1 = PythonOps::GetGlobal(__pyx_context, "ValueError");
    __pyx_t_3 = __site_call1_316_24->Target(__site_call1_316_24, __pyx_context, __pyx_t_1, ((System::Object^)"Condition on arguments not satisfied: x.ndim == s.shape[0]"));
    __pyx_t_1 = nullptr;
    throw PythonOps::MakeException(__pyx_context, __pyx_t_3, nullptr, nullptr);
    __pyx_t_3 = nullptr;
    goto __pyx_L6;
  }
  __pyx_L6:;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":317
 *     if not (r == np.PyArray_DIMS(s_)[0]):
 *         raise ValueError('Condition on arguments not satisfied: x.ndim == s.shape[0]')
 *     xsz = np.PyArray_SIZE(x_)             # <<<<<<<<<<<<<<
 *     sz = 1
 *     for i in range(r):
 */
  __pyx_v_xsz = PyArray_SIZE(__pyx_v_x_);

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":318
 *         raise ValueError('Condition on arguments not satisfied: x.ndim == s.shape[0]')
 *     xsz = np.PyArray_SIZE(x_)
 *     sz = 1             # <<<<<<<<<<<<<<
 *     for i in range(r):
 *         sz *= s_[i]
 */
  __pyx_v_sz = 1;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":319
 *     xsz = np.PyArray_SIZE(x_)
 *     sz = 1
 *     for i in range(r):             # <<<<<<<<<<<<<<
 *         sz *= s_[i]
 *     howmany = xsz // sz
 */
  __pyx_t_9 = __pyx_v_r;
  for (__pyx_t_10 = 0; __pyx_t_10 < __pyx_t_9; __pyx_t_10+=1) {
    __pyx_v_i = __pyx_t_10;

    /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":320
 *     sz = 1
 *     for i in range(r):
 *         sz *= s_[i]             # <<<<<<<<<<<<<<
 *     howmany = xsz // sz
 *     if sz * howmany != xsz:
 */
    __pyx_t_11 = __pyx_v_i;
    __pyx_t_12 = -1;
    if (__pyx_t_11 < 0) {
      __pyx_t_11 += __pyx_bshape_0_s_;
      if (unlikely(__pyx_t_11 < 0)) __pyx_t_12 = 0;
    } else if (unlikely(__pyx_t_11 >= __pyx_bshape_0_s_)) __pyx_t_12 = 0;
    if (unlikely(__pyx_t_12 != -1)) {
      __Pyx_RaiseBufferIndexError(__pyx_t_12);
    }
    __pyx_v_sz *= (*__Pyx_BufPtrCContig1d(int *, (int *)(long long)__pyx_bstruct_s_->UnsafeAddress, __pyx_t_11, __pyx_bstride_0_s_));
  }

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":321
 *     for i in range(r):
 *         sz *= s_[i]
 *     howmany = xsz // sz             # <<<<<<<<<<<<<<
 *     if sz * howmany != xsz:
 *         raise ValueError("inconsistency in x.shape and s argument")
 */
  __pyx_v_howmany = (__pyx_v_xsz / __pyx_v_sz);

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":322
 *         sz *= s_[i]
 *     howmany = xsz // sz
 *     if sz * howmany != xsz:             # <<<<<<<<<<<<<<
 *         raise ValueError("inconsistency in x.shape and s argument")
 *     fc.zfftnd(<fwc_complex_x16_t*>np.PyArray_DATA(x_), r, <fwi_integer_t*>np.PyArray_DATA(s_), direction, howmany, normalize_)
 */
  __pyx_t_2 = ((__pyx_v_sz * __pyx_v_howmany) != __pyx_v_xsz);
  if (__pyx_t_2) {

    /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":323
 *     howmany = xsz // sz
 *     if sz * howmany != xsz:
 *         raise ValueError("inconsistency in x.shape and s argument")             # <<<<<<<<<<<<<<
 *     fc.zfftnd(<fwc_complex_x16_t*>np.PyArray_DATA(x_), r, <fwi_integer_t*>np.PyArray_DATA(s_), direction, howmany, normalize_)
 *     # Return the non-flattened view of the buffer
 */
    __pyx_t_3 = PythonOps::GetGlobal(__pyx_context, "ValueError");
    __pyx_t_1 = __site_call1_323_24->Target(__site_call1_323_24, __pyx_context, __pyx_t_3, ((System::Object^)"inconsistency in x.shape and s argument"));
    __pyx_t_3 = nullptr;
    throw PythonOps::MakeException(__pyx_context, __pyx_t_1, nullptr, nullptr);
    __pyx_t_1 = nullptr;
    goto __pyx_L9;
  }
  __pyx_L9:;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":324
 *     if sz * howmany != xsz:
 *         raise ValueError("inconsistency in x.shape and s argument")
 *     fc.zfftnd(<fwc_complex_x16_t*>np.PyArray_DATA(x_), r, <fwi_integer_t*>np.PyArray_DATA(s_), direction, howmany, normalize_)             # <<<<<<<<<<<<<<
 *     # Return the non-flattened view of the buffer
 *     return x_
 */
  GLOBALFUNC(zfftnd)(((__pyx_t_double_complex *)PyArray_DATA(__pyx_v_x_)), __pyx_v_r, ((fwi_integer_t *)PyArray_DATA(((NumpyDotNet::ndarray^)__pyx_v_s_))), __pyx_v_direction, __pyx_v_howmany, __pyx_v_normalize_);

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":326
 *     fc.zfftnd(<fwc_complex_x16_t*>np.PyArray_DATA(x_), r, <fwi_integer_t*>np.PyArray_DATA(s_), direction, howmany, normalize_)
 *     # Return the non-flattened view of the buffer
 *     return x_             # <<<<<<<<<<<<<<
 * 
 * 
 */
  __pyx_r = ((System::Object^)__pyx_v_x_);
  goto __pyx_L0;

  __pyx_r = nullptr;
  __pyx_L0:;
  __Pyx_SafeReleaseBuffer(__pyx_bstruct_s_);
  return __pyx_r;
}

/* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":330
 * 
 * # Template for destroy_cfft_cache, destroy_cfftnd_cache, destroy_dct1_cache, destroy_dct2_cache, destroy_ddct1_cache, destroy_ddct2_cache, destroy_drfft_cache, destroy_rfft_cache, destroy_zfft_cache, destroy_zfftnd_cache
 * cpdef object destroy_cfft_cache():             # <<<<<<<<<<<<<<
 *     """destroy_cfft_cache()
 * 
 */

static  System::Object^ destroy_cfft_cache(void) {
  System::Object^ __pyx_r = nullptr;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":338
 * 
 *     """
 *     fc.destroy_cfft_cache()             # <<<<<<<<<<<<<<
 * cpdef object destroy_cfftnd_cache():
 *     """destroy_cfftnd_cache()
 */
  GLOBALFUNC(destroy_cfft_cache)();

  __pyx_r = nullptr;
  return __pyx_r;
}

/* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":339
 *     """
 *     fc.destroy_cfft_cache()
 * cpdef object destroy_cfftnd_cache():             # <<<<<<<<<<<<<<
 *     """destroy_cfftnd_cache()
 * 
 */

static  System::Object^ destroy_cfftnd_cache(void) {
  System::Object^ __pyx_r = nullptr;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":347
 * 
 *     """
 *     fc.destroy_cfftnd_cache()             # <<<<<<<<<<<<<<
 * cpdef object destroy_dct1_cache():
 *     """destroy_dct1_cache()
 */
  GLOBALFUNC(destroy_cfftnd_cache)();

  __pyx_r = nullptr;
  return __pyx_r;
}

/* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":348
 *     """
 *     fc.destroy_cfftnd_cache()
 * cpdef object destroy_dct1_cache():             # <<<<<<<<<<<<<<
 *     """destroy_dct1_cache()
 * 
 */

static  System::Object^ destroy_dct1_cache(void) {
  System::Object^ __pyx_r = nullptr;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":356
 * 
 *     """
 *     fc.destroy_dct1_cache()             # <<<<<<<<<<<<<<
 * cpdef object destroy_dct2_cache():
 *     """destroy_dct2_cache()
 */
  GLOBALFUNC(destroy_dct1_cache)();

  __pyx_r = nullptr;
  return __pyx_r;
}

/* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":357
 *     """
 *     fc.destroy_dct1_cache()
 * cpdef object destroy_dct2_cache():             # <<<<<<<<<<<<<<
 *     """destroy_dct2_cache()
 * 
 */

static  System::Object^ destroy_dct2_cache(void) {
  System::Object^ __pyx_r = nullptr;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":365
 * 
 *     """
 *     fc.destroy_dct2_cache()             # <<<<<<<<<<<<<<
 * cpdef object destroy_ddct1_cache():
 *     """destroy_ddct1_cache()
 */
  GLOBALFUNC(destroy_dct2_cache)();

  __pyx_r = nullptr;
  return __pyx_r;
}

/* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":366
 *     """
 *     fc.destroy_dct2_cache()
 * cpdef object destroy_ddct1_cache():             # <<<<<<<<<<<<<<
 *     """destroy_ddct1_cache()
 * 
 */

static  System::Object^ destroy_ddct1_cache(void) {
  System::Object^ __pyx_r = nullptr;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":374
 * 
 *     """
 *     fc.destroy_ddct1_cache()             # <<<<<<<<<<<<<<
 * cpdef object destroy_ddct2_cache():
 *     """destroy_ddct2_cache()
 */
  GLOBALFUNC(destroy_ddct1_cache)();

  __pyx_r = nullptr;
  return __pyx_r;
}

/* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":375
 *     """
 *     fc.destroy_ddct1_cache()
 * cpdef object destroy_ddct2_cache():             # <<<<<<<<<<<<<<
 *     """destroy_ddct2_cache()
 * 
 */

static  System::Object^ destroy_ddct2_cache(void) {
  System::Object^ __pyx_r = nullptr;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":383
 * 
 *     """
 *     fc.destroy_ddct2_cache()             # <<<<<<<<<<<<<<
 * cpdef object destroy_drfft_cache():
 *     """destroy_drfft_cache()
 */
  GLOBALFUNC(destroy_ddct2_cache)();

  __pyx_r = nullptr;
  return __pyx_r;
}

/* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":384
 *     """
 *     fc.destroy_ddct2_cache()
 * cpdef object destroy_drfft_cache():             # <<<<<<<<<<<<<<
 *     """destroy_drfft_cache()
 * 
 */

static  System::Object^ destroy_drfft_cache(void) {
  System::Object^ __pyx_r = nullptr;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":392
 * 
 *     """
 *     fc.destroy_drfft_cache()             # <<<<<<<<<<<<<<
 * cpdef object destroy_rfft_cache():
 *     """destroy_rfft_cache()
 */
  GLOBALFUNC(destroy_drfft_cache)();

  __pyx_r = nullptr;
  return __pyx_r;
}

/* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":393
 *     """
 *     fc.destroy_drfft_cache()
 * cpdef object destroy_rfft_cache():             # <<<<<<<<<<<<<<
 *     """destroy_rfft_cache()
 * 
 */

static  System::Object^ destroy_rfft_cache(void) {
  System::Object^ __pyx_r = nullptr;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":401
 * 
 *     """
 *     fc.destroy_rfft_cache()             # <<<<<<<<<<<<<<
 * cpdef object destroy_zfft_cache():
 *     """destroy_zfft_cache()
 */
  GLOBALFUNC(destroy_rfft_cache)();

  __pyx_r = nullptr;
  return __pyx_r;
}

/* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":402
 *     """
 *     fc.destroy_rfft_cache()
 * cpdef object destroy_zfft_cache():             # <<<<<<<<<<<<<<
 *     """destroy_zfft_cache()
 * 
 */

static  System::Object^ destroy_zfft_cache(void) {
  System::Object^ __pyx_r = nullptr;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":410
 * 
 *     """
 *     fc.destroy_zfft_cache()             # <<<<<<<<<<<<<<
 * cpdef object destroy_zfftnd_cache():
 *     """destroy_zfftnd_cache()
 */
  GLOBALFUNC(destroy_zfft_cache)();

  __pyx_r = nullptr;
  return __pyx_r;
}

/* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":411
 *     """
 *     fc.destroy_zfft_cache()
 * cpdef object destroy_zfftnd_cache():             # <<<<<<<<<<<<<<
 *     """destroy_zfftnd_cache()
 * 
 */

static  System::Object^ destroy_zfftnd_cache(void) {
  System::Object^ __pyx_r = nullptr;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":419
 * 
 *     """
 *     fc.destroy_zfftnd_cache()             # <<<<<<<<<<<<<<
 * 
 * 
 */
  GLOBALFUNC(destroy_zfftnd_cache)();

  __pyx_r = nullptr;
  return __pyx_r;
}

/* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":423
 * 
 * # Template for dct1, dct2, dct3, ddct1, ddct2, ddct3
 * def dct1(object x, object n=None, fwi_integer_t normalize=0, bint overwrite_x=False):             # <<<<<<<<<<<<<<
 *     """dct1(x[, n, normalize, overwrite_x]) -> x
 * 
 */

static System::Object^ dct1(System::Object^ x, [InteropServices::Optional]System::Object^ n, [InteropServices::Optional]System::Object^ normalize, [InteropServices::Optional]System::Object^ overwrite_x) {
  System::Object^ __pyx_v_x = nullptr;
  System::Object^ __pyx_v_n = nullptr;
  fwi_integer_t __pyx_v_normalize;
  int __pyx_v_overwrite_x;
  NumpyDotNet::ndarray^ __pyx_v_x_;
  fwi_integer_t __pyx_v_n_;
  fwi_integer_t __pyx_v_howmany;
  System::Object^ __pyx_r = nullptr;
  System::Object^ __pyx_t_1 = nullptr;
  long __pyx_t_2;
  System::Object^ __pyx_t_3 = nullptr;
  System::Object^ __pyx_t_4 = nullptr;
  int __pyx_t_5;
  fwi_integer_t __pyx_t_6;
  int __pyx_t_7;
  int __pyx_t_8;
  __pyx_v_x = x;
  if (dynamic_cast<System::Reflection::Missing^>(n) == nullptr) {
    __pyx_v_n = n;
  } else {
    __pyx_v_n = ((System::Object^)nullptr);
  }
  if (dynamic_cast<System::Reflection::Missing^>(normalize) == nullptr) {
    __pyx_v_normalize = __site_cvt_423_0->Target(__site_cvt_423_0, normalize);
  } else {
    __pyx_v_normalize = ((fwi_integer_t)0);
  }
  if (dynamic_cast<System::Reflection::Missing^>(overwrite_x) == nullptr) {
    __pyx_v_overwrite_x = __site_cvt_423_0_1->Target(__site_cvt_423_0_1, overwrite_x);
  } else {
    __pyx_v_overwrite_x = ((int)0);
  }
  __pyx_v_x_ = nullptr;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":441
 *     cdef fwi_integer_t n_
 *     cdef fwi_integer_t howmany
 *     x_ = np.PyArray_FROMANY(x, fwr_real_x4_t_enum, 0, 0,             # <<<<<<<<<<<<<<
 *                             np.NPY_C_CONTIGUOUS | np.NPY_FORCECAST |
 *                             (0 if overwrite_x else np.NPY_ENSURECOPY))
 */
  __pyx_t_1 = (System::Object^)(long long)(NPY_FLOAT32);

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":443
 *     x_ = np.PyArray_FROMANY(x, fwr_real_x4_t_enum, 0, 0,
 *                             np.NPY_C_CONTIGUOUS | np.NPY_FORCECAST |
 *                             (0 if overwrite_x else np.NPY_ENSURECOPY))             # <<<<<<<<<<<<<<
 *     n_ = n if (n is not None) else np.PyArray_SIZE(x_)
 *     howmany = np.PyArray_SIZE(x_) // n_
 */
  if (__pyx_v_overwrite_x) {
    __pyx_t_2 = 0;
  } else {
    __pyx_t_2 = NPY_ENSURECOPY;
  }
  __pyx_t_3 = ((NPY_C_CONTIGUOUS | NPY_FORCECAST) | __pyx_t_2);
  __pyx_t_4 = PyArray_FROMANY(__pyx_v_x, __pyx_t_1, __pyx_int_0, __pyx_int_0, __pyx_t_3); 
  __pyx_t_1 = nullptr;
  __pyx_t_3 = nullptr;
  if (__pyx_t_4 == nullptr || dynamic_cast<NumpyDotNet::ndarray^>(__pyx_t_4) == nullptr) {
    throw PythonOps::MakeException(__pyx_context, PythonOps::GetGlobal(__pyx_context, "TypeError"), "type error", nullptr);
  }
  __pyx_v_x_ = ((NumpyDotNet::ndarray^)__pyx_t_4);
  __pyx_t_4 = nullptr;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":444
 *                             np.NPY_C_CONTIGUOUS | np.NPY_FORCECAST |
 *                             (0 if overwrite_x else np.NPY_ENSURECOPY))
 *     n_ = n if (n is not None) else np.PyArray_SIZE(x_)             # <<<<<<<<<<<<<<
 *     howmany = np.PyArray_SIZE(x_) // n_
 *     if not ((n_ > 0) and (n_ <= np.PyArray_SIZE(x_))):
 */
  __pyx_t_5 = (__pyx_v_n != nullptr);
  if (__pyx_t_5) {
    __pyx_t_4 = __pyx_v_n;
  } else {
    __pyx_t_3 = PyArray_SIZE(__pyx_v_x_);
    __pyx_t_4 = __pyx_t_3;
    __pyx_t_3 = nullptr;
  }
  __pyx_t_6 = __site_cvt_fwi_integer_t_444_9->Target(__site_cvt_fwi_integer_t_444_9, __pyx_t_4);
  __pyx_t_4 = nullptr;
  __pyx_v_n_ = __pyx_t_6;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":445
 *                             (0 if overwrite_x else np.NPY_ENSURECOPY))
 *     n_ = n if (n is not None) else np.PyArray_SIZE(x_)
 *     howmany = np.PyArray_SIZE(x_) // n_             # <<<<<<<<<<<<<<
 *     if not ((n_ > 0) and (n_ <= np.PyArray_SIZE(x_))):
 *         raise ValueError('Condition on arguments not satisfied: (n > 0) and (n <= x.size)')
 */
  __pyx_v_howmany = (PyArray_SIZE(__pyx_v_x_) / __pyx_v_n_);

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":446
 *     n_ = n if (n is not None) else np.PyArray_SIZE(x_)
 *     howmany = np.PyArray_SIZE(x_) // n_
 *     if not ((n_ > 0) and (n_ <= np.PyArray_SIZE(x_))):             # <<<<<<<<<<<<<<
 *         raise ValueError('Condition on arguments not satisfied: (n > 0) and (n <= x.size)')
 *     if not ((n_ * howmany) == np.PyArray_SIZE(x_)):
 */
  __pyx_t_5 = (__pyx_v_n_ > 0);
  if (__pyx_t_5) {
    __pyx_t_7 = (__pyx_v_n_ <= PyArray_SIZE(__pyx_v_x_));
    __pyx_t_8 = __pyx_t_7;
  } else {
    __pyx_t_8 = __pyx_t_5;
  }
  __pyx_t_5 = (!__pyx_t_8);
  if (__pyx_t_5) {

    /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":447
 *     howmany = np.PyArray_SIZE(x_) // n_
 *     if not ((n_ > 0) and (n_ <= np.PyArray_SIZE(x_))):
 *         raise ValueError('Condition on arguments not satisfied: (n > 0) and (n <= x.size)')             # <<<<<<<<<<<<<<
 *     if not ((n_ * howmany) == np.PyArray_SIZE(x_)):
 *         raise ValueError('Condition on arguments not satisfied: (n * howmany) == x.size')
 */
    __pyx_t_4 = PythonOps::GetGlobal(__pyx_context, "ValueError");
    __pyx_t_3 = __site_call1_447_24->Target(__site_call1_447_24, __pyx_context, __pyx_t_4, ((System::Object^)"Condition on arguments not satisfied: (n > 0) and (n <= x.size)"));
    __pyx_t_4 = nullptr;
    throw PythonOps::MakeException(__pyx_context, __pyx_t_3, nullptr, nullptr);
    __pyx_t_3 = nullptr;
    goto __pyx_L5;
  }
  __pyx_L5:;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":448
 *     if not ((n_ > 0) and (n_ <= np.PyArray_SIZE(x_))):
 *         raise ValueError('Condition on arguments not satisfied: (n > 0) and (n <= x.size)')
 *     if not ((n_ * howmany) == np.PyArray_SIZE(x_)):             # <<<<<<<<<<<<<<
 *         raise ValueError('Condition on arguments not satisfied: (n * howmany) == x.size')
 *     fc.dct1(<fwr_real_x4_t*>np.PyArray_DATA(x_), n_, howmany, normalize)
 */
  __pyx_t_5 = (!((__pyx_v_n_ * __pyx_v_howmany) == PyArray_SIZE(__pyx_v_x_)));
  if (__pyx_t_5) {

    /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":449
 *         raise ValueError('Condition on arguments not satisfied: (n > 0) and (n <= x.size)')
 *     if not ((n_ * howmany) == np.PyArray_SIZE(x_)):
 *         raise ValueError('Condition on arguments not satisfied: (n * howmany) == x.size')             # <<<<<<<<<<<<<<
 *     fc.dct1(<fwr_real_x4_t*>np.PyArray_DATA(x_), n_, howmany, normalize)
 *     return x_
 */
    __pyx_t_3 = PythonOps::GetGlobal(__pyx_context, "ValueError");
    __pyx_t_4 = __site_call1_449_24->Target(__site_call1_449_24, __pyx_context, __pyx_t_3, ((System::Object^)"Condition on arguments not satisfied: (n * howmany) == x.size"));
    __pyx_t_3 = nullptr;
    throw PythonOps::MakeException(__pyx_context, __pyx_t_4, nullptr, nullptr);
    __pyx_t_4 = nullptr;
    goto __pyx_L6;
  }
  __pyx_L6:;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":450
 *     if not ((n_ * howmany) == np.PyArray_SIZE(x_)):
 *         raise ValueError('Condition on arguments not satisfied: (n * howmany) == x.size')
 *     fc.dct1(<fwr_real_x4_t*>np.PyArray_DATA(x_), n_, howmany, normalize)             # <<<<<<<<<<<<<<
 *     return x_
 * def dct2(object x, object n=None, fwi_integer_t normalize=0, bint overwrite_x=False):
 */
  GLOBALFUNC(dct1)(((fwr_real_x4_t *)PyArray_DATA(__pyx_v_x_)), __pyx_v_n_, __pyx_v_howmany, __pyx_v_normalize);

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":451
 *         raise ValueError('Condition on arguments not satisfied: (n * howmany) == x.size')
 *     fc.dct1(<fwr_real_x4_t*>np.PyArray_DATA(x_), n_, howmany, normalize)
 *     return x_             # <<<<<<<<<<<<<<
 * def dct2(object x, object n=None, fwi_integer_t normalize=0, bint overwrite_x=False):
 *     """dct2(x[, n, normalize, overwrite_x]) -> x
 */
  __pyx_r = ((System::Object^)__pyx_v_x_);
  goto __pyx_L0;

  __pyx_r = nullptr;
  __pyx_L0:;
  return __pyx_r;
}

/* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":452
 *     fc.dct1(<fwr_real_x4_t*>np.PyArray_DATA(x_), n_, howmany, normalize)
 *     return x_
 * def dct2(object x, object n=None, fwi_integer_t normalize=0, bint overwrite_x=False):             # <<<<<<<<<<<<<<
 *     """dct2(x[, n, normalize, overwrite_x]) -> x
 * 
 */

static System::Object^ dct2(System::Object^ x, [InteropServices::Optional]System::Object^ n, [InteropServices::Optional]System::Object^ normalize, [InteropServices::Optional]System::Object^ overwrite_x) {
  System::Object^ __pyx_v_x = nullptr;
  System::Object^ __pyx_v_n = nullptr;
  fwi_integer_t __pyx_v_normalize;
  int __pyx_v_overwrite_x;
  NumpyDotNet::ndarray^ __pyx_v_x_;
  fwi_integer_t __pyx_v_n_;
  fwi_integer_t __pyx_v_howmany;
  System::Object^ __pyx_r = nullptr;
  System::Object^ __pyx_t_1 = nullptr;
  long __pyx_t_2;
  System::Object^ __pyx_t_3 = nullptr;
  System::Object^ __pyx_t_4 = nullptr;
  int __pyx_t_5;
  fwi_integer_t __pyx_t_6;
  int __pyx_t_7;
  int __pyx_t_8;
  __pyx_v_x = x;
  if (dynamic_cast<System::Reflection::Missing^>(n) == nullptr) {
    __pyx_v_n = n;
  } else {
    __pyx_v_n = ((System::Object^)nullptr);
  }
  if (dynamic_cast<System::Reflection::Missing^>(normalize) == nullptr) {
    __pyx_v_normalize = __site_cvt_452_0->Target(__site_cvt_452_0, normalize);
  } else {
    __pyx_v_normalize = ((fwi_integer_t)0);
  }
  if (dynamic_cast<System::Reflection::Missing^>(overwrite_x) == nullptr) {
    __pyx_v_overwrite_x = __site_cvt_452_0_1->Target(__site_cvt_452_0_1, overwrite_x);
  } else {
    __pyx_v_overwrite_x = ((int)0);
  }
  __pyx_v_x_ = nullptr;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":470
 *     cdef fwi_integer_t n_
 *     cdef fwi_integer_t howmany
 *     x_ = np.PyArray_FROMANY(x, fwr_real_x4_t_enum, 0, 0,             # <<<<<<<<<<<<<<
 *                             np.NPY_C_CONTIGUOUS | np.NPY_FORCECAST |
 *                             (0 if overwrite_x else np.NPY_ENSURECOPY))
 */
  __pyx_t_1 = (System::Object^)(long long)(NPY_FLOAT32);

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":472
 *     x_ = np.PyArray_FROMANY(x, fwr_real_x4_t_enum, 0, 0,
 *                             np.NPY_C_CONTIGUOUS | np.NPY_FORCECAST |
 *                             (0 if overwrite_x else np.NPY_ENSURECOPY))             # <<<<<<<<<<<<<<
 *     n_ = n if (n is not None) else np.PyArray_SIZE(x_)
 *     howmany = np.PyArray_SIZE(x_) // n_
 */
  if (__pyx_v_overwrite_x) {
    __pyx_t_2 = 0;
  } else {
    __pyx_t_2 = NPY_ENSURECOPY;
  }
  __pyx_t_3 = ((NPY_C_CONTIGUOUS | NPY_FORCECAST) | __pyx_t_2);
  __pyx_t_4 = PyArray_FROMANY(__pyx_v_x, __pyx_t_1, __pyx_int_0, __pyx_int_0, __pyx_t_3); 
  __pyx_t_1 = nullptr;
  __pyx_t_3 = nullptr;
  if (__pyx_t_4 == nullptr || dynamic_cast<NumpyDotNet::ndarray^>(__pyx_t_4) == nullptr) {
    throw PythonOps::MakeException(__pyx_context, PythonOps::GetGlobal(__pyx_context, "TypeError"), "type error", nullptr);
  }
  __pyx_v_x_ = ((NumpyDotNet::ndarray^)__pyx_t_4);
  __pyx_t_4 = nullptr;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":473
 *                             np.NPY_C_CONTIGUOUS | np.NPY_FORCECAST |
 *                             (0 if overwrite_x else np.NPY_ENSURECOPY))
 *     n_ = n if (n is not None) else np.PyArray_SIZE(x_)             # <<<<<<<<<<<<<<
 *     howmany = np.PyArray_SIZE(x_) // n_
 *     if not ((n_ > 0) and (n_ <= np.PyArray_SIZE(x_))):
 */
  __pyx_t_5 = (__pyx_v_n != nullptr);
  if (__pyx_t_5) {
    __pyx_t_4 = __pyx_v_n;
  } else {
    __pyx_t_3 = PyArray_SIZE(__pyx_v_x_);
    __pyx_t_4 = __pyx_t_3;
    __pyx_t_3 = nullptr;
  }
  __pyx_t_6 = __site_cvt_fwi_integer_t_473_9->Target(__site_cvt_fwi_integer_t_473_9, __pyx_t_4);
  __pyx_t_4 = nullptr;
  __pyx_v_n_ = __pyx_t_6;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":474
 *                             (0 if overwrite_x else np.NPY_ENSURECOPY))
 *     n_ = n if (n is not None) else np.PyArray_SIZE(x_)
 *     howmany = np.PyArray_SIZE(x_) // n_             # <<<<<<<<<<<<<<
 *     if not ((n_ > 0) and (n_ <= np.PyArray_SIZE(x_))):
 *         raise ValueError('Condition on arguments not satisfied: (n > 0) and (n <= x.size)')
 */
  __pyx_v_howmany = (PyArray_SIZE(__pyx_v_x_) / __pyx_v_n_);

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":475
 *     n_ = n if (n is not None) else np.PyArray_SIZE(x_)
 *     howmany = np.PyArray_SIZE(x_) // n_
 *     if not ((n_ > 0) and (n_ <= np.PyArray_SIZE(x_))):             # <<<<<<<<<<<<<<
 *         raise ValueError('Condition on arguments not satisfied: (n > 0) and (n <= x.size)')
 *     if not ((n_ * howmany) == np.PyArray_SIZE(x_)):
 */
  __pyx_t_5 = (__pyx_v_n_ > 0);
  if (__pyx_t_5) {
    __pyx_t_7 = (__pyx_v_n_ <= PyArray_SIZE(__pyx_v_x_));
    __pyx_t_8 = __pyx_t_7;
  } else {
    __pyx_t_8 = __pyx_t_5;
  }
  __pyx_t_5 = (!__pyx_t_8);
  if (__pyx_t_5) {

    /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":476
 *     howmany = np.PyArray_SIZE(x_) // n_
 *     if not ((n_ > 0) and (n_ <= np.PyArray_SIZE(x_))):
 *         raise ValueError('Condition on arguments not satisfied: (n > 0) and (n <= x.size)')             # <<<<<<<<<<<<<<
 *     if not ((n_ * howmany) == np.PyArray_SIZE(x_)):
 *         raise ValueError('Condition on arguments not satisfied: (n * howmany) == x.size')
 */
    __pyx_t_4 = PythonOps::GetGlobal(__pyx_context, "ValueError");
    __pyx_t_3 = __site_call1_476_24->Target(__site_call1_476_24, __pyx_context, __pyx_t_4, ((System::Object^)"Condition on arguments not satisfied: (n > 0) and (n <= x.size)"));
    __pyx_t_4 = nullptr;
    throw PythonOps::MakeException(__pyx_context, __pyx_t_3, nullptr, nullptr);
    __pyx_t_3 = nullptr;
    goto __pyx_L5;
  }
  __pyx_L5:;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":477
 *     if not ((n_ > 0) and (n_ <= np.PyArray_SIZE(x_))):
 *         raise ValueError('Condition on arguments not satisfied: (n > 0) and (n <= x.size)')
 *     if not ((n_ * howmany) == np.PyArray_SIZE(x_)):             # <<<<<<<<<<<<<<
 *         raise ValueError('Condition on arguments not satisfied: (n * howmany) == x.size')
 *     fc.dct2(<fwr_real_x4_t*>np.PyArray_DATA(x_), n_, howmany, normalize)
 */
  __pyx_t_5 = (!((__pyx_v_n_ * __pyx_v_howmany) == PyArray_SIZE(__pyx_v_x_)));
  if (__pyx_t_5) {

    /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":478
 *         raise ValueError('Condition on arguments not satisfied: (n > 0) and (n <= x.size)')
 *     if not ((n_ * howmany) == np.PyArray_SIZE(x_)):
 *         raise ValueError('Condition on arguments not satisfied: (n * howmany) == x.size')             # <<<<<<<<<<<<<<
 *     fc.dct2(<fwr_real_x4_t*>np.PyArray_DATA(x_), n_, howmany, normalize)
 *     return x_
 */
    __pyx_t_3 = PythonOps::GetGlobal(__pyx_context, "ValueError");
    __pyx_t_4 = __site_call1_478_24->Target(__site_call1_478_24, __pyx_context, __pyx_t_3, ((System::Object^)"Condition on arguments not satisfied: (n * howmany) == x.size"));
    __pyx_t_3 = nullptr;
    throw PythonOps::MakeException(__pyx_context, __pyx_t_4, nullptr, nullptr);
    __pyx_t_4 = nullptr;
    goto __pyx_L6;
  }
  __pyx_L6:;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":479
 *     if not ((n_ * howmany) == np.PyArray_SIZE(x_)):
 *         raise ValueError('Condition on arguments not satisfied: (n * howmany) == x.size')
 *     fc.dct2(<fwr_real_x4_t*>np.PyArray_DATA(x_), n_, howmany, normalize)             # <<<<<<<<<<<<<<
 *     return x_
 * def dct3(object x, object n=None, fwi_integer_t normalize=0, bint overwrite_x=False):
 */
  GLOBALFUNC(dct2)(((fwr_real_x4_t *)PyArray_DATA(__pyx_v_x_)), __pyx_v_n_, __pyx_v_howmany, __pyx_v_normalize);

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":480
 *         raise ValueError('Condition on arguments not satisfied: (n * howmany) == x.size')
 *     fc.dct2(<fwr_real_x4_t*>np.PyArray_DATA(x_), n_, howmany, normalize)
 *     return x_             # <<<<<<<<<<<<<<
 * def dct3(object x, object n=None, fwi_integer_t normalize=0, bint overwrite_x=False):
 *     """dct3(x[, n, normalize, overwrite_x]) -> x
 */
  __pyx_r = ((System::Object^)__pyx_v_x_);
  goto __pyx_L0;

  __pyx_r = nullptr;
  __pyx_L0:;
  return __pyx_r;
}

/* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":481
 *     fc.dct2(<fwr_real_x4_t*>np.PyArray_DATA(x_), n_, howmany, normalize)
 *     return x_
 * def dct3(object x, object n=None, fwi_integer_t normalize=0, bint overwrite_x=False):             # <<<<<<<<<<<<<<
 *     """dct3(x[, n, normalize, overwrite_x]) -> x
 * 
 */

static System::Object^ dct3(System::Object^ x, [InteropServices::Optional]System::Object^ n, [InteropServices::Optional]System::Object^ normalize, [InteropServices::Optional]System::Object^ overwrite_x) {
  System::Object^ __pyx_v_x = nullptr;
  System::Object^ __pyx_v_n = nullptr;
  fwi_integer_t __pyx_v_normalize;
  int __pyx_v_overwrite_x;
  NumpyDotNet::ndarray^ __pyx_v_x_;
  fwi_integer_t __pyx_v_n_;
  fwi_integer_t __pyx_v_howmany;
  System::Object^ __pyx_r = nullptr;
  System::Object^ __pyx_t_1 = nullptr;
  long __pyx_t_2;
  System::Object^ __pyx_t_3 = nullptr;
  System::Object^ __pyx_t_4 = nullptr;
  int __pyx_t_5;
  fwi_integer_t __pyx_t_6;
  int __pyx_t_7;
  int __pyx_t_8;
  __pyx_v_x = x;
  if (dynamic_cast<System::Reflection::Missing^>(n) == nullptr) {
    __pyx_v_n = n;
  } else {
    __pyx_v_n = ((System::Object^)nullptr);
  }
  if (dynamic_cast<System::Reflection::Missing^>(normalize) == nullptr) {
    __pyx_v_normalize = __site_cvt_481_0->Target(__site_cvt_481_0, normalize);
  } else {
    __pyx_v_normalize = ((fwi_integer_t)0);
  }
  if (dynamic_cast<System::Reflection::Missing^>(overwrite_x) == nullptr) {
    __pyx_v_overwrite_x = __site_cvt_481_0_1->Target(__site_cvt_481_0_1, overwrite_x);
  } else {
    __pyx_v_overwrite_x = ((int)0);
  }
  __pyx_v_x_ = nullptr;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":499
 *     cdef fwi_integer_t n_
 *     cdef fwi_integer_t howmany
 *     x_ = np.PyArray_FROMANY(x, fwr_real_x4_t_enum, 0, 0,             # <<<<<<<<<<<<<<
 *                             np.NPY_C_CONTIGUOUS | np.NPY_FORCECAST |
 *                             (0 if overwrite_x else np.NPY_ENSURECOPY))
 */
  __pyx_t_1 = (System::Object^)(long long)(NPY_FLOAT32);

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":501
 *     x_ = np.PyArray_FROMANY(x, fwr_real_x4_t_enum, 0, 0,
 *                             np.NPY_C_CONTIGUOUS | np.NPY_FORCECAST |
 *                             (0 if overwrite_x else np.NPY_ENSURECOPY))             # <<<<<<<<<<<<<<
 *     n_ = n if (n is not None) else np.PyArray_SIZE(x_)
 *     howmany = np.PyArray_SIZE(x_) // n_
 */
  if (__pyx_v_overwrite_x) {
    __pyx_t_2 = 0;
  } else {
    __pyx_t_2 = NPY_ENSURECOPY;
  }
  __pyx_t_3 = ((NPY_C_CONTIGUOUS | NPY_FORCECAST) | __pyx_t_2);
  __pyx_t_4 = PyArray_FROMANY(__pyx_v_x, __pyx_t_1, __pyx_int_0, __pyx_int_0, __pyx_t_3); 
  __pyx_t_1 = nullptr;
  __pyx_t_3 = nullptr;
  if (__pyx_t_4 == nullptr || dynamic_cast<NumpyDotNet::ndarray^>(__pyx_t_4) == nullptr) {
    throw PythonOps::MakeException(__pyx_context, PythonOps::GetGlobal(__pyx_context, "TypeError"), "type error", nullptr);
  }
  __pyx_v_x_ = ((NumpyDotNet::ndarray^)__pyx_t_4);
  __pyx_t_4 = nullptr;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":502
 *                             np.NPY_C_CONTIGUOUS | np.NPY_FORCECAST |
 *                             (0 if overwrite_x else np.NPY_ENSURECOPY))
 *     n_ = n if (n is not None) else np.PyArray_SIZE(x_)             # <<<<<<<<<<<<<<
 *     howmany = np.PyArray_SIZE(x_) // n_
 *     if not ((n_ > 0) and (n_ <= np.PyArray_SIZE(x_))):
 */
  __pyx_t_5 = (__pyx_v_n != nullptr);
  if (__pyx_t_5) {
    __pyx_t_4 = __pyx_v_n;
  } else {
    __pyx_t_3 = PyArray_SIZE(__pyx_v_x_);
    __pyx_t_4 = __pyx_t_3;
    __pyx_t_3 = nullptr;
  }
  __pyx_t_6 = __site_cvt_fwi_integer_t_502_9->Target(__site_cvt_fwi_integer_t_502_9, __pyx_t_4);
  __pyx_t_4 = nullptr;
  __pyx_v_n_ = __pyx_t_6;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":503
 *                             (0 if overwrite_x else np.NPY_ENSURECOPY))
 *     n_ = n if (n is not None) else np.PyArray_SIZE(x_)
 *     howmany = np.PyArray_SIZE(x_) // n_             # <<<<<<<<<<<<<<
 *     if not ((n_ > 0) and (n_ <= np.PyArray_SIZE(x_))):
 *         raise ValueError('Condition on arguments not satisfied: (n > 0) and (n <= x.size)')
 */
  __pyx_v_howmany = (PyArray_SIZE(__pyx_v_x_) / __pyx_v_n_);

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":504
 *     n_ = n if (n is not None) else np.PyArray_SIZE(x_)
 *     howmany = np.PyArray_SIZE(x_) // n_
 *     if not ((n_ > 0) and (n_ <= np.PyArray_SIZE(x_))):             # <<<<<<<<<<<<<<
 *         raise ValueError('Condition on arguments not satisfied: (n > 0) and (n <= x.size)')
 *     if not ((n_ * howmany) == np.PyArray_SIZE(x_)):
 */
  __pyx_t_5 = (__pyx_v_n_ > 0);
  if (__pyx_t_5) {
    __pyx_t_7 = (__pyx_v_n_ <= PyArray_SIZE(__pyx_v_x_));
    __pyx_t_8 = __pyx_t_7;
  } else {
    __pyx_t_8 = __pyx_t_5;
  }
  __pyx_t_5 = (!__pyx_t_8);
  if (__pyx_t_5) {

    /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":505
 *     howmany = np.PyArray_SIZE(x_) // n_
 *     if not ((n_ > 0) and (n_ <= np.PyArray_SIZE(x_))):
 *         raise ValueError('Condition on arguments not satisfied: (n > 0) and (n <= x.size)')             # <<<<<<<<<<<<<<
 *     if not ((n_ * howmany) == np.PyArray_SIZE(x_)):
 *         raise ValueError('Condition on arguments not satisfied: (n * howmany) == x.size')
 */
    __pyx_t_4 = PythonOps::GetGlobal(__pyx_context, "ValueError");
    __pyx_t_3 = __site_call1_505_24->Target(__site_call1_505_24, __pyx_context, __pyx_t_4, ((System::Object^)"Condition on arguments not satisfied: (n > 0) and (n <= x.size)"));
    __pyx_t_4 = nullptr;
    throw PythonOps::MakeException(__pyx_context, __pyx_t_3, nullptr, nullptr);
    __pyx_t_3 = nullptr;
    goto __pyx_L5;
  }
  __pyx_L5:;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":506
 *     if not ((n_ > 0) and (n_ <= np.PyArray_SIZE(x_))):
 *         raise ValueError('Condition on arguments not satisfied: (n > 0) and (n <= x.size)')
 *     if not ((n_ * howmany) == np.PyArray_SIZE(x_)):             # <<<<<<<<<<<<<<
 *         raise ValueError('Condition on arguments not satisfied: (n * howmany) == x.size')
 *     fc.dct3(<fwr_real_x4_t*>np.PyArray_DATA(x_), n_, howmany, normalize)
 */
  __pyx_t_5 = (!((__pyx_v_n_ * __pyx_v_howmany) == PyArray_SIZE(__pyx_v_x_)));
  if (__pyx_t_5) {

    /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":507
 *         raise ValueError('Condition on arguments not satisfied: (n > 0) and (n <= x.size)')
 *     if not ((n_ * howmany) == np.PyArray_SIZE(x_)):
 *         raise ValueError('Condition on arguments not satisfied: (n * howmany) == x.size')             # <<<<<<<<<<<<<<
 *     fc.dct3(<fwr_real_x4_t*>np.PyArray_DATA(x_), n_, howmany, normalize)
 *     return x_
 */
    __pyx_t_3 = PythonOps::GetGlobal(__pyx_context, "ValueError");
    __pyx_t_4 = __site_call1_507_24->Target(__site_call1_507_24, __pyx_context, __pyx_t_3, ((System::Object^)"Condition on arguments not satisfied: (n * howmany) == x.size"));
    __pyx_t_3 = nullptr;
    throw PythonOps::MakeException(__pyx_context, __pyx_t_4, nullptr, nullptr);
    __pyx_t_4 = nullptr;
    goto __pyx_L6;
  }
  __pyx_L6:;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":508
 *     if not ((n_ * howmany) == np.PyArray_SIZE(x_)):
 *         raise ValueError('Condition on arguments not satisfied: (n * howmany) == x.size')
 *     fc.dct3(<fwr_real_x4_t*>np.PyArray_DATA(x_), n_, howmany, normalize)             # <<<<<<<<<<<<<<
 *     return x_
 * def ddct1(object x, object n=None, fwi_integer_t normalize=0, bint overwrite_x=False):
 */
  GLOBALFUNC(dct3)(((fwr_real_x4_t *)PyArray_DATA(__pyx_v_x_)), __pyx_v_n_, __pyx_v_howmany, __pyx_v_normalize);

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":509
 *         raise ValueError('Condition on arguments not satisfied: (n * howmany) == x.size')
 *     fc.dct3(<fwr_real_x4_t*>np.PyArray_DATA(x_), n_, howmany, normalize)
 *     return x_             # <<<<<<<<<<<<<<
 * def ddct1(object x, object n=None, fwi_integer_t normalize=0, bint overwrite_x=False):
 *     """ddct1(x[, n, normalize, overwrite_x]) -> x
 */
  __pyx_r = ((System::Object^)__pyx_v_x_);
  goto __pyx_L0;

  __pyx_r = nullptr;
  __pyx_L0:;
  return __pyx_r;
}

/* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":510
 *     fc.dct3(<fwr_real_x4_t*>np.PyArray_DATA(x_), n_, howmany, normalize)
 *     return x_
 * def ddct1(object x, object n=None, fwi_integer_t normalize=0, bint overwrite_x=False):             # <<<<<<<<<<<<<<
 *     """ddct1(x[, n, normalize, overwrite_x]) -> x
 * 
 */

static System::Object^ ddct1(System::Object^ x, [InteropServices::Optional]System::Object^ n, [InteropServices::Optional]System::Object^ normalize, [InteropServices::Optional]System::Object^ overwrite_x) {
  System::Object^ __pyx_v_x = nullptr;
  System::Object^ __pyx_v_n = nullptr;
  fwi_integer_t __pyx_v_normalize;
  int __pyx_v_overwrite_x;
  NumpyDotNet::ndarray^ __pyx_v_x_;
  fwi_integer_t __pyx_v_n_;
  fwi_integer_t __pyx_v_howmany;
  System::Object^ __pyx_r = nullptr;
  System::Object^ __pyx_t_1 = nullptr;
  long __pyx_t_2;
  System::Object^ __pyx_t_3 = nullptr;
  System::Object^ __pyx_t_4 = nullptr;
  int __pyx_t_5;
  fwi_integer_t __pyx_t_6;
  int __pyx_t_7;
  int __pyx_t_8;
  __pyx_v_x = x;
  if (dynamic_cast<System::Reflection::Missing^>(n) == nullptr) {
    __pyx_v_n = n;
  } else {
    __pyx_v_n = ((System::Object^)nullptr);
  }
  if (dynamic_cast<System::Reflection::Missing^>(normalize) == nullptr) {
    __pyx_v_normalize = __site_cvt_510_0->Target(__site_cvt_510_0, normalize);
  } else {
    __pyx_v_normalize = ((fwi_integer_t)0);
  }
  if (dynamic_cast<System::Reflection::Missing^>(overwrite_x) == nullptr) {
    __pyx_v_overwrite_x = __site_cvt_510_0_1->Target(__site_cvt_510_0_1, overwrite_x);
  } else {
    __pyx_v_overwrite_x = ((int)0);
  }
  __pyx_v_x_ = nullptr;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":528
 *     cdef fwi_integer_t n_
 *     cdef fwi_integer_t howmany
 *     x_ = np.PyArray_FROMANY(x, fwr_real_x8_t_enum, 0, 0,             # <<<<<<<<<<<<<<
 *                             np.NPY_C_CONTIGUOUS | np.NPY_FORCECAST |
 *                             (0 if overwrite_x else np.NPY_ENSURECOPY))
 */
  __pyx_t_1 = (System::Object^)(long long)(NPY_FLOAT64);

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":530
 *     x_ = np.PyArray_FROMANY(x, fwr_real_x8_t_enum, 0, 0,
 *                             np.NPY_C_CONTIGUOUS | np.NPY_FORCECAST |
 *                             (0 if overwrite_x else np.NPY_ENSURECOPY))             # <<<<<<<<<<<<<<
 *     n_ = n if (n is not None) else np.PyArray_SIZE(x_)
 *     howmany = np.PyArray_SIZE(x_) // n_
 */
  if (__pyx_v_overwrite_x) {
    __pyx_t_2 = 0;
  } else {
    __pyx_t_2 = NPY_ENSURECOPY;
  }
  __pyx_t_3 = ((NPY_C_CONTIGUOUS | NPY_FORCECAST) | __pyx_t_2);
  __pyx_t_4 = PyArray_FROMANY(__pyx_v_x, __pyx_t_1, __pyx_int_0, __pyx_int_0, __pyx_t_3); 
  __pyx_t_1 = nullptr;
  __pyx_t_3 = nullptr;
  if (__pyx_t_4 == nullptr || dynamic_cast<NumpyDotNet::ndarray^>(__pyx_t_4) == nullptr) {
    throw PythonOps::MakeException(__pyx_context, PythonOps::GetGlobal(__pyx_context, "TypeError"), "type error", nullptr);
  }
  __pyx_v_x_ = ((NumpyDotNet::ndarray^)__pyx_t_4);
  __pyx_t_4 = nullptr;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":531
 *                             np.NPY_C_CONTIGUOUS | np.NPY_FORCECAST |
 *                             (0 if overwrite_x else np.NPY_ENSURECOPY))
 *     n_ = n if (n is not None) else np.PyArray_SIZE(x_)             # <<<<<<<<<<<<<<
 *     howmany = np.PyArray_SIZE(x_) // n_
 *     if not ((n_ > 0) and (n_ <= np.PyArray_SIZE(x_))):
 */
  __pyx_t_5 = (__pyx_v_n != nullptr);
  if (__pyx_t_5) {
    __pyx_t_4 = __pyx_v_n;
  } else {
    __pyx_t_3 = PyArray_SIZE(__pyx_v_x_);
    __pyx_t_4 = __pyx_t_3;
    __pyx_t_3 = nullptr;
  }
  __pyx_t_6 = __site_cvt_fwi_integer_t_531_9->Target(__site_cvt_fwi_integer_t_531_9, __pyx_t_4);
  __pyx_t_4 = nullptr;
  __pyx_v_n_ = __pyx_t_6;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":532
 *                             (0 if overwrite_x else np.NPY_ENSURECOPY))
 *     n_ = n if (n is not None) else np.PyArray_SIZE(x_)
 *     howmany = np.PyArray_SIZE(x_) // n_             # <<<<<<<<<<<<<<
 *     if not ((n_ > 0) and (n_ <= np.PyArray_SIZE(x_))):
 *         raise ValueError('Condition on arguments not satisfied: (n > 0) and (n <= x.size)')
 */
  __pyx_v_howmany = (PyArray_SIZE(__pyx_v_x_) / __pyx_v_n_);

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":533
 *     n_ = n if (n is not None) else np.PyArray_SIZE(x_)
 *     howmany = np.PyArray_SIZE(x_) // n_
 *     if not ((n_ > 0) and (n_ <= np.PyArray_SIZE(x_))):             # <<<<<<<<<<<<<<
 *         raise ValueError('Condition on arguments not satisfied: (n > 0) and (n <= x.size)')
 *     if not ((n_ * howmany) == np.PyArray_SIZE(x_)):
 */
  __pyx_t_5 = (__pyx_v_n_ > 0);
  if (__pyx_t_5) {
    __pyx_t_7 = (__pyx_v_n_ <= PyArray_SIZE(__pyx_v_x_));
    __pyx_t_8 = __pyx_t_7;
  } else {
    __pyx_t_8 = __pyx_t_5;
  }
  __pyx_t_5 = (!__pyx_t_8);
  if (__pyx_t_5) {

    /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":534
 *     howmany = np.PyArray_SIZE(x_) // n_
 *     if not ((n_ > 0) and (n_ <= np.PyArray_SIZE(x_))):
 *         raise ValueError('Condition on arguments not satisfied: (n > 0) and (n <= x.size)')             # <<<<<<<<<<<<<<
 *     if not ((n_ * howmany) == np.PyArray_SIZE(x_)):
 *         raise ValueError('Condition on arguments not satisfied: (n * howmany) == x.size')
 */
    __pyx_t_4 = PythonOps::GetGlobal(__pyx_context, "ValueError");
    __pyx_t_3 = __site_call1_534_24->Target(__site_call1_534_24, __pyx_context, __pyx_t_4, ((System::Object^)"Condition on arguments not satisfied: (n > 0) and (n <= x.size)"));
    __pyx_t_4 = nullptr;
    throw PythonOps::MakeException(__pyx_context, __pyx_t_3, nullptr, nullptr);
    __pyx_t_3 = nullptr;
    goto __pyx_L5;
  }
  __pyx_L5:;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":535
 *     if not ((n_ > 0) and (n_ <= np.PyArray_SIZE(x_))):
 *         raise ValueError('Condition on arguments not satisfied: (n > 0) and (n <= x.size)')
 *     if not ((n_ * howmany) == np.PyArray_SIZE(x_)):             # <<<<<<<<<<<<<<
 *         raise ValueError('Condition on arguments not satisfied: (n * howmany) == x.size')
 *     fc.ddct1(<fwr_real_x8_t*>np.PyArray_DATA(x_), n_, howmany, normalize)
 */
  __pyx_t_5 = (!((__pyx_v_n_ * __pyx_v_howmany) == PyArray_SIZE(__pyx_v_x_)));
  if (__pyx_t_5) {

    /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":536
 *         raise ValueError('Condition on arguments not satisfied: (n > 0) and (n <= x.size)')
 *     if not ((n_ * howmany) == np.PyArray_SIZE(x_)):
 *         raise ValueError('Condition on arguments not satisfied: (n * howmany) == x.size')             # <<<<<<<<<<<<<<
 *     fc.ddct1(<fwr_real_x8_t*>np.PyArray_DATA(x_), n_, howmany, normalize)
 *     return x_
 */
    __pyx_t_3 = PythonOps::GetGlobal(__pyx_context, "ValueError");
    __pyx_t_4 = __site_call1_536_24->Target(__site_call1_536_24, __pyx_context, __pyx_t_3, ((System::Object^)"Condition on arguments not satisfied: (n * howmany) == x.size"));
    __pyx_t_3 = nullptr;
    throw PythonOps::MakeException(__pyx_context, __pyx_t_4, nullptr, nullptr);
    __pyx_t_4 = nullptr;
    goto __pyx_L6;
  }
  __pyx_L6:;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":537
 *     if not ((n_ * howmany) == np.PyArray_SIZE(x_)):
 *         raise ValueError('Condition on arguments not satisfied: (n * howmany) == x.size')
 *     fc.ddct1(<fwr_real_x8_t*>np.PyArray_DATA(x_), n_, howmany, normalize)             # <<<<<<<<<<<<<<
 *     return x_
 * def ddct2(object x, object n=None, fwi_integer_t normalize=0, bint overwrite_x=False):
 */
  GLOBALFUNC(ddct1)(((fwr_real_x8_t *)PyArray_DATA(__pyx_v_x_)), __pyx_v_n_, __pyx_v_howmany, __pyx_v_normalize);

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":538
 *         raise ValueError('Condition on arguments not satisfied: (n * howmany) == x.size')
 *     fc.ddct1(<fwr_real_x8_t*>np.PyArray_DATA(x_), n_, howmany, normalize)
 *     return x_             # <<<<<<<<<<<<<<
 * def ddct2(object x, object n=None, fwi_integer_t normalize=0, bint overwrite_x=False):
 *     """ddct2(x[, n, normalize, overwrite_x]) -> x
 */
  __pyx_r = ((System::Object^)__pyx_v_x_);
  goto __pyx_L0;

  __pyx_r = nullptr;
  __pyx_L0:;
  return __pyx_r;
}

/* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":539
 *     fc.ddct1(<fwr_real_x8_t*>np.PyArray_DATA(x_), n_, howmany, normalize)
 *     return x_
 * def ddct2(object x, object n=None, fwi_integer_t normalize=0, bint overwrite_x=False):             # <<<<<<<<<<<<<<
 *     """ddct2(x[, n, normalize, overwrite_x]) -> x
 * 
 */

static System::Object^ ddct2(System::Object^ x, [InteropServices::Optional]System::Object^ n, [InteropServices::Optional]System::Object^ normalize, [InteropServices::Optional]System::Object^ overwrite_x) {
  System::Object^ __pyx_v_x = nullptr;
  System::Object^ __pyx_v_n = nullptr;
  fwi_integer_t __pyx_v_normalize;
  int __pyx_v_overwrite_x;
  NumpyDotNet::ndarray^ __pyx_v_x_;
  fwi_integer_t __pyx_v_n_;
  fwi_integer_t __pyx_v_howmany;
  System::Object^ __pyx_r = nullptr;
  System::Object^ __pyx_t_1 = nullptr;
  long __pyx_t_2;
  System::Object^ __pyx_t_3 = nullptr;
  System::Object^ __pyx_t_4 = nullptr;
  int __pyx_t_5;
  fwi_integer_t __pyx_t_6;
  int __pyx_t_7;
  int __pyx_t_8;
  __pyx_v_x = x;
  if (dynamic_cast<System::Reflection::Missing^>(n) == nullptr) {
    __pyx_v_n = n;
  } else {
    __pyx_v_n = ((System::Object^)nullptr);
  }
  if (dynamic_cast<System::Reflection::Missing^>(normalize) == nullptr) {
    __pyx_v_normalize = __site_cvt_539_0->Target(__site_cvt_539_0, normalize);
  } else {
    __pyx_v_normalize = ((fwi_integer_t)0);
  }
  if (dynamic_cast<System::Reflection::Missing^>(overwrite_x) == nullptr) {
    __pyx_v_overwrite_x = __site_cvt_539_0_1->Target(__site_cvt_539_0_1, overwrite_x);
  } else {
    __pyx_v_overwrite_x = ((int)0);
  }
  __pyx_v_x_ = nullptr;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":557
 *     cdef fwi_integer_t n_
 *     cdef fwi_integer_t howmany
 *     x_ = np.PyArray_FROMANY(x, fwr_real_x8_t_enum, 0, 0,             # <<<<<<<<<<<<<<
 *                             np.NPY_C_CONTIGUOUS | np.NPY_FORCECAST |
 *                             (0 if overwrite_x else np.NPY_ENSURECOPY))
 */
  __pyx_t_1 = (System::Object^)(long long)(NPY_FLOAT64);

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":559
 *     x_ = np.PyArray_FROMANY(x, fwr_real_x8_t_enum, 0, 0,
 *                             np.NPY_C_CONTIGUOUS | np.NPY_FORCECAST |
 *                             (0 if overwrite_x else np.NPY_ENSURECOPY))             # <<<<<<<<<<<<<<
 *     n_ = n if (n is not None) else np.PyArray_SIZE(x_)
 *     howmany = np.PyArray_SIZE(x_) // n_
 */
  if (__pyx_v_overwrite_x) {
    __pyx_t_2 = 0;
  } else {
    __pyx_t_2 = NPY_ENSURECOPY;
  }
  __pyx_t_3 = ((NPY_C_CONTIGUOUS | NPY_FORCECAST) | __pyx_t_2);
  __pyx_t_4 = PyArray_FROMANY(__pyx_v_x, __pyx_t_1, __pyx_int_0, __pyx_int_0, __pyx_t_3); 
  __pyx_t_1 = nullptr;
  __pyx_t_3 = nullptr;
  if (__pyx_t_4 == nullptr || dynamic_cast<NumpyDotNet::ndarray^>(__pyx_t_4) == nullptr) {
    throw PythonOps::MakeException(__pyx_context, PythonOps::GetGlobal(__pyx_context, "TypeError"), "type error", nullptr);
  }
  __pyx_v_x_ = ((NumpyDotNet::ndarray^)__pyx_t_4);
  __pyx_t_4 = nullptr;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":560
 *                             np.NPY_C_CONTIGUOUS | np.NPY_FORCECAST |
 *                             (0 if overwrite_x else np.NPY_ENSURECOPY))
 *     n_ = n if (n is not None) else np.PyArray_SIZE(x_)             # <<<<<<<<<<<<<<
 *     howmany = np.PyArray_SIZE(x_) // n_
 *     if not ((n_ > 0) and (n_ <= np.PyArray_SIZE(x_))):
 */
  __pyx_t_5 = (__pyx_v_n != nullptr);
  if (__pyx_t_5) {
    __pyx_t_4 = __pyx_v_n;
  } else {
    __pyx_t_3 = PyArray_SIZE(__pyx_v_x_);
    __pyx_t_4 = __pyx_t_3;
    __pyx_t_3 = nullptr;
  }
  __pyx_t_6 = __site_cvt_fwi_integer_t_560_9->Target(__site_cvt_fwi_integer_t_560_9, __pyx_t_4);
  __pyx_t_4 = nullptr;
  __pyx_v_n_ = __pyx_t_6;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":561
 *                             (0 if overwrite_x else np.NPY_ENSURECOPY))
 *     n_ = n if (n is not None) else np.PyArray_SIZE(x_)
 *     howmany = np.PyArray_SIZE(x_) // n_             # <<<<<<<<<<<<<<
 *     if not ((n_ > 0) and (n_ <= np.PyArray_SIZE(x_))):
 *         raise ValueError('Condition on arguments not satisfied: (n > 0) and (n <= x.size)')
 */
  __pyx_v_howmany = (PyArray_SIZE(__pyx_v_x_) / __pyx_v_n_);

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":562
 *     n_ = n if (n is not None) else np.PyArray_SIZE(x_)
 *     howmany = np.PyArray_SIZE(x_) // n_
 *     if not ((n_ > 0) and (n_ <= np.PyArray_SIZE(x_))):             # <<<<<<<<<<<<<<
 *         raise ValueError('Condition on arguments not satisfied: (n > 0) and (n <= x.size)')
 *     if not ((n_ * howmany) == np.PyArray_SIZE(x_)):
 */
  __pyx_t_5 = (__pyx_v_n_ > 0);
  if (__pyx_t_5) {
    __pyx_t_7 = (__pyx_v_n_ <= PyArray_SIZE(__pyx_v_x_));
    __pyx_t_8 = __pyx_t_7;
  } else {
    __pyx_t_8 = __pyx_t_5;
  }
  __pyx_t_5 = (!__pyx_t_8);
  if (__pyx_t_5) {

    /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":563
 *     howmany = np.PyArray_SIZE(x_) // n_
 *     if not ((n_ > 0) and (n_ <= np.PyArray_SIZE(x_))):
 *         raise ValueError('Condition on arguments not satisfied: (n > 0) and (n <= x.size)')             # <<<<<<<<<<<<<<
 *     if not ((n_ * howmany) == np.PyArray_SIZE(x_)):
 *         raise ValueError('Condition on arguments not satisfied: (n * howmany) == x.size')
 */
    __pyx_t_4 = PythonOps::GetGlobal(__pyx_context, "ValueError");
    __pyx_t_3 = __site_call1_563_24->Target(__site_call1_563_24, __pyx_context, __pyx_t_4, ((System::Object^)"Condition on arguments not satisfied: (n > 0) and (n <= x.size)"));
    __pyx_t_4 = nullptr;
    throw PythonOps::MakeException(__pyx_context, __pyx_t_3, nullptr, nullptr);
    __pyx_t_3 = nullptr;
    goto __pyx_L5;
  }
  __pyx_L5:;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":564
 *     if not ((n_ > 0) and (n_ <= np.PyArray_SIZE(x_))):
 *         raise ValueError('Condition on arguments not satisfied: (n > 0) and (n <= x.size)')
 *     if not ((n_ * howmany) == np.PyArray_SIZE(x_)):             # <<<<<<<<<<<<<<
 *         raise ValueError('Condition on arguments not satisfied: (n * howmany) == x.size')
 *     fc.ddct2(<fwr_real_x8_t*>np.PyArray_DATA(x_), n_, howmany, normalize)
 */
  __pyx_t_5 = (!((__pyx_v_n_ * __pyx_v_howmany) == PyArray_SIZE(__pyx_v_x_)));
  if (__pyx_t_5) {

    /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":565
 *         raise ValueError('Condition on arguments not satisfied: (n > 0) and (n <= x.size)')
 *     if not ((n_ * howmany) == np.PyArray_SIZE(x_)):
 *         raise ValueError('Condition on arguments not satisfied: (n * howmany) == x.size')             # <<<<<<<<<<<<<<
 *     fc.ddct2(<fwr_real_x8_t*>np.PyArray_DATA(x_), n_, howmany, normalize)
 *     return x_
 */
    __pyx_t_3 = PythonOps::GetGlobal(__pyx_context, "ValueError");
    __pyx_t_4 = __site_call1_565_24->Target(__site_call1_565_24, __pyx_context, __pyx_t_3, ((System::Object^)"Condition on arguments not satisfied: (n * howmany) == x.size"));
    __pyx_t_3 = nullptr;
    throw PythonOps::MakeException(__pyx_context, __pyx_t_4, nullptr, nullptr);
    __pyx_t_4 = nullptr;
    goto __pyx_L6;
  }
  __pyx_L6:;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":566
 *     if not ((n_ * howmany) == np.PyArray_SIZE(x_)):
 *         raise ValueError('Condition on arguments not satisfied: (n * howmany) == x.size')
 *     fc.ddct2(<fwr_real_x8_t*>np.PyArray_DATA(x_), n_, howmany, normalize)             # <<<<<<<<<<<<<<
 *     return x_
 * def ddct3(object x, object n=None, fwi_integer_t normalize=0, bint overwrite_x=False):
 */
  GLOBALFUNC(ddct2)(((fwr_real_x8_t *)PyArray_DATA(__pyx_v_x_)), __pyx_v_n_, __pyx_v_howmany, __pyx_v_normalize);

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":567
 *         raise ValueError('Condition on arguments not satisfied: (n * howmany) == x.size')
 *     fc.ddct2(<fwr_real_x8_t*>np.PyArray_DATA(x_), n_, howmany, normalize)
 *     return x_             # <<<<<<<<<<<<<<
 * def ddct3(object x, object n=None, fwi_integer_t normalize=0, bint overwrite_x=False):
 *     """ddct3(x[, n, normalize, overwrite_x]) -> x
 */
  __pyx_r = ((System::Object^)__pyx_v_x_);
  goto __pyx_L0;

  __pyx_r = nullptr;
  __pyx_L0:;
  return __pyx_r;
}

/* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":568
 *     fc.ddct2(<fwr_real_x8_t*>np.PyArray_DATA(x_), n_, howmany, normalize)
 *     return x_
 * def ddct3(object x, object n=None, fwi_integer_t normalize=0, bint overwrite_x=False):             # <<<<<<<<<<<<<<
 *     """ddct3(x[, n, normalize, overwrite_x]) -> x
 * 
 */

static System::Object^ ddct3(System::Object^ x, [InteropServices::Optional]System::Object^ n, [InteropServices::Optional]System::Object^ normalize, [InteropServices::Optional]System::Object^ overwrite_x) {
  System::Object^ __pyx_v_x = nullptr;
  System::Object^ __pyx_v_n = nullptr;
  fwi_integer_t __pyx_v_normalize;
  int __pyx_v_overwrite_x;
  NumpyDotNet::ndarray^ __pyx_v_x_;
  fwi_integer_t __pyx_v_n_;
  fwi_integer_t __pyx_v_howmany;
  System::Object^ __pyx_r = nullptr;
  System::Object^ __pyx_t_1 = nullptr;
  long __pyx_t_2;
  System::Object^ __pyx_t_3 = nullptr;
  System::Object^ __pyx_t_4 = nullptr;
  int __pyx_t_5;
  fwi_integer_t __pyx_t_6;
  int __pyx_t_7;
  int __pyx_t_8;
  __pyx_v_x = x;
  if (dynamic_cast<System::Reflection::Missing^>(n) == nullptr) {
    __pyx_v_n = n;
  } else {
    __pyx_v_n = ((System::Object^)nullptr);
  }
  if (dynamic_cast<System::Reflection::Missing^>(normalize) == nullptr) {
    __pyx_v_normalize = __site_cvt_568_0->Target(__site_cvt_568_0, normalize);
  } else {
    __pyx_v_normalize = ((fwi_integer_t)0);
  }
  if (dynamic_cast<System::Reflection::Missing^>(overwrite_x) == nullptr) {
    __pyx_v_overwrite_x = __site_cvt_568_0_1->Target(__site_cvt_568_0_1, overwrite_x);
  } else {
    __pyx_v_overwrite_x = ((int)0);
  }
  __pyx_v_x_ = nullptr;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":586
 *     cdef fwi_integer_t n_
 *     cdef fwi_integer_t howmany
 *     x_ = np.PyArray_FROMANY(x, fwr_real_x8_t_enum, 0, 0,             # <<<<<<<<<<<<<<
 *                             np.NPY_C_CONTIGUOUS | np.NPY_FORCECAST |
 *                             (0 if overwrite_x else np.NPY_ENSURECOPY))
 */
  __pyx_t_1 = (System::Object^)(long long)(NPY_FLOAT64);

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":588
 *     x_ = np.PyArray_FROMANY(x, fwr_real_x8_t_enum, 0, 0,
 *                             np.NPY_C_CONTIGUOUS | np.NPY_FORCECAST |
 *                             (0 if overwrite_x else np.NPY_ENSURECOPY))             # <<<<<<<<<<<<<<
 *     n_ = n if (n is not None) else np.PyArray_SIZE(x_)
 *     howmany = np.PyArray_SIZE(x_) // n_
 */
  if (__pyx_v_overwrite_x) {
    __pyx_t_2 = 0;
  } else {
    __pyx_t_2 = NPY_ENSURECOPY;
  }
  __pyx_t_3 = ((NPY_C_CONTIGUOUS | NPY_FORCECAST) | __pyx_t_2);
  __pyx_t_4 = PyArray_FROMANY(__pyx_v_x, __pyx_t_1, __pyx_int_0, __pyx_int_0, __pyx_t_3); 
  __pyx_t_1 = nullptr;
  __pyx_t_3 = nullptr;
  if (__pyx_t_4 == nullptr || dynamic_cast<NumpyDotNet::ndarray^>(__pyx_t_4) == nullptr) {
    throw PythonOps::MakeException(__pyx_context, PythonOps::GetGlobal(__pyx_context, "TypeError"), "type error", nullptr);
  }
  __pyx_v_x_ = ((NumpyDotNet::ndarray^)__pyx_t_4);
  __pyx_t_4 = nullptr;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":589
 *                             np.NPY_C_CONTIGUOUS | np.NPY_FORCECAST |
 *                             (0 if overwrite_x else np.NPY_ENSURECOPY))
 *     n_ = n if (n is not None) else np.PyArray_SIZE(x_)             # <<<<<<<<<<<<<<
 *     howmany = np.PyArray_SIZE(x_) // n_
 *     if not ((n_ > 0) and (n_ <= np.PyArray_SIZE(x_))):
 */
  __pyx_t_5 = (__pyx_v_n != nullptr);
  if (__pyx_t_5) {
    __pyx_t_4 = __pyx_v_n;
  } else {
    __pyx_t_3 = PyArray_SIZE(__pyx_v_x_);
    __pyx_t_4 = __pyx_t_3;
    __pyx_t_3 = nullptr;
  }
  __pyx_t_6 = __site_cvt_fwi_integer_t_589_9->Target(__site_cvt_fwi_integer_t_589_9, __pyx_t_4);
  __pyx_t_4 = nullptr;
  __pyx_v_n_ = __pyx_t_6;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":590
 *                             (0 if overwrite_x else np.NPY_ENSURECOPY))
 *     n_ = n if (n is not None) else np.PyArray_SIZE(x_)
 *     howmany = np.PyArray_SIZE(x_) // n_             # <<<<<<<<<<<<<<
 *     if not ((n_ > 0) and (n_ <= np.PyArray_SIZE(x_))):
 *         raise ValueError('Condition on arguments not satisfied: (n > 0) and (n <= x.size)')
 */
  __pyx_v_howmany = (PyArray_SIZE(__pyx_v_x_) / __pyx_v_n_);

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":591
 *     n_ = n if (n is not None) else np.PyArray_SIZE(x_)
 *     howmany = np.PyArray_SIZE(x_) // n_
 *     if not ((n_ > 0) and (n_ <= np.PyArray_SIZE(x_))):             # <<<<<<<<<<<<<<
 *         raise ValueError('Condition on arguments not satisfied: (n > 0) and (n <= x.size)')
 *     if not ((n_ * howmany) == np.PyArray_SIZE(x_)):
 */
  __pyx_t_5 = (__pyx_v_n_ > 0);
  if (__pyx_t_5) {
    __pyx_t_7 = (__pyx_v_n_ <= PyArray_SIZE(__pyx_v_x_));
    __pyx_t_8 = __pyx_t_7;
  } else {
    __pyx_t_8 = __pyx_t_5;
  }
  __pyx_t_5 = (!__pyx_t_8);
  if (__pyx_t_5) {

    /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":592
 *     howmany = np.PyArray_SIZE(x_) // n_
 *     if not ((n_ > 0) and (n_ <= np.PyArray_SIZE(x_))):
 *         raise ValueError('Condition on arguments not satisfied: (n > 0) and (n <= x.size)')             # <<<<<<<<<<<<<<
 *     if not ((n_ * howmany) == np.PyArray_SIZE(x_)):
 *         raise ValueError('Condition on arguments not satisfied: (n * howmany) == x.size')
 */
    __pyx_t_4 = PythonOps::GetGlobal(__pyx_context, "ValueError");
    __pyx_t_3 = __site_call1_592_24->Target(__site_call1_592_24, __pyx_context, __pyx_t_4, ((System::Object^)"Condition on arguments not satisfied: (n > 0) and (n <= x.size)"));
    __pyx_t_4 = nullptr;
    throw PythonOps::MakeException(__pyx_context, __pyx_t_3, nullptr, nullptr);
    __pyx_t_3 = nullptr;
    goto __pyx_L5;
  }
  __pyx_L5:;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":593
 *     if not ((n_ > 0) and (n_ <= np.PyArray_SIZE(x_))):
 *         raise ValueError('Condition on arguments not satisfied: (n > 0) and (n <= x.size)')
 *     if not ((n_ * howmany) == np.PyArray_SIZE(x_)):             # <<<<<<<<<<<<<<
 *         raise ValueError('Condition on arguments not satisfied: (n * howmany) == x.size')
 *     fc.ddct3(<fwr_real_x8_t*>np.PyArray_DATA(x_), n_, howmany, normalize)
 */
  __pyx_t_5 = (!((__pyx_v_n_ * __pyx_v_howmany) == PyArray_SIZE(__pyx_v_x_)));
  if (__pyx_t_5) {

    /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":594
 *         raise ValueError('Condition on arguments not satisfied: (n > 0) and (n <= x.size)')
 *     if not ((n_ * howmany) == np.PyArray_SIZE(x_)):
 *         raise ValueError('Condition on arguments not satisfied: (n * howmany) == x.size')             # <<<<<<<<<<<<<<
 *     fc.ddct3(<fwr_real_x8_t*>np.PyArray_DATA(x_), n_, howmany, normalize)
 *     return x_
 */
    __pyx_t_3 = PythonOps::GetGlobal(__pyx_context, "ValueError");
    __pyx_t_4 = __site_call1_594_24->Target(__site_call1_594_24, __pyx_context, __pyx_t_3, ((System::Object^)"Condition on arguments not satisfied: (n * howmany) == x.size"));
    __pyx_t_3 = nullptr;
    throw PythonOps::MakeException(__pyx_context, __pyx_t_4, nullptr, nullptr);
    __pyx_t_4 = nullptr;
    goto __pyx_L6;
  }
  __pyx_L6:;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":595
 *     if not ((n_ * howmany) == np.PyArray_SIZE(x_)):
 *         raise ValueError('Condition on arguments not satisfied: (n * howmany) == x.size')
 *     fc.ddct3(<fwr_real_x8_t*>np.PyArray_DATA(x_), n_, howmany, normalize)             # <<<<<<<<<<<<<<
 *     return x_
 * 
 */
  GLOBALFUNC(ddct3)(((fwr_real_x8_t *)PyArray_DATA(__pyx_v_x_)), __pyx_v_n_, __pyx_v_howmany, __pyx_v_normalize);

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":596
 *         raise ValueError('Condition on arguments not satisfied: (n * howmany) == x.size')
 *     fc.ddct3(<fwr_real_x8_t*>np.PyArray_DATA(x_), n_, howmany, normalize)
 *     return x_             # <<<<<<<<<<<<<<
 * 
 * 
 */
  __pyx_r = ((System::Object^)__pyx_v_x_);
  goto __pyx_L0;

  __pyx_r = nullptr;
  __pyx_L0:;
  return __pyx_r;
}

/* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\numpy.pxd":190
 *     object Npy_INTERFACE_array "Npy_INTERFACE_OBJECT" (NpyArray*)
 * 
 * cdef inline object PyUFunc_FromFuncAndData(PyUFuncGenericFunction* func, void** data,             # <<<<<<<<<<<<<<
 *         char* types, int ntypes, int nin, int nout,
 *         int identity, char* name, char* doc, int c):
 */

static CYTHON_INLINE System::Object^ PyUFunc_FromFuncAndData(__pyx_t_5scipy_7fftpack_5numpy_PyUFuncGenericFunction *__pyx_v_func, void **__pyx_v_data, char *__pyx_v_types, int __pyx_v_ntypes, int __pyx_v_nin, int __pyx_v_nout, int __pyx_v_identity, char *__pyx_v_name, char *__pyx_v_doc, int __pyx_v_c) {
  System::Object^ __pyx_r = nullptr;
  System::Object^ __pyx_t_1 = nullptr;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\numpy.pxd":193
 *         char* types, int ntypes, int nin, int nout,
 *         int identity, char* name, char* doc, int c):
 *    return Npy_INTERFACE_ufunc(NpyUFunc_FromFuncAndDataAndSignature(func, data, types, ntypes, nin, nout, identity, name, doc, c, NULL))             # <<<<<<<<<<<<<<
 * 
 * cdef inline object PyArray_ZEROS(int ndim, intp_t *shape, int typenum, int fortran):
 */
  __pyx_t_1 = Npy_INTERFACE_OBJECT(NpyUFunc_FromFuncAndDataAndSignature(__pyx_v_func, __pyx_v_data, __pyx_v_types, __pyx_v_ntypes, __pyx_v_nin, __pyx_v_nout, __pyx_v_identity, __pyx_v_name, __pyx_v_doc, __pyx_v_c, NULL)); 
  __pyx_r = __pyx_t_1;
  __pyx_t_1 = nullptr;
  goto __pyx_L0;

  __pyx_r = nullptr;
  __pyx_L0:;
  return __pyx_r;
}

/* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\numpy.pxd":195
 *    return Npy_INTERFACE_ufunc(NpyUFunc_FromFuncAndDataAndSignature(func, data, types, ntypes, nin, nout, identity, name, doc, c, NULL))
 * 
 * cdef inline object PyArray_ZEROS(int ndim, intp_t *shape, int typenum, int fortran):             # <<<<<<<<<<<<<<
 *     shape_list = []
 *     cdef int i
 */

static CYTHON_INLINE System::Object^ PyArray_ZEROS(int __pyx_v_ndim, __pyx_t_5scipy_7fftpack_5numpy_intp_t *__pyx_v_shape, int __pyx_v_typenum, int __pyx_v_fortran) {
  System::Object^ __pyx_v_shape_list;
  int __pyx_v_i;
  System::Object^ __pyx_v_numpy;
  System::Object^ __pyx_r = nullptr;
  System::Object^ __pyx_t_1 = nullptr;
  int __pyx_t_2;
  int __pyx_t_3;
  System::Object^ __pyx_t_4 = nullptr;
  System::Object^ __pyx_t_5 = nullptr;
  System::Object^ __pyx_t_6 = nullptr;
  __pyx_v_shape_list = nullptr;
  __pyx_v_numpy = nullptr;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\numpy.pxd":196
 * 
 * cdef inline object PyArray_ZEROS(int ndim, intp_t *shape, int typenum, int fortran):
 *     shape_list = []             # <<<<<<<<<<<<<<
 *     cdef int i
 *     for i in range(ndim):
 */
  __pyx_t_1 = PythonOps::MakeListNoCopy(gcnew array<System::Object^>{});
  __pyx_v_shape_list = __pyx_t_1;
  __pyx_t_1 = nullptr;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\numpy.pxd":198
 *     shape_list = []
 *     cdef int i
 *     for i in range(ndim):             # <<<<<<<<<<<<<<
 *         shape_list.append(shape[i])
 *     import numpy
 */
  __pyx_t_2 = __pyx_v_ndim;
  for (__pyx_t_3 = 0; __pyx_t_3 < __pyx_t_2; __pyx_t_3+=1) {
    __pyx_v_i = __pyx_t_3;

    /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\numpy.pxd":199
 *     cdef int i
 *     for i in range(ndim):
 *         shape_list.append(shape[i])             # <<<<<<<<<<<<<<
 *     import numpy
 *     return numpy.zeros(shape_list, Npy_INTERFACE_descr(NpyArray_DescrFromType(typenum)), 'F' if fortran else 'C')
 */
    __pyx_t_1 = __site_get_append_199_18->Target(__site_get_append_199_18, ((System::Object^)__pyx_v_shape_list), __pyx_context);
    __pyx_t_4 = (__pyx_v_shape[__pyx_v_i]);
    __pyx_t_5 = __site_call1_199_25->Target(__site_call1_199_25, __pyx_context, __pyx_t_1, __pyx_t_4);
    __pyx_t_1 = nullptr;
    __pyx_t_4 = nullptr;
    __pyx_t_5 = nullptr;
  }

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\numpy.pxd":200
 *     for i in range(ndim):
 *         shape_list.append(shape[i])
 *     import numpy             # <<<<<<<<<<<<<<
 *     return numpy.zeros(shape_list, Npy_INTERFACE_descr(NpyArray_DescrFromType(typenum)), 'F' if fortran else 'C')
 * 
 */
  __pyx_t_5 = LightExceptions::CheckAndThrow(PythonOps::ImportTop(__pyx_context, "numpy", -1));
  __pyx_v_numpy = __pyx_t_5;
  __pyx_t_5 = nullptr;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\numpy.pxd":201
 *         shape_list.append(shape[i])
 *     import numpy
 *     return numpy.zeros(shape_list, Npy_INTERFACE_descr(NpyArray_DescrFromType(typenum)), 'F' if fortran else 'C')             # <<<<<<<<<<<<<<
 * 
 * cdef inline object PyArray_EMPTY(int ndim, intp_t *shape, int typenum, int fortran):
 */
  __pyx_t_5 = __site_get_zeros_201_16->Target(__site_get_zeros_201_16, __pyx_v_numpy, __pyx_context);
  __pyx_t_4 = Npy_INTERFACE_OBJECT(NpyArray_DescrFromType(__pyx_v_typenum)); 
  if (__pyx_v_fortran) {
    __pyx_t_1 = "F";
  } else {
    __pyx_t_1 = "C";
  }
  __pyx_t_6 = __site_call3_201_22->Target(__site_call3_201_22, __pyx_context, __pyx_t_5, ((System::Object^)__pyx_v_shape_list), __pyx_t_4, ((System::Object^)__pyx_t_1));
  __pyx_t_5 = nullptr;
  __pyx_t_4 = nullptr;
  __pyx_t_1 = nullptr;
  __pyx_r = __pyx_t_6;
  __pyx_t_6 = nullptr;
  goto __pyx_L0;

  __pyx_r = nullptr;
  __pyx_L0:;
  return __pyx_r;
}

/* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\numpy.pxd":203
 *     return numpy.zeros(shape_list, Npy_INTERFACE_descr(NpyArray_DescrFromType(typenum)), 'F' if fortran else 'C')
 * 
 * cdef inline object PyArray_EMPTY(int ndim, intp_t *shape, int typenum, int fortran):             # <<<<<<<<<<<<<<
 *     shape_list = []
 *     cdef int i
 */

static CYTHON_INLINE System::Object^ PyArray_EMPTY(int __pyx_v_ndim, __pyx_t_5scipy_7fftpack_5numpy_intp_t *__pyx_v_shape, int __pyx_v_typenum, int __pyx_v_fortran) {
  System::Object^ __pyx_v_shape_list;
  int __pyx_v_i;
  System::Object^ __pyx_v_numpy;
  System::Object^ __pyx_r = nullptr;
  System::Object^ __pyx_t_1 = nullptr;
  int __pyx_t_2;
  int __pyx_t_3;
  System::Object^ __pyx_t_4 = nullptr;
  System::Object^ __pyx_t_5 = nullptr;
  System::Object^ __pyx_t_6 = nullptr;
  __pyx_v_shape_list = nullptr;
  __pyx_v_numpy = nullptr;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\numpy.pxd":204
 * 
 * cdef inline object PyArray_EMPTY(int ndim, intp_t *shape, int typenum, int fortran):
 *     shape_list = []             # <<<<<<<<<<<<<<
 *     cdef int i
 *     for i in range(ndim):
 */
  __pyx_t_1 = PythonOps::MakeListNoCopy(gcnew array<System::Object^>{});
  __pyx_v_shape_list = __pyx_t_1;
  __pyx_t_1 = nullptr;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\numpy.pxd":206
 *     shape_list = []
 *     cdef int i
 *     for i in range(ndim):             # <<<<<<<<<<<<<<
 *         shape_list.append(shape[i])
 *     import numpy
 */
  __pyx_t_2 = __pyx_v_ndim;
  for (__pyx_t_3 = 0; __pyx_t_3 < __pyx_t_2; __pyx_t_3+=1) {
    __pyx_v_i = __pyx_t_3;

    /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\numpy.pxd":207
 *     cdef int i
 *     for i in range(ndim):
 *         shape_list.append(shape[i])             # <<<<<<<<<<<<<<
 *     import numpy
 *     return numpy.empty(shape_list, Npy_INTERFACE_descr(NpyArray_DescrFromType(typenum)), 'F' if fortran else 'C')
 */
    __pyx_t_1 = __site_get_append_207_18->Target(__site_get_append_207_18, ((System::Object^)__pyx_v_shape_list), __pyx_context);
    __pyx_t_4 = (__pyx_v_shape[__pyx_v_i]);
    __pyx_t_5 = __site_call1_207_25->Target(__site_call1_207_25, __pyx_context, __pyx_t_1, __pyx_t_4);
    __pyx_t_1 = nullptr;
    __pyx_t_4 = nullptr;
    __pyx_t_5 = nullptr;
  }

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\numpy.pxd":208
 *     for i in range(ndim):
 *         shape_list.append(shape[i])
 *     import numpy             # <<<<<<<<<<<<<<
 *     return numpy.empty(shape_list, Npy_INTERFACE_descr(NpyArray_DescrFromType(typenum)), 'F' if fortran else 'C')
 * 
 */
  __pyx_t_5 = LightExceptions::CheckAndThrow(PythonOps::ImportTop(__pyx_context, "numpy", -1));
  __pyx_v_numpy = __pyx_t_5;
  __pyx_t_5 = nullptr;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\numpy.pxd":209
 *         shape_list.append(shape[i])
 *     import numpy
 *     return numpy.empty(shape_list, Npy_INTERFACE_descr(NpyArray_DescrFromType(typenum)), 'F' if fortran else 'C')             # <<<<<<<<<<<<<<
 * 
 * cdef inline object PyArray_New(void *subtype, int nd, npy_intp *dims, int type_num, npy_intp *strides, void *data, int itemsize, int flags, void *obj):
 */
  __pyx_t_5 = __site_get_empty_209_16->Target(__site_get_empty_209_16, __pyx_v_numpy, __pyx_context);
  __pyx_t_4 = Npy_INTERFACE_OBJECT(NpyArray_DescrFromType(__pyx_v_typenum)); 
  if (__pyx_v_fortran) {
    __pyx_t_1 = "F";
  } else {
    __pyx_t_1 = "C";
  }
  __pyx_t_6 = __site_call3_209_22->Target(__site_call3_209_22, __pyx_context, __pyx_t_5, ((System::Object^)__pyx_v_shape_list), __pyx_t_4, ((System::Object^)__pyx_t_1));
  __pyx_t_5 = nullptr;
  __pyx_t_4 = nullptr;
  __pyx_t_1 = nullptr;
  __pyx_r = __pyx_t_6;
  __pyx_t_6 = nullptr;
  goto __pyx_L0;

  __pyx_r = nullptr;
  __pyx_L0:;
  return __pyx_r;
}

/* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\numpy.pxd":211
 *     return numpy.empty(shape_list, Npy_INTERFACE_descr(NpyArray_DescrFromType(typenum)), 'F' if fortran else 'C')
 * 
 * cdef inline object PyArray_New(void *subtype, int nd, npy_intp *dims, int type_num, npy_intp *strides, void *data, int itemsize, int flags, void *obj):             # <<<<<<<<<<<<<<
 *     assert subtype == NULL
 *     assert obj == NULL
 */

static CYTHON_INLINE System::Object^ PyArray_New(void *__pyx_v_subtype, int __pyx_v_nd, __pyx_t_5scipy_7fftpack_5numpy_npy_intp *__pyx_v_dims, int __pyx_v_type_num, __pyx_t_5scipy_7fftpack_5numpy_npy_intp *__pyx_v_strides, void *__pyx_v_data, int __pyx_v_itemsize, int __pyx_v_flags, void *__pyx_v_obj) {
  System::Object^ __pyx_r = nullptr;
  System::Object^ __pyx_t_1 = nullptr;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\numpy.pxd":212
 * 
 * cdef inline object PyArray_New(void *subtype, int nd, npy_intp *dims, int type_num, npy_intp *strides, void *data, int itemsize, int flags, void *obj):
 *     assert subtype == NULL             # <<<<<<<<<<<<<<
 *     assert obj == NULL
 *     return Npy_INTERFACE_array(NpyArray_New(subtype, nd, dims, type_num, strides, data, itemsize, flags, obj))
 */
  #ifndef PYREX_WITHOUT_ASSERTIONS
  if (unlikely(!(__pyx_v_subtype == NULL))) {
    PythonOps::RaiseAssertionError(nullptr);
  }
  #endif

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\numpy.pxd":213
 * cdef inline object PyArray_New(void *subtype, int nd, npy_intp *dims, int type_num, npy_intp *strides, void *data, int itemsize, int flags, void *obj):
 *     assert subtype == NULL
 *     assert obj == NULL             # <<<<<<<<<<<<<<
 *     return Npy_INTERFACE_array(NpyArray_New(subtype, nd, dims, type_num, strides, data, itemsize, flags, obj))
 * 
 */
  #ifndef PYREX_WITHOUT_ASSERTIONS
  if (unlikely(!(__pyx_v_obj == NULL))) {
    PythonOps::RaiseAssertionError(nullptr);
  }
  #endif

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\numpy.pxd":214
 *     assert subtype == NULL
 *     assert obj == NULL
 *     return Npy_INTERFACE_array(NpyArray_New(subtype, nd, dims, type_num, strides, data, itemsize, flags, obj))             # <<<<<<<<<<<<<<
 * 
 * cdef inline bint PyArray_CHKFLAGS(ndarray n, int flags):
 */
  __pyx_t_1 = Npy_INTERFACE_OBJECT(NpyArray_New(__pyx_v_subtype, __pyx_v_nd, __pyx_v_dims, __pyx_v_type_num, __pyx_v_strides, __pyx_v_data, __pyx_v_itemsize, __pyx_v_flags, __pyx_v_obj)); 
  __pyx_r = __pyx_t_1;
  __pyx_t_1 = nullptr;
  goto __pyx_L0;

  __pyx_r = nullptr;
  __pyx_L0:;
  return __pyx_r;
}

/* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\numpy.pxd":216
 *     return Npy_INTERFACE_array(NpyArray_New(subtype, nd, dims, type_num, strides, data, itemsize, flags, obj))
 * 
 * cdef inline bint PyArray_CHKFLAGS(ndarray n, int flags):             # <<<<<<<<<<<<<<
 *      # XXX "long long" is wrong type
 *     return  NpyArray_CHKFLAGS(<NpyArray*> <long long>n.Array, flags)
 */

static CYTHON_INLINE int PyArray_CHKFLAGS(NumpyDotNet::ndarray^ __pyx_v_n, int __pyx_v_flags) {
  int __pyx_r;
  System::Object^ __pyx_t_1 = nullptr;
  PY_LONG_LONG __pyx_t_2;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\numpy.pxd":218
 * cdef inline bint PyArray_CHKFLAGS(ndarray n, int flags):
 *      # XXX "long long" is wrong type
 *     return  NpyArray_CHKFLAGS(<NpyArray*> <long long>n.Array, flags)             # <<<<<<<<<<<<<<
 * 
 * cdef inline void* PyArray_DATA(ndarray n):
 */
  __pyx_t_1 = __site_get_Array_218_54->Target(__site_get_Array_218_54, ((System::Object^)__pyx_v_n), __pyx_context);
  __pyx_t_2 = __site_cvt_PY_LONG_LONG_218_54->Target(__site_cvt_PY_LONG_LONG_218_54, __pyx_t_1);
  __pyx_t_1 = nullptr;
  __pyx_r = NpyArray_CHKFLAGS(((NpyArray *)((PY_LONG_LONG)__pyx_t_2)), __pyx_v_flags);
  goto __pyx_L0;

  __pyx_r = 0;
  __pyx_L0:;
  return __pyx_r;
}

/* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\numpy.pxd":220
 *     return  NpyArray_CHKFLAGS(<NpyArray*> <long long>n.Array, flags)
 * 
 * cdef inline void* PyArray_DATA(ndarray n):             # <<<<<<<<<<<<<<
 *     # XXX "long long" is wrong type
 *     return NpyArray_DATA(<NpyArray*> <long long>n.Array)
 */

static CYTHON_INLINE void *PyArray_DATA(NumpyDotNet::ndarray^ __pyx_v_n) {
  void *__pyx_r;
  System::Object^ __pyx_t_1 = nullptr;
  PY_LONG_LONG __pyx_t_2;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\numpy.pxd":222
 * cdef inline void* PyArray_DATA(ndarray n):
 *     # XXX "long long" is wrong type
 *     return NpyArray_DATA(<NpyArray*> <long long>n.Array)             # <<<<<<<<<<<<<<
 * 
 * cdef inline intp_t* PyArray_DIMS(ndarray n):
 */
  __pyx_t_1 = __site_get_Array_222_49->Target(__site_get_Array_222_49, ((System::Object^)__pyx_v_n), __pyx_context);
  __pyx_t_2 = __site_cvt_PY_LONG_LONG_222_49->Target(__site_cvt_PY_LONG_LONG_222_49, __pyx_t_1);
  __pyx_t_1 = nullptr;
  __pyx_r = NpyArray_DATA(((NpyArray *)((PY_LONG_LONG)__pyx_t_2)));
  goto __pyx_L0;

  __pyx_r = 0;
  __pyx_L0:;
  return __pyx_r;
}

/* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\numpy.pxd":224
 *     return NpyArray_DATA(<NpyArray*> <long long>n.Array)
 * 
 * cdef inline intp_t* PyArray_DIMS(ndarray n):             # <<<<<<<<<<<<<<
 *     # XXX "long long" is wrong type
 *     return NpyArray_DIMS(<NpyArray*> <long long>n.Array)
 */

static CYTHON_INLINE __pyx_t_5scipy_7fftpack_5numpy_intp_t *PyArray_DIMS(NumpyDotNet::ndarray^ __pyx_v_n) {
  __pyx_t_5scipy_7fftpack_5numpy_intp_t *__pyx_r;
  System::Object^ __pyx_t_1 = nullptr;
  PY_LONG_LONG __pyx_t_2;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\numpy.pxd":226
 * cdef inline intp_t* PyArray_DIMS(ndarray n):
 *     # XXX "long long" is wrong type
 *     return NpyArray_DIMS(<NpyArray*> <long long>n.Array)             # <<<<<<<<<<<<<<
 * 
 * cdef inline intp_t PyArray_SIZE(ndarray n):
 */
  __pyx_t_1 = __site_get_Array_226_49->Target(__site_get_Array_226_49, ((System::Object^)__pyx_v_n), __pyx_context);
  __pyx_t_2 = __site_cvt_PY_LONG_LONG_226_49->Target(__site_cvt_PY_LONG_LONG_226_49, __pyx_t_1);
  __pyx_t_1 = nullptr;
  __pyx_r = NpyArray_DIMS(((NpyArray *)((PY_LONG_LONG)__pyx_t_2)));
  goto __pyx_L0;

  __pyx_r = 0;
  __pyx_L0:;
  return __pyx_r;
}

/* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\numpy.pxd":228
 *     return NpyArray_DIMS(<NpyArray*> <long long>n.Array)
 * 
 * cdef inline intp_t PyArray_SIZE(ndarray n):             # <<<<<<<<<<<<<<
 *     # XXX "long long" is wrong type
 *     return NpyArray_SIZE(<NpyArray*> <long long>n.Array)
 */

static CYTHON_INLINE __pyx_t_5scipy_7fftpack_5numpy_intp_t PyArray_SIZE(NumpyDotNet::ndarray^ __pyx_v_n) {
  __pyx_t_5scipy_7fftpack_5numpy_intp_t __pyx_r;
  System::Object^ __pyx_t_1 = nullptr;
  PY_LONG_LONG __pyx_t_2;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\numpy.pxd":230
 * cdef inline intp_t PyArray_SIZE(ndarray n):
 *     # XXX "long long" is wrong type
 *     return NpyArray_SIZE(<NpyArray*> <long long>n.Array)             # <<<<<<<<<<<<<<
 * 
 * cdef inline object PyArray_FromAny(op, newtype, min_depth, max_depth, flags, context):
 */
  __pyx_t_1 = __site_get_Array_230_49->Target(__site_get_Array_230_49, ((System::Object^)__pyx_v_n), __pyx_context);
  __pyx_t_2 = __site_cvt_PY_LONG_LONG_230_49->Target(__site_cvt_PY_LONG_LONG_230_49, __pyx_t_1);
  __pyx_t_1 = nullptr;
  __pyx_r = NpyArray_SIZE(((NpyArray *)((PY_LONG_LONG)__pyx_t_2)));
  goto __pyx_L0;

  __pyx_r = 0;
  __pyx_L0:;
  return __pyx_r;
}

/* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\numpy.pxd":232
 *     return NpyArray_SIZE(<NpyArray*> <long long>n.Array)
 * 
 * cdef inline object PyArray_FromAny(op, newtype, min_depth, max_depth, flags, context):             # <<<<<<<<<<<<<<
 *     import clr
 *     import NumpyDotNet.NpyArray
 */

static CYTHON_INLINE System::Object^ PyArray_FromAny(System::Object^ __pyx_v_op, System::Object^ __pyx_v_newtype, System::Object^ __pyx_v_min_depth, System::Object^ __pyx_v_max_depth, System::Object^ __pyx_v_flags, System::Object^ __pyx_v_context) {
  System::Object^ __pyx_v_clr;
  System::Object^ __pyx_v_NumpyDotNet;
  System::Object^ __pyx_r = nullptr;
  System::Object^ __pyx_t_1 = nullptr;
  System::Object^ __pyx_t_2 = nullptr;
  __pyx_v_clr = nullptr;
  __pyx_v_NumpyDotNet = nullptr;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\numpy.pxd":233
 * 
 * cdef inline object PyArray_FromAny(op, newtype, min_depth, max_depth, flags, context):
 *     import clr             # <<<<<<<<<<<<<<
 *     import NumpyDotNet.NpyArray
 *     return NumpyDotNet.NpyArray.FromAny(op, newtype, min_depth, max_depth, flags, context)
 */
  __pyx_t_1 = LightExceptions::CheckAndThrow(PythonOps::ImportTop(__pyx_context, "clr", -1));
  __pyx_v_clr = __pyx_t_1;
  __pyx_t_1 = nullptr;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\numpy.pxd":234
 * cdef inline object PyArray_FromAny(op, newtype, min_depth, max_depth, flags, context):
 *     import clr
 *     import NumpyDotNet.NpyArray             # <<<<<<<<<<<<<<
 *     return NumpyDotNet.NpyArray.FromAny(op, newtype, min_depth, max_depth, flags, context)
 * 
 */
  __pyx_t_1 = LightExceptions::CheckAndThrow(PythonOps::ImportTop(__pyx_context, "NumpyDotNet.NpyArray", -1));
  __pyx_v_NumpyDotNet = __pyx_t_1;
  __pyx_t_1 = nullptr;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\numpy.pxd":235
 *     import clr
 *     import NumpyDotNet.NpyArray
 *     return NumpyDotNet.NpyArray.FromAny(op, newtype, min_depth, max_depth, flags, context)             # <<<<<<<<<<<<<<
 * 
 * cdef inline object PyArray_FROMANY(m, type, min, max, flags):
 */
  __pyx_t_1 = __site_get_NpyArray_235_22->Target(__site_get_NpyArray_235_22, __pyx_v_NumpyDotNet, __pyx_context);
  __pyx_t_2 = __site_get_FromAny_235_31->Target(__site_get_FromAny_235_31, __pyx_t_1, __pyx_context);
  __pyx_t_1 = nullptr;
  __pyx_t_1 = __site_call6_235_39->Target(__site_call6_235_39, __pyx_context, __pyx_t_2, __pyx_v_op, __pyx_v_newtype, __pyx_v_min_depth, __pyx_v_max_depth, __pyx_v_flags, __pyx_v_context);
  __pyx_t_2 = nullptr;
  __pyx_r = __pyx_t_1;
  __pyx_t_1 = nullptr;
  goto __pyx_L0;

  __pyx_r = nullptr;
  __pyx_L0:;
  return __pyx_r;
}

/* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\numpy.pxd":237
 *     return NumpyDotNet.NpyArray.FromAny(op, newtype, min_depth, max_depth, flags, context)
 * 
 * cdef inline object PyArray_FROMANY(m, type, min, max, flags):             # <<<<<<<<<<<<<<
 *     if flags & NPY_ENSURECOPY:
 *         flags |= NPY_DEFAULT
 */

static CYTHON_INLINE System::Object^ PyArray_FROMANY(System::Object^ __pyx_v_m, System::Object^ __pyx_v_type, System::Object^ __pyx_v_min, System::Object^ __pyx_v_max, System::Object^ __pyx_v_flags) {
  System::Object^ __pyx_r = nullptr;
  System::Object^ __pyx_t_1 = nullptr;
  System::Object^ __pyx_t_2 = nullptr;
  int __pyx_t_3;
  int __pyx_t_4;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\numpy.pxd":238
 * 
 * cdef inline object PyArray_FROMANY(m, type, min, max, flags):
 *     if flags & NPY_ENSURECOPY:             # <<<<<<<<<<<<<<
 *         flags |= NPY_DEFAULT
 *     return PyArray_FromAny(m, Npy_INTERFACE_descr(NpyArray_DescrFromType(type)), min, max, flags, None)
 */
  __pyx_t_1 = (System::Object^)(long long)(NPY_ENSURECOPY);
  __pyx_t_2 = __site_op_and_238_13->Target(__site_op_and_238_13, __pyx_v_flags, __pyx_t_1);
  __pyx_t_1 = nullptr;
  __pyx_t_3 = __site_istrue_238_13->Target(__site_istrue_238_13, __pyx_t_2);
  __pyx_t_2 = nullptr;
  if (__pyx_t_3) {

    /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\numpy.pxd":239
 * cdef inline object PyArray_FROMANY(m, type, min, max, flags):
 *     if flags & NPY_ENSURECOPY:
 *         flags |= NPY_DEFAULT             # <<<<<<<<<<<<<<
 *     return PyArray_FromAny(m, Npy_INTERFACE_descr(NpyArray_DescrFromType(type)), min, max, flags, None)
 * 
 */
    __pyx_t_2 = (System::Object^)(long long)(NPY_DEFAULT);
    __pyx_t_1 = __site_op_ior_239_14->Target(__site_op_ior_239_14, __pyx_v_flags, __pyx_t_2);
    __pyx_t_2 = nullptr;
    __pyx_v_flags = __pyx_t_1;
    __pyx_t_1 = nullptr;
    goto __pyx_L3;
  }
  __pyx_L3:;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\numpy.pxd":240
 *     if flags & NPY_ENSURECOPY:
 *         flags |= NPY_DEFAULT
 *     return PyArray_FromAny(m, Npy_INTERFACE_descr(NpyArray_DescrFromType(type)), min, max, flags, None)             # <<<<<<<<<<<<<<
 * 
 * cdef inline object PyArray_Check(obj):
 */
  __pyx_t_4 = __site_cvt_int_240_77->Target(__site_cvt_int_240_77, __pyx_v_type);
  __pyx_t_1 = Npy_INTERFACE_OBJECT(NpyArray_DescrFromType(__pyx_t_4)); 
  __pyx_t_2 = PyArray_FromAny(__pyx_v_m, __pyx_t_1, __pyx_v_min, __pyx_v_max, __pyx_v_flags, nullptr); 
  __pyx_t_1 = nullptr;
  __pyx_r = __pyx_t_2;
  __pyx_t_2 = nullptr;
  goto __pyx_L0;

  __pyx_r = nullptr;
  __pyx_L0:;
  return __pyx_r;
}

/* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\numpy.pxd":242
 *     return PyArray_FromAny(m, Npy_INTERFACE_descr(NpyArray_DescrFromType(type)), min, max, flags, None)
 * 
 * cdef inline object PyArray_Check(obj):             # <<<<<<<<<<<<<<
 *     return isinstance(obj, ndarray)
 * 
 */

static CYTHON_INLINE System::Object^ PyArray_Check(System::Object^ __pyx_v_obj) {
  System::Object^ __pyx_r = nullptr;
  System::Object^ __pyx_t_1 = nullptr;
  System::Object^ __pyx_t_2 = nullptr;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\numpy.pxd":243
 * 
 * cdef inline object PyArray_Check(obj):
 *     return isinstance(obj, ndarray)             # <<<<<<<<<<<<<<
 * 
 * cdef inline object PyArray_NDIM(obj):
 */
  __pyx_t_1 = PythonOps::GetGlobal(__pyx_context, "isinstance");
  __pyx_t_2 = __site_call2_243_21->Target(__site_call2_243_21, __pyx_context, __pyx_t_1, __pyx_v_obj, ((System::Object^)((System::Object^)__pyx_ptype_5scipy_7fftpack_5numpy_ndarray)));
  __pyx_t_1 = nullptr;
  __pyx_r = __pyx_t_2;
  __pyx_t_2 = nullptr;
  goto __pyx_L0;

  __pyx_r = nullptr;
  __pyx_L0:;
  return __pyx_r;
}

/* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\numpy.pxd":245
 *     return isinstance(obj, ndarray)
 * 
 * cdef inline object PyArray_NDIM(obj):             # <<<<<<<<<<<<<<
 *     return obj.ndim
 * 
 */

static CYTHON_INLINE System::Object^ PyArray_NDIM(System::Object^ __pyx_v_obj) {
  System::Object^ __pyx_r = nullptr;
  System::Object^ __pyx_t_1 = nullptr;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\numpy.pxd":246
 * 
 * cdef inline object PyArray_NDIM(obj):
 *     return obj.ndim             # <<<<<<<<<<<<<<
 * 
 * cdef inline void import_array():
 */
  __pyx_t_1 = __site_get_ndim_246_14->Target(__site_get_ndim_246_14, __pyx_v_obj, __pyx_context);
  __pyx_r = __pyx_t_1;
  __pyx_t_1 = nullptr;
  goto __pyx_L0;

  __pyx_r = nullptr;
  __pyx_L0:;
  return __pyx_r;
}

/* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\numpy.pxd":248
 *     return obj.ndim
 * 
 * cdef inline void import_array():             # <<<<<<<<<<<<<<
 *     pass
 */

static CYTHON_INLINE void import_array(void) {

}
// XXX skipping all typeobj definitions
/* Cython code section 'pystring_table' */
/* Cython code section 'cached_builtins' */
/* Cython code section 'init_globals' */

static int __Pyx_InitGlobals(void) {
  __pyx_int_0 = 0;
  __pyx_int_1 = 1;

  return 0;
}
/* Cython code section 'init_module' */
static void __Pyx_InitSites(CodeContext^ __pyx_context) {
  const int PythonOperationKind_Contains = 5;
  const int PythonOperationKind_GetEnumeratorForIteration = 18;
  const int PythonOperationKind_FloorDivide = 23;
  const int PythonOperationKind_TrueDivide = 25;
  const int PythonOperationKind_InPlaceFloorDivide = 0x20000000 | 23;
  const int PythonOperationKind_InPlaceTrueDivide = 0x20000000 | 25;
  __site_cvt_31_0 = CallSite< System::Func< CallSite^, System::Object^, fwi_integer_t >^ >::Create(PythonOps::MakeConversionAction(__pyx_context, fwi_integer_t::typeid, ConversionResultKind::ExplicitCast));
  __site_cvt_31_0_1 = CallSite< System::Func< CallSite^, System::Object^, int >^ >::Create(PythonOps::MakeConversionAction(__pyx_context, int::typeid, ConversionResultKind::ExplicitCast));
  __site_cvt_fwi_integer_t_51_17 = CallSite< System::Func< CallSite^, System::Object^, fwi_integer_t >^ >::Create(PythonOps::MakeConversionAction(__pyx_context, fwi_integer_t::typeid, ConversionResultKind::ExplicitCast));
  __site_cvt_fwi_integer_t_55_9 = CallSite< System::Func< CallSite^, System::Object^, fwi_integer_t >^ >::Create(PythonOps::MakeConversionAction(__pyx_context, fwi_integer_t::typeid, ConversionResultKind::ExplicitCast));
  __site_call1_58_24 = CallSite< System::Func< CallSite^, CodeContext^, System::Object^, System::Object^, System::Object^ >^ >::Create(PythonOps::MakeInvokeAction(__pyx_context, CallSignature(1)));
  __site_call1_60_24 = CallSite< System::Func< CallSite^, CodeContext^, System::Object^, System::Object^, System::Object^ >^ >::Create(PythonOps::MakeInvokeAction(__pyx_context, CallSignature(1)));
  __site_cvt_63_0 = CallSite< System::Func< CallSite^, System::Object^, fwi_integer_t >^ >::Create(PythonOps::MakeConversionAction(__pyx_context, fwi_integer_t::typeid, ConversionResultKind::ExplicitCast));
  __site_cvt_63_0_1 = CallSite< System::Func< CallSite^, System::Object^, int >^ >::Create(PythonOps::MakeConversionAction(__pyx_context, int::typeid, ConversionResultKind::ExplicitCast));
  __site_cvt_fwi_integer_t_83_17 = CallSite< System::Func< CallSite^, System::Object^, fwi_integer_t >^ >::Create(PythonOps::MakeConversionAction(__pyx_context, fwi_integer_t::typeid, ConversionResultKind::ExplicitCast));
  __site_cvt_fwi_integer_t_87_9 = CallSite< System::Func< CallSite^, System::Object^, fwi_integer_t >^ >::Create(PythonOps::MakeConversionAction(__pyx_context, fwi_integer_t::typeid, ConversionResultKind::ExplicitCast));
  __site_call1_90_24 = CallSite< System::Func< CallSite^, CodeContext^, System::Object^, System::Object^, System::Object^ >^ >::Create(PythonOps::MakeInvokeAction(__pyx_context, CallSignature(1)));
  __site_call1_92_24 = CallSite< System::Func< CallSite^, CodeContext^, System::Object^, System::Object^, System::Object^ >^ >::Create(PythonOps::MakeInvokeAction(__pyx_context, CallSignature(1)));
  __site_cvt_98_0 = CallSite< System::Func< CallSite^, System::Object^, fwi_integer_t >^ >::Create(PythonOps::MakeConversionAction(__pyx_context, fwi_integer_t::typeid, ConversionResultKind::ExplicitCast));
  __site_cvt_98_0_1 = CallSite< System::Func< CallSite^, System::Object^, int >^ >::Create(PythonOps::MakeConversionAction(__pyx_context, int::typeid, ConversionResultKind::ExplicitCast));
  __site_cvt_fwi_integer_t_118_17 = CallSite< System::Func< CallSite^, System::Object^, fwi_integer_t >^ >::Create(PythonOps::MakeConversionAction(__pyx_context, fwi_integer_t::typeid, ConversionResultKind::ExplicitCast));
  __site_cvt_fwi_integer_t_123_9 = CallSite< System::Func< CallSite^, System::Object^, fwi_integer_t >^ >::Create(PythonOps::MakeConversionAction(__pyx_context, fwi_integer_t::typeid, ConversionResultKind::ExplicitCast));
  __site_call1_126_24 = CallSite< System::Func< CallSite^, CodeContext^, System::Object^, System::Object^, System::Object^ >^ >::Create(PythonOps::MakeInvokeAction(__pyx_context, CallSignature(1)));
  __site_call1_128_24 = CallSite< System::Func< CallSite^, CodeContext^, System::Object^, System::Object^, System::Object^ >^ >::Create(PythonOps::MakeInvokeAction(__pyx_context, CallSignature(1)));
  __site_cvt_131_0 = CallSite< System::Func< CallSite^, System::Object^, fwi_integer_t >^ >::Create(PythonOps::MakeConversionAction(__pyx_context, fwi_integer_t::typeid, ConversionResultKind::ExplicitCast));
  __site_cvt_131_0_1 = CallSite< System::Func< CallSite^, System::Object^, int >^ >::Create(PythonOps::MakeConversionAction(__pyx_context, int::typeid, ConversionResultKind::ExplicitCast));
  __site_cvt_fwi_integer_t_151_17 = CallSite< System::Func< CallSite^, System::Object^, fwi_integer_t >^ >::Create(PythonOps::MakeConversionAction(__pyx_context, fwi_integer_t::typeid, ConversionResultKind::ExplicitCast));
  __site_cvt_fwi_integer_t_156_9 = CallSite< System::Func< CallSite^, System::Object^, fwi_integer_t >^ >::Create(PythonOps::MakeConversionAction(__pyx_context, fwi_integer_t::typeid, ConversionResultKind::ExplicitCast));
  __site_call1_159_24 = CallSite< System::Func< CallSite^, CodeContext^, System::Object^, System::Object^, System::Object^ >^ >::Create(PythonOps::MakeInvokeAction(__pyx_context, CallSignature(1)));
  __site_call1_161_24 = CallSite< System::Func< CallSite^, CodeContext^, System::Object^, System::Object^, System::Object^ >^ >::Create(PythonOps::MakeInvokeAction(__pyx_context, CallSignature(1)));
  __site_cvt_164_0 = CallSite< System::Func< CallSite^, System::Object^, fwi_integer_t >^ >::Create(PythonOps::MakeConversionAction(__pyx_context, fwi_integer_t::typeid, ConversionResultKind::ExplicitCast));
  __site_cvt_164_0_1 = CallSite< System::Func< CallSite^, System::Object^, int >^ >::Create(PythonOps::MakeConversionAction(__pyx_context, int::typeid, ConversionResultKind::ExplicitCast));
  __site_cvt_fwi_integer_t_184_17 = CallSite< System::Func< CallSite^, System::Object^, fwi_integer_t >^ >::Create(PythonOps::MakeConversionAction(__pyx_context, fwi_integer_t::typeid, ConversionResultKind::ExplicitCast));
  __site_cvt_fwi_integer_t_189_9 = CallSite< System::Func< CallSite^, System::Object^, fwi_integer_t >^ >::Create(PythonOps::MakeConversionAction(__pyx_context, fwi_integer_t::typeid, ConversionResultKind::ExplicitCast));
  __site_call1_192_24 = CallSite< System::Func< CallSite^, CodeContext^, System::Object^, System::Object^, System::Object^ >^ >::Create(PythonOps::MakeInvokeAction(__pyx_context, CallSignature(1)));
  __site_call1_194_24 = CallSite< System::Func< CallSite^, CodeContext^, System::Object^, System::Object^, System::Object^ >^ >::Create(PythonOps::MakeInvokeAction(__pyx_context, CallSignature(1)));
  __site_cvt_197_0 = CallSite< System::Func< CallSite^, System::Object^, fwi_integer_t >^ >::Create(PythonOps::MakeConversionAction(__pyx_context, fwi_integer_t::typeid, ConversionResultKind::ExplicitCast));
  __site_cvt_197_0_1 = CallSite< System::Func< CallSite^, System::Object^, int >^ >::Create(PythonOps::MakeConversionAction(__pyx_context, int::typeid, ConversionResultKind::ExplicitCast));
  __site_cvt_fwi_integer_t_217_17 = CallSite< System::Func< CallSite^, System::Object^, fwi_integer_t >^ >::Create(PythonOps::MakeConversionAction(__pyx_context, fwi_integer_t::typeid, ConversionResultKind::ExplicitCast));
  __site_cvt_fwi_integer_t_222_9 = CallSite< System::Func< CallSite^, System::Object^, fwi_integer_t >^ >::Create(PythonOps::MakeConversionAction(__pyx_context, fwi_integer_t::typeid, ConversionResultKind::ExplicitCast));
  __site_call1_225_24 = CallSite< System::Func< CallSite^, CodeContext^, System::Object^, System::Object^, System::Object^ >^ >::Create(PythonOps::MakeInvokeAction(__pyx_context, CallSignature(1)));
  __site_call1_227_24 = CallSite< System::Func< CallSite^, CodeContext^, System::Object^, System::Object^, System::Object^ >^ >::Create(PythonOps::MakeInvokeAction(__pyx_context, CallSignature(1)));
  __site_cvt_233_0 = CallSite< System::Func< CallSite^, System::Object^, fwi_integer_t >^ >::Create(PythonOps::MakeConversionAction(__pyx_context, fwi_integer_t::typeid, ConversionResultKind::ExplicitCast));
  __site_cvt_233_0_1 = CallSite< System::Func< CallSite^, System::Object^, int >^ >::Create(PythonOps::MakeConversionAction(__pyx_context, int::typeid, ConversionResultKind::ExplicitCast));
  __site_cvt_fwi_integer_t_256_17 = CallSite< System::Func< CallSite^, System::Object^, fwi_integer_t >^ >::Create(PythonOps::MakeConversionAction(__pyx_context, fwi_integer_t::typeid, ConversionResultKind::ExplicitCast));
  __site_get_shape_264_24 = CallSite< System::Func< CallSite^, System::Object^, CodeContext^, System::Object^ >^ >::Create(PythonOps::MakeGetAction(__pyx_context, "shape", false));
  __site_cvt_fwi_integer_t_267_23 = CallSite< System::Func< CallSite^, System::Object^, fwi_integer_t >^ >::Create(PythonOps::MakeConversionAction(__pyx_context, fwi_integer_t::typeid, ConversionResultKind::ExplicitCast));
  __site_call1_269_24 = CallSite< System::Func< CallSite^, CodeContext^, System::Object^, System::Object^, System::Object^ >^ >::Create(PythonOps::MakeInvokeAction(__pyx_context, CallSignature(1)));
  __site_call1_276_24 = CallSite< System::Func< CallSite^, CodeContext^, System::Object^, System::Object^, System::Object^ >^ >::Create(PythonOps::MakeInvokeAction(__pyx_context, CallSignature(1)));
  __site_cvt_280_0 = CallSite< System::Func< CallSite^, System::Object^, fwi_integer_t >^ >::Create(PythonOps::MakeConversionAction(__pyx_context, fwi_integer_t::typeid, ConversionResultKind::ExplicitCast));
  __site_cvt_280_0_1 = CallSite< System::Func< CallSite^, System::Object^, int >^ >::Create(PythonOps::MakeConversionAction(__pyx_context, int::typeid, ConversionResultKind::ExplicitCast));
  __site_cvt_fwi_integer_t_303_17 = CallSite< System::Func< CallSite^, System::Object^, fwi_integer_t >^ >::Create(PythonOps::MakeConversionAction(__pyx_context, fwi_integer_t::typeid, ConversionResultKind::ExplicitCast));
  __site_get_shape_311_24 = CallSite< System::Func< CallSite^, System::Object^, CodeContext^, System::Object^ >^ >::Create(PythonOps::MakeGetAction(__pyx_context, "shape", false));
  __site_cvt_fwi_integer_t_314_23 = CallSite< System::Func< CallSite^, System::Object^, fwi_integer_t >^ >::Create(PythonOps::MakeConversionAction(__pyx_context, fwi_integer_t::typeid, ConversionResultKind::ExplicitCast));
  __site_call1_316_24 = CallSite< System::Func< CallSite^, CodeContext^, System::Object^, System::Object^, System::Object^ >^ >::Create(PythonOps::MakeInvokeAction(__pyx_context, CallSignature(1)));
  __site_call1_323_24 = CallSite< System::Func< CallSite^, CodeContext^, System::Object^, System::Object^, System::Object^ >^ >::Create(PythonOps::MakeInvokeAction(__pyx_context, CallSignature(1)));
  __site_cvt_423_0 = CallSite< System::Func< CallSite^, System::Object^, fwi_integer_t >^ >::Create(PythonOps::MakeConversionAction(__pyx_context, fwi_integer_t::typeid, ConversionResultKind::ExplicitCast));
  __site_cvt_423_0_1 = CallSite< System::Func< CallSite^, System::Object^, int >^ >::Create(PythonOps::MakeConversionAction(__pyx_context, int::typeid, ConversionResultKind::ExplicitCast));
  __site_cvt_fwi_integer_t_444_9 = CallSite< System::Func< CallSite^, System::Object^, fwi_integer_t >^ >::Create(PythonOps::MakeConversionAction(__pyx_context, fwi_integer_t::typeid, ConversionResultKind::ExplicitCast));
  __site_call1_447_24 = CallSite< System::Func< CallSite^, CodeContext^, System::Object^, System::Object^, System::Object^ >^ >::Create(PythonOps::MakeInvokeAction(__pyx_context, CallSignature(1)));
  __site_call1_449_24 = CallSite< System::Func< CallSite^, CodeContext^, System::Object^, System::Object^, System::Object^ >^ >::Create(PythonOps::MakeInvokeAction(__pyx_context, CallSignature(1)));
  __site_cvt_452_0 = CallSite< System::Func< CallSite^, System::Object^, fwi_integer_t >^ >::Create(PythonOps::MakeConversionAction(__pyx_context, fwi_integer_t::typeid, ConversionResultKind::ExplicitCast));
  __site_cvt_452_0_1 = CallSite< System::Func< CallSite^, System::Object^, int >^ >::Create(PythonOps::MakeConversionAction(__pyx_context, int::typeid, ConversionResultKind::ExplicitCast));
  __site_cvt_fwi_integer_t_473_9 = CallSite< System::Func< CallSite^, System::Object^, fwi_integer_t >^ >::Create(PythonOps::MakeConversionAction(__pyx_context, fwi_integer_t::typeid, ConversionResultKind::ExplicitCast));
  __site_call1_476_24 = CallSite< System::Func< CallSite^, CodeContext^, System::Object^, System::Object^, System::Object^ >^ >::Create(PythonOps::MakeInvokeAction(__pyx_context, CallSignature(1)));
  __site_call1_478_24 = CallSite< System::Func< CallSite^, CodeContext^, System::Object^, System::Object^, System::Object^ >^ >::Create(PythonOps::MakeInvokeAction(__pyx_context, CallSignature(1)));
  __site_cvt_481_0 = CallSite< System::Func< CallSite^, System::Object^, fwi_integer_t >^ >::Create(PythonOps::MakeConversionAction(__pyx_context, fwi_integer_t::typeid, ConversionResultKind::ExplicitCast));
  __site_cvt_481_0_1 = CallSite< System::Func< CallSite^, System::Object^, int >^ >::Create(PythonOps::MakeConversionAction(__pyx_context, int::typeid, ConversionResultKind::ExplicitCast));
  __site_cvt_fwi_integer_t_502_9 = CallSite< System::Func< CallSite^, System::Object^, fwi_integer_t >^ >::Create(PythonOps::MakeConversionAction(__pyx_context, fwi_integer_t::typeid, ConversionResultKind::ExplicitCast));
  __site_call1_505_24 = CallSite< System::Func< CallSite^, CodeContext^, System::Object^, System::Object^, System::Object^ >^ >::Create(PythonOps::MakeInvokeAction(__pyx_context, CallSignature(1)));
  __site_call1_507_24 = CallSite< System::Func< CallSite^, CodeContext^, System::Object^, System::Object^, System::Object^ >^ >::Create(PythonOps::MakeInvokeAction(__pyx_context, CallSignature(1)));
  __site_cvt_510_0 = CallSite< System::Func< CallSite^, System::Object^, fwi_integer_t >^ >::Create(PythonOps::MakeConversionAction(__pyx_context, fwi_integer_t::typeid, ConversionResultKind::ExplicitCast));
  __site_cvt_510_0_1 = CallSite< System::Func< CallSite^, System::Object^, int >^ >::Create(PythonOps::MakeConversionAction(__pyx_context, int::typeid, ConversionResultKind::ExplicitCast));
  __site_cvt_fwi_integer_t_531_9 = CallSite< System::Func< CallSite^, System::Object^, fwi_integer_t >^ >::Create(PythonOps::MakeConversionAction(__pyx_context, fwi_integer_t::typeid, ConversionResultKind::ExplicitCast));
  __site_call1_534_24 = CallSite< System::Func< CallSite^, CodeContext^, System::Object^, System::Object^, System::Object^ >^ >::Create(PythonOps::MakeInvokeAction(__pyx_context, CallSignature(1)));
  __site_call1_536_24 = CallSite< System::Func< CallSite^, CodeContext^, System::Object^, System::Object^, System::Object^ >^ >::Create(PythonOps::MakeInvokeAction(__pyx_context, CallSignature(1)));
  __site_cvt_539_0 = CallSite< System::Func< CallSite^, System::Object^, fwi_integer_t >^ >::Create(PythonOps::MakeConversionAction(__pyx_context, fwi_integer_t::typeid, ConversionResultKind::ExplicitCast));
  __site_cvt_539_0_1 = CallSite< System::Func< CallSite^, System::Object^, int >^ >::Create(PythonOps::MakeConversionAction(__pyx_context, int::typeid, ConversionResultKind::ExplicitCast));
  __site_cvt_fwi_integer_t_560_9 = CallSite< System::Func< CallSite^, System::Object^, fwi_integer_t >^ >::Create(PythonOps::MakeConversionAction(__pyx_context, fwi_integer_t::typeid, ConversionResultKind::ExplicitCast));
  __site_call1_563_24 = CallSite< System::Func< CallSite^, CodeContext^, System::Object^, System::Object^, System::Object^ >^ >::Create(PythonOps::MakeInvokeAction(__pyx_context, CallSignature(1)));
  __site_call1_565_24 = CallSite< System::Func< CallSite^, CodeContext^, System::Object^, System::Object^, System::Object^ >^ >::Create(PythonOps::MakeInvokeAction(__pyx_context, CallSignature(1)));
  __site_cvt_568_0 = CallSite< System::Func< CallSite^, System::Object^, fwi_integer_t >^ >::Create(PythonOps::MakeConversionAction(__pyx_context, fwi_integer_t::typeid, ConversionResultKind::ExplicitCast));
  __site_cvt_568_0_1 = CallSite< System::Func< CallSite^, System::Object^, int >^ >::Create(PythonOps::MakeConversionAction(__pyx_context, int::typeid, ConversionResultKind::ExplicitCast));
  __site_cvt_fwi_integer_t_589_9 = CallSite< System::Func< CallSite^, System::Object^, fwi_integer_t >^ >::Create(PythonOps::MakeConversionAction(__pyx_context, fwi_integer_t::typeid, ConversionResultKind::ExplicitCast));
  __site_call1_592_24 = CallSite< System::Func< CallSite^, CodeContext^, System::Object^, System::Object^, System::Object^ >^ >::Create(PythonOps::MakeInvokeAction(__pyx_context, CallSignature(1)));
  __site_call1_594_24 = CallSite< System::Func< CallSite^, CodeContext^, System::Object^, System::Object^, System::Object^ >^ >::Create(PythonOps::MakeInvokeAction(__pyx_context, CallSignature(1)));
  __site_get_append_199_18 = CallSite< System::Func< CallSite^, System::Object^, CodeContext^, System::Object^ >^ >::Create(PythonOps::MakeGetAction(__pyx_context, "append", false));
  __site_call1_199_25 = CallSite< System::Func< CallSite^, CodeContext^, System::Object^, System::Object^, System::Object^ >^ >::Create(PythonOps::MakeInvokeAction(__pyx_context, CallSignature(1)));
  __site_get_zeros_201_16 = CallSite< System::Func< CallSite^, System::Object^, CodeContext^, System::Object^ >^ >::Create(PythonOps::MakeGetAction(__pyx_context, "zeros", false));
  __site_call3_201_22 = CallSite< System::Func< CallSite^, CodeContext^, System::Object^, System::Object^, System::Object^, System::Object^, System::Object^ >^ >::Create(PythonOps::MakeInvokeAction(__pyx_context, CallSignature(3)));
  __site_get_append_207_18 = CallSite< System::Func< CallSite^, System::Object^, CodeContext^, System::Object^ >^ >::Create(PythonOps::MakeGetAction(__pyx_context, "append", false));
  __site_call1_207_25 = CallSite< System::Func< CallSite^, CodeContext^, System::Object^, System::Object^, System::Object^ >^ >::Create(PythonOps::MakeInvokeAction(__pyx_context, CallSignature(1)));
  __site_get_empty_209_16 = CallSite< System::Func< CallSite^, System::Object^, CodeContext^, System::Object^ >^ >::Create(PythonOps::MakeGetAction(__pyx_context, "empty", false));
  __site_call3_209_22 = CallSite< System::Func< CallSite^, CodeContext^, System::Object^, System::Object^, System::Object^, System::Object^, System::Object^ >^ >::Create(PythonOps::MakeInvokeAction(__pyx_context, CallSignature(3)));
  __site_get_Array_218_54 = CallSite< System::Func< CallSite^, System::Object^, CodeContext^, System::Object^ >^ >::Create(PythonOps::MakeGetAction(__pyx_context, "Array", false));
  __site_cvt_PY_LONG_LONG_218_54 = CallSite< System::Func< CallSite^, System::Object^, PY_LONG_LONG >^ >::Create(PythonOps::MakeConversionAction(__pyx_context, PY_LONG_LONG::typeid, ConversionResultKind::ExplicitCast));
  __site_get_Array_222_49 = CallSite< System::Func< CallSite^, System::Object^, CodeContext^, System::Object^ >^ >::Create(PythonOps::MakeGetAction(__pyx_context, "Array", false));
  __site_cvt_PY_LONG_LONG_222_49 = CallSite< System::Func< CallSite^, System::Object^, PY_LONG_LONG >^ >::Create(PythonOps::MakeConversionAction(__pyx_context, PY_LONG_LONG::typeid, ConversionResultKind::ExplicitCast));
  __site_get_Array_226_49 = CallSite< System::Func< CallSite^, System::Object^, CodeContext^, System::Object^ >^ >::Create(PythonOps::MakeGetAction(__pyx_context, "Array", false));
  __site_cvt_PY_LONG_LONG_226_49 = CallSite< System::Func< CallSite^, System::Object^, PY_LONG_LONG >^ >::Create(PythonOps::MakeConversionAction(__pyx_context, PY_LONG_LONG::typeid, ConversionResultKind::ExplicitCast));
  __site_get_Array_230_49 = CallSite< System::Func< CallSite^, System::Object^, CodeContext^, System::Object^ >^ >::Create(PythonOps::MakeGetAction(__pyx_context, "Array", false));
  __site_cvt_PY_LONG_LONG_230_49 = CallSite< System::Func< CallSite^, System::Object^, PY_LONG_LONG >^ >::Create(PythonOps::MakeConversionAction(__pyx_context, PY_LONG_LONG::typeid, ConversionResultKind::ExplicitCast));
  __site_get_NpyArray_235_22 = CallSite< System::Func< CallSite^, System::Object^, CodeContext^, System::Object^ >^ >::Create(PythonOps::MakeGetAction(__pyx_context, "NpyArray", false));
  __site_get_FromAny_235_31 = CallSite< System::Func< CallSite^, System::Object^, CodeContext^, System::Object^ >^ >::Create(PythonOps::MakeGetAction(__pyx_context, "FromAny", false));
  __site_call6_235_39 = CallSite< System::Func< CallSite^, CodeContext^, System::Object^, System::Object^, System::Object^, System::Object^, System::Object^, System::Object^, System::Object^, System::Object^ >^ >::Create(PythonOps::MakeInvokeAction(__pyx_context, CallSignature(6)));
  __site_op_and_238_13 = CallSite< System::Func< CallSite^, System::Object^, System::Object^, System::Object^ >^ >::Create(PythonOps::MakeBinaryOperationAction(__pyx_context, ExpressionType::And));
  __site_istrue_238_13 = CallSite< System::Func< CallSite^, System::Object^, bool >^ >::Create(PythonOps::MakeConversionAction(__pyx_context, bool::typeid, ConversionResultKind::ExplicitCast));
  __site_op_ior_239_14 = CallSite< System::Func< CallSite^, System::Object^, System::Object^, System::Object^ >^ >::Create(PythonOps::MakeBinaryOperationAction(__pyx_context, ExpressionType::OrAssign));
  __site_cvt_int_240_77 = CallSite< System::Func< CallSite^, System::Object^, int >^ >::Create(PythonOps::MakeConversionAction(__pyx_context, int::typeid, ConversionResultKind::ExplicitCast));
  __site_call2_243_21 = CallSite< System::Func< CallSite^, CodeContext^, System::Object^, System::Object^, System::Object^, System::Object^ >^ >::Create(PythonOps::MakeInvokeAction(__pyx_context, CallSignature(2)));
  __site_get_ndim_246_14 = CallSite< System::Func< CallSite^, System::Object^, CodeContext^, System::Object^ >^ >::Create(PythonOps::MakeGetAction(__pyx_context, "ndim", false));
}
[SpecialName]
static void PerformModuleReload(PythonContext^ context, PythonDictionary^ dict) {
  dict["__builtins__"] = context->BuiltinModuleInstance;
  __pyx_context = (gcnew ModuleContext(dict, context))->GlobalContext;
  __Pyx_InitSites(__pyx_context);
  __Pyx_InitGlobals();
  /*--- Type init code ---*/
  /*--- Create function pointers ---*/
  /*--- Execution code ---*/
  PythonDictionary^ __pyx_t_1;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":26
 * 
 * """
 * np.import_array()             # <<<<<<<<<<<<<<
 * 
 * cdef extern from "string.h":
 */
  import_array();

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\_fftpack.pyx":1
 * #cython: ccomplex=True             # <<<<<<<<<<<<<<
 * #cython: cdivision=True
 * 
 */
  __pyx_t_1 = PythonOps::MakeEmptyDict();
  PythonOps::SetGlobal(__pyx_context, "__test__", ((System::Object^)__pyx_t_1));
  __pyx_t_1 = nullptr;

  /* "C:\Documents and Settings\Jason\Documents\Visual Studio 2010\Projects\scipy-refactor\scipy\fftpack\numpy.pxd":248
 *     return obj.ndim
 * 
 * cdef inline void import_array():             # <<<<<<<<<<<<<<
 *     pass
 */
}
/* Cython code section 'cleanup_globals' */
/* Cython code section 'cleanup_module' */
/* Cython code section 'main_method' */
/* Cython code section 'dotnet_globals' */


static Types::PythonType^ __pyx_ptype_5scipy_7fftpack_5numpy_ndarray = nullptr;
static Types::PythonType^ __pyx_ptype_5scipy_7fftpack_5numpy_dtype = nullptr;



/* Cython code section 'utility_code_def' */

/* Runtime support code */

#if 0
static CYTHON_INLINE int __Pyx_IsLittleEndian(void) {
  unsigned int n = 1;
  return *(unsigned char*)(&n) != 0;
}

typedef struct {
  __Pyx_StructField root;
  __Pyx_BufFmt_StackElem* head;
  size_t fmt_offset;
  int new_count, enc_count;
  int is_complex;
  char enc_type;
  char packmode;
} __Pyx_BufFmt_Context;

static void __Pyx_BufFmt_Init(__Pyx_BufFmt_Context* ctx,
                              __Pyx_BufFmt_StackElem* stack,
                              __Pyx_TypeInfo* type) {
  stack[0].field = &ctx->root;
  stack[0].parent_offset = 0;
  ctx->root.type = type;
  ctx->root.name = "buffer dtype";
  ctx->root.offset = 0;
  ctx->head = stack;
  ctx->head->field = &ctx->root;
  ctx->fmt_offset = 0;
  ctx->head->parent_offset = 0;
  ctx->packmode = '@';
  ctx->new_count = 1;
  ctx->enc_count = 0;
  ctx->enc_type = 0;
  ctx->is_complex = 0;
  while (type->typegroup == 'S') {
    ++ctx->head;
    ctx->head->field = type->fields;
    ctx->head->parent_offset = 0;
    type = type->fields->type;
  }
}

static int __Pyx_BufFmt_ParseNumber(const char** ts) {
    int count;
    const char* t = *ts;
    if (*t < '0' || *t > '9') {
      return -1;
    } else {
        count = *t++ - '0';
        while (*t >= '0' && *t < '9') {
            count *= 10;
            count += *t++ - '0';
        }
    }
    *ts = t;
    return count;
}

static void __Pyx_BufFmt_RaiseUnexpectedChar(char ch) {
  char msg[] = {ch, 0};
  PyErr_Format(PyExc_ValueError, "Unexpected format string character: '%s'", msg);
}

static const char* __Pyx_BufFmt_DescribeTypeChar(char ch, int is_complex) {
  switch (ch) {
    case 'b': return "'char'";
    case 'B': return "'unsigned char'";
    case 'h': return "'short'";
    case 'H': return "'unsigned short'";
    case 'i': return "'int'";
    case 'I': return "'unsigned int'";
    case 'l': return "'long'";
    case 'L': return "'unsigned long'";
    case 'q': return "'long long'";
    case 'Q': return "'unsigned long long'";
    case 'f': return (is_complex ? "'complex float'" : "'float'");
    case 'd': return (is_complex ? "'complex double'" : "'double'");
    case 'g': return (is_complex ? "'complex long double'" : "'long double'");
    case 'T': return "a struct";
    case 'O': return "Python object";
    case 'P': return "a pointer";
    case 0: return "end";
    default: return "unparseable format string";
  }
}

static size_t __Pyx_BufFmt_TypeCharToStandardSize(char ch, int is_complex) {
  switch (ch) {
    case '?': case 'c': case 'b': case 'B': return 1;
    case 'h': case 'H': return 2;
    case 'i': case 'I': case 'l': case 'L': return 4;
    case 'q': case 'Q': return 8;
    case 'f': return (is_complex ? 8 : 4);
    case 'd': return (is_complex ? 16 : 8);
    case 'g': {
      PyErr_SetString(PyExc_ValueError, "Python does not define a standard format string size for long double ('g')..");
      return 0;
    }
    case 'O': case 'P': return sizeof(void*);
    default:
      __Pyx_BufFmt_RaiseUnexpectedChar(ch);
      return 0;
    }
}

static size_t __Pyx_BufFmt_TypeCharToNativeSize(char ch, int is_complex) {
  switch (ch) {
    case 'c': case 'b': case 'B': return 1;
    case 'h': case 'H': return sizeof(short);
    case 'i': case 'I': return sizeof(int);
    case 'l': case 'L': return sizeof(long);
    #ifdef HAVE_LONG_LONG
    case 'q': case 'Q': return sizeof(PY_LONG_LONG);
    #endif
    case 'f': return sizeof(float) * (is_complex ? 2 : 1);
    case 'd': return sizeof(double) * (is_complex ? 2 : 1);
    case 'g': return sizeof(long double) * (is_complex ? 2 : 1);
    case 'O': case 'P': return sizeof(void*);
    default: {
      __Pyx_BufFmt_RaiseUnexpectedChar(ch);
      return 0;
    }    
  }
}

typedef struct { char c; short x; } __Pyx_st_short;
typedef struct { char c; int x; } __Pyx_st_int;
typedef struct { char c; long x; } __Pyx_st_long;
typedef struct { char c; float x; } __Pyx_st_float;
typedef struct { char c; double x; } __Pyx_st_double;
typedef struct { char c; long double x; } __Pyx_st_longdouble;
typedef struct { char c; void *x; } __Pyx_st_void_p;
#ifdef HAVE_LONG_LONG
typedef struct { char c; PY_LONG_LONG x; } __Pyx_s_long_long;
#endif

static size_t __Pyx_BufFmt_TypeCharToAlignment(char ch, int is_complex) {
  switch (ch) {
    case '?': case 'c': case 'b': case 'B': return 1;
    case 'h': case 'H': return sizeof(__Pyx_st_short) - sizeof(short);
    case 'i': case 'I': return sizeof(__Pyx_st_int) - sizeof(int);
    case 'l': case 'L': return sizeof(__Pyx_st_long) - sizeof(long);
#ifdef HAVE_LONG_LONG
    case 'q': case 'Q': return sizeof(__Pyx_s_long_long) - sizeof(PY_LONG_LONG);
#endif
    case 'f': return sizeof(__Pyx_st_float) - sizeof(float);
    case 'd': return sizeof(__Pyx_st_double) - sizeof(double);
    case 'g': return sizeof(__Pyx_st_longdouble) - sizeof(long double);
    case 'P': case 'O': return sizeof(__Pyx_st_void_p) - sizeof(void*);
    default:
      __Pyx_BufFmt_RaiseUnexpectedChar(ch);
      return 0;
    }
}

static size_t __Pyx_BufFmt_TypeCharToGroup(char ch, int is_complex) {
  switch (ch) {
    case 'c': case 'b': case 'h': case 'i': case 'l': case 'q': return 'I';
    case 'B': case 'H': case 'I': case 'L': case 'Q': return 'U';
    case 'f': case 'd': case 'g': return (is_complex ? 'C' : 'R');
    case 'O': return 'O';
    case 'P': return 'P';
    default: {
      __Pyx_BufFmt_RaiseUnexpectedChar(ch);
      return 0;
    }    
  }
}

static void __Pyx_BufFmt_RaiseExpected(__Pyx_BufFmt_Context* ctx) {
  if (ctx->head == NULL || ctx->head->field == &ctx->root) {
    const char* expected;
    const char* quote;
    if (ctx->head == NULL) {
      expected = "end";
      quote = "";
    } else {
      expected = ctx->head->field->type->name;
      quote = "'";
    }
    PyErr_Format(PyExc_ValueError,
                 "Buffer dtype mismatch, expected %s%s%s but got %s",
                 quote, expected, quote,
                 __Pyx_BufFmt_DescribeTypeChar(ctx->enc_type, ctx->is_complex));
  } else {
    __Pyx_StructField* field = ctx->head->field;
    __Pyx_StructField* parent = (ctx->head - 1)->field;
    PyErr_Format(PyExc_ValueError,
                 "Buffer dtype mismatch, expected '%s' but got %s in '%s.%s'",
                 field->type->name, __Pyx_BufFmt_DescribeTypeChar(ctx->enc_type, ctx->is_complex),
                 parent->type->name, field->name);
  }
}

static int __Pyx_BufFmt_ProcessTypeChunk(__Pyx_BufFmt_Context* ctx) {
  char group;
  size_t size, offset;
  if (ctx->enc_type == 0) return 0;
  group = __Pyx_BufFmt_TypeCharToGroup(ctx->enc_type, ctx->is_complex);
  do {
    __Pyx_StructField* field = ctx->head->field;
    __Pyx_TypeInfo* type = field->type;
  
    if (ctx->packmode == '@' || ctx->packmode == '^') {
      size = __Pyx_BufFmt_TypeCharToNativeSize(ctx->enc_type, ctx->is_complex);
    } else {
      size = __Pyx_BufFmt_TypeCharToStandardSize(ctx->enc_type, ctx->is_complex);
    }
    if (ctx->packmode == '@') {
      int align_at = __Pyx_BufFmt_TypeCharToAlignment(ctx->enc_type, ctx->is_complex);
      int align_mod_offset;
      if (align_at == 0) return -1;
      align_mod_offset = ctx->fmt_offset % align_at;
      if (align_mod_offset > 0) ctx->fmt_offset += align_at - align_mod_offset;
    }

    if (type->size != size || type->typegroup != group) {
      if (type->typegroup == 'C' && type->fields != NULL) {
        /* special case -- treat as struct rather than complex number */
        size_t parent_offset = ctx->head->parent_offset + field->offset;
        ++ctx->head;
        ctx->head->field = type->fields;
        ctx->head->parent_offset = parent_offset;
        continue;
      }
    
      __Pyx_BufFmt_RaiseExpected(ctx);
      return -1;
    }

    offset = ctx->head->parent_offset + field->offset;
    if (ctx->fmt_offset != offset) {
      PyErr_Format(PyExc_ValueError,
                   "Buffer dtype mismatch; next field is at offset %"PY_FORMAT_SIZE_T"d "
                   "but %"PY_FORMAT_SIZE_T"d expected", ctx->fmt_offset, offset);
      return -1;
    }

    ctx->fmt_offset += size;
  
    --ctx->enc_count; /* Consume from buffer string */

    /* Done checking, move to next field, pushing or popping struct stack if needed */
    while (1) {
      if (field == &ctx->root) {
        ctx->head = NULL;
        if (ctx->enc_count != 0) {
          __Pyx_BufFmt_RaiseExpected(ctx);
          return -1;
        }
        break; /* breaks both loops as ctx->enc_count == 0 */
      }
      ctx->head->field = ++field;
      if (field->type == NULL) {
        --ctx->head;
        field = ctx->head->field;
        continue;
      } else if (field->type->typegroup == 'S') {
        size_t parent_offset = ctx->head->parent_offset + field->offset;
        if (field->type->fields->type == NULL) continue; /* empty struct */
        field = field->type->fields;
        ++ctx->head;
        ctx->head->field = field;
        ctx->head->parent_offset = parent_offset;
        break;
      } else {
        break;
      }
    }
  } while (ctx->enc_count);
  ctx->enc_type = 0;
  ctx->is_complex = 0;
  return 0;    
}

static int __Pyx_BufFmt_FirstPack(__Pyx_BufFmt_Context* ctx) {
  if (ctx->enc_type != 0 || ctx->packmode != '@') {
    PyErr_SetString(PyExc_ValueError, "Buffer packing mode currently only allowed at beginning of format string (this is a defect)");
    return -1;
  }
  return 0;
}

static const char* __Pyx_BufFmt_CheckString(__Pyx_BufFmt_Context* ctx, const char* ts) {
  int got_Z = 0;
  while (1) {
    switch(*ts) {
      case 0:
        if (ctx->enc_type != 0 && ctx->head == NULL) {
          __Pyx_BufFmt_RaiseExpected(ctx);
          return NULL;
        }
        if (__Pyx_BufFmt_ProcessTypeChunk(ctx) == -1) return NULL;
        if (ctx->head != NULL) {
          __Pyx_BufFmt_RaiseExpected(ctx);
          return NULL;
        }
        return ts;
      case ' ':
      case 10:
      case 13:
        ++ts;
        break;
      case '<':
        if (!__Pyx_IsLittleEndian()) {
          PyErr_SetString(PyExc_ValueError, "Little-endian buffer not supported on big-endian compiler");
          return NULL;
        }
        if (__Pyx_BufFmt_FirstPack(ctx) == -1) return NULL;
        ctx->packmode = '=';
        ++ts;
        break;
      case '>':
      case '!':
        if (__Pyx_IsLittleEndian()) {
          PyErr_SetString(PyExc_ValueError, "Big-endian buffer not supported on little-endian compiler");
          return NULL;
        }
        if (__Pyx_BufFmt_FirstPack(ctx) == -1) return NULL;
        ctx->packmode = '=';
        ++ts;
        break;
      case '=':
      case '@':
      case '^':
        if (__Pyx_BufFmt_FirstPack(ctx) == -1) return NULL;
        ctx->packmode = *ts++;
        break;
      case 'T': /* substruct */
        {
          int i;
          const char* ts_after_sub;
          int struct_count = ctx->new_count;
          ctx->new_count = 1;
          ++ts;
          if (*ts != '{') {
            PyErr_SetString(PyExc_ValueError, "Buffer acquisition: Expected '{' after 'T'");
            return NULL;
          }
          ++ts;
          ts_after_sub = ts;
          for (i = 0; i != struct_count; ++i) {
            ts_after_sub = __Pyx_BufFmt_CheckString(ctx, ts);
            if (!ts_after_sub) return NULL;
          }
          ts = ts_after_sub;
        }
        break;
      case '}': /* end of substruct; either repeat or move on */
        ++ts;
        return ts;
      case 'x':
        if (__Pyx_BufFmt_ProcessTypeChunk(ctx) == -1) return NULL;
        ctx->fmt_offset += ctx->new_count;
        ctx->new_count = 1;
        ctx->enc_count = 0;
        ctx->enc_type = 0;
        ++ts;
        break;
      case 'Z':
        got_Z = 1;
        ++ts;
        if (*ts != 'f' && *ts != 'd' && *ts != 'g') {
          __Pyx_BufFmt_RaiseUnexpectedChar('Z');
          return NULL;
        }        /* fall through */
      case 'c': case 'b': case 'B': case 'h': case 'H': case 'i': case 'I':
      case 'l': case 'L': case 'q': case 'Q':
      case 'f': case 'd': case 'g':
      case 'O':
        if (ctx->enc_type == *ts && got_Z == ctx->is_complex) {
          /* Continue pooling same type */
          ctx->enc_count += ctx->new_count;
        } else {
          /* New type */
          if (__Pyx_BufFmt_ProcessTypeChunk(ctx) == -1) return NULL;
          ctx->enc_count = ctx->new_count;
          ctx->enc_type = *ts;
          ctx->is_complex = got_Z;
        }
        ++ts;
        ctx->new_count = 1;
        got_Z = 0;
        break;
      default:
        {
          ctx->new_count = __Pyx_BufFmt_ParseNumber(&ts);
          if (ctx->new_count == -1) { /* First char was not a digit */
            char msg[2] = { *ts, 0 };
            PyErr_Format(PyExc_ValueError,
                         "Does not understand character buffer dtype format string ('%s')", msg);
            return NULL;
          }
        }
      
    }
  }
}
#endif

static CYTHON_INLINE void __Pyx_GetBufferAndValidate(NumpyDotNet::IExtBufferProtocol^& buf, System::Object^ obj, __Pyx_TypeInfo* dtype, int flags, int nd, int cast, __Pyx_BufFmt_StackElem* stack) {
  if (obj == Py_None) {
    buf = nullptr;
    return;
  }
  __Pyx_GetBuffer(obj, buf, flags);
  if (buf->NumberDimensions != nd) {
    buf = nullptr;
    throw PythonOps::ValueError("Buffer has wrong number of dimensions (expected {0}, got {1})", nd, buf->NumberDimensions);
  }
  if (!cast) {
#if 0
    XXX
    __Pyx_BufFmt_Context ctx;
    __Pyx_BufFmt_Init(&ctx, stack, dtype);
    if (!__Pyx_BufFmt_CheckString(&ctx, buf->format)) goto fail;
#endif
  }
  if ((unsigned)buf->ItemSize != dtype->size) {
    buf = nullptr;
    throw PythonOps::ValueError("Item size of buffer ({0} byte{1}) does not match size of '{2}' ({3} byte{4})",
      buf->ItemSize, (buf->ItemSize > 1) ? "s" : "",
      gcnew System::String(dtype->name),
      dtype->size, (dtype->size > 1) ? "s" : "");
  }
#if 0
  XXX
  if (buf->suboffsets == NULL) buf->suboffsets = __Pyx_minusones;
#endif
  return;
fail:;
  buf = nullptr;
  throw PythonOps::ValueError("XXX buffer error");
}

static CYTHON_INLINE void __Pyx_SafeReleaseBuffer(NumpyDotNet::IExtBufferProtocol^ info) {
  if (info == nullptr) return;
#if 0
  XXX
  if (info->buf == NULL) return;
  if (info->suboffsets == __Pyx_minusones) info->suboffsets = NULL;
#endif
  __Pyx_ReleaseBuffer(info);
}
static void __Pyx_RaiseBufferIndexError(int axis) {
  throw PythonOps::IndexError(
     "Out of bounds on buffer access (axis {0})", axis);
}


static void __Pyx_GetBuffer(System::Object^ obj, NumpyDotNet::IExtBufferProtocol^& view, int flags) {
  view = NumpyDotNet::NpyBuffer::GetBufferForObject(obj, (NumpyDotNet::NpyBuffer::PyBuf)flags);
}
static void __Pyx_ReleaseBuffer(NumpyDotNet::IExtBufferProtocol^ view) {
  /* do nothing */
}

#if CYTHON_CCOMPLEX
  #ifdef __cplusplus
    static CYTHON_INLINE __pyx_t_float_complex __pyx_t_float_complex_from_parts(float x, float y) {
      return ::std::complex< float >(x, y);
    }
  #else
    static CYTHON_INLINE __pyx_t_float_complex __pyx_t_float_complex_from_parts(float x, float y) {
      return x + y*(__pyx_t_float_complex)_Complex_I;
    }
  #endif
#else
    static CYTHON_INLINE __pyx_t_float_complex __pyx_t_float_complex_from_parts(float x, float y) {
      __pyx_t_float_complex z;
      z.real = x;
      z.imag = y;
      return z;
    }
#endif

#if CYTHON_CCOMPLEX
#else
    static CYTHON_INLINE int __Pyx_c_eqf(__pyx_t_float_complex a, __pyx_t_float_complex b) {
       return (a.real == b.real) && (a.imag == b.imag);
    }
    static CYTHON_INLINE __pyx_t_float_complex __Pyx_c_sumf(__pyx_t_float_complex a, __pyx_t_float_complex b) {
        __pyx_t_float_complex z;
        z.real = a.real + b.real;
        z.imag = a.imag + b.imag;
        return z;
    }
    static CYTHON_INLINE __pyx_t_float_complex __Pyx_c_difff(__pyx_t_float_complex a, __pyx_t_float_complex b) {
        __pyx_t_float_complex z;
        z.real = a.real - b.real;
        z.imag = a.imag - b.imag;
        return z;
    }
    static CYTHON_INLINE __pyx_t_float_complex __Pyx_c_prodf(__pyx_t_float_complex a, __pyx_t_float_complex b) {
        __pyx_t_float_complex z;
        z.real = a.real * b.real - a.imag * b.imag;
        z.imag = a.real * b.imag + a.imag * b.real;
        return z;
    }
    static CYTHON_INLINE __pyx_t_float_complex __Pyx_c_quotf(__pyx_t_float_complex a, __pyx_t_float_complex b) {
        __pyx_t_float_complex z;
        float denom = b.real * b.real + b.imag * b.imag;
        z.real = (a.real * b.real + a.imag * b.imag) / denom;
        z.imag = (a.imag * b.real - a.real * b.imag) / denom;
        return z;
    }
    static CYTHON_INLINE __pyx_t_float_complex __Pyx_c_negf(__pyx_t_float_complex a) {
        __pyx_t_float_complex z;
        z.real = -a.real;
        z.imag = -a.imag;
        return z;
    }
    static CYTHON_INLINE int __Pyx_c_is_zerof(__pyx_t_float_complex a) {
       return (a.real == 0) && (a.imag == 0);
    }
    static CYTHON_INLINE __pyx_t_float_complex __Pyx_c_conjf(__pyx_t_float_complex a) {
        __pyx_t_float_complex z;
        z.real =  a.real;
        z.imag = -a.imag;
        return z;
    }
/*
    static CYTHON_INLINE float __Pyx_c_absf(__pyx_t_float_complex z) {
#if HAVE_HYPOT
        return hypotf(z.real, z.imag);
#else
        return sqrtf(z.real*z.real + z.imag*z.imag);
#endif
    }
*/
#endif

#if CYTHON_CCOMPLEX
  #ifdef __cplusplus
    static CYTHON_INLINE __pyx_t_double_complex __pyx_t_double_complex_from_parts(double x, double y) {
      return ::std::complex< double >(x, y);
    }
  #else
    static CYTHON_INLINE __pyx_t_double_complex __pyx_t_double_complex_from_parts(double x, double y) {
      return x + y*(__pyx_t_double_complex)_Complex_I;
    }
  #endif
#else
    static CYTHON_INLINE __pyx_t_double_complex __pyx_t_double_complex_from_parts(double x, double y) {
      __pyx_t_double_complex z;
      z.real = x;
      z.imag = y;
      return z;
    }
#endif

#if CYTHON_CCOMPLEX
#else
    static CYTHON_INLINE int __Pyx_c_eq(__pyx_t_double_complex a, __pyx_t_double_complex b) {
       return (a.real == b.real) && (a.imag == b.imag);
    }
    static CYTHON_INLINE __pyx_t_double_complex __Pyx_c_sum(__pyx_t_double_complex a, __pyx_t_double_complex b) {
        __pyx_t_double_complex z;
        z.real = a.real + b.real;
        z.imag = a.imag + b.imag;
        return z;
    }
    static CYTHON_INLINE __pyx_t_double_complex __Pyx_c_diff(__pyx_t_double_complex a, __pyx_t_double_complex b) {
        __pyx_t_double_complex z;
        z.real = a.real - b.real;
        z.imag = a.imag - b.imag;
        return z;
    }
    static CYTHON_INLINE __pyx_t_double_complex __Pyx_c_prod(__pyx_t_double_complex a, __pyx_t_double_complex b) {
        __pyx_t_double_complex z;
        z.real = a.real * b.real - a.imag * b.imag;
        z.imag = a.real * b.imag + a.imag * b.real;
        return z;
    }
    static CYTHON_INLINE __pyx_t_double_complex __Pyx_c_quot(__pyx_t_double_complex a, __pyx_t_double_complex b) {
        __pyx_t_double_complex z;
        double denom = b.real * b.real + b.imag * b.imag;
        z.real = (a.real * b.real + a.imag * b.imag) / denom;
        z.imag = (a.imag * b.real - a.real * b.imag) / denom;
        return z;
    }
    static CYTHON_INLINE __pyx_t_double_complex __Pyx_c_neg(__pyx_t_double_complex a) {
        __pyx_t_double_complex z;
        z.real = -a.real;
        z.imag = -a.imag;
        return z;
    }
    static CYTHON_INLINE int __Pyx_c_is_zero(__pyx_t_double_complex a) {
       return (a.real == 0) && (a.imag == 0);
    }
    static CYTHON_INLINE __pyx_t_double_complex __Pyx_c_conj(__pyx_t_double_complex a) {
        __pyx_t_double_complex z;
        z.real =  a.real;
        z.imag = -a.imag;
        return z;
    }
/*
    static CYTHON_INLINE double __Pyx_c_abs(__pyx_t_double_complex z) {
#if HAVE_HYPOT
        return hypot(z.real, z.imag);
#else
        return sqrt(z.real*z.real + z.imag*z.imag);
#endif
    }
*/
#endif
/* Cython code section 'end' */
};
[assembly: PythonModule("scipy__fftpack___fftpack", module__fftpack::typeid)];
};
