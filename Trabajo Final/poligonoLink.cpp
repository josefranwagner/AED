#include "poligonoLink.h"

//DESARROLLO DE FUNCIONES


void addVertice (poligono& p, const t_punto& puntoAux){
    auto n = new Nodo; 
    n-> punto.x = puntoAux.x;
    n-> punto.y = puntoAux.y;
    n-> nxtNodo = p.firstPunto;
    p.firstPunto = n;
}

t_punto getVertice (const poligono& p, unsigned lado){
    auto aux = p.firstPunto;
    if ( lado <= getCantidadLados(p) ){
        for( unsigned i=0; i < getCantidadLados(p)-lado ; i++ ) 
            aux = aux->nxtNodo;
        return aux-> punto;
    }
    else
        return {-10000,-10000};   //En el caso de que el punto no exista
}

void setVertice (poligono& p, unsigned lado, t_punto puntoNuevo){
    auto aux = p.firstPunto;
    for( unsigned i=0; i < getCantidadLados(p)-lado; i++) 
        aux = aux-> nxtNodo;
    aux-> punto.x = puntoNuevo.x;
    aux-> punto.y = puntoNuevo.y;
}

void removeVertice (poligono& p){   //remueve el ultimo punto
    if (p.firstPunto != nullptr){
        auto aux = p.firstPunto;    //por mi implementación, el ultimo punto es el primer punto del nodo.
        p.firstPunto=aux->nxtNodo;
    }
}

unsigned getCantidadLados (const poligono& p){
    unsigned lados = 0;
    auto aux = p.firstPunto;
    while (aux != nullptr) {
        lados ++;
        aux = aux-> nxtNodo;
    }
    return lados;
}

float get_getPerimetro (const poligono& p){
    float resultado = 0;
    t_punto puntoAuxiliar;
    Nodo* aux;
    puntoAuxiliar.x = p.firstPunto-> punto.x;
    puntoAuxiliar.y = p.firstPunto-> punto.y;
    aux = p.firstPunto;
    while ( aux-> nxtNodo != nullptr ){
        resultado = resultado + getDistancia (puntoAuxiliar, aux-> punto);
        puntoAuxiliar.x = aux-> punto.x;
        puntoAuxiliar.y = aux-> punto.y;
        aux = aux-> nxtNodo;
    }
    resultado = resultado + getDistancia (puntoAuxiliar, aux-> punto) + getDistancia (aux-> punto, p.firstPunto-> punto);
    return resultado;
}

bool extraerSeparador (std::ifstream& entrada){
    entrada.clear();
    char separador = '%';   //Inicializo con cualquier dato para asegurarme que no contenga # en caso de que no pueda leer.
    entrada >> separador;
    return ( separador == '#');
}

bool extraerPoligono (std::ifstream& entrada, poligono& p){
    p.firstPunto = nullptr;
    if (not extraerColor (entrada, p.color)) return false;
    t_punto puntoAuxiliar;
	while (extraerPunto(entrada, puntoAuxiliar)){
		addVertice(p, puntoAuxiliar);
    }
    t_punto aux;
    return ( extraerSeparador(entrada) );
}

void enviarPoligono (const poligono& p, std::ofstream& salida){ 
    salida << "Color RGB: " << "(" << p.color.red << "," << p.color.green << "," << p.color.blue << ")" <<"\n";
    salida << "Lados: " << getCantidadLados(p) << "\n";
    salida << "PUNTOS" << "\n";
    unsigned i = getCantidadLados(p);
    for ( auto aux {p.firstPunto}; aux != nullptr ; aux = aux->nxtNodo){
        salida << "Punto " << i << ":";
        enviarPunto (aux->punto,salida);
        salida << "\n";
        i--;
    }
    salida << "\n" << "Perimetro: " << get_getPerimetro(p) << "\n\n";
}