# Un comentario de make
a.out: TablaHash.o Diccionario.o main.o
	g++ TablaHash.o Diccionario.o main.o

Diccionario.o: Diccionario.cpp Diccionario.h TablaHash.h
	g++ -c Diccionario.cpp

TablaHash.o: TablaHash.cpp TablaHash.h
	g++ -c TablaHash.cpp

main.o: main.cpp Diccionario.h
	g++ -c main.cpp
