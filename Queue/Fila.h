#ifndef QUEUE
#define QUEUE
#define EXIT_SUCCESS 0
#define VERSION printf("\n\nVersao do sistema 1.0.0\n")

typedef struct queue fila;

fila* inicia_fila(int tamanho);

int fila_vazia();
int fila_cheia();
int de_queue(fila* f);

void en_queue(int valor, fila* f);
void ver_fila(fila *f);


#endif
