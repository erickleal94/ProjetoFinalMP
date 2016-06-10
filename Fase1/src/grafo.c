#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <grafo.h>

//se for 1 serão escritas mensagens de erro para
//a saída padrão
#define DEBUG 0

struct tarefa{
	int id_externo;
	char nome[103];
	int tarefa_executada;
};

struct lista_vert;

typedef struct lista_vert_codigo {
	struct tarefa dado; /*nome do vértice, dada pelo usuário*/
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

grafo_t *criar_grafo(void) {
	grafo_t *meu_grafo = (grafo_t *) malloc(sizeof(grafo_t));
	meu_grafo->tabela = NULL;
	meu_grafo->vert = NULL;
	meu_grafo->origem = NULL;
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

resposta existe_origem(const grafo_t *meu_grafo, int id_externo) {
	lista_origem_t *iterator;
	
	if (existe_vert(meu_grafo, id_externo)) {
		
		for (iterator = meu_grafo->origem; iterator != NULL; iterator = iterator->next) {
			if (iterator->destino->id_externo == id_externo)
				return TRUE;
		}
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
/*
void inserir_vert(grafo_t *meu_grafo, const char *nome) {
	
	if (existe_vert(meu_grafo, nome) == FALSE) {
		
		int id;
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
			strcpy(novo->dado.nome, nome);
			
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
			novo->antecessores = NULL;
			novo->sucessores = NULL;
			novo->next = iterator;
			
			if (prev == NULL) {
				meu_grafo->vert = novo;
			} else {
				prev->next = novo;
			}
		}
	} else {
#if DEBUG
		fprintf(stderr, "ERROR: Vertice ja existe, ");
		fprintf(stderr, "tentativa de inserir vert <%s> nao sucedida\n", nome);
#endif
	}
	
}

void inserir_origem(grafo_t *meu_grafo, const char *nome) {
	
	if (existe_vert(meu_grafo, nome) == TRUE && existe_origem(meu_grafo, nome) == FALSE) {
		
		int id = achar_id(meu_grafo, nome);
		
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
		if (existe_vert(meu_grafo, nome) == TRUE) {
#if DEBUG
			fprintf(stderr, "ERROR: Origem ja existe, ");
			fprintf(stderr, "tentativa de inserir origem <%s> nao sucedida\n", nome);
#endif
		} else {
#if DEBUG
			fprintf(stderr, "ERROR: Vertice nao existe, ");
			fprintf(stderr, "tentativa de inserir origem <%s> nao sucedida\n", nome);
#endif
		}
	}
	
}

void inserir_aresta(grafo_t *meu_grafo, const char *nome1, const char *nome2, const double peso) {
	
	if (existe_vert(meu_grafo, nome1) == TRUE && existe_vert(meu_grafo, nome2) == TRUE
		&& existe_aresta(meu_grafo, nome1, nome2) == FALSE) {
		
		if (peso > 0.0) {
			int id1 = achar_id(meu_grafo, nome1);
			int id2 = achar_id(meu_grafo, nome2);
			int ainda_nao_achou1 = 1, ainda_nao_achou2 = 1;
			
			lista_vert_t *vert1 = NULL, *vert2 = NULL, *iterator1;
			lista_aresta_t *novo1 = (lista_aresta_t *) malloc(sizeof(lista_aresta_t));
			lista_aresta_t *novo2 = (lista_aresta_t *) malloc(sizeof(lista_aresta_t));
			lista_aresta_t *iterator2, *prev = NULL;;
			
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
			fprintf(stderr, "tentativa de inserir aresta <%s,%s,%lf> nao sucedida\n", nome1, nome2, peso);
#endif
		}
	} else {
		if (existe_vert(meu_grafo, nome1) == TRUE && existe_vert(meu_grafo, nome2) == TRUE) {
#if DEBUG
			fprintf(stderr, "ERROR: Um dos vertices eh inesxitente, ");
			fprintf(stderr, "tentativa de inserir aresta <%s,%s,%lf> nao sucedida\n", nome1, nome2, peso);
#endif
		} else {
#if DEBUG
			fprintf(stderr, "ERROR: Ja exite aresta entre esses vertices, ");
			fprintf(stderr, "tentativa de inserir aresta <%s,%s,%lf> nao sucedida\n", nome1, nome2, peso);
#endif
		}
	}
	
}

void ler_vert(grafo_t *meu_grafo, FILE *fp) {
	char s[101], c;
	while (fscanf(fp, " %[^\n,]%c", s, &c)) {
		inserir_vert(meu_grafo, s);
		if (c == '\n')
			break;
	}
}
void ler_origem(grafo_t *meu_grafo, FILE *fp) {
	char s[101], c;
	while (fscanf(fp, " %[^\n,]%c", s, &c) == 2) {
		inserir_origem(meu_grafo, s);
		if (c == '\n')
			break;
	}
}
void ler_aresta(grafo_t *meu_grafo, FILE *fp) {
	char s1[101], s2[101];
	double weight;
	while (fscanf(fp, " %[^,]%*c %[^,]%*c%lf%*[ \n]", s1, s2, &weight) == 3) {
		inserir_aresta(meu_grafo, s1, s2, weight);
	}
}

void ler_grafo(grafo_t *meu_grafo, const char *file) {
	
	FILE *fp = fopen(file, "r");
	if (fp != NULL) {
		ler_vert(meu_grafo, fp);
		ler_origem(meu_grafo, fp);
		ler_aresta(meu_grafo, fp);
	}
}

void remover_vert(grafo_t *meu_grafo, const char *nome) {
	
	if (existe_vert(meu_grafo, nome) == TRUE) {
		
		int id = achar_id(meu_grafo, nome);
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
			if(existe_origem(meu_grafo, nome)) {
				remover_origem(meu_grafo, nome);
			}
			
			//remover arestas
			{
				lista_aresta_t *iterator;
				for (iterator = retirase->sucessores; iterator != NULL; iterator = retirase->sucessores) {
					int id2 = iterator->destino->id;
					remover_aresta(meu_grafo, nome, achar_nome(meu_grafo, id2));
					//remove a aresta id->id2, para isso
					//remove id2 da sucessao de id e id da antecessao de id2
				}
				
				for (iterator = retirase->antecessores; iterator != NULL; iterator = retirase->antecessores) {
					int id2 = iterator->destino->id;
					remover_aresta(meu_grafo, achar_nome(meu_grafo, id2), nome);
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

void remover_origem(grafo_t *meu_grafo, const char *nome) {
	
	if (existe_vert(meu_grafo, nome) == TRUE && existe_origem(meu_grafo, nome) == TRUE) {
		
		int id = achar_id(meu_grafo, nome);
		
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

void remover_aresta(grafo_t *meu_grafo, const char *nome1, const char *nome2) {
	
	if (existe_vert(meu_grafo, nome1) == TRUE && existe_vert(meu_grafo, nome2) == TRUE
		&& existe_aresta(meu_grafo, nome1, nome2) == TRUE) {
		
		int id1 = achar_id(meu_grafo, nome1);
		int id2 = achar_id(meu_grafo, nome2);
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

void escrever_vert(const grafo_t *meu_grafo, FILE *fp) {
	
	lista_vert_codigo_t *iterator = meu_grafo->tabela;
	
	if (iterator != NULL) {
		
		fprintf(fp, "%s", iterator->dado.nome);
		
		for (iterator = iterator->next; iterator != NULL; iterator = iterator->next) {
			fprintf(fp, ", %s", iterator->dado.nome);
		}
		fprintf(fp, "\n");
	} else {//nenhum vertice
		fprintf(fp, "\n");
	}
}
void escrever_origem(const grafo_t *meu_grafo, FILE *fp) {
	lista_origem_t *iterator = meu_grafo->origem;
	
	if (iterator != NULL) {
		fprintf(fp, "%s", achar_nome(meu_grafo, iterator->destino->id));
		
		for (iterator = iterator->next; iterator != NULL; iterator = iterator->next) {
			fprintf(fp, ", %s", achar_nome(meu_grafo, iterator->destino->id));
		}
		fprintf(fp, "\n");
	} else {
		fprintf(fp, "\n");
	}
}
void escrever_aresta(const grafo_t *meu_grafo, FILE *fp) {
	char *s1;
	lista_vert_t *iterator1;
	lista_aresta_t *iterator2;
	
	for (iterator1 = meu_grafo->vert; iterator1 != NULL; iterator1 = iterator1->next) {
		s1 = achar_nome(meu_grafo, iterator1->id);
		for (iterator2 = iterator1->sucessores; iterator2 != NULL; iterator2 = iterator2->next) {
			fprintf(fp, "%s, %s, %lf\n", s1, achar_nome(meu_grafo, iterator2->destino->id), iterator2->peso);
		}
	}
}

void escrever_grafo(const grafo_t *meu_grafo, const char *file) {
	
	FILE *fp = fopen(file, "w");
	
	escrever_vert(meu_grafo, fp);
	escrever_origem(meu_grafo, fp);
	escrever_aresta(meu_grafo, fp);
}

int maior_id(const grafo_t *meu_grafo) {
	lista_vert_codigo_t *iterator;
	int maior = -1;
	for (iterator = meu_grafo->tabela; iterator != NULL; iterator = iterator->next) {
		if (iterator->id > maior)
			maior = iterator->id;
	}
	
	return maior;
}

int num_vert(const grafo_t *meu_grafo) {
	lista_vert_t *iterator;
	int num = 0;
	for (iterator = meu_grafo->vert; iterator != NULL; iterator = iterator->next) {
		num++;
	}
	
	return num;
}

int num_arestas(const grafo_t *meu_grafo) {
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

double menor_caminho(const grafo_t *meu_grafo, const char *inicio, const char *fim) {
	
	if (existe_vert(meu_grafo, inicio) && existe_vert(meu_grafo, fim)) {
		int id_ini = achar_id(meu_grafo, inicio);
		int id_fim = achar_id(meu_grafo, fim);
		int maior = maior_id(meu_grafo);
		int n = num_vert(meu_grafo);
		
		double dist_fim;
	
		const double inf = 2e40;
		
		//vertices existentes variam de 0 ate maior,
		//possivelmente com buracos, ou seja, valores sem nada
		double *dist = (double *) malloc(sizeof(double) * (maior + 1));
		
		int i;
		lista_vert_t *iterator1;
		lista_aresta_t *iterator2;
		
		for (i = 0; i <= maior; i++) {
			dist[i] = inf; //infinito
		}
		dist[id_ini] = 0;
		
		//Bellman Ford's Algorithm
		for (i = 1; i <= n - 1; i++) {
			for (iterator1 = meu_grafo->vert; iterator1 != NULL; iterator1 = iterator1->next) {
				if (dist[iterator1->id] < 2e9) {//se a distancia nao for infinito
					for (iterator2 = iterator1->sucessores; iterator2 != NULL; iterator2 = iterator2->next) {
						if (dist[iterator1->id] + iterator2->peso < dist[iterator2->destino->id]) {
							 dist[iterator2->destino->id] = dist[iterator1->id] + iterator2->peso;
						}
					}
				}
			}
		}
		
		dist_fim = dist[id_fim];
		
		free(dist);
		
		if (dist_fim < inf) {
			return dist_fim;
		} else {
			return -1.0;
		}
		
	} else {
#if DEBUG
		fprintf(stderr, "ERROR: Vertice inicial ou final nao existe, ");
		fprintf(stderr, "tentativa de achar caminho <%s,%s> nao sucedida\n", inicio, fim);
#endif
	}
	
	return -1.0;
}

int dfs(const grafo_t *meu_grafo, lista_vert_t *atual, int *marc) {
	
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

resposta eh_conexo(const grafo_t *meu_grafo) {
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
*/
