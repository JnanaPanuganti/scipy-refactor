#!/usr/bin/env python
# Usage:
#   In the parent directory run
#     python setup_linalg.py build --build-platlib=.
#     python -c 'import linalg;linalg.test(1)'
#
# Created by: Pearu Peterson, March 2002
#
""" Test functions for linalg.basic module

"""
"""
Bugs:
1) solve.check_random_sym_complex fails if a is complex
   and transpose(a) = conjugate(a) (a is Hermitian).
"""

import Numeric
from Numeric import arange, add, array

from scipy_base.testing import rand
def random(size):
    return rand(*size)

import os,sys
d = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0,d)
from __init__ import solve,inv,det,lstsq, toeplitz, hankel, tri, triu, tril
del sys.path[0]

from scipy_base.testing import assert_array_almost_equal, assert_equal
from scipy_base.testing import assert_almost_equal, assert_array_equal
from scipy_base.testing import ScipyTestCase
import unittest

def get_mat(n):
    data = arange(n)
    data = add.outer(data,data)
    return data

class test_solve(ScipyTestCase):

    def check_simple(self):
        a = [[1,20],[-30,4]]
        for b in ([[1,0],[0,1]],[1,0],
                  [[2,1],[-30,4]]):
            x = solve(a,b)
            assert_array_almost_equal(Numeric.matrixmultiply(a,x),b)
        
    def check_simple_sym(self):
        a = [[2,3],[3,5]]
        for lower in [0,1]:
            for b in ([[1,0],[0,1]],[1,0]):
                x = solve(a,b,sym_pos=1,lower=lower)
                assert_array_almost_equal(Numeric.matrixmultiply(a,x),b)

    def check_simple_sym_complex(self):
        a = [[5,2],[2,4]]
        for b in [[1j,0],
                  [[1j,1j],
                   [0,2]],
                  ]:
            x = solve(a,b,sym_pos=1)
            assert_array_almost_equal(Numeric.matrixmultiply(a,x),b)

    def check_random(self):

        n = 20
        a = random([n,n])
        for i in range(n): a[i,i] = 20*(.1+a[i,i])
        for i in range(4):
            b = random([n,3])
            x = solve(a,b)
            assert_array_almost_equal(Numeric.matrixmultiply(a,x),b)

    def check_random_complex(self):
        n = 20
        a = random([n,n]) + 1j * random([n,n])
        for i in range(n): a[i,i] = 20*(.1+a[i,i])
        for i in range(2):
            b = random([n,3])
            x = solve(a,b)
            assert_array_almost_equal(Numeric.matrixmultiply(a,x),b)

    def check_random_sym(self):
        n = 20
        a = random([n,n])
        for i in range(n):
            a[i,i] = abs(20*(.1+a[i,i]))
            for j in range(i):
                a[i,j] = a[j,i]
        for i in range(4):
            b = random([n])
            x = solve(a,b,sym_pos=1)
            assert_array_almost_equal(Numeric.matrixmultiply(a,x),b)

    def check_random_sym_complex(self):
        n = 20
        a = random([n,n])
        #a  = a + 1j*random([n,n]) # XXX: with this the accuracy will be very low
        for i in range(n):
            a[i,i] = abs(20*(.1+a[i,i]))
            for j in range(i):
                a[i,j] = Numeric.conjugate(a[j,i])
        b = random([n])+2j*random([n])
        for i in range(2):
            x = solve(a,b,sym_pos=1)
            assert_array_almost_equal(Numeric.matrixmultiply(a,x),b)

    def bench_random(self):
        import LinearAlgebra
        Numeric_solve = LinearAlgebra.solve_linear_equations
        print
        print '      Solving system of linear equations'
        print '      =================================='

        print '      |    contiguous     |   non-contiguous '
        print '----------------------------------------------'
        print ' size |  scipy  | Numeric |  scipy  | Numeric'
        
        for size,repeat in [(20,1000),(100,150),(500,2),(1000,1)][:-1]:
            repeat *= 2
            print '%5s' % size,
            sys.stdout.flush()
            
            a = random([size,size])
            # larger diagonal ensures non-singularity:
            for i in range(size): a[i,i] = 10*(.1+a[i,i])
            b = random([size])

            print '| %6.2f ' % self.measure('solve(a,b)',repeat),
            sys.stdout.flush()

            print '| %6.2f ' % self.measure('Numeric_solve(a,b)',repeat),
            sys.stdout.flush()
                        
            a = a[-1::-1,-1::-1] # turn into a non-contiguous array
            assert not a.iscontiguous()

            print '| %6.2f ' % self.measure('solve(a,b)',repeat),
            sys.stdout.flush()

            print '| %6.2f ' % self.measure('Numeric_solve(a,b)',repeat),
            sys.stdout.flush()

            print '   (secs for %s calls)' % (repeat)


