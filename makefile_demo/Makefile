#This is a Makefile for 2 source files: main.c, strcomp.c
compare_strings: main.o strcomp.o
	gcc main.o strcomp.o -o compare_strings 

main.o: main.c strcomp.h
	gcc -c main.c strcomp.h

strcomp.o: strcomp.c strcomp.h
	gcc -c strcomp.c strcomp.h

clean:
	rm -f *.o compare_strings