#include<iostream>
#include "Diccionario.h"

Diccionario::Diccionario(){
	contador = 0;
}

void Diccionario::insertar(string palabra){
	if(!this->consultar(palabra)){			
		this->diccionario.push_back(palabra);
		this->contador = this->contador + 1;
	}
}

bool Diccionario::consultar(string palabra){
	list<string>::iterator EA;
	string actual;
	EA = this->diccionario.begin();

	while(EA != this->diccionario.end() && *EA != palabra){
		EA++;
	}
	if(EA == this->diccionario.end()){
		return false;
	}
	return true;
}

void Diccionario::vaciar(){
		this->diccionario.clear();
		this->contador = 0;
}	

int Diccionario::tamano(){
	return this->contador;	
}
