#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafo_priv.h"
#include "grafo.h"
#include <algorithm>

using namespace std;

//se for 1 serão escritas mensagens de erro para
//a saída padrão
#define DEBUG 0

grafo_priv_t *criar_grafo(void) {
	grafo_priv_t *meu_grafo = (grafo_priv_t *) malloc(sizeof(grafo_priv_t));
	
	Celula_priv_t *celula_mae;
	celula_mae = (Celula_priv_t *) malloc(sizeof(Celula_priv_t));
	celula_mae->id_externo = -1;
	celula_mae->executada = 1;
	celula_mae->ini_min = 0;
	celula_mae->pre_req = 0;
	celula_mae->nome[0] = '\0';
	
	meu_grafo->tabela = NULL;
	meu_grafo->vert = NULL;
	meu_grafo->origem = NULL;
	
	inserir_vert(meu_grafo, celula_mae);
	inserir_origem(meu_grafo, celula_mae);
	
	return meu_grafo;
}
grafo_priv_t *deletar_grafo(grafo_priv_t *meu_grafo) {
	lista_vert_codigo_t *iterator;
	
	for (iterator = meu_grafo->tabela; iterator != NULL; iterator = meu_grafo->tabela) {
// 		remover_vert(meu_grafo, iterator->dado.nome);
	}
	free(meu_grafo);
	
	return NULL;
}

Celula_priv_t *cria_celula(int id_externo, int executada, int duracao, int ini_min, int pre_req, int *reqs, char *nome){
	Celula_priv_t *nova_celula = (Celula_priv_t *) malloc(sizeof(Celula_priv_t));

	nova_celula->id_externo = id_externo;
	nova_celula->executada = executada;
	nova_celula->duracao = duracao;
	nova_celula->ini_min = ini_min;
	nova_celula->pre_req = pre_req;
	if(reqs!=NULL){
		nova_celula->reqs = (int*)malloc(sizeof(int)*pre_req);
		for(int i=0; i<pre_req; i++){
			nova_celula->reqs[i] = reqs[i];
		}
	}else{
		nova_celula->reqs = NULL;
	}
	strcpy(nova_celula->nome, nome);

	return nova_celula;
}

resposta existe_vert(const grafo_priv_t *meu_grafo, int id_externo) {
	lista_vert_codigo_t *iterator;
	
	for (iterator = meu_grafo->tabela; iterator != NULL; iterator = iterator->next) {
		if (iterator->dado.id_externo == id_externo)
			return TRUE;
	}
	return FALSE;
}

resposta existe_origem(const grafo_priv_t *meu_grafo, int id_externo) {
	lista_origem_t *iterator;
	
	if (existe_vert(meu_grafo, id_externo)) {
		
		for (iterator = meu_grafo->origem; iterator != NULL; iterator = iterator->next) {
			if (iterator->destino->id_externo == id_externo)
				return TRUE;
		}
	}
	return FALSE;
}

