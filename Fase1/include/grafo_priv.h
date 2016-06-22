#ifndef GRAFO_PRIV
#define GRAFO_PRIV

typedef struct Celula_priv {
	int id_externo, executada, duracao;
	int ini_min, pre_req;
	int *reqs;
	char nome[200];

} Celula_priv_t;

struct lista_vert;

typedef struct lista_vert_codigo {
	Celula_priv_t dado;	/*nome do vértice, dada pelo usuário*/
	int id;			/*representação interna do vértice, gerado pelo código*/
	struct lista_vert_codigo *next;
} lista_vert_codigo_t;

typedef struct lista_aresta {
	struct lista_vert *destino;
	double peso;
	struct lista_aresta *next;
} lista_aresta_t;

typedef struct lista_vert {
	int id;			/*representação interna do vértice, gerado pelo código*/
	int id_externo;
	int pre_req;
	lista_aresta_t *antecessores;
	lista_aresta_t *sucessores;
	struct lista_vert *next;
} lista_vert_t;

typedef struct lista_origem {
	lista_vert_t *destino;
	struct lista_origem *next;
} lista_origem_t;

typedef struct grafo_priv {
	lista_vert_codigo_t *tabela; /* tabela nome do vértice - código*/
	lista_vert_t *vert;
	lista_origem_t *origem;
} grafo_priv_t;

enum resp;
typedef enum resp resposta;

resposta existe_origem(const grafo_priv_t *meu_grafo, int id_externo);
void inserir_origem(grafo_priv_t *meu_grafo, Celula_priv_t *celula);

#endif
