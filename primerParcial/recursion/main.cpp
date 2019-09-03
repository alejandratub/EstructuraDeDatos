#include "recursion.h"


int main()
{
    string s = "aaabbbccc";
    limpiaString(s);
    cout << "String limpio " << limpiaString(s) << endl;
    
    string str = "abbaaaaaabb";
    string sub = "ab";
    cuantaSubstring(str, sub);
    cout << "sub string " << cuantaSubstring(str, sub) << endl;
    
    int num = 123;
    sumaDigitos(num);
    cout << "suma de digitos " << sumaDigitos(num) << endl;
    
    string p = "((()))";
    anidacionCorrecta(p);
    cout << "parentesis " << anidacionCorrecta(p) << endl;
}

