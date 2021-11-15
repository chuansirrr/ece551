cyoa-step1: cyoa-step1.o step1.o
	g++ -o cyoa-step1 -ggdb3 cyoa-step1.o step1.o
cyoa-step2: cyoa-step2.o book.o
	g++ -o cyoa-step2 -ggdb3 cyoa-step2.o book.o

cyoa.o: step1.cpp step1.hpp book.cpp book.hpp
	g++ -std=gnu++98 -pedantic -Wall -Werror -ggdb3 -c step1.cpp book.cpp

cyoa-step1.o:step1.cpp step1.hpp cyoa-step1.cpp
	g++ -std=gnu++98 -pedantic -Wall -Werror -ggdb3 -c cyoa-step1.cpp
cyoa-step2.o:book.cpp book.hpp cyoa-step2.cpp
	g++ -std=gnu++98 -pedantic -Wall -Werror -ggdb3 -c cyoa-step2.cpp
clean:
	rm -f *~ *.o cyoa-step1 byoa-step2
