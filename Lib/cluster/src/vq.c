/*
 * vim:syntax=c
 */
#include <stddef.h>
#include <math.h>

/*
 * results is put into code, which contains initially the initial code
 *
 * mdist and code should have at least n elements
 */
const static double rbig = 1e100;


static int float_vq_1d(const float *in, int n, 
    const float *init, int ncode, 
    int *code, float *mdist)
{
    int i, j;
    float m, d;

    for (i = 0; i < n; ++i) {
        m = (float)rbig;
        /* Compute the minimal distance for obsvervation i */
        for (j = 0; j < ncode; ++j) {
            d = (in[i] - init[j]);
            d *= d;
            if ( d < m) {
                m = d;
            }
        }
        mdist[i] = m;
        code[i] = j;
    }
    return 0;
}

static int float_vq_obs(const float *obs,
    float *code_book, int Ncodes, int Nfeatures,
       int* code, float *lowest_dist)
{
	int i,j,k=0;
	float dist, diff;

	*lowest_dist = (float) rbig;
	for(i = 0; i < Ncodes; i++) {
		dist = 0;
		for(j=0; j < Nfeatures; j++) {
			diff = code_book[k] - obs[j];
			dist += diff*diff;
			k++;
		}
		dist = (float)sqrt(dist);
		if (dist < *lowest_dist) {
			*code = i;
			*lowest_dist = dist;
		}
	}

    return 0;
}

int float_tvq(
    float* obs,
    float* code_book, 
    int Nobs, int Ncodes, int Nfeatures,
    int* codes, float* lowest_dist)
{
    int i;
	for( i = 0; i < Nobs; i++) {		
		float_vq_obs(
                    &(obs[i*Nfeatures]),
                    code_book,Ncodes, Nfeatures,
                    &(codes[i]), &(lowest_dist[i]));
	}
    return 0;
}

static int double_vq_1d(const double *in, int n, 
    const double *init, int ncode, 
    int *code, double *mdist)
{
    int i, j;
    double m, d;

    for (i = 0; i < n; ++i) {
        m = (double)rbig;
        /* Compute the minimal distance for obsvervation i */
        for (j = 0; j < ncode; ++j) {
            d = (in[i] - init[j]);
            d *= d;
            if ( d < m) {
                m = d;
            }
        }
        mdist[i] = m;
        code[i] = j;
    }
    return 0;
}

static int double_vq_obs(const double *obs,
    double *code_book, int Ncodes, int Nfeatures,
       int* code, double *lowest_dist)
{
	int i,j,k=0;
	double dist, diff;

	*lowest_dist = (double) rbig;
	for(i = 0; i < Ncodes; i++) {
		dist = 0;
		for(j=0; j < Nfeatures; j++) {
			diff = code_book[k] - obs[j];
			dist += diff*diff;
			k++;
		}
		dist = (double)sqrt(dist);
		if (dist < *lowest_dist) {
			*code = i;
			*lowest_dist = dist;
		}
	}

    return 0;
}

int double_tvq(
    double* obs,
    double* code_book, 
    int Nobs, int Ncodes, int Nfeatures,
    int* codes, double* lowest_dist)
{
    int i;
	for( i = 0; i < Nobs; i++) {		
		double_vq_obs(
                    &(obs[i*Nfeatures]),
                    code_book,Ncodes, Nfeatures,
                    &(codes[i]), &(lowest_dist[i]));
	}
    return 0;
}

