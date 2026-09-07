#include <iostream>
#include <string>
#include "problemas.h"

using namespace std;

void problema7()
{
    string cadena;

    cout << "Ingrese una cadena de caracteres: " << endl;
    cin >> cadena;
    for  (size_t n = 0; n < cadena.length(); n++)
    {
        for (size_t i = n+1; i < cadena.length(); i++)
        {
            if (cadena[n] == cadena[i])
            {
                cadena.erase(i,1);
                i--;
            }
        }
    }
    cout<< cadena << endl;
}
