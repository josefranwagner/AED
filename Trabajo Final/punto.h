#include <iostream>
#include <fstream>
#include <array>
#include <cmath>
#include <string>
#include <iomanip>
//#include "color.h"

// Definición de tipos de datos

struct t_punto {
    float x,y;
};

// Prototipos de funciones

bool isIgualPunto (t_punto punto1, t_punto punto2);
float getDistancia (t_punto punto1, t_punto punto2);
float getDistanciaAlOrigen (t_punto punto);
bool extraerComa (std::ifstream& entrada);
bool extraerPunto (std::ifstream& entrada, t_punto& punto);
void enviarPunto (t_punto punto , std::ofstream& salida);