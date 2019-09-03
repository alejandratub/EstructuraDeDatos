#include <iostream>
using namespace std;
#include "Arreglo.h"
int main()
{
    
    Arreglo <int> array(10);
    array.Lectura();
    cout << "Arreglo Original: ";
    array.Escribe();
    //array.mergeSort(0,10);
   // array.Escribe();
   // cout << "Quick Sort: ";
   // array.quickSort(0,9);
   //cout << "Selection Sort" << endl;
//array.selectionSort();
//    cout << "Insertion Sort" << endl;
  //   array.insertionSort();
     cout << "Bubble Sort" << endl;
     array.bubbleSort();
    
  //  array.quickSort();
   // array.particion(0,9);
//    array.Escribe();
   return 0;
}
