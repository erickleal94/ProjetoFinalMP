#include <curses.h>                
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <grafo_priv.h>
#include <grafo.h>

void interface_remover_tarefa(){
	
	int ID;
	
	clear();
	refresh();
	box(stdscr, 0, 0);
	move(1,1);
	printw("Qual o codigo da tarefa que deseja remover?");
	move(2,1);
	scanw("%d", &ID);
	//funcao que vai remover tarefa
	refresh();
	
	getch();
	clear();
	box(stdscr, 0, 0);
	refresh();
	
	
}

void interface_editar_tarefa(){
	
	int ID;
	
	clear();
	refresh();
	box(stdscr, 0, 0);
	move(1,1);
	printw("Qual o codigo da tarefa que deseja editar?");
	move(2,1);
	scanw("%d", &ID);
	//funcao que vai editar tarefa
	refresh();
	
	getch();
	clear();
	box(stdscr, 0, 0);
	refresh();	
	
}

void interface_inserir_tarefa(){
	
	int ID, ini_min, duracao, pre_req, *reqs;
	char nome[100];
	int i, j;
	
	clear();
	refresh();
	box(stdscr, 0, 0);
	move(1,1);
	printw("Digite as informacoes da tarefa que deseja inserir:");
	move(2,1);
	printw("Codigo da tarefa: ");
	scanw("%d", &ID);
	move(3,1);
	printw("Digite o nome da tarefa: ");
	scanw(" %[^\n]", nome);
	move(4,1);
	printw("Tempo de inicio minimo: ");
	scanw("%d", &ini_min);
	move(5,1);
	printw("Tempo de duracao: ");
	scanw("%d", &duracao);
	move(6,1);
	printw("Quantidade de pre-requisitos: ");
	scanw("%d", &pre_req);
	if(pre_req > 0){
		reqs = (int*)malloc(sizeof(int)*pre_req);
		for (i = 0, j = 7; i < pre_req; i++, j++) {
			move(j,1);
			printw("Codigo do pre-requisito: ");
			scanw("%d", &reqs[i]);
		}
	}
	
	
	//funcao que vai inserir tarefa
	refresh();
	
	
	getch();
	clear();
	box(stdscr, 0, 0);
	refresh();	
	
}

void interface_caminho_completo(const grafo_priv_t *meu_grafo){
	
	int tempo;
	
	clear();
	refresh();
	box(stdscr, 0, 0);
	move(1,1);
	printw("Tempo para executar todas as tarefas: ");
	//tempo = funcao que vai medir o tempo
	//printw("%d", tempo);
	refresh();
	
	getch();
	clear();
	box(stdscr, 0, 0);
	refresh();
		
}

void interface_caminho_parcial(){
	
	int tempo;
	
	init_pair(2,COLOR_RED,COLOR_BLACK);
	init_pair(3,COLOR_GREEN,COLOR_BLACK);
	init_pair(4,COLOR_YELLOW,COLOR_BLACK);
	
	
	clear();
	refresh();
	box(stdscr, 0, 0);
	move(1,1);
	printw("Qual o tempo que deseja analisar?");
	move(2,1);
	scanw("%d", &tempo);
	//funcao que vai analisar o tempo
	move(3,1);
	attron(COLOR_PAIR(3));
	printw("Tarefas ja concluidas: ");
	move(4,1);
	attron(COLOR_PAIR(4));
	printw("Tarefas em execucao: ");
	move(5,1);	
	attron(COLOR_PAIR(2));
	printw("Tarefas nao iniciadas: ");
	move(6,1);	
	
	refresh();
	getch();
	clear();
	attron(COLOR_PAIR(1));
	box(stdscr, 0, 0);
	refresh();
	
	
}

void interface_vizualizar_tarefas(){
	
	clear();
	refresh();
	box(stdscr, 0, 0);
	move(1,1);
	printw("As tarefas sao: ");
	move(2,1);	
	//funcao para imprimir tarefas
	refresh();
	
	getch();
	clear();
	box(stdscr, 0, 0);
	refresh();
}

void interface_vizualizar_determinada_tarefa(const grafo_priv_t *meu_grafo){
	
	int ID, i;
	Celula_priv_t celula;
	
	clear();
	refresh();
	box(stdscr, 0, 0);
	move(1,1);
	printw("Qual o codigo da tarefa que deseja visualizar?");
	move(2,1);
	scanw("%d", &ID);
	
	*celula = achar_celula(meu_grafo, ID);
	
	move(3,1);
	printw("%d %s %d %d %d %d ", celula->id_externo, celula->nome, celula->executada, celula->duracao, celula->ini_min, celula->pre_req);
	if(celula->pre_req > 0){
		for(i = 0; i < celula->pre_req; i++){
			printw("%d ", celula->reqs[i]);
		}
		
	}
	
	
	
	refresh();
	
	getch();
	clear();
	box(stdscr, 0, 0);
	refresh();	
	
}


int main(){
	
	int escolha = -1;
	
	
	initscr();
	start_color();
	box(stdscr, 0, 0);
	init_pair(1,COLOR_WHITE,COLOR_BLACK); //Texto(BRANCO) | Fundo(PRETO)
	bkgd(COLOR_PAIR(1));
	
	while(escolha != 0){
		move(1,1);
		printw("Escolha o que deseja fazer:");
		move(2,1);
		printw("1 - Remover tarefa");
		move(3,1);
		printw("2 - Editar tarefa");
		move(4,1);
		printw("3 - Inserir tarefa");
		move(5,1);
		printw("4 - Visualizar tempo para completar todas as tarefas");
		move(6,1);
		printw("5 - Visualizar situacao das tarefas em determinado tempo");
		move(7,1);
		printw("6 - Visualizar todas as tarefas");
		move(8,1);
		printw("7 - Visualizar determinada tarefa");	
		move(9,1);
		printw("0 - Sair");
		move(10,1);
		scanw("%d", &escolha);
		refresh();
		switch(escolha){
			case 1:
				interface_remover_tarefa();
				break;	
			
			case 2:
				interface_editar_tarefa();
				break;
			
			case 3:
				interface_inserir_tarefa();
				break;
			
			case 4:
				interface_caminho_completo();
				break;
				
			case 5:
				interface_caminho_parcial();
				break;
				
			case 6:
				interface_vizualizar_tarefas();
				break;
				
			case 7:
					interface_vizualizar_determinada_tarefa();
					break;
					
			case 0:
				break;			
		}
	}
	
	
	
	
	
	
	endwin();
	return 0;
	
	
}
