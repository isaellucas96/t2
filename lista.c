//Lista.c




typedef struct noPontas{
	noPontas *prox;
	noPontas *ant;
	Dado *dado;
};

typedef struct list{
	noPontas *first;
	noPontas *last;
	int size;
};
Lista create(){
	list novaLista;

	novaLista = (list *)malloc(sizeof(list));
	novaLista->first = NULL;
	novaLista->last = NULL;
	novaLista->size = 0;

	return (Lista)novaLista;
}
Posic insert(Lista lista, Dado obj){
	noPontas novoNo;
	noPontas aux;
	novoNo = (noPontas *)malloc(sizeof(noPontas));
	novoNo->dado = obj;
	novoNo->prox = NULL;
	novoNo->ant = NULL;

	if(lista->size == 0){
		lista->first = novoNo;
	}
	else{
		aux = lista->last;
		aux->prox = novoNo;
		novoNo->ant = aux;


	}
	lista->size++;
	lista->last = novoNo;

	return (Posic)novoNo;
	
}
