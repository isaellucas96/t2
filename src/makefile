all: siguel
siguel: t2.o circle.o rectangle.o listaVetor.o opGeo.o openingFile.o
	gcc -o siguel t2.o opGeo.o circle.o rectangle.o listaVetor.o openingFile.o -pedantic -ansi -lm -g
t2.o: t2.c
	gcc -c t2.c -pedantic -ansi -g
opGeo.o: opGeo.c listaVetor.h circle.h rectangle.h 
	gcc -c opGeo.c -pedantic -ansi -g
circle.o: circle.c listaVetor.h
	gcc -c circle.c -pedantic -ansi -g
rectangle.o: rectangle.c listaVetor.h
	gcc -c rectangle.c -pedantic -ansi -g
listaVetor.o: listaVetor.c circle.h rectangle.h
	gcc -c listaVetor.c -pedantic -ansi -g
openingFile.o: openingFile.c 
	gcc -c openingFile.c -pedantic -ansi -g
