#include <iostream>
using namespace std;
#include "Arreglo.h"
int main()
{
    
    Arreglo <int> array;
    string nombre;
    cout << "\n *****ARCHIVO*****" << endl;
    cout << " Ingresa el nombre del archivo que desea abrir (Ej. archivo.txt): ";
    cin >> nombre;
    array.lecturaDatos(nombre);
    cout << "Arreglo Original: ";
   // array.Escribe();
    //cout << "Quick Sort: ";
    //array.quickSort(0,9);
    //array.particion(0,9);
    //array.Escribe();
   // cout << "Merge Sort: ";
   // array.mergeSort(0,9);
  // array.bubbleSort();
  array.selectionSort();
    array.Escribe();
   return 0;
}
