
import sigtools
import MLab

_modedict = {'valid':0, 'same':1, 'full':2}
_boundarydict = {'fill':0, 'pad':0, 'wrap':2, 'circular':2, 'symm':1, 'symmetric':1, 'reflect':4}
                                                                            
def _valfrommode(mode):
    try:
        val = _modedict[mode]
    except KeyError:
        if val not in [0,1,2]:
            raise ValueError, "Acceptable mode flags are 'valid' (0), 'same' (1), or 'full' (2)."
        val = mode
    return val

def _bvalfromboundary(boundary):
    try:
        val = _boundarydict[boundary]
    except KeyError:
        if val not in [0,1,2]:
            raise ValueError, "Acceptable boundary flags are 'fill', 'wrap' (or 'circular'), \n  and 'symm' (or 'symmetric')."
        val = boundary << 2
    return val


def correlate(volume, kernel, mode='full'):
    """ correlate(in1, in2, mode='full')  Filtering of in1 with in2.

  Description:

     Cross-correlate in1 and in2 with the output size determined by mode.

  Inputs:

    in1 -- an N-dimensional array.
    in2 -- an array with the same number of dimensions as in1.
    mode -- a flag indicating the size of the output
            'valid'  (0): The output consists only of those elements that
                            do not rely on the zero-padding.
            'same'   (1): The output is the same size as the input centered
                            with respect to the 'full' output.
            'full'   (2): The output is the full discrete linear
                            cross-correlation of the inputs. (Default)

  Outputs:  (out,)

    out -- an N-dimensional array containing a subset of the discrete linear
           cross-correlation of in1 with in2.
 
    """
    # Code is faster if kernel is smallest array.
    volume = MLab.asarray(volume)
    kernel = MLab.asarray(kernel)
    if (MLab.product(kernel.shape) > MLab.product(volume.shape)):
        temp = kernel
        kernel = volume
        volume = temp
        del temp

    val = _valfrommode(mode)

    return sigtools._correlateND(volume, kernel, val)

def convolve(volume,kernel,mode='full'):
    """ convolve(in1, in2, mode='full')  Convolution of in1 with in2.

  Description:

     Convolve in1 and in2 with output size determined by mode.

  Inputs:

    in1 -- an N-dimensional array.
    in2 -- an array with the same number of dimensions as in1.
    mode -- a flag indicating the size of the output
            'valid'  (0): The output consists only of those elements that
                            do not rely on the zero-padding.
            'same'   (1): The output is the same size as the input centered
                            with respect to the 'full' output.
            'full'   (2): The output is the full discrete linear convolution
                            of the inputs. (Default)

  Outputs:  (out,)

    out -- an N-dimensional array containing a subset of the discrete linear
           convolution of in1 with in2.

    """
    volume = MLab.asarray(volume)
    kernel = MLab.asarray(kernel)
    if (MLab.product(kernel.shape) > MLab.product(volume.shape)):
        temp = kernel
        kernel = volume
        volume = temp
        del temp

    slice_obj = [slice(None,None,-1)]*len(kernel.shape)
    val = _valfrommode(mode)
    
    return sigtools._correlateND(volume,kernel[slice_obj],val)

def order_filter(a, domain, order):
    """
 order_filter(in, domain, rank)  Perform an order filter on in.

  Description:

    Perform an order filter on the array in.  The domain argument acts as a
    mask centered over each pixel.  The non-zero elements of domain are
    used to select elements surrounding each input pixel which are placed
    in a list.   The list is sorted, and the output for that pixel is the
    element corresponding to rank in the sorted list.
    
  Inputs:

    in -- an N-dimensional input array.
    domain -- a mask array with the same number of dimensions as in.  Each
              dimension should have an odd number of elements.
    rank -- an non-negative integer which selects the element from the
            sorted list (0 corresponds to the largest element, 1 is the
            next largest element, etc.)

  Output: (out,)

    out -- the results of the order filter in an array with the same
           shape as in.
          
    """
    domain = MLab.asarray(domain)
    size = domain.shape
    for k in range(len(size)):
        if (size[k] % 2) != 1:
            raise ValueError, "Each dimension of domain argument should have an odd number of elements."
    return sigtools._orderfilterND(a, domain, rank)
   

