seq:
	gcc -O3 seq.c -o seq
	./seq
pthread:
	gcc -O3 pthread.c -o pthread -lpthread
	./pthread
omp:
	gcc -O3 omp.c -o omp -fopenmp
	./omp
clean: 
	$(RM) seq pthread omp
