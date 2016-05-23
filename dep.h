#define EASY 10
#define REGULAR 20
#define HELL 30
///Colors
enum COLORS {
    BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN,
    LIGHT_GRAY, DARK_GRAY, LIGHT_BLUE, LIGHT_GREEN, LIGHT_CYAN,
    LIGHT_RED, LIGHT_MAGENTA, YELLOW, WHITE
};
typedef enum COLORS DOS_COLORS;
///Tipo de dado BOOLEANO
enum boolean {
	true = 1, false = 0
};
typedef enum boolean bool;
///Estruturas de dados
struct Ship_str
{
	int tot;
	int corveta;
	int fragata;
	int submarino;
	int mina_naval;
	int porta_aviao;
	int contratorpediro;
	bool atk_especial;
	
};
typedef struct Ship_str Ship;

struct Player_str
{
	int		num;
	int		pnt;
	int 	nav[50][50];
	int		map[30][30];
	char	atk[30][30];
	char	nom[100];
};
typedef struct Player_str Player;

struct Game_str
{
	int game_mode;
	int game_level;
	int last_move;
	bool game_save_load;
	Player player_1;
	Player player_2;
};
typedef struct Game_str Game_dat;

struct Save_str
{
	char partida[200];
	Game_dat game_data;
	Ship ship_data;
};
typedef struct Save_str Save;
