breaker: break.o
	gcc -o breaker break.o
break.o: break.c
	gcc -std=gnu99 -pedantic -Wwrite-strings -Werror -Wall -c break.c
clean:
	rm -f breaker *.o *.c~
