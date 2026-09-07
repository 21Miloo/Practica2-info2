#include <iostream>
#include "problemas.h"

using namespace std;

// Practica 2 - Informatica 2

// Juan Camilo Lopez Castrillon
// Juan David Acevedo

// Universidad de Antioquia

int main()
{
    // La opcion que elige el usuario. El 0 sale del programa.
    // Cada opcion es el numero del problema tal cual aparece en la guia.
    int opcion;

    do{
        cout << endl;
        cout << "===== PRACTICA MANEJO DE MEMORIA =====" << endl;
        cout << "--- PROBLEMAS ---" << endl;
        cout << "  1. Problema 1  - Descomposicion en billetes" << endl;
        cout << "  3. Problema 3  - Comparar dos cadenas" << endl;
        cout << "  5. Problema 5  - Entero a cadena (por referencia)" << endl;
        cout << "  7. Problema 7  - Eliminar caracteres repetidos" << endl;
        cout << "  9. Problema 9  - Separar en numeros de n cifras y sumar" << endl;
        cout << " 11. Problema 11 - Gestion de asientos de sala de cine" << endl;
        cout << " 13. Problema 13 - Contar estrellas en una matriz" << endl;
        cout << " 15. Problema 15 - Interseccion de dos rectangulos" << endl;
        cout << "--------------------------------------" << endl;
        cout << "  0. Salir" << endl;
        cout << "Seleccione una opcion: ";

        cin >> opcion;

        // Si el usuario escribe una letra hay que reparar cin igual que
        // en los problemas. Se le pone -1 a opcion (un valor que no
        // existe en el menu) para que el switch caiga en el default.
        if(cin.fail()){
            cin.clear();             // quita el error de cin
            cin.ignore(10000, '\n'); // limpia la basura que quedo en el buffer
            opcion = -1;
        }

        cout << endl;

        switch(opcion){ // Compara la variable opcion con el caso y ejecuta el que se escoja.

            case 1:
                problema1();
                break;

            case 3:
                problema3();
                break;

            case 5:
                problema5();
                break;

            case 7:
                problema7();
                break;

            case 9:
                problema9();
                break;

            case 11:
                problema11();
                break;

            case 13:
                problema13();
                break;

            case 15:
                problema15();
                break;

            case 0:
                cout << "Saliendo del programa." << endl;
                break;

            // default es lo que pasa cuando 'opcion' no coincide con ningun case.
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
                break;
        }

    } while(opcion != 0);

    return 0;
}
