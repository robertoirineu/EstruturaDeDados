#ifndef LISTA_DINAMICA_ENCADEADA
#define LISTA_DINAMICA_ENCADEADA
#define EXIT_SUCCESS 0;
#define VERSION printf("\n\nVersao do sistema 1.0.0\n")

typedef struct lista_no no;

no *cria_no();
no *remove_no(int valor, no *lista);
no *ultimo_no(no *n);

void exibe_lista(no *lista);
void adiciona_no(int valor, no *lista);
void limpa_lista(no *lista);

int contem_valor(int valor, no *lista);

#endif
