//////Alejandra Tubilla Castellanos//////
    /////////A01022960////////////////
       /////Proyecto 2//////
#include <iostream>
using namespace std;
#include <string>

//declaración de funciones
string limpiaString(string s);
int cuantaSubstring(string s, string sub);
int sumaDigitos(int n);
bool anidacionCorrecta(string s);

//recibe un string y regresa el string "limpio"
string limpiaString(string s)
{
    int size_s = s.size(); //guarda el tamaño del string
        string nuevo_string; //guarda el nuevo string
        int i = 0;
        
        if(size_s == 0 || size_s == 1) //si el tamaño del string es igual a 0 o 1
        {
            return s;//devuelve el string 
        }
        else //si no se cumple el caso base
        {
            if(s.at(i) == s.at(i + 1))  // compara la letra en una posición con la de la posición siguiente
              //at accesa a la posición de un string 
            {
                return limpiaString(s.substr(i + 1));   //regresa la letra dentro del nuevo string 
                //substr construye un nuevo string 
            }
            else 
            {
                nuevo_string = s.at(i) + limpiaString(s.substr(i + 1));  //cuando la letra no es igual la agregamos al nuevo string 
                return nuevo_string; //regresa el nuevo string completo 
            }
        }
}

//recibe un string s y un substring sub y regresa el número de veces que 
//aparece el substring en el string
int cuantaSubstring(string s, string sub)
{
    int i = 0;
    int size_s = s.size(); //guarda el tamaño del string
    int size_sub = sub.size();
     if(size_s == 0 || size_sub ==  0) //si el tamaño del string y el substring es igual a 0
        {
            return 0;//devuelve 0 porque no puede comparar nada
        }
        
    else 
    {
      if(size_sub > size_s) //si el tamaño del substring es mas grande que el del string
      {
          return 0; //devuelve 0 
      }
      else
      {
          if(s.substr(i, size_sub) == sub)  // si lo que está en el substring coincide con lo del string 

          {
              return  cuantaSubstring(s.substr(size_sub), sub) + 1; //devuelve la función + 1
          }
          else
          {
              return cuantaSubstring(s.substr(i + 1), sub); //si no coincide devuelve la misma función en el lugar 1 en vez de cero 
          }
      }
    }
    
}

//recibe un entero n y regresa la suma de sus digitos
int sumaDigitos(int n)
{
    if (n == 0) // si n es igual a 0
    {      
        return n; //devuelve n 
    }
    else 
    {
    return (n % 10) + sumaDigitos (n / 10) ;                    //divide el numero en digitos y los suma
    }
}

//recibe un string s formado con paréntesis anidados y regresa ture si los
//paréntesis están correctamente anidados y false si no lo están
bool anidacionCorrecta(string s)
{
    int i = 0;
    int size_s = s.size(); //guarda el tamaño del string 
   
    if(size_s == 0) //si el tamaño del string es igual a 0
    {
        return false; //devuelve falso
    }
    if((size_s % 2) != 0) //si el tamaño del string no es par
    {
        return false; //devuelve falso
    }
     
    if(size_s == 2) // si el tamaño del string es igual a 2
    {
        if((s.at(i) == '(') && (s.at(size_s - 1) == ')')) // comparar que el parentesis del espacio 0 esta correctamente anidado con el segundo 
        {
            return true; //si se cumple devuelve true 
        }
        else 
        {
            return false; // si no se cumple la condicion pasada devuelve false 
        }
    }
    else 
    {
        if((s.at(i) == '(') && (s.at(size_s - 1) == ')')) //si el tamaño del string es par checar lo mismo que si es igual a 2
        {
            return anidacionCorrecta(s.substr(i + 1, size_s -2));  //si se cumple devuelve la función checando los espacios siguientes
        }
        else 
        {
            return false;  //si no se cumple devuelve falso 
        }
    }
    
}





