myProgram:power.o test-power.o
	gcc -o myProgram power.o test-power.o
power.o:power.c 
	gcc -std=gnu99 -pedantic -Wall -c power.c
test-power.c:test-power.c
	gcc -std=gnu99 -pedantic -Wall -c test-power.c
.PHONY:clean
clean:
	rm -f myProgram *.o *.c~ *.h~

