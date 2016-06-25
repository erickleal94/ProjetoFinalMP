#include <stdio.h>
#include <stdlib.h>
#include <grafo.h>
#include <gtest/gtest.h>

TEST(criar_grafoTest, criacao) {
	
	grafo_priv_t *meu_grafo = criar_grafo();
	
	EXPECT_TRUE(meu_grafo != NULL);
	EXPECT_EQ(0, num_vert(meu_grafo));
	EXPECT_EQ(0, num_arestas(meu_grafo));
	
	meu_grafo = deletar_grafo(meu_grafo);
	
}

TEST(deletar_grafoTest, delecao_grafo_vazio) {
	
	grafo_priv_t *meu_grafo = criar_grafo();
	meu_grafo = deletar_grafo(meu_grafo);
	
	EXPECT_TRUE(meu_grafo == NULL);
	
}

TEST(existe_vertTest, vertices_nao_existentes) {
	
	grafo_priv_t *meu_grafo = criar_grafo();
	
	EXPECT_EQ(FALSE_T, existe_vert(meu_grafo, 100));
	EXPECT_EQ(FALSE_T, existe_vert(meu_grafo, 101));
	EXPECT_EQ(FALSE_T, existe_vert(meu_grafo, 102));
	EXPECT_EQ(FALSE_T, existe_vert(meu_grafo, 200));
	EXPECT_EQ(FALSE_T, existe_vert(meu_grafo, 201));
	
	
	meu_grafo = deletar_grafo(meu_grafo);
	
}

TEST(existe_vertTest, vertices_existentes) {
	
	grafo_priv_t *meu_grafo = criar_grafo();
	
	Celula_priv_t *nova1 = cria_celula(100, 0, 3, 0, 0, NULL, (const char *) "tarefa1");
	Celula_priv_t *nova2 = cria_celula(101, 0, 2, 0, 0, NULL, (const char *) "tarefa2");
	Celula_priv_t *nova3 = cria_celula(102, 0, 4, 0, 0, NULL, (const char *) "tarefa3");
	Celula_priv_t *nova4 = cria_celula(200, 0, 1, 0, 0, NULL, (const char *) "tarefa4");
	Celula_priv_t *nova5 = cria_celula(201, 0, 5, 0, 0, NULL, (const char *) "tarefa5");

	inserir_vert(meu_grafo, nova1);
	inserir_vert(meu_grafo, nova2);
	inserir_vert(meu_grafo, nova3);
	inserir_vert(meu_grafo, nova4);
	inserir_vert(meu_grafo, nova5);
	
	EXPECT_EQ(TRUE_T, existe_vert(meu_grafo, 100));
	EXPECT_EQ(TRUE_T, existe_vert(meu_grafo, 101));
	EXPECT_EQ(TRUE_T, existe_vert(meu_grafo, 102));
	EXPECT_EQ(TRUE_T, existe_vert(meu_grafo, 200));
	EXPECT_EQ(TRUE_T, existe_vert(meu_grafo, 201));
	
	meu_grafo = deletar_grafo(meu_grafo);
	
}

TEST(existe_arestaTest, vertices_inexistentes) {
	
	grafo_priv_t *meu_grafo = criar_grafo();
	
	EXPECT_EQ(FALSE_T, existe_aresta(meu_grafo, 100, 101));
	EXPECT_EQ(FALSE_T, existe_aresta(meu_grafo, 100, 102));
	EXPECT_EQ(FALSE_T, existe_aresta(meu_grafo, 200, 202));
	
	meu_grafo = deletar_grafo(meu_grafo);
	
}

