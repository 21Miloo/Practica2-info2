cmake_minimum_required(VERSION 3.16)

project(practica-manejo-memoria LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(practica-manejo-memoria main.cpp
    Problema1.cpp
    Problema5.cpp
    Problema9.cpp
    problemas.h
    problema3.cpp
    Problema7.cpp
    Problema13.cpp
    ejercicio1.cpp
    Problema15.cpp
    Problema11.cpp)

include(GNUInstallDirs)
install(TARGETS practica-manejo-memoria
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
