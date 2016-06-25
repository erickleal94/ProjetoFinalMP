#ifndef GRAFO_PRIV
#define GRAFO_PRIV

#include "grafo.h"

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


/***************************************************************************
 * Função: Existe origem nome?
 * Descrição
 * 	Verfica a existência de uma origem dado
 * Parâmetros
 * 	meu_grafo	- Deve ser passado um grafo inicializado
 * 	nome		- Deve ser passado uma string de até 100 
 * 			caracteres, mais o caracter zero terminal.
 * 			Se a string tiver mais que 100 caracteres,
 * 			a origem não será encontrado, uma vez que
 * 			100 é o maior número de caracteres que uma
 * 			origem pode ter.
 * 
 * Valor retornado
 * 	Retorna uma resposta, que será TRUE caso exista uma origem,
 * 	e FALSE caso não exista.
 * Assertiva de entrada
 * 	O grafo já deve ter sido inicializado por criar_grafo(),
 * 	se não for o programa pode ser interrompido.
 * 	strlen(nome) <= 100
 * Assertivas de saída
 * 	O retorno será TRUE ou FALSE
 * 	O conteúdo do grafo e da string passados não serão modificados
***************************************************************************/
resposta existe_origem(const grafo_priv_t *meu_grafo, int id_externo);


/***************************************************************************
 * Função: Inserir origem
 * Descrição
 * 	Caso nome seja um vértice e ainda não seja uma origem, insere-se uma.
 * 
 * 	Se não existir o vertice ou já exista essa origem, e caso a opção de DEBUG
 *	seja ativada, (macro DEBUG é igual à 1), será enviada uma mensagem à saída
 * 	padrão de erro. Independente de DEBUG, a origem não será adicionada.
 * 
 * 	Assim se for desejado adicionar uma origem que não se sabe se já é um vértice
 * 	ou não, use inserir_vert e depois inserir_origem, com o mesmo nome.
 * Parâmetros
 * 	meu_grafo	- Deve ser passado um grafo inicializado
 * 	nome		- Deve ser passado uma string de até 100 
 * 			caracteres, mais o caracter zero terminal.
 * 
 * Valor retornado
 * 	Retorna a grafo modificado por referência, ou seja, o grafo
 * 	passado será modificado sem a necessidade de receber um valor
 * 	de retorno.
 * Assertiva de entrada
 * 	O grafo já deve ter sido inicializado por criar_grafo(),
 * 	se não for o programa pode ser interrompido.
 * 	strlen(nome) <= 100
 * 
 * Assertivas de saída
 * 	O grafo retornado foi adicionado de uma origem, não se assegura
 * 	sua conexividade.
 * 	O conteúdo da string passada não será modificado
***************************************************************************/
void inserir_origem(grafo_priv_t *meu_grafo, Celula_priv_t *celula);


/***************************************************************************
 * Função: Remover origem
 * Descrição
 * 	Caso não existir o vértice nome ou el não for uma origem, nada será feito,
 * 	não será gerado nenhum warning.
 * 
 * 	Se existir a origem, ela será removida. O vértices permanecerá no
 *	grafo.
 * Parâmetros
 * 	meu_grafo	- Deve ser passado um grafo inicializado
 * 	nome		- Deve ser passado uma string de até 100 
 * 			caracteres, mais o caracter zero terminal.
 * 
 * Valor retornado
 * 	Retorna a grafo modificado por referência, ou seja, o grafo
 * 	passado será modificado sem a necessidade de receber um valor
 * 	de retorno.
 * Assertiva de entrada
 * 	O grafo já deve ter sido inicializado por criar_grafo(),
 * 	se não for o programa pode ser interrompido.
 * 	strlen(nome) <= 100
 * 
 * Assertivas de saída
 * 	O grafo retornado por referência foi removido de uma origem,
 *	não se assegura sua conexividade.
 * 	O conteúdo da string passada não será modificado
***************************************************************************/
void remover_origem(grafo_priv_t *meu_grafo, int id_externo);

#endif
