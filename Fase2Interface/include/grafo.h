#ifndef GRAFO
#define GRAFO

/**
 * @file grafo.h
 * @brief Define funções usadas pelo usuario
 */

typedef enum resp { 
	FALSE_T,
	TRUE_T
} resposta;



struct grafo_priv;
typedef struct grafo_priv grafo_priv_t;
struct Celula_priv;
typedef struct Celula_priv Celula_priv_t;

/**
 * @brief Cria grafo
 * 
 * @section desc Descrição
 * 	Aloca a memória necessária e inicializa
 * 	um grafo
 * @section para Parâmetros
 * 	Não ha parâmetros, a alocação e inicializam não
 * 	dependem de nenhum parâmetro do usuário
 * 
 * @return	Se retorna um ponteiro para a grafo criado
 * 
 * @section assert Assertiva de saída
 * 	O grafo gerado é consistente e não
 * 	possui nenhum vértice, origem ou aresta.
***************************************************************************/
grafo_priv_t *criar_grafo(void);
/**
 * @brief Deleta grafo
 * 
 * @section desc Descrição
 * 	Desaloca toda a memória utilizada pelo grafo
 *
 * @param  	meu_grafo	- Deve ser passado um ponteiro para um grafo
 *			inicializado
 * 
 * @return Retorna um ponteiro para o grafo, que será NULL.
 * 	O valor de retorno é muito importante, uma vez que
 * 	se ele não for utilizado o grafo do usuário apontará
 * 	para um endereço não alocado e qualquer tentativa de utilizá-lo
 * 	poderá gerar erros no sistema.
 * 	Caso o grafo passado não tenha sido inicializado, o programa poderá
 * 	parar a execução
 * 
 * @section assert Assertiva de entrada
 * 	O grafo já deve ter sido inicializado por criar_grafo()
 * Assertiva de saída
 * 	Se retornará um ponteiro para o mesmo grafo passado, após a deleção
 * 	que será NULL.
***************************************************************************/
grafo_priv_t *deletar_grafo(grafo_priv_t *meu_grafo);

/***************************************************************************
 * Função: Existe vértice nome?
 * Descrição
 * 	Verfica a existência de um vértice dado
 * Parâmetros
 * 	meu_grafo	- Deve ser passado um ponteiro para um grafo
 *			inicializado
 * 	nome		- Deve ser passado uma string de até 100 
 * 			caracteres, mais o caracter zero terminal.
 * 			Se a string tiver mais que 100 caracteres,
 * 			o vértice não será encontrado, uma vez que
 * 			100 é o maior número de caracteres que um
 * 			vértice pode ter.
 * 
 * Valor retornado
 * 	Retorna uma resposta, que será TRUE caso exista o vértice,
 * 	e FALSE caso não exista.
 * Assertiva de entrada
 * 	O grafo já deve ter sido inicializado por criar_grafo(),
 * 	se não for o programa pode ser interrompido.
 * 	strlen(nome) <= 100
 * Assertivas de saída
 * 	O retorno será TRUE ou FALSE
 * 	O conteúdo do grafo e da string passados não serão modificados
***************************************************************************/
resposta existe_vert(const grafo_priv_t *meu_grafo, int id_externo);

/***************************************************************************
 * Função: Criar nova célula
 * Descrição
 * 	Cria uma nova célula com os os dados inseridos
 * Parâmetros
 * 	meu_grafo	- Deve ser passado um ponteiro para um grafo
 *			inicializado
 *  id_externo 	- Deve ser um inteiro que é o ID da tarefa
 *  executada 	- Deve ser um inteiro que indica se a tarefa 
 * 			ja foi ou nao executada.
 *  duracao 	- Deve ser um inteiro que representa a duraçao da tarefa
 *  ini_min 	- Deve ser um inteiro que representa o tempo 
 * 			minimo para iniciar a tarefa.
 *  pre_req 	- Deve ser um inteiro que representa a quantidade de 
 * 			pre requisitos que a tarega possui.
 *  reqs 		- Deve ser um ponteiro pra inteiro contendo todos os 
 *  		IDs dos pre requisitos da tarefa.
 * 	nome		- Deve ser passado uma string de até 100 
 * 			caracteres, mais o caracter zero terminal que será o nome da célular.
 * 
 * 
 * Valor retornado
 * 	Retorna uma célula com os dados que foram inseridos na chamada
 * Assertiva de entrada
 * 	Os numeros devem ser inteiros maiores que 0.
 *  A string de nome deve ser de ate 100 caracteres.
 * Assertivas de saída
 * 	O retorno será uma célula contendo os dados que foram passados na entrada
***************************************************************************/
Celula_priv_t *cria_celula(int id_externo, int executada, int duracao, int ini_min, int pre_req, int *reqs, const char *nome);

