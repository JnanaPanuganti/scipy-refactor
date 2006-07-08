
/************************************************************************/
/* swig_num.i -- typemaps for mapping C arrays to Python Numeric arrays */
/*                                                                      */    
/* This file is auto-generated by swig_num_gen.py.                      */
/* DO NOT EDIT THIS FILE DIRECTLY unless you want your changes          */
/* clobbered by the next run of the generator.                          */
/************************************************************************/

%include typemaps.i

/************************************************************************/
/*                   helper functions and initialization                */
/************************************************************************/
%{

#include "numpy/arrayobject.h"

// hmmm. how do we prevent typedefs from conflicting
// with users definition on complex numbers?
//#include "complex_test.h"
//typedef struct{ float real; 
//                float imag;} complex;
//typedef struct{ double real; 
//                double imag;} zcomplex;


// used for converting typecodes to memory sizes.
int char_to_size(char type)
{
    if (type=='i') return sizeof(int);
    if (type=='f') return sizeof(float);
    if (type=='d') return sizeof(double);
    if (type=='c') return 2*sizeof(float);
    if (type=='z') return 2*sizeof(double);
}
int char_to_numtype(char type)
{
    if (type=='i') return 'i';
    if (type=='f') return 'f';
    if (type=='d') return 'd';
    if (type=='c') return 'F';
    if (type=='z') return 'D';
}
%}

%init %{
        import_array();
%}

%{

typedef int int_IN_D0;
typedef float float_IN_D0;
typedef double double_IN_D0;
typedef int int_IN_D1;
typedef float float_IN_D1;
typedef double double_IN_D1;
typedef int int_IN_D2;
typedef float float_IN_D2;
typedef double double_IN_D2;
typedef int int_IN_D0_D1;
typedef float float_IN_D0_D1;
typedef double double_IN_D0_D1;
typedef int int_IN_D0_D2;
typedef float float_IN_D0_D2;
typedef double double_IN_D0_D2;
typedef int int_IN_D1_D2;
typedef float float_IN_D1_D2;
typedef double double_IN_D1_D2;
typedef int int_IN_D0_D1_D2;
typedef float float_IN_D0_D1_D2;
typedef double double_IN_D0_D1_D2;


typedef int int_ARGOUT_D0;
typedef float float_ARGOUT_D0;
typedef double double_ARGOUT_D0;
typedef int int_ARGOUT_D1;
typedef float float_ARGOUT_D1;
typedef double double_ARGOUT_D1;
typedef int int_ARGOUT_D2;
typedef float float_ARGOUT_D2;
typedef double double_ARGOUT_D2;
typedef int int_ARGOUT_D0_D1;
typedef float float_ARGOUT_D0_D1;
typedef double double_ARGOUT_D0_D1;
typedef int int_ARGOUT_D0_D2;
typedef float float_ARGOUT_D0_D2;
typedef double double_ARGOUT_D0_D2;
typedef int int_ARGOUT_D1_D2;
typedef float float_ARGOUT_D1_D2;
typedef double double_ARGOUT_D1_D2;
typedef int int_ARGOUT_D0_D1_D2;
typedef float float_ARGOUT_D0_D1_D2;
typedef double double_ARGOUT_D0_D1_D2;


typedef int int_ARGOUT_TUPLE_D0;
typedef float float_ARGOUT_TUPLE_D0;
typedef double double_ARGOUT_TUPLE_D0;
typedef int int_ARGOUT_TUPLE_D1;
typedef float float_ARGOUT_TUPLE_D1;
typedef double double_ARGOUT_TUPLE_D1;
typedef int int_ARGOUT_TUPLE_D2;
typedef float float_ARGOUT_TUPLE_D2;
typedef double double_ARGOUT_TUPLE_D2;
typedef int int_ARGOUT_TUPLE_D0_D1;
typedef float float_ARGOUT_TUPLE_D0_D1;
typedef double double_ARGOUT_TUPLE_D0_D1;
typedef int int_ARGOUT_TUPLE_D0_D2;
typedef float float_ARGOUT_TUPLE_D0_D2;
typedef double double_ARGOUT_TUPLE_D0_D2;
typedef int int_ARGOUT_TUPLE_D1_D2;
typedef float float_ARGOUT_TUPLE_D1_D2;
typedef double double_ARGOUT_TUPLE_D1_D2;
typedef int int_ARGOUT_TUPLE_D0_D1_D2;
typedef float float_ARGOUT_TUPLE_D0_D1_D2;
typedef double double_ARGOUT_TUPLE_D0_D1_D2;


typedef int int_OUT_D0;
typedef float float_OUT_D0;
typedef double double_OUT_D0;
typedef int int_OUT_D1;
typedef float float_OUT_D1;
typedef double double_OUT_D1;
typedef int int_OUT_D2;
typedef float float_OUT_D2;
typedef double double_OUT_D2;
typedef int int_OUT_D0_D1;
typedef float float_OUT_D0_D1;
typedef double double_OUT_D0_D1;
typedef int int_OUT_D0_D2;
typedef float float_OUT_D0_D2;
typedef double double_OUT_D0_D2;
typedef int int_OUT_D1_D2;
typedef float float_OUT_D1_D2;
typedef double double_OUT_D1_D2;
typedef int int_OUT_D0_D1_D2;
typedef float float_OUT_D0_D1_D2;
typedef double double_OUT_D0_D1_D2;


%}

