#include <iostream>
#include <array>
#include <cmath>
#include <string>
#include <iomanip>

// Definición de tipos de datos

struct t_color{
    uint8_t red, green, blue;
};

struct t_punto {
    float x,y;
};

struct poligono{
    unsigned lados;
    std::array <t_punto,20> puntos;  //Supongo como máximo que los polígonos a trabajar serán de 20 lados. 
    t_color color;
};

// Prototipos de funciones

void addVertice (poligono& p, const t_punto& punto);
t_punto getVertice (const poligono& p, unsigned lado);
void setVertice (poligono& p, unsigned lado, t_punto punto);
void removeVertice (poligono& p);
float getDistanciaAlOrigen (t_punto punto);
unsigned getCantidadLados (const poligono& p);
float get_getPerimetro (const poligono& p);
