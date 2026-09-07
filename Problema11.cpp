#include <iostream>
#include "problemas.h"

using namespace std;

void gestionCine() {
    const int FILAS = 15;
    const int COLUMNAS = 20;
    char sala[FILAS][COLUMNAS];

    // Inicializar la sala con '-' (asientos libres)
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            sala[i][j] = '-';
        }
    }

    int opcion = 0;
    char filaChar;
    int columnaNum;

    while (opcion != 3) {

        // --- DIBUJAR TABLERO ---
        cout << "\n================ SALA DE CINE ================\n    ";

        // Encabezado con números de columna usando if-else tradicional
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

        switch (opcion) {
        case 1: {
            cout << "\n--- RESERVAR ASIENTO ---\n";
            cout << "Ingrese la fila (A-O): ";
            cin >> filaChar;
            cout << "Ingrese el numero de asiento (1-20): ";
            cin >> columnaNum;

            // Convertir minúsculas a mayúsculas manualmente
            if (filaChar >= 'a' && filaChar <= 'o') {
                filaChar = filaChar - 32;
            }

            int fila = filaChar - 'A';
            int columna = columnaNum - 1;

            if (fila < 0 || fila >= FILAS || columna < 0 || columna >= COLUMNAS) {
                cout << "\n>> ERROR: Coordenadas fuera de rango.\n";
            } else if (sala[fila][columna] == '+') {
                cout << "\n>> ERROR: El asiento ya esta reservado.\n";
            } else {
                sala[fila][columna] = '+';
                cout << "\n>> ¡Reserva realizada con exito!\n";
            }
            break;
        }

        case 2: {
            cout << "\n--- CANCELAR RESERVA ---\n";
            cout << "Ingrese la fila (A-O): ";
            cin >> filaChar;
            cout << "Ingrese el numero de asiento (1-20): ";
            cin >> columnaNum;

            // Convertir minúsculas a mayúsculas manualmente
            if (filaChar >= 'a' && filaChar <= 'o') {
                filaChar = filaChar - 32;
            }

            int fila = filaChar - 'A';
            int columna = columnaNum - 1;

            if (fila < 0 || fila >= FILAS || columna < 0 || columna >= COLUMNAS) {
                cout << "\n>> ERROR: Coordenadas fuera de rango.\n";
            } else if (sala[fila][columna] == '-') {
                cout << "\n>> ERROR: El asiento ya esta libre.\n";
            } else {
                sala[fila][columna] = '-';
                cout << "\n>> ¡Cancelacion realizada con exito!\n";
            }
            break;
        }

        case 3:
            cout << "\nRegresando...\n";
            break;

        default:
            cout << "\n>> Opcion no valida. Intente de nuevo.\n";
            break;
        }
    }
}

// Punto de entrada que llama el menu de main.cpp
void problema11(){
    gestionCine();
}
