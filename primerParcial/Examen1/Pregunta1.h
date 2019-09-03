#ifndef RECTANGULO_
#define RECTANGULO_

#include <iostream>
using namespace std;

class Rectangulo
{
    public:
    Rectangulo(float, float);
    float areaRectangulo(float, float);
    float perimetroRectangulo(float, float);
    float getAltura();
    float getBase();
    protected:
    float base;
    float altura;
    float area;
    float perimetro;
    
};
#endif
Rectangulo::Rectangulo(float base, float altura)
{
    this->base = base;
    this->altura = altura;
}
float Rectangulo::getAltura()
{
    return altura;
}
float Rectangulo::getBase()
{
    return base;
}

float Rectangulo::areaRectangulo(float altura, float base)
{
    area = (altura * base);
    cout << "El área del Rectángulo es: " << area << endl;
    return area;
}

float Rectangulo::perimetroRectangulo(float altura, float base)
{
    perimetro = (altura *2) + (base *2);
    cout << "El perímetro del Rectangulo es: " << perimetro << endl;
    return perimetro;
}


