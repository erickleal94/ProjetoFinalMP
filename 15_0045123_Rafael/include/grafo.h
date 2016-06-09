#ifndef GRAFO
#define GRAFO

typedef enum resp {
	FALSE,
	TRUE
} resposta;


struct grafo;
typedef grafo grafo_t;

/***************************************************************************
 * Função: Cria grafo
 * Descrição
 * 	Aloca a memória necessária e inicializa
 * 	um grafo
 * Parâmetros
 * 	Não ha parâmetros, a alocação e inicializam não
 * 	dependem de nenhum parâmetro do usuário
 * 
 * Valor retornado
 * 	Se retorna um ponteiro para a grafo criado
 * Assertiva de saída
 * 	O grafo gerado é consistente e não
 * 	possui nenhum vértice, origem ou aresta.
***************************************************************************/
grafo_t *criar_grafo(void);

/***************************************************************************
 * Função: Deleta grafo
 * Descrição
 * 	Desaloca toda a memória utilizada pelo grafo
 * Parâmetros
 *  	meu_grafo	- Deve ser passado um ponteiro para um grafo
 *			inicializado
 * 
 * Valor retornado
 * 	Retorna um ponteiro para o grafo, que será NULL.
 * 	O valor de retorno é muito importante, uma vez que
 * 	se ele não for utilizado o grafo do usuário apontará
 * 	para um endereço não alocado e qualquer tentativa de utilizá-lo
 * 	poderá gerar erros no sistema.
 * 	
 * 	Caso o grafo passado não tenha sido inicializado, o programa poderá
 * 	parar a execução
 * Assertiva de entrada
 * 	O grafo já deve ter sido inicializado por criar_grafo()
 * Assertiva de saída
 * 	Se retornará um ponteiro para o mesmo grafo passado, após a deleção
 * 	que será NULL.
***************************************************************************/
grafo_t *deletar_grafo(grafo_t *meu_grafo);

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
resposta existe_vert(const grafo_t *meu_grafo, int id_externo);

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
resposta existe_origem(const grafo_t *meu_grafo, int id_externo);

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
resposta existe_aresta(const grafo_t *meu_grafo, int id_externo1, int id_externo2);

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
int achar_id(const grafo_t *meu_grafo, int id_externo);

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
char *achar_nome(const grafo_t *meu_grafo, int id_externo);

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
void inserir_vert(grafo_t *meu_grafo, const char *nome);

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
void inserir_origem(grafo_t *meu_grafo, const char *nome);

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
void inserir_aresta(grafo_t *meu_grafo, const char *nome1, const char *nome2, const double peso);

/***************************************************************************
 * Função: Ler vértice
 * Descrição
 * 	Lê um conjunto de vértices de um arquivo. Os vértices devem ser dados
 * 	como definidos na especificação. Se todo o arquivo estiver no formato
 * 	para leitura, use ler_grafo
 * Parâmetros
 * 	meu_grafo	- Deve ser passado um grafo inicializado
 * 	fp		- Deve ser passado um arquivo já aberta para leitura,
 * 			o arquivo deve seguir o formato de entrada definido na
 * 			especificação
 * 
 * Valor retornado
 * 	Retorna a grafo modificado por referência, ou seja, o grafo
 * 	passado será modificado sem a necessidade de receber um valor
 * 	de retorno.
 * Assertiva de entrada
 * 	O grafo já deve ter sido inicializado por criar_grafo(),
 * 	se não for o programa pode ser interrompido.
 * 	O arquivo já foi aberto com permissão para leitura
 * 	O arquivo está no formato que pode ser lido.
 * 
 * Assertivas de saída
 * 	O grafo retornado foi adicionado de vértices, não se assegura
 * 	sua conexividade.
 * 	Só será lido do arquivo, seu conteúdo não será modificado.
***************************************************************************/
void ler_vert(grafo_t *meu_grafo, FILE *fp);

