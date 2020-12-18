#include <iostream>
#include <fstream>
#include <array>
#include <cmath>
#include <string>
#include <iomanip>

// Definición de tipos de datos

struct t_color{
    int red, green, blue;
};

const uint8_t MAX_INTENSIDAD_COLOR = 255;
const uint8_t MIN_INTENSIDAD_COLOR = 0;

// Prototipos de funciones

t_color sumarColores (const t_color& color1, const t_color& color2);
t_color restarColores (const t_color& color1, const t_color& color2);
t_color mezclarColores (const t_color& color1, const t_color& color2);
bool isIgualColor (const t_color& color1, const t_color& color2);
t_color getComplementario (const t_color& color);
std::string getHtmlHex (const t_color& color);
std::string getHtmlRgb (const t_color& color);
bool extraerParentesisApertura (std::ifstream& entrada);
bool extraerParentesisCierre (std::ifstream& entrada);
bool extraerColor (std::ifstream& entrada, t_color& color);
