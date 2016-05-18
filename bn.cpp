#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <windows.h>

#define TF 20

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
	int 	nav[40][20];
	int		map[TF][TF];
	char	atk[TF][TF];
	char	nome[100];
};

void pos_embarc(Player player_str);
void atualiza_tela(int type, int player_number);
void status_rfs(void);

Player player1, player2;

int main()
{
	int i, j, x, y, end = 0, p = 1;
	player1.acert = 0;
	player2.acert = 0;
	setlocale(LC_ALL, "Portuguese");
	textcolor(WHITE);
	printf(".........................................................BATATA NAVAL.......................................................\n\n");
	textcolor(LIGHT_BLUE);
	printf("[-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-]  |  [-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-]\n");
	printf("[-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-]  |  [-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-]\n");
	printf("[-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-]  |  [-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-]\n");
	printf("[-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-]  |  [-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-]\n");
	printf("[-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-]  |  [-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-]\n");
	printf("[-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-]  |  [-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-]\n");
	printf("[-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-]  |  [-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-]\n");
	printf("[-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-]  |  [-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-]\n");
	printf("[-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-]  |  [-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-]\n");
	printf("[-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-]  |  [-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-]\n");
	printf("[-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-]  |  [-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-]\n");
	printf("[-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-]  |  [-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-]\n");
	printf("[-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-]  |  [-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-]\n");
	printf("[-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-]  |  [-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-]\n");
	printf("[-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-]  |  [-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-]\n");
	printf("[-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-]  |  [-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-]\n");
	printf("[-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-]  |  [-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-]\n");
	printf("[-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-]  |  [-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-]\n");
	printf("[-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-]  |  [-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-]\n");
	printf("[-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-]  |  [-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-][-]\n\n");
	textcolor(WHITE);
	printf(".........................................................START GAME..........................................................\n\n");
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
	
	
	while(end!=1)
	{
		atualiza_tela(2,p);
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
				if(player2.atk[x-1][y-1] == ' ')
				{
					player2.atk[x-1][y-1] = 'X';
					player1.acert++;
					
					if(player2.map[x-1][y-1] == 9)
					{
						printf("\nATAQUE ESPECIAL ENCONTRADO: \n");
						printf("Orientação do ataque [1-Linha ou 2-Coluna] : ");
						scanf("%d",&x);
						if(x == 1)
						{
							printf("Selecione a Linha: ");
							scanf("%d",&x);
							for(i=0;i<TF;i++)
							{
								if(player2.map[x-1][i] == 0)
									player2.atk[x-1][i] = 'O';
								else
								{
									player2.atk[x-1][i] = 'X';
									player1.acert++;
								}
							}
						}
						else
						{
							printf("Selecione a Coluna: ");
							scanf("%d",&x);
							for(i=0;i<TF;i++)
							{
								if(player2.map[i][x-1] == 0)
									player2.atk[i][x-1] = 'O';
								else
								{
									player2.atk[i][x-1] = 'X';
									player1.acert++;
								}
							}
						}
						
					}
				}
			}
			if(player1.acert == 37)
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
					if(player2.atk[x-1][y-1] == ' ')
					{
						player1.atk[x-1][y-1] = 'X';
						player2.acert++;
						
						if(player2.map[x-1][y-1] == 9)
						{
							printf("\nATAQUE ESPECIAL ENCONTRADO: \n");
							printf("Orientação do ataque [1-Linha ou 2-Coluna] : ");
							scanf("%d",&x);
							if(x == 1)
							{
								printf("Selecione a Linha: ");
								scanf("%d",&x);
								for(i=0;i<TF;i++)
								{
									if(player1.map[x-1][i] == 0)
										player1.atk[x-1][i] = 'O';
									else
									{
										player1.atk[x-1][i] = 'X';
										player2.acert++;
									}
								}
							}
							else
							{
								printf("Selecione a Coluna: ");
								scanf("%d",&x);
								for(i=0;i<TF;i++)
								{
									if(player1.map[i][x-1] == 0)
										player1.atk[i][x-1] = 'O';
									else
									{
										player1.atk[i][x-1] = 'X';
										player2.acert++;
									}
								}
							}
							
						}
					}
				}
				
				if(player2.acert == 37)
					end = 1;
				else
				{
					p = 1;
					system("cls");
				}
			}
		
	}
	
	if(player1.acert == 37)
		printf("\n\n\n\t\t%s - Venceu\n\n\n\n",player1.nome);
	else
		if(player2.acert == 37)
			printf("\n\n\n\t\t%s - Venceu\n\n\n\n", player2.nome);
	getch();
}

