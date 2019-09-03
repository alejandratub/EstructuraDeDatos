#include <iostream>
#include <cstdlib>
using namespace std;

#ifndef PILA_H
#define PILA_H

class Pila
{
    public:
    Pila(int);
    bool push(int);
    bool pop(int&);
    bool pilaLlena();
    bool pilaVacia();
    void imprimePila();
    
    private:
    int top;
    int MAX;
    int *stack;
};
#endif

Pila::Pila(int MAX)
{
     if(MAX > 0)
     {
         stack = new int[MAX];
         this->MAX = MAX;
         top = -1;
     }
    
}
bool Pila::push(int dato)
{
    if(pilaLlena() == false)
    {
        top++;
         stack[top] = dato;
         return true;
    }
    else
    {
        
         cout << "La pila ya está llena" << endl;
        return false;
    }
    
 
}
bool Pila::pop(int &dato)
{
    if (pilaVacia() == true)
    {
        cout << "La pila está vacía" << endl;
        return false;
    }
    else
    {
        dato = stack[top];
        top--;
        return true;
    }
}
bool Pila::pilaLlena()
{
    if (top == MAX)
    {
        return true;
    }
    else 
    {
        return false;
    }
}
bool Pila::pilaVacia()
{
    if (top == -1)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

void Pila::imprimePila()
{
        for(int i = 0; i <= top; i ++)
        {
            cout << " " << stack[i];
        }
        cout << "\n Top: " << top << endl;
}