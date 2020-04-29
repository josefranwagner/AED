/*
Programa: Adicion
Objetivo: Devuelve la suma de dos numeros ingresados por el usuario
Autor: Jose Francisco Wagner
Ultima modificación: 20200426
*/

#include <iostream>

int main (){
	std::cout << "Ingrese un primer valor a sumar: ";
	int PrimerNum;
	std::cin >> PrimerNum;
	std::cout << "Ingrese un segundo valor a sumar: ";
	int SegundoNum;
	std::cin >> SegundoNum;
	std::cout << "RESULTADO: ";
	std::cout << PrimerNum+SegundoNum;
}
