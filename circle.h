#ifndef __CIRCLE_H
#define __CIRCLE_H

#include <stdio.h>
#include <stdlib.h>
#include "listaVetor.h"

/*Tipo de dado absrato circulo*/
typedef void* Circulo;

/*Procedimento para desenho de circulo*/
void drawCircle(Dado svgBase, Circulo r);


/*Funcao para criação da instância circulo*/
Circulo createCircle(int i, char *stroke, char *fill, float r, float x, float y);

/*Funcao que retorna o raio do circulo*/
float getRaio(Circulo c);

/*Funcao que retorna o X do circulo*/
float getCircleX(Circulo c);

/*Funcao que retorna o Y do circulo*/
float getCircleY(Circulo c);

/*Funcao que retorna a cor de preenchimento do circulo*/
char *getCircleFill(Circulo c);

/*Funcao que retorna a cor de borda do circulo*/
char *getCircleStroke(Circulo c);

/*Procedimento para limpar os circulos da memoria*/
void freeCircle(Circulo c);










#endif