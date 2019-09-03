#include <iostream>
using namespace std;
int maximo(int array[], int n){
        
    if(n == 1){
        return array[0];
    }

    else {
        if( array[n] > array[n - 1]){
            return maximo(array, n - 1);
        }
        else{
            return array[n - 1];
        }
    }
}


int main()
{
    int n = 5;
    int *array;
    array = new int [n];
    
    
    array[0] = 3;
    array[1] = 1;
    array[2] = 0;
    array[3] = 8;
    array[4] = 6;
    
    //array[n] = {1,2,3,4,5};
    cout << "Máximo: " << maximo(array,n) << endl;
}
