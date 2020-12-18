# Trabajo Final

### Transcripción del problema

Crear un programa que permita extraer poligonos de un flujo de entrada y enviarlos a un flujo de salida cumpliendo la condición de que el perímetro de ese poligono sea superior a un valor X. 

### Refinamiento del problema e Hipótesis de trabajo

Se deben considerar dos tipos distintos para la implementación del tipo de dato poligono, una será una versión continua donde los puntos del poligono esten almacenados en un arreglo y la otra versión a desarrollar debe ser enlazada, por medio de punteros y nodos que contengan los puntos del poligono.

#### Tipo de dato color

- Estructura compuesta por tres variables enteras con las que representaremos la intensidad de cada componente del color siguiendo el formato RGB (red, green, blue)

- Se desarrollará un archivo color.h que contenga los prototipos de las funciones a utilizar y la definición del tipo de dato. A su vez se debe crear un archivo color.cpp que desarrolle las funciones enunciadas en el header y por último se probarán dichas funciones mediante el archivo colorTest.cpp

#### Tipo de dato punto

- Estructura compuesta por dos variables reales con las que representaremos las coordenadas x e y de los puntos que formen parte de cada poligono.

- Se desarrollará un archivo punto.h que contenga los prototipos de las funciones a utilizar y la definición del tipo de dato. A su vez se debe crear un archivo punto.cpp que desarrolle las funciones enunciadas en el header y por último se probarán dichas funciones mediante el archivo puntoTest.cpp

#### Tipo de dato poligono

##### Variante continua

- Estructura compuesta por un numero entero que representa la cantidad de lados que posee el poligono, un arreglo de 20 unidades como máximo (hipótesis de trabajo) y un color.

- Se desarrollará un archivo poligono.h que contenga los prototipos de las funciones a utilizar y la definición del tipo de dato. A su vez se debe crear un archivo poligono.cpp que desarrolle las funciones enunciadas en el header y por último se probarán dichas funciones mediante el archivo poligonoTest.cpp

##### Variante enlazada

- Estructura compuesta por un puntero a un nodo que representa el primer punto del poligono y un color. Asimismo cada nodo es una estructura compuesta por un punto y un puntero al proximo nodo. Haremos uso del puntero nulo para marcar el fin de los puntos de un poligono.

- Se desarrollará un archivo poligonoLink.h que contenga los prototipos de las funciones a utilizar y la definición del tipo de dato. A su vez se debe crear un archivo poligonoLink.cpp que desarrolle las funciones enunciadas en el header y por último se probarán dichas funciones mediante el archivo poligonoLinkTest.cpp

_Ambas variantes del tipo de dato poligono serán testeadas bajo el archivo_ **testFlujo.cpp** _que contiene las directivas para resolver el problema_


_Consideraremos que los poligonos a enviar al flujo de salida deberán cumplir el requisito de que su perímetro es mayor a 50.0 y su cantidad de lados debe ser mayor a 2 para que sea considerado poligono_


## Descripción de archivos

**color.cpp**: desarrollo de funciones para tipo de dato color

**color.h**: definición de tipo de dato color y prototipo de funciones

**colorTest.cpp**: prueba de funciones para tipo de dato color

**punto.cpp**: desarrollo de funciones para tipo de dato punto

**punto.h**: definición de tipo de dato punto y prototipo de funciones

**puntoTest.cpp**: prueba de funciones para tipo de dato punto

**poligono.cpp**: desarrollo de funciones para tipo de dato poligono en su versión continua

**poligono.h**: definición de tipo de dato poligono en su version continua y prototipo de funciones

**poligonoTest.cpp**: prueba de funciones para tipo de dato poligono en su version continua

**poligonoLink.cpp**: desarrollo de funciones para tipo de dato poligono en su versión enlazada

**poligonoLink.h**: definición de tipo de dato poligono en su version enlazada y prototipo de funciones

**poligonoLinkTest.cpp**: prueba de funciones para tipo de dato poligono en su version enlazada

**testFlujo**: prueba de extracción de poligonos mediante flujos de E/S 