TEST(existe_arestaTest, arestas_inexistentes) {
	
	grafo_priv_t *meu_grafo = criar_grafo();
	
	Celula_priv_t *nova1 = cria_celula(100, 0, 3, 0, 0, NULL, (const char *) "tarefa1");
	Celula_priv_t *nova2 = cria_celula(101, 0, 2, 0, 0, NULL, (const char *) "tarefa2");
	Celula_priv_t *nova3 = cria_celula(102, 0, 4, 0, 0, NULL, (const char *) "tarefa3");
	Celula_priv_t *nova4 = cria_celula(200, 0, 1, 0, 0, NULL, (const char *) "tarefa4");
	Celula_priv_t *nova5 = cria_celula(201, 0, 5, 0, 0, NULL, (const char *) "tarefa5");
	
	inserir_vert(meu_grafo, nova1);
	inserir_vert(meu_grafo, nova2);
	inserir_vert(meu_grafo, nova3);
	inserir_vert(meu_grafo, nova4);
	inserir_vert(meu_grafo, nova5);

	EXPECT_EQ(FALSE_T, existe_aresta(meu_grafo, 100, 101));
	EXPECT_EQ(FALSE_T, existe_aresta(meu_grafo, 100, 102));
	EXPECT_EQ(FALSE_T, existe_aresta(meu_grafo, 200, 202));

	meu_grafo = deletar_grafo(meu_grafo);
	
}

TEST(existe_arestaTest, arestas_existentes) {
	
	grafo_priv_t *meu_grafo = criar_grafo();

	int reqs1[1] = {100};
	int reqs2[1] = {101};
	int reqs3[1] = {102};
	
	Celula_priv_t *nova1 = cria_celula(100, 0, 3, 0, 0, NULL, (const char *) "tarefa1");
	Celula_priv_t *nova2 = cria_celula(101, 0, 2, 0, 0, NULL, (const char *) "tarefa2");
	Celula_priv_t *nova3 = cria_celula(102, 0, 4, 0, 1, reqs1, (const char *) "tarefa3");
	Celula_priv_t *nova4 = cria_celula(200, 0, 1, 0, 1, reqs2, (const char *) "tarefa4");
	Celula_priv_t *nova5 = cria_celula(201, 0, 5, 0, 1, reqs3, (const char *) "tarefa5");

	inserir_vert(meu_grafo, nova1);
	inserir_vert(meu_grafo, nova2);

	inserir_aresta(meu_grafo, 100, nova3, 1.0);
	inserir_aresta(meu_grafo, 101, nova4, 2.0);
	inserir_aresta(meu_grafo, 102, nova5, 5);
	
	EXPECT_EQ(TRUE_T, existe_aresta(meu_grafo, 100, 102));
	EXPECT_EQ(TRUE_T, existe_aresta(meu_grafo, 101, 200));
	EXPECT_EQ(TRUE_T, existe_aresta(meu_grafo, 102, 201));
	EXPECT_EQ(FALSE_T, existe_aresta(meu_grafo, 100, 200));
	
	meu_grafo = deletar_grafo(meu_grafo);
	
}

TEST(existe_arestaTest, peso_invalido) {
	
	grafo_priv_t *meu_grafo = criar_grafo();
	
	int reqs1[1] = {100};
	int reqs2[1] = {101};
	int reqs3[1] = {102};
	
	Celula_priv_t *nova1 = cria_celula(100, 0, 3, 0, 0, NULL, (const char *) "tarefa1");
	Celula_priv_t *nova2 = cria_celula(101, 0, 2, 0, 0, NULL, (const char *) "tarefa2");
	Celula_priv_t *nova3 = cria_celula(102, 0, 4, 0, 1, reqs1, (const char *) "tarefa3");
	Celula_priv_t *nova4 = cria_celula(200, 0, 1, 0, 1, reqs2, (const char *) "tarefa4");
	Celula_priv_t *nova5 = cria_celula(201, 0, 5, 0, 1, reqs3, (const char *) "tarefa5");

	inserir_vert(meu_grafo, nova1);
	inserir_vert(meu_grafo, nova2);

	inserir_aresta(meu_grafo, 100, nova3, 0.0);
	inserir_aresta(meu_grafo, 101, nova4, -2.0);
	inserir_aresta(meu_grafo, 102, nova5, -5);
	
	EXPECT_EQ(FALSE_T, existe_aresta(meu_grafo, 100, 102));
	EXPECT_EQ(FALSE_T, existe_aresta(meu_grafo, 101, 200));
	EXPECT_EQ(FALSE_T, existe_aresta(meu_grafo, 102, 201));
	
	meu_grafo = deletar_grafo(meu_grafo);
	
}

