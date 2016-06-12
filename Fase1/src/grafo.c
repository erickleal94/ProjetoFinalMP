#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <grafo.h>

//se for 1 serão escritas mensagens de erro para
//a saída padrão
#define DEBUG 0

struct lista_vert;

typedef struct lista_vert_codigo {
	Celula_t dado; /*nome do vértice, dada pelo usuário*/
	int id; /*representação interna do vértice, gerado pelo código*/
	struct lista_vert_codigo *next;
} lista_vert_codigo_t;

typedef struct lista_aresta {
	struct lista_vert *destino;
	double peso;
	struct lista_aresta *next;
} lista_aresta_t;

typedef struct lista_vert {
	int id; /*representação interna do vértice, gerado pelo código*/
	int id_externo;
	lista_aresta_t *antecessores;
	lista_aresta_t *sucessores;
	struct lista_vert *next;
} lista_vert_t;

typedef struct lista_origem {
	lista_vert_t *destino;
	struct lista_origem *next;
} lista_origem_t;

typedef struct grafo {
	lista_vert_codigo_t *tabela; /* tabela nome do vértice - código*/
	lista_vert_t *vert;
	lista_origem_t *origem;
} grafo_t;


extern struct Celula{
	
	int ID_tarefa, executada, duracao, ini_min, pre_req;
	char nome[200];
		
	
}

void inserir_origem(grafo_t *meu_grafo, Celula_t *celula);

grafo_t *criar_grafo(void) {
	grafo_t *meu_grafo = (grafo_t *) malloc(sizeof(grafo_t));
	Celula_t *celula = (Celula_t *) malloc(sizeof(Celula_t));
	
	celula->ID_tarefa = -1;
	celula->executada = 1;
	celula->duracao = 0;
	celula->ini_min = 0;
	celula->pre_req = 0;
	celula->nome = "";
	
	meu_grafo->tabela = NULL;
	meu_grafo->vert = NULL;
	meu_grafo->origem = NULL;
	
// 	inserir_vert(meu_grafo, celula);
// 	inserir_origem(meu_grafo, celula);
	
	return meu_grafo;
}
grafo_t *deletar_grafo(grafo_t *meu_grafo) {
	lista_vert_codigo_t *iterator;
	
	for (iterator = meu_grafo->tabela; iterator != NULL; iterator = meu_grafo->tabela) {
// 		remover_vert(meu_grafo, iterator->dado.nome);
	}
	free(meu_grafo);
	
	return NULL;
}

resposta existe_vert(const grafo_t *meu_grafo, int id_externo) {
	lista_vert_codigo_t *iterator;
	
	for (iterator = meu_grafo->tabela; iterator != NULL; iterator = iterator->next) {
		if (iterator->dado.id_externo == id_externo)
			return TRUE;
	}
	return FALSE;
}

resposta existe_aresta(const grafo_t *meu_grafo, int id_externo1, int id_externo2) {
	lista_vert_t *vert_inicial;
	lista_aresta_t *iterator;
	
	if (existe_vert(meu_grafo, id_externo1) && existe_vert(meu_grafo, id_externo2)) {
		
		for (vert_inicial = meu_grafo->vert; vert_inicial != NULL; vert_inicial = vert_inicial->next) {
			if (vert_inicial->id_externo == id_externo1) {
				for (iterator = vert_inicial->sucessores; iterator != NULL; iterator = iterator->next) {
					if (iterator->destino->id_externo == id_externo2) {
						return TRUE;
					}
				}
				return FALSE;
			}
		}
	}
	return FALSE;
}

int achar_id(const grafo_t *meu_grafo, int id_externo) {
	lista_vert_codigo_t *iterator;
	
	for (iterator = meu_grafo->tabela; iterator != NULL; iterator = iterator->next) {
		if (iterator->dado.id_externo == id_externo) {
			return iterator->id;
		}
	}
	return -1;
}
char *achar_nome(const grafo_t *meu_grafo, int id_externo) {
	lista_vert_codigo_t *iterator;
	
	for (iterator = meu_grafo->tabela; iterator != NULL; iterator = iterator->next) {
		if (iterator->dado.id_externo == id_externo) {
			return iterator->dado.nome;
		}
	}
	return NULL;
}
#undef DEBUG