/*
 *
 * @atualiza_tela(int type, int player_number)
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
		atualiza_tela(1, player_str.id);
		printf("%d° MINA NAVAL\n\n",i+1);
		printf("[X] -> ");
		scanf("%d",&x);
		printf("[Y] -> ");
		scanf("%d",&y);
		player_str.map[x-1][y-1]	= 1;
		
		player_str.nav[i][0]		= x-1;
		player_str.nav[i][1]		= y-1;
		
		if(player_str.id == 1)
			player1 = player_str;
		else
			player2 = player_str;
	}
	
	for(i=0;i<3;i++)
	{
		atualiza_tela(1, player_str.id);
		
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
				
				player_str.nav[4+i][0]		= x-1;	player_str.nav[4+i][1]		= y-1;
				player_str.nav[4+i][2]		= x;	player_str.nav[4+i][3]		= y-1;
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
				
				player_str.nav[4+i][0]		= x-1;	player_str.nav[4+i][1]		= y-1;
				player_str.nav[4+i][2]		= x-1;	player_str.nav[4+i][3]		= y;
				
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
	
	for(i=0;i<3;i++)
	{
		atualiza_tela(1, player_str.id);
		
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
				
				player_str.nav[7+i][0]		= x-1;	player_str.nav[7+i][1]		= y-1;
				player_str.nav[7+i][2]		= x;	player_str.nav[7+i][3]		= y-1;
				player_str.nav[7+i][4]		= x+1;	player_str.nav[7+i][5]		= y-1;
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
				
				player_str.nav[7+i][0]		= x-1;	player_str.nav[7+i][1]		= y-1;
				player_str.nav[7+i][2]		= x-1;	player_str.nav[7+i][3]		= y;
				player_str.nav[7+i][4]		= x-1;	player_str.nav[7+i][5]		= y+1;	
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
		atualiza_tela(1, player_str.id);
		
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
				
				player_str.nav[10+i][0]		= x-1;	player_str.nav[10+i][1]	= y-1;
				player_str.nav[10+i][2]		= x;	player_str.nav[10+i][3]	= y-1;
				player_str.nav[10+i][4]		= x+1;	player_str.nav[10+i][5]	= y-1;
				player_str.nav[10+i][6]		= x+2;	player_str.nav[10+i][7]	= y-1;
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
				
				player_str.nav[10+i][0]		= x-1;	player_str.nav[10+i][1]	= y-1;
				player_str.nav[10+i][2]		= x-1;	player_str.nav[10+i][3]	= y;
				player_str.nav[10+i][4]		= x-1;	player_str.nav[10+i][5]	= y+1;
				player_str.nav[10+i][6]		= x-1;	player_str.nav[10+i][7]	= y+2;	
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
		atualiza_tela(1, player_str.id);
		
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
				
				player_str.nav[12+i][0]		= x-1;	player_str.nav[12+i][1]		= y-1;
				player_str.nav[12+i][2]		= x;	player_str.nav[12+i][3]		= y-1;
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
				
				player_str.nav[12+i][0]		= x-1;	player_str.nav[12+i][1]		= y-1;
				player_str.nav[12+i][2]		= x-1;	player_str.nav[12+i][3]		= y;	
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
		atualiza_tela(1, player_str.id);
		
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
			if((x <= TF-3) && (y <= TF-2) && (player_str.map[x-1][y-1] == 0) && (player_str.map[x][y-1] == 0) && (player_str.map[x+1][y-1] == 0) && (player_str.map[x+2][y-1] == 0) &&  (player_str.map[x-1][y] == 0) && (player_str.map[x][y] == 0) && (player_str.map[x+1][y] == 0) && (player_str.map[x+2][y] == 0))
			{
				player_str.map[x-1][y-1]	= 6;
				player_str.map[x][y-1]		= 6;
				player_str.map[x+1][y-1]	= 6;
				player_str.map[x+2][y-1]	= 6;
				player_str.map[x-1][y]		= 6;
				player_str.map[x][y]		= 6;
				player_str.map[x+1][y]		= 6;
				player_str.map[x+2][y]		= 6;
				
				player_str.nav[13+i][0]		= x-1;	player_str.nav[13+i][1]		= y-1;
				player_str.nav[13+i][2]		= x;	player_str.nav[13+i][3]		= y-1;
				player_str.nav[13+i][4]		= x+1;	player_str.nav[13+i][5]		= y-1;
				player_str.nav[13+i][6]		= x+2;	player_str.nav[13+i][7]		= y-1;
				
				player_str.nav[13+i][8]		= x-1;	player_str.nav[13+i][9]		= y;
				player_str.nav[13+i][10]	= x;	player_str.nav[13+i][11]	= y;
				player_str.nav[13+i][12]	= x+1;	player_str.nav[13+i][13]	= y;
				player_str.nav[13+i][14]	= x+2;	player_str.nav[13+i][15]	= y;
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
			if((y <= TF-4) && (x <= TF-2) && (player_str.map[x-1][y-1] == 0) && (player_str.map[x-1][y] == 0) && (player_str.map[x-1][y+1] == 0) && (player_str.map[x-1][y+2] == 0) && (player_str.map[x][y-1] == 0) && (player_str.map[x][y] == 0) && (player_str.map[x][y+1] == 0) && (player_str.map[x][y+2] == 0))
			{
				player_str.map[x-1][y-1]	= 6;
				player_str.map[x-1][y]		= 6;
				player_str.map[x-1][y+1]	= 6;
				player_str.map[x-1][y+2] 	= 6;
				player_str.map[x][y-1]		= 6;
				player_str.map[x][y]		= 6;
				player_str.map[x][y+1]		= 6;
				player_str.map[x][y+2]		= 6;
				
				player_str.nav[13+i][0]		= x-1;	player_str.nav[13+i][1]		= y-1;
				player_str.nav[13+i][2]		= x-1;	player_str.nav[13+i][3]		= y;
				player_str.nav[13+i][4]		= x-1;	player_str.nav[13+i][5]		= y+1;
				player_str.nav[13+i][6]		= x-1;	player_str.nav[13+i][7]		= y+2;
				
				player_str.nav[13+i][8]		= x;	player_str.nav[13+i][9]		= y-1;
				player_str.nav[13+i][10]	= x;	player_str.nav[13+i][11]	= y;
				player_str.nav[13+i][12]	= x;	player_str.nav[13+i][13]	= y+1;
				player_str.nav[13+i][14]	= x;	player_str.nav[13+i][15]	= y+2;
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
	
	i=1;
	while(i!=0)
	{
		x = 1+(rand() % TF);
		y = 1+(rand() % TF);
		if(player_str.map[x][y] == 0)
		{
			player_str.map[x][y] = 9;
			i=0;
		}
	}
}


void atualiza_tela(int type, int player_number)
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
						if(player1.atk[i][j] == 'O')
							textcolor(WHITE);
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
						if(player2.atk[i][j] == 'O')
							textcolor(WHITE);
						printf("[%c]",player2.atk[i][j]);
					}
				textcolor(WHITE);	
				printf("\t%d\n",i+1);
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
			status_rfs();
		}
}

void status_rfs(void)
{
	int i;
	for(i=0;i<3;i++)
	{
		textcolor(GREEN);
		if(i<2)
		{
			textcolor(GREEN);
			if(player1.atk[ player1.nav[i][0] ][ player1.nav[i][1] ] == 'X')
				textcolor(LIGHT_RED);
			printf("%d° Mina Naval    ",i+1);
			textcolor(GREEN);
			
			textcolor(GREEN);
			if(player1.atk[ player1.nav[i+4][0] ][ player1.nav[i+4][1] ] == 'X' && player1.atk[ player1.nav[i+4][2] ][ player1.nav[i+4][3] ] == 'X')
				textcolor(LIGHT_RED);
			printf("%d° Corveta    ",i+1);
			
			textcolor(GREEN);
			if(player1.atk[ player1.nav[i+7][0] ][ player1.nav[i+7][1] ] == 'X' && player1.atk[ player1.nav[i+7][2] ][ player1.nav[i+7][3] ] == 'X' && player1.atk[ player1.nav[i+7][4] ][ player1.nav[i+7][5] ] == 'X')
				textcolor(LIGHT_RED);
			printf("%d° Contratorpedeiro    ",i+1);
			
			textcolor(GREEN);
			if(player1.atk[ player1.nav[i+10][0] ][ player1.nav[i+10][1] ] == 'X' && player1.atk[ player1.nav[i+10][2] ][ player1.nav[i+10][3] ] == 'X' && player1.atk[ player1.nav[i+10][4] ][ player1.nav[i+10][5] ] == 'X'  && player1.atk[ player1.nav[i+10][6] ][ player1.nav[i+10][7] ] == 'X')
				textcolor(LIGHT_RED);
			printf("%d° Fragata      |\t",i+1);
			
			/********************************************************************************************************************************/
			textcolor(GREEN);
			if(player2.atk[ player2.nav[i][0] ][ player2.nav[i][1] ] == 'X')
				textcolor(LIGHT_RED);
			printf("  %d° Mina Naval    ",i+1);
			
			textcolor(GREEN);
			if(player2.atk[ player2.nav[i+4][0] ][ player2.nav[i+4][1] ] == 'X' && player2.atk[ player2.nav[i+4][2] ][ player2.nav[i+4][3] ] == 'X')
				textcolor(LIGHT_RED);
			printf("%d° Corveta    ",i+1);
			
			textcolor(GREEN);
			if(player2.atk[ player2.nav[i+7][0] ][ player2.nav[i+7][1] ] == 'X' && player2.atk[ player2.nav[i+7][2] ][ player2.nav[i+7][3] ] == 'X' && player2.atk[ player2.nav[i+7][4] ][ player2.nav[i+7][5] ] == 'X')
				textcolor(LIGHT_RED);
			printf("%d° Contratorpedeiro    ",i+1);
			
			textcolor(GREEN);
			if(player2.atk[ player2.nav[i+10][0] ][ player2.nav[i+10][1] ] == 'X' && player2.atk[ player2.nav[i+10][2] ][ player2.nav[i+10][3] ] == 'X' && player2.atk[ player2.nav[i+10][4] ][ player2.nav[i+10][5] ] == 'X'  && player2.atk[ player2.nav[i+10][6] ][ player2.nav[i+10][7] ] == 'X')
				textcolor(LIGHT_RED);
			printf("%d° Fragata\n",i+1);
		}
		else
		{
			if(i == 2)
			{
				textcolor(GREEN);
				if(player1.atk[ player1.nav[i][0] ][ player1.nav[i][1] ] == 'X')
					textcolor(LIGHT_RED);
				printf("%d° Mina Naval    ",i+1);
				
				textcolor(GREEN);
				if(player1.atk[ player1.nav[i+4][0] ][ player1.nav[i+4][1] ] == 'X' && player1.atk[ player1.nav[i+4][2] ][ player1.nav[i+4][3] ] == 'X')
					textcolor(LIGHT_RED);
				printf("%d° Corveta    ",i+1);
				
				textcolor(GREEN);
				if(player1.atk[ player1.nav[i+7][0] ][ player1.nav[i+7][1] ] == 'X' && player1.atk[ player1.nav[i+7][2] ][ player1.nav[i+7][3] ] == 'X' && player1.atk[ player1.nav[i+7][4] ][ player1.nav[i+7][5] ] == 'X')
					textcolor(LIGHT_RED);
				printf("%d° Contratorpedeiro                    |\t",i+1);
				
				
				
				/*********************************************************************************************************************/
				
				textcolor(GREEN);
				if(player2.atk[ player2.nav[i][0] ][ player2.nav[i][1] ] == 'X')
					textcolor(LIGHT_RED);
				printf("  %d° Mina Naval    ",i+1);
				
				textcolor(GREEN);
				if(player2.atk[ player2.nav[i+4][0] ][ player2.nav[i+4][1] ] == 'X' && player2.atk[ player2.nav[i+4][2] ][ player2.nav[i+4][3] ] == 'X')
					textcolor(LIGHT_RED);
				printf("%d° Corveta    ",i+1);
				
				textcolor(GREEN);
				if(player2.atk[ player2.nav[i+7][0] ][ player2.nav[i+7][1] ] == 'X' && player2.atk[ player2.nav[i+7][2] ][ player2.nav[i+7][3] ] == 'X' && player2.atk[ player2.nav[i+7][4] ][ player2.nav[i+7][5] ] == 'X')
					textcolor(LIGHT_RED);
				printf("%d° Contratorpedeiro\n",i+1);
			}
		}
	}
	
		
		textcolor(GREEN);
			if(player1.atk[ player1.nav[3][0] ][ player1.nav[3][1] ] == 'X')
				textcolor(LIGHT_RED);
			printf("%d° Mina Naval    ",4);
		textcolor(GREEN);

		if(player1.atk[ player1.nav[12][0] ][ player1.nav[12][1] ] == 'X' && player1.atk[ player1.nav[12][2] ][ player1.nav[12][3] ] == 'X')
			textcolor(LIGHT_RED);
		printf("%d° Submarino  ",1);
		
		textcolor(GREEN);
		if(player1.atk[ player1.nav[13][0] ][ player1.nav[13][1] ] == 'X' 
		&& player1.atk[ player1.nav[13][2] ][ player1.nav[13][3] ] == 'X' 
		&& player1.atk[ player1.nav[13][4] ][ player1.nav[13][5] ] == 'X' 
		&& player1.atk[ player1.nav[13][6] ][ player1.nav[13][7] ] == 'X' 
		&& player1.atk[ player1.nav[13][8] ][ player1.nav[13][9] ] == 'X' 
		&& player1.atk[ player1.nav[13][10] ][ player1.nav[13][11] ] == 'X' 
		&& player1.atk[ player1.nav[13][12] ][ player1.nav[13][13] ] == 'X' 
		&& player1.atk[ player1.nav[13][14] ][ player1.nav[13][15] ] == 'X')
			textcolor(LIGHT_RED);
		printf("%d° Porta-Avião                         |\t",i+1);
		
		
		
		/*****************************************************************/
		
		
		textcolor(GREEN);
		if(player2.atk[ player2.nav[3][0] ][ player2.nav[3][1] ] == 'X')
			textcolor(LIGHT_RED);
		printf("  %d° Mina Naval    ",4);
		
		textcolor(GREEN);
		if(player2.atk[ player2.nav[12][0] ][ player2.nav[12][1] ] == 'X' 
		&& player2.atk[ player2.nav[12][2] ][ player2.nav[12][3] ] == 'X')
			textcolor(LIGHT_RED);
		printf("1° Submarino  ");
		
		textcolor(GREEN);
		if(player2.atk[ player2.nav[13][0] ][ player2.nav[13][1] ] == 'X' 
		&& player2.atk[ player2.nav[13][2] ][ player2.nav[13][3] ] == 'X' 
		&& player2.atk[ player2.nav[13][4] ][ player2.nav[13][5] ] == 'X' 
		&& player2.atk[ player2.nav[13][6] ][ player2.nav[13][7] ] == 'X' 
		&& player2.atk[ player2.nav[13][8] ][ player2.nav[13][9] ] == 'X' 
		&& player2.atk[ player2.nav[13][10] ][ player2.nav[13][11] ] == 'X' 
		&& player2.atk[ player2.nav[13][12] ][ player2.nav[13][13] ] == 'X' 
		&& player2.atk[ player2.nav[13][14] ][ player2.nav[13][15] ] == 'X')
			textcolor(LIGHT_RED);
		printf("1° Porta-Avião\n");
	
	textcolor(WHITE);
}
