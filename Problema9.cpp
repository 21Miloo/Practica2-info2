#include <iostream>
#include <string>
#include "problemas.h"

using namespace std;
//Escribe un programa que reciba un número n y lea una cadena de caracteres numéricos, el programa debe
//separar la cadena de caracteres en números de n cifras, sumarlos e imprimir el resultado. En caso de no poderse
//dividir exactamente en números de n cifras se colocan ceros a la izquierda del primer número.
// Ejemplo: Si n=3 y se lee el arreglo 87512395 la suma sería 087+512+395=994.

// funcion para convertir string a entero
int strToInt(string cadena) {
    int resultado = 0;
    int i = 0; // Contador del bucle
    bool esNegativo = false;
    // Si el primer caracter es '-', es negativo
    if (cadena[0] == '-') {
        esNegativo = true;
        i = 1; // empezamos a leer dígitos desde la posicion 1, saltando el signo
    }
    for (; i < cadena.length(); i++) {
        int digito = cadena[i] - '0'; // Operamos con ASCII: el compilador toma el 8(56 ascii) y le resta 0(48 ascii), da el numero entero = 8, y opera asi con cada digito
        resultado = resultado * 10 + digito; // multiplicamos por 10 para empujar los digitos anteriores un lugar a la izquierda, dejando espacio para el nuevo digito a la derecha
    }
    if (esNegativo) {
        resultado = -resultado; // Si es negativo, le agregamos el signo menos al resultado final
    }
    return resultado;
};

// funcion para separar la cadena de numeros y sumarlos
void separarYSumar(string cadena, int n){
    int longitudCadena = cadena.length();

    // Si no es múltiplo exacto, rellenamos con ceros a la izquierda
    int resto = longitudCadena % n;
    if (resto != 0) {
        int cerosFaltantes = n - resto;
        string ceros(cerosFaltantes, '0'); // crea un string con "cerosFaltantes" copias de '0'
        cadena = ceros + cadena;           // los pega al inicio
        longitudCadena = cadena.length();  // actualizamos la longitud, ya cambió
    }

    int suma = 0;
    for(int i = 0; i < longitudCadena; i += n){ // avanzamos de "n" en "n"
        string trozo = cadena.substr(i, n); // toma "n" caracteres desde la posicion i
        int valor = strToInt(trozo); // usamos nuestra funcion que convierte string a entero
        suma += valor;
        cout << "Trozo: " << trozo << " -> " << valor << endl;
    }
    cout << "Suma total: " << suma << endl;
}

void problema9(){
    int n;
    string cadenaDeNumeros;
    bool valido;
    do{
        valido = true;
        cout << "Ingrese caracteres numericos" << endl;
        cin >> cadenaDeNumeros;
        cout << "Ingrese numero de N cifras de separacion" << endl;
        cin >> n;
        if(cin.fail()){
            valido = false;
            cout << "Entrada invalida. Debe ingresar un numero" << endl;
            cin.clear(); // Quitamos el error
            cin.ignore(10000, '\n'); // Limpiamos el buffer (limpiamos los caracteres que tomo la variable)
        } else if(n <= 0){ // <-- ahora tambien rechaza n=0, evita division por cero
            valido = false;
            cout << "Entrada invalida. La cantidad debe ser mayor a cero" << endl;
        }
    } while(!valido);
    separarYSumar(cadenaDeNumeros, n);
}