/************************************************************************/
/*                        typemap code for IN arguments                 */
/************************************************************************/
%{                                                                        
PyArrayObject* IN_in(PyObject* source, char* basetype_string,             
                             int** target_dims, int dims)                 
{                                                                         
    PyArrayObject *a_obj;                                                 
    char ar_type = char_to_numtype(basetype_string[0]);                   
    a_obj = (PyArrayObject*) PyArray_ContiguousFromObject(source,ar_type, 
                                                             dims,dims);  
    if (a_obj == NULL)                                                    
    {                                                                     
        //PyArray Contiguous From Object will set the error value.        
    	return NULL;                                                      
    }                                                                     
    for(int i = 0; i < dims;i++)                                          
    {                                                                     
        *(target_dims[i]) = a_obj->dimensions[i];                         
    }                                                                     
    return a_obj;                                                         
}                                                                         
                                                                          
%}                                                                        
%typemap(python,freearg) DECREF {  Py_XDECREF($arg); }                    
    
%typemap(python,in) IN_D0 *
{
    int* targ_dims[1] = {_d0};
    PyArrayObject* a_obj = IN_in($source,"$basetype",targ_dims,1);
    if (a_obj == NULL) return NULL;
    $target = ($type) a_obj->data;
    $source = (PyObject*)a_obj;
}

%typemap(python,freearg) IN_D0 * = DECREF;
    
%typemap(python,in) IN_D1 *
{
    int* targ_dims[1] = {_d1};
    PyArrayObject* a_obj = IN_in($source,"$basetype",targ_dims,1);
    if (a_obj == NULL) return NULL;
    $target = ($type) a_obj->data;
    $source = (PyObject*)a_obj;
}

%typemap(python,freearg) IN_D1 * = DECREF;
    
%typemap(python,in) IN_D2 *
{
    int* targ_dims[1] = {_d2};
    PyArrayObject* a_obj = IN_in($source,"$basetype",targ_dims,1);
    if (a_obj == NULL) return NULL;
    $target = ($type) a_obj->data;
    $source = (PyObject*)a_obj;
}

%typemap(python,freearg) IN_D2 * = DECREF;
    
%typemap(python,in) IN_D0_D1 *
{
    int* targ_dims[2] = {_d0,_d1};
    PyArrayObject* a_obj = IN_in($source,"$basetype",targ_dims,2);
    if (a_obj == NULL) return NULL;
    $target = ($type) a_obj->data;
    $source = (PyObject*)a_obj;
}

%typemap(python,freearg) IN_D0_D1 * = DECREF;
    
%typemap(python,in) IN_D0_D2 *
{
    int* targ_dims[2] = {_d0,_d2};
    PyArrayObject* a_obj = IN_in($source,"$basetype",targ_dims,2);
    if (a_obj == NULL) return NULL;
    $target = ($type) a_obj->data;
    $source = (PyObject*)a_obj;
}

%typemap(python,freearg) IN_D0_D2 * = DECREF;
    
%typemap(python,in) IN_D1_D2 *
{
    int* targ_dims[2] = {_d1,_d2};
    PyArrayObject* a_obj = IN_in($source,"$basetype",targ_dims,2);
    if (a_obj == NULL) return NULL;
    $target = ($type) a_obj->data;
    $source = (PyObject*)a_obj;
}

%typemap(python,freearg) IN_D1_D2 * = DECREF;
    
%typemap(python,in) IN_D0_D1_D2 *
{
    int* targ_dims[3] = {_d0,_d1,_d2};
    PyArrayObject* a_obj = IN_in($source,"$basetype",targ_dims,3);
    if (a_obj == NULL) return NULL;
    $target = ($type) a_obj->data;
    $source = (PyObject*)a_obj;
}

