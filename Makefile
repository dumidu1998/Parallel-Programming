all:
	gcc  seq.c -o seq
	./seq
	gcc -O3 pthread.c -o pthread -lpthread
	./pthread
	gcc -O3 omp.c -o omp -fopenmp
	./omp
clean: 
	$(RM) seq
