PoligonoCont: poligono.o testFlujo.o color.o punto.o
	g++ poligono.o color.o punto.o testFlujo.o -o PoligonoCont

PoligonoLink: poligonoLink.o testFlujo.o color.o punto.o
	g++ poligonoLink.o color.o punto.o testFlujo.o -o PoligonoLink

PoligonoLinkTest: poligonoLink.o poligonoLinkTest.o color.o punto.o
	g++ poligonoLink.o color.o punto.o poligonoLinkTest.o -o PoligonoLinkTest

poligonoLinkTest.o: poligonoLinkTest.cpp
	g++ -c poligonoLinkTest.cpp

poligonoLink.o: poligonoLink.cpp
	g++ -c poligonoLink.cpp

Poligono: poligono.o poligonoTest.o color.o punto.o
	g++ poligono.o color.o punto.o poligonoTest.o -o Poligono

Color: color.o colorTest.o
	g++ color.o colorTest.o -o Color

Punto: punto.o puntoTest.o
	g++ punto.o puntoTest.o -o Punto
	
testFlujo.o: testFlujo.cpp
	g++ -c testFlujo.cpp

poligono.o: poligono.cpp
	g++ -c poligono.cpp

poligonoTest.o: poligonoTest.cpp
	g++ -c poligonoTest.cpp

color.o: color.cpp
	g++ -c color.cpp

colorTest.o: colorTest.cpp
	g++ -c colorTest.cpp

punto.o: punto.cpp
	g++ -c punto.cpp

puntoTest.o: puntoTest.cpp
	g++ -c puntoTest.cpp
