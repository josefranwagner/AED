/*
Programa: Color + Geometría (punto, triangulo y poligono)
Objetivo: Creación de tipos de datos punto, color, triangulo y poligono. Definir operaciones y ejecutar pruebas sobre ellas.
Autor: Jose Francisco Wagner
Ultima modificación: 20200910.
*/

#include "figuras.h"
#include <cassert>

// Bloque principal

int main (){

    poligono poligono1 = {4,{ { {2,2},{1,1},{0,0},{10,10} } }, RED};
    poligono poligono2 = {5,{ { {100,50},{2,2},{1,1},{0,0},{10,10} } }, GREEN};
    poligono poligono3 = {7,{ { {15.8,9},{5,2.5},{0,7},{3.2,3.3},{5,8},{12,3.1},{1,0.5} } }, YELLOW};
    triangulo triangulo1 = { { { {100,50},{2,2},{1,1} } }, WHITE};
    triangulo triangulo2 = { { { {10.2,5},{0,-3},{5.1,12} } }, BLACK};
    triangulo triangulo3 = { { { {0,0},{2,2},{4,0} } }, CYAN};

// PRUEBAS COLOR

    //SUMAR COLORES

    assert ( 255 == sumarColores({125,0,0}, {130,0,0}).red );
    assert ( 0 == sumarColores({125,0,0}, {130,0,0}).green );
    assert ( 0 == sumarColores({125,0,0}, {130,0,0}).blue );
    assert ( 0 == sumarColores(GREEN, GREEN).red );
    assert ( 255 == sumarColores(GREEN, GREEN).green );
    assert ( 0 == sumarColores(GREEN, GREEN).blue );
    assert ( 255 == sumarColores(YELLOW, CYAN).red );
    assert ( 255 == sumarColores(YELLOW, CYAN).green );
    assert ( 255 == sumarColores(YELLOW, CYAN).blue );

    //RESTAR COLORES

    assert ( 0 == restarColores(BLACK, WHITE).red );
    assert ( 0 == restarColores(BLACK, WHITE).green );
    assert ( 0 == restarColores(BLACK, WHITE).blue );
    assert ( 0 == restarColores({123,45,87}, {182,35,65}).red );
    assert ( 10 == restarColores({123,45,87}, {182,35,65}).green );
    assert ( 22 == restarColores({123,45,87}, {182,35,65}).blue );
    assert ( 245 == restarColores({245,227,32}, GREEN).red );
    assert ( 0 == restarColores({245,227,32}, GREEN).green );
    assert ( 255 == restarColores({245,227,255}, GREEN).blue );

    //IGUALDAD COLORES

    assert ( isIgualColor({0,0,255}, BLUE) );
    assert ( isIgualColor(CYAN, {0,255,255}) );
    assert ( not isIgualColor({0,123,242}, {125,80,150}));

    //MEZCLAR COLORES

    assert ( 255 == mezclarColores(MAGENTA, YELLOW).red );
    assert ( 127 == mezclarColores(MAGENTA, YELLOW).green );
    assert ( 127 == mezclarColores(MAGENTA, YELLOW).blue );
    assert ( 200 == mezclarColores({145,50,37}, YELLOW).red );
    assert ( 152 == mezclarColores({145,50,37}, YELLOW).green );
    assert ( 18 == mezclarColores({145,50,37}, YELLOW).blue );
    assert ( 49 == mezclarColores({21,32,198}, {78,12,25}).red );
    assert ( 22 == mezclarColores({21,32,198}, {78,12,25}).green );
    assert ( 111 == mezclarColores({21,32,198}, {78,12,25}).blue );

    //COMPLEMENTARIO

    assert ( CYAN.red == getComplementario(RED).red );
    assert ( CYAN.green == getComplementario(RED).green );
    assert ( CYAN.blue == getComplementario(RED).blue );
    assert ( WHITE.red == getComplementario(BLACK).red );
    assert ( WHITE.green == getComplementario(BLACK).green );
    assert ( WHITE.blue == getComplementario(BLACK).blue );
    assert ( 110 == getComplementario({145,50,37}).red );
    assert ( 205 == getComplementario({145,50,37}).green );
    assert ( 218 == getComplementario({145,50,37}).blue );    

    //GET HTML

    assert ( "#ff0000" == getHtmlHex(RED) );
    assert ( "#87cefa" == getHtmlHex({135,206,250}) );
    assert ( "#ffe4e1" == getHtmlHex({255,228,225}) );

    //GET RGB

    assert ( "rgb(255,0,0)" == getHtmlRgb(RED) );
    assert ( "rgb(253,245,230)" == getHtmlRgb({253,245,230}) );
    assert ( "rgb(255,255,255)" == getHtmlRgb(WHITE) );

// PRUEBAS PUNTO

    //IGUALDAD

    assert ( isIgualPunto({0,0}, {0,0}) );
    assert ( not isIgualPunto({-1,2}, {2,-1}) );
    assert ( isIgualPunto({2.5,107}, {2.5,107}) );
    assert ( not isIgualPunto({10.0,35}, {10,27}) );
    assert ( isIgualPunto({10.0,35}, {10,35}) );

    //GET DISTANCIA

    assert ( 1.410 <= getDistancia(poligono1.puntos.at(0), poligono1.puntos.at(1)) and 1.425 >= getDistancia(poligono1.puntos.at(0), poligono1.puntos.at(1)) );
    assert ( 14.14 <= getDistancia(poligono1.puntos.at(2), poligono1.puntos.at(3)) and 14.143 >= getDistancia(poligono1.puntos.at(2), poligono1.puntos.at(3)) );
    assert ( 109.122 <= getDistancia(poligono2.puntos.at(0), poligono2.puntos.at(1)) and 109.124 >= getDistancia(poligono2.puntos.at(0), poligono2.puntos.at(1)) );

    //GET DISTANCIA AL ORIGEN

    assert ( 0 == getDistanciaAlOrigen(poligono1.puntos.at(2)) );
    assert ( 2.827 <= getDistanciaAlOrigen(poligono2.puntos.at(1)) and 2.829 >= getDistanciaAlOrigen(poligono2.puntos.at(1)) );
    assert ( 111.802 <= getDistanciaAlOrigen(triangulo1.puntos.at(0)) and 111.804 >= getDistanciaAlOrigen(triangulo1.puntos.at(0)) );

// PRUEBAS TRIANGULO

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

// PRUEBAS POLIGONO

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

    poligono1 = {4,{ { {2,2},{1,1},{0,0},{10,10} } }, RED};
    poligono2 = {5,{ { {100,50},{2,2},{1,1},{0,0},{10,10} } }, GREEN};
    poligono3 = {7,{ { {15.8,9},{5,2.5},{0,7},{3.2,3.3},{5,8},{12,3.1},{1,0.5} } }, YELLOW};

    removeVertice(poligono1);
    removeVertice(poligono2);
    removeVertice(poligono3);
    assert ( 3 == poligono1.lados );    //espero que le poligono tenga un lado mas por el setVertice de la linea 169
    assert ( 4 == poligono2.lados );    //espero que le poligono tenga un lado mas por el setVertice de la linea 170
    assert ( 6 == poligono3.lados );    //espero que le poligono tenga un lado mas por el setVertice de la linea 171

    //GET CANTIDAD DE LADOS

    poligono1 = {4,{ { {2,2},{1,1},{0,0},{10,10} } }, RED};
    poligono2 = {5,{ { {100,50},{2,2},{1,1},{0,0},{10,10} } }, GREEN};
    poligono3 = {7,{ { {15.8,9},{5,2.5},{0,7},{3.2,3.3},{5,8},{12,3.1},{1,0.5} } }, YELLOW};

    assert ( 4 == getCantidadLados(poligono1) );
    assert ( 5 == getCantidadLados(poligono2) );
    assert ( 7 == getCantidadLados(poligono3) );

    //GET PERIMETRO

    poligono1 = {4,{ { {2,2},{1,1},{0,0},{10,10} } }, RED};
    poligono2 = {5,{ { {100,50},{2,2},{1,1},{0,0},{10,10} } }, GREEN};
    poligono3 = {7,{ { {15.8,9},{5,2.5},{0,7},{3.2,3.3},{5,8},{12,3.1},{1,0.5} } }, YELLOW};

    assert ( 28.283 <= get_getPerimetro(poligono1) and 28.285 >= get_getPerimetro(poligono1) );
    assert ( 224.581 <= get_getPerimetro(poligono2) and 224.583 >= get_getPerimetro(poligono2) );
    assert ( 66.170 <= get_getPerimetro(poligono3) and 66.172 >= get_getPerimetro(poligono3) );
};


