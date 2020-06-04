/*
Programa: Función Celsius
Objetivo: Desarrollar una función que, dada una magnitud Farehnheit, calcule su equivalente en Celsius
Autor: Jose Francisco Wagner
Ultima modificación: 20200604
*/

#include <cassert>
#include <iostream>

// Prototipos de funciones

double Celsius (double);
bool AreNear (double, double, double = 0.001);

// BLOQUE PRINCIPAL

int main (){
    assert (AreNear(0,Celsius(32.00),0.001));           // 32° F = 0° C | 0-0 <= 0.001
    assert (AreNear(32.00,Celsius(89.6),0.001));        // 89.6° F = 32° C | 32.00 - 32.00 <= 0.001
    assert (AreNear(-32.00,Celsius(-25.6),0.001));      // -25.6° F = -32° C | -32.00 - (-32.00) <= 0.001
    assert (AreNear(-32.001,Celsius(-25.6),0.001));     // -25.6° F = -32° C | -32.001 - (-32.00) <= 0.001
    assert (AreNear(-32.0001,Celsius(-25.6),0.001));    // -25.6° F = -32° C | -32.00 - (-32.0001) = 0.0001
    assert (AreNear(-32.002,Celsius(-25.6),0.001));     // -25.6° F = -32° C | -32.00 - (-32.002) = 0.002
}

// Definición de la función

double Celsius (double x){return
    (5.00/9.00)*(x-32);
}

bool AreNear (double a, double b, double tolerancia){return
    a >= b? (a-b) <= tolerancia
    : (b-a) <= tolerancia;
}
