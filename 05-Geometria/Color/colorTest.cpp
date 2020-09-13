#include "color.h"
#include <cassert>

// Bloque principal

int main (){

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
};