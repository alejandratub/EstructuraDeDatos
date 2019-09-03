#include "BST.h"
#include <iostream>

using namespace std;

int main()
{
	ArbolBinario obj1;
	obj1.crear("arbol.txt");
	obj1.imprime();
	cout<<endl;
	obj1.insertar(2);
	cout<<endl;
	obj1.insertar(10);
	cout<<endl;
	obj1.insertar(60);
	cout<<endl;
	obj1.buscar(2, obj1.raiz);
	cout<<endl;
	obj1.buscar(100, obj1.raiz);
	cout<<endl;
	obj1.elimina(10);
	cout<<endl;
	obj1.imprime();
	cout<<endl;
	obj1.elimina(19);
	cout<<endl;
	obj1.insertar(50);
	cout<<endl;
	obj1.imprime();
	cout<<endl;
return 0;
}