/***************************************************************************
 * Função: Existe aresta nome?
 * Descrição
 * 	Verfica a existência de um vértice dado
 * Parâmetros
 * 	meu_grafo	- Deve ser passado um grafo inicializado
 * 	nome1 e nome2	- Devem ser passadas duas string de até 100 
 * 			caracteres, mais o caracter zero terminal.
 * 			Se as strings tiverem mais que 100 caracteres,
 * 			a aresta não será encontrado, uma vez que
 * 			100 é o maior número de caracteres que um
 * 			os vértices da aresta podem ter.
 * 
 * Valor retornado
 * 	Retorna uma resposta, que será TRUE caso exista a aresta,
 * 	e FALSE caso não exista.
 * Assertiva de entrada
 * 	O grafo já deve ter sido inicializado por criar_grafo(),
 * 	se não for o programa pode ser interrompido.
 * 	strlen(nome1) <= 100
 * 	strlen(nome2) <= 100
 * Assertivas de saída
 * 	O retorno será TRUE ou FALSE
 * 	O conteúdo do grafo e das strings passados não serão modificados
***************************************************************************/
resposta existe_aresta(const grafo_priv_t *meu_grafo, int id_externo1, int id_externo2);

/***************************************************************************
 * Função: Achar id
 * Descrição
 * 	Todo vértice armazenado no grafo possui um nome, uma string
 * 	de até 100 caracteres mais o caracter zero terminal, e um
 * 	identificador (id), um inteiro que é como o vértice é
 * 	armazenado internamente.
 * 	Essa função acha esse identificador
 * 
 * 	O valor do id não deverá interessar ao usuário, porém,
 * 	se algum cliente desejar criar mais utilidades para a biblioteca
 * 	grafos, essa função é necessária.
 * 
 * 	Vale dizer que vértices, origens, e arestas estão ordenados
 * 	de menores id até maiores, logo se for sesejado que se mostrem os
 * 	dados em ordem alfabética, devem-se inserir os vértices em ordem
 * 	alfabética.
 * 
 * 	ids são criados do menor para o maior, sendo o menor valor possível
 * 	0.
 * 
 * 	Por motivos de segurança sempre se verifica se existe_vert nome antes
 * 	de se usar achar_id
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
 * 	Retorna um inteiro id. Caso não se ache o vértice nome, esse
 * 	inteiro será -1, caso contrário será o valor do identificador
 * 	de nome
 * Assertiva de entrada
 * 	O grafo já deve ter sido inicializado por criar_grafo(),
 * 	se não for o programa pode ser interrompido.
 * 	strlen(nome) <= 100
 * 	Já foi checado que existe_vert(meu_grafo, nome) == TRUE
 * Assertivas de saída
 * 	Se existir um vértice nome, 0 <= id <= max(int), sendo que
 * 	max(int) é o maior valor que pode ser representado num inteiro
 * 	Se não existir id = -1
 * Assertivas de saída
 * 	O retorno será TRUE ou FALSE
 * 	O conteúdo do grafo e da string passados não serão modificados
***************************************************************************/
int achar_id(const grafo_priv_t *meu_grafo, int id_externo);

/***************************************************************************
 * Função: Achar nome
 * Descrição
 * 	Encontra o nome dado pelo usuário ao vértice de identificador id
 * 
 * 	Todo vértice armazenado no grafo possui um nome, uma string
 * 	de até 100 caracteres mais o caracter zero terminal, e um
 * 	identificador (id), um inteiro que é como o vértice é
 * 	armazenado internamente.
 * Parâmetros
 * 	meu_grafo	- Deve ser passado um grafo inicializado
 * 	id		- Deve ser passado um inteiro não negativo
 * 			válido, ou seja, que represente um vértice
 * 
 * Valor retornado
 * 	Retorna um ponteiro para o começo do nome. Caso não se ache
 *	um vérice com id, retorna-se NULL.
 * Assertiva de entrada
 * 	O grafo já deve ter sido inicializado por criar_grafo(),
 * 	se não for o programa pode ser interrompido.
 * 	0 <= id
 * 	Há um vértice representado por id
 * 
 * Assertivas de saída
 * 	Se existir um vértice id, a resposta será um ponteiro != NULL,
 * 	que aponta para onde está armazenado o nome dado pelo usuário
 * 	ao vértice
 * 	Se não existir, retorna-se NULL
 * Assertivas de saída
 * 	O retorno será TRUE ou FALSE
 * 	O conteúdo do grafo e do inteiro passados não serão modificados
***************************************************************************/
Celula_priv_t *achar_celula(const grafo_priv_t *meu_grafo, int id_externo);

