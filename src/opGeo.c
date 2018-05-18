

#include "opGeo.h"
float distancia(float xb, float xa, float yb, float ya){
	float aux;
	aux = sqrt((pow((xb-xa),2))+(pow((yb-ya),2)));
	return aux;
}

void sobreposicao(Lista list, FILE *arquivo, FILE *fileConsulta, FILE *svg){
	int j,k;
	float dist,somaRaios,x,y,altura,largura,i,alt;
	float xSo, ySo, hSo, wSo;/*Variaveis do retangulo de sobreposicao*/
	char sobrepoe = 'n';/*'s' para SIM e 'n' para NAO*/
	char tipoJ, tipoK;
	Dado one, two;
	Dado oneR, twoR;
	fscanf(arquivo,"%d %d",&j,&k);
	tipoJ = getTipo(list,&j);
	tipoK = getTipo(list,&k);
	if(tipoJ=='c' && tipoK=='c'){
		/*Ambos sao circulos*/
		one = getObj(list,&j);
		two = getObj(list,&k);

		dist = distancia(getCircleX(two),getCircleX(one),getCircleY(two),getCircleY(one));
		somaRaios = getRaio(one)+getRaio(two);
		if(somaRaios>dist){
			sobrepoe = 's';
			/*------------desenho do sobrepoe-------*/
			if((getCircleX(one)-getRaio(one))<((getCircleX(two)-getRaio(two)))){
				xSo = getCircleX(one) - getRaio(one);
			}
			else if((getCircleX(two)-getRaio(two))<((getCircleX(one)-getRaio(one)))){
				xSo = getCircleX(two) - getRaio(two);
			}
			if((getCircleX(one)+getRaio(one))>((getCircleX(two)+getRaio(two)))){
				wSo = getCircleX(one) + getRaio(one) - xSo;
			}
			else if((getCircleX(two)+getRaio(two))>((getCircleX(one)+getRaio(one)))){
				wSo = getCircleX(two) + getRaio(two) - xSo;
			}
			if((getCircleY(one)-getRaio(one))<((getCircleY(two)-getRaio(two)))){
				ySo = getCircleY(one) - getRaio(one);
			}
			else if((getCircleY(two)-getRaio(two))<((getCircleY(one)-getRaio(one)))){
				ySo = getCircleY(two) - getRaio(two);
			}
			if((getCircleY(one)+getRaio(one))>((getCircleY(two)+getRaio(two)))){
				hSo = getCircleY(one) + getRaio(one) - ySo;
			}
			else if((getCircleY(two)+getRaio(two))>((getCircleY(one)+getRaio(one)))){
				hSo = getCircleY(two) + getRaio(two) - ySo;
			}
			fprintf(svg,"<rect x=\"%.6f\" y=\"%.6f\" height=\"%.6f\" width=\"%.6f\" fill=\"none\" stroke=\"%s\" stroke-dasharray=\"5\" />\n",(xSo-1),(ySo-1),(hSo+2),(wSo+2),"purple");/* stroke-dasharray=\"2\" */
			fprintf(svg,"<text x=\"%.6f\" y=\"%.6f\" font-size=\"%.6f\" fill=\"%s\"> sobrepõe</text>\n",xSo,(ySo),(hSo/5),"purple");
			/*----------------fim do desenho do sobrepoe----*/	
		}

	}
	else if((tipoJ=='r' && tipoK=='c')||(tipoJ=='c' && tipoK=='r')){
		if(tipoJ=='r' && tipoK=='c'){
			oneR = getObj(list,&j);
			two = getObj(list,&k);
		}
		else{
			oneR = getObj(list,&k);
			two = getObj(list,&j);
		}

		x = getRectangleX(oneR);
		y = getRectangleY(oneR);
		altura = getRectangleH(oneR);
		largura = getRectangleW(oneR);
		/*for(i=x;i<=(largura+x);i+=0.01){
			dist = distancia(i,getCircleX(two),y,getCircleY(two));
			if(dist<getRaio(two)){
				sobrepoe = 's';
				break;
			}
			dist = distancia(i,getCircleX(two),(y+altura),getCircleY(two));
			if(dist<getRaio(two)){
				sobrepoe = 's';
				break;
			}
		}
		if(sobrepoe == 'n')
		for(i=y;i<=(altura+y);i+=0.01){
			dist = distancia(x,getCircleX(two),i,getCircleY(two));
			if(dist<getRaio(two)){
				sobrepoe = 's';
				break;
			}
			dist = distancia((x+largura),getCircleX(two),i,getCircleY(two));
			if(dist<getRaio(two)){
				sobrepoe = 's';
				break;
			}
		}*/
		for(alt=y;alt<=(y+altura);alt+=0.01){
			for(i=x;i<=(x+largura);i+=0.01){
				dist = distancia(i,getCircleX(two),alt,getCircleY(two));
				if(dist<getRaio(two)){
					sobrepoe = 's';
					
				}
			}
		}
		/*------------desenho do tracejado do sobrepoe-------------*/
		if(sobrepoe == 's'){
			if(x<(getCircleX(two)-getRaio(two))){
				xSo = x;
			}
			else if((getCircleX(two)-getRaio(two))<x){
				xSo = (getCircleX(two) - getRaio(two));
			}
			if((x+largura)>(getCircleX(two)+getRaio(two))){
				wSo = (x+largura) - xSo;	
			}
			else if((getCircleX(two)+getRaio(two))>(x+largura)){
				wSo = (getCircleX(two)+getRaio(two)) - xSo;
			}
			if(y<(getCircleY(two)-getRaio(two))){
				ySo = y;
			}
			else if((getCircleY(two)-getRaio(two))<y){
				ySo = (getCircleY(two) - getRaio(two));
			}
			if((y+altura)>(getCircleY(two)+getRaio(two))){
				hSo = y+altura-ySo;
			}
			else if((getCircleY(two)+getRaio(two))>(y+altura)){
				hSo = (getCircleY(two)+getRaio(two)) - ySo;
			}
			fprintf(svg,"<rect x=\"%.6f\" y=\"%.6f\" height=\"%.6f\" width=\"%.6f\" fill=\"none\" stroke=\"%s\" stroke-dasharray=\"5\" />\n",(xSo-1),(ySo-1),(hSo+2),(wSo+2),"purple");
			fprintf(svg,"<text x=\"%.6f\" y=\"%.6f\" font-size=\"%.6f\" fill=\"%s\"> sobrepõe</text>\n",xSo,(ySo),(hSo/5),"purple");
		/*----------------desenho do tracejado do sobrepoe-------------*/
		}
		
	}
	/*else if(tipoJ=='c' && tipoK=='r'){
		circle *one;
		rectangle *two;
		one = (circle *)vetorId[j];
		two = (rectangle *)vetorId[two];
	}*/
	else if(tipoJ=='r' && tipoK=='r'){
		oneR = getObj(list,(Dado)&j);
		twoR = getObj(list,(Dado)&k);

		/*if(getCircleX(one) > getCircleX(two) && getCircleX(one) <(getCircleX(two) + two->w)){
			if(getCircleY(one) > getCircleY(two), && getCircleY(one) < (getCircleY(two), + two->h))
				sobrepoe = 's';
			else if((getCircleY(one) + one->h) > getCircleY(two), && (getCircleY(one) + one->h) < (getCircleY(two), + two->h))
				sobrepoe = 's';
		}
		else if((getCircleX(one) + one->w) > getCircleX(two) && (getCircleX(one) + one->w) < (getCircleX(two) + two->w)){
			if(getCircleY(one) > getCircleY(two), && getCircleY(one) < (getCircleY(two), + two->h))
				sobrepoe = 's';
			else if((getCircleY(one) + one->h) > getCircleY(two), && (getCircleY(one) + one->h) < (getCircleY(two), + two->h))
				sobrepoe = 's';
		}*/
		if(((getRectangleX(twoR)>=getRectangleX(oneR)&&getRectangleX(twoR)<=(getRectangleX(oneR)+getRectangleW(oneR)))||(getRectangleX(oneR)>=getRectangleX(twoR)&&getRectangleX(oneR)<=(getRectangleX(twoR)+getRectangleW(twoR))))||(((getRectangleX(twoR)+getRectangleW(twoR))>=getRectangleX(oneR)&&(getRectangleX(twoR)+getRectangleW(twoR))<=(getRectangleX(oneR)+getRectangleW(oneR)))||((getRectangleX(oneR)+getRectangleW(oneR))>=getRectangleX(twoR)&&(getRectangleX(oneR)+getRectangleW(oneR))<=(getRectangleX(twoR)+getRectangleW(twoR))))){
			if(((getRectangleY(oneR))<=(getRectangleY(twoR)+getRectangleH(twoR))&&getRectangleY(oneR)>=getRectangleY(twoR))||(getRectangleY(twoR)>=getRectangleY(oneR)&&getRectangleY(twoR)<=(getRectangleY(oneR)+getRectangleH(oneR)))
				||((getRectangleY(oneR)+getRectangleH(oneR))<=(getRectangleY(twoR)+getRectangleH(twoR))&&(getRectangleY(oneR)+getRectangleH(oneR))>=getRectangleY(twoR)||(getRectangleY(twoR)+getRectangleH(twoR))>=getRectangleY(oneR)&&(getRectangleY(twoR)+getRectangleH(twoR))<=(getRectangleY(oneR)+getRectangleH(oneR)))){
				sobrepoe = 's';
			}
		}
		/*---------------------------tracejado do sobrepoe-----------------*/
		if(sobrepoe == 's'){
			if(getRectangleX(oneR)<getRectangleX(twoR)){
				xSo = getRectangleX(oneR);
			}
			else if(getRectangleX(twoR)<=getRectangleX(oneR)){
				xSo = getRectangleX(twoR);
			}
			if((getRectangleX(oneR)+getRectangleW(oneR))>(getRectangleX(twoR)+getRectangleW(twoR))){
				wSo = getRectangleX(oneR) + getRectangleW(oneR) - xSo;
			}
			else if((getRectangleX(twoR)+getRectangleW(twoR))>=(getRectangleX(oneR)+getRectangleW(oneR))){
				wSo = getRectangleX(twoR) + getRectangleW(twoR) - xSo;
			}
			if(getRectangleY(oneR)<getRectangleY(twoR)){
				ySo = getRectangleY(oneR);
			}
			else if(getRectangleY(twoR)<=getRectangleY(oneR)){
				ySo = getRectangleY(twoR);
			}
			if((getRectangleY(oneR)+getRectangleH(oneR))>(getRectangleY(twoR)+getRectangleH(twoR))){
				hSo = getRectangleY(oneR) + getRectangleH(oneR) - ySo;
			}
			else if((getRectangleY(twoR)+getRectangleH(twoR))>=(getRectangleY(oneR)+getRectangleH(oneR))){
				hSo = getRectangleY(twoR) + getRectangleH(twoR) - ySo;
			}
			fprintf(svg,"<rect x=\"%.6f\" y=\"%.6f\" height=\"%.6f\" width=\"%.6f\" fill=\"none\" stroke=\"%s\" stroke-dasharray=\"5\" />\n",(xSo-1),(ySo-1),(hSo+2),(wSo+2),"purple");/* stroke-dasharray=\"2\" */
			fprintf(svg,"<text x=\"%.6f\" y=\"%.6f\" font-size=\"%.6f\" fill=\"%s\"> sobrepõe</text>\n",xSo,(ySo),(hSo/5),"purple");
			/*----------------------------fim do tracejado---------------*/
		}

		
	}
	if(sobrepoe == 's')
		fprintf(fileConsulta,"o %d %d\nSIM\n",j,k);
	else
		fprintf(fileConsulta,"o %d %d\nNAO\n",j,k);
}