def medfilt(volume,kernel_size=None):
    """
 medfilt(in, kernel_size=3)  Perform a median filter on input array.

  Description:

    Apply a median filter to the input array using a local window-size
    given by kernel_size.

  Inputs:

    in -- An N-dimensional input array.
    kernel_size -- A scalar or an N-length list giving the size of the
                   median filter window in each dimension.  Elements of
                   kernel_size should be odd.  If kernel_size is a scalar,
                   then this scalar is used as the size in each dimension.

  Outputs: (out,)

    out -- An array the same size as input containing the median filtered
           result.
  
    """
    volume = MLab.asarray(volume)
    if kernel_size == None:
        kernel_size = [3] * len(volume.shape)
    kernel_size = MLab.asarray(kernel_size)
    if len(kernel_size.shape) == 0:
        kernel_size = [kernel_size.toscalar()] * len(volume.shape)
    kernel_size = MLab.asarray(kernel_size)

    for k in range(len(volume.shape)):
        if (kernel_size[k] % 2) != 1:
            raise ValueError, "Each element of kernel_size should be odd." 

    domain = MLab.ones(kernel_size)

    numels = MLab.product(kernel_size)
    order = numels/2
    return sigtools._order_filterND(volume,domain,order)


def wiener(im,mysize=None,noise=None):
    """
 wiener(in, kernel_size=3, noise_power=None)  Perform a wiener filter.

  Description:

    Apply a wiener filter to the N-dimensional array in.

  Inputs:

    in -- an N-dimensional array.
    kernel_size -- A scalar or an N-length list giving the size of the
                   median filter window in each dimension.  Elements of
                   kernel_size should be odd.  If kernel_size is a scalar,
                   then this scalar is used as the size in each dimension.
    noise -- The noise-power to use.  If None, then noise is estimated as
             the average of the local variance of the input.

  Outputs: (out,)

    out -- Wiener filtered result with the same shape as in.

    """
    im = asarray(im)
    if mysize == None:
        mysize = [3] * len(im.shape)
    mysize = MLab.asarray(mysize);

    # Estimate the local mean
    lMean = correlate(im,ones(mysize),1) / MLab.prod(mysize)

    # Estimate the local variance
    lVar = correlate(im**2,ones(mysize),1) / MLab.prod(mysize) - lMean**2

    # Estimate the noise power if needed.
    if noise==None:
        noise = MLab.mean(ravel(lVar))

    # Compute result
    # f = lMean + (maximum(0, lVar - noise) ./
    #               maximum(lVar, noise)) * (im - lMean) 
    #
    out = im - lMean
    im = lVar - noise
    im = MLab.maximum(im,0)
    lVar = MLab.maximum(lVar,noise)
    out = out / lVar
    out = out * im
    out = out + lMean

    return out

def convolve2d(in1, in2, mode='full', boundary='fill', fillvalue=0):
    """ convolve2d(in1, in2, mode='full', boundary='fill', fillvalue=0)

  Description:

     Convolve in1 and in2 with output size determined by mode and boundary
     conditions determined by boundary and fillvalue.

  Inputs:

    in1 -- a 2-dimensional array.
    in2 -- a 2-dimensional array.
    mode -- a flag indicating the size of the output
            'valid'  (0): The output consists only of those elements that
                            do not rely on the zero-padding.
            'same'   (1): The output is the same size as the input centered
                            with respect to the 'full' output.
            'full'   (2): The output is the full discrete linear convolution
                            of the inputs. (*Default*)
    boundary -- a flag indicating how to handle boundaries
                'fill' : pad input arrays with fillvalue. (*Default*)
                'wrap' : circular boundary conditions.
                'symm' : symmetrical boundary conditions.
    fillvalue -- value to fill pad input arrays with (*Default* = 0)

  Outputs:  (out,)

    out -- a 2-dimensional array containing a subset of the discrete linear
           convolution of in1 with in2.

    """
    val = _valfrommode(mode)
    bval = _bvalfromboundary(boundary)
        
    return sigtools._convolve2d(volume,kernel,1,val,bval,fillvalue)

