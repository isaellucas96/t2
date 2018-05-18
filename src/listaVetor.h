#ifndef __LISTAVETOR_
#define __LISTAVETOR_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*Tipo de dado*/
typedef void* Dado;

/*Tipo lista de vetor*/
typedef void* Lista;

/*Procedimento para inserir objeto na lista*/
void insertListVector(Lista list, Dado obj, int id, char tipoGeo);

/*Função para criar uma lista*/
Lista createList(Dado in);

/*Função para obter um objeto da lista*/
Dado getObj(Lista list, Dado in);

/*Função que retorna o tipo de forma geometrica que esta naquele id*/
char getTipo(Lista list, Dado in);

/*Função para redimensionar a lista*/
Lista sizeList(Lista list, Dado in);

/*Procedimento para liberar a lista*/
void freeList(Lista list);

#endif
