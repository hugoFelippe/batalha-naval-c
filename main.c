#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include "dep.h"
///Variaveis Globais
Game_dat game_data;
Ship ship_data;



///Programa Principal
int main() {
	setlocale(LC_ALL, "Portuguese");
	
	load_game();
	init_game();
	
	
	getch();
	return 0;
}
