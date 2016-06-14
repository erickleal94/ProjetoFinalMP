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


/*Este módulo contém as funções relacionadas à lógica de funcionamento do programa. Funções utilizadas para a manipulação de arestas e percorrimento do grafo*/


//cria uma nova lista de arestas com o vertice de origem e o de destino iniciais  
/*t_arestas* criaArestas(char origem[],char destino[],int peso){
	t_arestas* arestas = (t_arestas*)malloc(sizeof(t_arestas));
	if(arestas == NULL){
		printf("Erro no malloc(criaArestas)\n");
		return NULL;
	}
	arestas->adjacentes = criaLista();
	//'seta' o nome da origem
	strcpy(arestas->nome, origem);
	//adiciona a aresta em si
	insereLista(arestas->adjacentes, destino, peso);
	arestas->proxA = NULL;

	return arestas;
}
//insere uma aresta desejada
grafo_ret insereAresta(t_grafo* g, char origem[],char destino[],int peso){
	//caso g nao exista
	if(g == NULL || origem ==NULL || destino == NULL){
		return GRAFO_ERR;
	}
	//verifica de a origem e o destino são vertices
	else if(buscaLista(g->vertices, origem) == NULL){
		return GRAFO_ERR;
	}
	else if(buscaLista(g->vertices, destino) == NULL){
		return GRAFO_ERR;
	}
	//caso seja a primeira aresta
	else if(g->arestas == NULL){
		g->arestas = criaArestas(origem, destino, peso);
		return GRAFO_OK;
	}
	else if(peso < 0){   
		printf("Peso deve ser positivo e nao negativo.");
		return GRAFO_ERR;
	}
	t_arestas* AUX;
	//procura caso exista uma aresta já com o nome
	for(AUX = g->arestas ; AUX->proxA != NULL ; AUX = AUX->proxA){
		//se a origem for igual a origem desejada
		if(strcmp(AUX->nome, origem) == 0){
			insereLista(AUX->adjacentes, destino, peso);
			return GRAFO_OK;
		}
	}
	//caso não exista e criada uma nova aresta
	AUX->proxA = (t_arestas*)malloc(sizeof(t_arestas));
	if(AUX->proxA == NULL){
		printf("Erro no malloc(insereAresta)\n");
		return GRAFO_ERR;
	}
	strcpy(AUX->proxA->nome, origem);
	AUX->proxA->adjacentes = criaLista();
	insereLista(AUX->proxA->adjacentes, destino, peso);
	AUX->proxA->proxA = NULL;

	return GRAFO_OK;
}
//retira uma aresta especifidade
grafo_ret retiraAresta(t_grafo* g, char origem[],char destino[]){
	t_arestas* AUXa;
	apontador AUX;
	//procura pela aresta de origem e destino especificados e retira-os
	for(AUXa = g->arestas ; AUXa != NULL ; AUXa = AUXa->proxA){
		if(strcmp(AUXa->nome, origem) == 0){
			for(AUX =  AUXa->adjacentes->inicio->prox; AUX != NULL ; AUX = AUX->prox){
				if(strcmp(AUX->nome, destino) == 0){
					retiraLista(AUXa->adjacentes, buscaLista(AUXa->adjacentes, destino));
					return GRAFO_OK;
				}
			}
		}
	}

	return GRAFO_ERR;
}
//retira todas as arestas com o determinado vertice
grafo_ret retiraVerAresta(t_grafo* g, char vertice[]){
	if(g->arestas == NULL || vertice == NULL){
		return GRAFO_ERR;
	}
	t_arestas* AUXa;
	apontador AUX;
	for(AUXa = g->arestas ; AUXa != NULL ; AUXa = AUXa->proxA){
		if(strcmp(AUXa->nome, vertice) == 0){
			for(AUX =  AUXa->adjacentes->inicio->prox; AUX != NULL ; AUX = AUX->prox){
				retiraLista(AUXa->adjacentes, buscaLista(AUXa->adjacentes, AUX->nome));
			}
		}
		else 
			for(AUX = AUXa->adjacentes->inicio->prox; AUX != NULL ; AUX = AUX->prox){
				if(strcmp(AUX->nome, vertice) == 0){
					retiraLista(AUXa->adjacentes, buscaLista(AUXa->adjacentes, vertice));
					
				}
			}
	}
	return GRAFO_OK;
}
//retorna a o vertice(no formato t_aresta*) que possui o nome desejado
t_arestas* buscaVerAresta(t_grafo* g, char *nome){
	t_arestas* AUXa;
	for(AUXa = g->arestas ; AUXa != NULL ; AUXa = AUXa->proxA){
		if(strcmp(AUXa->nome, nome) == 0){
			return AUXa;
		}
	}

	return NULL;
}


*/
/* FUNÇÕES PARA DESCOBRIR O CAMINHO ENTRE DOIS VERTICES*/
/*
//retorna o peso da aresta do pai(origem) ate o vertice desejado
int buscaPesoPai(t_grafo* g, t_arestas* a){
	if(a->pai == NULL)
		return 0;
	else{
		apontador AUX;
		t_arestas* AUXa = a->pai;
		for(AUX = AUXa->adjacentes->inicio->prox; AUX != NULL ; AUX = AUX->prox){
			if(strcmp(a->nome, AUX->nome) == 0){
				return AUX->peso;
			}
		}
	}
}

void limpaArestas(t_grafo* g){
	t_arestas* AUX = NULL;
	t_arestas* AUXa;
	for(AUXa = g->arestas ; AUXa != NULL ; AUXa = AUXa->proxA){
		if(AUX != NULL){
			free(AUX);
		}
		limpaLista(AUXa->adjacentes);
		AUX = AUXa;
	}
	//na ultima iteracao o penultimo elemento AUX nao foi desalocado pois o looping sera terminado antes disso
	free(AUX);
}

void DFS_Visit(t_grafo* g, t_arestas* u){
	//soma os caminhos para chegar a esse vertice
	if(u->pai != NULL)
		u->caminho = u->pai->caminho + buscaPesoPai(g, u);

	u->cor = CINZA;
	apontador AUX;
	t_arestas* AUXa;
	for(AUX = u->adjacentes->inicio->prox; AUX != NULL ; AUX = AUX->prox){
		AUXa = buscaVerAresta(g, AUX->nome);
		if(AUXa->cor == BRANCO){
			AUXa->pai = u;//strcpy(AUXa->pai, u->nome);
			DFS_Visit(g, AUXa);
		}
	}

	u->cor = PRETO;
}
//Busca em profundidade, já atualizando o peso para realizar o caminho
grafo_ret DFS(t_grafo* g, char *inicial){
	t_arestas* AUXa;
	for(AUXa = g->arestas ; AUXa != NULL ; AUXa = AUXa->proxA){
		AUXa->cor = BRANCO;
		AUXa->pai = NULL;
		AUXa->caminho = 0;
	}
	//procura o vertice inicial
	AUXa = buscaVerAresta(g, inicial);
	if(AUXa == NULL){
		return GRAFO_ERR;
	}
	DFS_Visit(g, AUXa);
	//realiza a busca para outros vertices
	for(AUXa = g->arestas ; AUXa != NULL ; AUXa = AUXa->proxA){
		if(AUXa->cor == BRANCO){
			DFS_Visit(g, AUXa);
		}
	}
	return GRAFO_OK;
}

void imprimePai(t_grafo* g){
	t_arestas* AUXa;
	for(AUXa = g->arestas ; AUXa != NULL ; AUXa = AUXa->proxA){
		printf("%s -> %s\n", AUXa->nome, AUXa->pai->nome);
	}
}
// retorna o gasto do caminho de um vertice
int pegaPesoCaminho(t_grafo* g, char* nome){
	t_arestas* AUXa;
	for(AUXa = g->arestas ; AUXa != NULL ; AUXa = AUXa->proxA){
		if(strcmp(AUXa->nome, nome) == 0 && AUXa->caminho != 0){
			return AUXa->caminho;
		}
	}

	return -1;
}

int percursoEntre(t_grafo* g, char origem[],char destino[]){
	//caso g , origem e destino nao existam
	if(g == NULL || origem == NULL ||destino == NULL){
		return -1;
	}
	//verifica de a origem e o destino são vertices
	else if(buscaLista(g->vertices, origem) == NULL){
		return -1;
	}
	else if(buscaLista(g->vertices, destino) == NULL){
		return -1;
	}
	int r;
	//realiza busca por profundidade
	DFS(g, origem);
	//a partir do vertice final verifica se é possivel chegar na origem a partir dele, ou vice versa
	t_arestas* AUXa = buscaVerAresta(g, destino);
	r = AUXa->caminho;
	//verifica se existe um caminho ate a origem
	while(AUXa != NULL && strcmp(AUXa->nome, origem) != 0){
		AUXa = AUXa->pai;
	}
	if(AUXa == NULL){
		return -1;
	}

	return r;
}
*/
