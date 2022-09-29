# Parallel-Programming

### Comparision between sequential, Pthread and OpenMP parallel programming 

Run on Linux Terminal
#### Sequential 
`
  cc -O3 seq.c -o seq && ./seq
`

#### Pthread 
`
 cc -O3 pthread.c -o pthread -lpthread && ./pthread
`

#### OpenMp 
`
  cc -O3 omp.c -o omp -fopenmp && ./omp
`
