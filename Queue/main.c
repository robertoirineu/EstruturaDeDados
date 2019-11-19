#include "Fila.c"
#include <string.h>

int main(){
	fila *q = inicia_fila(10);
	int i;

	for(i = 0; i < 5; i++){
		en_queue(i, q);
	} 

	ver_fila(q);

	de_queue(q);

	printf("\n");
	ver_fila(q);

	en_queue(15, q);

	printf("\n");
	ver_fila(q);

	VERSION;
	return EXIT_SUCCESS;
}
