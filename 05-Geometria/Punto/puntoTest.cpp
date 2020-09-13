#include "punto.h"
#include <cassert>

//Bloque principal

int main (){

//IGUALDAD

    assert ( isIgualPunto({0,0}, {0,0}) );
    assert ( not isIgualPunto({-1,2}, {2,-1}) );
    assert ( isIgualPunto({2.5,107}, {2.5,107}) );
    assert ( not isIgualPunto({10.0,35}, {10,27}) );
    assert ( isIgualPunto({10.0,35}, {10,35}) );

//GET DISTANCIA

    assert ( 1.410 <= getDistancia({2,2}, {1,1}) and 1.425 >= getDistancia({2,2}, {1,1}) );
    assert ( 14.14 <= getDistancia({0,0},{10,10}) and 14.143 >= getDistancia({0,0},{10,10}) );
    assert ( 109.122 <= getDistancia({100,50},{2,2}) and 109.124 >= getDistancia({100,50},{2,2}) );

//GET DISTANCIA AL ORIGEN

    assert ( 0 == getDistanciaAlOrigen({0,0}) );
    assert ( 2.827 <= getDistanciaAlOrigen({2,2}) and 2.829 >= getDistanciaAlOrigen({2,2}) );
    assert ( 111.802 <= getDistanciaAlOrigen({100,50}) and 111.804 >= getDistanciaAlOrigen({100,50}) );
};