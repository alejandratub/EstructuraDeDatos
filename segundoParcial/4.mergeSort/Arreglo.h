#include <iostream>
#include <string.h>

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
        int busquedaBinaria(int,int,int);
        int busquedaSecuencial(int);
        void selectionSort();
        void bubbleSort();
        void insertionSort();
        void mergeSort(int, int); //declaración de la función mergeSort 
        void merge(int,int, int); //declaración de la función merge
        void imprime();
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
void Arreglo<T>::Escribe()
{
    int Indice;
        for (Indice = 0; Indice < Tam; Indice++){
            cout << "\nPosicion[" << Indice << "] = " << Datos[Indice];
        }
    cout << "\n";
}

template <class T>
void Arreglo<T>:: selectionSort()
{
    int comparaciones = 0;
    cout << "Selection Sort: ";
    for (int i = 0; i < Tam - 1; i++) 
    {
        int minimo = i;
        for (int j = i + 1; j < Tam; j++)
        { 
            if (Datos[j] < Datos[minimo]) 
            {
            minimo = j;
            }
        }
    int tmp;
        tmp= Datos[i];
        Datos[i] = Datos[minimo];
        Datos[minimo] = tmp;
        cout << "Iteracion: " << i << endl;
        for(int k = 0; k < Tam; ++k)
        {
            cout << " " << Datos[k] << endl;
        }
        cout << "\n" ;
    
        
    }
    /* for(int i = 0; i < Tam; ++i)
     {
        cout << " " << Datos[i];
     }
         cout << "\n";*/
         cout << "num de comparaciones "<< comparaciones << endl;
}
template <class T>
void Arreglo<T>::bubbleSort()
{
    int comparaciones = 0;
   cout << "Bubble Sort: ";
    for(int i = 0; i < Tam - 1; i++)
    {
        for(int j = 0; j < Tam - i - 1; j++)
        {
            if(Datos[j+1] < Datos[j])
            {
                int tmp = Datos[j + 1];
                Datos[j + 1] = Datos[j];
                Datos[j] = tmp;
            } 
          
        }
          cout << "Iteracion: " << i << endl;
        for(int k = 0; k < Tam; ++k)
        {
            cout << " " << Datos[k] << endl;
        }
        cout << "\n" ;
        
    
        }
} 
template <class T>
void Arreglo<T>::insertionSort()
{
    int comparaciones = 0;
    cout << "Insertion Sort: ";
    for (int i = 0; i < Tam - 1; i++)
    {
         
        int j = i + 1;
        int tmp = Datos[j];
        while (j > 0 && tmp < Datos[j-1])
        {
            Datos[j] = Datos[j-1];
            j--;
        }
        Datos[j] = tmp;
        cout << "Iteracion: " << i << endl;
        for(int k = 0; k < Tam; ++k)
        {
            cout << " " << Datos[k] << endl;
        }
        cout << "\n" ;
    
       
    }
    /*for(int i = 0; i < Tam; ++i)
    {
        cout << " " << Datos[i];
    }
        cout << "\n";*/
}
template <class T>
int Arreglo<T>::busquedaSecuencial(int k) //función que busca el elemento dentro del arreglo 
{
	int resultado = -1; // declaro la variable "resultado" y la inicializo en "-1" por si no se encuentra el resultado 
	for(int i = 0; i < Tam; i++) //mientras "i" sea menor que el tamaño del arreglo 
	{
		if(Datos[i] == k) //comparar si "k" (el valor que estamos buscando) es igual al elemento dentro del arreglo en la posición "i"
		{
			resultado = i;
		}
	}
	return resultado; //la función devuelve el resultado 
}
template <class T>
int Arreglo<T>::busquedaBinaria(int inicio, int fin, int k)
{
	int nuevo = 0;
	if (inicio > fin)
	{
		cout << "ERROR" << endl;
	}
    int indice;
    
    if (fin < inicio)
    {
        indice = -1;
    }
    
    else
    {
        int nuevo = (inicio + fin) / 2; //division entera o flor
       
        if (k == Datos[nuevo])
        {
            indice = nuevo;
        }
            else if (k < Datos[nuevo])
            {
                indice = busquedaBinaria(inicio, nuevo - 1, k);
            }
        
        else
        {
            indice = busquedaBinaria(nuevo + 1, fin, k);
        }
    }
    return indice;
}
 template <class T>
 void Arreglo<T>::mergeSort(int lo, int hi) //inicialización de la función 
 {
     if (lo >= hi)  //si el inicio es mayor o igual al fin 
     {
         return; //termina la función
     }
    int medio = (lo + hi)/2; // crear una nueva variable para obtener la mitad del arreglo 
    mergeSort(lo, medio); // se vuelve a llamar a la misma función pero ahora empezando en el principio del arreglo y terminando en la mitad
    mergeSort( medio + 1, hi); //se vuelve a llamar a la misma función pero ahora empezando en la mitad + 1 y terminando en el final original
    merge(lo, medio, hi); // manda a llamar a la función merge con los parametros de principio y fin 
}  


template <class T>
void Arreglo<T>:: merge(int lo, int mid, int hi) //inicialización de la función
{
    
   int aux[Tam]; //declaración de un arreglo temporal 
    int i = lo; // declaración de un nuevo índice para el inicio del arreglo
    int j = mid + 1; //declaración de un nuevo índice para la mitad del arreglo
    int k = lo; //declaración de un nuevo índice para el arreglo auxiliar
     for (int a = lo; a <= hi; a++) //dentro de este ciclo se hace la copia del arreglo original 
    {
        aux[a] = Datos[a];
    }
    
    while( i <= mid && j <= hi) //mientras el inicio del arreglo sea menos o igual al medio y el 
    {
            if(aux[i] <= aux[j]) //si el elemento de la primera mitad del arreglo es menor al elemento de la segunda mitad del arreglo
            {
                Datos[k] = aux[i]; // insertar el elemento en el nuevo arreglo
                i++; //aumento el contador de la primera mitad
                k++; //aumento el contador del arreglo auxiliar
            }
            else 
            {
                Datos[k] = aux[j]; /// instertar el elemento en el nuevo arreglo
                j++; //aumento el contador en la segunda mitad
                k++; //aumento el contador del arreglo auxiliar
            }
    }
    if( i == mid && j <= hi) //si el contador de la primera mitad ya llegó a la mitad y el segundo contador toda vía no termina
        {
                while (j <= hi) // mientras el contador sea menor o igual al tamaño final
                {
                    Datos[k] = aux[j]; //inserto los elementos en el arreglo
                    k++; //aumento el contador del arreglo auxiliar
                    j++; //aumento el contador de la segunda mitad
                }
                
        }
    else 
    {
        while (i <= mid) //mientras el contador de la primera mitad sea menor o igual a la mitad del arreglo
        {
            Datos[k] = aux[i]; //inserto los elementos en el nuevo arreglo
            k++; //aumento el contador del arreglo auxiliar
            i++; //aumento el contador de la primera mitad
        }
    }
}

template <class T>
void Arreglo<T>::imprime()
{
    for(int i = 0; i < Tam; ++i)
     {
        cout << " " << Datos[i] << endl;
     }
}