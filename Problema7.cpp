#include <iostream>
#include <string>
#include "problemas.h"

using namespace std;

// ============================================================
// PROBLEMA 7: Eliminar los caracteres repetidos de una cadena.
//
// La idea:
//   Se deja la PRIMERA aparicion de cada caracter y se borran las demas.
//   Para eso usamos dos ciclos, uno dentro del otro:
//
//     - El ciclo de afuera (n) va parado en un caracter a la vez.
//       Ese es el caracter "que se queda".
//     - El ciclo de adentro (i) revisa TODO lo que viene despues de n
//       buscando copias de ese caracter, y las borra.
//
//   Como el ciclo de afuera avanza de izquierda a derecha, cuando llega
//   a una posicion ya no quedan copias de los caracteres anteriores.
//
//   Ej: "programacion" -> "progamcin"
//       (se borro la 2da 'r', la 2da 'o', la 2da 'a'... y asi)
// ============================================================

void problema7()
{
    string cadena;

    cout << "Ingrese una cadena de caracteres: " << endl;
    cin >> cadena; // OJO: cin >> lee una sola palabra, corta en el espacio

    // Ciclo de afuera: 'n' es el caracter que estamos revisando y que se queda.
    for  (size_t n = 0; n < cadena.length(); n++)
    {
        // Ciclo de adentro: arranca en n+1, o sea justo DESPUES de n,
        // porque solo nos interesa lo que viene mas adelante.
        // (Si empezara en 0 se compararia el caracter consigo mismo
        //  y se borraria a si mismo.)
        for (size_t i = n+1; i < cadena.length(); i++)
        {
            // Encontramos una copia del caracter que esta en la posicion n
            if (cadena[n] == cadena[i])
            {
                // erase(i, 1) borra 1 caracter empezando en la posicion i.
                cadena.erase(i,1);

                // ESTA LINEA ES LA CLAVE Y ES FACIL DE OLVIDAR:
                // al borrar, todos los caracteres de la derecha se corren
                // un puesto hacia la izquierda para tapar el hueco. Eso
                // significa que en la posicion i ya hay un caracter NUEVO
                // que todavia no hemos revisado.
                // Con i-- devolvemos el contador, y como el for hace i++
                // enseguida, terminamos revisando otra vez la misma
                // posicion i en vez de saltarnosla.
                //
                // Sin el i--, en "aabb" se saltaria caracteres y quedarian
                // repetidos sin borrar.
                i--;
            }
        }

        // OJO: cadena.length() se vuelve a consultar en cada vuelta del for,
        // por eso no hay problema con que la cadena se vaya achicando
        // mientras la recorremos.
    }

    cout<< cadena << endl;
}