resposta existe_aresta(const grafo_priv_t *meu_grafo, int id_externo1, int id_externo2) {
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

int achar_id(const grafo_priv_t *meu_grafo, int id_externo) {
	lista_vert_codigo_t *iterator;
	
	for (iterator = meu_grafo->tabela; iterator != NULL; iterator = iterator->next) {
		if (iterator->dado.id_externo == id_externo) {
			return iterator->id;
		}
	}
	return -1;
}
Celula_priv_t *achar_celula(const grafo_priv_t *meu_grafo, int id_externo) {
	lista_vert_codigo_t *iterator;
	
	for (iterator = meu_grafo->tabela; iterator != NULL; iterator = iterator->next) {
		if (iterator->dado.id_externo == id_externo) {
			return &iterator->dado;
		}
	}
	return NULL;
}

void inserir_vert(grafo_priv_t *meu_grafo, Celula_priv_t *celula) {

	resposta tem_pre_req = TRUE;
	//verificar a existencia dos pre requisitos
	for(int i=0; i<celula->pre_req; i++){
		if(existe_vert(meu_grafo, celula->reqs[i]) == FALSE){
			tem_pre_req = FALSE;
		}
	}
	
	if (existe_vert(meu_grafo, celula->id_externo) == FALSE && tem_pre_req == TRUE
	&& (celula->nome[0] == '\0'
	|| !(celula->id_externo < 0 || celula->pre_req < 0 || celula->ini_min < 0))) {
		
		int id;
		
		celula->ini_min = (celula->ini_min == 0) ? 0 : -celula->ini_min;
		
		//inserar vertice na tabela
		{
			lista_vert_codigo_t *iterator, *prev = NULL;
			lista_vert_codigo_t *novo = (lista_vert_codigo_t *) malloc(sizeof(lista_vert_codigo_t));
			int last = -1;
			
			for (iterator = meu_grafo->tabela; iterator != NULL; iterator = iterator->next) {
				if (iterator->id - last > 1) { //buraco
					break;
				}
				last = iterator->id;
				prev = iterator;
			}
			
			novo->id = last + 1;
			id = novo->id;
			novo->dado = *celula;
			
			novo->next = iterator;
			
			if (prev == NULL) {
				meu_grafo->tabela = novo;
			} else {
				prev->next = novo;
			}
		}
		//insere vertice
		{
			lista_vert_t *iterator, *prev = NULL;
			lista_vert_t *novo = (lista_vert_t *) malloc(sizeof(lista_vert_t));
			
			for (iterator = meu_grafo->vert; iterator != NULL; iterator = iterator->next) {
				if (id < iterator->id) {
					break;
				}
				prev = iterator;
			}
			
			novo->id = id;
			novo->id_externo = celula->id_externo;
			novo->antecessores = NULL;
			novo->sucessores = NULL;
			novo->next = iterator;
			
			if (prev == NULL) {
				meu_grafo->vert = novo;
			} else {
				prev->next = novo;
			}
		}
	} else if (existe_vert(meu_grafo, celula->id_externo) == FALSE) {
#if DEBUG
		fprintf(stderr, "ERROR: Vertice ja existe, ");
		fprintf(stderr, "tentativa de inserir vert <%s> nao sucedida\n", celula->nome);
#endif
	}else if (tem_pre_req == FALSE){
#if DEBUG
		fprintf(stderr, "ERROR: Um ou mais pre-requisitos nao existem, ");
		fprintf(stderr, "tentativa de inserir vert <%s> nao sucedida\n", celula->nome);
#endif
	} else {
#if DEBUG
		fprintf(stderr, "ERROR: Dados incorretos, ");
		fprintf(stderr, "tentativa de inserir vert <%s> nao sucedida\n", celula->nome);
#endif
	}
	
}

void inserir_origem(grafo_priv_t *meu_grafo, Celula_priv_t *celula) {
	
	if (existe_vert(meu_grafo, celula->id_externo) == TRUE && existe_origem(meu_grafo, celula->id_externo) == FALSE) {
		
		int id = achar_id(meu_grafo, celula->id_externo);
		
		lista_origem_t *iterator, *prev = NULL;
		lista_origem_t *novo = (lista_origem_t *) malloc(sizeof(lista_origem_t));
		
		lista_vert_t *vert_atual;
		
		for (vert_atual = meu_grafo->vert; vert_atual != NULL; vert_atual = vert_atual->next) {
			if (vert_atual->id == id)
				break;
		}
		
		for (iterator = meu_grafo->origem; iterator != NULL; iterator = iterator->next) {
			if (id < iterator->destino->id) {
				break;
			}
			prev = iterator;
		}
		
		novo->destino = vert_atual;
		novo->next = iterator;
		
		if (prev == NULL) {
			meu_grafo->origem = novo;
		} else {
			prev->next = novo;
		}
	} else {
		if (existe_vert(meu_grafo, celula->id_externo) == TRUE) {
#if DEBUG
			fprintf(stderr, "ERROR: Origem ja existe, ");
			fprintf(stderr, "tentativa de inserir origem <%s> nao sucedida\n", celula->nome);
#endif
		} else {
#if DEBUG
			fprintf(stderr, "ERROR: Vertice nao existe, ");
			fprintf(stderr, "tentativa de inserir origem <%s> nao sucedida\n", celula->nome);
#endif
		}
	}
	
}


void inserir_aresta(grafo_priv_t *meu_grafo, int id_externo1, Celula_priv_t *celula2, int peso) {
	
	if (existe_vert(meu_grafo, id_externo1) == TRUE && existe_vert(meu_grafo, celula2->id_externo) == TRUE
		&& existe_aresta(meu_grafo, id_externo1, celula2->id_externo) == FALSE) {
		
		if (peso > 0) {
			int id1 = achar_id(meu_grafo, id_externo1);
			int id2 = achar_id(meu_grafo, celula2->id_externo);
			int ainda_nao_achou1 = 1, ainda_nao_achou2 = 1;
			
			lista_vert_t *vert1 = NULL, *vert2 = NULL, *iterator1;
			lista_aresta_t *novo1 = (lista_aresta_t *) malloc(sizeof(lista_aresta_t));
			lista_aresta_t *novo2 = (lista_aresta_t *) malloc(sizeof(lista_aresta_t));
			lista_aresta_t *iterator2, *prev = NULL;
			
			peso = -peso;
			
			for (iterator1 = meu_grafo->vert; ainda_nao_achou1 || ainda_nao_achou2; iterator1 = iterator1->next) {
				if (iterator1->id == id1) {
					vert1 = iterator1;
					ainda_nao_achou1 = 0;
				}
				if (iterator1->id == id2) {
					vert2 = iterator1;
					ainda_nao_achou2 = 0;
				}
			}
			
			
			prev = NULL;
			for (iterator2 = vert1->sucessores; iterator2 != NULL; iterator2 = iterator2->next) {
				if (id2 < iterator2->destino->id) {
					break;
				}
				prev = iterator2;
			}
			novo1->destino = vert2;
			novo1->peso = peso;
			novo1->next = iterator2;
			
			if (prev == NULL) {
				vert1->sucessores = novo1;
			} else {
				prev->next = novo1;
			}
			
			prev = NULL;
			for (iterator2 = vert2->antecessores; iterator2 != NULL; iterator2 = iterator2->next) {
				if (id1 < iterator2->destino->id) {
					break;
				}
				prev = iterator2;
			}
			
			novo2->destino = vert1;
			novo2->peso = peso;
			novo2->next = iterator2;
			
			if (prev == NULL) {
				vert2->antecessores = novo2;
			} else {
				prev->next = novo2;
			}
		} else {
#if DEBUG
			fprintf(stderr, "ERROR: Peso invalido, ");
			fprintf(stderr, "tentativa de inserir aresta <%d,%s,%lf> nao sucedida\n",
				id_externo1, celula2->nome, -peso);
#endif
		}
	} else {
		if (existe_vert(meu_grafo, id_externo1) == TRUE && existe_vert(meu_grafo, celula2->id_externo) == TRUE) {
#if DEBUG
			fprintf(stderr, "ERROR: Um dos vertices eh inexistente, ");
			fprintf(stderr, "tentativa de inserir aresta <%s,%s,%lf> nao sucedida\n",
				id_externo1, celula2->nome, -peso);
#endif
		} else {
#if DEBUG
			fprintf(stderr, "ERROR: Ja existe aresta entre esses vertices, ");
			fprintf(stderr, "tentativa de inserir aresta <%s,%s,%lf> nao sucedida\n",
				id_externo1, celula2->nome, -peso);
#endif
		}
	}
	
}

//TODO

void remover_vert(grafo_priv_t *meu_grafo, int id_externo) {
	
	if (existe_vert(meu_grafo, id_externo) == TRUE) {
		
		int id = achar_id(meu_grafo, id_externo);
		{
			lista_vert_t *prev = NULL, *retirase = NULL;
			
			//achar vertice
			{
				lista_vert_t *iterator;
				
				for (iterator = meu_grafo->vert; iterator != NULL; iterator = iterator->next) {
					if (iterator->id == id) { //buraco
						retirase = iterator;
						break;
					}
					prev = iterator;
				}
			}
			//se for origem remova-a
			if(existe_origem(meu_grafo, id_externo)) {
				remover_origem(meu_grafo, id_externo);
			}
			
			//remover arestas
			{
				lista_aresta_t *iterator;
				for (iterator = retirase->sucessores; iterator != NULL; iterator = retirase->sucessores) {
					int id_externo2 = iterator->destino->id_externo;
					remover_aresta(meu_grafo, id_externo, id_externo2);
					//remove a aresta id->id2, para isso
					//remove id2 da sucessao de id e id da antecessao de id2
				}
				
				for (iterator = retirase->antecessores; iterator != NULL; iterator = retirase->antecessores) {
					int id_externo2 = iterator->destino->id_externo;
					remover_aresta(meu_grafo, id_externo2, id_externo);
					//remove a aresta id2->id, para isso
					//remove id da sucessao de id2 e id2 da antecessao de id
				}
			}
			//remover vertices
			if (prev == NULL) {
				meu_grafo->vert = retirase->next;
			} else {
				prev->next = retirase->next;
			}
			free(retirase);
		}
		//remover tabela relativa ao vértice retirado
		{
			lista_vert_codigo_t *iterator, *prev = NULL;
			lista_vert_codigo_t *retirase = NULL;
			
			for (iterator = meu_grafo->tabela; iterator != NULL; iterator = iterator->next) {
				if (iterator->id == id) {
					retirase = iterator;
					break;
				}
				prev = iterator;
			}
			if (prev == NULL) {
				meu_grafo->tabela = retirase->next;
			} else {
				prev->next = retirase->next;
			}
			free(retirase);
		}
	}
	
}

void remover_origem(grafo_priv_t *meu_grafo, int id_externo) {
	
	if (existe_vert(meu_grafo, id_externo) == TRUE && existe_origem(meu_grafo, id_externo) == TRUE) {
		
		int id = achar_id(meu_grafo, id_externo);
		
		lista_origem_t *iterator, *prev = NULL;
		lista_origem_t *retirase = NULL;
		
		for (iterator = meu_grafo->origem; iterator != NULL; iterator = iterator->next) {
			if (iterator->destino->id == id) {
				retirase = iterator;
				break;
			}
			prev = iterator;
		}
		
		if (prev == NULL) {
			meu_grafo->origem = retirase->next;
		} else {
			prev->next = retirase->next;
		}
		free(retirase);
	}
	
}

void remover_aresta(grafo_priv_t *meu_grafo, int id_externo1, int id_externo2) {
	
	if (existe_vert(meu_grafo, id_externo1) == TRUE && existe_vert(meu_grafo, id_externo2) == TRUE
		&& existe_aresta(meu_grafo, id_externo1, id_externo2) == TRUE) {
		
		int id1 = achar_id(meu_grafo, id_externo1);
		int id2 = achar_id(meu_grafo, id_externo2);
		int ainda_nao_retirou1 = 1, ainda_nao_retirou2 = 1;
		
		lista_vert_t *iterator1;
		lista_aresta_t *prev = NULL, *iterator2, *retirase;
		
		for (iterator1 = meu_grafo->vert; ainda_nao_retirou1 || ainda_nao_retirou2; iterator1 = iterator1->next) {
			if (iterator1->id == id1) {
				for (iterator2 = iterator1->sucessores; iterator2 != NULL; iterator2 = iterator2->next) {
					if (iterator2->destino->id == id2) {
						retirase = iterator2;
						if (prev == NULL) {
							iterator1->sucessores = retirase->next;
						} else {
							prev->next = retirase->next;
						}
						free(retirase);
						break;
					}
					prev = iterator2;
				}
				ainda_nao_retirou1 = 0;
			}
			if (iterator1->id == id2) {
				for (iterator2 = iterator1->antecessores; iterator2 != NULL; iterator2 = iterator2->next) {
					if (iterator2->destino->id == id1) {
						retirase = iterator2;
						if (prev == NULL) {
							iterator1->antecessores = retirase->next;
						} else {
							prev->next = retirase->next;
						}
						free(retirase);
						break;
					}
					prev = iterator2;
				}
				ainda_nao_retirou2 = 0;
			}
		}
	}
	
}

int maior_id(const grafo_priv_t *meu_grafo) {
	lista_vert_codigo_t *iterator;
	int maior = -1;
	for (iterator = meu_grafo->tabela; iterator != NULL; iterator = iterator->next) {
		if (iterator->id > maior)
			maior = iterator->id;
	}
	
	return maior;
}

int num_vert(const grafo_priv_t *meu_grafo) {
	lista_vert_t *iterator;
	int num = 0;
	for (iterator = meu_grafo->vert; iterator != NULL; iterator = iterator->next) {
		num++;
	}
	
	return num;
}

int num_arestas(const grafo_priv_t *meu_grafo) {
	lista_vert_t *iterator1;
	lista_aresta_t *iterator2;
	int num = 0;
	for (iterator1 = meu_grafo->vert; iterator1 != NULL; iterator1 = iterator1->next) {
		for (iterator2 = iterator1->sucessores; iterator2 != NULL; iterator2 = iterator2->next) {
			num++;
		}
	}
	
	return num;
}

void menor_caminho(const grafo_priv_t *meu_grafo, int **dist) {
	
	int id_ini = achar_id(meu_grafo, -1);
	int maior = maior_id(meu_grafo);
	int n = num_vert(meu_grafo);

	const int inf = 2e8;
	
	//vertices existentes variam de 0 ate maior,
	//possivelmente com buracos, ou seja, valores sem nada
	*dist = (int *) malloc(sizeof(int) * (maior + 1));
	
	int i;
	lista_vert_t *iterator1;
	lista_aresta_t *iterator2;
	
	for (i = 0; i <= maior; i++) {
		(*dist)[i] = inf; //infinito
	}
	(*dist)[id_ini] = 0;
	
	//Bellman Ford's Algorithm
	for (i = 1; i <= n - 1; i++) {
		for (iterator1 = meu_grafo->vert; iterator1 != NULL; iterator1 = iterator1->next) {
			if ((*dist)[iterator1->id] < 2e9) {//se a distancia nao for infinito
				for (iterator2 = iterator1->sucessores; iterator2 != NULL; iterator2 = iterator2->next) {
					if ((*dist)[iterator1->id] + iterator2->peso < (*dist)[iterator2->destino->id]) {
						Celula_priv_t *celula = achar_celula(meu_grafo, iterator2->destino->id);
						(*dist)[iterator2->destino->id] = min((*dist)[iterator1->id], celula->ini_min) + iterator2->peso;
					}
				}
			}
		}
	}
}

int dfs(const grafo_priv_t *meu_grafo, lista_vert_t *atual, int *marc) {
	
	int visitados = 1;
	lista_aresta_t *iterator;
	
	marc[atual->id] = 1;
	
	for (iterator = atual->sucessores; iterator != NULL; iterator = iterator->next) {
		if (!marc[iterator->destino->id]) {
			visitados += dfs(meu_grafo, iterator->destino, marc);
		}
	}
	
	return visitados;
}

resposta eh_conexo(const grafo_priv_t *meu_grafo) {
	int n = num_vert(meu_grafo);
	int maior = maior_id(meu_grafo);
	int visitados = 0;
	
	int *marc = (int *) malloc(sizeof(int) * (maior + 1));
	int i;
	
	lista_origem_t *iterator;
	
	if (n == 0) {
		return TRUE; //se nao ha vertices, eh conexo
	}
	
	for (i = 0; i <= maior; i++) {
		marc[i] = 0;
	}
	
	for (iterator = meu_grafo->origem; iterator != NULL; iterator = iterator->next) {
		if (!marc[iterator->destino->id]) {
			visitados += dfs(meu_grafo, iterator->destino, marc);
		}
	}
	
	free(marc);
	
	if (visitados == n) {
		return TRUE;
	} else {
		return FALSE;
	}
	//nao necessario
	return FALSE;
}


#undef DEBUG
