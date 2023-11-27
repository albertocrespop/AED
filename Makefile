# Un comentario de make
a.out: Diccionario.o main.o
	g++ Diccionario.o main.o

Diccionario.o: Diccionario.cpp Diccionario.h
	g++ -c Diccionario.cpp

main.o: main.cpp Diccionario.h
	g++ -c main.cpp

