#include "Fila.c"

int main(){
	fila *q = inicia_fila(10);

	printf("%i\n",fila_cheia(q));
	return EXIT_SUCCESS;
}
