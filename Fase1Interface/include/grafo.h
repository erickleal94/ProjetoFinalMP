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

grafo_priv_t *criar_grafo(void); //DONE
grafo_priv_t *deletar_grafo(grafo_priv_t *meu_grafo); //DONE

resposta existe_vert(const grafo_priv_t *meu_grafo, int id_externo); //DONE
resposta existe_aresta(const grafo_priv_t *meu_grafo, int id_externo1, int id_externo2); //DONE

int achar_id(const grafo_priv_t *meu_grafo, int id_externo); //DONE
Celula_priv_t *achar_celula(const grafo_priv_t *meu_grafo, int id_externo); //DONE

void inserir_vert(grafo_priv_t *meu_grafo, Celula_priv_t *celula);  //DONE
void inserir_aresta(grafo_priv_t *meu_grafo, int id_externo1, Celula_priv_t *celula2, int peso);  //DONE

void Ler_Tarefas(grafo_priv_t *meu_grafo, Celula_priv_t *celula, const char *NomeArq);

void remover_vert(grafo_priv_t *meu_grafo, int id_externo);
void remover_aresta(grafo_priv_t *meu_grafo, int id_externo1, int id_externo2);

void Imprime_Tarefas(grafo_priv_t *meu_grafo, int linha, int coluna);
void Grava_Arq(grafo_priv_t *meu_grafo, char *NomeArq);

int maior_id(const grafo_priv_t *meu_grafo);

int num_vert(const grafo_priv_t *meu_grafo);
int num_arestas(const grafo_priv_t *meu_grafo);

void menor_caminho(const grafo_priv_t *meu_grafo, int **dist);

resposta eh_conexo(const grafo_priv_t *meu_grafo);

#endif