%typemap(python,freearg) IN_D0_D1_D2 * = DECREF;

/************************************************************************/
/*                  typemap code for ARGOUT arguments                   */
/************************************************************************/
%{
char* ARGOUT_check(char* basetype_string,int* dims, int dim_len)
{
    char *rdata;
    int element_size = char_to_size(basetype_string[0]);
    int tot_length = 1;
    for (int i = 0; i < dim_len; i++)
        tot_length *= dims[i];        
    rdata = (char*)malloc(tot_length*element_size);
    if(rdata == NULL)
	{
	    PyErr_SetString(PyExc_MemoryError, "can't allocate memory for output array for arg$argnum");
	    return NULL;
	}	
    return rdata;
}

PyObject* ARGOUT_argout(char* source, char* basetype_string, 
                                int* dims, int dim_len)
{
    PyArrayObject *res;
    char array_type = char_to_numtype(basetype_string[0]);
    res = (PyArrayObject *)PyArray_FromDimsAndData(dim_len, dims, 
                                                   array_type,source);
    if(res == NULL)
    {
        //PyErr_SetString(PyExc_ValueError, "error converting internal data to array");
    	return NULL;
    }
    res->flags |= NPY_OWNDATA; // we want the array to deallocate mem when it is finished.
    // stick result in the output tuple (target).
    // Need to think about generality of this one...
    return (PyObject *) res;
}
%}

%typemap(python, ignore) ARGOUT_D0 * {}
%typemap(python, check) ARGOUT_D0 *
{
    int dim_len = 1;
    int dims[1] = {*_d0};
    $target = ($type) ARGOUT_check("$basetype",dims,dim_len);
    if ($target == NULL) return NULL;
}
%typemap(python, argout) ARGOUT_D0 *
{
    int dim_len = 1;
    int dims[1] = {*_d0};
    $target = ARGOUT_argout( (char*) $source,"$basetype",
                                     dims, dim_len);
    if ($target == NULL) return NULL;
}

%typemap(python, ignore) ARGOUT_D1 * {}
%typemap(python, check) ARGOUT_D1 *
{
    int dim_len = 1;
    int dims[1] = {*_d1};
    $target = ($type) ARGOUT_check("$basetype",dims,dim_len);
    if ($target == NULL) return NULL;
}
%typemap(python, argout) ARGOUT_D1 *
{
    int dim_len = 1;
    int dims[1] = {*_d1};
    $target = ARGOUT_argout( (char*) $source,"$basetype",
                                     dims, dim_len);
    if ($target == NULL) return NULL;
}

%typemap(python, ignore) ARGOUT_D2 * {}
%typemap(python, check) ARGOUT_D2 *
{
    int dim_len = 1;
    int dims[1] = {*_d2};
    $target = ($type) ARGOUT_check("$basetype",dims,dim_len);
    if ($target == NULL) return NULL;
}
%typemap(python, argout) ARGOUT_D2 *
{
    int dim_len = 1;
    int dims[1] = {*_d2};
    $target = ARGOUT_argout( (char*) $source,"$basetype",
                                     dims, dim_len);
    if ($target == NULL) return NULL;
}

%typemap(python, ignore) ARGOUT_D0_D1 * {}
%typemap(python, check) ARGOUT_D0_D1 *
{
    int dim_len = 2;
    int dims[2] = {*_d0,*_d1};
    $target = ($type) ARGOUT_check("$basetype",dims,dim_len);
    if ($target == NULL) return NULL;
}
%typemap(python, argout) ARGOUT_D0_D1 *
{
    int dim_len = 2;
    int dims[2] = {*_d0,*_d1};
    $target = ARGOUT_argout( (char*) $source,"$basetype",
                                     dims, dim_len);
    if ($target == NULL) return NULL;
}

%typemap(python, ignore) ARGOUT_D0_D2 * {}
%typemap(python, check) ARGOUT_D0_D2 *
{
    int dim_len = 2;
    int dims[2] = {*_d0,*_d2};
    $target = ($type) ARGOUT_check("$basetype",dims,dim_len);
    if ($target == NULL) return NULL;
}
%typemap(python, argout) ARGOUT_D0_D2 *
{
    int dim_len = 2;
    int dims[2] = {*_d0,*_d2};
    $target = ARGOUT_argout( (char*) $source,"$basetype",
                                     dims, dim_len);
    if ($target == NULL) return NULL;
}

