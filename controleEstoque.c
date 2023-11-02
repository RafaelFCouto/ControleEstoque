#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct produto {
	char id[30];
	char nome[50];
	char descricao[100];
	char codigoDeBarras [15];
	float preco;
	struct produto *proxProduto;
} prod;



prod *listaProduto = NULL;

/*
struct entradaEstoque {
	struct produto *prod;
	char dataDeEntrada[11];
	int qtdDeItens;
	
};

typedef struct entradaEstoque entradaEstoque;

entradaEstoque *entradaEstoque;
*/
struct estoque{
	struct prod *prod;
	char dataDeEntrada[11];
	int qtdDeItens;
	
};


void cadastroDeProduto (char id[], char nome[], char descricao[], char codigoDeBarras, float preco){
	
	prod *p = (prod*) malloc(sizeof(prod));
	
	strcpy(p->id, id);
	strcpy(p->nome, nome);
	strcpy(p->descricao, descricao);
	strcpy(p->codigoDeBarras, codigoDeBarras);
	p->preco = preco;
	

	p->proxProduto = listaProduto;
	listaProduto = p;
	
}

void addProdutos(){
	
	char continuarCadProd;
	
	
	//produto
	char id[30];
	char nome[30];
	char descricao[30];
	char codigoDeBarras [15];
	float preco;
	char precoStr[20];
	
	do{
		printf("INFORME O ID DO PRODUTO: "); fgets(id, sizeof(id), stdin);
		//criar uma função pra validar se o ID já está cadastrado ou não
		printf("INFORME O NOME DO PRODUTO: ");  fgets(nome, sizeof(nome), stdin);
		printf("INFORME O DESCRICAO DO PRODUTO: ");  fgets(descricao, sizeof(descricao), stdin);
		printf("INFORME O CODIGO DE BARRAS PRODUTO: ");  fgets(codigoDeBarras, sizeof(codigoDeBarras), stdin);
		
		printf("INFORME O PRECO DO PRODUTO: "); fgets(precoStr, sizeof(precoStr), stdin);
		preco = atof(precoStr);
		cadastroDeProduto(id, nome, descricao, codigoDeBarras, preco);
		printf("DESEJA CONTINUAR CADASTRANDO PRODUTO [S/N]? "); scanf("%s", &continuarCadProd);
		getchar(); //buffer do continuarCadProd
		printf("\n");
								
								
	}while(continuarCadProd == 's' || continuarCadProd == 'S');	
}

/*
void entradaNoEstoque(char id[], char dataDeEntrada[], int qtdDeItens){
	
	
}
*/

int main () {
	
	//apoio
	int escMain  = 0;
	int escMainProd = 0;
	
	//char continuarCadProd;
	
	
	/*produto
	char id[30];
	char nome[30];
	char descricao[30];
	char codigoDeBarras [15];
	float preco;
	*/
	do{
		
		printf("--- CONTROLE DE ESTOQUE ---\n\n");
		printf("1 - VERIFICAR PRODUTOS\n");
		printf("2 - CONTROLAR ESTOQUE\n");
		printf("3 - ENCERRAR\n\n");
		printf("ESCOLHA UMA DAS OPCOES: "); scanf("%d", &escMain);
		
		
		switch (escMain){
			case 1: 
			
				do{
					printf("\n");
					printf("--- MENU DE PRODUTOS ---\n\n");
					printf("1 - CADASTRAR PRODUTO\n");
					printf("2 - EDITAR PRODUTO\n");
					printf("3 - LISTAR PRODUTO\n");
					printf("4 - REMOVER PRODUTO\n");
					printf("5 - VOLTAR AO MENU INICIAL\n\n");
					printf("ESCOLHA UMA OPCAO: ");scanf("%d", &escMainProd);
					getchar(); // buffer do escMainProd
					
					switch (escMainProd){
						case 1:
							/*
							do{
								printf("INFORME O ID DO PRODUTO: "); fgets(id, sizeof(id), stdin);
								//criar uma função pra validar se o ID já está cadastrado ou não
								printf("INFORME O NOME DO PRODUTO: ");  fgets(nome, sizeof(nome), stdin);
								printf("INFORME O DESCRICAO DO PRODUTO: ");  fgets(descricao, sizeof(descricao), stdin);
								printf("INFORME O CODIGO DE BARRAS PRODUTO: ");  fgets(codigoDeBarras, sizeof(codigoDeBarras), stdin);
								//printf("INFORME O PRECO DO PRODUTO: "); scanf("%f", &preco);
								//getchar(); //buffer do preço
								cadastroDeProduto(id, nome, descricao, codigoDeBarras);
								printf("DESEJA CONTINUAR CADASTRANDO PRODUTO [S/N]? "); scanf("%s", &continuarCadProd);
								getchar(); //buffer do continuarCadProd
								printf("\n");
								
								
							}while(continuarCadProd == 's' || continuarCadProd == 'S');
							printf("VOCE SERA DIRECIONADO AO MENU DOS PRODUTOS\n");
							
						
						
								
						break;*/
						
							addProdutos();
						
						
					}
					
					
					
				}while(escMainProd != 5);
			break;		
				
		}
		
		
		
	}while(escMain != 3);
	
	
	return 0;	
}
