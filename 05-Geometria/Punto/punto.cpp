#include "punto.h"

bool isIgualPunto (t_punto punto1, t_punto punto2){
    return punto1.x == punto2.x and punto1.y == punto2.y;
}

float getDistancia (t_punto punto1, t_punto punto2){
    return sqrt ( ( (punto2.x - punto1.x) * (punto2.x - punto1.x) ) + ( (punto2.y - punto1.y) * (punto2.y - punto1.y) ) );
};

float getDistanciaAlOrigen (t_punto punto){
    return sqrt ( ( (punto.x) * (punto.x) ) + ( (punto.y) * (punto.y) ) );
};
