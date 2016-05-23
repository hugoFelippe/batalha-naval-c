#include <stdio.h>
#include <stdlib.h>
#include "dep.h"

extern Game_dat game_data;
extern Ship ship_data;

void init_game()
{
	int p = 1;
	bool end = false;
	switch(game_data.game_mode)
	{
		case 1:
				if(game_data.game_save_load == false)
				{
					game_set_ship(1);
					game_set_ship(2);
				}
				else
					p = game_data.last_move
				while(end!=true)
				{
					atk(p);
					
					if(game_data.player_1.pnt == ship_data.tot)
						end = true;
					if(game_data.player_2.pnt == ship_data.tot)
						end = true;
					
					if(p == 1)
						p = 2;
					else
						p = 1;
						
					save_game(p);
				}	
			break;
		case 2:
				if(game_data.game_save_load == false)
				{
					game_set_ship(1);
					game_AI_set_ship(2);
				}
				else
					p = game_data.last_move
				while(end!=true)
				{
					if(p == 1)
						atk(p);
					else
						ia_atk(p);
					
					if(game_data.player_1.pnt == ship_data.tot)
						end = true;
					if(game_data.player_2.pnt == ship_data.tot)
						end = true;
					
					if(p == 1)
						p = 2;
					else
						p = 1;
					save_game(p);
				}
				
			break;
		case 3:
				if(game_data.game_save_load == false)
				{
					game_AI_set_ship(1);
					game_AI_set_ship(2);
				}
				else
					p = game_data.last_move
				while(end!=true)
				{
					ia_atk(p);
					
					if(game_data.player_1.pnt == ship_data.tot)
						end = true;
					if(game_data.player_2.pnt == ship_data.tot)
						end = true;
					
					if(p == 1)
						p = 2;
					else
						p = 1;
					save_game(p);
				}
			break;
	}
	if(game_data.player_1.pnt == ship_data.tot)
		printf("\n\n\n\t\t %s - Venceu\n\n\n\n", game_data.player_1.nom);
	else
		if(game_data.player_2.pnt == ship_data.tot)
			printf("\n\n\n\t\t %s - Venceu\n\n\n\n", game_data.player_2.nom);
	getch();
	
	
	
	
}
