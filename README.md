# Practica 2 - Laboratorio de Informatica 2

Universidad de Antioquia
Facultad de Ingenieria

## Integrantes

- Juan Camilo Lopez Castrillon
- Juan David Acevedo

## Descripcion

Solucion a los ejercicios y problemas de la practica 2 sobre manejo de memoria en C++
(punteros, arreglos, paso por referencia y matrices).

El programa se ejecuta desde un menu en consola (`main.cpp`) que permite escoger
que problema correr. Cada problema esta implementado en su propio archivo `.cpp` y
sus prototipos estan declarados en `problemas.h`.

## Contenido

| Archivo | Descripcion |
|---|---|
| `ejercicio1.cpp` | Invertir un arreglo usando punteros |
| `Problema1.cpp` | Descomposicion de un monto en billetes |
| `problema3.cpp` | Comparar si dos cadenas son iguales |
| `Problema5.cpp` | Convertir un entero a cadena (por referencia) |
| `Problema7.cpp` | Eliminar caracteres repetidos de una cadena |
| `Problema9.cpp` | Separar una cadena en numeros de n cifras y sumarlos |
| `Problema11.cpp` | Gestion de asientos de una sala de cine |
| `Problema13.cpp` | Contar "estrellas" en una matriz |
| `Problema15.cpp` | Interseccion de dos rectangulos |

## Compilacion y ejecucion

Con CMake:

```bash
cmake -B build
cmake --build build
```

O directamente con g++:

```bash
g++ -std=c++17 -o practica main.cpp ejercicio1.cpp Problema1.cpp problema3.cpp Problema5.cpp Problema7.cpp Problema9.cpp Problema11.cpp Problema13.cpp Problema15.cpp
```

Luego se ejecuta el binario generado y se escoge la opcion deseada en el menu.
La opcion `0` termina el programa.
