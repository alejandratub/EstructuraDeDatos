
#include <iostream> //declara la librería para archivos de entrada y salida
#include <string> // declara la librería para el manejo de strings
#include <fstream> // declara la librería para el manejo de archivos
#include <cstdlib>
using namespace std;

#define MAX 50

template <class T>
class Arreglo
{
    private:
        int *Datos =NULL;
        int Tam;
    public:
        Arreglo(); //declaración del constructor sin parámetros
        ~Arreglo(); //declaración del destructor
        void Lectura(); //declaración de la función para la lectura de datos 
        void Escribe(); //declaración de la función para escribir el arreglo
        void lecturaDatos(string); //declaración de la función para leer un arreglo desde un archivo
        int busquedaBinaria(int,int,int); //declaración de la función para la busqueda binaria
        int busquedaSecuencial(int); //declaración de la función para la búsqueda secuencial
        void selectionSort(); //Declaración de la función selection sort
        void bubbleSort(); //declaración de la función Bubble Sort
        void insertionSort(); //declaración de la función insertion sort
        void mergeSort(int, int); //declaración de la función mergeSort 
        void merge(int,int, int); //declaración de la función merge
        void quickSort(int, int); //declaración de la función quickSort
        int particion(int,int);//declaración de la función partición
        void intercambiar(int, int); //declaración de una función auxiliar para hacer el intercambio de los valores
        void imprime();
};


template <class T>
Arreglo<T>::Arreglo() //inicialización del constructor
{
    //Tam = valor; //asigna el tamaño del arreglo recibido 
}
template <class T>
Arreglo<T>::~Arreglo()
{
    delete [] Datos;
}
    
template <class T>
void Arreglo<T>::Lectura() //inicialización de la función para la lectura de datos
{
    int Indice;
    while (Tam < 1 || Tam > MAX); //mientras el tamaño sea menor que uno o mayor al máximo
        for (Indice = 0; Indice < Tam; Indice++) //mientras que el indice sea menor al tamaño del arreglo
        {
            cout << "Ingrese un elemento [" << Indice << "] : ";
            cin >> Datos[Indice]; //ingresar valores (elementos del arreglo)
        }
}



template <class T>
void Arreglo<T>::Escribe() //inicialización de la función para escribir los datos
{
        for (int Indice = 0; Indice < Tam; Indice++) //mientras que el indice sea menor al tamaño del arreglo
        {
            cout << "\nPosicion[" << Indice << "] = "/* " "*/ << Datos[Indice]; //imprime los elementos del arreglo
        }
    //cout << "\n";
}

template <class T>
void Arreglo<T>::lecturaDatos(string archivo) //función para leer los datos
{
    int i = 0; // declaración de la variable "i", inicialización de "i" en 0
    fstream archivo_num;// Declaracion del archivo
    string linea;//creo una variable tipo string para recibir el valor que se encuentra en la linea del archivo 
    archivo_num.open(archivo.c_str());//abre el archivo
    
    if(archivo_num.is_open()) // si el archivo está abierto
    {
    	cout << "Se abrió el archivo correctamente" << endl; //le muestra al usuario que se realizó correctamente
    	getline(archivo_num,linea);
    	Tam = atoi(linea.c_str()); //se le asigna un valor al tamaño al leer la primera linea del archivo
    	Datos = new int [Tam]; // se le asigna al arreglo un tamaño
    	while(!archivo_num.eof()) //mientras no se termine el archivo
    	{
    		archivo_num.ignore(0,'\n');
    		getline(archivo_num, linea); //se lee los valores
    		Datos[i] = atoi(linea.c_str()); // se va guardando un elemento en cada posición del arreglo
    		i++; // se le suma 1 al contador para poder avanzar en las posiciones del arreglo
    	}
    }
    else //si no se abrió el archivo 
    {
    	cout << "No se pudo abrir el archivo " << endl; //le avisa al usuario que no se abrio correctamente 
    }
    archivo_num.close();// se cierra el archivo
}