class test_inv(ScipyTestCase):

    def check_simple(self):
        a = [[1,2],[3,4]]
        a_inv = inv(a)
        assert_array_almost_equal(Numeric.matrixmultiply(a,a_inv),
                                  [[1,0],[0,1]])
    def check_random(self):
        n = 20
        for i in range(4):
            a = random([n,n])
            for i in range(n): a[i,i] = 20*(.1+a[i,i])
            a_inv = inv(a)
            assert_array_almost_equal(Numeric.matrixmultiply(a,a_inv),
                                      Numeric.identity(n))
    def check_simple_complex(self):
        a = [[1,2],[3,4j]]
        a_inv = inv(a)
        assert_array_almost_equal(Numeric.matrixmultiply(a,a_inv),
                                  [[1,0],[0,1]])

    def check_random_complex(self):
        n = 20
        for i in range(4):
            a = random([n,n])+2j*random([n,n])
            for i in range(n): a[i,i] = 20*(.1+a[i,i])
            a_inv = inv(a)
            assert_array_almost_equal(Numeric.matrixmultiply(a,a_inv),
                                      Numeric.identity(n))


    def bench_random(self):
        import LinearAlgebra
        Numeric_inv = LinearAlgebra.inverse
        print
        print '           Finding matrix inverse'
        print '      =================================='
        print '      |    contiguous     |   non-contiguous '
        print '----------------------------------------------'
        print ' size |  scipy  | Numeric |  scipy  | Numeric'
        
        for size,repeat in [(20,1000),(100,150),(500,2),(1000,1)][:-1]:
            repeat *= 2
            print '%5s' % size,
            sys.stdout.flush()
            
            a = random([size,size])
            # large diagonal ensures non-singularity:
            for i in range(size): a[i,i] = 10*(.1+a[i,i])

            print '| %6.2f ' % self.measure('inv(a)',repeat),
            sys.stdout.flush()

            print '| %6.2f ' % self.measure('Numeric_inv(a)',repeat),
            sys.stdout.flush()
                        
            a = a[-1::-1,-1::-1] # turn into a non-contiguous array
            assert not a.iscontiguous()

            print '| %6.2f ' % self.measure('inv(a)',repeat),
            sys.stdout.flush()

            print '| %6.2f ' % self.measure('Numeric_inv(a)',repeat),
            sys.stdout.flush()

            print '   (secs for %s calls)' % (repeat)


class test_det(ScipyTestCase):

    def check_simple(self):
        a = [[1,2],[3,4]]
        a_det = det(a)
        assert_almost_equal(a_det,-2.0)

    def check_simple_complex(self):
        a = [[1,2],[3,4j]]
        a_det = det(a)
        assert_almost_equal(a_det,-6+4j)

    def check_random(self):
        import LinearAlgebra
        Numeric_det = LinearAlgebra.determinant
        n = 20
        for i in range(4):
            a = random([n,n])
            d1 = det(a)
            d2 = Numeric_det(a)
            assert_almost_equal(d1,d2)

    def check_random_complex(self):
        import LinearAlgebra
        Numeric_det = LinearAlgebra.determinant
        n = 20
        for i in range(4):
            a = random([n,n]) + 2j*random([n,n])
            d1 = det(a)
            d2 = Numeric_det(a)
            assert_almost_equal(d1,d2)

    def bench_random(self):
        import LinearAlgebra
        Numeric_det = LinearAlgebra.determinant
        print
        print '           Finding matrix determinant'
        print '      =================================='
        print '      |    contiguous     |   non-contiguous '
        print '----------------------------------------------'
        print ' size |  scipy  | Numeric |  scipy  | Numeric'
        
        for size,repeat in [(20,1000),(100,150),(500,2),(1000,1)][:-1]:
            repeat *= 2
            print '%5s' % size,
            sys.stdout.flush()
            
            a = random([size,size])

            print '| %6.2f ' % self.measure('det(a)',repeat),
            sys.stdout.flush()

            print '| %6.2f ' % self.measure('Numeric_det(a)',repeat),
            sys.stdout.flush()
                        
            a = a[-1::-1,-1::-1] # turn into a non-contiguous array
            assert not a.iscontiguous()

            print '| %6.2f ' % self.measure('det(a)',repeat),
            sys.stdout.flush()

            print '| %6.2f ' % self.measure('Numeric_det(a)',repeat),
            sys.stdout.flush()

            print '   (secs for %s calls)' % (repeat)


