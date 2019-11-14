#include "ListaDinamicaEncadeada.c"

int main(){
	no* inicio = cria_no();
	int i;
	
	for(i = 0; i<5; i++){
		adiciona_no(i, inicio);
	}

	exibe_lista(inicio);
	limpa_lista(inicio);

	VERSION;
	return EXIT_SUCCESS;
}
