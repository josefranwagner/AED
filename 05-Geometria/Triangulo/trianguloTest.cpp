#include "triangulo.h"
#include <cassert>

// Bloque principal

int main (){

    triangulo triangulo1 = { { { {100,50},{2,2},{1,1} } }, {255,255,255}};
    triangulo triangulo2 = { { { {10.2,5},{0,-3},{5.1,12} } }, {0,0,0}};
    triangulo triangulo3 = { { { {0,0},{2,2},{4,0} } }, {0,255,255}};

//GET PERIMETRO

    assert ( 221.0005 <= getPerimetro(triangulo1) and 221.0007 >= getPerimetro(triangulo1) );
    assert ( 37.466 <= getPerimetro(triangulo2) and 37.468 >= getPerimetro(triangulo2) );
    assert ( 9.655 <= getPerimetro(triangulo3) and 9.657 >= getPerimetro(triangulo3) );

//GET AREA

    assert ( 24.9 <= getArea(triangulo1) and 25.1 >= getArea(triangulo1) );
    assert ( 56.0 <= getArea(triangulo2) and 56.2 >= getArea(triangulo2) );
    assert ( 3.9 <= getArea(triangulo3) and 4.1 >= getArea(triangulo3) );

//IS ESCALENO/EQUILATERO/ISOCELES

    assert ( isEscaleno(triangulo1) );
    assert ( isEscaleno(triangulo2) );
    assert ( not isEscaleno(triangulo3) );
    assert ( not isEquilatero(triangulo1) );
    assert ( not isEquilatero(triangulo2) );
    assert ( not isEquilatero(triangulo3) );
    assert ( not isIsosceles(triangulo1) );
    assert ( not isIsosceles(triangulo2) );
    assert ( isIsosceles(triangulo3) );

//GET TIPO TRIANGULO

    assert ( t_tipoTriangulo::Escaleno == getTipo(triangulo1) );
    assert ( t_tipoTriangulo::Escaleno == getTipo(triangulo2) );
    assert ( t_tipoTriangulo::Isosceles == getTipo(triangulo3) );
    
};