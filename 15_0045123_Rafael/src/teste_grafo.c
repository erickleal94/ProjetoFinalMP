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
	
	EXPECT_EQ(FALSE, existe_vert(meu_grafo, (const char *) "A"));
	EXPECT_EQ(FALSE, existe_vert(meu_grafo, (const char *) "1"));
	EXPECT_EQ(FALSE, existe_vert(meu_grafo, (const char *) "vert"));
	EXPECT_EQ(FALSE, existe_vert(meu_grafo, (const char *) "test"));
	EXPECT_EQ(FALSE, existe_vert(meu_grafo, (const char *) ""));
	
	
	meu_grafo = deletar_grafo(meu_grafo);
	
}

TEST(existe_vertTest, vertices_existentes) {
	
	grafo_t *meu_grafo = criar_grafo();
	
	inserir_vert(meu_grafo, (const char *) "A");
	inserir_vert(meu_grafo, (const char *) "1");
	inserir_vert(meu_grafo, (const char *) "vert");
	inserir_vert(meu_grafo, (const char *) "test");
	inserir_vert(meu_grafo, (const char *) "");
	
	EXPECT_EQ(TRUE, existe_vert(meu_grafo, (const char *) "A"));
	EXPECT_EQ(TRUE, existe_vert(meu_grafo, (const char *) "1"));
	EXPECT_EQ(TRUE, existe_vert(meu_grafo, (const char *) "vert"));
	EXPECT_EQ(TRUE, existe_vert(meu_grafo, (const char *) "test"));
	EXPECT_EQ(TRUE, existe_vert(meu_grafo, (const char *) ""));
	
	meu_grafo = deletar_grafo(meu_grafo);
	
}

TEST(existe_origemTest, origens_inexistentes) {
	
	grafo_t *meu_grafo = criar_grafo();
	
	inserir_vert(meu_grafo, (const char *) "A");
	
	inserir_vert(meu_grafo, (const char *) "1");
	
	inserir_vert(meu_grafo, (const char *) "vert");
	
	inserir_vert(meu_grafo, (const char *) "test");
	
	inserir_vert(meu_grafo, (const char *) "");
	
	EXPECT_EQ(FALSE, existe_origem(meu_grafo, (const char *) "A"));
	EXPECT_EQ(FALSE, existe_origem(meu_grafo, (const char *) "1"));
	EXPECT_EQ(FALSE, existe_origem(meu_grafo, (const char *) "vert"));
	EXPECT_EQ(FALSE, existe_origem(meu_grafo, (const char *) "test"));
	EXPECT_EQ(FALSE, existe_origem(meu_grafo, (const char *) ""));
	
	meu_grafo = deletar_grafo(meu_grafo);
	
}

TEST(existe_origemTest, vertices_inexistentes) {
	
	grafo_t *meu_grafo = criar_grafo();
	
	inserir_origem(meu_grafo, (const char *) "A");
	
	EXPECT_EQ(FALSE, existe_origem(meu_grafo, (const char *) "A"));
	EXPECT_EQ(FALSE, existe_origem(meu_grafo, (const char *) "1"));
	EXPECT_EQ(FALSE, existe_origem(meu_grafo, (const char *) "vert"));
	EXPECT_EQ(FALSE, existe_origem(meu_grafo, (const char *) "test"));
	EXPECT_EQ(FALSE, existe_origem(meu_grafo, (const char *) ""));
	
	meu_grafo = deletar_grafo(meu_grafo);
	
}

TEST(existe_origemTest, origens_existentes) {
	
	grafo_t *meu_grafo = criar_grafo();
	
	inserir_vert(meu_grafo, (const char *) "A");
	inserir_origem(meu_grafo, (const char *) "A");
	
	inserir_vert(meu_grafo, (const char *) "vert");
	inserir_origem(meu_grafo, (const char *) "vert");
	
	inserir_vert(meu_grafo, (const char *) "");
	inserir_origem(meu_grafo, (const char *) "");
	
	EXPECT_EQ(TRUE, existe_origem(meu_grafo, (const char *) "A"));
	EXPECT_EQ(TRUE, existe_origem(meu_grafo, (const char *) "vert"));
	EXPECT_EQ(TRUE, existe_origem(meu_grafo, (const char *) ""));
	
	meu_grafo = deletar_grafo(meu_grafo);
	
}

