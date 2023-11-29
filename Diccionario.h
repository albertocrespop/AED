#ifndef DICCIONARIO
#define DICCIONARIO
#include<list>
#include<string>
#include "TablaHash.h"

using namespace std;

class Diccionario{
	private:
		TablaHash diccionario;
		int contador;
	public:
		Diccionario();
		void insertar(string palabra);
		bool consultar(string palabra);
		void vaciar(void);
		int tamano(void);
};

#endif