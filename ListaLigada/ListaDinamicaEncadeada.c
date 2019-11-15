#include "ListaDinamicaEncadeada.h"
#include <stdio.h>
#include <stdlib.h>

/**
*Unidade atomica da lista
*/
typedef struct lista_no{
	int valor;
	no *proximo;
}no;

/**
*@Signature: no* cria_no().
*@Param lista: none.
*@Return: o metodo uma nova instancia de no.
*/
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

/**
*@Signature: void exibe_lista(no *lista).
*@Param lista: elemento cujo valor util sera exibido.
*@Return: void.
*/
void exibe_lista(no *lista){
	no *exibe;
	for(exibe = lista->proximo; exibe != NULL; exibe = exibe->proximo){
		printf("%i ",exibe->valor);
	}
	printf("\n");
}

/**
*@Signature: void adiciona_no(int valor, no *lista).
*@Param valor: valor a ser adicionado.
*@Param lista: elemento no qual o valor sera adicionado.
*@Return: void.
*@Append: o valor sera adicionado no inicio da lista nessa implementacao a lista possui uma cabeca que marca seu inicio.
*/
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

/**
*@Signature: void limpa_lista(no *lista).
*@Param lista: elemento que tera suas informacoes apagadas.
*@Return: void.
*/
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

/**
*@Signature: no *remove_no(int valor, no *lista).
*@Param valor: valor a ser achado.
*@Param lista: elemento no qual o valor sera buscado.
*@Return: o metodo retorno a primeira ocorrencia do valor desejado e remove o no da lista.
*/
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
*@Signature: int contain_valor(int valor, no *lista).
*@Param valor: valor a ser achado.
*@Param lista: elemento no qual o valor sera buscado.
*@Return: o metodo retorna 0 se não encontrar o valor ou entao o numero de ocorrencias do valor.
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

/**
*@Signature: no *ultimo_no(no *n).
*@Param n: elemento elemento que será percorrido ate seu ultimo no.
*@Return: o metodo retorna o ultimo no do elemento dado, no caso n.
*/
no *ultimo_no(no *n){
	if(n->proximo == NULL){
		return n; 
	}else{
		ultimo_no(n->proximo);	
	}
}
