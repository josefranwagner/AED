/*
Programa: Leer poligonos y mostrarlos
Objetivo: Obtener poligonos mediante un flujo de entrada, procesarlos y enviarlos a un flujo de salida.
Autor: Jose Francisco Wagner
Ultima modificación: 20201022.
*/

#include "showPol.h"

//BLOQUE PRINCIPAL

int main(){
    poligono p;
    std::ifstream entrada("datosPoligonos.txt");
    std::ofstream salida ("poligonos.txt");
    char separador;
    entrada >> separador;
    while (separador=='#' and not entrada.eof()){
        extraerPoligono (entrada,p,salida);
        enviarPoligono (p,salida);
        entrada.clear();    //limpieza del flujo
        entrada >> separador;
    }
}