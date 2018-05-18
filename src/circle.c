

#include "listaVetor.h"
#include "circle.h"

struct circle{
	int id;
	float x;
	float y;
	float stroke;
	float radius;
	char colorFill[20];
	char colorStroke[20];
};

/*Mudança no nome da struct para o nome do objeto circulo*/
typedef struct circle circle;

void drawCircle(Dado svgBase, Circulo c){
	FILE *svg;
	circle *aux;
	svg = (FILE *)svgBase;
	aux = (circle *)c;
	fprintf(svg,"<circle cx=\"%.6f\" cy=\"%.6f\" r=\"%.6f\" fill=\"%s\" stroke=\"%s\" />\n",aux->x,aux->y,aux->radius,aux->colorFill,aux->colorStroke);
}
Circulo createCircle(int i, char *stroke, char *fill, float r, float x, float y){
	circle *novo;
	novo = (circle *)malloc(sizeof(circle));
	novo->id = i;
	novo->x = x;
	novo->y = y;
	novo->radius = r;
	strcpy(novo->colorFill,fill);
	strcpy(novo->colorStroke,stroke);
	return (Dado)novo;	
}

float getRaio(Circulo c){
	circle *aux;
	aux = (circle *)c;
	return aux->radius;
}
float getCircleX(Circulo c){
	circle *aux;
	aux = (circle *)c;
	return aux->x;
}
float getCircleY(Circulo c){
	circle *aux;
	aux = (circle *)c;
	return aux->y;
}
char *getCircleFill(Circulo c){
	circle *aux;
	aux = (circle *)c;
	return aux->colorFill;
}
char *getCircleStroke(Circulo c){
	circle *aux;
	aux = (circle *)c;
	return aux->colorStroke;
}

void freeCircle(Circulo c){
	circle *aux;
	aux = (circle *)c;
	free(aux);
	aux = NULL;
}





