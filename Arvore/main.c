#include "Arvore.c"

int main(){
	setlocale(LC_ALL,"Portuguese");
	no *raiz;
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
			scanf("%i", resp_opc);

			if(resp_opc == 1){

				
				adicionar_no(int valor, no *arvore);
			}
			
	
		}while(resp_opc == 1 || resp_opc == 2 || resp_opc == 3);
	}
	
	VERSION;
	return EXIT_SUCCESS;
}
