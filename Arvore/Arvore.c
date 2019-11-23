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
	no *pai;

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
	n->pai = NULL;

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
		printf("%i ", n->valor);
		exibe_arvore(n->d);
	}
}

/**
*@Assing [void adicionar_valor(int valor, no *arvore)]
*@Parameter [no *arvore] elemento no qual conteúdo util será adicionado.
*@Parameter [int valor] elemento util que será adicionado na árvore.
*@Return [empty] 
*/
void adicionar_valor(int valor, no *arvore){
	if(arvore == NULL){
		arvore = criar_no();
		arvore->valor = valor;

	}else if(arvore->pai == NULL){
		if(arvore->valor >= valor){
			no *n = criar_no();

			n->pai = arvore;
			n->valor = valor;
			arvore->e = n;
		}else{
			no *n = criar_no();

			n->pai = arvore;
			n->valor = valor;
			arvore->d = n;
		}
	}else{
		if(arvore->valor >= valor){
			if(arvore->e != NULL){
				adicionar_valor(valor, arvore->e);
			}else{
				no *n = criar_no();

				n->pai = arvore;
				n->valor = valor;
				arvore->e = n;

			}
		}else{
			if(arvore->d != NULL){
				adicionar_valor(valor, arvore->d);
			}else{
				no *n = criar_no();

				n->pai = arvore;
				n->valor = valor;
				arvore->d = n;

			}
		}
	}
}

/**
*@Assing [void limpar_arvore(no *arvore)]
*@Parameter [no *arvore] elemento que será removido.
*@Return [empty].
*/
void limpar_arvore(no *arvore){

	if(arvore != NULL){
		no *d = arvore->d;
		no *e = arvore->e;

		free(arvore);
		
		limpar_arvore(d);
		limpar_arvore(e);
	}
}

/**
*@Assing [void limpar_arvore(no *arvore)]
*@Parameter [no *arvore] elemento que será removido.
*@Return [empty].
*/
void re_arranjo(no *old, no *target){
	if(old != NULL){

		adicionar_valor(old->valor, target);

		if(old->e != NULL){
			re_arranjo(old->e, target);
		}

		if(old->d != NULL){
			re_arranjo(old->d, target);
		}
	}
}

/**
*@Assing [no *remover_valor()(int valor, no *tree)]
*@Parameter [no *arvore] elemento no qual conteúdo util será removido.
*@Parameter [int valor] elemento util que será removido da árvore.
*@Return [no *] elemento a ser retornado.
*/
no *remover_valor(int valor, no *tree){
	
	if(tree == NULL){
		return tree;
	}

	if(valor == tree->valor){
		no *aux = tree;
		
		re_arranjo(tree->e, tree->pai);	
		re_arranjo(tree->d, tree->pai);
		re_arranjo((tree->pai->e->valor != valor? tree->pai->e:tree->pai->d), tree->pai);

		limpar_arvore(aux->d);
		limpar_arvore(aux->e);
		
		return aux;
		
	}

	if(tree->valor >= valor){
		return remover_valor(valor, tree->e);
	}else{
		return remover_valor(valor, tree->d);
	}
	
}
