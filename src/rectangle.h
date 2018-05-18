#ifndef __RECTANGLE_H
#define __RECTANGLE_H

#include <stdlib.h>
#include <stdio.h>
#include "listaVetor.h"

/*Tipo de dado abstrato*/
typedef void* Retangulo;

/*Procedimento para desenhar um retangulo*/
void drawRectangle(Dado svgBase, Retangulo r);

/*Função que cria uma instância retangulo*/
Retangulo createRectangle(int i, char *stroke, char *fill, float w, float h, float x, float y);

/*Função que retorna X do retangulo*/
float getRectangleX(Retangulo r);

/*Função que retorna Y do retangulo*/
float getRectangleY(Retangulo r);

/*Função que retorna a LARGURA do retangulo*/
float getRectangleW(Retangulo r);

/*Função que retorna a ALTURA do retangulo*/
float getRectangleH(Retangulo r);

/*Função que retorna a cor da borda do retangulo*/
char *getRectangleStroke(Retangulo r);

/*Função que retorna a cor do preenchimento do retangulo*/
char *getRectangleFill(Retangulo r);

/*Procedimento que limpa os retangulos da lista*/
void freeRectangle(Retangulo r);



#endif
