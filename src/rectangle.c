#include "rectangle.h"
#include "listaVetor.h"

struct rectangle{
	int id;
	float x;
	float y;
	float w; /*largura*/
	float h; /*altura*/
	char colorFill[20];
	char colorStroke[20];
};

/*Mudança de nome do tipo da instância*/
typedef struct rectangle rectangle;

void drawRectangle(Dado svgBase, Retangulo r){
	FILE *svg;
	rectangle *aux;
	svg = (FILE *)svgBase;
	aux = (rectangle *)r;
	fprintf(svg,"<rect x=\"%.6f\" y=\"%.6f\" height=\"%.6f\" width=\"%.6f\" fill=\"%s\" stroke=\"%s\" />\n",aux->x,aux->y,aux->h,aux->w,aux->colorFill,aux->colorStroke);

}
Retangulo createRectangle(int i, char *stroke, char *fill, float w, float h, float x, float y){
	rectangle *novo;
	novo = (rectangle *)malloc(sizeof(rectangle));
	novo->id = i;
	novo->x = x;
	novo->y = y;
	novo->w = w;
	novo->h = h;
	strcpy(novo->colorFill,fill);
	strcpy(novo->colorStroke,stroke);
	return (Dado)novo;
}

float getRectangleX(Retangulo r){
	rectangle *aux;
	aux = (rectangle *)r;
	return aux->x;
}
float getRectangleY(Retangulo r){
	rectangle *aux;
	aux = (rectangle *)r;
	return aux->y;
}
float getRectangleW(Retangulo r){
	rectangle *aux;
	aux = (rectangle *)r;
	return aux->w;
}
float getRectangleH(Retangulo r){
	rectangle *aux;
	aux = (rectangle *)r;
	return aux->h;
}
char *getRectangleStroke(Retangulo r){
	rectangle *aux;
	aux = (rectangle *)r;
	return aux->colorStroke;
}
char *getRectangleFill(Retangulo r){
	rectangle *aux;
	aux = (rectangle *)r;
	return aux->colorFill;
}
void freeRectangle(Retangulo r){
	rectangle *aux;
	aux = (rectangle *)r;
	free(aux);
	aux = NULL;
}