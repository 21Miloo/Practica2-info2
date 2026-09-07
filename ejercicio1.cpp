#include <iostream>
#include "problemas.h"

// ============================================================
// Este programa invierte un arreglo (array) usando punteros.
// Usa dos funciones:
//   - fun_a: intercambia (swap) los valores de dos variables usando punteros
//   - fun_b: recorre el arreglo desde los extremos hacia el centro,
//            llamando a fun_a para ir invirtiendo el orden
// ============================================================

using namespace std;

// Declaraciones (prototipos) de las funciones.
// Esto le dice al compilador "estas funciones existen y las voy
// a definir más abajo", para que main() las pueda usar sin problema.
void fun_a(int *px, int *py);
void fun_b(int a[], int tam);

void ejercicio1()
{
    // Creamos un arreglo de 10 enteros, inicializado con los valores 0 a 9.
    int array[10] = {0,1,2,3,4,5,6,7,8,9};

    // Llamamos a fun_b, pasando el arreglo y su tamaño (10).
    // OJO: en C++, cuando pasas un arreglo a una función, en realidad
    // se pasa la DIRECCIÓN de memoria del primer elemento (decae a puntero).
    // Por eso fun_b puede modificar el arreglo original directamente,
    // sin necesidad de "devolverlo".
    fun_b(array, 10);

    // Mostramos el arreglo ya invertido.
    cout << "Arreglo invertido: ";
    for(int k = 0; k < 10; k++){
        cout << array[k] << " ";
    }
    cout << endl;
}

// ------------------------------------------------------------
// fun_a: función de INTERCAMBIO (SWAP)
// ------------------------------------------------------------
// Recibe DOS PUNTEROS a enteros (px y py), es decir, recibe las
// direcciones de memoria de dos variables, no los valores directamente.
// Esto le permite modificar los valores ORIGINALES desde fuera de main,
// algo que no podría hacer si recibiera los enteros por valor (int x, int y).
void fun_a(int *px, int *py){

    // *px significa "el valor que está guardado en la dirección px"
    // (esto se llama "desreferenciar" el puntero).
    // Guardamos ese valor en una variable temporal para no perderlo.
    int tmp = *px;

    // Ahora copiamos el valor de *py dentro de *px.
    // Es decir: "lo que apunta px, ahora vale lo mismo que lo que apunta py".
    *px = *py;

    // Y finalmente ponemos en *py el valor que habíamos guardado en tmp
    // (el valor original de *px).
    *py = tmp;

    // Resultado: los dos valores quedaron intercambiados.
}

// ------------------------------------------------------------
// fun_b: INVIERTE el arreglo "en su lugar" (in-place)
// ------------------------------------------------------------
// Recibe:
//   - a[]: el arreglo (en realidad, un puntero al primer elemento)
//   - tam: el tamaño del arreglo (cuántos elementos tiene)
void fun_b(int a[], int tam){

    int f, i; // f = índice desde el frente (front), i = índice desde el final

    // b es un puntero que apunta al mismo lugar que a.
    // Aquí no era estrictamente necesario crear "b" (podríamos usar "a"
    // directamente), pero es válido y funciona igual.
    int *b = a;

    // Ciclo for con DOS variables de control a la vez:
    //   - f empieza en 0 (el primer elemento)
    //   - i empieza en tam-1 (el último elemento, porque los índices
    //     de un arreglo van de 0 a tam-1)
    // La condición f < i significa "mientras no se hayan cruzado los
    // índices" (es decir, mientras aún queden elementos por intercambiar
    // desde afuera hacia el centro).
    // En cada vuelta: f aumenta en 1, e i disminuye en 1.
    for(f=0, i=tam-1; f<i; f++, i--){

        // &b[f] es "la dirección de memoria del elemento en la posición f"
        // &b[i] es "la dirección de memoria del elemento en la posición i"
        // Le pasamos esas direcciones a fun_a, para que intercambie
        // los valores en esas posiciones del arreglo original.
        fun_a(&b[f], &b[i]);
    }

    // Al terminar el ciclo, el arreglo queda invertido.
    // Ejemplo: {0,1,2,3,4,5,6,7,8,9} --> {9,8,7,6,5,4,3,2,1,0}
}