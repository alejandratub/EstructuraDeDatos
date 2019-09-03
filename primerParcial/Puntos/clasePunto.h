#include <iostream>
using namespace std;
#ifndef PUNTO
#define PUNTO

class Punto
{
    public:

    Punto(float, float); //Inicializa las coordenadas del punto (x,y)
    
    float ObtenerCoordenadaX();  //regresa la coordenada x del punto
    float ObtenerCoordenadaY();  //regresa la coordenada y del punto 
    void ModificaX(float);  //cambia el valor de la coordenada x del punto
    void ModificaY(float);  //cambia el valor de la coordenada y del punto 
    void ImprimeCoordenadas();  //imprime las coordenadas del punto
    
    
    private:
    float CoordenadaX;  //coordenada X del punto
    float CoordenadaY; //coordenada Y del punto 
};
#endif
    
    Punto::Punto(float CoordenadaX, float CoordenadaY)                                                                              //Inicializa las coordenadas del punto (x,y)
    {
        this->CoordenadaX = CoordenadaX;                                                                                             //inicializa la coordenada en x
        this->CoordenadaY = CoordenadaY;                                                                                            //inicializa la coordenada en y
        cout << "La coordenada inicial en x es: " << CoordenadaX << endl; //imprime la coordenada inicial en x
        cout << "La coordenada inicial en y es: " << CoordenadaY << endl; //imprime la coordenada inicial en y
    }
    float Punto:: ObtenerCoordenadaX()//regresa la coordenada x del punto
    {
        return CoordenadaX; //devuelve la coordenada en x
    }
    float Punto:: ObtenerCoordenadaY() //regresa la coordenada y del punto 
    {
        return CoordenadaY; //devuelve la coordenada en y
    }
    void Punto:: ModificaX(float x) //cambia el valor de la coordenada x del punto
    {
        
        CoordenadaX = x; //le asigna el valor ingresado a la coordenada x
    }
    void Punto::ModificaY(float y) //cambia el valor de la coordenada y del punto 
    {
        
        CoordenadaY = y; //le asigna el valor ingresado a la coordenada y
        
    }
    void Punto:: ImprimeCoordenadas() //imprime las coordenadas del punto
    {
        cout << "Las coordenadas finales del punto son: " << "( " << CoordenadaX << " , " << CoordenadaY << " )" << endl; //imprime las coordenadas finales
    }
    



