/*#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H*/
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class nodo
{
public:
	int valor;
    nodo *hijoIzq=nullptr;
    nodo *hijoDer=nullptr;

    nodo(int dato)
    {
    	valor = dato;
    }
};


class ArbolBinario
{
public:
//~ArbolBinario();
//crea el árbol leyendo los datos desde un archivo
void crear (string archivo);
//insertara un elemento en el árbol
void insertar(int dato);
//buscar un elemento en el árbol. Regresa true si se encontró y false si no 
bool buscar(int dato, nodo *&a);
//elimina un elemento del árbol
bool elimina(int dato);
//imprime todos los elementos del árbol en INORDEN
bool eliminaNodo(nodo *&a, int num);
bool eliminaReal(nodo*&a, int num);
void insert(nodo*&a, int num);
//imprime los elementos del arbol
void clear(nodo*&a);
void clear();
void imprime();
void inorden(nodo*&a);
	nodo *raiz=NULL;


};
void ArbolBinario::clear ()
{
    clear(raiz);
}

// Private method to delete all the nodes in the subtree specified

void ArbolBinario::clear (nodo *&a)
{
    if (a == nullptr)
        return;
    clear(a->hijoIzq);
    clear(a->hijoDer);
    delete a;
}
//ArbolBinario::~ArbolBinario()
//{
//	delete ;
//}
void ArbolBinario::crear(string archivo) //inicialización de la funcion
	{
		//abre el archivo y lee los datos
		string line ="";
		int pos=0;
		ifstream myfile (archivo);
		if(myfile.is_open())
		{
			while(getline(myfile, line))
			{
				if (pos==0)
				{
					++pos;
				}
				else
				{
					insertar(stoi(line));
				}
			}
		}
	}	
void ArbolBinario::insertar(int num) //incialización de la función
	{
        insert(raiz, num); //manda a llamar a la función insert
	}
void ArbolBinario::insert(nodo *&a, int num) //inicialización de la función 
	{
		// si a es null
		if (a == nullptr)
		{
			//crea un nuevo nodo
			a = new nodo(num);
		}
		//si a tiene un valor 
		else if(a -> valor > num || a->valor == num)
		{
			//crea un nodo hijo izquierdo 
			insert(a -> hijoIzq, num);
		}
		else if(a->valor<num)
		{ 
			//crea un nodo hijo derecho 
			insert(a -> hijoDer, num);
		}
	}
bool ArbolBinario::buscar(int num, nodo *&a) //inicialización de la función buscar
	{
		if (a == nullptr) // si a es nula
		{
			cout<<"No se encontró el dato buscado "<<endl;
			return false; //regresa falso
		}
		else //sino 
		{
			if (a -> valor == num) //si el valor de a es igual al dato que se está buscando 
			{
				cout<<"Se encontró el dato buscando"<<endl;
				return true; //regresa true
			}
			else if(a -> valor > num || a -> valor == num) //si no es 
			{
				//busca en el nodo izquierdo 
				buscar(num, a->hijoIzq);
			}
			else if(a->valor<num)
			{
				//busca en el nodo derecho
				buscar(num, a->hijoDer);
			}
		}
	}
bool ArbolBinario::elimina(int num) //inicialización de la función elimina
	{
		eliminaNodo(raiz, num);
	}
bool ArbolBinario::eliminaNodo(nodo *&a, int num) //para eliminar el nodo
	{
		if (a==nullptr) // si no se encuentra el dato 
		{
			cout<<"No se encontró el dato, no se puede eliminar"<<endl;
			return false; //regresa false
		}
		else
		{
			if (a->valor==num) //si se quiere eliminar un nodo con hijos se llama la función elimina real 
			{
				eliminaReal(raiz, num);
			}
			else if(a->valor>num || a->valor==num)
			{
				eliminaNodo(a->hijoIzq, num);
			}
			else if(a->valor<num)
			{
				eliminaNodo(a->hijoDer, num);
			}
		}
	}	
bool ArbolBinario:: eliminaReal(nodo *&a, int num) //función para eliminar un nodo padre y convierte al hijo derecho en el nodo padre
		{
		//nodo *a;
		nodo *padre;
		//a=raiz;
		if (a->hijoIzq==nullptr && a->hijoDer==nullptr)
				{
					if (padre->hijoDer=a)
					{
						padre->hijoDer=nullptr;
					}
					else
					{
						padre->hijoIzq=nullptr;
					}
					cout<<"Se ha eliminado el dato"<<endl;
					return true;					
				}
				else if(a->hijoIzq==nullptr && a->hijoDer!=nullptr)
				{
					if (padre->hijoIzq==a)
					{
						padre->hijoIzq=a->hijoDer;
						delete a;
					}
					else
					{
						padre->hijoDer=a->hijoDer;
						delete a;
					}
					cout<<"Dato eliminado"<<endl;
					return true;
				}
				else if (a->hijoIzq!=nullptr && a->hijoDer==nullptr)
				{
					if (padre->hijoIzq==a)
					{
						padre->hijoIzq=a->hijoIzq;
						delete a;
					}
					else
					{
						padre->hijoDer=a->hijoIzq;
						delete a;
					}
					cout<<"Dato eliminado "<<endl;
					return true;
				}
				else if(a->hijoIzq!=nullptr && a->hijoDer!=nullptr)
				{
					nodo *aux;
					aux=a->hijoDer;
					if (aux->hijoIzq==nullptr && aux->hijoDer==nullptr)
					{
						a=aux;
						delete aux;
						a->hijoDer=nullptr;
					}
					else
					{
						if ((a->hijoDer)->hijoIzq!=nullptr)
						{
							nodo *o;
							nodo *op;
							op=a->hijoDer;
							o=(a->hijoDer)->hijoIzq;
							while(o->hijoIzq!=nullptr)
							{
								op=o;
								o=o->hijoIzq;
							}
							a->valor=o->valor;
							delete o;
							o->hijoIzq=nullptr;
						}
						else
						{
							nodo *temp;
							temp=a->hijoDer;
							a->valor=temp->valor;
							a->hijoDer=temp->hijoDer;
							delete temp;
						}
					}
					cout<<"Dato eliminado "<<endl;
					return true;
				}
	}
void ArbolBinario::imprime() //inicialización de la función imprimir
{
	inorden(raiz); //manda a llamar a la función inorden para imprimirlo de esta forma 
}
void ArbolBinario::inorden(nodo *&a)
	{
		if (a==nullptr)
		{
			return;
		}
		else
		{
			inorden(a->hijoIzq);
			cout<<a->valor<<" ";
			inorden(a->hijoDer);
		}
	}

/*void preorden(nodo *&a)
	{
		if (a==nullptr)
		{
			return;
		}
		else
		{
			cout<<a->valor<<" ";
			preorden(a->hijoIzq);
			preorden(a->hijoDer);
		}
	}
	void postorden(nodo *&a)
	{
		if (a==nullptr)
		{
			return;
		}
		else
		{
			postorden(a->hijoIzq);
			postorden(a->hijoDer);
			cout<<a->valor<<" ";
		}
	}*/

/*void crearArbol(nodo *&a)
	{
		int num;
		char resp;
		cout<<"Ingrese su dato: "<<endl;
		cin>>num;
		a=new nodo(num);
        cout<<"Tiene hijo izquierdo? y/n "<<endl;               estaba bonito
        cin>>resp;
        if (resp=='y')
        	crearArbol(a->hijoIzq);
        cout<<"Tiene hijo derecho? y/n "<<endl;
        cin>>resp;
        if (resp=='y')
        	crearArbol(a->hijoDer);
	}*/