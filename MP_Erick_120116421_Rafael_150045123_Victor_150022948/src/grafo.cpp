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

/*Esta módulo contém as funções relacionadas à criação do grafo, leitura de arquivo, escrita em arquivo, inserção e remoção de vérticese de origens.*/


t_grafo* criaGrafo(){
	t_grafo* graph = (t_grafo*)malloc(sizeof(t_grafo));
	graph->vertices = criaLista();
	graph->origens = criaLista();
	graph->arestas = NULL;
	return graph;
}

t_grafo* criaGrafoArq(char *nomeArq){
	t_grafo* g = criaGrafo();
	int i , j;
	FILE *fp, *fp2;
	fp = fopen(nomeArq, "r");
	char string[1000];
	char nome[200], dest[100], *ps;
	int ID_tarefa, executada, duracao, ini_min, pre_req, *reqs;



	fp2 = fopen("saida.txt", "w");
	
	
	//leitura dos vertices
	j = 1;
	while(fscanf(fp, "%d '%[^']' %d %d %d %d", &ID_tarefa, nome, &executada, &duracao, &ini_min, &pre_req)>0){
		
		reqs = (int*)malloc(sizeof(int)*pre_req);
		for (i = 0; i < pre_req; i++) {
			fscanf(fp, "%d", &reqs[i]);
					
		}
		fprintf(fp2, "%d %s %d %d %d %d", ID_tarefa, nome, executada, duracao, ini_min, pre_req);
		for (i = 0; i < pre_req; i++) {
			fprintf(fp2, " %d", reqs[i]);
					
		}
		fprintf(fp2, "\n");
		insereVertice(g, nome, ID_tarefa, executada, duracao, ini_min, pre_req, reqs);
		fgetc(fp);
		
		move(j, 1);
		printw("%d %s %d %d %d %d", ID_tarefa, nome, executada, duracao, ini_min, pre_req);
		for (i = 0; i < pre_req; i++) {
			printw(" %d", reqs[i]);
					
		}
		refresh();                                      
		
		
		j++;
	}
	getch();
	
	/*
	//Leitura das origens
	fscanf(fp, "%[^\n]s", string);
	j=0;
	for(i = 0; i < strlen(string); i++){
		if(string[i] != ',' && string[i] != ' '){
			nome[j] = string[i];
			j++;
		}
		else if(string[i] == ','){
			//j++;
			nome[j] = '\0';
			j=0;
			insereOrigem(g, nome);
		}	
	}
	insereOrigem(g, nome);
	fgetc(fp);
	j=0;
	//leitura das arestas
	while(fscanf(fp, "%[^\n]s", string) > 0){
		ps = strtok(string, " ,");
		strcpy(nome, ps);
		ps = strtok(NULL, " ,");
		strcpy(dest, ps);
		ps = strtok(NULL, " ,");

		insereAresta(g, nome, dest, atoi(ps));
		fgetc(fp);
	}*/

	fclose(fp);
	fclose(fp2);
	return g;
}

grafo_ret insereVertice(t_grafo* g, char vertice[], int ID_tarefa, int executada, int duracao, int ini_min, int pre_req, int reqs[]){
	if(g == NULL || vertice == NULL){
		return GRAFO_ERR;
	}
	//verifica de o vertice já existe
	else if(buscaLista(g->vertices, vertice) != NULL){
		return GRAFO_ERR;
	}
	insereLista(g->vertices, vertice, duracao, ID_tarefa, executada, ini_min, pre_req, reqs);
	return GRAFO_OK;
}

/*grafo_ret insereOrigem(t_grafo* g, char origem[]){
	if(g == NULL || origem == NULL){
		return GRAFO_ERR;
	}
	//verifica se existe um vertice que sera origem
	if(buscaLista(g->vertices, origem) == NULL){
		return GRAFO_ERR;
	}
	else
		//se existir insere-o como origem
		insereLista(g->origens, origem, 0);
		return GRAFO_OK;
}

grafo_ret retiraVertice(t_grafo* g, char vertice[]){
	if(g == NULL || vertice == NULL){
		return GRAFO_ERR;
	}
	//verifica se o elemento existe
	else if(buscaLista(g->vertices, vertice) == NULL){
		return GRAFO_ERR;
	}
	//ao remover um vertice deve removelo caso ele seja uma origem
	retiraOrigem(g, vertice);
	//retira o elemento requisitado da lista de vertices
	retiraLista(g->vertices, buscaLista(g->vertices, vertice));
	//retira as arestas que possuem o vertice removido
	retiraVerAresta(g, vertice);

	return GRAFO_OK;
}

grafo_ret retiraOrigem(t_grafo* g, char origem[]){
	if(g == NULL || origem == NULL){
		return GRAFO_ERR;
	}
	//verifica se o elemento existe
	else if(buscaLista(g->origens, origem) == NULL){
		return GRAFO_ERR;
	}
	//retira o elemento requisitado da lista de origens
	retiraLista(g->origens, buscaLista(g->origens, origem));

	return GRAFO_OK;
}

//desaloca o grafo
grafo_ret limpaGrafo(t_grafo* g){
	if(g == NULL){
		return GRAFO_ERR;
	}
	limpaLista(g->vertices);
	limpaLista(g->origens);
	limpaArestas(g);
	free(g);

	return GRAFO_OK;
}

void imprimeGrafo(t_grafo* g){
	apontador AUX;
	printf("Vertices: ");
	for(AUX = g->vertices->inicio->prox ; AUX != NULL ; AUX = AUX->prox){
		printf("%s, ", AUX->nome);
	}
	printf("\n");
	printf("Origens: ");
	for(AUX = g->origens->inicio->prox ; AUX != NULL ; AUX = AUX->prox){
		printf("%s, ", AUX->nome);
	}
	printf("\n");
	printf("Arestas: \n");
	t_arestas* AUXa;
	for(AUXa = g->arestas ; AUXa != NULL ; AUXa = AUXa->proxA){
		for(AUX =  AUXa->adjacentes->inicio->prox; AUX != NULL ; AUX = AUX->prox){
			printf("%s, ", AUXa->nome);
			printf("%s, ", AUX->nome);
			printf("%d\n", AUX->peso);
		}
	}
}

void imprimeGrafoArq(t_grafo* g, char *nomeArq){
	FILE *fp;
	fp = fopen(nomeArq, "w");

	apontador AUX;
	//Vertices
	for(AUX = g->vertices->inicio->prox ; AUX != NULL ; AUX = AUX->prox){
		fprintf(fp, "%s", AUX->nome);
		if(AUX->prox != NULL){
			fprintf(fp, ", ");
		}
	}
	fprintf(fp, "\n");
	//Origens
	for(AUX = g->origens->inicio->prox ; AUX != NULL ; AUX = AUX->prox){
		fprintf(fp, "%s", AUX->nome);
		if(AUX->prox != NULL){
			fprintf(fp, ", ");
		}
	}
	fprintf(fp, "\n");
	//Arestas
	t_arestas* AUXa;
	for(AUXa = g->arestas ; AUXa != NULL ; AUXa = AUXa->proxA){
		for(AUX =  AUXa->adjacentes->inicio->prox; AUX != NULL ; AUX = AUX->prox){
			fprintf(fp, "%s, ", AUXa->nome);
			fprintf(fp, "%s, ", AUX->nome);
			fprintf(fp, "%d\n", AUX->peso);
		}
	}

	fclose(fp);
}*/
