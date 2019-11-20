#include "Pilha.c"
#include <string.h>

int main(){
	int verificacao;
	int valor;
	int tamanho_pilha;
	int verifica_empilha_desempilha;
	pilha *p;

	printf("\n========================================");
	printf("\n||Deseja iniciar pilha?               ||");
	printf("\n||1 -> Sim.                           ||");
	printf("\n||? -> Qualquer outro valor para sair.||");
	printf("\n========================================\n");
	printf("||->");
	scanf("%i",&verificacao);

	if(verificacao == 1){	
		do{
			printf("||Digite o tamanho da pilha: ");
			scanf("%i", &tamanho_pilha);

			if(tamanho_pilha > 0){
				p = cria_pilha(tamanho_pilha);
			}else{
				printf("||Tamanho da pilha invalido\n");
			}
		}while(tamanho_pilha <= 0);

		printf("\n\n");

		do{
			printf("\n===========================================");
			printf("\n||Pilha inicializada, escolha uma opcao. ||");
			printf("\n||1 -> Empilhar.                         ||");
			printf("\n||2 -> Desenpilhar.                      ||");
			printf("\n||3 -> Exibir pilha.                     ||");
			printf("\n||? -> Outro valor para sair.            ||");
			printf("\n===========================================\n");
			printf("||->");
			scanf("%i", &verifica_empilha_desempilha);

			if(verifica_empilha_desempilha == 1){
				if(pilha_cheia(p)){
					printf("||Pilha cheia, nao e possivel empilhar.\n");					
					
				}else{
					printf("||Digite o valor a ser empilhado: ");
					scanf("%i",&valor);
					to_push(valor, p);
					printf("||Valor empilhado com sucesso!\n");
					
				}
			}
				
			if(verifica_empilha_desempilha == 2){
				if(pilha_vazia(p)){
					printf("||Pilha vazia, nao e possivel desempilhar.\n");					
					
				}else{
					int pego = to_pop(p);
					printf("||O valor %i estava no topo e foi retirado.\n", pego);					
				}
			}

			if(verifica_empilha_desempilha == 3){
				printf("||Pilha:\n");
				if(pilha_vazia(p)){
					printf("||A pilha esta vazia.\n");
				}else{
					exibir_pilha(p);
				}
			}

		}while(verifica_empilha_desempilha == 1 || verifica_empilha_desempilha == 2 || verifica_empilha_desempilha == 3);
		
	}
	
	VERSION;
	return EXIT_SUCCESS;
}
