/*UNIVERSIDADE DE BRASÍLIA
* INSTITUTO DE CIÊNCIAS EXATAS
* DEPARTAMENTO DE CIÊNCIA DA COMPUTAÇÃO
* Brasília, 15 de maio de 2016
* Disciplina: MÉTODOS DE PROGRAMAÇÃO
* Aluno: Victor Fabre Figueiredo – 15/0022948 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estruturas.h"
#include <gtest/gtest.h>

/*Este módulo contém os testes que serão realizados. Existem testes para testar cada uma das funções em diferentes cenários,
 *os teste foram desenvolvidos se baseando no arquivo "entrada.txt" e no grafo nele contido. Caso o programa seja executado
 *com uma outra entrada, os testes poderão falhar. Ao final da execução, um arquivo denominado "saida.txt" será criado
 *contendo o grafo no mesmo formato do arquivo de entrada.*/

TEST(Graph_Tests, Creating){
	t_grafo* g = criaGrafoArq((char*)"entrada.txt");
	t_grafo* test = NULL;
	ASSERT_NE(test, g);
	EXPECT_EQ(GRAFO_OK , limpaGrafo(g));
}

TEST(Graph_Tests, Inserting){
	t_grafo* g = criaGrafoArq((char*)"entrada.txt");
	t_grafo* test = NULL;
	ASSERT_NE(test, g);
	//vertices
	EXPECT_EQ(GRAFO_OK, insereVertice(g, (char*)"O"));          //inserindo um vertice qualquer
	EXPECT_EQ(GRAFO_ERR, insereVertice(test, (char*)"VF"));     //inserindo um vertice qualquer em um grafo nulo
	EXPECT_EQ(GRAFO_ERR, insereVertice(test, (char*)"O"));      //inserindo um vertice já existente
	//origens
	EXPECT_EQ(GRAFO_OK, insereOrigem(g, (char*)"O"));       //inserindo uma origem
	EXPECT_EQ(GRAFO_ERR, insereOrigem(g, (char*)"K"));      //inserindo uma origem que não existe como vertice
	EXPECT_EQ(GRAFO_ERR, insereOrigem(test, (char*)"O"));   //inserindo uma origem em um grafo nulo
	//arestas
	EXPECT_EQ(GRAFO_OK, insereAresta(g, (char*)"F", (char*)"O", 6));    //inserindo uma aresta normal
	EXPECT_EQ(GRAFO_ERR, insereAresta(g, (char*)"P", (char*)"O", 1));	//inserindo uma aresta que não possui o vertice P como origem
	EXPECT_EQ(GRAFO_ERR, insereAresta(g, (char*)"F", (char*)"P", 3));   //inserindo uma aresta que não possui o vertice P como dest
	EXPECT_EQ(GRAFO_OK , limpaGrafo(g));
}

TEST(Graph_Tests, Removing){
	t_grafo* g = criaGrafoArq((char*)"entrada.txt");
	t_grafo* test = NULL;
	ASSERT_NE(test, g);
	//a partir do grafo de exemplo removeremos seus elementos
	EXPECT_EQ(GRAFO_ERR,retiraOrigem(test, (char*)"C"));     //retira uma origem de um grafo nulo
	EXPECT_EQ(GRAFO_OK,retiraOrigem(g, (char*)"C"));         //retira uma origem existente
	EXPECT_EQ(GRAFO_ERR,retiraOrigem(g, (char*)"L"));        //retira uma origem inexistente 
	EXPECT_EQ(GRAFO_ERR,retiraOrigem(g, (char*)"F"));        //retira uma origem inexistente mas é um vértice
	//arestas
	EXPECT_EQ(GRAFO_OK,retiraAresta(g, (char*)"F",(char*)"F"));    //retira uma aresta existente
	EXPECT_EQ(GRAFO_ERR,retiraAresta(g, (char*)"F",(char*)"P"));   //retira uma aresta com um dos vertices inexistentes
	EXPECT_EQ(GRAFO_ERR,retiraAresta(g, (char*)"P",(char*)"O"));   //retira uma aresta completamente inexistente
	//vertices
	EXPECT_EQ(GRAFO_ERR,retiraVertice(test, (char*)"A"));     //retira um vertice de um grafo nulo
	EXPECT_EQ(GRAFO_ERR,retiraVertice(g, (char*)"P"));        //retira um vertice inexistente
	EXPECT_EQ(GRAFO_OK,retiraVertice(g, (char*)"A"));         // retira um vertice existente
    // ao retirar esse vertice, as arestas com ele presente também sao retiradas, assim se quisermos retirar alguma aresta ou origem com ele deve ser encontrado um erro
	EXPECT_EQ(GRAFO_ERR,retiraAresta(g, (char*)"A", (char*)"B"));    // verifica se a aresta A nao existe
	EXPECT_EQ(GRAFO_ERR,retiraOrigem(g, (char*)"A"));                // retira origem A nao existe

	EXPECT_EQ(GRAFO_OK , limpaGrafo(g));
}

TEST(Graph_Tests, Tracks){
	t_grafo* g = criaGrafoArq((char*)"entrada.txt");
	t_grafo* test = NULL;
	ASSERT_NE(test, g);
	
	imprimeGrafoArq(g, "saida.txt");
	
	//caminhos possiveis
	EXPECT_EQ(3, percursoEntre(g, (char*)"A", (char*)"C"));
	EXPECT_EQ(2, percursoEntre(g, (char*)"A", (char*)"D"));
	EXPECT_EQ(1, percursoEntre(g, (char*)"A", (char*)"B"));
	EXPECT_EQ(2, percursoEntre(g, (char*)"B", (char*)"C"));
	EXPECT_EQ(1, percursoEntre(g, (char*)"B", (char*)"D"));
	EXPECT_EQ(1, percursoEntre(g, (char*)"E", (char*)"F"));
	EXPECT_EQ(3, percursoEntre(g, (char*)"E", (char*)"B"));
	//caminhos que devem falhar
	EXPECT_EQ(-1, percursoEntre(g, (char*)"E", (char*)"A"));
	EXPECT_EQ(-1, percursoEntre(g, (char*)"B", (char*)"A"));
	EXPECT_EQ(-1, percursoEntre(g, (char*)"C", (char*)"A"));
	EXPECT_EQ(-1, percursoEntre(g, (char*)"D", (char*)"A"));
	EXPECT_EQ(-1, percursoEntre(g, (char*)"F", (char*)"A"));
	EXPECT_EQ(-1, percursoEntre(g, (char*)"C", (char*)"E"));
	EXPECT_EQ(-1, percursoEntre(g, (char*)"A", (char*)"E"));
	EXPECT_EQ(-1, percursoEntre(g, (char*)"F", (char*)"E"));

	
	EXPECT_EQ(GRAFO_OK , limpaGrafo(g));
}

int main(int argc, char** argv){
	
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
