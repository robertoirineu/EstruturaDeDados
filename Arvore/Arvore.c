#include "Arvore.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/**
*[Node] unidade básica da árvore contendo duas folhas
*/
typedef struct node{
	int valor;
	no *e;
	no *d;

} no;

/**
*@Assing [no *criar_no()]
*@Parameter [empty]
*@Return [no *] Caso seja possível criar o nó ele é retornado.
*/
no *criar_no(){
	setlocale(LC_ALL,"Portuguese");

	no *n = (no *)malloc(sizeof(no *));
	
	if(n != NULL){
		printf("Não foi possível criar nó");
		return NULL;
	}

	n->e = NULL;
	n->d = NULL;

	return n;
}

/**
*@Assing [exibe_arvore(no *n)]
*@Parameter [no *n] elemento cujo conteúdo util será exibido pelo método e-r-d ou inorder.
*@Return [empty] 
*/
void exibe_arvore(no *n){
	if(n != NULL){
		exibe_arvore(n->e);
		printf(" %i", n->valor);
		exibe_arvore(n->d);
	}
}

/**
*@Assing [void adicionar_no(int valor, no *arvore)]
*@Parameter [no *arvore] elemento no qual conteúdo util será adicionado.
*@Parameter [int valor] elemento util que será adicionado na árvore.
*@Return [empty] 
*/
void adicionar_no(int valor, no *arvore){
	if(arvore == NULL){
		arvore = criar_no();
		arvore->valor = valor;
	}else{
		if(arvore->valor >= valor){
			adicionar_no(valor, arvore->e);
		}else{
			adicionar_no(valor, arvore->d);
		}
	}
}
