#ifndef DICPALABRAS_H
#define DICPALABRAS_H

#include <list>
#include <string>
using namespace std;


class DicPalabras {
private:
    list<string> lista;
    int contador;

public:
    DicPalabras();
    void vaciar();
    void insertar(string palabra);
    bool consultar(string palabra);
    int numElem();
};

#endif // DICPALABRAS_H
