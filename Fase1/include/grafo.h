#ifndef GRAFO
#define GRAFO

typedef enum resp {
	FALSE,
	TRUE
} resposta;


struct grafo_priv;
typedef struct grafo_priv grafo_priv_t;
struct Celula_priv;
typedef struct Celula_priv Celula_priv_t;

grafo_priv_t *criar_grafo(void);
grafo_priv_t *deletar_grafo(grafo_priv_t *meu_grafo);

resposta existe_vert(const grafo_priv_t *meu_grafo, int id_externo);
resposta existe_aresta(const grafo_priv_t *meu_grafo, int id_externo1, int id_externo2);

int achar_id(const grafo_priv_t *meu_grafo, int id_externo);
char *achar_nome(const grafo_priv_t *meu_grafo, int id_externo);

void inserir_vert(grafo_priv_t *meu_grafo, Celula_priv_t *celula);
void inserir_aresta(grafo_priv_t *meu_grafo, int id_externo1, Celula_priv_t *celula2, double peso);

void Ler_Tarefas(Celula_priv_t *celula, const char *NomeArq);

void remover_vert(grafo_priv_t *meu_grafo, Celula_priv_t *celula);
void remover_aresta(grafo_priv_t *meu_grafo, Celula_priv_t *celula1, Celula_priv_t *celula2);

void Imprime_Tarefas(Celula_priv_t *celula);
void Grava_Arq(Celula_priv_t *celula, char *NomeArq);

int maior_id(const grafo_priv_t *meu_grafo);

int num_vert(const grafo_priv_t *meu_grafo);
int num_arestas(const grafo_priv_t *meu_grafo);

double menor_caminho(const grafo_priv_t *meu_grafo, const char *inicio, const char *fim);

resposta eh_conexo(const grafo_priv_t *meu_grafo);

#endif
