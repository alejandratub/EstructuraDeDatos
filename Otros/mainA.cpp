#include <iostream>
#include "Arbol.h"

using namespace std;
int main() {
	Arbol uno;
	uno.CrearArbol(uno.RegresaRaiz());
	cout<<"\n";
	cout << "Preorden: " << endl;
	uno.Preorden(uno.RegresaRaiz());
	cout<<"\n";
	cout << "Inorden: " << endl;
	uno.Inorden(uno.RegresaRaiz());
	cout<<"\n";
	cout << "Postorden: " << endl;
	uno.Postorden(uno.RegresaRaiz());
	
}