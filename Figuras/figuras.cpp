#include <iostream>
#include <cassert>

// Definición de tipos de datos

enum struct t_color {Rojo, Verde, Amarillo, Azul, Naranja};

struct t_punto {
    int x,y;
};

struct triangulo{
    t_punto puntos[3];
    t_color color;
};

struct poligono{
    unsigned lados;
    t_punto puntos [20];  //Supongo como máximo que los polígonos a trabajar serán de 20 lados. 
    t_color color;
};

// Prototipos de funciones

//  NOTA: Podría considerarse un triangulo como caso particular de polígono validando el num de puntos con la variable "lados".
//  En este caso, y como indica la consigna, plantearemos  dos estructuras diferentes y las trabajaremos por separado.

t_punto getPunto (const poligono& p, unsigned pos_punto);
t_punto getPunto (const triangulo& t, unsigned pos_punto);
t_color getColorPoligono (const poligono& p);
t_color getColorTriangulo (const triangulo& t);
unsigned getCantidadLadosPoligono (const poligono& p);

void setColorTriangulo (triangulo& t, t_color colorElegido);
void setColorPoligono (poligono& p, t_color colorElegido);

void modificarPuntoTriangulo (triangulo& t, unsigned pos_punto ,const t_punto& puntoNuevo);
void modificarPuntoPoligono (poligono& p, unsigned pos_punto ,const t_punto& puntoNuevo);
void AgregarPuntoPoligono (poligono& p, t_punto punto);

// Bloque principal

int main (){
    poligono poligono1 = {4,{{2,2},{1,1},{0,0},{10,10}}, t_color::Rojo};        //cuadrado de color rojo
    poligono poligono2 = {5,{ {100,50},{2,2},{1,1},{0,0},{10,10} }, t_color::Verde};        //pentagono de color verde
    triangulo t = { { {100,50},{2,2},{1,1} }, t_color::Azul};      //triangulo de color azul
    assert (getPunto(poligono1,2).x == 1);
    assert (getPunto(poligono1,2).y == 1);
    assert (getColorPoligono(poligono2) == t_color::Verde);
    assert (getColorTriangulo(t) == t_color::Azul);
    assert (getCantidadLadosPoligono(poligono2) == 5);
    setColorTriangulo(t,t_color::Naranja);
    assert (t.color == t_color::Naranja);
    setColorPoligono(poligono1, t_color::Amarillo);
    assert (poligono1.color == t_color::Amarillo);
    modificarPuntoTriangulo (t,2,{0,1});
    assert (t.puntos[1].x == 0);    // como el array contempla el 0 tengo que restarle uno para acceder a la posicion real del arreglo
    assert (t.puntos[1].y == 1);    // desde el punto de vista del usuario el punto que selecciona es el punto numero 2
    modificarPuntoPoligono (poligono2, 4 ,{-1,-5});
    assert (poligono2.puntos[3].x == -1);
    assert (poligono2.puntos[3].y == -5);
    AgregarPuntoPoligono (poligono1,{15,25});
    assert (poligono1.puntos[poligono1.lados-1].x == 15);
    assert (poligono1.puntos[poligono1.lados-1].y == 25);
};

// Definición de funciones

t_punto getPunto (const poligono& p, unsigned pos_punto){
    return p.puntos[pos_punto-1];
}

t_punto getPunto (const triangulo& t, unsigned pos_punto){
    return t.puntos[pos_punto-1];
}

t_color getColorPoligono (const poligono& p){
    return p.color;
}

t_color getColorTriangulo (const triangulo& t){
    return t.color;
}

unsigned getCantidadLadosPoligono (const poligono& p){
    return p.lados;
}

void setColorTriangulo (triangulo& t, t_color colorElegido){
    t.color=colorElegido;
}

void setColorPoligono (poligono& p, t_color colorElegido){
    p.color=colorElegido;
}

void modificarPuntoTriangulo (triangulo& t, unsigned pos_punto ,const t_punto& puntoNuevo){
    t.puntos[pos_punto-1]=puntoNuevo;
}

void modificarPuntoPoligono (poligono& p, unsigned pos_punto ,const t_punto& puntoNuevo){
    p.puntos[pos_punto-1]=puntoNuevo;
}

void AgregarPuntoPoligono (poligono& p, t_punto punto){
    p.lados++;
    p.puntos[p.lados-1]=punto;
}