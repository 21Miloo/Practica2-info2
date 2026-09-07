#include <iostream>
#include "problemas.h"

using namespace std;

// ============================================================
// PROBLEMA 13: Contar cuantas "estrellas" hay en una matriz de 6x8.
//
// Que es una estrella:
//   Una estrella es una cruz de 5 casillas: una casilla del centro
//   mas sus 4 vecinas (arriba, abajo, izquierda y derecha).
//
//                    arriba
//        izquierda   CENTRO   derecha
//                    abajo
//
//   Se cuenta como estrella si el PROMEDIO de esas 5 casillas es mayor a 6.
//   Promedio = suma de las 5 casillas dividida entre 5.
// ============================================================

// --- POR QUE EL PARAMETRO SE ESCRIBE ASI: int (*matriz)[8] ---
//
// Cuando se pasa una matriz a una funcion, C++ NO copia la matriz: lo que
// llega es la direccion de memoria donde empieza. Por eso se recibe un puntero.
//
// int (*matriz)[8] se lee: "matriz es un puntero a un arreglo de 8 enteros",
// o sea, un puntero que apunta a UNA FILA completa de 8 numeros.
//
// El 8 (numero de columnas) es obligatorio; el 6 (numero de filas) no, porque
// para moverse de una fila a otra el compilador solo necesita saber cuanto
// mide una fila.
//
// OJO con los parentesis: int (*matriz)[8] es un puntero a un arreglo de 8 int,
// mientras que int *matriz[8] seria un arreglo de 8 punteros. No es lo mismo.
int contarEstrellas(int (*matriz)[8]) // recibe un puntero a una fila de 8 enteros
{
    int estrellas = 0; // aqui vamos acumulando cuantas encontramos

    // --- POR QUE LOS CICLOS NO EMPIEZAN EN 0 ---
    // El centro de la estrella necesita tener vecina arriba, abajo, izquierda
    // y derecha. Las casillas del borde no las tienen todas, entonces no
    // pueden ser centro de una estrella.
    //
    // Filas: van de 0 a 5, asi que los centros validos son de 1 a 4.
    // Columnas: van de 0 a 7, asi que los centros validos son de 1 a 6.
    //
    // Si empezaramos en 0 nos saldriamos de la matriz y leeriamos basura
    // de la memoria (o el programa se cae).
    for (int i = 1; i < 5; i++) // evitamos la primera y última fila
    {
        for (int j = 1; j < 7; j++) // evitamos la primera y ultima columna
        {
            // --- COMO LEER *(*(matriz + i) + j) ---
            // Es exactamente lo mismo que escribir matriz[i][j], pero hecho
            // "a mano" con punteros. Se lee de adentro hacia afuera:
            //
            //   matriz + i      -> avanza i filas desde el inicio
            //   *(matriz + i)   -> entra a esa fila (es la fila i completa)
            //   *(matriz+i) + j -> avanza j casillas dentro de esa fila
            //   *(*(matriz+i)+j)-> lee el numero que hay en esa casilla
            //
            // El asterisco (*) significa "dame el valor que hay en esa direccion".
            int suma =
                *(*(matriz + i) + j)       // centro
                + *(*(matriz + i) + j - 1) // izquierda (misma fila, una columna atras)
                + *(*(matriz + i) + j + 1) // derecha   (misma fila, una columna adelante)
                + *(*(matriz + i - 1) + j) // arriba    (fila anterior, misma columna)
                + *(*(matriz + i + 1) + j); // abajo    (fila siguiente, misma columna)

            // --- POR QUE 5.0 Y NO 5 ---
            // Con 5.0 la division da decimales (division real).
            // Si escribieramos suma / 5 seria division ENTERA y botaria los
            // decimales: 33/5 daria 6 en vez de 6.6, y esa estrella no se
            // contaria porque 6 no es mayor que 6.
            if (suma / 5.0 > 6)
            {
                estrellas++; // encontramos una, sumamos 1 al contador
            }
        }
    }

    return estrellas; // devolvemos el total al que llamo la funcion
}

void problema13()
{
    // La matriz viene fija en el enunciado, no la pide el usuario.
    // 6 filas x 8 columnas.
    int matriz[6][8] =
        {
            {0, 3, 4, 0, 0, 0, 6, 8},
            {5, 13, 6, 0, 0, 0, 2, 3},
            {2, 6, 2, 7, 3, 0, 10, 0},
            {0, 0, 4, 15, 4, 1, 6, 0},
            {0, 0, 7, 12, 6, 9, 10, 4},
            {5, 0, 6, 10, 6, 4, 8, 0}
        };

    // Al pasar 'matriz' a la funcion, el nombre de la matriz se convierte
    // solo en la direccion de su primera fila. Por eso encaja con el
    // parametro int (*matriz)[8] sin tener que escribir nada raro.
    //
    // Con esta matriz el resultado es 5 estrellas.
    cout << "Numero de estrellas: " << contarEstrellas(matriz) << endl;
}
