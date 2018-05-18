
#include "listaVetor.h"


struct date{
	char tipoGeo;
	Dado d;
};

/*Tipo de estrutura de dados de figuras geometricas*/
typedef struct date Date;

Lista createList(Dado in){
	int i,*aux;
	Date *list;
	aux = (int *)in;
	i = *aux;
	list = (Date *)malloc(i*sizeof(Date));
	memset(list,0,sizeof(Date));
	return (Dado)list;
}
void insertListVector(Lista list, Dado obj, int id, char tipoGeo){
	Date *aux;
	aux = (Date *)list;
	aux[id].d = obj;
	aux[id].tipoGeo = tipoGeo; 
}
Dado getObj(Lista list, Dado in){
	Date *aux;
	Dado obj;
	int i, *inteiroAuxiliar;
	inteiroAuxiliar = (int *)in;
	i = *inteiroAuxiliar;
	aux = (Date *)list;
	obj = (Dado)aux[i].d;
	return (Dado)obj;
}
char getTipo(Lista list, Dado in){
	Date *aux;
	char  c;
	int i, *intAux;
	intAux = (int*)in;
	i = *intAux;
	aux = (Date *)list;
	c = aux[i].tipoGeo;
	return c;
}
Lista sizeList(Lista list, Dado in){
	int i, *intAux;
	Date *aux;
	aux = (Date *)list;
	intAux = (int *)in;
	i = *intAux;
	list = (Date *)realloc(list,i*sizeof(Date));
	return (Lista)list;
}
void freeList(Lista list){
	Date *aux;
	aux = (Date *)list;
	free(aux);
	aux = NULL;
} 