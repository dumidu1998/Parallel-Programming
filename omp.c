#include <assert.h>
#include <math.h>
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define RANDLIMIT 5
#define N 5000
#define NUMLIMIT 70.0
#define THREADS 8

float A[N][N];
float B[N][N];
float C[N][N];

int main(int argc, char *argv[]) {

  int i, j, k;
  double elapsed;
  struct timeval tv1, tv2;
  struct timezone tz;

  omp_set_num_threads(THREADS);

  printf("OpenMp method Matrix multiplication of %d X %d matrix using %d "
         "threads.\n",
         N, N, THREADS);

  /* generate the matrixes */
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      A[i][j] = (double)rand() / (double)((unsigned)RAND_MAX);
      B[i][j] = (double)rand() / (double)((unsigned)RAND_MAX);
    }
  }

  gettimeofday(&tv1, &tz);
  /*omp multiplication */
#pragma omp parallel for private(i, j, k) shared(A, B, C)
  for (i = 0; i < N; ++i) {
    for (j = 0; j < N; ++j) {
      for (k = 0; k < N; ++k) {
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  }

  gettimeofday(&tv2, &tz);

  elapsed = (double)(tv2.tv_sec - tv1.tv_sec) +
            (double)(tv2.tv_usec - tv1.tv_usec) * 1.e-6;
  printf("Time taken = %.6f seconds.\n\n", elapsed);

  return 0;
}