/***************************************************************************
 * Função: Inserir vértice
 * Descrição
 * 	Caso não existir um vértice nome, insere-se um.
 * 
 * 	Se já existir o vertice, e caso a opção de DEBUG seja ativada,
 * 	(macro DEBUG é igual à 1), será enviada uma mensagem à saída padrão
 * 	de erro. Independente de DEBUG, o vértice não será adicionado.
 * 
 * 	Para isso guarda-se uma cópia da string dada pelo
 * 	usuário
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
 * 	O grafo retornado por referência foi adicionado de um vértice,
 *	não se assegura sua conexividade.
 * 	O conteúdo da string passada não serão modificado, porém será
 * 	copiado
***************************************************************************/
void inserir_vert(grafo_priv_t *meu_grafo, Celula_priv_t *celula);

/***************************************************************************
 * Função: Inserir aresta
 * Descrição
 * 	Caso nome1 e nome2 sejam vértices, peso > 0 e ainda não haja uma aresta
 * 	ente eles, insere-se uma.
 *
 * 
 * 	Se não existir algum dos vértices ou já exista uma aresta ou se peso <= 0,
 *	e caso a opção de DEBUG seja ativada, (macro DEBUG é igual à 1), será enviada
 *	uma mensagem à saída padrão de erro. Independente de DEBUG, a aresta não será adicionada.
 * 
 * 	Assim se for desejado adicionar uma aresta que não se sabe se já exitem os vértices
 * 	ou não, use inserir_vert, para cada um e depois inserir_aresta.
 * Parâmetros
 * 	meu_grafo	- Deve ser passado um grafo inicializado
 * 	nome1 e nome2	- Devem ser passadas duas string de até 100 
 * 			caracteres, mais o caracter zero terminal.
 * 			Se as strings tiverem mais que 100 caracteres,
 * 			a aresta não será encontrado, uma vez que
 * 			100 é o maior número de caracteres que um
 * 			os vértices da aresta podem ter.
 * 	peso 		- Deve ser um número real maior que zero
 * 
 * Valor retornado
 * 	Retorna a grafo modificado por referência, ou seja, o grafo
 * 	passado será modificado sem a necessidade de receber um valor
 * 	de retorno.
 * Assertiva de entrada
 * 	O grafo já deve ter sido inicializado por criar_grafo(),
 * 	se não for o programa pode ser interrompido.
 * 	strlen(nome1) <= 100
 * 	strlen(nome2) <= 100
 * 	peso > 0
 * 
 * Assertivas de saída
 * 	O grafo retornado foi adicionado de uma aresta, não se assegura
 * 	sua conexividade.
 * 	O conteúdo das strings passadas e do número real não serão modificados
***************************************************************************/
void inserir_aresta(grafo_priv_t *meu_grafo, int id_externo1, Celula_priv_t *celula2, int peso);


/***************************************************************************
 * Função: Remover vértice
 * Descrição
 * 	Caso não existir um vértice nome, nada será feito, não será
 * 	gerado nenhum warning.
 * 
 * 	Se existir o vertice, ele será removido.
 * 	Se ele for origem, a origem será removida.
 * 	Se houverem arestas incidentes nele, saindo ou entrando, elas serão removidas,
 * 	incluindo dos outros vértices.
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
 * 	O grafo retornado por referência foi removido de um vértice,
 *	não se assegura sua conexividade.
 * 	O conteúdo da string passada não serão modificado
***************************************************************************/
void remover_vert(grafo_priv_t *meu_grafo, int id_externo);

/***************************************************************************
 * Função: Remover aresta
 * Descrição
 * 	Caso não existirem vértices nome1 e nome2 ou não existir uma aresta
 * 	de nome1 para nome2, nada será feito, não será gerado nenhum warning.
 * 
 * 	Se existir a aresta, ela será removida. Os vértices permanecerão no
 *	grafo.
 * Parâmetros
 * 	meu_grafo	- Deve ser passado um grafo inicializado
 * 	nome1 e nome2	- Devem ser passadas duas string de até 100 
 * 			caracteres, mais o caracter zero terminal.
 * 			Se as strings tiverem mais que 100 caracteres,
 * 			a aresta não será encontrado, uma vez que
 * 			100 é o maior número de caracteres que um
 * 			os vértices da aresta podem ter.
 * 
 * Valor retornado
 * 	Retorna a grafo modificado por referência, ou seja, o grafo
 * 	passado será modificado sem a necessidade de receber um valor
 * 	de retorno.
 * Assertiva de entrada
 * 	O grafo já deve ter sido inicializado por criar_grafo(),
 * 	se não for o programa pode ser interrompido.
 * 	strlen(nome1) <= 100
 * 	strlen(nome2) <= 100
 * 
 * Assertivas de saída
 * 	O grafo retornado por referência foi removido de uma aresta,
 *	não se assegura sua conexividade.
 * 	O conteúdo das string passadas não será modificado
***************************************************************************/
void remover_aresta(grafo_priv_t *meu_grafo, int id_externo1, int id_externo2);


