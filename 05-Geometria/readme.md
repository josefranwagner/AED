# Análisis del problema

## Transcripción del problema

Se deben desarrollar los siguientes tipos de datos:

- Color
- Punto
- Triangulo
- Poligono

A su vez, debemos especificar conjunto de operaciones y conjunto de valores para cada uno de esos datos y realizar pruebas sobre dichas operaciones.

## Consideraciones

### Color

- Se utilizará el formato de color RGB representando la intensidad de cada color (rojo, verde y azul) con un valor entre 0 y 255. Para su representación en C++ se utilizará una variable del tipo uint8_t proporcionada por la librería iostream.

- Definiremos constantes para los colores primarios y los secundarios (Cyan, Magenta, Amarillo, Negro, Blanco) los cuales serán inicializados mediante una suma/resta de colores primarios.

### Punto

- Definimos el tipo punto para hacer uso de el en las estructuras de Triangulo y Poligono, representado por un par ordenado (x,y) en el plano real.

### Triangulo

- La estructura triangulo estará representada por 3 pares ordenados de puntos y un color.

- Utilizaremos el tipo de dato enumerado para poder calificar a los triangulos en sus diferentes tipos: Escaleno, Isosceles o Equilatero.

- Para el calculo de area de un triangulo haremos uso de la [Fórmula de Herón](https://es.wikipedia.org/wiki/F%C3%B3rmula_de_Her%C3%B3n). 

### Poligono

- La estructura poligono estará representada por un numero natural que indicará la cantidad de lados que posee el poligono, una cantidad finita de puntos (suponemos 20 como maximo) y un color.

