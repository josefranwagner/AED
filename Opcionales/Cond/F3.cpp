/*
Programa: Función f3
Objetivo: Realizar una funcion llamada f3 que devuelva el valor f3(x) = x para todo x perteneciente al intervalo (-oo,-3) U {0} U (3,+oo) y f3(x) = -x en otro caso.
Autor: Jose Francisco Wagner
Ultima modificación: 20200604
*/

// Inclusión de librerías externas

#include <cassert>

// Prototipo de la función

double f3 (double);

// BLOQUE PRINCIPAL

int main (){
    assert (-5==f3(-5));
    assert (3==f3(-3));
    assert (1==f3(-1));
    assert (0==f3(0));
    assert (-1==f3(1));
    assert (-3==f3(3));
    assert (5==f3(5));
}

// Definición de la función

double f3 (double x) {return
    (x>=-3 and x<0) or (x>0 and x<=3) ? -x 
    : x ;}
    
