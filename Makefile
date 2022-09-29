all:
	gcc  seq.c -o seq
	./seq
clean: 
	$(RM) seq
