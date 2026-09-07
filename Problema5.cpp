#include <iostream>
#include <string>
#include "problemas.h"
#include "problemas.h"


using namespace std;

// Haz una funcion que reciba un numero entero (int) y lo convierta a cadena de caracteres.
// Usa parametros por referencia para retornar la cadena. Escribe un programa de prueba.
// Ej: Si recibe un int con valor 123, la cadena que se retorne debe ser "123".



//Convierte entero a cadena de caracteres
void intToStr(int numero, string &resultado){

    bool esNegativo = false;

    if(numero <0){
        esNegativo = true;
        numero = -numero;
    }

    if(numero ==0){
        resultado = "0";
        return; //finaliza la funcion
    }

    //Algoritmo clave -----------------------------
    string temp = ""; // variable temporal
    while (numero>0){
        int digito = numero % 10; // sacamos modulo 10 ya que siempre el residuo nos dara el mismo digito.
        char c = digito + '0'; //  convertimos el digito a caracter // Se usa comilla simple en el 0 para representar un solo caracter
        temp = c + temp;
        numero = numero / 10; // quitamos el ultimo digito
    }

    if(esNegativo){
        resultado = "-" + temp;
    } else {
        resultado = temp;
    }

}


void problema5(){

    int numero;
    string cadena;
    bool valido;

    // Validacion de Entrada ------------------------------------------------------------------------------
    do{
        valido = true;
        cout << "Ingrese numero entero" << endl;
        cin >> numero;

        if(cin.fail()){
            valido = false;
            cout << "Entrada invalida. Debe ingresar un numero" << endl;
            cin.clear(); // Quitamos el error
            cin.ignore(10000, '\n'); // Limpiamos el buffer (limpiamos los caracteres que tomo la variable)
        }
    } while (!valido);

    intToStr(numero, cadena); // Cadena se llena dentro de la funcion. El valor global de cadena se cambia gracias a que se pasa como parametro por referencia &

    cout << "La cadena resultante es: \"" << cadena << "\"" << endl;


}

