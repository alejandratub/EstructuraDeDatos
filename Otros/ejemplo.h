#ifndef ARREGLO_
#define ARREGLO_

#include <iostream> //declara la librería para archivos de entrada y salida
#include <string> // declara la librería para el manejo de strings
#include <fstream> // declara la librería para el manejo de archivos
using namespace std;

class Arreglo  //declaración de la clase
{
public: //elementos públicos (funciones)
	Arreglo(); //declara el constructor
	// lee los datos de un archivo cuyo nombre recibe como parámetro
	void lecturaDatos(string archivo); 
	//busca el elemento "k" en el arreglo, usando el algoritmo SECUENCIAL.
	//si lo encuentra devuelve su posición y en caso contrario regresa un -1
	int busquedaSecuencial(int k);
	//busca el elemento "k" en el arreglo, usando el algoritmo BINARIO.
	//Si lo encuentra devuelve su posición y en caso contrario regresa un -1
	int busquedaBinaria(int inicio, int fin, int k);
	//recibe el tamaño del arreglo
	int getSize();

protected: //elementos protegidos o privados (atributos)
	int size; // delaración de la variable para guardar el tamaño del arreglo
	int *arr; // declaración de un arreglo 
};
#endif

Arreglo::Arreglo() //inicialización del contructor
{
	size = 0; //asigna un valor a la variable size
}

int Arreglo::getSize() 
{
	return size; // regresa el valor de la variable size
}

void Arreglo::lecturaDatos(string archivo) //función de la lectura del archivo de datos 
{
  string linea; // declaración del string linea
  int posicion = 0; //devlaracion de la variable inicializada en 0

  ifstream myfile (archivo); // le paso el nombre del archivo a "myfile" para poder leerlo
  //"ifstream" --> te permite leer de los archivos
  if(myfile.is_open()) // si mi archivo está abierto
  //"is_open" --> comprueba que el archivo este abierto 
  {
  	cout << "Se abrió el archivo exitosamente" << endl;
  	while(getline(myfile, linea)) // va a ir buscando lo que tiene el archivo linea por linea
  	{
  		if (size == 0) // si el tamaño es 0
  		{
  			size = stoi(linea); // te convierte la primera linea a entero 
  			// "stoi" --> convierte de string a entero
  			arr = new int[size]; // le paso al arreglo el string 
  		}
  		else //sino
  		{
  			arr[posicion] = stoi(linea); //convierte el valor que tiene en esa posición a entero
  			++posicion; // va aumentando la posición de uno en uno 
  		}
  	}
  }
  else // si el archivo no está abierto le avisa al usuario
  {
  	cout << "NO se abrió el archivo exitosamente" << endl;
  }

}

int Arreglo::busquedaSecuencial(int k) //función que busca el elemento dentro del arreglo 
{
	int resultado = -1; // declaro la variable "resultado" y la inicializo en "-1" por si no se encuentra el resultado 
	int i = 0;
	while((resultado == -1) && (i < size)) //mientras "i" sea menor que el tamaño del arreglo 
	{
		if(arr[i] == k) //comparar si "k" (el valor que estamos buscando) es igual al elemento dentro del arreglo en la posición "i"
		{
			resultado = (i - 1); // si se cumple esta condicion resultado va a ser igual a "i" (la posición en la que se encuentra el elemento)
		}
		i++;
	}
	return resultado; //la función devuelve el resultado 
}

int Arreglo::busquedaBinaria(int inicio, int fin, int k)
{
	int nuevo = 0;
	if((inicio > fin) || (inicio < 0) || (fin < 0) || (fin > size))
	{
		cout << "No se puede buscar el elemento, parámetros incorrectos" << endl;
	}
	else if (inicio == fin) //si el inicio y el fin son iguales
	{
		if(arr[inicio] == k) // el elemento del arreglo en la posición de inicio es igual a "k"
		{
			return inicio; // regresa la posición de inicio
		}
		else  // sino 
		{
			return -1; // regresa "-1" (quiere decir que no se encuentra el elemento dentro del arreglo)
		}
	}
	else 
	{
		if((inicio + fin) % 2 == 0) // si el tamaño dentro del que estoy buscando se puede dividr entre 2
		{
			nuevo = ((inicio + fin)/2); // crear un nuevo tamaño dividiendo el anterior entre 2
		}
		else
		{
			nuevo = ((inicio + fin) + 1)/2; // crear un nuevo tamaño dividiendo el anterior +1 entre 2
		}
		if(arr[nuevo] <= k) // si el elemento del arreglo en la posición nueva (la mitad del arreglo) es menor o igual a "k" (el elemento que estamos buscando)
		{
			if(arr[nuevo] == k) // checar si el elemento del arreglo en la posición nueva es igual a "k"
			{
				return nuevo; // devuelve la posición "nueva" (donde se encontró el elemento)
			}
			else //sino
			{
				return busquedaBinaria(nuevo, fin, k); //devuelve la misma función, pero ahora va desde la posición nueva hasta el final del arreglo (haciendolo más chico)
			}
		}
		else //sino
		{
			return busquedaBinaria(inicio, nuevo, k); // devuelve la misma función, pero ahora va desde el inicio hasta la posición nueva (haciendolo más chico)
		}
	}
}