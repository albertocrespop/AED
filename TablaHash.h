#ifndef TABLA_HASH
#define TABLA_HASH
#include<list>
#include<string>

using namespace std;

string reemplazarU(string palabra);

class TablaHash{
	private:
		int t;
		int nElem;
		list<string> * tablahash;
	public:
		TablaHash ();
		void insertar (string palabra);
		bool consultar (string palabra);
		void vaciar (void);
		int numElem (void) { return nElem; }
		int funcHash(string palabra);

		list<string> obtenerU(string palabra);
};

#endif