void pontoInterno(Lista list, FILE *arquivo, FILE *fileConsulta){
	int j;
	float x,y,dist;
	char tipoJ;
	Dado c, r;
	fscanf(arquivo,"%d %f %f",&j,&x,&y);
	tipoJ = getTipo(list,(Dado)&j);
	if(tipoJ == 'c'){
		c = getObj(list,(Dado)&j);
		dist = distancia(x,getCircleX(c),y,getCircleY(c));
		if(dist<(getRaio(c)-1)){
			fprintf(fileConsulta,"i %d %.6f %.6f\nSIM\n",j,x,y);
		}
		else{
			fprintf(fileConsulta,"i %d %.6f %.6f\nNAO\n",j,x,y);
		}
	}
	else if(tipoJ =='r'){
		r = getObj(list,(Dado)&j);
		if(x>(getRectangleX(r)-1) && x<((getRectangleX(r)+1)+(getRectangleW(r)-2))){
			if(y>(getRectangleY(r)+1) && y<((getRectangleY(r)+1)+(getRectangleH(r)-2))){
				fprintf(fileConsulta,"i %d %.6f %.6f\nSIM\n",j,x,y);
			}
			else{
				fprintf(fileConsulta,"i %d %.6f %.6f\nNAO\n",j,x,y);
			}
		}
		else{
			fprintf(fileConsulta,"i %d %.6f %.6f\nNAO\n",j,x,y);
		}
	}
}
void dPoint(Lista list, FILE *arquivo, FILE *fileConsulta){
	int j,k;
	float dist;
	char tipoJ, tipoK;
	Dado one, two, c;
	Dado r, oneR, twoR;
	fscanf(arquivo,"%d %d",&j,&k);
	tipoJ = getTipo(list,(Dado)&j);
	tipoK = getTipo(list,(Dado)&k);
	if(tipoJ=='c' && tipoK=='c'){
		one = getObj(list,(Dado)&j);
		two = getObj(list,(Dado)&k);

		dist = distancia(getCircleX(one),getCircleX(two),getCircleY(one),getCircleY(two));
	}
	else if(tipoJ=='r' && tipoK=='c'){
		r = getObj(list,(Dado)&j);
		c = getObj(list,(Dado)&k);

		dist = distancia((getRectangleX(r)+(getRectangleW(r)/2)),getCircleX(c),(getRectangleY(r)+(getRectangleH(r)/2)),getCircleY(c));
	}
	else if(tipoJ=='c' && tipoK=='r'){
		r = getObj(list,(Dado)&k);
		c = getObj(list,(Dado)&j);

		dist = distancia((getRectangleX(r)+(getRectangleW(r)/2)),getCircleX(c),(getRectangleY(r)+(getRectangleH(r)/2)),getCircleY(c));
	}
	else if(tipoJ=='r' && tipoK=='r'){
		oneR = getObj(list,(Dado)&j);
		twoR = getObj(list,(Dado)&k);

		dist = distancia((getRectangleX(oneR)+(getRectangleW(oneR)/2)),(getRectangleX(twoR)+(getRectangleW(twoR)/2)),(getRectangleY(oneR)+(getRectangleH(oneR)/2)),(getRectangleY(twoR)+(getRectangleH(twoR)/2)));

	}
	fprintf(fileConsulta,"d %d %d\n%.6f\n",j,k,dist);
}