/***************************************************************************
 * Função: Maior id
 * Descrição
 * 	Retorna o valor do maior identificador (id) usado.
 * 
 * 	Se não foi utilizado nenhum id, ou seja, se não há nenhum vértice retorna -1
 * Parâmetros
 * 	meu_grafo	- Deve ser passado um grafo inicializado
 * 
 * Valor retornado
 * 	Será retornado um inteiro.
 * Assertiva de entrada
 * 	O grafo já deve ter sido inicializado por criar_grafo(),
 * 	se não for o programa pode ser interrompido.
 * 
 * Assertivas de saída
 * 	O grafo não será modificado.
 * 	Se não há nenhum vértice (num_vert(meu_grafo) == 0), retorna -1
 * 	Caso contrário, o valor de retorno >= 0
***************************************************************************/
int maior_id(const grafo_priv_t *meu_grafo);

/***************************************************************************
 * Função: Número de vértices
 * Descrição
 * 	Retorna o número de vértices do grafo
 * Parâmetros
 * 	meu_grafo	- Deve ser passado um grafo inicializado
 * 
 * Valor retornado
 * 	Será retornado um inteiro >= 0.
 * Assertiva de entrada
 * 	O grafo já deve ter sido inicializado por criar_grafo(),
 * 	se não for o programa pode ser interrompido.
 * 
 * Assertivas de saída
 * 	O grafo não será modificado.
 * 	O valor de retorno é maior ou igual 0
***************************************************************************/
int num_vert(const grafo_priv_t *meu_grafo);

/***************************************************************************
 * Função: Número de arestas
 * Descrição
 * 	Retorna o número de arestas do grafo
 * Parâmetros
 * 	meu_grafo	- Deve ser passado um grafo inicializado
 * 
 * Valor retornado
 * 	Será retornado um inteiro >= 0.
 * Assertiva de entrada
 * 	O grafo já deve ter sido inicializado por criar_grafo(),
 * 	se não for o programa pode ser interrompido.
 * 
 * Assertivas de saída
 * 	O grafo não será modificado.
 * 	O valor de retorno é maior ou igual 0
***************************************************************************/
int num_arestas(const grafo_priv_t *meu_grafo);

/***************************************************************************
 * Função: Menor caminho
 * Descrição
 * 	Retorna o tamanho de menor caminho de inicio até fim.
 * 
 * 	Caso não haja um caminho entre os dois, ou um deles não for vértice retorna
 * 	-1.
 * Parâmetros
 * 	meu_grafo	- Deve ser passado um grafo inicializado
 * 	inicio e fim	- Devem ser passadas duas string de até 100 
 * 			caracteres, sem contar o caracter zero terminal.
 * Valor retornado
 * 	Será retornado um número real.
 * Assertiva de entrada
 * 	O grafo já deve ter sido inicializado por criar_grafo(),
 * 	se não for o programa pode ser interrompido.
 * 
 * Assertivas de saída
 * 	O grafo não será modificado.
 * 	Se não houver caminho retorna -1.
 * 	Caso contrário, o valor de retorno é maior ou igual à 0, e é o menor caminho de inicio até fim
 * 	O menor caminho de um vértice à ele mesmo é 0.
***************************************************************************/
int menor_caminho(const grafo_priv_t *meu_grafo, int **dist);

/***************************************************************************
 * Função: É conexo?
 * Descrição
 * 	Verifica se partindo da origem podem-se alcançar todos os vértices do grafo.
 * 	SE for possível retorna TRUE, caso contrário FALSE.
 * Parâmetros
 * 	meu_grafo	- Deve ser passado um grafo inicializado
 * Valor retornado
 * 	Se for possível alcançar todos os vértices partindo das origens retorna TRUE,
 * 	caso contrário FALSE.
 * 	Um grafo sem vértices é conexo.
 * Assertiva de entrada
 * 	O grafo já deve ter sido inicializado por criar_grafo(),
 * 	se não for o programa pode ser interrompido.
 * 
 * Assertivas de saída
 * 	O grafo não será modificado.
***************************************************************************/
resposta eh_conexo(const grafo_priv_t *meu_grafo);

int tempo_minimo(const grafo_priv_t *meu_grafo, int id_fim);
void ja_feito(const grafo_priv_t *meu_grafo, int d);

void Ler_Tarefas(grafo_priv_t *meu_grafo, Celula_priv_t *celula, const char *NomeArq);
void editar_celula(grafo_priv_t *meu_grafo, int ID);

void Imprime_Tarefas(const grafo_priv_t *meu_grafo, int linha, int coluna);
void Grava_Arq(grafo_priv_t *meu_grafo, char *NomeArq);

grafo_priv_t* criaGrafoArq(char *nomeArq);

#endif
