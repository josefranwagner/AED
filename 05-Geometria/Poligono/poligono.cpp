#include "poligono.h"

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

float getDistancia (t_punto punto1, t_punto punto2){
    return sqrt ( ( (punto2.x - punto1.x) * (punto2.x - punto1.x) ) + ( (punto2.y - punto1.y) * (punto2.y - punto1.y) ) );
};

float get_getPerimetro (const poligono& p){
    float perimetro = 0;
    for (int i = 1; i  < (p.lados); i++){
        perimetro = perimetro + getDistancia (p.puntos.at(i-1), p.puntos.at(i));
    }
    return perimetro + getDistancia(p.puntos.at(p.lados-1), p.puntos.at(0));
};
