/*
	NOME: GUSTAVO LOPES DE BRITO
	MATRICULA: 14/0142657
	SISTEMA OPERACIONAL: LINUX
	Trabalho : TSA3 - Estrutura de Dados e Algoritmos
*/

#include <stdio.h>
#include <stdlib.h>
#include "functions.c"

int main(){
	int resposta = 0;
	char entrada[100];
	TreeMun *rootMun;
	TreeCD *rootCD;
	TreeTotal *rootTotal;
	TreeUF * rootUF;
	rootMun = NULL;
	rootCD = NULL;
	rootTotal = NULL;
	FILE *fp;
	fp = fopen("dadosArrumados.csv", "r+");
	do{
		print_menu();
		scanf("%d", &resposta);
		switch(resposta){
			case 1:
				if(rootMun == NULL && rootCD == NULL && rootTotal == NULL){
					import_data(fp, &rootMun, &rootCD, &rootTotal);
					printf("DADOS IMPORTADOS COM SUCESSO!\n");
				}
				else
					printf("DADOS JÁ FORAM IMPORTADOS!\n");
				break;
			case 2:
				if(rootMun == NULL && rootCD == NULL && rootTotal == NULL)
					printf("IMPORTE OS DADOS PRIMEIRO\n");
				else
					print_menu_relatorios(rootMun, rootCD, rootTotal,fp);
				break;
			case 3:
				rootUF = NULL;
				rootUF = createTreeUF(fp, rootUF);
				printf("\n");
				print_ufTree(rootUF,fp);
				printf("\n");
				free_ufTree(&rootUF);
				break;
			case 4:
				if(rootMun == NULL){	
					printf("IMPORTE OS DADOS PRIMEIRO\n");
				}
				else{
					printf("Qual municipio deseja buscar?\n");
					getchar();
					scanf("%[^\n]", entrada);
					searchMun(rootMun, entrada,fp);
				}
				break;
			case 5:
				free_TreeMun(&(rootMun));
				free_TreeCD(&(rootCD));
				free_TreeTotal(&(rootTotal));
				break;
			default:
				printf("Escolha opcão valida\n");
				break;	
		}
	}while(resposta != 5);

	fclose(fp);
	
	return 0;
}