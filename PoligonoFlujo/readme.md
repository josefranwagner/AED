# Análisis del problema

## Transcripción del problema

Se debe desarrollar un programa que permita leer poligonos ordenados de cierta forma desde un flujo de datos de entrada y pueda enviarlos hacia un flujo de salida.

## Hipótesis de trabajo

- Para realizar este programa utilizaremos archivos de texto y variables del tipo ifstream para flujo de entrada y ofstream para flujo de salida (incluidas en la librería fstream)

- El archivo que contiene la información de los poligonos sigue el siguiente criterio:

"#(R,G,B) P1 P2 ... PN#(R,G,B) P1 P2 ... PN...., donde R,G y B son las intensidades de cada color del formato RGB, P1,...,PN son los diferentes puntos que componen al poligono.