%typemap(python, ignore) ARGOUT_D1_D2 * {}
%typemap(python, check) ARGOUT_D1_D2 *
{
    int dim_len = 2;
    int dims[2] = {*_d1,*_d2};
    $target = ($type) ARGOUT_check("$basetype",dims,dim_len);
    if ($target == NULL) return NULL;
}
%typemap(python, argout) ARGOUT_D1_D2 *
{
    int dim_len = 2;
    int dims[2] = {*_d1,*_d2};
    $target = ARGOUT_argout( (char*) $source,"$basetype",
                                     dims, dim_len);
    if ($target == NULL) return NULL;
}

%typemap(python, ignore) ARGOUT_D0_D1_D2 * {}
%typemap(python, check) ARGOUT_D0_D1_D2 *
{
    int dim_len = 3;
    int dims[3] = {*_d0,*_d1,*_d2};
    $target = ($type) ARGOUT_check("$basetype",dims,dim_len);
    if ($target == NULL) return NULL;
}
%typemap(python, argout) ARGOUT_D0_D1_D2 *
{
    int dim_len = 3;
    int dims[3] = {*_d0,*_d1,*_d2};
    $target = ARGOUT_argout( (char*) $source,"$basetype",
                                     dims, dim_len);
    if ($target == NULL) return NULL;
}

/************************************************************************/
/*             typemap code for ARGOUT_TUPLE arguments                  */
/************************************************************************/

%typemap(python, ignore) ARGOUT_TUPLE_D0 * = ARGOUT_D0 *;
%typemap(python, check) ARGOUT_TUPLE_D0 * = ARGOUT_D0 *;
%typemap(python, argout) ARGOUT_TUPLE_D0 *
{
    int dim_len = 1;
    int dims[1] = {*_d0};
    PyObject * res;
    res = ARGOUT_argout( (char*) $source,"$basetype",
                                     dims, dim_len);
    if ($target == NULL) 
        return NULL;
    $target = t_output_helper($target, res);
}  

%typemap(python, ignore) ARGOUT_TUPLE_D1 * = ARGOUT_D1 *;
%typemap(python, check) ARGOUT_TUPLE_D1 * = ARGOUT_D1 *;
%typemap(python, argout) ARGOUT_TUPLE_D1 *
{
    int dim_len = 1;
    int dims[1] = {*_d1};
    PyObject * res;
    res = ARGOUT_argout( (char*) $source,"$basetype",
                                     dims, dim_len);
    if ($target == NULL) 
        return NULL;
    $target = t_output_helper($target, res);
}  

%typemap(python, ignore) ARGOUT_TUPLE_D2 * = ARGOUT_D2 *;
%typemap(python, check) ARGOUT_TUPLE_D2 * = ARGOUT_D2 *;
%typemap(python, argout) ARGOUT_TUPLE_D2 *
{
    int dim_len = 1;
    int dims[1] = {*_d2};
    PyObject * res;
    res = ARGOUT_argout( (char*) $source,"$basetype",
                                     dims, dim_len);
    if ($target == NULL) 
        return NULL;
    $target = t_output_helper($target, res);
}  

%typemap(python, ignore) ARGOUT_TUPLE_D0_D1 * = ARGOUT_D0_D1 *;
%typemap(python, check) ARGOUT_TUPLE_D0_D1 * = ARGOUT_D0_D1 *;
%typemap(python, argout) ARGOUT_TUPLE_D0_D1 *
{
    int dim_len = 2;
    int dims[2] = {*_d0,*_d1};
    PyObject * res;
    res = ARGOUT_argout( (char*) $source,"$basetype",
                                     dims, dim_len);
    if ($target == NULL) 
        return NULL;
    $target = t_output_helper($target, res);
}  

%typemap(python, ignore) ARGOUT_TUPLE_D0_D2 * = ARGOUT_D0_D2 *;
%typemap(python, check) ARGOUT_TUPLE_D0_D2 * = ARGOUT_D0_D2 *;
%typemap(python, argout) ARGOUT_TUPLE_D0_D2 *
{
    int dim_len = 2;
    int dims[2] = {*_d0,*_d2};
    PyObject * res;
    res = ARGOUT_argout( (char*) $source,"$basetype",
                                     dims, dim_len);
    if ($target == NULL) 
        return NULL;
    $target = t_output_helper($target, res);
}  

