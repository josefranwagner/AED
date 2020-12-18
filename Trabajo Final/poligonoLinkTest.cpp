#include "poligonoLink.h"
#include <cassert>

// Bloque principal

int main (){

    poligono p1,p2,p3;
    std::ifstream entrada("datosPoligonos.txt");
    std::ofstream salida ("poligonos.txt");
    
    //GENERACION DE POLIGONOS PARA TEST
    extraerPoligono (entrada, p1);
    entrada.clear();
    extraerPoligono (entrada, p2);
    entrada.clear();
    extraerPoligono (entrada, p3);
    entrada.clear();

    //PRUEBAS

    assert ( getCantidadLados(p1) == 2);
    assert ( getCantidadLados(p2) == 4);
    assert ( getCantidadLados(p3) == 5 );

    // ADD VERTICE
    addVertice (p1,{5,5});
    addVertice (p2,{5,5});
    addVertice (p3,{5,5});

    //GET CANTIDAD DE LADOS
    assert ( getCantidadLados(p1) == 3 );
    assert ( getCantidadLados(p2) == 5 );
    assert ( getCantidadLados(p3) == 6 );

    //GET VERTICE
    assert ( isIgualPunto(getVertice(p1,3),{5,5}) );
    assert ( isIgualPunto(getVertice(p2,5),{5,5}) );
    assert ( isIgualPunto(getVertice(p3,6),{5,5}) );
    
    //SET VERTICE
    setVertice(p1,1,{-5,-5});
    setVertice(p2,1,{-5,-5});
    setVertice(p3,1,{-5,-5});
    assert ( isIgualPunto(getVertice(p1,1),{-5,-5}) );
    assert ( isIgualPunto(getVertice(p2,1),{-5,-5}) );
    assert ( isIgualPunto(getVertice(p3,1),{-5,-5}) );

    //REMOVE VERTICE
    assert ( getCantidadLados(p1) == 3 );
    assert ( getCantidadLados(p2) == 5 );
    assert ( getCantidadLados(p3) == 6 );
    removeVertice(p1);
    removeVertice(p2);
    removeVertice(p3);
    assert ( getCantidadLados(p1) == 2 );
    assert ( getCantidadLados(p2) == 4 );
    assert ( getCantidadLados(p3) == 5 );

    //GET PERIMETRO

    assert ( 16.96 <= get_getPerimetro(p1) and 16.98 >= get_getPerimetro(p1) );
    assert ( 45.24 <= get_getPerimetro(p2) and 45.26 >= get_getPerimetro(p2) );
    assert ( 48.07 <= get_getPerimetro(p3) and 48.09 >= get_getPerimetro(p3) );

};
