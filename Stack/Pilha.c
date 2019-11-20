#include "Pilha.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/**
*[Fila] estrutura de dados cuja a principal caracteristica e LIFO
*/
typedef struct stack{
	int top;
	int *stc;
	int capacidade;
} pilha;

/**
*@Assign [pilha *cria_pilha(int tamanho)].
*@Parameter [tamanho] o tamanho da pilha a ser criada.
*@Return [pilha *] retorna uma pilha.
*/
pilha *cria_pilha(int tamanho){
	pilha *p = (pilha *)malloc(sizeof(pilha *));

	p->top = -1;
	p->capacidade = tamanho;
	p->stc = (int *)malloc(tamanho * (sizeof(int *)));

	return p;
}

/**
*@Assign [int pilha_cheia(pilha *p)].
*@Parameter [pilha *p] elemento a ser verificado
*@Return [int] retorna 0 caso a pilha nao esteja cheia e 1 caso contrario
*/
int pilha_cheia(pilha *p){
	int tamanho = p->capacidade;
	return p->top == --tamanho;
}

/**
*@Assign [int pilha_vazia(pilha *p)].
*@Parameter [pilha *p] elemento a ser verificado
*@Return [int] retorna 1 caso a pilha nao esteja vazia e 0 do caso contrario
*/
int pilha_vazia(pilha *p){
	return p->top < 0;
}

/**
*@Assign [int tamanho_pilha(pilha *p)].
*@Parameter [pilha *p] elemento cujo os itens serao contadas.
*@Return [int] retorna a quantidade de elementos da pilha.
*/
int tamanho_pilha(pilha *p){
	int tamanho = p->top;
	return ++tamanho;
}

/**
*@Assign [int to_pop(pilha *p)].
*@Parameter [pilha *p] elemento cujo item sera removido.
*@Return [int] retorna o elemento do topo da pilha.
*/
int to_pop(pilha *p){
	
	if(pilha_vazia(p)){
		printf("\nPilha vazia, remocao nao possivel.\n");
		assert(!pilha_vazia(p));
	}

	return p->stc[p->top--];
}

/**
*@Assign [void to_push(int valor, pilha *p)].
*@Parameter [valor] elemento cujo item sera removido.
*@Parameter [pilha *p] elemento cujo item sera removido.
*@Return [void].
*/
void to_push(int valor, pilha *p){
	
	if(pilha_cheia(p)){
		printf("\nPilha cheia, adicao nao possivel.\n");
		assert(!pilha_cheia(p));
	}

	p->stc[++p->top] = valor;
}

/**
*@Assign [void exibir_pilha(pilha *p)].
*@Parameter [pilha *p] elemento cujo item sera exibido.
*@Return [void].
*/
void exibir_pilha(pilha *p){
	int interator;
	int top = p->top;
	for(interator = top; interator > -1; interator--){
		printf("\n  %i", p->stc[interator]);
	}
}




