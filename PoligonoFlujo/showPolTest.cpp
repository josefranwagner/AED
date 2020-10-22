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