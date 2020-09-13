#include <iostream>
#include <array>
#include <cmath>
#include <string>
#include <iomanip>

// Definición de tipos de datos

struct t_punto {
    float x,y;
};

// Prototipos de funciones

bool isIgualPunto (t_punto punto1, t_punto punto2);
float getDistancia (t_punto punto1, t_punto punto2);
float getDistanciaAlOrigen (t_punto punto);