#include <iostream>	
#include <cctype>
#include <string>
#include <list>
#include "diccionario.h"
using namespace std;

int main(){
	DicPalabras diccionario;
	diccionario.insertar("Hola");
	cout << "Buscando palabra 'Hola'... " << endl;
	if(diccionario.consultar("Hola")){cout << "Encontrado" << endl;}
	else{cout << "No encontrado" << endl;}
	
	diccionario.insertar("Mundo");
	cout << "Buscando palabra 'Mundo'... " << endl;
	if(diccionario.consultar("Mundo")){cout << "Encontrado" << endl;}
	else{cout << "No encontrado" << endl;}
	
	cout << "Buscando palabra 'Adios'... " << endl;
	if(diccionario.consultar("Adios")){cout << "Encontrado" << endl;}
	else{cout << "No encontrado" << endl;}
	
	diccionario.vaciar();
	cout << "Buscando palabra 'Hola'... " << endl;
	if(diccionario.consultar("Hola")){cout << "Encontrado" << endl;}
	else{cout << "No encontrado" << endl;}
	
	
	
	return 0;
}
