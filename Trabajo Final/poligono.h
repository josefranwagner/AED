#include <iostream>
#include <fstream>
#include <array>
#include <cmath>
#include "punto.h"
#include "color.h"

// TIPOS DE DATOS

const float PERIMETRO_MAXIMO = 50.0;

struct poligono{
    unsigned lados;
    std::array <t_punto,20> puntos;  //Supongo como máximo que los polígonos a trabajar serán de 20 lados. 
    t_color color;
};

//PROTOTIPOS DE FUNCIONES

void addVertice (poligono& p, const t_punto& punto);
t_punto getVertice (const poligono& p, unsigned lado);
void setVertice (poligono& p, unsigned lado, t_punto punto);
void removeVertice (poligono& p);
unsigned getCantidadLados (const poligono& p);
float get_getPerimetro (const poligono& p);
bool extraerSeparador (std::ifstream& entrada);
bool extraerPoligono (std::ifstream& entrada, poligono& p);
void enviarPoligono (const poligono& p, std::ofstream& salida);