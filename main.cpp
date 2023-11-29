#include<iostream>
#include "Diccionario.h"

using namespace std;

Diccionario palabras;

string normalizar(string p){
	for(int i = 0; p[i] != '\0'; i++){									
		
		if(p[i] == -61){												
			if(p[i+1] == -95 || p[i+1] == -127){						
				p[i] = 'a';												
				p.erase(i+1,1);											
			}															
			else if(p[i+1] == -87 || p[i+1] == -119){
				p[i] = 'e';
				p.erase(i+1,1);
			}
			else if(p[i+1] == -83 || p[i+1] == -115){
				p[i] = 'i';
				p.erase(i+1,1);
			}
			else if(p[i+1] == -77 || p[i+1] == -109){
				p[i] = 'o';
				p.erase(i+1,1);
			}
			else if(p[i+1] == -70 || p[i+1] == -102){
				p[i] = 'u';
				p.erase(i+1,1);
			}
			else if(p[i+1] == -79){										
				p[i+1] = -111;
			}
			else if(p[i+1] == -68){
				p[i+1] = -100;
			}
		}
																		
		if(p[i] > 96 && p[i] < 123){									
			p[i] = p[i] - 32;
		}
		
	}
	return p;
}

string cesar(string palabra){
	string ces = palabra;
	for(int i = 0; i < ces.length(); i++){
		if(ces[i] == 'A'){
			ces[i] = 'Z';
		}
		else if (ces[i] == -61){
			ces[i] = 78;
			ces.erase(i+1,1);
		}
		else if(ces[i] == 'O'){
			ces[i] = -61;
			ces.insert(i+1,1,-111);
		}
		else if(ces[i] != -111 && ces[i] <= 'Z' && ces[i] >= 'A'){
		    ces[i] = ces[i] - 1;   
		}
	}
	return ces;
}

bool contieneU(string palabra){
	for(char letra : palabra){
		if(letra == 'U'){
			return true;
		}
	}
	return false;
}

void generarCombinacionesIterativo(string& palabra, list<string>& combs) {
    list<string> temp;
    combs.push_back(palabra);

    for (int i = 0; i < palabra.length(); ++i) {
        if (palabra[i] == 'U') {
            for (string& comb : combs) {
                string nuevaPalabra = comb;
                nuevaPalabra[i] = -61;
				nuevaPalabra.insert(i+1,1,-100);
                temp.push_back(nuevaPalabra);
            }
        }
    }

    combs.splice(combs.end(), temp);
}

list<string> combinaciones(string& palabra) {
    list<string> combs;
    generarCombinacionesIterativo(palabra, combs);

    return combs;
}

bool consola(string comando){
	string c;
	int n;
	n = 0;
			
	if(comando.compare("<insertar>") == 0){

		while(cin>>c && c.compare("</insertar>") != 0){
			palabras.insertar(normalizar(c));
			n++;
		}
		
		cout<<"Insertando: "<<n<<" palabras"<<endl;
		cout<<"Total diccionario: "<<palabras.tamano()<<" palabras"<<endl;
		
	}
	else if(comando.compare("<vaciar>") == 0){
		palabras.vaciar();
		cout<<"Vaciando"<<endl;
		cout<<"Total diccionario: "<<palabras.tamano()<<" palabras"<<endl;
	}
	else if(comando.compare("<buscar>") == 0){
		cin>>c;
		c = normalizar(c);
		if(palabras.consultar(c) == true){
			cout<<"Buscando: "<<c<<" -> Encontrada"<<endl;
		}else{
			cout<<"Buscando: "<<c<<" -> No encontrada"<<endl;
		}
	}
	else if(comando.compare("<partidas>") == 0){
		cout<<"Partidas:";
		while(cin>>c && c.compare("</partidas>") != 0){
			cout<<" "<<normalizar(c);
		}
		cout<<endl;
		cout<<"No implementado"<<endl;
	}
	else if(comando.compare("<alocado>") == 0){
		cin>>c;
		cout<<"Alocado: "<<normalizar(c)<<endl;
		cout<<"No implementado"<<endl;
	}
	else if(comando.compare("<césar>") == 0){
		cin>>c;
		string input = normalizar(c);
		list<string> resultados;
		cout << "César: " << input << " ->";
		for(int i = 0; i < 27; i++){
			input = cesar(input);
			if(contieneU(input)){
				list<string> cmbs = combinaciones(input);
				for(string c : cmbs){
					if(palabras.consultar(c)){
						resultados.push_back(c);
					}
				}
			}
			else{
				if(palabras.consultar(input)){
					resultados.push_back(input);
				}
			}
		}
		resultados.sort();
		for(string c : resultados){
			cout << " " << c;
		}
		cout << endl;
	}
	else if(comando.compare("<juanagra>") == 0){
		cin>>c;
		cout<<"Juanagrama: "<<normalizar(c)<<endl;
		cout<<"No implementado"<<endl;
	}
	else if(comando.compare("<saco>") == 0){
		string a;
		cin>>c;
		cin>>a;
		cout<<"Saco: "<<normalizar(c)<<" "<<normalizar(a)<<endl;
		cout<<"No implementado"<<endl;
	}
	else if(comando.compare("<consomé>") == 0){
		cin>>c;
		cout<<"Consomé: "<<normalizar(c)<<endl;
		cout<<"No implementado"<<endl;
	}
	else if(comando.compare("<alarga>") == 0){
		cin>>c;
		cout<<"Alarga: "<<normalizar(c)<<endl;
		cout<<"No implementado"<<endl;
	}
	else if(comando.compare("<exit>") == 0){
		cout<<"Saliendo..."<<endl;
		return false;
	}
	return true;
}

int main(){
	string comandos;
	bool sigue = true;
	
	while(sigue && cin>>comandos){
		sigue = consola(comandos);
	}
	return 0;
}