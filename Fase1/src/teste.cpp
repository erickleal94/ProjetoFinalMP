#include <stdio.h>
#include <stdlib.h>
#include <grafo.h>
#include <grafo_priv.h>
#include <ncurses.h>

/*
void Ler_Tarefas(grafo_priv_t *meu_grafo, Celula_priv_t *celula, const char *NomeArq){
	
	FILE *fp;
	int i;
	int duracao;
	
	fp = fopen(NomeArq, "r");
	
	
	
	fscanf(fp, "%d '%[^']' %d %d %d %d", &celula->id_externo, celula->nome, &celula->executada, &duracao, &celula->ini_min, &celula->pre_req);
	
	inserir_vert(meu_grafo, celula);
	
	for (i = 0; i < celula->pre_req; i++) {
		int req;
		fscanf(fp, "%d", &req);
		//a direcao eh do pre-requisito ate a celula
		inserir_aresta(meu_grafo, req, celula, duracao);
	}
	
	
}

void Imprime_Tarefas(Celula_priv_t *celula){
	
	printw("%d %s %d %d %d %d\n", celula->id_externo, celula->nome, celula->executada, celula->duracao,celula->ini_min, celula->pre_req);
	refresh();                                      //Atualiza a tela   
    getch();   
	
};

void Grava_Arq(Celula_priv_t *celula, char *NomeArq){
	
	FILE *fp;
	
	fp = fopen(NomeArq, "w");
	
	fprintf(fp, "%d %s %d %d %d %d\n", celula->id_externo, celula->nome, celula->executada, celula->duracao,celula->ini_min, celula->pre_req);
	
}
*/


int main(){
	
	initscr();
	start_color();
	box(stdscr, 0, 0);
	init_pair(1,COLOR_WHITE,COLOR_BLACK); //Texto(BRANCO)     |  Fundo(PRETO)
	bkgd(COLOR_PAIR(1));
	move(1,1);
	Celula_priv_t celula;
	Ler_Tarefas(&celula, "teste.txt");
	Imprime_Tarefas(&celula);
	Grava_Arq(&celula, "testesaida.txt");
	
	endwin();
	
	return 0;
}
