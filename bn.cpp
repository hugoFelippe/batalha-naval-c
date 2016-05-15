#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <windows.h>
#define TF 15

enum DOS_COLORS {
    BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN,
    LIGHT_GRAY, DARK_GRAY, LIGHT_BLUE, LIGHT_GREEN, LIGHT_CYAN,
    LIGHT_RED, LIGHT_MAGENTA, YELLOW, WHITE
};

void textcolor (DOS_COLORS iColor)
{
    HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    BOOL b = GetConsoleScreenBufferInfo(hl, &bufferInfo);
    bufferInfo.wAttributes &= 0x00F0;
    SetConsoleTextAttribute (hl, bufferInfo.wAttributes |= iColor);
}

struct Player
{
	int		id;
	int		acert;
	char	nome[100];
	int		map[TF][TF];
	char	atk[TF][TF];
};

void pos_embarc(Player player_str);
void refresh_screen(int type, int player_number);

Player player1, player2;

int main()
{
	int i, j, x, y, end = 0, p = 1;
	player1.acert = 0;
	player2.acert = 0;
	setlocale(LC_ALL, "Portuguese");
	textcolor(WHITE);
	printf("..........................................BATATA NAVAL.........................................\n\n");
	textcolor(LIGHT_BLUE);
	printf("[-][-][-][-][-][-][-][-][-][-][-][-][-][-][-]  |  [-][-][-][-][-][-][-][-][-][-][-][-][-][-][-]\n");
	printf("[-][-][-][-][-][-][-][-][-][-][-][-][-][-][-]  |  [-][-][-][-][-][-][-][-][-][-][-][-][-][-][-]\n");
	printf("[-][-][-][-][-][-][-][-][-][-][-][-][-][-][-]  |  [-][-][-][-][-][-][-][-][-][-][-][-][-][-][-]\n");
	printf("[-][-][-][-][-][-][-][-][-][-][-][-][-][-][-]  |  [-][-][-][-][-][-][-][-][-][-][-][-][-][-][-]\n");
	printf("[-][-][-][-][-][-][-][-][-][-][-][-][-][-][-]  |  [-][-][-][-][-][-][-][-][-][-][-][-][-][-][-]\n");
	printf("[-][-][-][-][-][-][-][-][-][-][-][-][-][-][-]  |  [-][-][-][-][-][-][-][-][-][-][-][-][-][-][-]\n");
	printf("[-][-][-][-][-][-][-][-][-][-][-][-][-][-][-]  |  [-][-][-][-][-][-][-][-][-][-][-][-][-][-][-]\n");
	printf("[-][-][-][-][-][-][-][-][-][-][-][-][-][-][-]  |  [-][-][-][-][-][-][-][-][-][-][-][-][-][-][-]\n");
	printf("[-][-][-][-][-][-][-][-][-][-][-][-][-][-][-]  |  [-][-][-][-][-][-][-][-][-][-][-][-][-][-][-]\n");
	printf("[-][-][-][-][-][-][-][-][-][-][-][-][-][-][-]  |  [-][-][-][-][-][-][-][-][-][-][-][-][-][-][-]\n");
	printf("[-][-][-][-][-][-][-][-][-][-][-][-][-][-][-]  |  [-][-][-][-][-][-][-][-][-][-][-][-][-][-][-]\n");
	printf("[-][-][-][-][-][-][-][-][-][-][-][-][-][-][-]  |  [-][-][-][-][-][-][-][-][-][-][-][-][-][-][-]\n");
	printf("[-][-][-][-][-][-][-][-][-][-][-][-][-][-][-]  |  [-][-][-][-][-][-][-][-][-][-][-][-][-][-][-]\n");
	printf("[-][-][-][-][-][-][-][-][-][-][-][-][-][-][-]  |  [-][-][-][-][-][-][-][-][-][-][-][-][-][-][-]\n");
	printf("[-][-][-][-][-][-][-][-][-][-][-][-][-][-][-]  |  [-][-][-][-][-][-][-][-][-][-][-][-][-][-][-]\n\n");
	textcolor(WHITE);
	printf("...........................................START GAME..........................................\n\n");
	textcolor(GREEN);
	printf("Player 1 -> ");
	gets(player1.nome);
	printf("Player 2 -> ");
	gets(player2.nome);
	
	player1.id = 1;
	player2.id = 2;
	
	for(i=0;i<TF;i++)
		for(j=0;j<TF;j++)
		{
			player1.map[i][j] = 0; 
			player2.map[i][j] = 0;
		}
	for(i=0;i<TF;i++)
		for(j=0;j<TF;j++)
		{
			player1.atk[i][j] = ' '; 
			player2.atk[i][j] = ' ';
		}
		
	textcolor(WHITE);
	pos_embarc(player1);
	pos_embarc(player2);
	
	
	printf("-----------GAME STARTED-----------\n\n");
	
	while(end!=1)
	{
		refresh_screen(2,p);
		
		printf("\nAtacar: \n");
		printf("[X] ->");
		scanf("%d",&x);
		printf("[Y] ->");
		scanf("%d",&y);
		
		if(p == 1)
		{
			if(player2.map[x-1][y-1] == 0)
				player2.atk[x-1][y-1] = 'O';
			else
			{
				player2.atk[x-1][y-1] = 'X';
				player1.acert++;
			}
			
			refresh_screen(2,p);
			
			if(player1.acert == 21)
				end = 1;
			
			p = 2;
			system("cls");
		}
		else
			if(p == 2)
			{
				if(player1.map[x-1][y-1] == 0)
					player1.atk[x-1][y-1] = 'O';
				else
				{
					player1.atk[x-1][y-1] = 'X';
					player2.acert++;
				}
				
				refresh_screen(2,0);
				
				if(player1.acert == 21)
					end = 1;
				else
				{
					p = 1;
					system("cls");
				}
			}
		
	}
	
	if(player1.acert == 21)
		printf("\n\n\n\t\t%s - Venceu\n\n\n\n",player1.nome);
	else
		if(player2.acert == 21)
			printf("\n\n\n\t\t%s - Venceu\n\n\n\n", player2.nome);
			
	getch();
}

