myProgram:test.o
	gcc -o myProgram test.o
test.o:test.c
	gcc -std=gnu99 -pedantic -Wall -c test.c
.PHONY:clean
clean:
	rm -f myProgram *.o *.c~
