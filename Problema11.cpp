#include <iostream>
#include "problemas.h"

using namespace std;

// ============================================================
// PROBLEMA 11: Gestion de asientos de una sala de cine.
//
// La sala es una matriz de caracteres de 15 filas x 20 columnas.
// Cada casilla es un asiento y guarda uno de dos caracteres:
//     '-'  = asiento libre
//     '+'  = asiento reservado
//
// El programa dibuja la sala, pregunta que se quiere hacer
// (reservar / cancelar / salir) y vuelve a empezar.
//
// La parte importante del ejercicio es la TRADUCCION:
// el usuario piensa en "fila C, asiento 5", pero la matriz
// piensa en indices que empiezan en 0 -> sala[2][4].
// ============================================================

void gestionCine() {
    // 'const' significa que estos valores no se pueden cambiar despues.
    // Se usan constantes en vez de escribir 15 y 20 por todo el codigo:
    // si algun dia la sala cambia de tamano, se cambia en un solo lugar.
    const int FILAS = 15;
    const int COLUMNAS = 20;

    // La sala es una matriz de char (caracteres), no de int,
    // porque adentro solo vamos a guardar los simbolos '-' y '+'.
    char sala[FILAS][COLUMNAS];

    // Inicializar la sala con '-' (asientos libres)
    //
    // Esto es OBLIGATORIO. Una matriz recien declarada no viene vacia:
    // trae la basura que hubiera en esa memoria. Si no la llenamos,
    // apareceria cualquier simbolo raro en el tablero.
    //
    // Se recorre con dos ciclos: el de afuera (i) va fila por fila,
    // y por cada fila el de adentro (j) recorre las 20 columnas.
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            sala[i][j] = '-';
        }
    }

    int opcion = 0;   // la opcion del submenu del cine (1, 2 o 3)
    char filaChar;    // la letra de fila que escribe el usuario (A-O)
    int columnaNum;   // el numero de asiento que escribe el usuario (1-20)

    // Este while mantiene el cine abierto. Se repite hasta que el usuario
    // escoja la opcion 3, que es la que devuelve al menu principal.
    while (opcion != 3) {

        // --- DIBUJAR TABLERO ---
        // Se vuelve a dibujar completo en cada vuelta para que se vean
        // los cambios de la reserva anterior.
        cout << "\n================ SALA DE CINE ================\n    ";

        // Encabezado con números de columna usando if-else tradicional
        //
        // Este if es solo cosmetico, para que las columnas queden alineadas:
        // el "1" ocupa 1 caracter y el "10" ocupa 2, entonces al de 1 digito
        // se le pone un espacio extra para que todos midan lo mismo.
        for (int j = 1; j <= COLUMNAS; j++) {
            if (j < 10) {
                cout << " " << j << " "; // Agrega un espacio extra para números de 1 dígito
            } else {
                cout << j << " ";        // Sin espacio extra para números de 2 dígitos
            }
        }
        cout << "\n";

        // Impresión de las filas con sus letras
        for (int i = 0; i < FILAS; i++) {
            // TRUCO DE ASCII: un char por dentro es un numero.
            // 'A' vale 65, entonces 'A'+0 da 'A', 'A'+1 da 'B', 'A'+2 da 'C'...
            // Asi sacamos la letra de cada fila sin escribir un arreglo de letras.
            char letraFila = 'A' + i;
            cout << letraFila << "  ";
            for (int j = 0; j < COLUMNAS; j++) {
                cout << " " << sala[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "==============================================\n";

        // --- PREGUNTAR ACCIÓN ---
        cout << "1. Reservar asiento\n";
        cout << "2. Cancelar reserva\n";
        cout << "3. Volver al menu principal\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        // El switch compara 'opcion' con cada case y ejecuta el que coincida.
        switch (opcion) {

        // OJO con las llaves { } despues de "case 1:".
        // Se ponen porque adentro se declaran variables nuevas (fila, columna).
        // Sin las llaves el compilador se queja, porque no sabria hasta donde
        // existen esas variables.
        case 1: {
            cout << "\n--- RESERVAR ASIENTO ---\n";
            cout << "Ingrese la fila (A-O): ";
            cin >> filaChar;
            cout << "Ingrese el numero de asiento (1-20): ";
            cin >> columnaNum;

            // Convertir minúsculas a mayúsculas manualmente
            //
            // En la tabla ASCII las minusculas estan 32 puestos despues de
            // las mayusculas ('a' vale 97 y 'A' vale 65, y 97 - 65 = 32).
            // Entonces restando 32 convertimos 'c' en 'C'.
            // Esto es para que el usuario pueda escribir la fila en minuscula
            // y el programa igual la entienda.
            if (filaChar >= 'a' && filaChar <= 'o') {
                filaChar = filaChar - 32;
            }

            // --- LA TRADUCCION A INDICES DE LA MATRIZ ---
            // filaChar - 'A' convierte la letra en numero:
            //     'A'-'A' da 0, 'B'-'A' da 1, 'C'-'A' da 2...
            // columnaNum - 1 porque el usuario cuenta desde 1 y la matriz desde 0.
            int fila = filaChar - 'A';
            int columna = columnaNum - 1;

            // --- VALIDACION: primero revisar, despues tocar la matriz ---
            // Este if va ANTES de leer sala[fila][columna]. Si el usuario
            // escribe una fila "Z" o el asiento 99, esos indices se saldrian
            // de la matriz y el programa leeria memoria que no le pertenece
            // (eso se cae o da resultados raros).
            if (fila < 0 || fila >= FILAS || columna < 0 || columna >= COLUMNAS) {
                cout << "\n>> ERROR: Coordenadas fuera de rango.\n";
            } else if (sala[fila][columna] == '+') {
                // Ya esta ocupado, no se puede reservar dos veces
                cout << "\n>> ERROR: El asiento ya esta reservado.\n";
            } else {
                // Solo aqui se modifica la matriz: marcamos el asiento como ocupado
                sala[fila][columna] = '+';
                cout << "\n>> ¡Reserva realizada con exito!\n";
            }
            break; // sale del switch (sin el break seguiria ejecutando el case 2)
        }

        // El case 2 es igualito al case 1 pero al reves:
        // en vez de poner '+' pone '-', y en vez de revisar si ya estaba
        // reservado revisa si ya estaba libre.
        case 2: {
            cout << "\n--- CANCELAR RESERVA ---\n";
            cout << "Ingrese la fila (A-O): ";
            cin >> filaChar;
            cout << "Ingrese el numero de asiento (1-20): ";
            cin >> columnaNum;

            // Convertir minúsculas a mayúsculas manualmente (igual que arriba)
            if (filaChar >= 'a' && filaChar <= 'o') {
                filaChar = filaChar - 32;
            }

            int fila = filaChar - 'A';
            int columna = columnaNum - 1;

            if (fila < 0 || fila >= FILAS || columna < 0 || columna >= COLUMNAS) {
                cout << "\n>> ERROR: Coordenadas fuera de rango.\n";
            } else if (sala[fila][columna] == '-') {
                // No se puede cancelar algo que nadie ha reservado
                cout << "\n>> ERROR: El asiento ya esta libre.\n";
            } else {
                sala[fila][columna] = '-'; // liberamos el asiento
                cout << "\n>> ¡Cancelacion realizada con exito!\n";
            }
            break;
        }

        case 3:
            // Al escribir 3 la condicion del while (opcion != 3) se vuelve
            // falsa, y por eso el ciclo termina y volvemos al menu principal.
            cout << "\nRegresando...\n";
            break;

        // default es lo que pasa cuando 'opcion' no es 1, 2 ni 3.
        default:
            cout << "\n>> Opcion no valida. Intente de nuevo.\n";
            break;
        }
    }
}

// Punto de entrada que llama el menu de main.cpp.
// Se separa en dos funciones para que main.cpp llame siempre al mismo
// nombre (problema11) sin importar como se llame la funcion de adentro.
void problema11(){
    gestionCine();
}
