#include "color.h"

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
    return (color1.red == color2.red) and (color1.green == color2.green) and (color1.blue == color2.blue);
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
