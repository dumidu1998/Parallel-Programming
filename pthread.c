#include <assert.h>
#include <math.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define RANDLIMIT 5 
#define N 10000     
#define NUMLIMIT 70.0
#define THREADS 8

void *slave(void *myid);

float a[N][N];
float b[N][N];
float c[N][N];
pthread_mutex_t mutex;

void *slave(void *myid) {
  long x, low, high;
  /*Calculate which rows to calculate by each Thread*/
  x = N / THREADS;
  low = (long)myid * x;
  high = low + x;
  int i, j, k;

  /*Calculation*/
  for (i = low; i < high; i++) {
    for (j = 0; j < N; j++) {
      c[i][j] = 0.0;
      for (k = 0; k < N; k++) {
        c[i][j] = c[i][j] + a[i][k] * b[k][j];
      }
    }
  }
}

int main(int argc, char *argv[]) {
  struct timeval start, stop;
  long i, j;
  pthread_t tid[THREADS];

  assert(N % THREADS == 0);
    printf("Pthread method Matrix multiplication of %d X %d matrix using %d threads.\n", N, N, THREADS);

  pthread_mutex_init(&mutex, NULL); /*initialize mutex*/

  /* generate mxs randomly */
  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++) {
      a[i][j] = 1 + (int)(NUMLIMIT * rand() / (RAND_MAX + 1.0));
      b[i][j] = (double)(rand() % RANDLIMIT);
    }

  gettimeofday(&start, 0);

  /*Creating Threads */
  for (i = 0; i < THREADS; i++)
    if (pthread_create(&tid[i], NULL, slave, (void *)i) != 0)
      perror("Pthread create fails");

  /*Joining Threads */
  for (i = 0; i < THREADS; i++)
    if (pthread_join(tid[i], NULL) != 0)
      perror("Pthread join fails");
  
  /*End Timing*/
  gettimeofday(&stop, 0);

  /*Print the timing*/
  fprintf(stdout, "Time Taken = %.6f seconds.\n\nn",
          (stop.tv_sec + stop.tv_usec * 1e-6) -
              (start.tv_sec + start.tv_usec * 1e-6));

  return 0;
}