/*
Programa: Función Minimo
Objetivo: Realizar una función que devuelva el minimo entre dos valores dados.
Autor: Jose Francisco Wagner
Ultima modificación: 20200604
*/

// Inclusión de librerías externas

#include <cassert>
#include <iostream>

// Prototipo de la función

int Min (int,int);

// BLOQUE PRINCIPAL

int main (){
    assert (4==Min(4,8));   //Se espera que la funcion Min devuelva el minimo entre 4 y 8, en este caso 4.
    assert (4==Min(8,4));   //Se espera que la funcion Min devuelva el minimo entre 8 y 4, en este caso 4.
    assert (4==Min(4,4));   //Se espera que la funcion Min devuelva el minimo entre 4 y 4, en este caso 4.
}

// Definición de la función

int Min (int a,int b){return
    a<b ? a 
    : b ;}
