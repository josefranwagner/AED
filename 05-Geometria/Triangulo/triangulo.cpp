#include "triangulo.h"

float getDistancia (t_punto punto1, t_punto punto2){
    return sqrt ( ( (punto2.x - punto1.x) * (punto2.x - punto1.x) ) + ( (punto2.y - punto1.y) * (punto2.y - punto1.y) ) );
};

float getPerimetro(const triangulo& t){
    return getDistancia(t.puntos.at(0),t.puntos.at(1)) + getDistancia(t.puntos.at(1),t.puntos.at(2)) + getDistancia(t.puntos.at(2),t.puntos.at(0));
};

float getSemiperimetro (const triangulo& t){
    return getPerimetro (t)/2;
};

float getArea (const triangulo& t){
    return sqrt (getSemiperimetro(t) * ((getSemiperimetro(t) - getDistancia(t.puntos.at(0),t.puntos.at(1))) * ((getSemiperimetro(t) - getDistancia(t.puntos.at(1),t.puntos.at(2)))) * (getSemiperimetro(t) - getDistancia(t.puntos.at(2),t.puntos.at(0)))));
};

bool isEscaleno (const triangulo& t){
    return (getDistancia(t.puntos.at(0),t.puntos.at(1)) != getDistancia(t.puntos.at(1),t.puntos.at(2))) and (getDistancia(t.puntos.at(0),t.puntos.at(1)) != getDistancia(t.puntos.at(2),t.puntos.at(0))) and (getDistancia(t.puntos.at(1),t.puntos.at(2)) != getDistancia(t.puntos.at(2),t.puntos.at(0)) );
};

bool isEquilatero (const triangulo& t){
    return (getDistancia(t.puntos.at(0),t.puntos.at(1)) == getDistancia(t.puntos.at(1),t.puntos.at(2))) and (getDistancia(t.puntos.at(0),t.puntos.at(1)) == getDistancia(t.puntos.at(2),t.puntos.at(0))) and (getDistancia(t.puntos.at(1),t.puntos.at(2)) == getDistancia(t.puntos.at(2),t.puntos.at(0)) );
};

bool isIsosceles (const triangulo& t){
    return (getDistancia(t.puntos.at(0),t.puntos.at(1)) == getDistancia(t.puntos.at(1),t.puntos.at(2))) or (getDistancia(t.puntos.at(0),t.puntos.at(1)) == getDistancia(t.puntos.at(2),t.puntos.at(0))) or (getDistancia(t.puntos.at(1),t.puntos.at(2)) == getDistancia(t.puntos.at(2),t.puntos.at(0))) ;
};

t_tipoTriangulo getTipo (const triangulo& t){
    return isIsosceles (t) == true?     t_tipoTriangulo::Isosceles
    :   isEquilatero(t) == true?    t_tipoTriangulo::Equilatero
        :   t_tipoTriangulo::Escaleno;
};
