#include "Fila.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef struct queue{
	int primeiro;
	int ultimo;
	int *que;
	int capacidade;

}fila;

fila* inicia_fila(int tamanho){
	fila *q = (fila*)malloc(sizeof(fila*));
	
	assert(q != NULL);	
	
	q->primeiro = 0;
	q->ultimo = 0;
	q->capacidade = tamanho;
	q->que = malloc(tamanho * sizeof(int*));

	return q;
}

int fila_cheia(fila *f){
	return ((f->ultimo - f->primeiro) == f->capacidade); 
}

void en_queue(int valor, fila* f){

	if(fila_cheia(f)){
		printf("\nFila cheia");	

	}
	
	if(f->ultimo == f->capacidade && f->primeiro != 0){
		f->ultimo = -1;

	}

	if(f->ultimo++ == f->primeiro){
		printf("\nFila cheia");

	}else{
		f->que[f->ultimo] = valor;
		f->ultimo++;
	}
}

