#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "dep.h"
///Variaveis Globais
extern Game_dat game_data;
extern Ship ship_data;
bool next;
int i, j;
///Funções
void load_game(void)
{
	int i, j, choice;
	FILE * arq;
	Save save_game[10], save_gm;
	next = false;
	
	srand( (unsigned)time(NULL) );
	
	while(next == false)
	{
		textcolor(LIGHT_BLUE);
		printf("....................BATATA NAVAL....................\n\n");
		textcolor(CYAN);             
		printf("    Deseja abrir jogo salvo: \n\n");
		printf("[1] -  Sim\n");
		printf("[2] -  Não\n");
		textcolor(GREEN);
		printf("- > ");
		scanf("%d",&choice);
		system("cls");
			
		if(choice == 1 || choice ==2)
			next = true;
		else
			next = false;
	}
	
	if(choice == 2)///Se o usuario não quiser abrir jogo salvo entra nessa condição
	{
		next = false;
		while(next == false)///Set Game_mode
		{
			textcolor(LIGHT_BLUE);
			printf("....................BATATA NAVAL....................\n\n");
			textcolor(CYAN);             
			printf("    Selecione o modo de jogo: \n\n");
			printf("[1] -  Jogador    vs   Jogador\n");
			printf("[2] -  Jogador    vs  Computador\n");
			printf("[3] - Computador  vs  Computador\n\n");
			textcolor(GREEN);
			printf("- > ");
			scanf("%d",&game_data.game_mode);
			system("cls");
			
			if(game_data.game_mode >= 1 && game_data.game_mode <=3)
				next = true;
			else
				next = false;
		}
		
		next = false;
		while(next == false)///Set Game_level
		{
			textcolor(LIGHT_BLUE);
			printf("....................BATATA NAVAL....................\n\n");
			textcolor(CYAN);             
			printf(" Selecione a dificuldade de jogo: \n\n");
			printf("[1] - Facil\n");
			printf("[2] - Normal\n");
			printf("[3] - Dificil\n\n");
			textcolor(GREEN);
			printf("- > ");
			scanf("%d",&game_data.game_level);
			system("cls");
			
			if(game_data.game_level >= 1 && game_data.game_level <=3)
				next = true;
			else
				next = false;
		}
		
		
		textcolor(LIGHT_BLUE);
		printf("....................BATATA NAVAL....................\n\n");
		textcolor(CYAN);             
		printf(" Player 1 : \n\n");
		printf("[NOME] - ");
		fflush(stdin);
		gets(game_data.player_1.nom);
		game_data.player_1.num = 1;
		game_data.player_1.pnt = 0;
		
		system("cls");
		
		if(game_data.game_mode == 1)
		{
			textcolor(LIGHT_BLUE);
			printf("....................BATATA NAVAL....................\n\n");
			textcolor(CYAN);    
			printf(" Player 2 : \n\n");
			printf("[NOME] - ");
			fflush(stdin);
			gets(game_data.player_2.nom);
		}
		else
		{
			strcpy(game_data.player_2.nom, "PC 2");
		}
		
		game_data.player_2.num = 2;
		game_data.player_2.pnt = 0;
		system("cls");
		
		for(i=0;i<HELL;i++)
			for(j=0;j<HELL;j++)
			{
				game_data.player_1.map[i][j] = 0; 
				game_data.player_2.map[i][j] = 0;
				game_data.player_1.atk[i][j] = '~'; 
				game_data.player_2.atk[i][j] = '~';
			}
			
		switch(game_data.game_level)
		{
			case 1:
				game_data.game_level		= EASY;
				ship_data.porta_aviao		= 0;//[][][][] [][][][]
				ship_data.fragata			= 1;//[][][][]
				ship_data.contratorpediro	= 1;//[][][]
				ship_data.submarino			= 0;//[][]
				ship_data.corveta			= 2;//[][]
				ship_data.mina_naval		= 3;//[]
				ship_data.tot				= 14;
				ship_data.atk_especial		= false;
				break;
			case 2:
				game_data.game_level = REGULAR;
				ship_data.porta_aviao		= 1;//[][][][] [][][][]
				ship_data.fragata			= 2;//[][][][]
				ship_data.contratorpediro	= 3;//[][][]
				ship_data.submarino			= 1;//[][]
				ship_data.corveta			= 2;//[][]
				ship_data.mina_naval		= 4;//[]
				ship_data.tot				= 35;
				ship_data.atk_especial		= true;
				break;
			case 3:
				game_data.game_level = HELL;
				ship_data.porta_aviao		= 2;//[][][][] [][][][]
				ship_data.fragata			= 3;//[][][][]
				ship_data.contratorpediro	= 4;//[][][]
				ship_data.submarino			= 2;//[][]
				ship_data.corveta			= 5;//[][]
				ship_data.mina_naval		= 10;//[]
				ship_data.tot				= 64;
				ship_data.atk_especial		= true;
		}
		game_data.game_save_load = false;
		game_data.id = rand();
	}
	else
	{
		i = 1;
		arq = fopen("save_game","rb+");
		if(arq == NULL)
		{
			printf("Não existem partidas salvas\n");
			system("pause");
			exit(0);
		}
		
		fread(&save_game[i-1], sizeof(Save), 1, arq);
		while (!feof(arq))
		{
			i++;
			fread(&save_game[i-1], sizeof(Save), 1, arq);
		}
		fclose(arq);
		
		for(j=0;j<i-1;j++)
			printf("[%d° PARTIDA] - %s\n", j+1, save_game[j].partida);
		
		
		printf("\n[ESCOLHA O NUMERO DA PARTIDA] - ");
		scanf("%d",&choice);
		
		
		arq = fopen("save_game","rb+");
		if(arq == NULL)
		{
			printf("Erro ao ler arquivo salvo\n");
			system("pause");
			exit(0);
		}
		
		i = 1;
		fread(&save_gm, sizeof(Save), 1, arq);
			
		if(i != choice)
			while (!feof(arq))
			{
				i++;
				fread(&save_gm, sizeof(Save), 1, arq);
				
				if(i == choice)
					break;
			}
		
		game_data = save_gm.game_data;
		ship_data = save_gm.ship_data;
		game_data.game_save_load = true;		
	}	
}
