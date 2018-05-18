#ifndef __OPENINGF_
#define __OPENINGF_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Função para abrir arquivo com nomes em uma ou mais stings*/
FILE* openFile(char **pathIn, char **nomeArquivo);

/*Função para abrir arquivo txt de consultas*/
FILE* openFileTxt(char **pathIn, char **nomeArquivo);

/*Função para abrir arquivo svg*/
FILE* openFileSvg(char **pathOut, char **nomeArquivo);


#endif