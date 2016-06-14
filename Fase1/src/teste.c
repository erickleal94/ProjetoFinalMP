#include <stdio.h>
#include <stdlib.h>
#include <grafo.h>
#include <ncurses.h> 

typedef struct Celula{
	
	int ID_tarefa, executada, duracao, ini_min, pre_req;
	char nome[200];
		
	
} Celula_t;

void Ler_Tarefas(grafo_t *meu_grafo, Celula_t *celula, const char *NomeArq){
	
	FILE *fp;
	
	fp = fopen(NomeArq, "r");
	
	
	
	fscanf(fp, "%d '%[^']' %d %d %d %d", &celula->ID_tarefa, celula->nome, &celula->executada, &celula->duracao, &celula->ini_min, &celula->pre_req);
	
	inserir_vert(meu_grafo, celula);
	
	for (i = 0; i < celula->pre_req; i++) {
		int req;
		fscanf("%d", &req);
		//a direcao eh do pre-requisito ate a celula
		inserir_aresta(meu_grafo, req, celula);
	}
	
	
}

void Imprime_Tarefas(Celula_t *celula){
	
	printw("%d %s %d %d %d %d\n", celula->ID_tarefa, celula->nome, celula->executada, celula->duracao,celula->ini_min, celula->pre_req);
	refresh();                                      //Atualiza a tela   
    getch();   
	
};

void Grava_Arq(Celula_t *celula, char *NomeArq){
	
	FILE *fp;
	
	fp = fopen(NomeArq, "w");
	
	fprintf(fp, "%d %s %d %d %d %d\n", celula->ID_tarefa, celula->nome, celula->executada, celula->duracao,celula->ini_min, celula->pre_req);
	
}



int main(){
	
	initscr();
	start_color();
	box(stdscr, 0, 0);
	init_pair(1,COLOR_WHITE,COLOR_BLACK); //Texto(BRANCO)     |  Fundo(PRETO)
	bkgd(COLOR_PAIR(1));
	move(1,1);
	Celula_t celula;
	Ler_Tarefas(&celula, "teste.txt");
	Imprime_Tarefas(&celula);
	Grava_Arq(&celula, "testesaida.txt");
	
	endwin();
	return 0;
}
