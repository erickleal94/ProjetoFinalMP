#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <grafo_priv.h>
#include <grafo.h>

//se for 1 serão escritas mensagens de erro para
//a saída padrão
#define DEBUG 1

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
char *achar_nome(const grafo_priv_t *meu_grafo, int id_externo) {
	lista_vert_codigo_t *iterator;
	
	for (iterator = meu_grafo->tabela; iterator != NULL; iterator = iterator->next) {
		if (iterator->dado.id_externo == id_externo) {
			return iterator->dado.nome;
		}
	}
	return NULL;
}

void inserir_vert(grafo_priv_t *meu_grafo, Celula_priv_t *celula) {
	
	if (existe_vert(meu_grafo, celula->id_externo) == FALSE
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
			novo->pre_req = celula->pre_req;
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


void inserir_aresta(grafo_priv_t *meu_grafo, int id_externo1, Celula_priv_t *celula2, double peso) {
	
	if (existe_vert(meu_grafo, id_externo1) == TRUE && existe_vert(meu_grafo, celula2->id_externo) == TRUE
		&& existe_aresta(meu_grafo, id_externo1, celula2->id_externo) == FALSE) {
		
		if (peso > 0.0) {
			int id1 = achar_id(meu_grafo, id_externo1);
			int id2 = achar_id(meu_grafo, celula2->id_externo);
			int ainda_nao_achou1 = 1, ainda_nao_achou2 = 1;
			
			lista_vert_t *vert1 = NULL, *vert2 = NULL, *iterator1;
			lista_aresta_t *novo1 = (lista_aresta_t *) malloc(sizeof(lista_aresta_t));
			lista_aresta_t *novo2 = (lista_aresta_t *) malloc(sizeof(lista_aresta_t));
			lista_aresta_t *iterator2, *prev = NULL;;
			
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
			fprintf(stderr, "ERROR: Um dos vertices eh inesxitente, ");
			fprintf(stderr, "tentativa de inserir aresta <%s,%s,%lf> nao sucedida\n",
				id_externo1, celula2->nome, -peso);
#endif
		} else {
#if DEBUG
			fprintf(stderr, "ERROR: Ja exite aresta entre esses vertices, ");
			fprintf(stderr, "tentativa de inserir aresta <%s,%s,%lf> nao sucedida\n",
				id_externo1, celula2->nome, -peso);
#endif
		}
	}
	
}

#undef DEBUG
