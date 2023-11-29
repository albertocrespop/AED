#include<iostream>
#include "Diccionario.h"

Diccionario::Diccionario(){
	contador = diccionario.numElem();
}

void Diccionario::insertar(string palabra){
	diccionario.insertar(palabra);
	contador = diccionario.numElem();
}

bool Diccionario::consultar(string palabra){
	return diccionario.consultar(palabra);
}

void Diccionario::vaciar(){
	diccionario.vaciar();
	contador = 0;
}	

int Diccionario::tamano(){
	return contador;
}