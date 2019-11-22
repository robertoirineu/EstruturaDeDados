#ifndef TREE
#define TREE
#define VERSION printf("\nVersao do sistema 1.0.0\n")
#define EXIT_SUCCESS 0

typedef struct node no;

no *criar_no();
no *remover_no();

void limpar_arvore(no *arvore);
void adicionar_no(int valor, no *arvore);
void exibe_arvore(no *n);

#endif
