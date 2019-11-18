#ifndef QUEUE
#define QUEUE

typedef struct queue fila;

int fila_vazia();
int fila_cheia();
fila* inicia_fila(int tamanho);
void en_queue(int valor, fila* f);
int de_queue(fila* f);
void ver_fila(fila *f);


#endif
