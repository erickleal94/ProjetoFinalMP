#include <stdio.h>
#include <stdlib.h>
#include <grafo.h>
#include <gtest/gtest.h>

TEST(criar_grafoTest, criacao) {
	
	grafo_t *meu_grafo = criar_grafo();
	
	EXPECT_TRUE(meu_grafo != NULL);
	EXPECT_EQ(0, num_vert(meu_grafo));
	EXPECT_EQ(0, num_arestas(meu_grafo));
	
	meu_grafo = deletar_grafo(meu_grafo);
	
}

TEST(deletar_grafoTest, delecao_grafo_vazio) {
	
	grafo_t *meu_grafo = criar_grafo();
	meu_grafo = deletar_grafo(meu_grafo);
	
	EXPECT_TRUE(meu_grafo == NULL);
	
}

TEST(existe_vertTest, vertices_nao_existentes) {
	
	grafo_t *meu_grafo = criar_grafo();
	
	EXPECT_EQ(FALSE, existe_vert(meu_grafo, 100);
	EXPECT_EQ(FALSE, existe_vert(meu_grafo, 101);
	EXPECT_EQ(FALSE, existe_vert(meu_grafo, 102);
	EXPECT_EQ(FALSE, existe_vert(meu_grafo, 200);
	EXPECT_EQ(FALSE, existe_vert(meu_grafo, 201);
	
	
	meu_grafo = deletar_grafo(meu_grafo);
	
}

TEST(existe_vertTest, vertices_existentes) {
	
	grafo_t *meu_grafo = criar_grafo();
	
	Celula_priv_t *nova1 = cria_celula(100, 0, 3, 0, NULL, (const char *) "tarefa1");
	Celula_priv_t *nova2 = cria_celula(101, 0, 2, 0, NULL, (const char *) "tarefa2");
	Celula_priv_t *nova3 = cria_celula(102, 0, 4, 0, NULL, (const char *) "tarefa3");
	Celula_priv_t *nova4 = cria_celula(200, 0, 1, 0, NULL, (const char *) "tarefa4");
	Celula_priv_t *nova5 = cria_celula(201, 0, 5, 0, NULL, (const char *) "tarefa5");

	inserir_vert(meu_grafo, nova1);
	inserir_vert(meu_grafo, nova2);
	inserir_vert(meu_grafo, nova3);
	inserir_vert(meu_grafo, nova4);
	inserir_vert(meu_grafo, nova5);
	
	EXPECT_EQ(TRUE, existe_vert(meu_grafo, 100);
	EXPECT_EQ(TRUE, existe_vert(meu_grafo, 101);
	EXPECT_EQ(TRUE, existe_vert(meu_grafo, 102);
	EXPECT_EQ(TRUE, existe_vert(meu_grafo, 200);
	EXPECT_EQ(TRUE, existe_vert(meu_grafo, 201);
	
	meu_grafo = deletar_grafo(meu_grafo);
	
}

TEST(existe_arestaTest, vertices_inexistentes) {
	
	grafo_t *meu_grafo = criar_grafo();
	
	EXPECT_EQ(FALSE, existe_aresta(meu_grafo, 100, 101);
	EXPECT_EQ(FALSE, existe_aresta(meu_grafo, 100, 102);
	EXPECT_EQ(FALSE, existe_aresta(meu_grafo, 200, 202);
	
	meu_grafo = deletar_grafo(meu_grafo);
	
}

TEST(existe_arestaTest, arestas_inexistentes) {
	
	grafo_t *meu_grafo = criar_grafo();
	
	Celula_priv_t *nova1 = cria_celula(100, 0, 3, 0, NULL, (const char *) "tarefa1");
	Celula_priv_t *nova2 = cria_celula(101, 0, 2, 0, NULL, (const char *) "tarefa2");
	Celula_priv_t *nova3 = cria_celula(102, 0, 4, 0, NULL, (const char *) "tarefa3");
	Celula_priv_t *nova4 = cria_celula(200, 0, 1, 0, NULL, (const char *) "tarefa4");
	Celula_priv_t *nova5 = cria_celula(201, 0, 5, 0, NULL, (const char *) "tarefa5");
	
	inserir_vert(meu_grafo, nova1);
	inserir_vert(meu_grafo, nova2);
	inserir_vert(meu_grafo, nova3);
	inserir_vert(meu_grafo, nova4);
	inserir_vert(meu_grafo, nova5);

	EXPECT_EQ(FALSE, existe_aresta(meu_grafo, 100, 101);
	EXPECT_EQ(FALSE, existe_aresta(meu_grafo, 100, 102);
	EXPECT_EQ(FALSE, existe_aresta(meu_grafo, 200, 202);

	meu_grafo = deletar_grafo(meu_grafo);
	
}

TEST(existe_arestaTest, arestas_existentes) {
	
	grafo_t *meu_grafo = criar_grafo();

	int reqs1[1] = {100};
	int reqs2[1] = {101};
	int reqs3[1] = {102};
	
	Celula_priv_t *nova1 = cria_celula(100, 0, 3, 0, NULL, (const char *) "tarefa1");
	Celula_priv_t *nova2 = cria_celula(101, 0, 2, 0, NULL, (const char *) "tarefa2");
	Celula_priv_t *nova3 = cria_celula(102, 0, 4, 1, (const int *) reqs1, (const char *) "tarefa3");
	Celula_priv_t *nova4 = cria_celula(200, 0, 1, 1, (const int *) reqs2, (const char *) "tarefa4");
	Celula_priv_t *nova5 = cria_celula(201, 0, 5, 1, (const int *) reqs3, (const char *) "tarefa5");

	inserir_vert(meu_grafo, nova1);
	inserir_vert(meu_grafo, nova2);

	inserir_aresta(meu_grafo, 100, nova3, 1.0);
	inserir_aresta(meu_grafo, 101, nova4, 2.0);
	inserir_aresta(meu_grafo, 102, nova5, 5);
	
	EXPECT_EQ(TRUE, existe_aresta(meu_grafo, 100, 102);
	EXPECT_EQ(TRUE, existe_aresta(meu_grafo, 101, 200);
	EXPECT_EQ(TRUE, existe_aresta(meu_grafo, 102, 201);
	EXPECT_EQ(FALSE, existe_aresta(meu_grafo, 100, 200);
	
	meu_grafo = deletar_grafo(meu_grafo);
	
}

TEST(existe_arestaTest, peso_invalido) {
	
	grafo_t *meu_grafo = criar_grafo();
	
	int reqs1[1] = {100};
	int reqs2[1] = {101};
	int reqs3[1] = {102};
	
	Celula_priv_t *nova1 = cria_celula(100, 0, 3, 0, NULL, (const char *) "tarefa1");
	Celula_priv_t *nova2 = cria_celula(101, 0, 2, 0, NULL, (const char *) "tarefa2");
	Celula_priv_t *nova3 = cria_celula(102, 0, 4, 1, (const int *) reqs1, (const char *) "tarefa3");
	Celula_priv_t *nova4 = cria_celula(200, 0, 1, 1, (const int *) reqs2, (const char *) "tarefa4");
	Celula_priv_t *nova5 = cria_celula(201, 0, 5, 1, (const int *) reqs3, (const char *) "tarefa5");

	inserir_vert(meu_grafo, nova1);
	inserir_vert(meu_grafo, nova2);

	inserir_aresta(meu_grafo, 100, nova3, 0.0);
	inserir_aresta(meu_grafo, 101, nova4, -2.0);
	inserir_aresta(meu_grafo, 102, nova5, -5);
	
	EXPECT_EQ(FALSE, existe_aresta(meu_grafo, 100, 102);
	EXPECT_EQ(FALSE, existe_aresta(meu_grafo, 101, 200);
	EXPECT_EQ(FALSE, existe_aresta(meu_grafo, 102, 201);
	
	meu_grafo = deletar_grafo(meu_grafo);
	
}

TEST(inserir_vertTest, insercao) {
	
	grafo_t *meu_grafo = criar_grafo();
	
	Celula_priv_t *nova1 = cria_celula(100, 0, 3, 0, NULL, (const char *) "tarefa1");
	Celula_priv_t *nova2 = cria_celula(101, 0, 2, 0, NULL, (const char *) "tarefa2");
	Celula_priv_t *nova3 = cria_celula(102, 0, 4, 0, NULL, (const char *) "tarefa3");
	Celula_priv_t *nova4 = cria_celula(200, 0, 1, 0, NULL, (const char *) "tarefa4");
	Celula_priv_t *nova5 = cria_celula(201, 0, 5, 0, NULL, (const char *) "tarefa5");

	inserir_vert(meu_grafo, nova1);
	inserir_vert(meu_grafo, nova2);
	inserir_vert(meu_grafo, nova3);
	inserir_vert(meu_grafo, nova4);
	inserir_vert(meu_grafo, nova5);
	
	EXPECT_EQ(TRUE, existe_vert(meu_grafo, 100);
	EXPECT_EQ(TRUE, existe_vert(meu_grafo, 101);
	EXPECT_EQ(TRUE, existe_vert(meu_grafo, 102);
	EXPECT_EQ(TRUE, existe_vert(meu_grafo, 200);
	EXPECT_EQ(TRUE, existe_vert(meu_grafo, 201);
	
	EXPECT_EQ(FALSE, existe_vert(meu_grafo, 203);
	EXPECT_EQ(FALSE, existe_vert(meu_grafo, 104);
	
	meu_grafo = deletar_grafo(meu_grafo);
	
}

TEST(inserir_arestaTest, vertice_inexistente) {
	
	grafo_t *meu_grafo = criar_grafo();
	
	int reqs1[1] = {100};
	int reqs2[1] = {101};
	int reqs3[1] = {102};
	
	Celula_priv_t *nova3 = cria_celula(102, 0, 4, 1, (const int *) reqs1, (const char *) "tarefa3");
	Celula_priv_t *nova4 = cria_celula(200, 0, 1, 1, (const int *) reqs2, (const char *) "tarefa4");
	Celula_priv_t *nova5 = cria_celula(201, 0, 5, 1, (const int *) reqs3, (const char *) "tarefa5");

	inserir_aresta(meu_grafo, 100, nova3, 1.0);
	inserir_aresta(meu_grafo, 101, nova4, 2.0);
	inserir_aresta(meu_grafo, 102, nova5, 5);
	
	EXPECT_EQ(FALSE, existe_aresta(meu_grafo, 100, 102);
	EXPECT_EQ(FALSE, existe_aresta(meu_grafo, 101, 200);
	EXPECT_EQ(FALSE, existe_aresta(meu_grafo, 102, 201);
	
	meu_grafo = deletar_grafo(meu_grafo);
	
}
TEST(inserir_arestaTest, vertice_existente) {
	
	grafo_t *meu_grafo = criar_grafo();
	
	int reqs1[1] = {100};
	int reqs2[1] = {101};
	int reqs3[1] = {102};
	
	Celula_priv_t *nova1 = cria_celula(100, 0, 3, 0, NULL, (const char *) "tarefa1");
	Celula_priv_t *nova2 = cria_celula(101, 0, 2, 0, NULL, (const char *) "tarefa2");
	Celula_priv_t *nova3 = cria_celula(102, 0, 4, 1, (const int *) reqs1, (const char *) "tarefa3");
	Celula_priv_t *nova4 = cria_celula(200, 0, 1, 1, (const int *) reqs2, (const char *) "tarefa4");
	Celula_priv_t *nova5 = cria_celula(201, 0, 5, 1, (const int *) reqs3, (const char *) "tarefa5");

	inserir_vert(meu_grafo, nova1);
	inserir_vert(meu_grafo, nova2);

	inserir_aresta(meu_grafo, 100, nova3, 1.0);
	inserir_aresta(meu_grafo, 101, nova4, 2.0);
	inserir_aresta(meu_grafo, 102, nova5, 5);
	
	EXPECT_EQ(TRUE, existe_aresta(meu_grafo, 100, 102);
	EXPECT_EQ(TRUE, existe_aresta(meu_grafo, 101, 200);
	EXPECT_EQ(TRUE, existe_aresta(meu_grafo, 102, 201);
	EXPECT_EQ(FALSE, existe_aresta(meu_grafo, 100, 200);
	
	meu_grafo = deletar_grafo(meu_grafo);
	
}

TEST(ler_escrever_grafoTest, grafo_do_exemplo) {
	
	const char *s1 = "input";
	const char *s2 = "output";
	grafo_t *meu_grafo = criar_grafo();
	
	ler_grafo(meu_grafo, s1);
	escrever_grafo(meu_grafo, s2);
	
	meu_grafo = deletar_grafo(meu_grafo);
	
}

TEST(ler_escrever_grafoTest, outras_aplicacoes) {
	
	const char *s1 = "input";
	const char *s2 = "extra_output";
	const char *s3 = "extra_info_input";
	const char *s4 = "extra_info_input2";
	grafo_t *meu_grafo = criar_grafo();
	
	ler_grafo(meu_grafo, s1);
	ler_grafo(meu_grafo, s3);
	ler_grafo(meu_grafo, s4);
	escrever_grafo(meu_grafo, s2);
	
	meu_grafo = deletar_grafo(meu_grafo);
	
}

TEST(remover_verticeTest, vertice_existente) {
	
	grafo_t *meu_grafo = criar_grafo();
	
	Celula_priv_t *nova1 = cria_celula(100, 0, 3, 0, NULL, (const char *) "tarefa1");
	Celula_priv_t *nova2 = cria_celula(101, 0, 2, 0, NULL, (const char *) "tarefa2");
	Celula_priv_t *nova3 = cria_celula(102, 0, 4, 0, NULL, (const char *) "tarefa3");
	
	inserir_vert(meu_grafo, nova1);
	inserir_vert(meu_grafo, nova2);
	inserir_vert(meu_grafo, nova3);
	
	EXPECT_EQ(TRUE, existe_vert(meu_grafo, 100));
	EXPECT_EQ(TRUE, existe_vert(meu_grafo, 101));
	EXPECT_EQ(TRUE, existe_vert(meu_grafo, 102));
	
	remover_vert(meu_grafo, 100);
	remover_vert(meu_grafo, 101);
	remover_vert(meu_grafo, 102);
	
	EXPECT_EQ(FALSE, existe_vert(meu_grafo, 100));
	EXPECT_EQ(FALSE, existe_vert(meu_grafo, 101));
	EXPECT_EQ(FALSE, existe_vert(meu_grafo, 102));
	
	meu_grafo = deletar_grafo(meu_grafo);
}

TEST(remover_verticeTest, vertice_inexistente) {
	
	grafo_t *meu_grafo = criar_grafo();
	
	EXPECT_EQ(FALSE, existe_vert(meu_grafo, 100));
	EXPECT_EQ(FALSE, existe_vert(meu_grafo, 101));
	
	remover_vert(meu_grafo, 100);
	remover_vert(meu_grafo, 101);
	
	EXPECT_EQ(FALSE, existe_vert(meu_grafo,100));
	EXPECT_EQ(FALSE, existe_vert(meu_grafo, 101));
	
	meu_grafo = deletar_grafo(meu_grafo);
}

TEST(remover_verticeTest, vertice_existente_com_origem_e_arestas) {
	
	grafo_t *meu_grafo = criar_grafo();
	
	int reqs1[1] = {100};
	int reqs2[1] = {101};
	int reqs3[1] = {102};
	
	Celula_priv_t *nova1 = cria_celula(100, 0, 3, 0, NULL, (const char *) "tarefa1");
	Celula_priv_t *nova2 = cria_celula(101, 0, 2, 0, NULL, (const char *) "tarefa2");
	Celula_priv_t *nova3 = cria_celula(102, 0, 4, 1, (const int *) reqs1, (const char *) "tarefa3");
	Celula_priv_t *nova4 = cria_celula(200, 0, 1, 1, (const int *) reqs2, (const char *) "tarefa4");
	Celula_priv_t *nova5 = cria_celula(201, 0, 5, 1, (const int *) reqs3, (const char *) "tarefa5");

	inserir_vert(meu_grafo, nova1);
	inserir_vert(meu_grafo, nova2);

	inserir_aresta(meu_grafo, 100, nova3, 1.0);
	inserir_aresta(meu_grafo, 101, nova4, 2.0);
	inserir_aresta(meu_grafo, 102, nova5, 5);
	
	EXPECT_EQ(TRUE, existe_aresta(meu_grafo, 100, 102);
	EXPECT_EQ(TRUE, existe_aresta(meu_grafo, 101, 200);
	EXPECT_EQ(TRUE, existe_aresta(meu_grafo, 102, 201);
	EXPECT_EQ(FALSE, existe_aresta(meu_grafo, 100, 200);

	remover_vert(meu_grafo, 100);
	remover_vert(meu_grafo, 102);

	EXPECT_EQ(FALSE, existe_vert(meu_grafo, 100));
	EXPECT_EQ(FALSE, existe_vert(meu_grafo, 102));

	EXPECT_EQ(FALSE, existe_aresta(meu_grafo, 100, 102);
	EXPECT_EQ(TRUE, existe_aresta(meu_grafo, 101, 200);
	EXPECT_EQ(FALSE, existe_aresta(meu_grafo, 102, 201);
	
	meu_grafo = deletar_grafo(meu_grafo);
}

TEST(remover_arestaTest, vertice_inexistente) {
	
	grafo_t *meu_grafo = criar_grafo();
	
	remover_aresta(meu_grafo, 100, 101);
	remover_aresta(meu_grafo, 101, 102);
	remover_aresta(meu_grafo, 101, 200);
	
	EXPECT_EQ(FALSE, existe_vert(meu_grafo, 100);
	EXPECT_EQ(FALSE, existe_vert(meu_grafo, 101);
	EXPECT_EQ(FALSE, existe_vert(meu_grafo, 102);
	EXPECT_EQ(FALSE, existe_vert(meu_grafo, 200);
	
	EXPECT_EQ(FALSE, existe_aresta(meu_grafo, 100, 101);
	EXPECT_EQ(FALSE, existe_aresta(meu_grafo, 101, 102;
	EXPECT_EQ(FALSE, existe_aresta(meu_grafo, 102, 200);
	
	meu_grafo = deletar_grafo(meu_grafo);
}

TEST(remover_arestaTest, aresta_existente) {
	
	grafo_t *meu_grafo = criar_grafo();

	int reqs1[1] = {100};
	int reqs2[1] = {101};
	int reqs3[1] = {102};
	
	Celula_priv_t *nova1 = cria_celula(100, 0, 3, 0, NULL, (const char *) "tarefa1");
	Celula_priv_t *nova2 = cria_celula(101, 0, 2, 0, NULL, (const char *) "tarefa2");
	Celula_priv_t *nova3 = cria_celula(102, 0, 4, 1, (const int *) reqs1, (const char *) "tarefa3");
	Celula_priv_t *nova4 = cria_celula(200, 0, 1, 1, (const int *) reqs2, (const char *) "tarefa4");
	Celula_priv_t *nova5 = cria_celula(201, 0, 5, 1, (const int *) reqs3, (const char *) "tarefa5");

	inserir_vert(meu_grafo, nova1);
	inserir_vert(meu_grafo, nova2);

	inserir_aresta(meu_grafo, 100, nova3, 1.0);
	inserir_aresta(meu_grafo, 101, nova4, 2.0);
	inserir_aresta(meu_grafo, 102, nova5, 5);

	remover_aresta(meu_grafo, 100, 102);
	remover_aresta(meu_grafo, 101, 200);
	remover_aresta(meu_grafo, 102, 201);

	EXPECT_EQ(TRUE, existe_vert(meu_grafo, 100);
	EXPECT_EQ(TRUE, existe_vert(meu_grafo, 101);
	EXPECT_EQ(TRUE, existe_vert(meu_grafo, 102);
	EXPECT_EQ(TRUE, existe_vert(meu_grafo, 200);
	EXPECT_EQ(TRUE, existe_vert(meu_grafo, 201);

	EXPECT_EQ(FALSE, existe_aresta(meu_grafo, 100, 102);
	EXPECT_EQ(FALSE, existe_aresta(meu_grafo, 101, 200);
	EXPECT_EQ(FALSE, existe_aresta(meu_grafo, 102, 201);
	
	meu_grafo = deletar_grafo(meu_grafo);
}
/*
TEST(menor_caminhoTest, caminho_existente) {
	
	const char *s1 = "input";
	grafo_t *meu_grafo = criar_grafo();
	
	

	ler_grafo(meu_grafo, s1);
	
	EXPECT_EQ(7.0, menor_caminho(meu_grafo, (const char *) "A", (const char *) "C"));
	EXPECT_EQ(3.0, menor_caminho(meu_grafo, (const char *) "A", (const char *) "B"));
	EXPECT_EQ(4.0, menor_caminho(meu_grafo, (const char *) "B", (const char *) "C"));
	EXPECT_EQ(0.0, menor_caminho(meu_grafo, (const char *) "A", (const char *) "A"));
	EXPECT_EQ(0.0, menor_caminho(meu_grafo, (const char *) "B", (const char *) "B"));
	EXPECT_EQ(0.0, menor_caminho(meu_grafo, (const char *) "C", (const char *) "C"));
	
	meu_grafo = deletar_grafo(meu_grafo);
}

TEST(menor_caminhoTest, caminho_inexistente) {
	
	const char *s1 = "input";
	grafo_t *meu_grafo = criar_grafo();
	
	
	
	ler_grafo(meu_grafo, s1);
	
	EXPECT_EQ(-1.0, menor_caminho(meu_grafo, (const char *) "C", (const char *) "A"));
	EXPECT_EQ(-1.0, menor_caminho(meu_grafo, (const char *) "A", (const char *) "bla"));
	EXPECT_EQ(-1.0, menor_caminho(meu_grafo, (const char *) "D", (const char *) "E"));
	
	meu_grafo = deletar_grafo(meu_grafo);
}

TEST(eh_conexoTest, conexo) {
	
	const char *s1 = "input";
	grafo_t *meu_grafo = criar_grafo();
	
	EXPECT_EQ(TRUE, eh_conexo(meu_grafo));
	
	ler_grafo(meu_grafo, s1);
	
	EXPECT_EQ(TRUE, eh_conexo(meu_grafo));
	
	inserir_vert(meu_grafo, (const char *) "D");
	inserir_origem(meu_grafo, (const char *) "D");
	
	EXPECT_EQ(TRUE, eh_conexo(meu_grafo));
	
	meu_grafo = deletar_grafo(meu_grafo);
}

TEST(eh_conexoTest, nao_conexo) {
	
	const char *s1 = "input";
	grafo_t *meu_grafo = criar_grafo();
	
	ler_grafo(meu_grafo, s1);
	inserir_vert(meu_grafo, (const char *) "D");
	
	EXPECT_EQ(FALSE, eh_conexo(meu_grafo));
	
	meu_grafo = deletar_grafo(meu_grafo);
}
*/
int main (int argc, char **argv) {
	
	grafo_t *meu_grafo = criar_grafo();
	
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
	
}
