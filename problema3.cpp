#include <iostream>
#include <string>
#include "problemas.h"

using namespace std;

void problema3()
{
    string cadena1, cadena2;

    cout << "Ingrese la primera cadena de caracteres: " << endl;
    cin >> cadena1;

    cout << "Ingrese la segunda cadena de caracteres: " << endl;
    cin >> cadena2;

    if (cadena1.size() != cadena2.size())
    {
        cout << "falso" << endl;
        return;
    }

    for (size_t i = 0; i < cadena1.length(); i++)
    {
        if (cadena1[i] != cadena2[i])
        {
            cout << "falso" << endl;
            return;
        }
    }

    cout << "verdadero" << endl;
}
