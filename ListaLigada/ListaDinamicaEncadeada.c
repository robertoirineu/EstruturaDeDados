#include "ListaDinamicaEncadeada.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct lista_no{
	int valor;
	no *proximo;
}no;

no* cria_no(){
	no* novo; 
	novo = (no *)malloc(sizeof(no *));

	if(novo == NULL){
		printf("\nNao foi possivel criar novo no.");
	}else{	
		novo->proximo = NULL;
	}

	return novo;

}


void exibe_lista(no *lista){
	no *exibe;
	for(exibe = lista->proximo; exibe != NULL; exibe = exibe->proximo){
		printf("%i ",exibe->valor);
	}
}

void adiciona_no(int valor, no *lista){
	if(lista == NULL){
		printf("\nA lista esta nula");
	}else{
	
		no *novo;
		novo = cria_no();
	
		novo->valor = valor;
		novo->proximo = lista->proximo;
		lista->proximo = novo;	
	}
}

void limpa_lista(no *lista){
	no *n = lista, *aux;
	
	while (n != NULL)
	{
        	aux = n;
        	n = n->proximo;
        	free (aux);
	}

    	lista = NULL;

	printf("\nLista vazia");
}

no *remove_no(int valor, no *lista){
	no *aux, *busca, *retorno;
	aux = cria_no();
	busca = lista->proximo;
	
	while(busca != NULL && busca->valor != valor){
		adiciona_no(busca->valor, aux);
		busca = busca->proximo;
	}

	if(busca != NULL){
		retorno = (no *)malloc(sizeof(no*));
		if(retorno != NULL){
			retorno->proximo = NULL;
			retorno->valor = aux->valor;
			
		}	
	}

	return retorno;
}













