/*
Programa: IsBisiesto
Objetivo: Realizar una función que, dado un año, indique si dicho año es bisiesto.
Autor: Jose Francisco Wagner
Ultima modificación: 20200610
*/

//  Inclusión de librerías externas

#include <cassert>

//  Prototipo de la función

bool IsBisiesto (unsigned);

//  BLOQUE PRINCIPAL

int main (){

    assert (IsBisiesto(2020));
    assert (not IsBisiesto(2010));
    assert (IsBisiesto(2000));
    assert (IsBisiesto(1584));
    assert (not IsBisiesto(1582));
    assert (not IsBisiesto(1580));
    assert (not IsBisiesto(1560));
    assert (not IsBisiesto(1578));
    assert (not IsBisiesto(1590));
    assert (IsBisiesto(1588));
    assert (not IsBisiesto(1542));
}

//  Definición de la función

bool IsBisiesto (unsigned anio){
    return ((anio >= 1582) and (anio%4 == 0) and (not anio%100 == 0 or anio%400 == 0));
}
