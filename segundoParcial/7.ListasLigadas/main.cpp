#include <iostream>
#include "Lista.h"

using namespace std;

int main() {
	Lista lista;
	int dato;
    cout << "insertamos '1' al inicio" << endl;
    lista.insertaInicio(1);
    lista.imprimeLista();
    cout << "insertamos '6' al final" << endl;
    lista.insertaFinal(6);
    lista.imprimeLista();
    cout << "insertamos '10' al final" << endl;
    lista.insertaFinal(10);
    lista.imprimeLista();
    cout << "insertamos '3' después del '6' " << endl;
    lista.insertaDespues(3,6);
    cout << "La lista es: " << endl;
    lista.imprimeLista();
    cout << "Eliminamos el elemento del inicio" << endl;
    lista.eliminaPrimero(dato);
    lista.imprimeLista(); 
    cout << "Eliminamos el elemento del final" << endl;
    lista.eliminaUltimo(dato);
    lista.imprimeLista();
    cout << "Eliminamos el '6'" << endl;
    lista.eliminaNodo(6, dato);
    lista.imprimeLista();
    cout << "La lista es: " << endl;
    lista.imprimeLista();
}