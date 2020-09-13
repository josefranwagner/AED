/*
Programa: Función Ansoluto
Objetivo: Realizar una función que devuelva el valor absoluto de un valor dado.
Autor: Jose Francisco Wagner
Ultima modificación: 20200604
*/

// Inclusión de librerías externas

#include <cassert>
#include <iostream>

// Prototipo de la función

int Abs(int);

// BLOQUE PRINCIPAL

int main (){
    assert(2==Abs(-2)); //Se espera que el valor que devuelva la función sea 2
    assert(0==Abs(0));  //Se espera que el valor que devuelva la función sea 0
    assert(2==Abs(2));  //Se espera que el valor que devuelva la función sea 2
}

// Definición de la función

int Abs(int x){return 
    x<0 ? -x 
    : x ;}
