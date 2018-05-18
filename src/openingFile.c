#include "openingFile.h"



FILE* openFile(char **pathIn, char **nomeArquivo){
	char *string;
	FILE* arquivo;
	string = (char *)malloc(1000*sizeof(char));
	if(strcmp(*pathIn,"")==0){
		sprintf(string,"%s",*nomeArquivo);
	}
	else sprintf(string,"%s/%s",*pathIn,*nomeArquivo);
	arquivo = fopen(string,"r");
	free(string);
	string = NULL;
	return arquivo;
}
FILE* openFileTxt(char **pathIn, char **nomeArquivo){
	int i,j;
	char  *aux,c,*string,*apoio;
	FILE *arquivo;
	aux = (char *)malloc(500*sizeof(char));
	string = (char *)malloc(500*sizeof(char));
	apoio = (char *)malloc(500*sizeof(char));
	/*for(i=1,c = nomeArquivo[0][0];c!='.';i++){
		aux[i-1] = c;
		c = nomeArquivo[0][i];
		if(c=='.')
			aux[i] = '\0';
	}*/
	strcpy(aux,*nomeArquivo);
	i=0;
	j=0;
	while(1){
		c = aux[i];
		if(c == '/'){
			strcpy(apoio,"");
			j=0;
		}
		if(c == '.')
			if(aux[i+1]=='g')
				if(aux[i+2]=='e')
					if(aux[i+3]=='o'){
						apoio[j]='\0';
						break;
		}
		apoio[j] = c;
		j++;
		i++;
	}

	sprintf(string,"%s/%s.txt",*pathIn,apoio);
	arquivo = fopen(string,"w");
	free(aux);
	aux = NULL;
	return arquivo;

}
FILE* openFileSvg(char **pathOut, char **nomeArquivo){
	int i,j;
	char  *aux,c,*string,*apoio;
	FILE *arquivo;
	aux = (char *)malloc(500*sizeof(char));
	string = (char *)malloc(500*sizeof(char));
	apoio = (char *)malloc(500*sizeof(char));
	/*for(i=1,c = nomeArquivo[0][0];c!='.';i++){
		aux[i-1] = c;
		c = nomeArquivo[0][i];
		if(c=='.')
			aux[i] = '\0';
	}*/
	strcpy(aux,*nomeArquivo);
	__fpurge(stdin);
	i=0;
	j=0;
	while(1){
		c = aux[i];
		if(c == '/'){
			strcpy(apoio,"");
			j=0;
		}
		if(c == '.')
			if(aux[i+1]=='g')
				if(aux[i+2]=='e')
					if(aux[i+3]=='o'){
						apoio[j]='\0';
						break;
		}
		apoio[j] = c;
		j++;
		i++;
	}

	sprintf(string,"%s/%s.svg",*pathOut,apoio);

	arquivo = fopen(string,"w");
	if(arquivo == NULL)
		printf("Arquivo deu ruim\n");
	free(aux);
	free(string);
	free(apoio);
	string = NULL;
	aux = NULL;
	apoio = NULL;
	fprintf(arquivo,"<svg >\n");
	return arquivo;
}
