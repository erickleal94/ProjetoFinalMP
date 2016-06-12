#ifndef GRAFO
#define GRAFO

typedef enum resp {
	FALSE,
	TRUE
} resposta;


struct grafo;
typedef grafo grafo_t;
struct Celula;
typedef Celula Celula_t;

grafo_t *criar_grafo(void);
grafo_t *deletar_grafo(grafo_t *meu_grafo);

resposta existe_vert(const grafo_t *meu_grafo, int id_externo);
resposta existe_aresta(const grafo_t *meu_grafo, int id_externo1, int id_externo2);

int achar_id(const grafo_t *meu_grafo, int id_externo);
char *achar_nome(const grafo_t *meu_grafo, int id_externo);

void inserir_vert(grafo_t *meu_grafo, Celula_t *celula);
void inserir_aresta(grafo_t *meu_grafo, Celula_t *celul1, Celula_t *celula2, const double peso);

void Ler_Tarefas(Celula_t *celula, const char *NomeArq);

void remover_vert(grafo_t *meu_grafo, Celula_t *celula);
void remover_aresta(grafo_t *meu_grafo, Celula_t *celula1, Celula_t *celula2);

void Imprime_Tarefas(Celula_t *celula);
void Grava_Arq(Celula_t *celula, char *NomeArq);

int maior_id(const grafo_t *meu_grafo);

int num_vert(const grafo_t *meu_grafo);
int num_arestas(const grafo_t *meu_grafo);

double menor_caminho(const grafo_t *meu_grafo, const char *inicio, const char *fim);

resposta eh_conexo(const grafo_t *meu_grafo);

#endif
