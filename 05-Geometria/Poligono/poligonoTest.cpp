#include "poligono.h"
#include <cassert>

// Bloque principal

int main (){

    poligono poligono1 = {4,{ { {2,2},{1,1},{0,0},{10,10} } }, {255,0,0}};
    poligono poligono2 = {5,{ { {100,50},{2,2},{1,1},{0,0},{10,10} } }, {0,255,0}};
    poligono poligono3 = {7,{ { {15.8,9},{5,2.5},{0,7},{3.2,3.3},{5,8},{12,3.1},{1,0.5} } }, {255,255,0}};

//ADD VERTICE

    addVertice(poligono1, {2,2});
    addVertice(poligono2, {2,2});
    addVertice(poligono3, {2,2});
    assert ( poligono1.puntos.at(poligono1.lados-1).x == 2 );
    assert ( poligono1.puntos.at(poligono1.lados-1).y == 2 );
    assert ( poligono2.puntos.at(poligono2.lados-1).x == 2 );
    assert ( poligono2.puntos.at(poligono2.lados-1).y == 2 );
    assert ( poligono3.puntos.at(poligono3.lados-1).x == 2 );
    assert ( poligono3.puntos.at(poligono3.lados-1).y == 2 );

//GET VERTICE

    assert ( 1 == getVertice(poligono1,2).x );
    assert ( 1 == getVertice(poligono1,2).y );
    assert ( 2 == getVertice(poligono2,2).x );
    assert ( 2 == getVertice(poligono2,2).y );
    assert ( 5 == getVertice(poligono3,2).x );
    assert ( 2.5 == getVertice(poligono3,2).y );

//SET VERTICE

    setVertice (poligono1, 1, {-1,-1});
    setVertice (poligono2, 1, {-1,-1});
    setVertice (poligono3, 1, {-1,-1});
    assert ( -1 == poligono1.puntos.at(0).x );
    assert ( -1 == poligono1.puntos.at(0).y );
    assert ( -1 == poligono2.puntos.at(0).x );
    assert ( -1 == poligono2.puntos.at(0).y );
    assert ( -1 == poligono3.puntos.at(0).x );
    assert ( -1 == poligono3.puntos.at(0).y );

//REMOVE VERTICE

    poligono1 = {4,{ { {2,2},{1,1},{0,0},{10,10} } }, {255,0,0}};
    poligono2 = {5,{ { {100,50},{2,2},{1,1},{0,0},{10,10} } }, {0,255,0}};
    poligono3 = {7,{ { {15.8,9},{5,2.5},{0,7},{3.2,3.3},{5,8},{12,3.1},{1,0.5} } }, {255,255,0}};

    removeVertice(poligono1);
    removeVertice(poligono2);
    removeVertice(poligono3);
    assert ( 3 == poligono1.lados );
    assert ( 4 == poligono2.lados );
    assert ( 6 == poligono3.lados );

//GET CANTIDAD DE LADOS

    poligono1 = {4,{ { {2,2},{1,1},{0,0},{10,10} } }, {255,0,0}};
    poligono2 = {5,{ { {100,50},{2,2},{1,1},{0,0},{10,10} } }, {0,255,0}};
    poligono3 = {7,{ { {15.8,9},{5,2.5},{0,7},{3.2,3.3},{5,8},{12,3.1},{1,0.5} } }, {255,255,0}};

    assert ( 4 == getCantidadLados(poligono1) );
    assert ( 5 == getCantidadLados(poligono2) );
    assert ( 7 == getCantidadLados(poligono3) );

//GET PERIMETRO

    poligono1 = {4,{ { {2,2},{1,1},{0,0},{10,10} } }, {255,0,0}};
    poligono2 = {5,{ { {100,50},{2,2},{1,1},{0,0},{10,10} } }, {0,255,0}};
    poligono3 = {7,{ { {15.8,9},{5,2.5},{0,7},{3.2,3.3},{5,8},{12,3.1},{1,0.5} } }, {255,255,0}};

    assert ( 28.283 <= get_getPerimetro(poligono1) and 28.285 >= get_getPerimetro(poligono1) );
    assert ( 224.581 <= get_getPerimetro(poligono2) and 224.583 >= get_getPerimetro(poligono2) );
    assert ( 66.170 <= get_getPerimetro(poligono3) and 66.172 >= get_getPerimetro(poligono3) );
};