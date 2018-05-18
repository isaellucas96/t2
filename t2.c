/*Trabalho 2*/
/*Isael Antonio Lucas Paulo*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "circle.h"
#include "rectangle.h"
#include "listaVetor.h"
#include "opGeo.h"
#include "openingFile.h"

void procedimentos(char **pathIn, char **pathOut, char **nomeArquivo, int *i){
	FILE *file, *fileConsulta, *svgBase;
	char comando[5];
	char colorFill[20], colorStroke[20],c;
	float x,y,r,w,h;
	int aux,j,id;
	Dado obj;
	Lista list;
	list = createList((Dado)i);
	file = openFile(pathIn,nomeArquivo);
	fileConsulta = openFileTxt(pathOut,nomeArquivo);
	svgBase = openFileSvg(pathOut,nomeArquivo);
	printf("antes do while\n");
	while(!feof(file)){
		printf("aqui dps do while\n");
		fscanf(file,"%s",comando);
		printf("aqui leu o comando-> %s\n",comando);
		/*comando 'nx' para alterar valor maximo de circulos e retangulos*/
		if(strcmp(comando,"nx")==0){
			fscanf(file,"%d",&aux);
			*i = aux;
			list = sizeList((Dado)list,(Dado)i);
		}
		/*comando 'c' para desenhar circulo*/
		else if(strcmp(comando,"c")==0){
			fscanf(file,"%d %s %s %f %f %f",&id,colorStroke,colorFill,&r,&x,&y);
			obj = createCircle(id,colorStroke,colorFill,r,x,y);
			insertListVector(list,obj,id,'c');
			drawCircle((Dado)svgBase,obj);
			obj = NULL;
		}
		/*comando 'r' para desenhar retangulo*/
		else if(strcmp(comando,"r")==0){
			fscanf(file,"%d %s %s %f %f %f %f",&id,colorStroke,colorFill,&w,&h,&x,&y);
			obj = createRectangle(id,colorStroke,colorFill,w,h,x,y);
			insertListVector(list,obj,id,'r');
			drawRectangle((Dado)svgBase,obj);
			obj = NULL;

		}
		/*comando 'o' para identificar sobreposição*/
		else if(strcmp(comando,"o")==0){
			sobreposicao(list,file,fileConsulta,svgBase);
		}
		/*comando 'i' para identificar se eh interno na forma geometrica*/
		else if(strcmp(comando,"i")==0){
			pontoInterno((Lista)list,file,fileConsulta);
		}
		/*comando 'd' para descobrir distancia de dois pontos*/
		else if(strcmp(comando,"d")==0){
			dPoint((Lista)list,file,fileConsulta);
		}
		/*comando 'a' para descobrir distancia de dois pontos*/
		else if(strcmp(comando,"a")==0){
			cSvg((Lista)list,file,nomeArquivo,pathOut,i);
		}
		/*comando '#' indicando o final do arquivo*/
		else if(strcmp(comando,"#")==0){
			for(aux=0;aux<(*i);i++){
				c = getTipo(list,(Dado)&aux);
				if(c == 'c'){
					obj = getObj(list,(Dado)&aux);
					freeCircle(obj);
				}
				else if(c == 'r'){
					obj = getObj(list,(Dado)&aux);
					freeRectangle(obj);
				}
			}
			freeList(list);
			fprintf(svgBase,"</svg>");
			fclose(svgBase);
			fclose(fileConsulta);
			fclose(file);
			break;
		}
	}
}
void parameters(int argc, char const **argv,char **pathIn,char **pathOut,char **nomeArquivo){
	int i;
	for(i=1;i<argc;i++){
		if(strcmp(argv[i],"-e")==0){
			strcpy(*(pathIn),argv[i+1]);
		}
		else if(strcmp(argv[i],"-f")==0){
			strcpy(*(nomeArquivo),argv[i+1]);
		}
		else if(strcmp(argv[i],"-o")==0){
			strcpy(*(pathOut),argv[i+1]);
		}
	}
}
int main(int argc, char const *argv[])
{
	int numeroMax;
	char **pathIn, **pathOut, **nomeArquivo;
	pathIn = (char **)malloc(sizeof(char*));
	pathOut = (char **)malloc(sizeof(char*));
	nomeArquivo = (char **)malloc(sizeof(char*));
	/*Alocações iniciais*/
	printf("alocacoes iniciais\n");
	*pathIn = (char *)malloc(1000*sizeof(char));
	*pathOut = (char *)malloc(1000*sizeof(char));
	*nomeArquivo = (char *)malloc(1000*sizeof(char));
	/*Fim das alocações dinamicas*/
	numeroMax = 1000;
	printf("antes dos parameters\n");
	strcpy(*pathIn,"");
	parameters(argc,argv,pathIn,pathOut,nomeArquivo);
	printf("depois dos parameters\n");
	procedimentos(pathIn,pathOut,nomeArquivo,&numeroMax);
	printf("dps dos procedimentos\n");
	free(*pathIn);
	free(*pathOut);
	free(*nomeArquivo);
	free(pathIn);
	free(pathOut);
	free(nomeArquivo);
	return 0;
}