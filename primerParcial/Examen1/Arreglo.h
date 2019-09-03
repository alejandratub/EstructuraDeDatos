#include <iostream>
using namespace std;

#define MAX 50

template <class T>
class Arreglo
{
    private:
        T Datos[MAX];
        int Tam;
    public:
        Arreglo();
        Arreglo(int);
        void Lectura();
        void Escribe();
        int busquedaSaltandoN(int n, int K);
        int busquedaSecuencial(int inicio, int final, int K);
};

template <class T>
Arreglo<T>::Arreglo(int valor)
{
    Tam = valor;
}
    
template <class T>
void Arreglo<T>::Lectura()
{
    int Indice;
    while (Tam < 1 || Tam > MAX);
        for (Indice = 0; Indice < Tam; Indice++){
            cout << "Ingrese un elemento [" << Indice << "] : ";
            cin >> Datos[Indice];
        }
}



template <class T>
void Arreglo<T>::Escribe(){
    int Indice;
        for (Indice = 0; Indice < Tam; Indice++){
            cout << "\nPosicion[" << Indice << "] = " << Datos[Indice];
        }
    cout << "\n";
}
template <class T>
int Arreglo<T>::busquedaSaltandoN(int n, int K)
{
    int
    int resultado = -1;
	for( indice ; i < Tam; i = i + n) //mientras "i" sea menor que el tamaño del arreglo 
	{
		if(Datos[indice] == K) //comparar si "k" (el valor que estamos buscando) es igual al elemento dentro del arreglo en la posición "i"
		{
			resultado = i;
		}
	}
	return resultado; //la función devuelve el resultado 
}
template <class T>
int Arreglo<T>::busquedaSecuencial(int inicio, int final, int K)
{
    int resultado = -1;
	for(indice = inicio; i < final; i++) //mientras "i" sea menor que el tamaño del arreglo 
	{
		if(Datos[indice] == K) //comparar si "k" (el valor que estamos buscando) es igual al elemento dentro del arreglo en la posición "i"
		{
			resultado = i;
		}
	}
	return resultado; //la función devuelve el resultado 
}


