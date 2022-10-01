#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define RANDLIMIT 5
#define N 6000
#define NUMLIMIT 70.0

float a[N][N];
float b[N][N];
float c[N][N];

int main(int argc, char *argv[]) {
  struct timeval start, stop;
  int i, j, k;

  printf("Sequential method Matrix multiplication of %d X %d matrix\n", N, N);

  /* generate the matrixes */
  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++) {
      a[i][j] = 1 + (int)(NUMLIMIT * rand() / (RAND_MAX + 1.0));
      b[i][j] = (double)(rand() % RANDLIMIT);
    }

  gettimeofday(&start, 0);

    /*Multiplying matrixes*/
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      c[i][j] = 0.0;
      for (k = 0; k < N; k++)
        c[i][j] = c[i][j] + a[i][k] * b[k][j];
    }
  }
  gettimeofday(&stop, 0);

/*Print the timing*/
  fprintf(stdout, "Time taken = %.6f seconds.\n\n",
          (stop.tv_sec + stop.tv_usec * 1e-6) -
              (start.tv_sec + start.tv_usec * 1e-6));

  return (0);
}