def direct_lstsq(a,b):
    a1 = Numeric.matrixmultiply(Numeric.transpose(a),a)
    b1 = Numeric.matrixmultiply(Numeric.transpose(a),b)
    return solve(a1,b1)

class test_lstsq(ScipyTestCase):

    def check_simple_exact(self):
        a = [[1,20],[-30,4]]
        for b in ([[1,0],[0,1]],[1,0],
                  [[2,1],[-30,4]]):
            x = lstsq(a,b)[0]
            assert_array_almost_equal(Numeric.matrixmultiply(a,x),b)

    def check_simple_overdet(self):
        a = [[1,2],[4,5],[3,4]]
        b = [1,2,3]
        x,res,r,s = lstsq(a,b)
        #XXX: check defintion of res
        assert_array_almost_equal(x,direct_lstsq(a,b))

    def check_simple_underdet(self):
        a = [[1,2,3],[4,5,6]]
        b = [1,2]
        x,res,r,s = lstsq(a,b)
        #XXX: need independent check
        assert_array_almost_equal(x,[[-0.05555556],[0.11111111],[0.27777778]])

    def check_random_exact(self):

        n = 20
        a = random([n,n])
        for i in range(n): a[i,i] = 20*(.1+a[i,i])
        for i in range(4):
            b = random([n,3])
            x = lstsq(a,b)[0]
            assert_array_almost_equal(Numeric.matrixmultiply(a,x),b)

    def check_random_complex_exact(self):
        n = 20
        a = random([n,n]) + 1j * random([n,n])
        for i in range(n): a[i,i] = 20*(.1+a[i,i])
        for i in range(2):
            b = random([n,3])
            x = lstsq(a,b)[0]
            assert_array_almost_equal(Numeric.matrixmultiply(a,x),b)

    def check_random_overdet(self):
        n = 20
        m = 15
        a = random([n,m])
        for i in range(m): a[i,i] = 20*(.1+a[i,i])
        for i in range(4):
            b = random([n,3])
            x,res,r,s = lstsq(a,b)
            assert r==m,'unexpected efficient rank'
            #XXX: check definition of res
            assert_array_almost_equal(x,direct_lstsq(a,b))

    def check_random_complex_overdet(self):
        n = 20
        m = 15
        a = random([n,m]) + 1j * random([n,m])
        for i in range(m): a[i,i] = 20*(.1+a[i,i])
        for i in range(2):
            b = random([n,3])
            x,res,r,s = lstsq(a,b)
            assert r==m,'unexpected efficient rank'
            #XXX: check definition of res
            assert_array_almost_equal(x,direct_lstsq(a,b),1e-3)
            #XXX: tolerance 1e-3 is quite large, investigate the reason

