#include "Arvore.c"

int main(){
	setlocale(LC_ALL,"Portuguese");
	no *raiz = NULL;
	int resp_ini;
	int valor;
	int resp_opc;

	printf("\n================================");
	printf("\n||Operar com árvore(ABB)?     ||");
	printf("\n||1 -> Sim.                   ||");
	printf("\n||? -> Outro valor para sair. ||");
	printf("\n================================");
	printf("\n||->");
	scanf("%i", &resp_ini);
	printf("\n");

	if(resp_ini == 1){
		do{
		
			printf("\n================================");
			printf("\n||Escolha a operação desejada: ||");
			printf("\n||1 -> Adicionar.              ||");
			printf("\n||2 -> Remover.                ||");
			printf("\n||3 -> Visualizar              ||");
			printf("\n||? -> Outro valor para sair.  ||");
			printf("\n================================");
			printf("\n||-> ");
			scanf("%i", &resp_opc);

			if(resp_opc == 1){
				printf("||Digite o valor a ser adicionado: ");
				scanf("%i", &valor);
				raiz = adicionar_valor(valor, raiz);
				printf("||Valor %i adicionado com sucesso!!!", valor);
			}

			if(resp_opc == 2){
				if(raiz == NULL){
					printf("||Árvore está vazia. Remoção não realizada.");

				}else{
					no *n = NULL;

					printf("||Digite o valor a ser removido: ");
					scanf("%i", &valor);
					n = remover_valor(valor, raiz);					

					if(n == NULL){
						printf("||Valor não encontrado.");
					}else{
						printf("\n||Valor %i removido", n->valor);
					}
				}
				
			}

			if(resp_opc == 3){
				if(raiz == NULL){
					printf("||Árvore está vazia.");

				}else{
					exibe_arvore(raiz);
				}				
			}
	
			printf("\n\n");

		}while(resp_opc == 1 || resp_opc == 2 || resp_opc == 3);
	}
	
	VERSION;
	return EXIT_SUCCESS;
}
