#include <iostream>
#include <string>
#include "problemas.h"

using namespace std;

// ============================================================
// PROBLEMA 3: Comparar si dos cadenas son iguales.
//
// La idea:
//   Dos cadenas son iguales solo si cumplen DOS condiciones:
//     1. Miden lo mismo.
//     2. Cada caracter coincide con el de la misma posicion en la otra.
//
//   Primero revisamos el tamano porque es lo mas barato: si miden
//   distinto ya sabemos la respuesta y no hace falta comparar letras.
//   Si miden igual, recorremos posicion por posicion.
//
//   Ej: "hola" vs "hola"  -> verdadero
//       "hola" vs "chao"  -> falso (mismo tamano, distintas letras)
//       "hola" vs "holaX" -> falso (distinto tamano)
// ============================================================

void problema3()
{
    // Dos variables tipo string, una para cada cadena que escriba el usuario.
    string cadena1, cadena2;

    cout << "Ingrese la primera cadena de caracteres: " << endl;
    cin >> cadena1; // OJO: cin >> corta en el primer espacio, lee una sola palabra

    cout << "Ingrese la segunda cadena de caracteres: " << endl;
    cin >> cadena2;

    // --- PRIMER FILTRO: el tamano ---
    // size() devuelve cuantos caracteres tiene la cadena.
    // Si no miden lo mismo, imposible que sean iguales.
    if (cadena1.size() != cadena2.size())
    {
        cout << "falso" << endl;
        return; // 'return' termina la funcion aqui mismo, no sigue comparando
    }

    // --- SEGUNDO FILTRO: caracter por caracter ---
    // Llegamos aqui solo si ambas miden lo mismo, asi que podemos usar
    // el mismo indice 'i' para las dos sin salirnos del rango.
    //
    // size_t es el tipo que usa C++ para tamanos y posiciones (siempre
    // positivo). Se usa en vez de int para que no de advertencia al
    // compararlo con length().
    for (size_t i = 0; i < cadena1.length(); i++)
    {
        // cadena1[i] es el caracter que esta en la posicion i.
        // Las posiciones empiezan en 0: en "hola" -> h=0, o=1, l=2, a=3.
        if (cadena1[i] != cadena2[i])
        {
            // Con UNA sola diferencia ya no son iguales.
            // No tiene sentido revisar el resto, salimos de una vez.
            cout << "falso" << endl;
            return;
        }
    }

    // Si el for termino completo sin encontrar ninguna diferencia,
    // entonces todos los caracteres coincidieron.
    cout << "verdadero" << endl;
}
