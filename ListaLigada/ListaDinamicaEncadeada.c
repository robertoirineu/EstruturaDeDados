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
	printf("\n");
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
}

no *remove_no(int valor, no *lista){
	
	no *aux, *busca, *retorno;

	busca = lista->proximo;
	aux = cria_no();
	retorno = NULL;
	
	while(busca != NULL && busca->valor != valor){
		adiciona_no(busca->valor, aux);
		busca = busca->proximo;
	}

	if(busca != NULL){
		retorno = cria_no();
		retorno->valor = busca->valor;
		no *ultimo = ultimo_no(aux);

		while(busca != NULL){
			busca = busca->proximo;
			if(busca != NULL){
				adiciona_no(busca->valor, ultimo);
			}
		}

		limpa_lista(lista->proximo);
		lista->proximo = aux->proximo;
		free(aux);
					
	}
	
	return retorno;
}

/**
*@Assinatura: int contain_valor(int valor, no *lista);
*@Param 1 valor: valor a ser achado.
*@Param 2 lista: elemento no qual o valor sera buscado
*@Return: o metodo retorna 0 se não encontrar o valor ou entao o numero de ocorrencias do valor
*/
int contem_valor(int valor, no *lista){
	no *aux = lista ->proximo;
	int achei = 0;

	while(aux != NULL){
		if(aux->valor == valor){
			achei++;		
		}
		aux = aux->proximo;	
	}
	
	return achei;
}

no *ultimo_no(no *n){
	if(n->proximo == NULL){
		return n; 
	}else{
		ultimo_no(n->proximo);	
	}
}
