#ifndef ARREGLO_
#define ARREGLO_

#include <iostream> //declara la librería para archivos de entrada y salida
#include <string> // declara la librería para el manejo de strings
#include <fstream> // declara la librería para el manejo de archivos
#include <cstdlib>
using namespace std;

class Arreglo  //declaración de la clase
{
	
private: //elementos protegidos o privados (atributos)
	int size; // delaración de la variable para guardar el tamaño del arreglo
	int *arr; // declaración de un arreglo 
	
public: //elementos públicos (funciones)
	Arreglo(); //declara el constructor

	// lee los datos de un archivo cuyo nombre recibe como parámetro
	void lecturaDatos(string); 
	//busca el elemento "k" en el arreglo, usando el algoritmo SECUENCIAL.
	//si lo encuentra devuelve su posición y en caso contrario regresa un -1
	int busquedaSecuencial(int);
	//busca el elemento "k" en el arreglo, usando el algoritmo BINARIO.
	//Si lo encuentra devuelve su posición y en caso contrario regresa un -1
	int busquedaBinaria(int, int, int);
	//recibe el tamaño del arreglo

};
#endif

Arreglo::Arreglo()
{
	size = 0;
} //inicialización del contructor

void Arreglo::lecturaDatos(string archivo) //función para leer los datos
{
    int i = 0; // declaración de la variable "i", inicialización de "i" en 0
    fstream archivo_num;// Declaracion del archivo
    string linea;//creo una variable tipo string para recibir el valor que se encuentra en la linea del archivo 
    archivo_num.open(archivo.c_str());//abre el archivo
    
    if(archivo_num.is_open()) // si el archivo está abierto
    {
    	cout << "Se abrió el archivo correctamente" << endl; //le muestra al usuario que se realizó correctamente
    	getline(archivo_num,linea);
    	size = atoi(linea.c_str()); //se le asigna un valor al tamaño al leer la primera linea del archivo
    	arr = new int [size]; // se le asigna al arreglo un tamaño
    	while(!archivo_num.eof()) //mientras no se termine el archivo
    	{
    		archivo_num.ignore(0,'\n');
    		getline(archivo_num, linea); //se lee los valores
    		arr[i] = atoi(linea.c_str()); // se va guardando un elemento en cada posición del arreglo
    		i++; // se le suma 1 al contador para poder avanzar en las posiciones del arreglo
    	}
    }
    else //si no se abrió el archivo 
    {
    	cout << "No se pudo abrir el archivo " << endl; //le avisa al usuario que no se abrio correctamente 
    }
    archivo_num.close();// se cierra el archivo
}



int Arreglo::busquedaSecuencial(int k) //función que busca el elemento dentro del arreglo 
{
	int resultado = -1; // declaro la variable "resultado" y la inicializo en "-1" por si no se encuentra el resultado 
	for(int i = 0; i < size; i++) //mientras "i" sea menor que el tamaño del arreglo 
	{
		if(arr[i] == k) //comparar si "k" (el valor que estamos buscando) es igual al elemento dentro del arreglo en la posición "i"
		{
			resultado = i;
		}
	}
	return resultado; //la función devuelve el resultado 
}

int Arreglo::busquedaBinaria(int inicio, int fin, int k)
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
        int nuevo = (inicio + fin) / 2; //division entera o fllor
       
        if (k == arr[nuevo])
        {
            indice = nuevo;
        }
            else if (k < arr[nuevo]){
                indice = busquedaBinaria(inicio, nuevo - 1, k);
            }
        
        else
        {
            indice = busquedaBinaria(nuevo + 1, fin, k);
        }
    }
    return indice;
}


