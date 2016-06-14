/*UNIVERSIDADE DE BRASÍLIA
* INSTITUTO DE CIÊNCIAS EXATAS
* DEPARTAMENTO DE CIÊNCIA DA COMPUTAÇÃO
* Brasília, 15 de maio de 2016
* Disciplina: MÉTODOS DE PROGRAMAÇÃO
* Aluno: Victor Fabre Figueiredo – 15/0022948
*        Erick Pizani Leal Guimaraes - 12/0116421
*        Rafael Lourenço de Lima Chehab 15/0045123*/

#include "estruturas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h> 

/*Este módulo contém as funções necessárias para a criação, uso e manipulação de uma lista duplamente encadeada*/


/*Cria uma lista duplamente encadeada vazia*/
TipoLista* criaLista(){
	TipoLista *lista = (TipoLista*)malloc(sizeof(TipoLista));
	lista->inicio =(apontador)malloc(sizeof(Celula));
	lista->final = lista->inicio;
	lista->final->prox = NULL;
	lista->final->anter = NULL;  

	return lista; 
}

/*Insere um elemento a lista, levando em consideração uma célula cabeça.*/
void insereLista(TipoLista *lista, char X[], int peso, int ID_tarefa, int executada, int ini_min, int pre_req, int reqs[]){
	
	int i;
	
	lista->final->prox = (apontador)malloc(sizeof(Celula));
	lista->final->prox->anter = lista->final;
	lista->final = lista->final->prox;
	strcpy(lista->final->nome, X);
	lista->final->duracao = peso;
	lista->final->ID_tarefa = ID_tarefa;
	lista->final->executada = executada;
	lista->final->ini_min = ini_min;
	lista->final->pre_req = pre_req;
	lista->final->reqs = (int*)malloc(sizeof(int)*pre_req);
	for (i = 0; i < pre_req; i++) {
		lista->final->reqs[i] = reqs[i];
					
	}
	lista->final->prox = NULL; 
}

/*Retira um elemento da lista a partir de um ponteiro indicando o elemento a ser retirado*/
void retiraLista(TipoLista *lista, Celula *AUX){
	if(AUX == NULL){
		printf("Ponteiro nulo.\n");
		return;
	}
	if(lista->inicio == AUX)
		lista->inicio = AUX->prox;
	else
		AUX->anter->prox = AUX->prox;
	if(AUX->prox == NULL)
		lista->final = AUX->anter;
	else
		AUX->prox->anter = AUX->anter;

	free(AUX);
}

/*Informa se a determinada lista está vazia ou não*/
int estaVazia(TipoLista *lista){ 
	return (lista->inicio == lista->final);
}

Celula* buscaLista(TipoLista* lista, char X[]){
	apontador AUX;
	for(AUX = lista->inicio->prox ; AUX != NULL ; AUX = AUX->prox){
		if(strcmp(AUX->nome, X) == 0){
			return AUX;
		}
	}

	return NULL;
}

/*Limpa a celula cabeça que restará após a execução do programa, e pode ser usada para limpar uma lista inteira*/
void limpaLista(TipoLista *lista){
	apontador AUX;
	for(AUX=lista->inicio->prox ; AUX!=NULL ; AUX=AUX->prox){
		free(AUX->anter);
	}
	free(lista->final);
	free(lista);
}