TEST(inserir_vertTest, insercao) {
	
	grafo_priv_t *meu_grafo = criar_grafo();
	
	Celula_priv_t *nova1 = cria_celula(100, 0, 3, 0, 0, NULL, (const char *) "tarefa1");
	Celula_priv_t *nova2 = cria_celula(101, 0, 2, 0, 0, NULL, (const char *) "tarefa2");
	Celula_priv_t *nova3 = cria_celula(102, 0, 4, 0, 0, NULL, (const char *) "tarefa3");
	Celula_priv_t *nova4 = cria_celula(200, 0, 1, 0, 0, NULL, (const char *) "tarefa4");
	Celula_priv_t *nova5 = cria_celula(201, 0, 5, 0, 0, NULL, (const char *) "tarefa5");

	inserir_vert(meu_grafo, nova1);
	inserir_vert(meu_grafo, nova2);
	inserir_vert(meu_grafo, nova3);
	inserir_vert(meu_grafo, nova4);
	inserir_vert(meu_grafo, nova5);
	
	EXPECT_EQ(TRUE_T, existe_vert(meu_grafo, 100));
	EXPECT_EQ(TRUE_T, existe_vert(meu_grafo, 101));
	EXPECT_EQ(TRUE_T, existe_vert(meu_grafo, 102));
	EXPECT_EQ(TRUE_T, existe_vert(meu_grafo, 200));
	EXPECT_EQ(TRUE_T, existe_vert(meu_grafo, 201));
	
	EXPECT_EQ(FALSE_T, existe_vert(meu_grafo, 203));
	EXPECT_EQ(FALSE_T, existe_vert(meu_grafo, 104));
	
	meu_grafo = deletar_grafo(meu_grafo);
	
}

TEST(inserir_arestaTest, vertice_inexistente) {
	
	grafo_priv_t *meu_grafo = criar_grafo();
	
	int reqs1[1] = {100};
	int reqs2[1] = {101};
	int reqs3[1] = {102};
	
	Celula_priv_t *nova3 = cria_celula(102, 0, 4, 0, 1, reqs1, (const char *) "tarefa3");
	Celula_priv_t *nova4 = cria_celula(200, 0, 1, 0, 1, reqs2, (const char *) "tarefa4");
	Celula_priv_t *nova5 = cria_celula(201, 0, 5, 0, 1, reqs3, (const char *) "tarefa5");

	inserir_aresta(meu_grafo, 100, nova3, 1.0);
	inserir_aresta(meu_grafo, 101, nova4, 2.0);
	inserir_aresta(meu_grafo, 102, nova5, 5);
	
	EXPECT_EQ(FALSE_T, existe_aresta(meu_grafo, 100, 102));
	EXPECT_EQ(FALSE_T, existe_aresta(meu_grafo, 101, 200));
	EXPECT_EQ(FALSE_T, existe_aresta(meu_grafo, 102, 201));
	
	meu_grafo = deletar_grafo(meu_grafo);
	
}
TEST(inserir_arestaTest, vertice_existente) {
	
	grafo_priv_t *meu_grafo = criar_grafo();
	
	int reqs1[1] = {100};
	int reqs2[1] = {101};
	int reqs3[1] = {102};
	
	Celula_priv_t *nova1 = cria_celula(100, 0, 3, 0, 0, NULL, (const char *) "tarefa1");
	Celula_priv_t *nova2 = cria_celula(101, 0, 2, 0, 0, NULL, (const char *) "tarefa2");
	Celula_priv_t *nova3 = cria_celula(102, 0, 4, 0, 1, reqs1, (const char *) "tarefa3");
	Celula_priv_t *nova4 = cria_celula(200, 0, 1, 0, 1, reqs2, (const char *) "tarefa4");
	Celula_priv_t *nova5 = cria_celula(201, 0, 5, 0, 1, reqs3, (const char *) "tarefa5");

	inserir_vert(meu_grafo, nova1);
	inserir_vert(meu_grafo, nova2);

	inserir_aresta(meu_grafo, 100, nova3, 1.0);
	inserir_aresta(meu_grafo, 101, nova4, 2.0);
	inserir_aresta(meu_grafo, 102, nova5, 5);
	
	EXPECT_EQ(TRUE_T, existe_aresta(meu_grafo, 100, 102));
	EXPECT_EQ(TRUE_T, existe_aresta(meu_grafo, 101, 200));
	EXPECT_EQ(TRUE_T, existe_aresta(meu_grafo, 102, 201));
	EXPECT_EQ(FALSE_T, existe_aresta(meu_grafo, 100, 200));
	
	meu_grafo = deletar_grafo(meu_grafo);
	
}

