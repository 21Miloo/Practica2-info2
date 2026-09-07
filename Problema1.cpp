#include <iostream>
#include "problemas.h"

using namespace std;

void problema1(){

    bool valido;
    int restante;
    int monto;
    int cantidad[10] = {0};
    int billetes[10] = {50000, 20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50};

    do {
        valido = true;
        cout << "Ingrese la cantidad de dinero " << endl;
        cin >> monto;

        if(cin.fail()){
            valido = false;
            cout << "Entrada invalida. Debe ingresar un numero" << endl;
            cin.clear(); // Quitamos el error
            cin.ignore(10000, '\n'); // Limpiamos el buffer (limpiamos los caracteres que tomo la variable)
        } else if(monto < 0){
            valido = false;
            cout << "Entrada invalida. La cantidad no puede ser negativa" << endl;
        }
    } while (!valido);


    restante = monto;

    // De mayor a menor: Cuantos caben (division entera) y con que me quedo -> (el modulo)
    // Recorremos cada denominacion y calculamos cuantas veces cabe en lo que resta
    for (int i = 0; i < 10; ++i) {
        cantidad[i] = restante / billetes[i];
        restante = restante % billetes[i];
    }


    //Imprimimos el resultado
    for (int i = 0; i < 10; ++i) {
        cout << billetes[i] << ": " << cantidad[i] << endl;
    }

    cout << "Faltante: " << restante << endl;

};