TEST(existe_origemTest, origens_existentes_e_inexistentes) {
	
	grafo_t *meu_grafo = criar_grafo();
	
	inserir_vert(meu_grafo, (const char *) "A");
	inserir_origem(meu_grafo, (const char *) "A");
	
	inserir_vert(meu_grafo, (const char *) "1");
	
	inserir_vert(meu_grafo, (const char *) "vert");
	inserir_origem(meu_grafo, (const char *) "vert");
	
	inserir_vert(meu_grafo, (const char *) "");
	inserir_origem(meu_grafo, (const char *) "");
	
	EXPECT_EQ(TRUE, existe_origem(meu_grafo, (const char *) "A"));
	EXPECT_EQ(FALSE, existe_origem(meu_grafo, (const char *) "1"));
	EXPECT_EQ(TRUE, existe_origem(meu_grafo, (const char *) "vert"));
	EXPECT_EQ(FALSE, existe_origem(meu_grafo, (const char *) "test"));
	EXPECT_EQ(TRUE, existe_origem(meu_grafo, (const char *) ""));
	
	meu_grafo = deletar_grafo(meu_grafo);
	
}

TEST(existe_arestaTest, vertices_inexistentes) {
	
	grafo_t *meu_grafo = criar_grafo();
	
	EXPECT_EQ(FALSE, existe_aresta(meu_grafo, (const char *) "A", (const char *) "B"));
	EXPECT_EQ(FALSE, existe_aresta(meu_grafo, (const char *) "A", (const char *) ""));
	EXPECT_EQ(FALSE, existe_aresta(meu_grafo, (const char *) "C", (const char *) "D"));
	
	meu_grafo = deletar_grafo(meu_grafo);
	
}

TEST(existe_arestaTest, arestas_inexistentes) {
	
	grafo_t *meu_grafo = criar_grafo();
	
	inserir_vert(meu_grafo, (const char *) "A");
	inserir_vert(meu_grafo, (const char *) "B");
	inserir_vert(meu_grafo, (const char *) "");
	inserir_vert(meu_grafo, (const char *) "C");
	inserir_vert(meu_grafo, (const char *) "D");
	
	EXPECT_EQ(FALSE, existe_aresta(meu_grafo, (const char *) "A", (const char *) "B"));
	EXPECT_EQ(FALSE, existe_aresta(meu_grafo, (const char *) "A", (const char *) ""));
	EXPECT_EQ(FALSE, existe_aresta(meu_grafo, (const char *) "C", (const char *) "D"));
	
	meu_grafo = deletar_grafo(meu_grafo);
	
}

TEST(existe_arestaTest, arestas_existentes) {
	
	grafo_t *meu_grafo = criar_grafo();
	
	inserir_vert(meu_grafo, (const char *) "A");
	inserir_vert(meu_grafo, (const char *) "B");
	inserir_vert(meu_grafo, (const char *) "");
	inserir_vert(meu_grafo, (const char *) "C");
	inserir_vert(meu_grafo, (const char *) "D");
	
	inserir_aresta(meu_grafo, (const char *) "A", (const char *) "B", 1.0);
	inserir_aresta(meu_grafo, (const char *) "A", (const char *) "", 2.0);
	inserir_aresta(meu_grafo, (const char *) "C", (const char *) "D", 5);
	
	EXPECT_EQ(TRUE, existe_aresta(meu_grafo, (const char *) "A", (const char *) "B"));
	EXPECT_EQ(TRUE, existe_aresta(meu_grafo, (const char *) "A", (const char *) ""));
	EXPECT_EQ(TRUE, existe_aresta(meu_grafo, (const char *) "C", (const char *) "D"));
	EXPECT_EQ(FALSE, existe_aresta(meu_grafo, (const char *) "D", (const char *) "C"));
	
	meu_grafo = deletar_grafo(meu_grafo);
	
}

