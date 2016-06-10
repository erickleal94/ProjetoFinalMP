#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h> 

typedef struct{
	
	int ID_tarefa, executada, duracao, ini_min, pre_req;
	char nome[200];
	int *reqs;
		
	
} Celula;

void Ler_Tarefas(Celula *celula, char *NomeArq){
	
	FILE *fp;
	
	fp = fopen(NomeArq, "r");
	
	
	
	fscanf(fp, "%d '%[^']' %d %d %d %d", &celula->ID_tarefa, celula->nome, &celula->executada, &celula->duracao, &celula->ini_min, &celula->pre_req);
	
	celula->reqs = malloc(sizeof(int)*(celula->pre_req));
	
	
	
	
}

void Imprime_Tarefas(Celula *celula){
	
	printw("%d %s %d %d %d %d\n", celula->ID_tarefa, celula->nome, celula->executada, celula->duracao,celula->ini_min, celula->pre_req);
	refresh();                                      //Atualiza a tela   
    getch();   
	
};

void Grava_Arq(Celula *celula, char *NomeArq){
	
	FILE *fp;
	
	fp = fopen(NomeArq, "w");
	
	fprintf(fp, "%d %s %d %d %d %d\n", celula->ID_tarefa, celula->nome, celula->executada, celula->duracao,celula->ini_min, celula->pre_req);
	
}



int main(){
	
	initscr();
	start_color();
	init_pair(1,COLOR_BLUE,COLOR_WHITE); //Texto(Azul)     |  Fundo(Branco)
	bkgd(COLOR_PAIR(1));
	move(1,0);
	Celula celula;
	Ler_Tarefas(&celula, "teste.txt");
	Imprime_Tarefas(&celula);
	Grava_Arq(&celula, "testesaida.txt");
	
	endwin();
	return 0;
}
