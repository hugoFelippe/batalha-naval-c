#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct Player
{
	char	nome[100];
	char	atk[10][10];
	int		map[10][10];
	int		acert;
};

//void refresh_screen(int type, int pla);



int main()
{
	int i, j, x, y, orientacao, end = 0, p = 1;
	Player player1, player2;
	
	player1.acert = 0;
	player2.acert = 0;
	
	printf(".........BATALHA NAVAL........\n\n");
	printf("[-][-][-][-][-][-][-][-][-][-]\n");
	printf("[-][-][-][-][-][-][-][-][-][-]\n");
	printf("[-][-][-][-][-][-][-][-][-][-]\n");
	printf("[-][-][-][-][-][-][-][-][-][-]\n");
	printf("[-][-][-][-][-][-][-][-][-][-]\n");
	printf("[-][-][-][-][-][-][-][-][-][-]\n");
	printf("[-][-][-][-][-][-][-][-][-][-]\n");
	printf("[-][-][-][-][-][-][-][-][-][-]\n");
	printf("[-][-][-][-][-][-][-][-][-][-]\n");
	printf("[-][-][-][-][-][-][-][-][-][-]\n\n");
	printf("----------START GAME----------\n\n");
	printf("Player 1 -> ");
	gets(player1.nome);
	printf("Player 2 -> ");
	gets(player2.nome);
	for(i=0;i<10;i++)
		for(j=0;j<10;j++)
		{
			player1.map[i][j] = 0; 
			player2.map[i][j] = 0;
		}
	for(i=0;i<10;i++)
		for(j=0;j<10;j++)
		{
			player1.atk[i][j] = '-'; 
			player2.atk[i][j] = '-';
		}
			 

	system("cls");
	printf("--------------------PLAYER 1--------------------\n\n");
	printf("X\n");
	printf("1\t- [-][-][-][-][-][-][-][-][-][-]\n");
	printf("2\t- [-][-][-][-][-][-][-][-][-][-]\n");
	printf("3\t- [-][-][-][-][-][-][-][-][-][-]\n");
	printf("4\t- [-][-][-][-][-][-][-][-][-][-]\n");
	printf("5\t- [-][-][-][-][-][-][-][-][-][-]\n");
	printf("6\t- [-][-][-][-][-][-][-][-][-][-]\n");
	printf("7\t- [-][-][-][-][-][-][-][-][-][-]\n");
	printf("8\t- [-][-][-][-][-][-][-][-][-][-]\n");
	printf("9\t- [-][-][-][-][-][-][-][-][-][-]\n");
	printf("10\t- [-][-][-][-][-][-][-][-][-][-]\n");
	printf("\t   |  |  |  |  |  |  |  |  |  | \n");
	printf("\t   1  2  3  4  5  6  7  8  9  10 -Y\n\n");
	for(i=0;i<4;i++)
	{
		printf("Onde deseja colocar o %do submarino\n",i+1);
		printf("[X] -> ");
		scanf("%d",&x);
		printf("[Y] -> ");
		scanf("%d",&y);
		player1.map[x-1][y-1] = 1;
		
	}
	
	///Refresh screen
	system("cls");
	printf("--------------------PLAYER 1--------------------\n\n");
	printf("X\n");
	for(i=0;i<10;i++)
	{
		printf("%d\t- ",i+1);
		for(j=0;j<10;j++)
			printf("[%d]",player1.map[i][j]);
		printf("\n");
	}
	printf("\t   |  |  |  |  |  |  |  |  |  | \n");
	printf("\t   1  2  3  4  5  6  7  8  9  10 -Y\n\n");
	///END Refresh screen
	
	
	for(i=0;i<2;i++)
	{
		printf("Onde deseja colocar o %do destroyer\n",i+1);
		
		printf("[X] -> ");
		scanf("%d",&x);
		printf("[Y] -> ");
		scanf("%d",&y);
		printf("[orientacao-> 1-vetical 2-horizontal] -> ");
		scanf("%d",&orientacao);

		if(orientacao == 1)
		{
			if(x <= 9 && player1.map[x-1][y-1] == 0 && player1.map[x][y-1] == 0)
			{
				player1.map[x-1][y-1] = 2;
				player1.map[x][y-1] = 2;
			}
			else
			{
				printf("\nPosicao ja utilizada!!!\n\n");
				i--;
			}
		}
		else
		{
			if(y <= 9 && player1.map[x-1][y-1] == 0 && player1.map[x-1][y] == 0)
			{
				player1.map[x-1][y-1] = 2;
				player1.map[x-1][y] = 2;	
			}
			else
			{
				printf("\nPosicao ja utilizada!!!\n\n");
				i--;
			}
		}
	}
	
	///Refresh screen
	system("cls");
	printf("--------------------PLAYER 1--------------------\n\n");
	printf("X\n");
	for(i=0;i<10;i++)
	{
		printf("%d\t- ",i+1);
		for(j=0;j<10;j++)
			printf("[%d]",player1.map[i][j]);
		printf("\n");
	}
	printf("\t   |  |  |  |  |  |  |  |  |  | \n");
	printf("\t   1  2  3  4  5  6  7  8  9  10 -Y\n\n");
	///END Refresh screen
	
	for(i=0;i<3;i++)
	{
		printf("Onde deseja colocar o %do cruzador\n",i+1);
		
		printf("[X] -> ");
		scanf("%d",&x);
		printf("[Y] -> ");
		scanf("%d",&y);
		printf("[orientacao-> 1-vetical 2-horizontal] -> ");
		scanf("%d",&orientacao);

		if(orientacao == 1)
		{
			if(x <= 8 && player1.map[x-1][y-1] == 0 && player1.map[x][y-1] == 0 && player1.map[x+1][y-1] == 0)
			{
				player1.map[x-1][y-1]	= 3;
				player1.map[x][y-1] 	= 3;
				player1.map[x+1][y-1]	= 3;
			}
			else
			{
				printf("\nPosicao ja utilizada!!!\n\n");
				i--;
			}
		}
		else
		{
			if(y <= 8 && player1.map[x-1][y-1] == 0 && player1.map[x-1][y] == 0 && player1.map[x-1][y+1] == 0 )
			{
				player1.map[x-1][y-1]	= 3;
				player1.map[x-1][y]		= 3;
				player1.map[x-1][y+1] 	= 3;
			}
			else
			{
				printf("\nPosicao ja utilizada!!!\n\n");
				i--;
			}
		}
	}
	
	///Refresh screen
	system("cls");
	printf("--------------------PLAYER 1--------------------\n\n");
	printf("X\n");
	for(i=0;i<10;i++)
	{
		printf("%d\t- ",i+1);
		for(j=0;j<10;j++)
			printf("[%d]",player1.map[i][j]);
		printf("\n");
	}
	printf("\t   |  |  |  |  |  |  |  |  |  | \n");
	printf("\t   1  2  3  4  5  6  7  8  9  10 -Y\n\n");
	///END Refresh screen
	
	for(i=0;i<1;i++)
	{
		printf("Onde deseja colocar o %do couracado\n",i+1);
		
		printf("[X] -> ");
		scanf("%d",&x);
		printf("[Y] -> ");
		scanf("%d",&y);
		printf("[orientacao-> 1-vetical 2-horizontal] -> ");
		scanf("%d",&orientacao);

		if(orientacao == 1)
		{
			if(x <= 7 && player1.map[x-1][y-1] == 0 && player1.map[x][y-1] == 0 && player1.map[x+1][y-1] == 0 && player1.map[x+2][y-1] == 0)
			{
				player1.map[x-1][y-1]	= 3;
				player1.map[x][y-1] 	= 3;
				player1.map[x+1][y-1]	= 3;
				player1.map[x+2][y-1]	= 3;
			}
			else
			{
				printf("\nPosicao ja utilizada!!!\n\n");
				i--;
			}
		}
		else
		{
			if(y <= 7 && player1.map[x-1][y-1] == 0 && player1.map[x-1][y] == 0 && player1.map[x-1][y+1] == 0 && player1.map[x-1][y+2] == 0)
			{
				player1.map[x-1][y-1]	= 4;
				player1.map[x-1][y]		= 4;
				player1.map[x-1][y+1] 	= 4;
				player1.map[x-1][y+2]	= 4;
			}
			else
			{
				printf("\nPosicao ja utilizada!!!\n\n");
				i--;
			}
		}
	}
	/*
	
					PLAYER 2
	
	*/
	
	system("cls");
	printf("--------------------PLAYER 2--------------------\n\n");
	printf("X\n");
	printf("1\t- [-][-][-][-][-][-][-][-][-][-]\n");
	printf("2\t- [-][-][-][-][-][-][-][-][-][-]\n");
	printf("3\t- [-][-][-][-][-][-][-][-][-][-]\n");
	printf("4\t- [-][-][-][-][-][-][-][-][-][-]\n");
	printf("5\t- [-][-][-][-][-][-][-][-][-][-]\n");
	printf("6\t- [-][-][-][-][-][-][-][-][-][-]\n");
	printf("7\t- [-][-][-][-][-][-][-][-][-][-]\n");
	printf("8\t- [-][-][-][-][-][-][-][-][-][-]\n");
	printf("9\t- [-][-][-][-][-][-][-][-][-][-]\n");
	printf("10\t- [-][-][-][-][-][-][-][-][-][-]\n");
	printf("\t   |  |  |  |  |  |  |  |  |  | \n");
	printf("\t   1  2  3  4  5  6  7  8  9  10 -Y\n\n");
	for(i=0;i<4;i++)
	{
		printf("Onde deseja colocar o %do submarino\n",i+1);
		printf("[X] -> ");
		scanf("%d",&x);
		printf("[Y] -> ");
		scanf("%d",&y);
		player2.map[x-1][y-1] = 1;
		
	}
	
	///Refresh screen
	system("cls");
	printf("--------------------PLAYER 2--------------------\n\n");
	printf("X\n");
	for(i=0;i<10;i++)
	{
		printf("%d\t- ",i+1);
		for(j=0;j<10;j++)
			printf("[%d]",player2.map[i][j]);
		printf("\n");
	}
	printf("\t   |  |  |  |  |  |  |  |  |  | \n");
	printf("\t   1  2  3  4  5  6  7  8  9  10 -Y\n\n");
	///END Refresh screen
	
	
	for(i=0;i<2;i++)
	{
		printf("Onde deseja colocar o %do destroyer\n",i+1);
		
		printf("[X] -> ");
		scanf("%d",&x);
		printf("[Y] -> ");
		scanf("%d",&y);
		printf("[orientacao-> 1-vetical 2-horizontal] -> ");
		scanf("%d",&orientacao);

		if(orientacao == 1)
		{
			if(x <= 9 && player2.map[x-1][y-1] == 0 && player2.map[x][y-1] == 0)
			{
				player2.map[x-1][y-1] = 2;
				player2.map[x][y-1] = 2;
			}
			else
			{
				printf("\nPosicao ja utilizada!!!\n\n");
				i--;
			}
		}
		else
		{
			if(y <= 9 && player2.map[x-1][y-1] == 0 && player2.map[x-1][y] == 0)
			{
				player2.map[x-1][y-1] = 2;
				player2.map[x-1][y] = 2;	
			}
			else
			{
				printf("\nPosicao ja utilizada!!!\n\n");
				i--;
			}
		}
	}
	
	///Refresh screen
	system("cls");
	printf("--------------------PLAYER 2--------------------\n\n");
	printf("X\n");
	for(i=0;i<10;i++)
	{
		printf("%d\t- ",i+1);
		for(j=0;j<10;j++)
			printf("[%d]",player2.map[i][j]);
		printf("\n");
	}
	printf("\t   |  |  |  |  |  |  |  |  |  | \n");
	printf("\t   1  2  3  4  5  6  7  8  9  10 -Y\n\n");
	///END Refresh screen
	
	for(i=0;i<3;i++)
	{
		printf("Onde deseja colocar o %do cruzador\n",i+1);
		
		printf("[X] -> ");
		scanf("%d",&x);
		printf("[Y] -> ");
		scanf("%d",&y);
		printf("[orientacao-> 1-vetical 2-horizontal] -> ");
		scanf("%d",&orientacao);

		if(orientacao == 1)
		{
			if(x <= 8 && player2.map[x-1][y-1] == 0 && player2.map[x][y-1] == 0 && player2.map[x+1][y-1] == 0)
			{
				player2.map[x-1][y-1]	= 3;
				player2.map[x][y-1] 	= 3;
				player2.map[x+1][y-1]	= 3;
			}
			else
			{
				printf("\nPosicao ja utilizada!!!\n\n");
				i--;
			}
		}
		else
		{
			if(y <= 8 && player2.map[x-1][y-1] == 0 && player2.map[x-1][y] == 0 && player2.map[x-1][y+1] == 0 )
			{
				player2.map[x-1][y-1]	= 3;
				player2.map[x-1][y]		= 3;
				player2.map[x-1][y+1] 	= 3;
			}
			else
			{
				printf("\nPosicao ja utilizada!!!\n\n");
				i--;
			}
		}
	}
	
	///Refresh screen
	system("cls");
	printf("--------------------PLAYER 2--------------------\n\n");
	printf("X\n");
	for(i=0;i<10;i++)
	{
		printf("%d\t- ",i+1);
		for(j=0;j<10;j++)
			printf("[%d]",player2.map[i][j]);
		printf("\n");
	}
	printf("\t   |  |  |  |  |  |  |  |  |  | \n");
	printf("\t   1  2  3  4  5  6  7  8  9  10 -Y\n\n");
	///END Refresh screen
	
	for(i=0;i<1;i++)
	{
		printf("Onde deseja colocar o %do couracado\n",i+1);
		
		printf("[X] -> ");
		scanf("%d",&x);
		printf("[Y] -> ");
		scanf("%d",&y);
		printf("[orientacao-> 1-vetical 2-horizontal] -> ");
		scanf("%d",&orientacao);

		if(orientacao == 1)
		{
			if(x <= 7 && player2.map[x-1][y-1] == 0 && player2.map[x][y-1] == 0 && player2.map[x+1][y-1] == 0 && player2.map[x+2][y-1] == 0)
			{
				player2.map[x-1][y-1]	= 3;
				player2.map[x][y-1] 	= 3;
				player2.map[x+1][y-1]	= 3;
				player2.map[x+2][y-1]	= 3;
			}
			else
			{
				printf("\nPosicao ja utilizada!!!\n\n");
				i--;
			}
		}
		else
		{
			if(y <= 7 && player2.map[x-1][y-1] == 0 && player2.map[x-1][y] == 0 && player2.map[x-1][y+1] == 0 && player2.map[x-1][y+2] == 0)
			{
				player2.map[x-1][y-1]	= 4;
				player2.map[x-1][y]		= 4;
				player2.map[x-1][y+1] 	= 4;
				player2.map[x-1][y+2]	= 4;
			}
			else
			{
				printf("\nPosicao ja utilizada!!!\n\n");
				i--;
			}
		}
	}	
	system("cls");
	
	
	
	
	
	printf("-----------GAME STARTED-----------\n\n");
	
	while(end!=1)
	{
		printf("--------------------PLAYER %d--------------------\n\n",p);
		
		printf(" \t----------PLAYER 1------------  |  ----------PLAYER 2------------\n");
		for(i=0;i<10;i++)
		{
			printf("%d\t",i+1);
			
			for(j=0;j<10;j++)
				printf("[%c]",player1.atk[i][j]);
			
			printf("  |  ");
			
			for(j=0;j<10;j++)
				printf("[%c]",player2.atk[i][j]);
					
			printf("\n");
		}
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
			
			system("cls");
			printf(" \t----------PLAYER 1------------  |  ----------PLAYER 2------------\n");
			for(i=0;i<10;i++)
			{
				printf("%d\t",i+1);
				
				for(j=0;j<10;j++)
					printf("[%c]",player1.atk[i][j]);
				
				printf("  |  ");
				
				for(j=0;j<10;j++)
					printf("[%c]",player2.atk[i][j]);
						
				printf("\n");
			}
			
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
				
				system("cls");
				printf(" \t----------PLAYER 1------------  |  ----------PLAYER 2------------\n");
				for(i=0;i<10;i++)
				{
					printf("%d\t",i+1);
					
					for(j=0;j<10;j++)
						printf("[%c]",player1.atk[i][j]);
					
					printf("  |  ");
					
					for(j=0;j<10;j++)
						printf("[%c]",player2.atk[i][j]);
							
					printf("\n");
				}
				
				if(player1.acert == 21)
					end = 1;
				
				p = 1;
				system("cls");
			}
		
	}
	
	if(player1.acert == 21)
		printf("\n%s - Venceu",player1.nome);
	else
		if(player2.acert == 21)
			printf("\n%s - Venceu", player2.nome);

}
/*
void refresh_screen(int type, int pla)
{
	/// TYPE == 1 - UM MAPA
	/// TYPE == 2 - DOIS MAPAS
	if(type == 1)
	{
		///Refresh screen
		system("cls");
		printf("--------------------PLAYER %d--------------------\n\n",pla);
		printf("X\n");
		for(i=0;i<10;i++)
		{
			printf("%d\t- ",i+1);
			for(j=0;j<10;j++)
				if(pla == 1)
					printf("[%d]",player1.map[i][j]);
				else
					if(pla == 2)
						printf("[%d]",player2.map[i][j]);
			printf("\n");
		}
		printf("\t   |  |  |  |  |  |  |  |  |  | \n");
		printf("\t   1  2  3  4  5  6  7  8  9  10 -Y\n\n");
		///END Refresh screen
	}
	
}*/