TEST(existe_arestaTest, peso_invalido) {
	
	grafo_t *meu_grafo = criar_grafo();
	
	inserir_vert(meu_grafo, (const char *) "A");
	inserir_vert(meu_grafo, (const char *) "B");
	inserir_vert(meu_grafo, (const char *) "");
	inserir_vert(meu_grafo, (const char *) "C");
	inserir_vert(meu_grafo, (const char *) "D");
	
	inserir_aresta(meu_grafo, (const char *) "A", (const char *) "B", 0.0);
	inserir_aresta(meu_grafo, (const char *) "A", (const char *) "", -2.0);
	inserir_aresta(meu_grafo, (const char *) "C", (const char *) "D", -5);
	
	EXPECT_EQ(FALSE, existe_aresta(meu_grafo, (const char *) "A", (const char *) "B"));
	EXPECT_EQ(FALSE, existe_aresta(meu_grafo, (const char *) "A", (const char *) ""));
	EXPECT_EQ(FALSE, existe_aresta(meu_grafo, (const char *) "C", (const char *) "D"));
	
	meu_grafo = deletar_grafo(meu_grafo);
	
}

TEST(inserir_vertTest, insercao) {
	
	grafo_t *meu_grafo = criar_grafo();
	
	inserir_vert(meu_grafo, (const char *) "A");
	inserir_vert(meu_grafo, (const char *) "B");
	inserir_vert(meu_grafo, (const char *) "");
	inserir_vert(meu_grafo, (const char *) "blabla");
	inserir_vert(meu_grafo, (const char *) "MP");
	inserir_vert(meu_grafo, (const char *) "A");
	
	EXPECT_EQ(TRUE, existe_vert(meu_grafo, (const char *) "A"));
	EXPECT_EQ(TRUE, existe_vert(meu_grafo, (const char *) "B"));
	EXPECT_EQ(TRUE, existe_vert(meu_grafo, (const char *) ""));
	EXPECT_EQ(TRUE, existe_vert(meu_grafo, (const char *) "blabla"));
	EXPECT_EQ(TRUE, existe_vert(meu_grafo, (const char *) "MP"));
	
	EXPECT_EQ(FALSE, existe_vert(meu_grafo, (const char *) "MP1"));
	EXPECT_EQ(FALSE, existe_vert(meu_grafo, (const char *) "MP_trab"));
	
	meu_grafo = deletar_grafo(meu_grafo);
	
}

TEST(inserir_origemTest, vertice_existente) {
	
	grafo_t *meu_grafo = criar_grafo();
	
	inserir_vert(meu_grafo, (const char *) "A");
	inserir_vert(meu_grafo, (const char *) "B");
	inserir_vert(meu_grafo, (const char *) "");
	inserir_vert(meu_grafo, (const char *) "blabla");
	inserir_vert(meu_grafo, (const char *) "MP");
	
	inserir_origem(meu_grafo, (const char *) "A");
	inserir_origem(meu_grafo, (const char *) "");
	inserir_origem(meu_grafo, (const char *) "MP");
	inserir_origem(meu_grafo, (const char *) "MP");
	inserir_origem(meu_grafo, (const char *) "MP");
	inserir_origem(meu_grafo, (const char *) "MP");
	
	EXPECT_EQ(TRUE, existe_origem(meu_grafo, (const char *) "A"));
	EXPECT_EQ(FALSE, existe_origem(meu_grafo, (const char *) "B"));
	EXPECT_EQ(TRUE, existe_origem(meu_grafo, (const char *) ""));
	EXPECT_EQ(FALSE, existe_origem(meu_grafo, (const char *) "blabla"));
	EXPECT_EQ(TRUE, existe_origem(meu_grafo, (const char *) "MP"));
	
	EXPECT_EQ(FALSE, existe_origem(meu_grafo, (const char *) "MP1"));
	EXPECT_EQ(FALSE, existe_origem(meu_grafo, (const char *) "MP_trab"));
	
	meu_grafo = deletar_grafo(meu_grafo);
	
}

TEST(inserir_origemTest, vertice_inexistente) {
	
	grafo_t *meu_grafo = criar_grafo();
	
	inserir_origem(meu_grafo, (const char *) "A");
	inserir_origem(meu_grafo, (const char *) "");
	inserir_origem(meu_grafo, (const char *) "MP");
	
	EXPECT_EQ(FALSE, existe_origem(meu_grafo, (const char *) "A"));
	EXPECT_EQ(FALSE, existe_origem(meu_grafo, (const char *) ""));
	EXPECT_EQ(FALSE, existe_origem(meu_grafo, (const char *) "MP"));
	
	EXPECT_EQ(FALSE, existe_origem(meu_grafo, (const char *) "MP1"));
	EXPECT_EQ(FALSE, existe_origem(meu_grafo, (const char *) "MP_trab"));
	
	meu_grafo = deletar_grafo(meu_grafo);
	
}

