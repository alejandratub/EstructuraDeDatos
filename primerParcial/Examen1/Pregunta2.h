#include <iostream>
#include <string>

using namespace std;

bool palindromo(string s)
{
    int size_s = s.size(); 
        int i = 0;
        if(size_s == 0) 
        {
            return true;
        }
        else 
        {
            if(s.at(i) == s.at(size_s - 1))
            {
                return palindromo(s.substr(i + 1, size_s - 2));
            }
            else
            {
               return false; 
            }
        }
}

