#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dep.h"

extern Game_dat game_data;
extern Ship ship_data;

void save_game(int last_move)
{
	FILE * arq;
	Save save_game;
	
	
	arq = fopen("save_game","ab+");
	if(arq == NULL)
	{
		printf("Erro ao abrir o arquivo\n");
		system("pause");
		exit(1);
	}
	strcpy(save_game.partida, game_data.player_1.nom);
	strcat(save_game.partida, " VS ");
	strcat(save_game.partida, game_data.player_2.nom);
	save_game.game_data = game_data;
	save_game.ship_data = ship_data;
	save_game.game_data.last_move = last_move;
	
	fwrite(&save_game, sizeof(Save), 1, arq);
	
	fclose(arq);
}

void atk(int player_id)
{
	int x, y, i, lvl = game_data.game_level;
	Player atk_player, def_player;
	
	if(player_id == 1)
	{
		atk_player = game_data.player_1;
		def_player = game_data.player_2;
	}
	else
	{
		atk_player = game_data.player_2;
		def_player = game_data.player_1;
	}
	
	bat_nav_screen(player_id);
	
	printf("\nAtacar: \n");
	printf("[X] ->");
	scanf("%d",&x);
	printf("[Y] ->");
	scanf("%d",&y);
	
	if(def_player.map[x-1][y-1] == 0)
		def_player.atk[x-1][y-1] = 'O';
	else
		if(def_player.map[x-1][y-1] == 9)
		{
			printf("\nATAQUE ESPECIAL ENCONTRADO: \n");
			printf("Orientação do ataque [1-Linha ou 2-Coluna] : ");
			scanf("%d",&x);
			if(x == 1)
			{
				printf("Selecione a Linha: ");
				scanf("%d",&x);
				for(i=0;i<lvl;i++)
				{
					if(def_player.map[x-1][i] == 0)
						def_player.atk[x-1][i] = 'O';
					else
						if(def_player.atk[x-1][i] == '~')
						{
							def_player.atk[x-1][i] = 'X';
							atk_player.pnt++;
						}
				}
			}
			else
			{
				printf("Selecione a Coluna: ");
				scanf("%d",&x);
				for(i=0;i<lvl;i++)
				{
					if(def_player.map[i][x-1] == 0)
						def_player.atk[i][x-1] = 'O';
					else
						if(def_player.atk[i][x-1] == '~')
						{
							def_player.atk[i][x-1] = 'X';
							atk_player.pnt++;
						}
				}
			}
		}
		else
			if(def_player.atk[x-1][y-1] == '~')
			{
				def_player.atk[x-1][y-1] = 'X';
				atk_player.pnt++;
			}
			
	if(player_id == 1)
	{
		game_data.player_1 = atk_player;
		game_data.player_2 = def_player;
	}
	else
	{
		game_data.player_2 = atk_player;
		game_data.player_1 = def_player;
	}		
	system("cls");
}

void ia_atk(int player_id)
{
	
}