template <class T>
void Arreglo<T>::intercambiar(int a, int b) //inicialización de la función auxiliar para intercambair valores
{
    //declaro una variable temporal
    T tmp;
    //intercambio el elemento en a por el elemento en b
    tmp = Datos[a];
    Datos[a] = Datos[b];
    Datos[b] = tmp;
}
template <class T>
void Arreglo<T>:: selectionSort() //inicialización de la función selection Sort
{
    int contador;
    for (int i = 0; i < Tam - 1; i++)  //mientras que el indice sea menor al tamaño del arreglo
    {
        int minimo = i;
        for (int j = i + 1; j < Tam; j++) //mientras que el indice sea menor al tamaño del arreglo
        {
            if (Datos[j] < Datos[minimo])  //si el elemento en la posición j es menor al elemento en la posición del minimo
            {
            minimo = j; //igualar los elementos
            contador ++;
            }
            
        }
    intercambiar(i, minimo); //intercambiar los valores
   // imprime();
    }
}
template <class T>
void Arreglo<T>::bubbleSort() //inicialización de la función bubble sort
{
    for(int i = 0; i < Tam - 1; i++) //mientras que el indice sea menor a la penúltima posición del arreglo
    {
        for(int j = 0; j < Tam - i - 1; j++) 
        {
            if(Datos[j+1] < Datos[j]) // si el elemento depúes de j es menor a j
            {
                intercambiar(j+1, j);
                 }  
        }
    }
} 
template <class T>
void Arreglo<T>::insertionSort() //inicialización de la función insertion sort
{
    for (int i = 0; i < Tam - 1; i++) //mientras que el indice sea menor al tamaño del arreglo -1 
    {
        //declaración de variables
        int j = i + 1;
        int tmp = Datos[j];
        while (j > 0 && tmp < Datos[j-1]) //mientras j sea mayor que 0 y el elemento en j sea menor al element en j-1
        {
            Datos[j] = Datos[j-1]; //iguala
            j--;//disminuye el contador
        }
        Datos[j] = tmp; //igualo elemento a la variable temporal
    }
  }
template <class T>
int Arreglo<T>::busquedaSecuencial(int k) //función que busca el elemento dentro del arreglo 
{
	int resultado = -1; // declaro la variable "resultado" y la inicializo en "-1" por si no se encuentra el resultado 
	for(int i = 0; i < Tam; i++) //mientras "i" sea menor que el tamaño del arreglo 
	{
		if(Datos[i] == k) //comparar si "k" (el valor que estamos buscando) es igual al elemento dentro del arreglo en la posición "i"
		{
			resultado = i;
		}
	}
	return resultado; //la función devuelve el resultado 
}
template <class T>
int Arreglo<T>::busquedaBinaria(int inicio, int fin, int k) //inicialización de la búsqueda binaria
{
	int nuevo = 0;
	if (inicio > fin) //si el inicio es mayor que el fin 
	{
		cout << "ERROR" << endl; //muestra un error al usuario
	}
    int indice;
    
    if (fin < inicio) // si el fin es más chico que el inicio
    {
        indice = -1; // al indice se le da un valor de error (-1)
    }
    else //sino
    {
        int nuevo = (inicio + fin) / 2; //division entera o flor
       
        if (k == Datos[nuevo]) // si el elemento que esoy buscando es igual a la posición nueva
        {
            indice = nuevo; //le asigno el valor al indice
        }
            else if (k < Datos[nuevo]) //si el elemento que estoy buscando es menor al elemento en la posición nueva
            {
                indice = busquedaBinaria(inicio, nuevo - 1, k); // vuelvo a llamar a la función pero ahora del inicio a la mitad del arreglo
            }
        else //sino
        {
            indice = busquedaBinaria(nuevo + 1, fin, k); //vuelvo a llamar a la función pero ahora de la mitad del arreglo al final
        }
    }
    return indice; //regresa la posición en la que se encuentra el elemento que estoy buscando
}

 template <class T>
 void Arreglo<T>::mergeSort(int lo, int hi) //inicialización de la función 
 {
     if (lo >= hi)  //si el inicio es mayor o igual al fin 
     {
         return; //termina la función
     }
    int medio = (lo + hi)/2; // crear una nueva variable para obtener la mitad del arreglo 
    mergeSort(lo, medio); // se vuelve a llamar a la misma función pero ahora empezando en el principio del arreglo y terminando en la mitad
    mergeSort( medio + 1, hi); //se vuelve a llamar a la misma función pero ahora empezando en la mitad + 1 y terminando en el final original
    merge(lo, medio, hi); // manda a llamar a la función merge con los parametros de principio y fin 
}  


