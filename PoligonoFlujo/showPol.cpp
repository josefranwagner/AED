#include "showPol.h"

//DESARROLLO DE FUNCIONES

void extraerColor (std::ifstream& entrada, t_color& color){
    char separador;
	entrada >> separador;
    entrada >> color.red;
    entrada >> separador;
    entrada >> color.green;
    entrada >> separador;
    entrada >> color.blue;
    entrada >> separador;
}

bool extraerPunto (std::ifstream& entrada, t_punto& punto){
	char coma;
	entrada >> punto.x;
    entrada >> coma;
    entrada >> punto.y;
	return bool{entrada};
}

void addVertice (poligono& p, const t_punto& punto){
    p.puntos.at(p.lados) = punto;
    p.lados++;
}

void enviarPoligono (const poligono& p, std::ofstream& salida){
    salida << "Color: " << "(" << p.color.red << "," << p.color.green << "," << p.color.blue << ")" <<"\n";
    for (int i=0; i < p.lados; i++){
        salida << "Punto " << i+1 << " : (" << p.puntos.at(i).x << "," << p.puntos.at(i).y << ")" << "\n";
    }
    salida << "Lados: " << p.lados << "\n\n";
}

bool extraerPoligono (std::ifstream& entrada, poligono& p, std::ofstream& salida){
    extraerColor (entrada, p.color);
    t_punto puntoAuxiliar;
    p.lados=0;
    while ( extraerPunto (entrada,puntoAuxiliar) ){
        addVertice (p, puntoAuxiliar);
    }
    return bool{entrada};
}