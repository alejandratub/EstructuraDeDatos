#include <iostream>
#include <stdlib.h>
using namespace std;

#ifndef LISTA_H
#define LISTA_H

class Lista
{
    public:
    Lista();
    //inserta un elemento al inicio de la lista
    void insertaInicio(int dato);
    //inserta un elemento al final de la lista
    void insertaFinal(int dato);
    //inserta un elemento después de un dato de referencia
    bool insertaDespues(int dato, int ref);
    //Elimina el primer elemento de la lista. Regresa true si la operación 
    //fue exitosa y false en caso contrario
    bool eliminaPrimero(int &dato);
    //Elimina el último elemento de la lista. Regresa true si la operación 
    //fue exitosa y false en caso contrario
    bool eliminaUltimo(int &dato);
    //Elimina un elemento dado de la lista. Regresa true si la operación
    //fue exitosa y false en caso contrario
    bool eliminaNodo(int ref, int &dato);
    //Imprime todos los elementos de la lisra en una fila
    void imprimeLista();
    
    	private:
    	//crea una estructura "nodo"
		typedef struct nodo
		{
			int datos; //valores del nodo
			nodo *siguiente; //crea un apuntador de la clase nodo
		}
		
		*nodoA; 
		nodoA inicio; //inicializa variables del tipo nodoA (apuntador)
		nodoA actual;
		nodoA temp;
};
#endif 

Lista::Lista() //inicializa el constructor
{
	inicio = NULL; //inicio igual a NULL
	actual = NULL; //actual igual a NULL
	temp = NULL; //temporal igual a NULL
}

void Lista::insertaInicio(int dato) //inicializa la función
{
	nodoA n = new nodo; //se crea un nodo nuevo 
	n -> siguiente = inicio; //el inicio se vuelve el siguiente
	n -> datos = dato; // ingresan los datos
	inicio = n; //inicio igual a n
	
}

void Lista::insertaFinal(int dato) //inicializo la función
{
	nodoA n = new nodo; //se crea un nuevo nodo
	nodoA ultimo = new nodo; //se agrega el nodo al final
	n -> siguiente = NULL; //el siguiente ahora es NULL
	n -> datos = dato; //se agregan los datos
	
	if (inicio) //si es el inicio
	{
		ultimo = inicio; //el ultimo se vuelve el inicio
		
		while (ultimo -> siguiente) //mientras el ultimo apunte al siguiente
		ultimo = ultimo -> siguiente; //el ultimo es el siguiente
		
		ultimo -> siguiente = n; //se le da el valor de n
	}
	else
	{
		inicio = n; //si no el inicio es n
	}
}
bool Lista::insertaDespues(int dato, int ref) //inicializa la función
{
	nodoA n = new nodo; //se crean nuevos nodos
	nodoA q = new nodo;
	
	n -> datos = dato; //da el valor ingresado 
		if (inicio)
		{ 
			q =  inicio; // q tiene el valor de inicio
			
			while ((q != NULL ) && ( q -> datos != ref)) // mientras q no sea NULL y el dato no sea la referencia
			{
				q = q -> siguiente; //q tiene el valor del siguiente
			}
			
			if (q != NULL) // si q no es NULL
			{
				n -> datos = dato; //se le da el valor a dato
				n -> siguiente = q -> siguiente;
				q -> siguiente = n;
				return true; //devuelve true si se realiza la operación
			}
			else
			{
				return false; //si no regresa false
			}
		}
		else 
		{
			return true; 
		}
		
}
bool Lista::eliminaPrimero(int &dato) //inicializa la función
{
	nodoA delA = NULL; // se crea un nuevo objeto igual a NULL
	if (inicio) // si es el inicio
	{
		delA = inicio; // se le asigna el valor de inicio
		inicio = delA -> siguiente; // incio se vuelve el siguiente
		delete delA; // se borra el que tiene el valor de inicio
		return true; // devuelve true si se cumple
	}
	else 
	{
		return false; //si no devuelve false
	}
	
}
bool Lista::eliminaUltimo(int &dato) //inicializo la función
{
	nodoA delA = NULL; //se crea un objeto igual a NULL
	nodoA ant =NULL; //crea un objeto igual a NULL
	if (inicio) // si es el inicio
	{
		if(!inicio -> siguiente) //el inicio se vuelve el siguiente
		{
			delete inicio; //borra inicio
			inicio = NULL; //inicio ahora apunta a NULL
		}
		else //sino 
		{
			delA = inicio; // se le asigna a la variable inicio
	
			while(delA -> siguiente) // la variable sea el siguiente
			{
				ant=delA; //igualamos ant a delA
				delA = delA -> siguiente; //delA ahora apunta al siguiente 
			}
			
			ant -> siguiente = NULL; // ant ahora apunta a NULL
			delete delA; //borra delA
		}
		return true; //si se completó la operación regresa true
	}
	else 
	{
		return false; // de lo contrario false
	}
	
}
bool Lista::eliminaNodo(int ref,int &dato) //inicializa la función
{
	nodoA delA = NULL; //crea un nodo que apunta a NULL
	temp = inicio; // temporal es igual al inicio
	actual = inicio; //actual es igual al inicio
	
	while (actual != NULL && actual -> datos != ref) //mientras el actual no es NULL y el actual no apunta a refernecia
	{
		temp = actual; // temporal es igual a actual
		actual = actual -> siguiente; //actual ahora apunta al siguiente
	}
	
	if (actual == NULL) //si el actual es igual a NULL
	{
		delete delA; //borra delA
		return false; //regresa falso 
	}
	
	else 
	{
		delA = actual; //el que vamos a eliminar lo igualamos al actual
		actual = actual -> siguiente; //actual ahora apunta al siguiente
		temp -> siguiente = actual; // temporal que apunta al siguiente ahora es igual al actual
		if (delA == inicio)  //si el que vamos a eliminar es igual al inicio
		{
			inicio = inicio -> siguiente; //inicio apunta al siguiente
			temp = NULL; //temporal apunta a NULL
		}
		delete delA; //eliminamos
		return true; //si se cumple devuelve true
	}
}
void Lista::imprimeLista() //inicializa la función
{
	actual = inicio; //actua igual al inicio
	
	while(actual != NULL) // mientras el actual no se NULL
	{
		cout<< actual -> datos << endl; //imprime actual
		actual  = actual -> siguiente ; //actual ahora es el siguiente
	}
}