TEST(inserir_arestaTest, vertice_inexistente) {
	
	grafo_t *meu_grafo = criar_grafo();
	
	inserir_aresta(meu_grafo, (const char *) "A", (const char *) "B", 3.0);
	inserir_aresta(meu_grafo, (const char *) "", (const char *) "A", 2);
	inserir_aresta(meu_grafo, (const char *) "MP", (const char *) "balao", 3.14);
	
	EXPECT_EQ(FALSE, existe_aresta(meu_grafo, (const char *) "A", (const char *) "B"));
	EXPECT_EQ(FALSE, existe_aresta(meu_grafo, (const char *) "", (const char *) "A"));
	EXPECT_EQ(FALSE, existe_aresta(meu_grafo, (const char *) "MP", (const char *) "balao"));
	EXPECT_EQ(FALSE, existe_aresta(meu_grafo, (const char *) "MP", (const char *) "B"));
	
	meu_grafo = deletar_grafo(meu_grafo);
	
}
TEST(inserir_arestaTest, vertice_existente) {
	
	grafo_t *meu_grafo = criar_grafo();
	
	inserir_vert(meu_grafo, (const char *) "A");
	inserir_vert(meu_grafo, (const char *) "B");
	inserir_vert(meu_grafo, (const char *) "");
	inserir_vert(meu_grafo, (const char *) "balao");
	inserir_vert(meu_grafo, (const char *) "MP");
	inserir_aresta(meu_grafo, (const char *) "A", (const char *) "B", 3.0);
	inserir_aresta(meu_grafo, (const char *) "", (const char *) "A", 2);
	inserir_aresta(meu_grafo, (const char *) "MP", (const char *) "balao", 3.14);
	
	EXPECT_EQ(TRUE, existe_aresta(meu_grafo, (const char *) "A", (const char *) "B"));
	EXPECT_EQ(TRUE, existe_aresta(meu_grafo, (const char *) "", (const char *) "A"));
	EXPECT_EQ(TRUE, existe_aresta(meu_grafo, (const char *) "MP", (const char *) "balao"));
	EXPECT_EQ(FALSE, existe_aresta(meu_grafo, (const char *) "MP", (const char *) "B"));
	
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
	
	const char *s1 = "A";
	const char *s2 = "B";
	grafo_t *meu_grafo = criar_grafo();
	
	inserir_vert(meu_grafo, s1);
	inserir_vert(meu_grafo, s2);
	
	EXPECT_EQ(TRUE, existe_vert(meu_grafo, s1));
	EXPECT_EQ(TRUE, existe_vert(meu_grafo, s2));
	
	remover_vert(meu_grafo, s1);
	remover_vert(meu_grafo, s2);
	
	EXPECT_EQ(FALSE, existe_vert(meu_grafo, s1));
	EXPECT_EQ(FALSE, existe_vert(meu_grafo, s2));
	
	meu_grafo = deletar_grafo(meu_grafo);
}

TEST(remover_verticeTest, vertice_inexistente) {
	
	const char *s1 = "A";
	const char *s2 = "B";
	grafo_t *meu_grafo = criar_grafo();
	
	EXPECT_EQ(FALSE, existe_vert(meu_grafo, s1));
	EXPECT_EQ(FALSE, existe_vert(meu_grafo, s2));
	
	remover_vert(meu_grafo, s1);
	remover_vert(meu_grafo, s2);
	
	EXPECT_EQ(FALSE, existe_vert(meu_grafo, s1));
	EXPECT_EQ(FALSE, existe_vert(meu_grafo, s2));
	
	meu_grafo = deletar_grafo(meu_grafo);
}

