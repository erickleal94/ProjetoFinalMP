/*UNIVERSIDADE DE BRASÍLIA
* INSTITUTO DE CIÊNCIAS EXATAS
* DEPARTAMENTO DE CIÊNCIA DA COMPUTAÇÃO
* Brasília, 15 de maio de 2016
* Disciplina: MÉTODOS DE PROGRAMAÇÃO
* Aluno: Victor Fabre Figueiredo – 15/0022948
*        Erick Pizani Leal Guimaraes - 12/0116421
*        Rafael Lourenço de Lima Chehab 15/0045123*/


#include "estruturas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h> 

int main(){
	
	initscr();
	start_color();
	box(stdscr, 0, 0);
	init_pair(1,COLOR_WHITE,COLOR_BLACK); //Texto(BRANCO) | Fundo(PRETO)
	bkgd(COLOR_PAIR(1));
	move(1,1);
	
	t_grafo* g = criaGrafoArq((char*)"teste.txt");
	
	endwin();
	return 0;
	
	
	
	
	
	
	
	
	return 0;
}
