#include "color.h"
#include <cassert>

const t_color RED = {MAX_INTENSIDAD_COLOR, MIN_INTENSIDAD_COLOR, MIN_INTENSIDAD_COLOR};
const t_color GREEN = {MIN_INTENSIDAD_COLOR, MAX_INTENSIDAD_COLOR, MIN_INTENSIDAD_COLOR};
const t_color BLUE = {MIN_INTENSIDAD_COLOR, MIN_INTENSIDAD_COLOR, MAX_INTENSIDAD_COLOR};

const t_color CYAN = sumarColores(GREEN, BLUE);
const t_color MAGENTA = sumarColores(RED, BLUE);
const t_color YELLOW = sumarColores(RED, GREEN);
const t_color BLACK = restarColores(RED, RED);
const t_color WHITE = sumarColores(RED, sumarColores(GREEN, BLUE));

// Bloque principal

int main (){

//SUMAR COLORES

    assert ( isIgualColor(sumarColores({125,0,0}, {130,0,0}), {255,0,0}) );
    assert ( isIgualColor(sumarColores(GREEN, GREEN), {0,255,0}) );
    assert ( isIgualColor(sumarColores(YELLOW, CYAN), {255,255,255}) );

//RESTAR COLORES

    assert ( isIgualColor(restarColores(BLACK, WHITE),{0,0,0}) );
    assert ( isIgualColor(restarColores({123,45,87}, {182,35,65}),{0,10,22}) );
    assert ( isIgualColor(restarColores({245,227,32}, GREEN),{245,0,32}) );

//MEZCLAR COLORES

    assert ( isIgualColor(mezclarColores(MAGENTA, YELLOW),{255,127,127}) );
    assert ( isIgualColor(mezclarColores({145,50,37}, YELLOW),{200,152,18}) );
    assert ( isIgualColor(mezclarColores({21,32,198}, {78,12,25}),{49,22,111}) );

//COMPLEMENTARIO

    assert ( isIgualColor(getComplementario(RED),CYAN) );
    assert ( isIgualColor(getComplementario(BLACK),WHITE) );
    assert ( isIgualColor(getComplementario({145,50,37}),{110,205,218}) );

//GET HTML

    assert ( getHtmlHex(RED) == "#ff0000" );
    assert ( getHtmlHex({135,206,250}) == "#87cefa" );
    assert ( getHtmlHex({255,228,225}) == "#ffe4e1" );

//GET RGB

    assert ( getHtmlRgb(RED) == "rgb(255,0,0)" );
    assert ( getHtmlRgb({253,245,230}) == "rgb(253,245,230)" );
    assert ( getHtmlRgb(WHITE) == "rgb(255,255,255)" );
};