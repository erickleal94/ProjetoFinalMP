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

