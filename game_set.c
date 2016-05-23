#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dep.h"
///Variaveis globais
extern Game_dat game_data;
extern Ship ship_data;
///Funções

void game_set_ship(int player)
{	
	Player player_str;
	int i, j, x, y, orientacao;
	int ind = 0;
	int lvl = game_data.game_level;
	
	if(player == 1)
		player_str = game_data.player_1;
	else
		player_str = game_data.player_2;
	
	for(i=0;i<30;i++)
			for(j=0;j<30;j++)
			{
				player_str.map[i][j] = 0; 
				player_str.map[i][j] = 0;
				player_str.atk[i][j] = '~'; 
				player_str.atk[i][j] = '~';
			}
	
	for(i=0;i<ship_data.mina_naval;i++)
	{
		set_nav_screen(player);
		
		printf("%d° MINA NAVAL\n\n",i+1);
		printf("[X] -> ");
		scanf("%d",&x);
		printf("[Y] -> ");
		scanf("%d",&y);
		if(x <= lvl && y <= lvl)
		{
			player_str.map[x-1][y-1]	= 1;
			
			player_str.nav[ind][0]		= x-1;
			player_str.nav[ind][1]		= y-1;
			
			ind++;
			
			if(player == 2)
				game_data.player_2 = player_str;
			else
				game_data.player_1 = player_str;
		}
		else
		{
			printf("\nNão é possivel colocar na posição indicada!!!\n");
			system("pause");
			i--;
		}
	}
	
	for(i=0;i<ship_data.corveta;i++)
	{
		set_nav_screen(player);
		
		printf("%d° Navio classe CORVETA\n\n",i+1);
		printf("[X] -> ");
		scanf("%d",&x);
		printf("[Y] -> ");
		scanf("%d",&y);
		printf("[Orientação -> 1-vetical, 2-horizontal] -> ");
		scanf("%d",&orientacao);

		if(orientacao == 1)
		{
			if((x <= lvl-2) && (y <= lvl) && (player_str.map[x-1][y-1] == 0) && (player_str.map[x][y-1] == 0))
			{
				player_str.map[x-1][y-1]	= 2;
				player_str.map[x][y-1]		= 2;
				
				player_str.nav[ind][0]	= x-1;	player_str.nav[ind][1]	= y-1;
				player_str.nav[ind][2]	= x;	player_str.nav[ind][3]	= y-1;
				
				ind++;
				
				if(player == 1)
					game_data.player_1 = player_str;
				else
					game_data.player_2 = player_str;
			}
			else
			{
				printf("\nNão é possivel colocar na posição indicada!!!\n");
				system("pause");
				i--;
			}
		}
		else
		{
			if((y <= lvl-2) && (x <= lvl) && (player_str.map[x-1][y-1] == 0) && (player_str.map[x-1][y] == 0))
			{
				player_str.map[x-1][y-1]	= 2;
				player_str.map[x-1][y]		= 2;
				
				player_str.nav[ind][0]	= x-1;	player_str.nav[ind][1]	= y-1;
				player_str.nav[ind][2]	= x-1;	player_str.nav[ind][3]	= y;
				
				ind++;
			
				if(player == 1)
					game_data.player_1 = player_str;
				else
					game_data.player_2 = player_str;
			}
			else
			{
				printf("\nNão é possivel colocar na posição indicada!!!\n");
				system("pause");
				i--;
			}
		}	
	}
		
	for(i=0;i<ship_data.contratorpediro;i++)
	{
		set_nav_screen(player);
		
		printf("%d° Navio classe CONTRATORPEDEIRO\n\n",i+1);
		printf("[X] -> ");
		scanf("%d",&x);
		printf("[Y] -> ");
		scanf("%d",&y);
		printf("[Orientação -> 1-vetical, 2-horizontal] -> ");
		scanf("%d",&orientacao);

		if(orientacao == 1)
		{
			if((x <= lvl-3) && (y <= lvl) && (player_str.map[x-1][y-1] == 0) && (player_str.map[x][y-1] == 0) && (player_str.map[x+1][y-1] == 0))
			{
				player_str.map[x-1][y-1]	= 3;
				player_str.map[x][y-1]		= 3;
				player_str.map[x+1][y-1]	= 3;
				
				player_str.nav[ind][0]		= x-1;	player_str.nav[ind][1]		= y-1;
				player_str.nav[ind][2]		= x;	player_str.nav[ind][3]		= y-1;
				player_str.nav[ind][4]		= x+1;	player_str.nav[ind][5]		= y-1;
				
				ind++;
				
				if(player == 1)
					game_data.player_1 = player_str;
				else
					game_data.player_2 = player_str;
			}
			else
			{
				printf("\nNão é possivel colocar na posição indicada!!!\n\n");
				system("pause");
				i--;
			}
		}
		else
		{
			if((y <= lvl-3) && (x <= lvl) && (player_str.map[x-1][y-1] == 0) && (player_str.map[x-1][y] == 0) && (player_str.map[x-1][y+1] == 0))
			{
				player_str.map[x-1][y-1]	= 3;
				player_str.map[x-1][y]		= 3;
				player_str.map[x-1][y+1]	= 3;
				
				player_str.nav[ind][0]		= x-1;	player_str.nav[ind][1]		= y-1;
				player_str.nav[ind][2]		= x-1;	player_str.nav[ind][3]		= y;
				player_str.nav[ind][4]		= x-1;	player_str.nav[ind][5]		= y+1;	
				
				ind++;
				
				if(player == 1)
					game_data.player_1 = player_str;
				else
					game_data.player_2 = player_str;
			}
			else
			{
				printf("\nNão é possivel colocar na posição indicada!!!\n\n");
				system("pause");
				i--;
			}
		}
	}
	
	for(i=0;i<ship_data.fragata;i++)
	{
		set_nav_screen(player);
		
		printf("%d° Navio classe FRAGATA\n\n",i+1);
		printf("[X] -> ");
		scanf("%d",&x);
		printf("[Y] -> ");
		scanf("%d",&y);
		printf("[Orientação -> 1-vetical, 2-horizontal] -> ");
		scanf("%d",&orientacao);

		if(orientacao == 1)
		{
			if((x <= lvl-4) && (y <= lvl) && (player_str.map[x-1][y-1] == 0) && (player_str.map[x][y-1] == 0) && (player_str.map[x+1][y-1] == 0) && (player_str.map[x+2][y-1] == 0))
			{
				player_str.map[x-1][y-1]	= 4;
				player_str.map[x][y-1]		= 4;
				player_str.map[x+1][y-1]	= 4;
				player_str.map[x+2][y-1]	= 4;
				
				player_str.nav[ind][0]		= x-1;	player_str.nav[ind][1]	= y-1;
				player_str.nav[ind][2]		= x;	player_str.nav[ind][3]	= y-1;
				player_str.nav[ind][4]		= x+1;	player_str.nav[ind][5]	= y-1;
				player_str.nav[ind][6]		= x+2;	player_str.nav[ind][7]	= y-1;
				
				ind++;
				
				if(player == 1)
					game_data.player_1 = player_str;
				else
					game_data.player_2 = player_str;
			}
			else
			{
				printf("\nNão é possivel colocar na posição indicada!!!\n\n");
				system("pause");
				i--;
			}
		}
		else
		{
			if((x <= lvl) && (y <= lvl-4) && (player_str.map[x-1][y-1] == 0) && (player_str.map[x-1][y] == 0) && (player_str.map[x-1][y+1] == 0) && (player_str.map[x-1][y+2] == 0))
			{
				player_str.map[x-1][y-1]	= 4;
				player_str.map[x-1][y]		= 4;
				player_str.map[x-1][y+1]	= 4;
				player_str.map[x-1][y+2]	= 4;
				
				player_str.nav[ind][0]		= x-1;	player_str.nav[ind][1]	= y-1;
				player_str.nav[ind][2]		= x-1;	player_str.nav[ind][3]	= y;
				player_str.nav[ind][4]		= x-1;	player_str.nav[ind][5]	= y+1;
				player_str.nav[ind][6]		= x-1;	player_str.nav[ind][7]	= y+2;
				
				ind++;
				
				if(player == 1)
					game_data.player_1 = player_str;
				else
					game_data.player_2 = player_str;	
			}
			else
			{
				printf("\nNão é possivel colocar na posição indicada!!!\n\n");
				system("pause");
				i--;
			}
		}
	}

	for(i=0;i<ship_data.submarino;i++)
	{
		set_nav_screen(player);
		
		printf("%d° Navio classe SUBMARINO\n\n",i+1);
		printf("[X] -> ");
		scanf("%d",&x);
		printf("[Y] -> ");
		scanf("%d",&y);
		printf("[Orientação -> 1-vetical, 2-horizontal] -> ");
		scanf("%d",&orientacao);

		if(orientacao == 1)
		{
			if((x <= lvl-2) && (y <= lvl) && (player_str.map[x-1][y-1] == 0) && (player_str.map[x][y-1] == 0))
			{
				player_str.map[x-1][y-1]	= 5;
				player_str.map[x][y-1]		= 5;
				
				player_str.nav[ind][0]		= x-1;	player_str.nav[ind][1]		= y-1;
				player_str.nav[ind][2]		= x;	player_str.nav[ind][3]		= y-1;
				
				ind++;
				
				if(player == 1)
					game_data.player_1 = player_str;
				else
					game_data.player_2 = player_str;
			}
			else
			{
				printf("\nNão é possivel colocar na posição indicada!!!\n\n");
				system("pause");
				i--;
			}
		}
		else
		{
			if((y <= lvl-2) && (x <= lvl) && (player_str.map[x-1][y-1] == 0) && (player_str.map[x-1][y] == 0))
			{
				player_str.map[x-1][y-1]	= 5;
				player_str.map[x-1][y]		= 5;
				
				player_str.nav[ind][0]		= x-1;	player_str.nav[ind][1]		= y-1;
				player_str.nav[ind][2]		= x-1;	player_str.nav[ind][3]		= y;
				
				ind++;
				
				if(player == 1)
					game_data.player_1 = player_str;
				else
					game_data.player_2 = player_str;	
			}
			else
			{
				printf("\nNão é possivel colocar na posição indicada!!!\n\n");
				system("pause");
				i--;
			}
		}
	}
	
	for(i=0;i<ship_data.porta_aviao;i++)
	{
		set_nav_screen(player);
		
		printf("%d° Navio classe PORTA-AVIÃO\n\n",i+1);
		printf("[X] -> ");
		scanf("%d",&x);
		printf("[Y] -> ");
		scanf("%d",&y);
		printf("[Orientação -> 1-vetical, 2-horizontal] -> ");
		scanf("%d",&orientacao);

		if(orientacao == 1)
		{
			if((x <= lvl-3) && (y <= lvl-2) && (player_str.map[x-1][y-1] == 0) && (player_str.map[x][y-1] == 0) && (player_str.map[x+1][y-1] == 0) && (player_str.map[x+2][y-1] == 0) &&  (player_str.map[x-1][y] == 0) && (player_str.map[x][y] == 0) && (player_str.map[x+1][y] == 0) && (player_str.map[x+2][y] == 0))
			{
				player_str.map[x-1][y-1]	= 6;
				player_str.map[x][y-1]		= 6;
				player_str.map[x+1][y-1]	= 6;
				player_str.map[x+2][y-1]	= 6;
				player_str.map[x-1][y]		= 6;
				player_str.map[x][y]		= 6;
				player_str.map[x+1][y]		= 6;
				player_str.map[x+2][y]		= 6;
				
				player_str.nav[ind][0]		= x-1;	player_str.nav[ind][1]		= y-1;
				player_str.nav[ind][2]		= x;	player_str.nav[ind][3]		= y-1;
				player_str.nav[ind][4]		= x+1;	player_str.nav[ind][5]		= y-1;
				player_str.nav[ind][6]		= x+2;	player_str.nav[ind][7]		= y-1;
				
				player_str.nav[ind][8]		= x-1;	player_str.nav[ind][9]		= y;
				player_str.nav[ind][10]		= x;	player_str.nav[ind][11]		= y;
				player_str.nav[ind][12]		= x+1;	player_str.nav[ind][13]		= y;
				player_str.nav[ind][14]		= x+2;	player_str.nav[ind][15]		= y;
				
				ind++;
				
				if(player == 1)
					game_data.player_1 = player_str;
				else
					game_data.player_2 = player_str;	
			}
			else
			{
				printf("\nNão é possivel colocar na posição indicada!!!\n\n");
				system("pause");
				i--;
			}
		}
		else
		{
			if((y <= lvl-4) && (x <= lvl-2) && (player_str.map[x-1][y-1] == 0) && (player_str.map[x-1][y] == 0) && (player_str.map[x-1][y+1] == 0) && (player_str.map[x-1][y+2] == 0) && (player_str.map[x][y-1] == 0) && (player_str.map[x][y] == 0) && (player_str.map[x][y+1] == 0) && (player_str.map[x][y+2] == 0))
			{
				player_str.map[x-1][y-1]	= 6;
				player_str.map[x-1][y]		= 6;
				player_str.map[x-1][y+1]	= 6;
				player_str.map[x-1][y+2] 	= 6;
				player_str.map[x][y-1]		= 6;
				player_str.map[x][y]		= 6;
				player_str.map[x][y+1]		= 6;
				player_str.map[x][y+2]		= 6;
				
				player_str.nav[ind][0]		= x-1;	player_str.nav[ind][1]		= y-1;
				player_str.nav[ind][2]		= x-1;	player_str.nav[ind][3]		= y;
				player_str.nav[ind][4]		= x-1;	player_str.nav[ind][5]		= y+1;
				player_str.nav[ind][6]		= x-1;	player_str.nav[ind][7]		= y+2;
				
				player_str.nav[ind][8]		= x;	player_str.nav[ind][9]		= y-1;
				player_str.nav[ind][10]		= x;	player_str.nav[ind][11]		= y;
				player_str.nav[ind][12]		= x;	player_str.nav[ind][13]		= y+1;
				player_str.nav[ind][14]		= x;	player_str.nav[ind][15]		= y+2;
				
				ind++;
				
				if(player == 1)
					game_data.player_1 = player_str;
				else
					game_data.player_2 = player_str;	
			}
			else
			{
				printf("\nNão é possivel colocar na posição indicada!!!\n\n");
				system("pause");
				i--;
			}
		}
	}
	
	i=1;
	while(i!=0)
	{
		x = 1+(rand() % lvl);
		y = 1+(rand() % lvl);
		if(player_str.map[x][y] == 0)
		{
			player_str.map[x][y] = 9;
			i=0;
		}
	}
	if(player == 1)
		game_data.player_1 = player_str;
	else
		game_data.player_2 = player_str;
}