/***************************************************************************
 * Função: Ler origem
 * Descrição
 * 	Lê um conjunto de origens de um arquivo. As origens devem ser dadas
 * 	como definidos na especificação. Se todo o arquivo estiver no formato
 * 	para leitura, use ler_grafo
 * Parâmetros
 * 	meu_grafo	- Deve ser passado um grafo inicializado
 * 	fp		- Deve ser passado um arquivo já aberta para leitura,
 * 			o arquivo deve seguir o formato de entrada definido na
 * 			especificação
 * 
 * Valor retornado
 * 	Retorna a grafo modificado por referência, ou seja, o grafo
 * 	passado será modificado sem a necessidade de receber um valor
 * 	de retorno.
 * Assertiva de entrada
 * 	O grafo já deve ter sido inicializado por criar_grafo(),
 * 	se não for o programa pode ser interrompido.
 * 	O arquivo já foi aberto com permissão para leitura
 * 	O arquivo está no formato que pode ser lido.
 * 
 * Assertivas de saída
 * 	O grafo retornado foi adicionado de origens, não se assegura
 * 	sua conexividade.
 * 	Só será lido do arquivo, seu conteúdo não será modificado.
***************************************************************************/
void ler_origem(grafo_t *meu_grafo, FILE *fp);

/***************************************************************************
 * Função: Ler aresta
 * Descrição
 * 	Lê um conjunto de aretas de um arquivo. As arestas devem ser dadas
 * 	como definidos na especificação. Se todo o arquivo estiver no formato
 * 	para leitura, use ler_grafo
 * Parâmetros
 * 	meu_grafo	- Deve ser passado um grafo inicializado
 * 	fp		- Deve ser passado um arquivo já aberta para leitura,
 * 			o arquivo deve seguir o formato de entrada definido na
 * 			especificação
 * 
 * Valor retornado
 * 	Retorna a grafo modificado por referência, ou seja, o grafo
 * 	passado será modificado sem a necessidade de receber um valor
 * 	de retorno.
 * Assertiva de entrada
 * 	O grafo já deve ter sido inicializado por criar_grafo(),
 * 	se não for o programa pode ser interrompido.
 * 	O arquivo já foi aberto com permissão para leitura
 * 	O arquivo está no formato que pode ser lido.
 * 
 * Assertivas de saída
 * 	O grafo retornado foi adicionado de arestas, não se assegura
 * 	sua conexividade.
 * 	Só será lido do arquivo, seu conteúdo não será modificado.
***************************************************************************/
void ler_aresta(grafo_t *meu_grafo, FILE *fp);

/***************************************************************************
 * Função: Ler grafo
 * Descrição
 * 	Lê um grafo de um arquivo com nome file. O arquivo deve ser dado
 * 	como definido na especificação.
 * Parâmetros
 * 	meu_grafo	- Deve ser passado um grafo inicializado
 * 	file		- Deve ser passado um nome para um arquivo no qual
 * 			o grafo está passado como definido na especificação
 * 
 * Valor retornado
 * 	Retorna a grafo modificado por referência, ou seja, o grafo
 * 	passado será modificado sem a necessidade de receber um valor
 * 	de retorno.
 * Assertiva de entrada
 * 	O grafo já deve ter sido inicializado por criar_grafo(),
 * 	se não for o programa pode ser interrompido.
 * 	O arquivo de nome file existe e segue as regras definidas na especificação
 * 
 * Assertivas de saída
 * 	O grafo retornado foi adicionado de vértices, origens e arestas, não se assegura
 * 	sua conexividade.
 * 	O conteúdo do arquivo de nome file não será modificado, nem o da string passada.
***************************************************************************/
void ler_grafo(grafo_t *meu_grafo, const char *file);

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
void remover_vert(grafo_t *meu_grafo, const char *nome);

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

void remover_origem(grafo_t *meu_grafo, const char *nome);

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
void remover_aresta(grafo_t *meu_grafo, const char *nome1, const char *nome2);

