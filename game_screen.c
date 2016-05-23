#include <stdio.h>
#include <stdlib.h>
#include "dep.h"
///Variaveis globais
extern Game_dat game_data;
extern Ship ship_data;
///Funções
void set_nav_screen(int player_num)
{
	int i, j;
	int lvl = game_data.game_level;
	/// Tela de posicionamento das embarcações
	system("cls");
	/***************************/
	textcolor(WHITE);
	printf("\t");
	for(i=0; i<lvl/2; i++)
		printf("   ");
	printf("PLAYER %d",player_num);
	for(i=0; i<lvl/2; i++)
		printf("   ");
	printf("\n\n");
	/***************************/
	printf("X\n");
	for(i=0;i<lvl;i++)
	{
		textcolor(WHITE);
		printf("%d\t- ",i+1);
		for(j=0;j<lvl;j++)
			if(player_num == 1)
			{
				if(game_data.player_1.map[i][j] == 0)
					textcolor(GREEN);
				else
					textcolor(RED);
				printf("[%d]",game_data.player_1.map[i][j]);
			}
			else
			{
				if(game_data.player_2.map[i][j] == 0)
					textcolor(GREEN);
				else
					textcolor(RED);
				printf("[%d]",game_data.player_2.map[i][j]);	
			}
		printf("\n");
	}
	/***************************/
	textcolor(WHITE);
	printf("\t  ");
	for(i=0; i<lvl;i++)
		printf(" | ");
	printf("\n");
	/***************************/
	printf("\t  ");
	for(i=0; i<lvl; i++)
		if(i<9)
			printf(" %d ",i+1);
		else
			if(i==9)
				printf(" %d ",i+1);
			else
				printf("%d ",i+1);
	
	printf(" - Y\n\n");
	/***************************/
}

