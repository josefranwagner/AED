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

struct triangulo{
    std::array <t_punto,3> puntos;
    t_color color;
};

enum struct t_tipoTriangulo {Escaleno, Isosceles, Equilatero};

// Prototipos de funciones

float getPerimetro(const triangulo& t);
float getArea (const triangulo& t);
bool isEscaleno (const triangulo& t);
bool isEquilatero (const triangulo& t);
bool isIsosceles (const triangulo& t);
t_tipoTriangulo getTipo (const triangulo& t);