TEST(remover_verticeTest, vertice_existente_com_origem_e_arestas) {
	
	grafo_t *meu_grafo = criar_grafo();
	
	inserir_vert(meu_grafo, (const char *) "A");
	inserir_vert(meu_grafo, (const char *) "B");
	inserir_vert(meu_grafo, (const char *) "balao");
	inserir_vert(meu_grafo, (const char *) "MP");
	
	inserir_origem(meu_grafo, (const char *) "A");
	inserir_origem(meu_grafo, (const char *) "balao");
	
	inserir_aresta(meu_grafo, (const char *) "A", (const char *) "B", 3.0);
	inserir_aresta(meu_grafo, (const char *) "MP", (const char *) "balao", 3.14);
	inserir_aresta(meu_grafo, (const char *) "balao", (const char *) "B", 1.0);
	
	EXPECT_EQ(TRUE, existe_vert(meu_grafo, (const char *) "A"));
	EXPECT_EQ(TRUE, existe_vert(meu_grafo, (const char *) "balao"));
	EXPECT_EQ(TRUE, existe_vert(meu_grafo, (const char *) "MP"));
	EXPECT_EQ(TRUE, existe_vert(meu_grafo, (const char *) "B"));
	
	EXPECT_EQ(TRUE, existe_origem(meu_grafo, (const char *) "A"));
	EXPECT_EQ(TRUE, existe_origem(meu_grafo, (const char *) "balao"));
	
	EXPECT_EQ(TRUE, existe_aresta(meu_grafo, (const char *) "A", (const char *) "B"));
	EXPECT_EQ(TRUE, existe_aresta(meu_grafo, (const char *) "MP", (const char *) "balao"));
	EXPECT_EQ(TRUE, existe_aresta(meu_grafo, (const char *) "balao", (const char *) "B"));
	
	remover_vert(meu_grafo, (const char *) "A");
	remover_vert(meu_grafo, (const char *) "MP");
	
	EXPECT_EQ(FALSE, existe_vert(meu_grafo, (const char *) "A"));
	EXPECT_EQ(TRUE, existe_vert(meu_grafo, (const char *) "balao"));
	EXPECT_EQ(FALSE, existe_vert(meu_grafo, (const char *) "MP"));
	EXPECT_EQ(TRUE, existe_vert(meu_grafo, (const char *) "B"));
	
	EXPECT_EQ(FALSE, existe_origem(meu_grafo, (const char *) "A"));
	EXPECT_EQ(TRUE, existe_origem(meu_grafo, (const char *) "balao"));
	
	EXPECT_EQ(FALSE, existe_aresta(meu_grafo, (const char *) "A", (const char *) "B"));
	EXPECT_EQ(FALSE, existe_aresta(meu_grafo, (const char *) "MP", (const char *) "balao"));
	EXPECT_EQ(TRUE, existe_aresta(meu_grafo, (const char *) "balao", (const char *) "B"));
	
	meu_grafo = deletar_grafo(meu_grafo);
}

TEST(remover_origemTest, vertice_inexistente) {
	
	grafo_t *meu_grafo = criar_grafo();
	
	inserir_origem(meu_grafo, (const char *) "A");
	inserir_origem(meu_grafo, (const char *) "balao");
	
	remover_origem(meu_grafo, (const char *) "A");
	remover_origem(meu_grafo, (const char *) "balao");
	remover_origem(meu_grafo, (const char *) "B");
	
	EXPECT_EQ(FALSE, existe_vert(meu_grafo, (const char *) "A"));
	
	EXPECT_EQ(FALSE, existe_origem(meu_grafo, (const char *) "A"));
	EXPECT_EQ(FALSE, existe_origem(meu_grafo, (const char *) "balao"));
	EXPECT_EQ(FALSE, existe_origem(meu_grafo, (const char *) "B"));
	
	meu_grafo = deletar_grafo(meu_grafo);
}

TEST(remover_origemTest, vertice_existente) {
	
	grafo_t *meu_grafo = criar_grafo();
	
	inserir_vert(meu_grafo, (const char *) "A");
	inserir_vert(meu_grafo, (const char *) "balao");
	inserir_vert(meu_grafo, (const char *) "B");
	
	inserir_origem(meu_grafo, (const char *) "A");
	inserir_origem(meu_grafo, (const char *) "balao");
	
	remover_origem(meu_grafo, (const char *) "A");
	remover_origem(meu_grafo, (const char *) "B");
	
	EXPECT_EQ(TRUE, existe_vert(meu_grafo, (const char *) "A"));
	EXPECT_EQ(TRUE, existe_vert(meu_grafo, (const char *) "B"));
	EXPECT_EQ(TRUE, existe_vert(meu_grafo, (const char *) "balao"));
	EXPECT_EQ(FALSE, existe_vert(meu_grafo, (const char *) "bla"));
	
	EXPECT_EQ(FALSE, existe_origem(meu_grafo, (const char *) "A"));
	EXPECT_EQ(TRUE, existe_origem(meu_grafo, (const char *) "balao"));
	EXPECT_EQ(FALSE, existe_origem(meu_grafo, (const char *) "B"));
	EXPECT_EQ(FALSE, existe_vert(meu_grafo, (const char *) "bla"));
	
	meu_grafo = deletar_grafo(meu_grafo);
}