%typemap(python, ignore) ARGOUT_TUPLE_D1_D2 * = ARGOUT_D1_D2 *;
%typemap(python, check) ARGOUT_TUPLE_D1_D2 * = ARGOUT_D1_D2 *;
%typemap(python, argout) ARGOUT_TUPLE_D1_D2 *
{
    int dim_len = 2;
    int dims[2] = {*_d1,*_d2};
    PyObject * res;
    res = ARGOUT_argout( (char*) $source,"$basetype",
                                     dims, dim_len);
    if ($target == NULL) 
        return NULL;
    $target = t_output_helper($target, res);
}  

%typemap(python, ignore) ARGOUT_TUPLE_D0_D1_D2 * = ARGOUT_D0_D1_D2 *;
%typemap(python, check) ARGOUT_TUPLE_D0_D1_D2 * = ARGOUT_D0_D1_D2 *;
%typemap(python, argout) ARGOUT_TUPLE_D0_D1_D2 *
{
    int dim_len = 3;
    int dims[3] = {*_d0,*_d1,*_d2};
    PyObject * res;
    res = ARGOUT_argout( (char*) $source,"$basetype",
                                     dims, dim_len);
    if ($target == NULL) 
        return NULL;
    $target = t_output_helper($target, res);
}  

/************************************************************************/
/*                   typemap code for OUT arguments                     */
/************************************************************************/

%typemap(python, out) OUT_D0 *
{
    // identical to  typemap(python,argout) ARGOUT__D0 *;
    int dim_len = 1;
    int dims[1] = {*_d0};
    $target = ARGOUT_argout( (char*) $source,"$basetype",
                                     dims, dim_len);
    if ($target == NULL) return NULL;
}

%typemap(python, out) OUT_D1 *
{
    // identical to  typemap(python,argout) ARGOUT__D1 *;
    int dim_len = 1;
    int dims[1] = {*_d1};
    $target = ARGOUT_argout( (char*) $source,"$basetype",
                                     dims, dim_len);
    if ($target == NULL) return NULL;
}

%typemap(python, out) OUT_D2 *
{
    // identical to  typemap(python,argout) ARGOUT__D2 *;
    int dim_len = 1;
    int dims[1] = {*_d2};
    $target = ARGOUT_argout( (char*) $source,"$basetype",
                                     dims, dim_len);
    if ($target == NULL) return NULL;
}

%typemap(python, out) OUT_D0_D1 *
{
    // identical to  typemap(python,argout) ARGOUT__D0_D1 *;
    int dim_len = 2;
    int dims[2] = {*_d0,*_d1};
    $target = ARGOUT_argout( (char*) $source,"$basetype",
                                     dims, dim_len);
    if ($target == NULL) return NULL;
}

%typemap(python, out) OUT_D0_D2 *
{
    // identical to  typemap(python,argout) ARGOUT__D0_D2 *;
    int dim_len = 2;
    int dims[2] = {*_d0,*_d2};
    $target = ARGOUT_argout( (char*) $source,"$basetype",
                                     dims, dim_len);
    if ($target == NULL) return NULL;
}

%typemap(python, out) OUT_D1_D2 *
{
    // identical to  typemap(python,argout) ARGOUT__D1_D2 *;
    int dim_len = 2;
    int dims[2] = {*_d1,*_d2};
    $target = ARGOUT_argout( (char*) $source,"$basetype",
                                     dims, dim_len);
    if ($target == NULL) return NULL;
}

%typemap(python, out) OUT_D0_D1_D2 *
{
    // identical to  typemap(python,argout) ARGOUT__D0_D1_D2 *;
    int dim_len = 3;
    int dims[3] = {*_d0,*_d1,*_d2};
    $target = ARGOUT_argout( (char*) $source,"$basetype",
                                     dims, dim_len);
    if ($target == NULL) return NULL;
}

%typemap(python, ignore) int DIM0(int* _d0)
{ _d0 = &$target; }
%typemap(python, ignore) int DIM1(int* _d1)
{ _d1 = &$target; }
%typemap(python, ignore) int DIM2(int* _d2)
{ _d2 = &$target; }

%typemap(python, in) int IN_DIM0(int* _d0)
{
    $target = (int) PyInt_AsLong($source);
    _d0 = &$target;
}
%typemap(python, in) int IN_DIM1(int* _d1)
{
    $target = (int) PyInt_AsLong($source);
    _d1 = &$target;
}
%typemap(python, in) int IN_DIM2(int* _d2)
{
    $target = (int) PyInt_AsLong($source);
    _d2 = &$target;
}



