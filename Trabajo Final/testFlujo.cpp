/*
Programa: Leer poligonos y enviarlos a un flujo de salida si cumplen con un requisito.
Objetivo: Obtener poligonos mediante un flujo de entrada, procesarlos y enviar a un flujo de salida los que cumplan con la condicion
de que su perimetro es mayor a 50.
Autor: Jose Francisco Wagner
Ultima modificación: 20201218.
*/

#include "poligono.h"

//BLOQUE PRINCIPAL

int main(){
    poligono p;
    std::ifstream entrada("datosPoligonos.txt");
    std::ofstream salida ("poligonos.txt");
    while ( extraerPoligono (entrada, p) ){
        if ( get_getPerimetro(p) > PERIMETRO_MAXIMO and getCantidadLados(p)>2)
            enviarPoligono (p,salida);
        entrada.clear();    //limpieza del flujo
    }
}