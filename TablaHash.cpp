#include <iostream>
#include <list>
#include "TablaHash.h"

string reemplazarU(string palabra){
	for (int i = 0; i < palabra.length(); i++){
		if(palabra[i] == -61 && palabra[i+1] == -100){
			palabra[i] = 'U';
			palabra.erase(i+1,1);
		}
	}
	return palabra;
}

TablaHash::TablaHash(){
	t = 10000;
	nElem = 0;
	tablahash = new list<string>[t];
}

void TablaHash::insertar(string palabra){
	int pos = funcHash(reemplazarU(palabra));
	list<string>::iterator iterador = tablahash[pos].begin();
	while(iterador != tablahash[pos].end() && *iterador < palabra){
		if(*iterador == palabra){
			break;
		}
		iterador++;
	}
	if (iterador == tablahash[pos].end()){
		tablahash[pos].push_back(palabra);
		nElem++;
	}
	else if (*iterador > palabra){
		tablahash[pos].insert(iterador,1,palabra);
		nElem++;
	}
}

bool TablaHash::consultar(string palabra){
	int pos = funcHash(reemplazarU(palabra));
	list<string>::iterator iterador = tablahash[pos].begin();
	while(iterador != tablahash[pos].end() && *iterador <= palabra){
		if(*iterador == palabra){
			return true;
		}
		iterador++;
	}
	return false;
}

list<string> TablaHash::obtenerU(string palabra){
	int pos = funcHash(palabra);
	list<string>::iterator iterador = tablahash[pos].begin();
	list<string> results;
	while(iterador != tablahash[pos].end() && reemplazarU(*iterador) <= palabra){
		if(reemplazarU(*iterador) == palabra){
			results.push_back(*iterador);
		}
		iterador++;
	}
	return results;
}

void TablaHash::vaciar(){
	for(int i = 0; i < t; i++){
		tablahash[i].clear();
	}
	nElem = 0;
}

int TablaHash::funcHash(string palabra) {
    unsigned int hash = 0;
    for (char c : palabra) {
        hash ^= (hash << 5) + (hash >> 2) + c;
    }
    return hash % t;
}