#include <iostream>
#include <fstream>
#include <array>

// TIPOS DE DATOS

struct t_color{
    int red, green, blue;
};

struct t_punto {
    float x,y;
};

struct poligono{
    unsigned lados;
    std::array <t_punto,20> puntos;  //Supongo como máximo que los polígonos a trabajar serán de 20 lados. 
    t_color color;
};

//PROTOTIPOS DE FUNCIONES

void extraerColor (std::ifstream& entrada, t_color& color);
bool extraerPunto (std::ifstream& entrada, t_punto& punto);
void addVertice (poligono& p, const t_punto& punto);
bool extraerPoligono (std::ifstream& entrada, poligono& p, std::ofstream& salida);
void enviarPoligono (const poligono& p, std::ofstream& salida);