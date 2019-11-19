#include "Fila.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/**
*[Fila]Elemento cuja caracteristica principal e FIFO 
*/
typedef struct queue{
	int primeiro;
	int ultimo;
	int *que;
	int capacidade;

}fila;

/**
*@Assign [fila* inicia_fila(int tamanho)].
*@Param [tamanho] capacidade maxima da fila.
*@Return [fila*] retorna uma fila.
*/
fila* inicia_fila(int tamanho){
	fila *q = (fila*)malloc(sizeof(fila*));
	
	assert(q != NULL);	
	
	q->primeiro = 0;
	q->ultimo = 0;
	q->capacidade = tamanho;
	q->que = malloc(tamanho * sizeof(int*));

	return q;
}

/**
*@Assign [fila_vazia(fila *f)].
*@Param [fila*] elemento a ser verificado.
*@Return [int] retorna 1 se fila vazia e 0 se conter algum elemento na fila.
*/
int fila_vazia(fila *f){
	return f->ultimo == f->primeiro; 
}

/**
*@Assign [int fila_cheia(fila *f)].
*@Param [fila*] elemento a ser verificado.
*@Return [int] retorna 0 se fila conter algum elemento e 1 se fila cheia.
*/
int fila_cheia(fila *f){
	return ((f->ultimo - f->primeiro) == f->capacidade); 
}

/**
*@Assign [int de_queue(fila* f)].
*@Param [fila*] elemento cujo valor sera retirado.
*@Return [int] retorna o elemento que esta a mais tempo na fila, ou seja, o que entrou primeiro, caso não seja possível a extrasao retorna -1.
*/
int de_queue(fila* f){
	if(fila_vazia(f)){
		printf("Fila vazia");
		assert(fila_vazia(f));	
	}

	int valor = f->que[f->primeiro];
	if(f->primeiro == (f->capacidade - 1)){
		f->primeiro = 0;
	}else{
		f->primeiro++;
	}
	
	return valor;
}

/**
*@Assign [void en_queue(int valor, fila* f)].
*@Param [valor] elemento a ser adicionado na fila.
*@Param [fila*] elemento no qual valor sera adicionado.
*@Return [void].
*/
void en_queue(int valor, fila* f){

	int adicionar = 1;
	int ver = f->ultimo;

	if(fila_cheia(f)){
		printf("\nFila cheia.\n");
		adicionar = 0;	

	}else if(f->ultimo == f->capacidade && f->primeiro != 0){
		f->ultimo = 0;
		

	}
	
	if((++ver) == f->primeiro){
		printf("\n|Fila cheia|\n");
		adicionar = 0;

	}
	
	if(adicionar){
		f->que[f->ultimo] = valor;
		f->ultimo++;
	}
}

/**
*@Assign [void ver_fila(fila *f)].
*@Param [fila*] elemento cujo valor sera exibido.
*@Return [void].
*/
void ver_fila(fila *f){
	int interator;
	
	if(f->primeiro > f->ultimo){
		for(interator = f->primeiro; interator < f->capacidade; interator++){
			printf("%i ",f->que[interator]);
		}

		for(interator = 0; interator < f->ultimo; interator++){
			printf("%i ",f->que[interator]);
		}		
	}else{
		for(interator = f->primeiro; interator < f->ultimo; interator++){
			printf("%i ",f->que[interator]);
		}
	}
}

