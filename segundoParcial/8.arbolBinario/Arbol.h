#include <iostream>
#include <cstdlib>
using namespace std;

//declaración de la clase Nodo
template <class T>
class Nodo
{
     private:
     T info;
     Nodo<T> *izquierdo;
     Nodo<T> *derecho;
     
     public:
     Nodo(); //declaracion del constructor
     T regresaInfo();
    // friend class ArbolBinario<T>;
};

template <class T>
Nodo<T>::Nodo() //inicialización del constructor
{
     izquierdo = NULL; //indica que los hijos apuntan a NULL (vacios)
     derecho = NULL;
}

template <class T>
T Nodo<T>::regresaInfo() //inicialización de la función
{
     return info; //regresa lo que tiene el nodo
}

//declaración de la clase ArbolBinario
template <class T>
class ArbolBinario
{
     private:
     Nodo<T> *raiz;
     
     public:
     ArbolBinario(); //declaración del constructor
     void CreaArbol(int *pointer);
     void Inorden(int *pointer);
     void Preorden(int *pointer);
     void Postorden(int *pointer);
};

template <class T>
ArbolBinario<T>::ArbolBinario()
{
     raiz = NULL; //inicialización del nodo raiz en NULL
}

template <class T>
void ArbolBinario<T>::CreaArbol(Nodo<T> *pointer)
{
     char resp;
     pointer = new Nodo<T>;
     cout << "Ingrese la información que desea almacenar: " << endl;
     cin >> pointer -> info;
     cout << "\n" << pointer->info << "¿Tiene hijo izquierdo (si/no) " << endl;
     cin >> resp;
     if (resp == "si")
     {
          CreaArbol(pointer->izquierdo);
          pointer->izquierdo = raiz;
     }
     cout << "\n" << pointer->info << "¿Tiene hijo derecho? (si/no) " << endl;
     cin >> resp;
     if (resp == "si")
     {
          CreaArbol(pointer->derecho);
          pointer->derecho = raiz;
     }
     raiz = pointer;
}

template <class T>
void ArbolBinario<T>::Preorden (Nodo<T> *pointer)
{
     if (pointer)
     {
          cout << pointer->info << " ";
          Preorden(pointer->izquierdo);
          Preorden(pointer->derecho);
     }
}

template <class T>
void ArbolBinario<T>::Inorden(Nodo<T> *pointer)
{
     if (pointer)
     {
          Inorden(pointer->izquierdo);
          cout << pointer->info << " ";
          Inorden(pointer->derecho);
     }
}

template <class T>
void ArbolBinario<T>::Postorden(Nodo<T> *pointer)
{
     if (pointer)
     {
          Postorden(pointer->izquierdo);
          Postorden(pointer->derecho);
          cout << pointer->info << " ";
     }
}