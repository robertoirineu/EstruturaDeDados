#ifndef STACK
#define STACK
#define VERSION printf("\nVersao do sistema 1.0.0\n")
#define EXIT_SUCCESS 0

typedef struct stack pilha;

pilha *cria_pilha(int tamanho);

int pilha_cheia(pilha *p);
int pilha_vazia(pilha *p);
int to_pop(pilha *p);
int tamanho_pilha(pilha *p);

void to_push(int valor, pilha *p);
void exibir_pilha(pilha *p);

#endif
