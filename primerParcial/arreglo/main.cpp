#include "Arreglo.h"

int main()
{
    Arreglo ob1;
    
    int num1;
    int num2;
    int inicio;
    int fin;
    int resultado;
    int resultado2;
    
    string nombre;
    
    cout << "\n *****ARCHIVO*****" << endl;
    cout << " Ingresa el nombre del archivo que desea abrir (Ej. archivo.txt): ";
    cin >> nombre;
    
    ob1.lecturaDatos(nombre);
    
    cout << "\n*****BÚSQUEDA SECUENCIAL*****" << endl;
    cout << " Ingresa el numero que desea buscar en el archivo: ";
    cin >> num1;
    
    resultado = ob1.busquedaSecuencial(num1);
    
    if (resultado == -1)
    {
        cout << " >> El número " << num1 << " NO se encuentra dentro del archivo (" << resultado << ")" << endl;
    }
    else{
        cout << " >> El número " << num1 << " se encuentra en la posición (" << resultado << ") del arreglo" << endl;
    }
    
    
    cout << "\n*****BÚSQUEDA BINARIA*****" << endl;
    cout << "RECUERDE: Los números dentro del archivo deben de estar ordenados" << endl;
    cout << " Ingrese el número que desea buscar dentro del archivo: ";
    cin >> num2;
    
    cout << " Ingresa la posición para iniciar la búsqueda: ";
    cin >> inicio;
    
    cout << " Ingresa la posición para finalizar la búsqueda: ";
    cin >> fin;
    
    resultado2 = ob1.busquedaBinaria(inicio,fin,num2);
    
    if (resultado2 == -1)
    {
        cout << " >> El número " << num2 << " NO se encuentra dentro del archivo (" << resultado2 << ")" << endl;
    }
    
    else{
        cout << " >> El número " << num2 << " se encuentra en la posición (" << resultado2 << ") del arreglo" << endl;
    }
    
    return 0;
    
}