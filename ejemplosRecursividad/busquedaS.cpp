#include <iostream>
using namespace std;

int busquedaSecuencial(int[] E, int n, int k)
{
    int respuesta = -1;
    int indice;
    
    for (indice = 0; indice < n; indice++)
    {
        if (k == E[indice])
        {
            respuesta = indice;
            break;
        }
    }
    return respuesta;
}
int main()
{
    respuesta;
    n  = 5;
    int *E;
    E = new int [n];
    
    E[0] = 1;
    E[1] = 2;
    E[2] = 3;
    E[3] = 4;
    E[4] = 5;
    
    cout << busquedaSecuencial([]E,n,0) << "Respuesta: " << respuesta << endl;
    
}