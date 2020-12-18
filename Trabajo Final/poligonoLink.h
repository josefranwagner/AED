#include <iostream>
#include <fstream>
#include <array>
#include <cmath>
#include "punto.h"
#include "color.h"

// TIPOS DE DATOS

const float PERIMETRO_MAXIMO = 50.0;

struct Nodo{
    t_punto punto;
    Nodo* nxtNodo;
};

struct poligono{
    Nodo* firstPunto = nullptr;
    t_color color;
};

//PROTOTIPOS DE FUNCIONES

void addVertice (poligono& p, const t_punto& puntoAux);
t_punto getVertice (const poligono& p, unsigned lado);
void setVertice (poligono& p, unsigned lado, t_punto puntoNuevo);
void removeVertice (poligono& p);
unsigned getCantidadLados (const poligono& p);
float get_getPerimetro (const poligono& p);
bool extraerSeparador (std::ifstream& entrada);
bool extraerPoligono (std::ifstream& entrada, poligono& p);
void enviarPoligono (const poligono& p, std::ofstream& salida);