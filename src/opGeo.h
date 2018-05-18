#ifndef __OPGEO_
#define __OPGEO_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaVetor.h"
#include "circle.h"
#include "rectangle.h"
#include "openingFile.h"


/*Função para calcular a distancia*/
float distancia(float xb, float xa, float yb, float ya);

/*Procedimento que calcula se existe a sobreposicao de figuras geometricas
 e faz os devidos avisos no arquivo de saida*/
void sobreposicao(Lista list, FILE *arquivo, FILE *fileConsulta, FILE *svg);

/*Procedimento que dado um ponto, verifica se ele eh interno a figura*/
void pontoInterno(Lista list, FILE *arquivo, FILE* fileConsulta);

/*Procedimento que calcula a distancia entre figuras*/
void dPoint(Lista list, FILE *arquivo, FILE *fileConsulta);

/*Procedimento que cria um arquivo svg e desenha as figuras pedidas e
linhas em seus centros de massa*/
void cSvg(Lista list, FILE *arquivo, char **nomeArquivo, char **pathOut, int *size);


#endif