template <class T>
void Arreglo<T>:: merge(int lo, int mid, int hi) //inicialización de la función
{
    
   int aux[Tam]; //declaración de un arreglo temporal 
    int i = lo; // declaración de un nuevo índice para el inicio del arreglo
    int j = mid + 1; //declaración de un nuevo índice para la mitad del arreglo
    int k = lo; //declaración de un nuevo índice para el arreglo auxiliar
     for (int a = lo; a <= hi; a++) //dentro de este ciclo se hace la copia del arreglo original 
    {
        aux[a] = Datos[a];
    }
    
    while( i <= mid && j <= hi) //mientras el inicio del arreglo sea menos o igual al medio y el 
    {
            if(aux[i] <= aux[j]) //si el elemento de la primera mitad del arreglo es menor al elemento de la segunda mitad del arreglo
            {
                Datos[k] = aux[i]; // insertar el elemento en el nuevo arreglo
                i++; //aumento el contador de la primera mitad
                k++; //aumento el contador del arreglo auxiliar
            }
            else 
            {
                Datos[k] = aux[j]; /// instertar el elemento en el nuevo arreglo
                j++; //aumento el contador en la segunda mitad
                k++; //aumento el contador del arreglo auxiliar
            }
    }
    if( i == mid && j <= hi) //si el contador de la primera mitad ya llegó a la mitad y el segundo contador toda vía no termina
        {
                while (j <= hi) // mientras el contador sea menor o igual al tamaño final
                {
                    Datos[k] = aux[j]; //inserto los elementos en el arreglo
                    k++; //aumento el contador del arreglo auxiliar
                    j++; //aumento el contador de la segunda mitad
                }
                
        }
    else 
    {
        while (i <= mid) //mientras el contador de la primera mitad sea menor o igual a la mitad del arreglo
        {
            Datos[k] = aux[i]; //inserto los elementos en el nuevo arreglo
            k++; //aumento el contador del arreglo auxiliar
            i++; //aumento el contador de la primera mitad
        }
    }
}

template <class T>
void Arreglo<T>::quickSort(int lo, int hi) //inicialización de la función
{
    int pivote; //declaración del pivote
    if (lo < hi)  //si el inicio es mas grande que el fin
    {
        //return; //termina la funcion
    //}
     pivote = particion(lo, hi);// declaración del pivote llamando a la función "partición"
        quickSort(lo, pivote- 1); //mandar a llamar a la función pero ordenando la primera mitad
        quickSort(pivote + 1, hi);//mandar a llamar a la función pero ordenando la segunda mitad
    }
}

template <class T>
int Arreglo<T>::particion(int lo, int hi)
{
    //declaración de variables 
    int inicio = lo;
    int fin = hi + 1;
    int pivote = lo;
    
    
    while (inicio < fin)//mientras el inicio sea menor al fin
    {
        do
        {
            fin--; //disminuir el contador
        }
        while (Datos[fin] > Datos[pivote]);//mientras el elemento del final sea mayor que el pivote
        
        do
        {
            inicio++; //aumenta el contador 
        }
        while ((inicio <= hi) && (Datos[inicio] < Datos[pivote])); //mientras el inicio sea menor que el fin y el elemento del inicio sea menor o igual al pivote
        
        
        if (inicio < fin)  //si el inicio es menor que el fin
        {
            intercambiar(inicio,fin);
        }
    }
  
   intercambiar(pivote, fin);
 
    return fin; //devolver la nueva posición del pivote
}
template <class T>
void Arreglo<T>::imprime()
{
    for(int i = 0; i < Tam; ++i)
     {
        cout << " " << Datos[i] << endl;
     }
}