def correlate2d():
    """ correlate2d(in1, in2, mode='full', boundary='fill', fillvalue=0)

  Description:

     Cross correlate in1 and in2 with output size determined by mode
     and boundary conditions determined by boundary and fillvalue.

  Inputs:

    in1 -- a 2-dimensional array.
    in2 -- a 2-dimensional array.
    mode -- a flag indicating the size of the output
            'valid'  (0): The output consists only of those elements that
                            do not rely on the zero-padding.
            'same'   (1): The output is the same size as the input centered
                            with respect to the 'full' output.
            'full'   (2): The output is the full discrete linear convolution
                            of the inputs. (*Default*)
    boundary -- a flag indicating how to handle boundaries
                'fill' : pad input arrays with fillvalue. (*Default*)
                'wrap' : circular boundary conditions.
                'symm' : symmetrical boundary conditions.
    fillvalue -- value to fill pad input arrays with (*Default* = 0)

  Outputs:  (out,)

    out -- a 2-dimensional array containing a subset of the discrete linear
           cross-correlation of in1 with in2.

    """
    val = _valfrommode(mode)
    bval = _bvalfromboundary(boundary)
        
    return sigtools._convolve2d(volume,kernel,0,val,bval,fillvalue)    

def medfilt2d(input, kernel_size=3):
    """
 medfilt2d(in, kernel_size=3)  Perform a median filter on input array.

  Description:

    Apply a median filter to the input array using a local window-size
    given by kernel_size (must be odd).

  Inputs:

    in -- An 2 dimensional input array.
    kernel_size -- A scalar or an length-2 list giving the size of the
                   median filter window in each dimension.  Elements of
                   kernel_size should be odd.  If kernel_size is a scalar,
                   then this scalar is used as the size in each dimension.

  Outputs: (out,)

    out -- An array the same size as input containing the median filtered
           result.
    """
    image = MLab.asarray(input)
    if kernel_size == None:
        kernel_size = [3] * 2
    kernel_size = MLab.asarray(kernel_size)
    if len(kernel_size.shape) == 0:
        kernel_size = [kernel_size.toscalar()] * 2
    kernel_size = MLab.asarray(kernel_size)

    for size in kernel_size:
        if (size % 2) != 1:
            raise ValueError, "Each element of kernel_size should be odd." 

    return sigtools._medfilt2d(image, kernel_size)

def remez(numtaps, bands, desired, weight=None, Hz=1, type='bandpass',
          maxiter=25, grid_density=16):
    """
 remez(numtaps, bands, desired, weight=None, Hz=1, type='bandpass',
       maxiter=25, grid_density=16)

  Description:

    Calculate the filter-coefficients for the finite impulse response
    (FIR) filter whose transfer function minimizes the maximum error
    between the desired gain and the realized gain in the specified bands
    using the remez exchange algorithm.

  Inputs:

    numtaps -- The desired number of taps in the filter.
    bands -- A montonic sequence containing the band edges.  All elements
             must be non-negative and less than 1/2 the sampling frequency
             as given by Hz.
    desired -- A sequency half the size of bands containing the desired gain
               in each of the specified bands
    weight -- A relative weighting to give to each band region.
    type --- The type of filter:
             'bandpass' : flat response in bands.
             'differentiator' : frequency proportional response in bands.

  Outputs: (out,)

    out -- A rank-1 array containing the coefficients of the optimal
           (in a minimax sense) filter.
    
    """
    # Convert type
    try:
        tnum = {'bandpass':1, 'differentiator':2}[type]
    except KeyError:
        raise ValueError, "Type must be 'bandpass', or 'differentiator'"

    # Convert weight
    if weight is None:
        weight = [1] * len(desired)

    return sigtools._remez(numtaps, bands, desired, weight, tnum, Hz,
                           maxiter, grid_density)