/***************************************************************************
 * Função: Escrever vértice
 * Descrição
 * 	Escreve o conjunto de vértices do grafo em um arquivo. Os vértices serão dados
 * 	como definidos na especificação. Se todo o arquivo for requerido no formato,
 * 	use escrever_grafo
 * Parâmetros
 * 	meu_grafo	- Deve ser passado um grafo inicializado
 * 	fp		- Deve ser passado um arquivo já aberta para escrita,
 * 			o arquivo será escrito no formato definido na
 * 			especificação
 * 
 * Valor retornado
 * 	Modifica o arquivo.
 * Assertiva de entrada
 * 	O grafo já deve ter sido inicializado por criar_grafo(),
 * 	se não for o programa pode ser interrompido.
 * 	O arquivo já foi aberto com permissão para escrita
 * 
 * Assertivas de saída
 * 	O grafo não será modificado.
 * 	Será escrito no arquivo, seu conteúdo será modificado.
***************************************************************************/
void escrever_vert(const grafo_t *meu_grafo, FILE *fp);

/***************************************************************************
 * Função: Escrever origem
 * Descrição
 * 	Escreve o conjunto de origens do grafo em um arquivo. As origens serão dadas
 * 	como definidos na especificação. Se todo o arquivo for requerido no formato,
 * 	use escrever_grafo
 * Parâmetros
 * 	meu_grafo	- Deve ser passado um grafo inicializado
 * 	fp		- Deve ser passado um arquivo já aberta para escrita,
 * 			o arquivo será escrito no formato definido na
 * 			especificação
 * 
 * Valor retornado
 * 	Modifica o arquivo.
 * Assertiva de entrada
 * 	O grafo já deve ter sido inicializado por criar_grafo(),
 * 	se não for o programa pode ser interrompido.
 * 	O arquivo já foi aberto com permissão para escrita
 * 
 * Assertivas de saída
 * 	O grafo não será modificado.
 * 	Será escrito no arquivo, seu conteúdo será modificado.
***************************************************************************/
void escrever_origem(const grafo_t *meu_grafo, FILE *fp);

/***************************************************************************
 * Função: Escrever aresta
 * Descrição
 * 	Escreve o conjunto de arestas do grafo em um arquivo. As arestas serão dadas
 * 	como definidos na especificação. Se todo o arquivo for requerido no formato,
 * 	use escrever_grafo
 * Parâmetros
 * 	meu_grafo	- Deve ser passado um grafo inicializado
 * 	fp		- Deve ser passado um arquivo já aberta para escrita,
 * 			o arquivo será escrito no formato definido na
 * 			especificação
 * 
 * Valor retornado
 * 	Modifica o arquivo.
 * Assertiva de entrada
 * 	O grafo já deve ter sido inicializado por criar_grafo(),
 * 	se não for o programa pode ser interrompido.
 * 	O arquivo já foi aberto com permissão para escrita
 * 
 * Assertivas de saída
 * 	O grafo não será modificado.
 * 	Será escrito no arquivo, seu conteúdo será modificado.
***************************************************************************/
void escrever_aresta(const grafo_t *meu_grafo, FILE *fp);

/***************************************************************************
 * Função: Escrever grafo
 * Descrição
 * 	Escreve um grafo em um arquivo com nome file. O arquivo será dado
 * 	como definido na especificação.
 * 
 * 	Se já há conteúo escrito no arquivo file, este será apagado ao se abrir
 * 	o arquivo
 * Parâmetros
 * 	meu_grafo	- Deve ser passado um grafo inicializado
 * 	file		- Deve ser passado um nome para um arquivo no qual
 * 			o grafo será passado como definido na especificação
 * 
 * Valor retornado
 * 	O arquivo será dado o formato definido na especificação
 * Assertiva de entrada
 * 	O grafo já deve ter sido inicializado por criar_grafo(),
 * 	se não for o programa pode ser interrompido.
 * 
 * Assertivas de saída
 * 	O grafo não será modificado.
 * 	Será escrito no arquivo, seu conteúdo será modificado, esse conteúdo
 * 	pode depois ser lido com ler_grafo, e gerará um grafo identico à meu_grafo
***************************************************************************/
void escrever_grafo(const grafo_t *meu_grafo, const char *file);

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
int maior_id(const grafo_t *meu_grafo);

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
int num_vert(const grafo_t *meu_grafo);

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
int num_arestas(const grafo_t *meu_grafo);

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
double menor_caminho(const grafo_t *meu_grafo, const char *inicio, const char *fim);

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
resposta eh_conexo(const grafo_t *meu_grafo);

#endif
