#include <iostream>
using namespace std;

int busquedaBinaria(int[] E, int primero, int ultimo, int K)
{ 
    int indice;
    if (ultimo < primero)
    {
        indice = -1
    }
    else 
    {
        int medio = (primero + ultimo) / 2; //division entera i floor 
        if(K == E[medio])
        {
            indice = medio;
        }
        else if (K < E[medio])
        {
            indice = busquedaBinaria(E, primero, medio -1, K);
        }
        else 
        {
            indice = busquedaBinaria(E, medio + 1, ultimo, K);
        }
    }
    return indice;
}

int main()
{
    int n = 5;
    int *array = new int [n];
    array[0] = 1;
    array[1] = 2;
    array[2] = 3;
    array[3] = 4;
    array[4] = 5;
    
    
    cout << "Busqueda Binaria : " << busquedaBinaria(array, array[0], array[4], 11) << endl;
}