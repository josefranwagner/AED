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

struct poligono{
    unsigned lados;
    std::array <t_punto,20> puntos;  //Supongo como máximo que los polígonos a trabajar serán de 20 lados. 
    t_color color;
};

const uint8_t MAX_INTENSIDAD_COLOR = 255;
const uint8_t MIN_INTENSIDAD_COLOR = 0;

const t_color RED = {MAX_INTENSIDAD_COLOR, MIN_INTENSIDAD_COLOR, MIN_INTENSIDAD_COLOR};
const t_color GREEN = {MIN_INTENSIDAD_COLOR, MAX_INTENSIDAD_COLOR, MIN_INTENSIDAD_COLOR};
const t_color BLUE = {MIN_INTENSIDAD_COLOR, MIN_INTENSIDAD_COLOR, MAX_INTENSIDAD_COLOR};

// Prototipos de funciones

// COLOR

t_color sumarColores (const t_color& color1, const t_color& color2);
t_color restarColores (const t_color& color1, const t_color& color2);
t_color mezclarColores (const t_color& color1, const t_color& color2);
bool isIgualColor (const t_color& color1, const t_color& color2);
t_color getComplementario (const t_color& color);
std::string getHtmlHex (const t_color& color);
std::string getHtmlRgb (const t_color& color);

//PUNTO

bool isIgualPunto (t_punto punto1, t_punto punto2);
float getDistancia (t_punto punto1, t_punto punto2);
float getDistanciaAlOrigen (t_punto punto);

//TRIANGULO

float getPerimetro(const triangulo& t);
float getArea (const triangulo& t);
bool isEscaleno (const triangulo& t);
bool isEquilatero (const triangulo& t);
bool isIsosceles (const triangulo& t);
t_tipoTriangulo getTipo (const triangulo& t);

//POLIGONO

void addVertice (poligono& p, const t_punto& punto);
t_punto getVertice (const poligono& p, unsigned lado);
void setVertice (poligono& p, unsigned lado, t_punto punto);
void removeVertice (poligono& p);
unsigned getCantidadLados (const poligono& p);
float get_getPerimetro (const poligono& p);

// Definición de funciones

t_color sumarColores (const t_color& color1, const t_color& color2){
    t_color auxiliar;
    (color1.red + color2.red >= MAX_INTENSIDAD_COLOR)?   auxiliar.red=MAX_INTENSIDAD_COLOR
    :   auxiliar.red = color1.red + color2.red;
    (color1.green + color2.green >= MAX_INTENSIDAD_COLOR)?   auxiliar.green=MAX_INTENSIDAD_COLOR
    :   auxiliar.green = color1.green + color2.green;
    (color1.blue + color2.blue >= MAX_INTENSIDAD_COLOR)?   auxiliar.blue=MAX_INTENSIDAD_COLOR
    :   auxiliar.blue = color1.blue + color2.blue;    
    return auxiliar;
};

t_color restarColores (const t_color& color1, const t_color& color2){
    t_color auxiliar;
    (color1.red - color2.red <= MIN_INTENSIDAD_COLOR)?   auxiliar.red=MIN_INTENSIDAD_COLOR
    :   auxiliar.red = color1.red - color2.red;
    (color1.green - color2.green <= MIN_INTENSIDAD_COLOR)?   auxiliar.green=MIN_INTENSIDAD_COLOR
    :   auxiliar.green = color1.green - color2.green;
    (color1.blue - color2.blue <= MIN_INTENSIDAD_COLOR)?   auxiliar.blue=MIN_INTENSIDAD_COLOR
    :   auxiliar.blue = color1.blue - color2.blue;    
    return auxiliar;
};

t_color mezclarColores (const t_color& color1, const t_color& color2){
    return {(color1.red + color2.red)/2, (color1.green + color2.green)/2, (color1.blue + color2.blue)/2};
};

bool isIgualColor (const t_color& color1, const t_color& color2){
    return ((color1.red == color2.red) and (color1.green == color2.green) and (color1.blue == color2.blue));
};

t_color getComplementario (const t_color& color){
    return {(MAX_INTENSIDAD_COLOR - color.red), (MAX_INTENSIDAD_COLOR - color.green), (MAX_INTENSIDAD_COLOR - color.blue)};
};

