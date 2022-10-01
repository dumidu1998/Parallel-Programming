# Parallel-Programming

### Comparision between sequential, Pthread and OpenMP parallel programming 

`
git update-index --chmod=+x your_script.sh
`

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

#### Check on the Action tab for results in different matrix sizes

![image](https://user-images.githubusercontent.com/50117273/193431294-caeb83c7-30a4-4af3-bf2f-df8f0bd30293.png)