class test_tri(unittest.TestCase):
    def check_basic(self):
        assert_equal(tri(4),array([[1,0,0,0],
                                   [1,1,0,0],
                                   [1,1,1,0],
                                   [1,1,1,1]]))
        assert_equal(tri(4,typecode='f'),array([[1,0,0,0],
                                                [1,1,0,0],
                                                [1,1,1,0],
                                                [1,1,1,1]],'f'))
    def check_diag(self):
        assert_equal(tri(4,k=1),array([[1,1,0,0],
                                       [1,1,1,0],
                                       [0,1,1,1],
                                       [1,1,1,1]]))
        assert_equal(tri(4,k=-1),array([[0,0,0,0],
                                        [1,0,0,0],
                                        [1,1,0,0],
                                        [1,1,1,0]]))
    def check_2d(self):
        assert_equal(tri(4,3),array([[1,0,0],
                                     [1,1,0],
                                     [1,1,1],
                                     [1,1,1]]))
        assert_equal(tri(3,4),array([[1,0,0,0],
                                     [1,1,0,0],
                                     [1,1,1,0]]))        
    def check_diag2d(self):
        assert_equal(tri(3,4,k=2),array([[1,1,1,0],
                                         [1,1,1,1],
                                         [1,1,1,1]]))
        assert_equal(tri(4,3,k=-2),array([[0,0,0],
                                          [0,0,0],
                                          [1,0,0],
                                          [1,1,0]]))

class test_tril(unittest.TestCase):
    def check_basic(self):
        a = (100*get_mat(5)).astype('l')
        b = a.copy()
        for k in range(5):
            for l in range(k+1,5):
                b[k,l] = 0
        assert_equal(tril(a),b)

    def check_diag(self):        
        a = (100*get_mat(5)).astype('f')
        b = a.copy()
        for k in range(5):
            for l in range(k+3,5):
                b[k,l] = 0
        assert_equal(tril(a,k=2),b)
        b = a.copy()
        for k in range(5):
            for l in range(max((k-1,0)),5):
                b[k,l] = 0
        assert_equal(tril(a,k=-2),b)

class test_triu(unittest.TestCase):
    def check_basic(self):
        a = (100*get_mat(5)).astype('l')
        b = a.copy()
        for k in range(5):
            for l in range(k+1,5):
                b[l,k] = 0
        assert_equal(triu(a),b)

    def check_diag(self):        
        a = (100*get_mat(5)).astype('f')
        b = a.copy()
        for k in range(5):
            for l in range(max((k-1,0)),5):
                b[l,k] = 0
        assert_equal(triu(a,k=2),b)
        b = a.copy()
        for k in range(5):
            for l in range(k+3,5):
                b[l,k] = 0
        assert_equal(tril(a,k=-2),b)

class test_toeplitz(unittest.TestCase):
    def check_basic(self):
        y = toeplitz([1,2,3])
        assert_array_equal(y,[[1,2,3],[2,1,2],[3,2,1]])
        y = toeplitz([1,2,3],[1,4,5])
        assert_array_equal(y,[[1,4,5],[2,1,4],[3,2,1]])
        
class test_hankel(unittest.TestCase):
    def check_basic(self):
        y = hankel([1,2,3])
        assert_array_equal(y,[[1,2,3],[2,3,0],[3,0,0]])
        y = hankel([1,2,3],[3,4,5])
        assert_array_equal(y,[[1,2,3],[2,3,4],[3,4,5]])


#####################################
def test_suite(level=1):
    suites = []
    if level > 0:
        suites.append( unittest.makeSuite(test_det,'check_') )
        suites.append( unittest.makeSuite(test_solve,'check_') )
        suites.append( unittest.makeSuite(test_inv,'check_') )
        suites.append( unittest.makeSuite(test_lstsq,'check_') )
        suites.append( unittest.makeSuite(test_tri,'check_') )
        suites.append( unittest.makeSuite(test_triu,'check_') )
        suites.append( unittest.makeSuite(test_tril,'check_') )
        suites.append( unittest.makeSuite(test_toeplitz,'check_') )
        suites.append( unittest.makeSuite(test_hankel,'check_') )

    if level > 5:
        suites.append( unittest.makeSuite(test_det,'bench_') )
        suites.append( unittest.makeSuite(test_solve,'bench_') )
        suites.append( unittest.makeSuite(test_inv,'bench_') )
        suites.append( unittest.makeSuite(test_lstsq,'bench_') )

    total_suite = unittest.TestSuite(suites)
    return total_suite

def test(level=10):
    all_tests = test_suite(level)
    runner = unittest.TextTestRunner()
    runner.run(all_tests)
    return runner

if __name__ == "__main__":
    if len(sys.argv)>1:
        level = eval(sys.argv[1])
    else:
        level = 10
    test(level)
