#include <iostream>
#include "problemas.h"

using namespace std;

int contarEstrellas(int (*matriz)[8]) // recibe un puntero a una fila de 8 enteros
{
    int estrellas = 0;

    for (int i = 1; i < 5; i++) // evitamos la primera y última fila
    {
        for (int j = 1; j < 7; j++) // evitamos la primera y ultima columna
        {
            int suma =
                *(*(matriz + i) + j)       // centro
                + *(*(matriz + i) + j - 1) // izquierda
                + *(*(matriz + i) + j + 1) // derecha
                + *(*(matriz + i - 1) + j) // arriba
                + *(*(matriz + i + 1) + j); // abajo

            if (suma / 5.0 > 6)
            {
                estrellas++;
            }
        }
    }

    return estrellas;
}

void problema13()
{
    int matriz[6][8] =
        {
            {0, 3, 4, 0, 0, 0, 6, 8},
            {5, 13, 6, 0, 0, 0, 2, 3},
            {2, 6, 2, 7, 3, 0, 10, 0},
            {0, 0, 4, 15, 4, 1, 6, 0},
            {0, 0, 7, 12, 6, 9, 10, 4},
            {5, 0, 6, 10, 6, 4, 8, 0}
        };

    cout << "Numero de estrellas: " << contarEstrellas(matriz) << endl;
}