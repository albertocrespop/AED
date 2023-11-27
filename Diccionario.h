#ifndef DICCIONARIO
#define DICCIONARIO
#include<list>
#include<string>

using namespace std;

class Diccionario{
	private:
		list<string> diccionario;
		int contador;
	public:
		Diccionario();
		void insertar(string palabra);
		bool consultar(string palabra);
		void vaciar(void);
		int tamano(void);
};



#endif