def lfilter(b, a, x, axis=-1, zi=None):
    """
 lfilter(b, a, x, axis=-1, zi=None)  Filter data in 1-D with an IIR or FIR filter

  Description

    Filter a data sequence, x, using a digital filter.  This works for many
    fundamental data types (including Object type).  The filter is a direct
    form II transposed implementation of the standard difference equation
    (see "Algorithm"). 

  Inputs:

    b -- The numerator coefficient vector in a 1-D sequence.
    a -- The denominator coefficient vector in a 1-D sequence.  If a[0]
         is not 1, then both a and b are normalized by a[0].
    x -- An N-dimensional input array.
    axis -- The axis of the input data array along which to apply the
            linear filter. The filter is applied to each subarray along
            this axis (*Default* = -1)
    zi -- Initial conditions for the filter delays.  It is a vector
          (or array of vectors) of length max(len(a),len(b))-1.  If
          zi=None or is not given then initial rest is assumed.

  Outputs: (y, {zf})

    y -- The output of the digital filter.
    zf -- If zi is None, this is not returned, otherwise, zf holds the
          final filter delay values.

  Algorithm:

    The filter function is implemented as a direct II transposed structure.
    This means that the filter implements

    y[n] = b[0]*x[n] + b[1]*x[n-1] + ... + b[nb]*x[n-nb]
                     - a[1]*y[n-1] + ... + a[na]*y[n-na]

    using the following difference equaitions:

    y[m] = b[0]*x[m] + z[0,m-1]
    z[0,m] = b[1]*x[m] + z[1,m-1] - a[1]*y[m]
    ...
    z[n-3,m] = b[n-2]*x[m] + z[n-2,m-1] - a[n-2]*y[m]
    z[n-2,m] = b[n-1]*x[m] - a[n-1]*y[m]

    where m is the output sample number and n=max(len(a),len(b)) is the
    model order.

    The rational transfer function describing this filter in the
    z-transform domain is
                                -1               -nb
                    b[0] + b[1]z  + ... + b[nb] z
            Y(z) = ---------------------------------- X(z)
                                -1               -na
                    a[0] + a[1]z  + ... + a[na] z
                    
    """
    if zi is None:
        return sigtools._linear_filter(b, a, x, axis)
    else:
        return sigtools._linear_filter(b, a, x, axis, zi)

def test():
    a = [3,4,5,6,5,4]
    b = [1,2,3]
    c = convolve(a,b)
    if (MLab.product(equal(c,[3,10,22,28,32,32,23,12]))==0):
        print "Error in convolve."

    f = [[3,4,5],[2,3,4],[1,2,5]]
    d = medfilt(f)
    if (MLab.product(ravel(equal(d,[[0,3,0],[2,3,3],[0,2,0]])))==0):
        print "Error in medfilt."

    g = MLab.array([[5,6,4,3],[3,5,6,2],[2,3,5,6],[1,6,9,7]],'d')
    correct = MLab.array([[2.16374269,3.2222222222, 2.8888888889, 1.6666666667],[2.666666667, 4.33333333333, 4.44444444444, 2.8888888888],[2.222222222, 4.4444444444, 5.4444444444, 4.801066874837],[1.33333333333, 3.92735042735, 6.0712560386, 5.0404040404]])
    h = wiener(g)
    if (MLab.abs(MLab.product(MLab.ravel(h-correct)))> 1e-7):
        print "Error in wiener."

    return

if __name__ == "__main__":
    test()


        
       

    