%apply IN_D0 * {int_IN_D0 *,float_IN_D0 *,double_IN_D0 *};
%apply IN_D1 * {int_IN_D1 *,float_IN_D1 *,double_IN_D1 *};
%apply IN_D2 * {int_IN_D2 *,float_IN_D2 *,double_IN_D2 *};
%apply IN_D0_D1 * {int_IN_D0_D1 *,float_IN_D0_D1 *,double_IN_D0_D1 *};
%apply IN_D0_D2 * {int_IN_D0_D2 *,float_IN_D0_D2 *,double_IN_D0_D2 *};
%apply IN_D1_D2 * {int_IN_D1_D2 *,float_IN_D1_D2 *,double_IN_D1_D2 *};
%apply IN_D0_D1_D2 * {int_IN_D0_D1_D2 *,float_IN_D0_D1_D2 *,double_IN_D0_D1_D2 *};


%apply ARGOUT_D0 * {int_ARGOUT_D0 *,float_ARGOUT_D0 *,double_ARGOUT_D0 *};
%apply ARGOUT_D1 * {int_ARGOUT_D1 *,float_ARGOUT_D1 *,double_ARGOUT_D1 *};
%apply ARGOUT_D2 * {int_ARGOUT_D2 *,float_ARGOUT_D2 *,double_ARGOUT_D2 *};
%apply ARGOUT_D0_D1 * {int_ARGOUT_D0_D1 *,float_ARGOUT_D0_D1 *,double_ARGOUT_D0_D1 *};
%apply ARGOUT_D0_D2 * {int_ARGOUT_D0_D2 *,float_ARGOUT_D0_D2 *,double_ARGOUT_D0_D2 *};
%apply ARGOUT_D1_D2 * {int_ARGOUT_D1_D2 *,float_ARGOUT_D1_D2 *,double_ARGOUT_D1_D2 *};
%apply ARGOUT_D0_D1_D2 * {int_ARGOUT_D0_D1_D2 *,float_ARGOUT_D0_D1_D2 *,double_ARGOUT_D0_D1_D2 *};


%apply ARGOUT_TUPLE_D0 * {int_ARGOUT_TUPLE_D0 *,float_ARGOUT_TUPLE_D0 *,double_ARGOUT_TUPLE_D0 *};
%apply ARGOUT_TUPLE_D1 * {int_ARGOUT_TUPLE_D1 *,float_ARGOUT_TUPLE_D1 *,double_ARGOUT_TUPLE_D1 *};
%apply ARGOUT_TUPLE_D2 * {int_ARGOUT_TUPLE_D2 *,float_ARGOUT_TUPLE_D2 *,double_ARGOUT_TUPLE_D2 *};
%apply ARGOUT_TUPLE_D0_D1 * {int_ARGOUT_TUPLE_D0_D1 *,float_ARGOUT_TUPLE_D0_D1 *,double_ARGOUT_TUPLE_D0_D1 *};
%apply ARGOUT_TUPLE_D0_D2 * {int_ARGOUT_TUPLE_D0_D2 *,float_ARGOUT_TUPLE_D0_D2 *,double_ARGOUT_TUPLE_D0_D2 *};
%apply ARGOUT_TUPLE_D1_D2 * {int_ARGOUT_TUPLE_D1_D2 *,float_ARGOUT_TUPLE_D1_D2 *,double_ARGOUT_TUPLE_D1_D2 *};
%apply ARGOUT_TUPLE_D0_D1_D2 * {int_ARGOUT_TUPLE_D0_D1_D2 *,float_ARGOUT_TUPLE_D0_D1_D2 *,double_ARGOUT_TUPLE_D0_D1_D2 *};


%apply OUT_D0 * {int_OUT_D0 *,float_OUT_D0 *,double_OUT_D0 *};
%apply OUT_D1 * {int_OUT_D1 *,float_OUT_D1 *,double_OUT_D1 *};
%apply OUT_D2 * {int_OUT_D2 *,float_OUT_D2 *,double_OUT_D2 *};
%apply OUT_D0_D1 * {int_OUT_D0_D1 *,float_OUT_D0_D1 *,double_OUT_D0_D1 *};
%apply OUT_D0_D2 * {int_OUT_D0_D2 *,float_OUT_D0_D2 *,double_OUT_D0_D2 *};
%apply OUT_D1_D2 * {int_OUT_D1_D2 *,float_OUT_D1_D2 *,double_OUT_D1_D2 *};
%apply OUT_D0_D1_D2 * {int_OUT_D0_D1_D2 *,float_OUT_D0_D1_D2 *,double_OUT_D0_D1_D2 *};