void cSvg(Lista list, FILE *arquivo, char **nomeArquivo, char **pathOut, int *size){
	int j,i,borja;
	char caractere,**nomeArquivoSufixo,*sufixo,colorStroke[20],tipoJ,*string,*apoio;
	float dist,xCenter,yCenter,xAux,yAux,xC,yC;
	FILE *svgSufixo;
	Dado c, aux, r;
	Dado date;
	nomeArquivoSufixo = (char **)malloc(sizeof(char*));
	*nomeArquivoSufixo = (char *)malloc(500*sizeof(char));
	string = (char *)malloc(500*sizeof(char));
	sufixo = (char *)malloc(500*sizeof(char));
 	apoio = (char *)malloc(500*sizeof(char));
	fscanf(arquivo,"%d %s",&j,sufixo);
	caractere = ' ';
	/*for(i=0; ;i++){
		caractere = nomeArquivo[0][i];
		if(caractere == '.'){
			nomeArquivoSufixo[0][i] = '\0';
			break;
		}
		nomeArquivoSufixo[0][i] = caractere;
	}*/
	i=0;
	borja=0;
	while(1){
		caractere = nomeArquivo[0][i];
		if(caractere == '/'){
			strcpy(apoio,"");
			borja=0;
		}
		if(caractere == '.')
			if(nomeArquivo[0][i+1]=='g')
				if(nomeArquivo[0][i+2]=='e')
					if(nomeArquivo[0][i+3]=='o'){
						apoio[borja]='\0';
						break;
		}
		apoio[borja] = caractere;
		borja++;
		i++;
	}
	tipoJ = getTipo(list,(Dado)&j);
	sprintf(string,"%s/%s-%s.svg",*pathOut,apoio,sufixo);
	/*svgSufixo = openFileSvg(pathOut,&string);*/
	svgSufixo = fopen(string,"w");
	fprintf(svgSufixo,"<svg >\n");
	for(i=0;i<(*size);i++){
		caractere = getTipo(list,(Dado)&i);
		if(caractere =='c'){
			date = getObj(list,(Dado)&i);
			drawCircle((Dado)svgSufixo,(Dado)date);
		}
		else if(caractere == 'r'){
			date = getObj(list,(Dado)&i);
			drawRectangle((Dado)svgSufixo,(Dado)date);
		}
	}
	if(tipoJ=='c'){
		c = getObj(list,(Dado)&j);
		strcpy(colorStroke,getCircleStroke(c));
		for(i=0;i<(*size);i++){
			caractere = getTipo(list,(Dado)&i);
			if(caractere == 'c'){
				aux = getObj(list,(Dado)&i);
				dist = distancia(getCircleX(c),getCircleX(aux),getCircleY(c),getCircleY(aux));
				xAux = (getCircleX(c)+((getCircleX(c) - getCircleX(aux))/2)*(-1));
				yAux = (getCircleY(c)+((getCircleY(c) - getCircleY(aux))/2)*(-1));
				fprintf(svgSufixo,"<line x1=\"%.6f\" y1=\"%.6f\" x2=\"%.6f\" y2=\"%.6f\" stroke=\"%s\"/>\n",getCircleX(c),getCircleY(c),getCircleX(aux),getCircleY(aux),colorStroke);
				fprintf(svgSufixo,"<text x=\"%.6f\" y=\"%.6f\" font-size=\"auto\" fill=\"%s\"> %.2f</text>\n",(xAux+3.0),(yAux+3.0),colorStroke,dist);
			}
			else if(caractere == 'r'){
				aux = getObj(list,(Dado)&i);
				xCenter = (getRectangleX(aux)+(getRectangleW(aux)/2));
				yCenter = (getRectangleY(aux)+(getRectangleH(aux)/2));
				dist = distancia(getCircleX(c),xCenter,getCircleY(c),yCenter);
				xAux = (getCircleX(c)+((getCircleX(c) - xCenter)/2)*(-1));
				yAux = (getCircleY(c)+((getCircleY(c) - yCenter)/2)*(-1));
				fprintf(svgSufixo,"<line x1=\"%.6f\" y1=\"%.6f\" x2=\"%.6f\" y2=\"%.6f\" stroke=\"%s\"/>\n",getCircleX(c),getCircleY(c),xCenter,yCenter,colorStroke);
				fprintf(svgSufixo,"<text x=\"%.6f\" y=\"%.6f\" font-size=\"auto\" fill=\"%s\"> %.2f</text>\n",(xAux+3.0),(yAux+3.0),colorStroke,dist);
			}
		}
	}
	else if(tipoJ=='r'){
		r = getObj(list,(Dado)&j);
		xC = (getRectangleX(r)+(getRectangleW(r)/2));
		yC = (getRectangleY(r)+(getRectangleH(r)/2));
		strcpy(colorStroke,getRectangleStroke(r));
		for(i=0;i<(*size);i++){
			if(i==j)
				i++;
			caractere = getTipo(list,(Dado)&i);
			if(caractere == 'c'){
				
				
				aux = getObj(list,(Dado)&i);
				dist = distancia(xC,getCircleX(aux),yC,getCircleY(aux));
				xAux = (xC+((xC - getCircleX(aux))/2)*(-1));
				yAux = (yC+((yC - getCircleY(aux))/2)*(-1));
				fprintf(svgSufixo,"<line x1=\"%.6f\" y1=\"%.6f\" x2=\"%.6f\" y2=\"%.6f\" stroke=\"%s\"/>\n",xC,yC,getCircleX(aux),getCircleY(aux),colorStroke);
				fprintf(svgSufixo,"<text x=\"%.6f\" y=\"%.6f\" font-size=\"auto\" fill=\"%s\"> %.2f</text>\n",(xAux+3.0),(yAux+3.0),colorStroke,dist);
			}
			else if(caractere == 'r'){
				
				aux = getObj(list,(Dado)&i);
				xCenter = (getRectangleX(aux)+(getRectangleW(aux)/2));
				yCenter = (getRectangleY(aux)+(getRectangleH(aux)/2));
				dist = distancia(xC,xCenter,yC,yCenter);
				xAux = (xC+((xC - xCenter)/2)*(-1));
				yAux = (yC+((yC - yCenter)/2)*(-1));
				fprintf(svgSufixo,"<line x1=\"%.6f\" y1=\"%.6f\" x2=\"%.6f\" y2=\"%.6f\" stroke=\"%s\"/>\n",xC,yC,xCenter,yCenter,colorStroke);
				fprintf(svgSufixo,"<text x=\"%.6f\" y=\"%.6f\" font-size=\"auto\" fill=\"%s\"> %.2f</text>\n",(xAux+3.0),(yAux+3.0),colorStroke,dist);
			}
		}
	}
	fprintf(svgSufixo,"</svg>");
	fclose(svgSufixo);
	free(sufixo);
	free(*nomeArquivoSufixo);
	free(nomeArquivoSufixo);
	free(apoio);
}