std::string getHtmlHex (const t_color& color){
    int red, green, blue;
    red = color.red;
    green = color.green;
    blue = color.blue;
    std::stringstream s1, s2, s3;
    std::string R, G, B;
    s1 << std::hex << red;
    R = s1.str();
    if (R.length() == 1){
        R = "0" + R;
    }
    s2 << std::hex << green;
    G = s2.str ();
    if (G.length() == 1){
        G = "0" + G;
    }
    s3 << std::hex << blue;
    B = s3.str ();
    if (B.length() == 1){
        B = "0" + B;
    }
    return "#" + R + G + B;
};

std::string getHtmlRgb (const t_color& color){
    return "rgb(" + std::to_string(color.red) + "," + std::to_string(color.green) + "," + std::to_string(color.blue) + ")";
} 

bool isIgualPunto (t_punto punto1, t_punto punto2){
    return ((punto1.x == punto2.x) and (punto1.y == punto2.y));
}

float getDistancia (t_punto punto1, t_punto punto2){
    return (sqrt ( ( (punto2.x - punto1.x) * (punto2.x - punto1.x) ) + ( (punto2.y - punto1.y) * (punto2.y - punto1.y) ) ) );
};

float getDistanciaAlOrigen (t_punto punto){
    return (sqrt ( ( (punto.x) * (punto.x) ) + ( (punto.y) * (punto.y) ) ) );
};

float getPerimetro(const triangulo& t){
    return ( getDistancia(t.puntos.at(0),t.puntos.at(1)) + getDistancia(t.puntos.at(1),t.puntos.at(2)) + getDistancia(t.puntos.at(2),t.puntos.at(0)));
};

float getSemiperimetro (const triangulo& t){
    return ((getPerimetro (t)/2));
};

float getArea (const triangulo& t){
    return (sqrt (getSemiperimetro(t) * ((getSemiperimetro(t) - getDistancia(t.puntos.at(0),t.puntos.at(1))) * ((getSemiperimetro(t) - getDistancia(t.puntos.at(1),t.puntos.at(2)))) * (getSemiperimetro(t) - getDistancia(t.puntos.at(2),t.puntos.at(0))))));
};

bool isEscaleno (const triangulo& t){
    return ((getDistancia(t.puntos.at(0),t.puntos.at(1)) != getDistancia(t.puntos.at(1),t.puntos.at(2))) and (getDistancia(t.puntos.at(0),t.puntos.at(1)) != getDistancia(t.puntos.at(2),t.puntos.at(0))) and (getDistancia(t.puntos.at(1),t.puntos.at(2)) != getDistancia(t.puntos.at(2),t.puntos.at(0)) ));
};

bool isEquilatero (const triangulo& t){
    return ((getDistancia(t.puntos.at(0),t.puntos.at(1)) == getDistancia(t.puntos.at(1),t.puntos.at(2))) and (getDistancia(t.puntos.at(0),t.puntos.at(1)) == getDistancia(t.puntos.at(2),t.puntos.at(0))) and (getDistancia(t.puntos.at(1),t.puntos.at(2)) == getDistancia(t.puntos.at(2),t.puntos.at(0)) ));
};

bool isIsosceles (const triangulo& t){
    return ((getDistancia(t.puntos.at(0),t.puntos.at(1)) == getDistancia(t.puntos.at(1),t.puntos.at(2))) or (getDistancia(t.puntos.at(0),t.puntos.at(1)) == getDistancia(t.puntos.at(2),t.puntos.at(0))) or (getDistancia(t.puntos.at(1),t.puntos.at(2)) == getDistancia(t.puntos.at(2),t.puntos.at(0)) ));
};

t_tipoTriangulo getTipo (const triangulo& t){
    return isIsosceles (t) == true?     t_tipoTriangulo::Isosceles
    :   isEquilatero(t) == true?    t_tipoTriangulo::Equilatero
        :   t_tipoTriangulo::Escaleno;
};

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
}

unsigned getCantidadLados (const poligono& p){
    return p.lados;
};

float get_getPerimetro (const poligono& p){
    float perimetro = 0;
    for (int i = 1; i  < (p.lados); i++){
        perimetro = perimetro + getDistancia (p.puntos.at(i-1), p.puntos.at(i));
    }
    return perimetro + getDistancia(p.puntos.at(p.lados-1), p.puntos.at(0));
};

const t_color CYAN = sumarColores(GREEN, BLUE);
const t_color MAGENTA = sumarColores(RED, BLUE);
const t_color YELLOW = sumarColores(RED, GREEN);
const t_color BLACK = restarColores(RED, RED);
const t_color WHITE = sumarColores(RED, sumarColores(GREEN, BLUE));
