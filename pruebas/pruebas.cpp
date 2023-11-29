#include <iostream>
using namespace std;

int main(){
    string palabra;
    cin >> palabra;
    for(int i = 0; i < int(palabra.length()); i++){
        cout << "|";
    }
    cout << int(palabra.length());
    return 0;
}