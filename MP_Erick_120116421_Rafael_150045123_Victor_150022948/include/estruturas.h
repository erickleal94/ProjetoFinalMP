/*UNIVERSIDADE DE BRASÍLIA
* INSTITUTO DE CIÊNCIAS EXATAS
* DEPARTAMENTO DE CIÊNCIA DA COMPUTAÇÃO
* Brasília, 15 de maio de 2016
* Disciplina: MÉTODOS DE PROGRAMAÇÃO
* Aluno: Victor Fabre Figueiredo – 15/0022948
*        Erick Pizani Leal Guimaraes - 12/0116421
*        Rafael Lourenço de Lima Chehab 15/0045123*/

#ifndef GRAFO
#define GRAFO


typedef struct Celula_P Celula;

typedef struct Celula_P* apontador;

typedef struct TipoLista_P TipoLista;

typedef struct Grafo_P t_grafo;

typedef struct Arestas_P t_arestas;

typedef enum{
	GRAFO_OK,
	GRAFO_ERR
} grafo_ret;
	
typedef enum{
	BRANCO,
	PRETO,
	CINZA
} visitado;


/*ESTRUTURAS PARA A UTILIZAÇÃO DE UMA LISTA DUPLAMENTE ENCADEADA*/	
struct TipoLista_P{
	apontador inicio, final;
};
	
struct Celula_P{
	apontador anter;
	int ID_tarefa, executada, duracao, ini_min, pre_req;
	char nome[200];
	int *reqs;
	apontador prox;
};

/*ESTRUTURAS DO GRAFO E DAS ARESTAS*/

struct Grafo_P{
	TipoLista* vertices;
	TipoLista* origens;
	t_arestas* arestas;
};

struct Arestas_P{
	char nome[100];
	TipoLista* adjacentes;
	t_arestas* proxA;
	t_arestas *pai;
	int cor; 
	int caminho;
};


TipoLista* criaLista();

void insereLista(TipoLista *lista, char X[], int peso, int ID_tarefa, int executada, int ini_min, int pre_req, int reqs[]);

void retiraLista(TipoLista *lista, Celula *AUX);

int estaVazia(TipoLista *lista);

Celula* buscaLista(TipoLista* lista, char X[]);

void limpaLista(TipoLista *lista);

	
	
t_grafo* criaGrafo();

t_grafo* criaGrafoArq(char *nomeArq);

grafo_ret limpaGrafo(t_grafo* g);

grafo_ret insereVertice(t_grafo* g, char vertice[], int ID_tarefa, int executada, int duracao, int ini_min, int pre_req, int reqs[]);

grafo_ret retiraVertice(t_grafo* g, char vertice[]);

grafo_ret insereOrigem(t_grafo* g, char origem[]);

grafo_ret retiraOrigem(t_grafo* g, char origem[]);

void imprimeGrafo(t_grafo* g);

void imprimeGrafoArq(t_grafo* g, char *nomeArq);



t_arestas* criaArestas(char origem[],char destino[],int peso);

grafo_ret insereAresta(t_grafo* g, char origem[],char destino[],int peso);

grafo_ret retiraAresta(t_grafo* g, char origem[],char destino[]);

grafo_ret retiraVerAresta(t_grafo* g, char vertice[]);

void limpaArestas(t_grafo* g);

grafo_ret DFS(t_grafo* g, char *inicial);

void imprimePai(t_grafo* g);

int pegaPesoCaminho(t_grafo* g, char* nome);

int percursoEntre(t_grafo* g, char origem[],char destino[]);

#endif