TEST(remover_verticeTest, vertice_existente) {
	
	grafo_priv_t *meu_grafo = criar_grafo();
	
	Celula_priv_t *nova1 = cria_celula(100, 0, 3, 0, 0, NULL, (const char *) "tarefa1");
	Celula_priv_t *nova2 = cria_celula(101, 0, 2, 0, 0, NULL, (const char *) "tarefa2");
	Celula_priv_t *nova3 = cria_celula(102, 0, 4, 0, 0, NULL, (const char *) "tarefa3");
	
	inserir_vert(meu_grafo, nova1);
	inserir_vert(meu_grafo, nova2);
	inserir_vert(meu_grafo, nova3);
	
	EXPECT_EQ(TRUE_T, existe_vert(meu_grafo, 100));
	EXPECT_EQ(TRUE_T, existe_vert(meu_grafo, 101));
	EXPECT_EQ(TRUE_T, existe_vert(meu_grafo, 102));
	
	remover_vert(meu_grafo, 100);
	remover_vert(meu_grafo, 101);
	remover_vert(meu_grafo, 102);
	
	EXPECT_EQ(FALSE_T, existe_vert(meu_grafo, 100));
	EXPECT_EQ(FALSE_T, existe_vert(meu_grafo, 101));
	EXPECT_EQ(FALSE_T, existe_vert(meu_grafo, 102));
	
	meu_grafo = deletar_grafo(meu_grafo);
}

TEST(remover_verticeTest, vertice_inexistente) {
	
	grafo_priv_t *meu_grafo = criar_grafo();
	
	EXPECT_EQ(FALSE_T, existe_vert(meu_grafo, 100));
	EXPECT_EQ(FALSE_T, existe_vert(meu_grafo, 101));
	
	remover_vert(meu_grafo, 100);
	remover_vert(meu_grafo, 101);
	
	EXPECT_EQ(FALSE_T, existe_vert(meu_grafo,100));
	EXPECT_EQ(FALSE_T, existe_vert(meu_grafo, 101));
	
	meu_grafo = deletar_grafo(meu_grafo);
}

TEST(remover_verticeTest, vertice_existente_com_origem_e_arestas) {
	
	grafo_priv_t *meu_grafo = criar_grafo();
	
	int reqs1[1] = {100};
	int reqs2[1] = {101};
	int reqs3[1] = {102};
	
	Celula_priv_t *nova1 = cria_celula(100, 0, 3, 0, 0, NULL, (const char *) "tarefa1");
	Celula_priv_t *nova2 = cria_celula(101, 0, 2, 0, 0, NULL, (const char *) "tarefa2");
	Celula_priv_t *nova3 = cria_celula(102, 0, 4, 0, 1, reqs1, (const char *) "tarefa3");
	Celula_priv_t *nova4 = cria_celula(200, 0, 1, 0, 1, reqs2, (const char *) "tarefa4");
	Celula_priv_t *nova5 = cria_celula(201, 0, 5, 0, 1, reqs3, (const char *) "tarefa5");

	inserir_vert(meu_grafo, nova1);
	inserir_vert(meu_grafo, nova2);

	inserir_aresta(meu_grafo, 100, nova3, 1.0);
	inserir_aresta(meu_grafo, 101, nova4, 2.0);
	inserir_aresta(meu_grafo, 102, nova5, 5);
	
	EXPECT_EQ(TRUE_T, existe_aresta(meu_grafo, 100, 102));
	EXPECT_EQ(TRUE_T, existe_aresta(meu_grafo, 101, 200));
	EXPECT_EQ(TRUE_T, existe_aresta(meu_grafo, 102, 201));
	EXPECT_EQ(FALSE_T, existe_aresta(meu_grafo, 100, 200));

	remover_vert(meu_grafo, 100);
	remover_vert(meu_grafo, 102);

	EXPECT_EQ(FALSE_T, existe_vert(meu_grafo, 100));
	EXPECT_EQ(FALSE_T, existe_vert(meu_grafo, 102));

	EXPECT_EQ(FALSE_T, existe_aresta(meu_grafo, 100, 102));
	EXPECT_EQ(TRUE_T, existe_aresta(meu_grafo, 101, 200));
	EXPECT_EQ(FALSE_T, existe_aresta(meu_grafo, 102, 201));
	
	meu_grafo = deletar_grafo(meu_grafo);
}

