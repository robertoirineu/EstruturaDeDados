#include "ListaDinamicaEncadeada.c"

int main(){
	no* inicio = cria_no();
	int i;
	
	for(i = 0; i<11; i++){
		adiciona_no(i, inicio);
	}

	exibe_lista(inicio);	
	remove_no(4, inicio);
	exibe_lista(inicio);
	printf("\n%i",contem_valor(5,inicio));	
	
	VERSION;
	return EXIT_SUCCESS;
}
