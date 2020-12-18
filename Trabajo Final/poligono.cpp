#include "poligono.h"

//DESARROLLO DE FUNCIONES

void addVertice (poligono& p, const t_punto& punto){
    p.puntos.at(p.lados) = punto;
    p.lados++;
};

t_punto getVertice (const poligono& p, unsigned lado){
    return p.puntos.at(lado-1);
};

void setVertice (poligono& p, unsigned lado, t_punto punto){
    p.puntos.at(lado-1) = punto;
};

void removeVertice (poligono& p){
    p.lados = p.lados-1;
};

unsigned getCantidadLados (const poligono& p){
    return p.lados;
};

float get_getPerimetro (const poligono& p){
    float perimetro = 0;
    for (int i = 1; i  < (p.lados); i++){
        perimetro = perimetro + getDistancia (p.puntos.at(i-1), p.puntos.at(i));
    }
    return perimetro + getDistancia(p.puntos.at(p.lados-1), p.puntos.at(0));
};

bool extraerSeparador (std::ifstream& entrada){
    entrada.clear();    //limpieza del flujo
    char separador = '%';   //Inicializo con cualquier dato para asegurarme que no contenga # en caso de que no pueda leer.
    entrada >> separador;
    return ( separador == '#');
}

bool extraerPoligono (std::ifstream& entrada, poligono& p){
    if (not extraerColor (entrada, p.color)) return false;
    t_punto puntoAuxiliar;
    p.lados=0;
	while (extraerPunto(entrada, puntoAuxiliar))
		addVertice(p, puntoAuxiliar);
    return ( extraerSeparador(entrada) );
}

void enviarPoligono (const poligono& p, std::ofstream& salida){
    salida << "Color RGB: " << "(" << p.color.red << "," << p.color.green << "," << p.color.blue << ")" <<"\n";
    salida << "Lados: " << p.lados << "\n";
    salida << "Puntos:";
    for ( int i=1; i <= getCantidadLados (p); i++ ){
        enviarPunto (getVertice(p,i) , salida);
    }
    salida << "\n" << "Perimetro: " << get_getPerimetro(p) << "\n\n";
}