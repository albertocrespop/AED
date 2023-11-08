#include "diccionario.h"
using namespace std;

DicPalabras::DicPalabras() {
    contador = 0;
}

void DicPalabras::vaciar() {
    lista.clear();
    contador = 0;
}

void DicPalabras::insertar(string palabra) {
    lista.push_front(palabra);
    contador++;
}

bool DicPalabras::consultar(string palabra) {
    for (const string &str : lista) {
        if (str == palabra) {
            return true;
        }
    }
    return false;
}

int DicPalabras::numElem() {
    return contador;
}
