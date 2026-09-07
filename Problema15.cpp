#include <iostream>
#include <algorithm>
#include "problemas.h"

using namespace std;

// Elabora un programa que permita hallar la interseccion entre un par de rectangulos. Representa los rectangulos como arreglos de 4 datos de la siguiente manera:
// Los primeros 2 datos corresponden a las coordenadas de la esquina superior izquierda del rectangulo (X,Y) como se observa en la figura 5.
// Los siguientes 2 datos representan el ancho y la altura del rectangulo como se observa en la figura 5.

//Implementa una funcion que reciba 2 arreglos que representen los rectangulos A y B, y por referencia retorne un rectangulo C (con la misma estructura descrita anteriormente) que
// corresponda a la interseccion de A y B, como se observa en la figura 6.

//Ej: si se ingresan los rectangulos A y B representados por los arreglos {0,0,8,4} y {5,2,6,7}, el rectangulo interseccion C debe der el srreglo {5,2,3,2}


void interseccionRectangulos(int rectanguloA[], int rectanguloB[], int(&rectanguloC)[4]){

    rectanguloC[0] = max(rectanguloA[0], rectanguloB[0]); // Coordenada en X de la esquina superior izquierda (borde izquierdo)
    rectanguloC[1] = max(rectanguloA[1], rectanguloB[1]); // Coordenada en Y (el eje Y crece hacia abajo, por eso max)

    rectanguloC[2] = min(rectanguloA[0] + rectanguloA[2], rectanguloB[0] + rectanguloB[2]) - rectanguloC[0]; // borde derecho menos X
    rectanguloC[3] = min(rectanguloA[1] + rectanguloA[3], rectanguloB[1] + rectanguloB[3]) - rectanguloC[1]; // borde inferior menos Y

    // Imprimimos el rectanguloC
    cout << "C = {";
    for (int i = 0; i < 4; ++i) {
        cout << rectanguloC[i];
        cout << "," ;
    }
    cout << "}";
}


void problema15(){

    bool valido;
    int rectanguloUno[4];
    int rectanguloDos[4];
    int rectanguloTres[4];

    cout << "Interseccion de Rectangulos" << endl;

    do{

        valido = true;

        cout << "Ingrese datos del primer rectangulo: " <<endl;
        // Llenado del Array
        for (int i = 0; i < 4; ++i) {
            cin >> rectanguloUno[i];

            if(cin.fail()){ // Bloque de validacion
                valido = false;
                cout << "Entrada invalida. Debe ingresar un numero" << endl;
                cin.clear(); // Quitamos el error
                cin.ignore(10000, '\n'); // Limpiamos el buffer (limpiamos los caracteres que tomo la variable)
            }
        }

        cout << "Ingrese datos del segundo rectangulo: " <<endl;
        // Llenado del Array
        for (int i = 0; i < 4; ++i) {

            cin >> rectanguloDos[i];

            if(cin.fail()){ // Bloque de validacion
            valido = false;
            cout << "Entrada invalida. Debe ingresar un numero" << endl;
            cin.clear(); // Quitamos el error
            cin.ignore(10000, '\n'); // Limpiamos el buffer (limpiamos los caracteres que tomo la variable)
            }
        }



    } while(!valido);


    interseccionRectangulos(rectanguloUno, rectanguloDos,rectanguloTres);


}