/*
 *
 * @refresh_screen(int type, int player_number)
 * #	Executa o processo de posicionamento das embarcações.
 * #
 * #	&vars:
 * #	player_str
 * #		Informar qual a variavel do player;
 * 
 */
void pos_embarc(Player player_str)
{
	int i, x, y, orientacao;
	for(i=0;i<4;i++)
	{
		refresh_screen(1, player_str.id);
		printf("%d° BOIA\n\n",i+1);
		printf("[X] -> ");
		scanf("%d",&x);
		printf("[Y] -> ");
		scanf("%d",&y);
		player_str.map[x-1][y-1] = 1;
		
		if(player_str.id == 1)
			player1 = player_str;
		else
			player2 = player_str;
	}
	
	for(i=0;i<3;i++)
	{
		refresh_screen(1, player_str.id);
		
		printf("%d° Navio classe CORVETA\n\n",i+1);
		printf("[X] -> ");
		scanf("%d",&x);
		printf("[Y] -> ");
		scanf("%d",&y);
		printf("[Orientação -> 1-vetical, 2-horizontal] -> ");
		scanf("%d",&orientacao);
		printf("\n");

		if(orientacao == 1)
		{
			if((x <= TF-2) && (player_str.map[x-1][y-1] == 0) && (player_str.map[x][y-1] == 0))
			{
				player_str.map[x-1][y-1]	= 2;
				player_str.map[x][y-1]		= 2;
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
			if((y <= TF-2) && (player_str.map[x-1][y-1] == 0) && (player_str.map[x-1][y] == 0))
			{
				player_str.map[x-1][y-1]	= 2;
				player_str.map[x-1][y]		= 2;	
			}
			else
			{
				printf("\nNão é possivel colocar na posição indicada!!!\n\n");
				system("pause");
				i--;
			}
		}
		if(player_str.id == 1)
			player1 = player_str;
		else
			player2 = player_str;
	}
	
	for(i=0;i<2;i++)
	{
		refresh_screen(1, player_str.id);
		
		printf("%d° Navio classe CONTRATORPEDEIRO\n\n",i+1);
		printf("[X] -> ");
		scanf("%d",&x);
		printf("[Y] -> ");
		scanf("%d",&y);
		printf("[Orientação -> 1-vetical, 2-horizontal] -> ");
		scanf("%d",&orientacao);
		printf("\n");

		if(orientacao == 1)
		{
			if((x <= TF-3) && (player_str.map[x-1][y-1] == 0) && (player_str.map[x][y-1] == 0) && (player_str.map[x+1][y-1] == 0))
			{
				player_str.map[x-1][y-1]	= 3;
				player_str.map[x][y-1]		= 3;
				player_str.map[x+1][y-1]	= 3;
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
			if((y <= TF-3) && (player_str.map[x-1][y-1] == 0) && (player_str.map[x-1][y] == 0) && (player_str.map[x-1][y+1] == 0))
			{
				player_str.map[x-1][y-1]	= 3;
				player_str.map[x-1][y]		= 3;
				player_str.map[x-1][y+1]	= 3;	
			}
			else
			{
				printf("\nNão é possivel colocar na posição indicada!!!\n\n");
				system("pause");
				i--;
			}
		}
		if(player_str.id == 1)
			player1 = player_str;
		else
			player2 = player_str;
	}
	
	for(i=0;i<1;i++)
	{
		refresh_screen(1, player_str.id);
		
		printf("%d° Navio classe FRAGATA\n\n",i+1);
		printf("[X] -> ");
		scanf("%d",&x);
		printf("[Y] -> ");
		scanf("%d",&y);
		printf("[Orientação -> 1-vetical, 2-horizontal] -> ");
		scanf("%d",&orientacao);
		printf("\n");

		if(orientacao == 1)
		{
			if((x <= TF-4) && (player_str.map[x-1][y-1] == 0) && (player_str.map[x][y-1] == 0) && (player_str.map[x+1][y-1] == 0) && (player_str.map[x+2][y-1] == 0))
			{
				player_str.map[x-1][y-1]	= 4;
				player_str.map[x][y-1]		= 4;
				player_str.map[x+1][y-1]	= 4;
				player_str.map[x+2][y-1]	= 4;
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
			if((y <= TF-4) && (player_str.map[x-1][y-1] == 0) && (player_str.map[x-1][y] == 0) && (player_str.map[x-1][y+1] == 0) && (player_str.map[x-1][y+2] == 0))
			{
				player_str.map[x-1][y-1]	= 4;
				player_str.map[x-1][y]		= 4;
				player_str.map[x-1][y+1]	= 4;
				player_str.map[x-1][y+2]	= 4;	
			}
			else
			{
				printf("\nNão é possivel colocar na posição indicada!!!\n\n");
				system("pause");
				i--;
			}
		}
		if(player_str.id == 1)
			player1 = player_str;
		else
			player2 = player_str;
	}
	
	for(i=0;i<1;i++)
	{
		refresh_screen(1, player_str.id);
		
		printf("%d° Navio classe SUBMARINO\n\n",i+1);
		printf("[X] -> ");
		scanf("%d",&x);
		printf("[Y] -> ");
		scanf("%d",&y);
		printf("[Orientação -> 1-vetical, 2-horizontal] -> ");
		scanf("%d",&orientacao);
		printf("\n");

		if(orientacao == 1)
		{
			if((x <= TF-2) && (player_str.map[x-1][y-1] == 0) && (player_str.map[x][y-1] == 0))
			{
				player_str.map[x-1][y-1]	= 5;
				player_str.map[x][y-1]		= 5;
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
			if((y <= TF-2) && (player_str.map[x-1][y-1] == 0) && (player_str.map[x-1][y] == 0))
			{
				player_str.map[x-1][y-1]	= 5;
				player_str.map[x-1][y]		= 5;	
			}
			else
			{
				printf("\nNão é possivel colocar na posição indicada!!!\n\n");
				system("pause");
				i--;
			}
		}
		if(player_str.id == 1)
			player1 = player_str;
		else
			player2 = player_str;
	}
	
	for(i=0;i<1;i++)
	{
		refresh_screen(1, player_str.id);
		
		printf("%d° Navio classe PORTA-AVIÃO\n\n",i+1);
		printf("[X] -> ");
		scanf("%d",&x);
		printf("[Y] -> ");
		scanf("%d",&y);
		printf("[Orientação -> 1-vetical, 2-horizontal] -> ");
		scanf("%d",&orientacao);
		printf("\n");

		if(orientacao == 1)
		{
			if((x <= TF-3) && (y <= TF-2) && (player_str.map[x-1][y-1] == 0) && (player_str.map[x][y-1] == 0) && (player_str.map[x+1][y-1] == 0) &&  (player_str.map[x-1][y] == 0) && (player_str.map[x][y] == 0) && (player_str.map[x+1][y] == 0))
			{
				player_str.map[x-1][y-1]	= 6;
				player_str.map[x][y-1]		= 6;
				player_str.map[x+1][y-1]	= 6;
				player_str.map[x-1][y]		= 6;
				player_str.map[x][y]		= 6;
				player_str.map[x+1][y]		= 6;
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
			if((y <= TF-3) && (x <= TF-2) && (player_str.map[x-1][y-1] == 0) && (player_str.map[x-1][y] == 0) && (player_str.map[x-1][y+1] == 0) && (player_str.map[x][y-1] == 0) && (player_str.map[x][y] == 0) && (player_str.map[x][y+1] == 0))
			{
				player_str.map[x-1][y-1]	= 6;
				player_str.map[x-1][y]		= 6;
				player_str.map[x-1][y+1]	= 6;
				player_str.map[x][y-1]		= 6;
				player_str.map[x][y]		= 6;
				player_str.map[x][y+1]		= 6;
			}
			else
			{
				printf("\nNão é possivel colocar na posição indicada!!!\n\n");
				system("pause");
				i--;
			}
		}
		if(player_str.id == 1)
			player1 = player_str;
		else
			player2 = player_str;
	}
}

/*
 *
 * @refresh_screen(int type, int player_number)
 * #	Faz a impressão de da tela, atualizando as informações.
 * #
 * #	&vars:
 * #	type
 * #	{
 * #		Pode ser:
 * #			1 -Tela com o mapa de localização das embarcações;
 * #			2 -Tela de ataque;
 * #	}
 * #	player_number
 * #		Informar se é o player 1 ou 2;
 * 
 */
void refresh_screen(int type, int player_number)
{
	int i, j;
	if(type == 1)
	{
		///Refresh screen
		system("cls");
		textcolor(WHITE);
		printf("\t");
		for(i=0; i<TF/2; i++)
			printf("---");
		printf("PLAYER %d",player_number);
		for(i=0; i<TF/2; i++)
			printf("---");
		printf("\n\n");
		
		
		printf("X\n");
		for(i=0;i<TF;i++)
		{
			textcolor(WHITE);
			printf("%d\t- ",i+1);
			for(j=0;j<TF;j++)
				if(player_number == 1)
				{
					if(player1.map[i][j] == 0)
						textcolor(GREEN);
					else
						textcolor(RED);
					printf("[%d]",player1.map[i][j]);
				}
				else
				{
					if(player2.map[i][j] == 0)
						textcolor(GREEN);
					else
						textcolor(RED);
					printf("[%d]",player2.map[i][j]);	
				}
			printf("\n");
		}
		
		textcolor(WHITE);
		printf("\t  ");
		for(i=0; i<TF;i++)
			printf(" | ");
		printf("\n");
		
		printf("\t  ");
		for(i=0; i<TF; i++)
			if(i<9)
				printf(" %d ",i+1);
			else
				if(i==9)
					printf(" %d ",i+1);
				else
					printf("%d ",i+1);
		printf(" - Y\n\n");
		
	}
	else
		if(type == 2)
		{
			system("cls");
			textcolor(CYAN);
			printf("\t");
			for(i=0; i<TF; i++)
				printf("---");
			printf("PLAYER %d",player_number);
			for(i=0; i<TF; i++)
				printf("---");
			printf("\n\n");
			
			textcolor(WHITE);
			printf("\t");
			for(i=0; i<(TF-1)/2; i++)
				printf("---");
			printf("PLAYER 1----");
			for(i=0; i<(TF-2)/2; i++)
				printf("--");
			printf("  |  ");
			for(i=0; i<(TF-1)/2; i++)
				printf("---");
			printf("PLAYER 2----");
			for(i=0; i<(TF-2)/2; i++)
				printf("--");
			printf("\n");
			
			
			for(i=0;i<TF;i++)
			{
				textcolor(WHITE);
				printf("%d\t",i+1);
				
				for(j=0;j<TF;j++)
					if(player1.atk[i][j] == ' ')
					{
						textcolor(LIGHT_BLUE);
						printf("[%c]",player1.atk[i][j]);
					}
					else
					{
						textcolor(RED);
						printf("[%c]",player1.atk[i][j]);
					}
				
				textcolor(WHITE);
				printf("  |  ");
				
				for(j=0;j<TF;j++)
					if(player2.atk[i][j] == ' ')
					{
						textcolor(LIGHT_BLUE);
						printf("[%c]",player2.atk[i][j]);
					}
					else
					{
						textcolor(RED);
						printf("[%c]",player2.atk[i][j]);
					}
						
				printf("\n");
			}
			
			textcolor(WHITE);
			printf("\t");
			for(i=0; i<TF;i++)
				printf(" | ");
			printf("  |  ");
			for(i=0; i<TF;i++)
				printf(" | ");
			printf("\n");
			
			printf("\t");
			for(i=0; i<TF; i++)
				if(i<9)
					printf(" %d ",i+1);
				else
					if(i==9)
						printf(" %d ",i+1);
					else
						printf("%d ",i+1);
	
			printf(" |  ");
			
			for(i=0; i<TF; i++)
				if(i<9)
					printf(" %d ",i+1);
				else
					if(i==9)
						printf(" %d ",i+1);
					else
						printf("%d ",i+1);
					
			printf(" - Y\n\n");
		}
}
