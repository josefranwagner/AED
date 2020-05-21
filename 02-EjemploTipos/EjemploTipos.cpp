/*
Programa: Ejemplo Tipos
Objetivo: Demostrar la aplicación de tipos de datos aprendida en clase
Autor: Jose Francisco Wagner
Ultima modificación: 20200520
*/

#include <iostream>
#include <cassert>  // Se incluye la librería cassert para hacer uso de la funcion 'assert'

int main (){

    int numeroNegativo=-2;  //tipo de dato entero inicializado en -2
    std::string saludoInicial="Hola";   //cadena "Hola"
    std::string saludoFinal="Mundo";    //cadena "Mundo"
    bool saludo=false;  //tipo de dato booleano inicializado en false
    unsigned numeroPositivo=6;  //tipo de dato unsigned inicializa en 6
    double numeroReal=14.0;    //tipo de dato real inicializado en 14.0
    char letra='A';  //tipo de dato caracter inicializado en 'A'

    assert(saludoInicial+saludoFinal=="HolaMundo"); //Concatenacion de strings
    saludo=true;
    assert(saludo); //Como saludo ahora es verdadero pasa la validación
    assert(saludoInicial+letra=="HolaA");   //Concatenacion de strings+char
    assert(numeroReal/numeroNegativo==-7.0);  //Como 14/(-2) = -7 pasa la validación
    assert(numeroNegativo+numeroPositivo>0);    //Como -2+6 > 0 pasa la validación
    assert(numeroNegativo-numeroPositivo==4);   //Como -2-6 = -8 el programa detiene su ejecución
}

