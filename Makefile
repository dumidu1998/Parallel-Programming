all:
	gcc  seq.c -o seq
	$(RM) seq
clean: 
	$(RM) seq