TEST(remover_arestaTest, vertice_inexistente) {
	
	grafo_priv_t *meu_grafo = criar_grafo();
	
	remover_aresta(meu_grafo, 100, 101);
	remover_aresta(meu_grafo, 101, 102);
	remover_aresta(meu_grafo, 101, 200);
	
	EXPECT_EQ(FALSE_T, existe_vert(meu_grafo, 100));
	EXPECT_EQ(FALSE_T, existe_vert(meu_grafo, 101));
	EXPECT_EQ(FALSE_T, existe_vert(meu_grafo, 102));
	EXPECT_EQ(FALSE_T, existe_vert(meu_grafo, 200));
	
	EXPECT_EQ(FALSE_T, existe_aresta(meu_grafo, 100, 101));
	EXPECT_EQ(FALSE_T, existe_aresta(meu_grafo, 101, 102));
	EXPECT_EQ(FALSE_T, existe_aresta(meu_grafo, 102, 200));
	
	meu_grafo = deletar_grafo(meu_grafo);
}

TEST(remover_arestaTest, aresta_existente) {
	
	grafo_priv_t *meu_grafo = criar_grafo();

	int reqs1[1] = {100};
	int reqs2[1] = {101};
	int reqs3[1] = {102};
	
	Celula_priv_t *nova1 = cria_celula(100, 0, 3, 0, 0, NULL, (const char *) "tarefa1");
	Celula_priv_t *nova2 = cria_celula(101, 0, 2, 0, 0, NULL, (const char *) "tarefa2");
	Celula_priv_t *nova3 = cria_celula(102, 0, 4, 0, 1, reqs1, (const char *) "tarefa3");
	Celula_priv_t *nova4 = cria_celula(200, 0, 1, 0, 1, reqs2, (const char *) "tarefa4");
	Celula_priv_t *nova5 = cria_celula(201, 0, 5, 0, 1, reqs3, (const char *) "tarefa5");

	inserir_vert(meu_grafo, nova1);
	inserir_vert(meu_grafo, nova2);

	inserir_aresta(meu_grafo, 100, nova3, 1.0);
	inserir_aresta(meu_grafo, 101, nova4, 2.0);
	inserir_aresta(meu_grafo, 102, nova5, 5);

	remover_aresta(meu_grafo, 100, 102);
	remover_aresta(meu_grafo, 101, 200);
	remover_aresta(meu_grafo, 102, 201);

	EXPECT_EQ(TRUE_T, existe_vert(meu_grafo, 100));
	EXPECT_EQ(TRUE_T, existe_vert(meu_grafo, 101));
	EXPECT_EQ(TRUE_T, existe_vert(meu_grafo, 102));
	EXPECT_EQ(TRUE_T, existe_vert(meu_grafo, 200));
	EXPECT_EQ(TRUE_T, existe_vert(meu_grafo, 201));

	EXPECT_EQ(FALSE_T, existe_aresta(meu_grafo, 100, 102));
	EXPECT_EQ(FALSE_T, existe_aresta(meu_grafo, 101, 200));
	EXPECT_EQ(FALSE_T, existe_aresta(meu_grafo, 102, 201));
	
	meu_grafo = deletar_grafo(meu_grafo);
}

int main (int argc, char **argv) {
	
	grafo_priv_t *meu_grafo = criar_grafo();
	
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
	
}