void game_AI_set_ship(int player)
{
	Player player_str;
	int i, j, x, y, orientacao;
	int ind = 0;
	int lvl = game_data.game_level;
	
	srand( (unsigned)time(NULL) );
	
	if(player == 1)
		player_str = game_data.player_1;
	else
		player_str = game_data.player_2;
	
	for(i=0;i<30;i++)
			for(j=0;j<30;j++)
			{
				player_str.map[i][j] = 0; 
				player_str.map[i][j] = 0;
				player_str.atk[i][j] = '~'; 
				player_str.atk[i][j] = '~';
			}
	
	for(i=0;i<ship_data.mina_naval;i++)
	{
		if(i==0)
		{
			x = rand() % lvl;
			y = rand() % lvl;
			if(x <= lvl && y <= lvl)
			{
				player_str.map[x][y]		= 1;
				
				player_str.nav[ind][0]		= x;
				player_str.nav[ind][1]		= y;
				y++;
				
				ind++;
			}
			else
			{
				i--;
			}
		}
		else
		{
			if(x <= lvl && y <= lvl)
			{
				player_str.map[x][y]		= 1;
				
				player_str.nav[ind][0]		= x;
				player_str.nav[ind][1]		= y;
				y++;
				ind++;
			}
			else
			{
				i--;
			}
		}
		
	}
	
	for(i=0;i<ship_data.corveta;i++)
	{
		x = 1 + (rand() % lvl);
		y = 1 + (rand() % lvl);
		orientacao = rand() % 1;

		if(orientacao == 0)
		{
			if((x <= lvl-2) && (y <= lvl) && (player_str.map[x-1][y-1] == 0) && (player_str.map[x][y-1] == 0))
			{
				player_str.map[x-1][y-1]	= 2;
				player_str.map[x][y-1]		= 2;
				
				player_str.nav[ind][0]	= x-1;	player_str.nav[ind][1]	= y-1;
				player_str.nav[ind][2]	= x;	player_str.nav[ind][3]	= y-1;
				
				ind++;
			}
			else
			{
				i--;
			}
		}
		else
		{
			if((y <= lvl-2) && (x <= lvl) && (player_str.map[x-1][y-1] == 0) && (player_str.map[x-1][y] == 0))
			{
				player_str.map[x-1][y-1]	= 2;
				player_str.map[x-1][y]		= 2;
				
				player_str.nav[ind][0]	= x-1;	player_str.nav[ind][1]	= y-1;
				player_str.nav[ind][2]	= x-1;	player_str.nav[ind][3]	= y;
				
				ind++;
			}
			else
			{
				i--;
			}
		}	
	}
		
	for(i=0;i<ship_data.contratorpediro;i++)
	{
		x = 1 + (rand() % lvl);
		y = 1 + (rand() % lvl);
		orientacao = rand() % 1;

		if(orientacao == 0)
		{
			if((x <= lvl-3) && (y <= lvl) && (player_str.map[x-1][y-1] == 0) && (player_str.map[x][y-1] == 0) && (player_str.map[x+1][y-1] == 0))
			{
				player_str.map[x-1][y-1]	= 3;
				player_str.map[x][y-1]		= 3;
				player_str.map[x+1][y-1]	= 3;
				
				player_str.nav[ind][0]		= x-1;	player_str.nav[ind][1]		= y-1;
				player_str.nav[ind][2]		= x;	player_str.nav[ind][3]		= y-1;
				player_str.nav[ind][4]		= x+1;	player_str.nav[ind][5]		= y-1;
				
				ind++;
			}
			else
			{
				i--;
			}
		}
		else
		{
			if((y <= lvl-3) && (x <= lvl) && (player_str.map[x-1][y-1] == 0) && (player_str.map[x-1][y] == 0) && (player_str.map[x-1][y+1] == 0))
			{
				player_str.map[x-1][y-1]	= 3;
				player_str.map[x-1][y]		= 3;
				player_str.map[x-1][y+1]	= 3;
				
				player_str.nav[ind][0]		= x-1;	player_str.nav[ind][1]		= y-1;
				player_str.nav[ind][2]		= x-1;	player_str.nav[ind][3]		= y;
				player_str.nav[ind][4]		= x-1;	player_str.nav[ind][5]		= y+1;	
				
				ind++;
			}
			else
			{
				i--;
			}
		}
	}
	
	for(i=0;i<ship_data.fragata;i++)
	{
		x = 1 + (rand() % lvl);
		y = 1 + (rand() % lvl);
		orientacao = rand() % 1;

		if(orientacao == 0)
		{
			if((x <= lvl-4) && (y <= lvl) && (player_str.map[x-1][y-1] == 0) && (player_str.map[x][y-1] == 0) && (player_str.map[x+1][y-1] == 0) && (player_str.map[x+2][y-1] == 0))
			{
				player_str.map[x-1][y-1]	= 4;
				player_str.map[x][y-1]		= 4;
				player_str.map[x+1][y-1]	= 4;
				player_str.map[x+2][y-1]	= 4;
				
				player_str.nav[ind][0]		= x-1;	player_str.nav[ind][1]	= y-1;
				player_str.nav[ind][2]		= x;	player_str.nav[ind][3]	= y-1;
				player_str.nav[ind][4]		= x+1;	player_str.nav[ind][5]	= y-1;
				player_str.nav[ind][6]		= x+2;	player_str.nav[ind][7]	= y-1;
				
				ind++;
			}
			else
			{
				i--;
			}
		}
		else
		{
			if((x <= lvl) && (y <= lvl-4) && (player_str.map[x-1][y-1] == 0) && (player_str.map[x-1][y] == 0) && (player_str.map[x-1][y+1] == 0) && (player_str.map[x-1][y+2] == 0))
			{
				player_str.map[x-1][y-1]	= 4;
				player_str.map[x-1][y]		= 4;
				player_str.map[x-1][y+1]	= 4;
				player_str.map[x-1][y+2]	= 4;
				
				player_str.nav[ind][0]		= x-1;	player_str.nav[ind][1]	= y-1;
				player_str.nav[ind][2]		= x-1;	player_str.nav[ind][3]	= y;
				player_str.nav[ind][4]		= x-1;	player_str.nav[ind][5]	= y+1;
				player_str.nav[ind][6]		= x-1;	player_str.nav[ind][7]	= y+2;
				
				ind++;	
			}
			else
			{
				i--;
			}
		}
	}

	for(i=0;i<ship_data.submarino;i++)
	{
		x = 1 + (rand() % lvl);
		y = 1 + (rand() % lvl);
		orientacao = rand() % 1;

		if(orientacao == 0)
		{
			if((x <= lvl-2) && (y <= lvl) && (player_str.map[x-1][y-1] == 0) && (player_str.map[x][y-1] == 0))
			{
				player_str.map[x-1][y-1]	= 5;
				player_str.map[x][y-1]		= 5;
				
				player_str.nav[ind][0]		= x-1;	player_str.nav[ind][1]		= y-1;
				player_str.nav[ind][2]		= x;	player_str.nav[ind][3]		= y-1;
				
				ind++;
			}
			else
			{
				i--;
			}
		}
		else
		{
			if((y <= lvl-2) && (x <= lvl) && (player_str.map[x-1][y-1] == 0) && (player_str.map[x-1][y] == 0))
			{
				player_str.map[x-1][y-1]	= 5;
				player_str.map[x-1][y]		= 5;
				
				player_str.nav[ind][0]		= x-1;	player_str.nav[ind][1]		= y-1;
				player_str.nav[ind][2]		= x-1;	player_str.nav[ind][3]		= y;
				
				ind++;	
			}
			else
			{
				i--;
			}
		}
	}
	
	for(i=0;i<ship_data.porta_aviao;i++)
	{
		x = 1 + (rand() % lvl);
		y = 1 + (rand() % lvl);
		orientacao = rand() % 1;

		if(orientacao == 0)
		{
			if((x <= lvl-3) && (y <= lvl-2) && (player_str.map[x-1][y-1] == 0) && (player_str.map[x][y-1] == 0) && (player_str.map[x+1][y-1] == 0) && (player_str.map[x+2][y-1] == 0) &&  (player_str.map[x-1][y] == 0) && (player_str.map[x][y] == 0) && (player_str.map[x+1][y] == 0) && (player_str.map[x+2][y] == 0))
			{
				player_str.map[x-1][y-1]	= 6;
				player_str.map[x][y-1]		= 6;
				player_str.map[x+1][y-1]	= 6;
				player_str.map[x+2][y-1]	= 6;
				player_str.map[x-1][y]		= 6;
				player_str.map[x][y]		= 6;
				player_str.map[x+1][y]		= 6;
				player_str.map[x+2][y]		= 6;
				
				player_str.nav[ind][0]		= x-1;	player_str.nav[ind][1]		= y-1;
				player_str.nav[ind][2]		= x;	player_str.nav[ind][3]		= y-1;
				player_str.nav[ind][4]		= x+1;	player_str.nav[ind][5]		= y-1;
				player_str.nav[ind][6]		= x+2;	player_str.nav[ind][7]		= y-1;
				
				player_str.nav[ind][8]		= x-1;	player_str.nav[ind][9]		= y;
				player_str.nav[ind][10]		= x;	player_str.nav[ind][11]		= y;
				player_str.nav[ind][12]		= x+1;	player_str.nav[ind][13]		= y;
				player_str.nav[ind][14]		= x+2;	player_str.nav[ind][15]		= y;
				
				ind++;	
			}
			else
			{
				i--;
			}
		}
		else
		{
			if((y <= lvl-4) && (x <= lvl-2) && (player_str.map[x-1][y-1] == 0) && (player_str.map[x-1][y] == 0) && (player_str.map[x-1][y+1] == 0) && (player_str.map[x-1][y+2] == 0) && (player_str.map[x][y-1] == 0) && (player_str.map[x][y] == 0) && (player_str.map[x][y+1] == 0) && (player_str.map[x][y+2] == 0))
			{
				player_str.map[x-1][y-1]	= 6;
				player_str.map[x-1][y]		= 6;
				player_str.map[x-1][y+1]	= 6;
				player_str.map[x-1][y+2] 	= 6;
				player_str.map[x][y-1]		= 6;
				player_str.map[x][y]		= 6;
				player_str.map[x][y+1]		= 6;
				player_str.map[x][y+2]		= 6;
				
				player_str.nav[ind][0]		= x-1;	player_str.nav[ind][1]		= y-1;
				player_str.nav[ind][2]		= x-1;	player_str.nav[ind][3]		= y;
				player_str.nav[ind][4]		= x-1;	player_str.nav[ind][5]		= y+1;
				player_str.nav[ind][6]		= x-1;	player_str.nav[ind][7]		= y+2;
				
				player_str.nav[ind][8]		= x;	player_str.nav[ind][9]		= y-1;
				player_str.nav[ind][10]		= x;	player_str.nav[ind][11]		= y;
				player_str.nav[ind][12]		= x;	player_str.nav[ind][13]		= y+1;
				player_str.nav[ind][14]		= x;	player_str.nav[ind][15]		= y+2;
				
				ind++;	
			}
			else
			{
				i--;
			}
		}
	}
	
	i=1;
	while(i!=0)
	{
		x = 1+(rand() % lvl);
		y = 1+(rand() % lvl);
		if(player_str.map[x][y] == 0)
		{
			player_str.map[x][y] = 9;
			i=0;
		}
	}
	if(player == 1)
		game_data.player_1 = player_str;
	else
		game_data.player_2 = player_str;
}