TEST(remover_arestaTest, vertice_inexistente) {
	
	grafo_t *meu_grafo = criar_grafo();
	
	remover_aresta(meu_grafo, (const char *) "A", (const char *) "B");
	remover_aresta(meu_grafo, (const char *) "A", (const char *) "MP");
	remover_aresta(meu_grafo, (const char *) "MP", (const char *) "C");
	
	EXPECT_EQ(FALSE, existe_vert(meu_grafo, (const char *) "A"));
	EXPECT_EQ(FALSE, existe_vert(meu_grafo, (const char *) "B"));
	EXPECT_EQ(FALSE, existe_vert(meu_grafo, (const char *) "MP"));
	EXPECT_EQ(FALSE, existe_vert(meu_grafo, (const char *) "C"));
	
	EXPECT_EQ(FALSE, existe_aresta(meu_grafo, (const char *) "A", (const char *) "B"));
	EXPECT_EQ(FALSE, existe_aresta(meu_grafo, (const char *) "A", (const char *) "MP"));
	EXPECT_EQ(FALSE, existe_aresta(meu_grafo, (const char *) "MP", (const char *) "C"));
	
	meu_grafo = deletar_grafo(meu_grafo);
}

TEST(remover_arestaTest, aresta_existente) {
	
	grafo_t *meu_grafo = criar_grafo();
	
	inserir_vert(meu_grafo, (const char *) "A");
	inserir_vert(meu_grafo, (const char *) "B");
	inserir_vert(meu_grafo, (const char *) "MP");
	inserir_vert(meu_grafo, (const char *) "C");
	inserir_vert(meu_grafo, (const char *) "balao");
	
	inserir_aresta(meu_grafo, (const char *) "C", (const char *) "A", -1.0);
	inserir_aresta(meu_grafo, (const char *) "A", (const char *) "balao", 0.0);
	inserir_aresta(meu_grafo, (const char *) "A", (const char *) "B", 3.0);
	inserir_aresta(meu_grafo, (const char *) "A", (const char *) "MP", 4.0);
	inserir_aresta(meu_grafo, (const char *) "MP", (const char *) "A", 5.0);
	inserir_aresta(meu_grafo, (const char *) "A", (const char *) "C", 0.1);
	
	
	remover_aresta(meu_grafo, (const char *) "A", (const char *) "B");
	remover_aresta(meu_grafo, (const char *) "A", (const char *) "MP");
	remover_aresta(meu_grafo, (const char *) "MP", (const char *) "C");
	
	EXPECT_EQ(TRUE, existe_vert(meu_grafo, (const char *) "A"));
	EXPECT_EQ(TRUE, existe_vert(meu_grafo, (const char *) "B"));
	EXPECT_EQ(TRUE, existe_vert(meu_grafo, (const char *) "MP"));
	EXPECT_EQ(TRUE, existe_vert(meu_grafo, (const char *) "C"));
	EXPECT_EQ(TRUE, existe_vert(meu_grafo, (const char *) "balao"));
	
	EXPECT_EQ(FALSE, existe_aresta(meu_grafo, (const char *) "C", (const char *) "A"));
	EXPECT_EQ(FALSE, existe_aresta(meu_grafo, (const char *) "A", (const char *) "balao"));
	EXPECT_EQ(FALSE, existe_aresta(meu_grafo, (const char *) "A", (const char *) "B"));
	EXPECT_EQ(FALSE, existe_aresta(meu_grafo, (const char *) "A", (const char *) "MP"));
	EXPECT_EQ(TRUE, existe_aresta(meu_grafo, (const char *) "MP", (const char *) "A"));
	EXPECT_EQ(FALSE, existe_aresta(meu_grafo, (const char *) "MP", (const char *) "C"));
	
	meu_grafo = deletar_grafo(meu_grafo);
}

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

int main (int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
	
}
