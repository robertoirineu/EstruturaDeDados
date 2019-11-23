#ifndef TREE
#define TREE
#define VERSION printf("\nVersao do sistema 1.0.0\n")
#define EXIT_SUCCESS 0

typedef struct node no;

no *criar_no();
no *remover_valor(int valor, no *tree);

void limpar_arvore(no *arvore);
void adicionar_valor(int valor, no *arvore);
void exibe_arvore(no *n);
void re_arranjo(no *old, no *target);

#endif