void bat_nav_screen(int player_num)
{
	int i, j;
	int lvl = game_data.game_level;
	Player player1, player2;
	player1 = game_data.player_1;
	player2 = game_data.player_2;
	int ind = 0, in = 0, va = 0;
	
	
	system("cls");
	/***************************/
	textcolor(CYAN);
	printf("\t");
	for(i=0; i<lvl; i++)
		printf("---");
	printf("PLAYER %d",player_num);
	for(i=0; i<lvl; i++)
		printf("---");
	printf("\n\n");			
	/***************************/
	for(i=0;i<lvl;i++)
	{
		textcolor(WHITE);
		printf("%d\t",i+1);
		
		for(j=0;j<lvl;j++)
			if(game_data.player_1.atk[i][j] == '~')
			{
				textcolor(LIGHT_BLUE);
				printf("[%c]",game_data.player_1.atk[i][j]);
			}
			else
			{
				textcolor(RED);
				if(game_data.player_1.atk[i][j] == 'O')
					textcolor(WHITE);
				printf("[%c]",game_data.player_1.atk[i][j]);
			}
		
		textcolor(WHITE);
		printf("  |  ");
		
		for(j=0;j<lvl;j++)
			if(game_data.player_2.atk[i][j] == '~')
			{
				textcolor(LIGHT_BLUE);
				printf("[%c]",game_data.player_2.atk[i][j]);
			}
			else
			{
				textcolor(RED);
				if(game_data.player_2.atk[i][j] == 'O')
					textcolor(WHITE);
				printf("[%c]",game_data.player_2.atk[i][j]);
			}
		textcolor(WHITE);	
		printf("\t%d\n",i+1);
	}
	/***************************/
	textcolor(WHITE);
	printf("\t");
	for(i=0; i<lvl;i++)
		printf(" | ");
	printf("  |  ");
	for(i=0; i<lvl;i++)
		printf(" | ");
	printf("\n");
	/***************************/
	printf("\t");
	for(i=0; i<lvl; i++)
		if(i<9)
			printf(" %d ",i+1);
		else
			if(i==9)
				printf(" %d ",i+1);
			else
				printf("%d ",i+1);

	printf(" |  ");
	
	for(i=0; i<lvl; i++)
		if(i<9)
			printf(" %d ",i+1);
		else
			if(i==9)
				printf(" %d ",i+1);
			else
				printf("%d ",i+1);
			
	printf(" - Y\n\n");
	for(i=0;i<5;i++)
	{
		/***********************************/
		va = 0;
		/***********************************/
		if(i<ship_data.mina_naval)
		{
			textcolor(GREEN);
			if(player1.atk[ player1.nav[i][0] ][ player1.nav[i][1] ] == 'X')
				textcolor(LIGHT_RED);
			printf("%d° Mina Naval    |",i+1);
			ind++;
		}
		else
			printf("                  ");
		/***********************************/
		va += ship_data.mina_naval;
		/***********************************/	
		if(i<ship_data.corveta)
		{
			textcolor(GREEN);
			if(player1.atk[ player1.nav[i+va][0] ][ player1.nav[i+va][1] ] == 'X' 
			&& player1.atk[ player1.nav[i+va][2] ][ player1.nav[i+va][3] ] == 'X')
				textcolor(LIGHT_RED);
			printf("%d° Corveta    |",i+1);
			ind++;
		}
		else
			printf("               ");
		/***********************************/	
		va += ship_data.corveta;
		/***********************************/	
		if(i<ship_data.contratorpediro)
		{
			textcolor(GREEN);
			if(player1.atk[ player1.nav[i+va][0] ][ player1.nav[i+va][1] ] == 'X' 
			&& player1.atk[ player1.nav[i+va][2] ][ player1.nav[i+va][3] ] == 'X' 
			&& player1.atk[ player1.nav[i+va][4] ][ player1.nav[i+va][5] ] == 'X')
				textcolor(LIGHT_RED);
			printf("%d° Contratorpedeiro    |",i+1);
			ind++;
		}
		else
			printf("                        ");
		/***********************************/
		va += ship_data.contratorpediro;
		/***********************************/
		if(i<ship_data.fragata)
		{
			textcolor(GREEN);
			if(player1.atk[ player1.nav[i+va][0] ][ player1.nav[i+va][1] ] == 'X' 
			&& player1.atk[ player1.nav[i+va][2] ][ player1.nav[i+va][3] ] == 'X' 
			&& player1.atk[ player1.nav[i+va][4] ][ player1.nav[i+va][5] ] == 'X'  
			&& player1.atk[ player1.nav[i+va][6] ][ player1.nav[i+va][7] ] == 'X')
				textcolor(LIGHT_RED);
			printf("%d° Fragata      ||\t",i+1);
			ind++;
		}
		else
			printf("                ||\t");
		/***********************************/
		va += ship_data.fragata;
		/***********************************/
		/*          PLAYER 2               */
		/***********************************/
		va = 0;
		/***********************************/
		if(i<ship_data.mina_naval)
		{
			textcolor(GREEN);
			if(player2.atk[ player2.nav[i][0] ][ player2.nav[i][1] ] == 'X')
				textcolor(LIGHT_RED);
			printf("%d° Mina Naval    |",i+1);
		}
		else
			printf("                  ");
		/***********************************/
		va += ship_data.mina_naval;
		/***********************************/	
		if(i<ship_data.corveta)
		{
			textcolor(GREEN);
			if(player2.atk[ player2.nav[i+va][0] ][ player2.nav[i+va][1] ] == 'X' 
			&& player2.atk[ player2.nav[i+va][2] ][ player2.nav[i+va][3] ] == 'X')
				textcolor(LIGHT_RED);
			printf("%d° Corveta    |",i+1);
		}
		else
			printf("               ");
		/***********************************/	
		va += ship_data.corveta;
		/***********************************/	
		if(i<ship_data.contratorpediro)
		{
			textcolor(GREEN);
			if(player2.atk[ player2.nav[i+va][0] ][ player2.nav[i+va][1] ] == 'X' 
			&& player2.atk[ player2.nav[i+va][2] ][ player2.nav[i+va][3] ] == 'X' 
			&& player2.atk[ player2.nav[i+va][4] ][ player2.nav[i+va][5] ] == 'X')
				textcolor(LIGHT_RED);
			printf("%d° Contratorpedeiro    |",i+1);
		}
		else
			printf("                        ");
		/***********************************/
		va += ship_data.contratorpediro;
		/***********************************/
		if(i<ship_data.fragata)
		{
			textcolor(GREEN);
			if(player2.atk[ player2.nav[i+va][0] ][ player2.nav[i+va][1] ] == 'X' 
			&& player2.atk[ player2.nav[i+va][2] ][ player2.nav[i+va][3] ] == 'X' 
			&& player2.atk[ player2.nav[i+va][4] ][ player2.nav[i+va][5] ] == 'X'  
			&& player2.atk[ player2.nav[i+va][6] ][ player2.nav[i+va][7] ] == 'X')
				textcolor(LIGHT_RED);
			printf("%d° Fragata\n",i+1);
		}
		else
			printf("\n");
	}
	
	if(ship_data.mina_naval>5)
	{
		ind += 5;
		in   = ind;
	}
	
	for(i=0;i<5;i++)
	{
		/***********************************/
		ind = in;
		/***********************************/
		if(i+5<ship_data.mina_naval)
		{
			textcolor(GREEN);
			if(player1.atk[ player1.nav[i][0] ][ player1.nav[i][1] ] == 'X')
				textcolor(LIGHT_RED);
			if(i==9)
				printf("%d° Mina Naval    |",0);
			else
				printf("%d° Mina Naval    |",i+6);
			textcolor(GREEN);
		}
		else
			printf("                  ");
		/***********************************/
		if(i<ship_data.submarino)
		{
			textcolor(GREEN);
			if(player1.atk[ player1.nav[ind+i][0] ][ player1.nav[ind+i][1] ] == 'X' && player1.atk[ player1.nav[ind+i][2] ][ player1.nav[ind+i][3] ] == 'X')
				textcolor(LIGHT_RED);
			printf("%d° Submarino  |",i+1);
		}
		else
			printf("               ");
		/***********************************/
		ind =+ ship_data.submarino;
		/***********************************/
		if(i<ship_data.porta_aviao)
		{
			textcolor(GREEN);
			if(player1.atk[ player1.nav[ind+i][0] ][ player1.nav[ind+i][1] ] == 'X' 
			&& player1.atk[ player1.nav[ind+i][2] ][ player1.nav[ind+i][3] ] == 'X' 
			&& player1.atk[ player1.nav[ind+i][4] ][ player1.nav[ind+i][5] ] == 'X' 
			&& player1.atk[ player1.nav[ind+i][6] ][ player1.nav[ind+i][7] ] == 'X' 
			&& player1.atk[ player1.nav[ind+i][8] ][ player1.nav[ind+i][9] ] == 'X' 
			&& player1.atk[ player1.nav[ind+i][10] ][ player1.nav[ind+i][11] ] == 'X' 
			&& player1.atk[ player1.nav[ind+i][12] ][ player1.nav[ind+i][13] ] == 'X' 
			&& player1.atk[ player1.nav[ind+i][14] ][ player1.nav[ind+i][15] ] == 'X')
				textcolor(LIGHT_RED);
			printf("%d° Porta-Avião                          ||\t",i+1);
		}
		else
			printf("                                        ||\t");
		/***********************************/
		ind = in;
		/***********************************/
		if(i+5<ship_data.mina_naval)
		{
			textcolor(GREEN);
			if(player2.atk[ player2.nav[i][0] ][ player2.nav[i][1] ] == 'X')
				textcolor(LIGHT_RED);
			if(i==9)
				printf("%d° Mina Naval    |",0);
			else
				printf("%d° Mina Naval    |",i+6);
			textcolor(GREEN);
		}
		else
			printf("                  ");
		/***********************************/
		if(i<ship_data.submarino)
		{
			textcolor(GREEN);
			if(player2.atk[ player2.nav[ind+i][0] ][ player2.nav[ind+i][1] ] == 'X' && player2.atk[ player2.nav[ind+i][2] ][ player2.nav[ind+i][3] ] == 'X')
				textcolor(LIGHT_RED);
			printf("%d° Submarino  |",i+1);
		}
		else
			printf("              ");
		/***********************************/
		ind += ship_data.submarino;
		/***********************************/
		if(i<ship_data.porta_aviao)
		{
			textcolor(GREEN);
			if(player2.atk[ player2.nav[ind+i][0] ][ player2.nav[ind+i][1] ] == 'X' 
			&& player2.atk[ player2.nav[ind+i][2] ][ player2.nav[ind+i][3] ] == 'X' 
			&& player2.atk[ player2.nav[ind+i][4] ][ player2.nav[ind+i][5] ] == 'X' 
			&& player2.atk[ player2.nav[ind+i][6] ][ player2.nav[ind+i][7] ] == 'X' 
			&& player2.atk[ player2.nav[ind+i][8] ][ player2.nav[ind+i][9] ] == 'X' 
			&& player2.atk[ player2.nav[ind+i][10] ][ player2.nav[ind+i][11] ] == 'X' 
			&& player2.atk[ player2.nav[ind+i][12] ][ player2.nav[ind+i][13] ] == 'X' 
			&& player2.atk[ player2.nav[ind+i][14] ][ player2.nav[ind+i][15] ] == 'X')
				textcolor(LIGHT_RED);
			printf("%d° Porta-Avião\n",i+1);
		}
		else
			printf("\n");
		/***********************************/
	}
	textcolor(WHITE);
}
