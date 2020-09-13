#include <iostream>
#include <array>
#include <cmath>
#include <string>
#include <iomanip>

// Definición de tipos de datos

struct t_color{
    uint8_t red, green, blue;
};

const uint8_t MAX_INTENSIDAD_COLOR = 255;
const uint8_t MIN_INTENSIDAD_COLOR = 0;

const t_color RED = {MAX_INTENSIDAD_COLOR, MIN_INTENSIDAD_COLOR, MIN_INTENSIDAD_COLOR};
const t_color GREEN = {MIN_INTENSIDAD_COLOR, MAX_INTENSIDAD_COLOR, MIN_INTENSIDAD_COLOR};
const t_color BLUE = {MIN_INTENSIDAD_COLOR, MIN_INTENSIDAD_COLOR, MAX_INTENSIDAD_COLOR};

// Prototipos de funciones

t_color sumarColores (const t_color& color1, const t_color& color2);
t_color restarColores (const t_color& color1, const t_color& color2);
t_color mezclarColores (const t_color& color1, const t_color& color2);
bool isIgualColor (const t_color& color1, const t_color& color2);
t_color getComplementario (const t_color& color);
std::string getHtmlHex (const t_color& color);
std::string getHtmlRgb (const t_color& color);

const t_color CYAN = sumarColores(GREEN, BLUE);
const t_color MAGENTA = sumarColores(RED, BLUE);
const t_color YELLOW = sumarColores(RED, GREEN);
const t_color BLACK = restarColores(RED, RED);
const t_color WHITE = sumarColores(RED, sumarColores(GREEN, BLUE));