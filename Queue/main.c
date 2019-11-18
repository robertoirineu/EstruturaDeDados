#include "Fila.c"

int main(){
	fila *q = inicia_fila(10);

	printf("%i\n",fila_cheia(q));

	int i = 0;
	int j = 1;
	if(i){
		printf("\nI == Ligado");
	}else{
		printf("\nI == Desligado");
	}

	if(j){
		printf("\nj == Ligado");
	}else{
		printf("\nJ == Desligado");
	}

	VERSION;
	return EXIT_SUCCESS;
}
