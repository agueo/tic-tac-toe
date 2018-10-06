#include "ttt.h"

char grid[LENGTH][WIDTH] = {
		' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',
		'-','-','-','-','-','+','-','-','-','-','-','+','-','-','-','-','-',
		' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',
		'-','-','-','-','-','+','-','-','-','-','-','+','-','-','-','-','-',
		' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' '
};

int main(void)
{
	players_t *player_table = (players_t *) calloc(1,sizeof(players_t));
	char isRunning;

	isRunning = init_game(player_table);
	if(isRunning)
		print_UI(player_table);

	while(isRunning)
	{
		// TODO P1 make move
		// TODO update grid
		// TODO Check grid for winner
		// TODO Clear Screen and print_UI
		// TODO p2 make move
		// TODO update grid
		// TODO check grid for winner
		// TODO Clear Screen and print_UI
		break;
	}
	draw_x(BR_X,BR_Y);
	print_grid();
}

char init_game(players_t *pt)
{
	pt->p1_name = (char *)malloc(sizeof(char) * 20);
	if(pt->p1_name == NULL)
		return 0;
	pt->p2_name = (char *)malloc(sizeof(char) * 20);
	if(pt->p2_name == NULL)
		return 0;

	printf("Player 1 enter your name: ");
	scanf("%s", pt->p1_name);

	printf("Player 2 enter your name: ");
	scanf("%s", pt->p2_name);

	return 1;
}

void print_UI(players_t *pt)
{
	system("clear");
	print_grid();
	printf("\n");
	printf("p1: %s, score: %d\n",pt->p1_name, pt->p1_points);
	printf("p2: %s, score: %d\n",pt->p2_name, pt->p2_points);
	printf("Valid moves are: \nTL,TM,TR,\nML,MM,MR,\nBL,BM,BR\n");
}

void print_grid(void)
{
	int i, j;
	for(i = 0; i < LENGTH; i++)
	{
		for(j = 0; j < WIDTH; j++)
		{
			printf("%c",grid[i][j]);
		}
		printf("\n");
	}
}

void draw_o(int x, int y)
{
	int row, col;
	for(row = x; row < x + CELL_SIZE; row++)
	{
		for(col = y; col < y + CELL_SIZE; col++)
		{
			if(row > x & row < (x+CELL_SIZE-1))
			{
				if(col == y)
					grid[col][row] = '#';
				else if(col == (y+CELL_SIZE-1))
					grid[col][row] = '#';
			}
			else if(col > y & col < (y + CELL_SIZE-1))
			{
				if(row == x)
					grid[col][row] = '#';
				else if(row == (x + CELL_SIZE-1))
					grid[col][row] = '#';
			}
		}
	}
}

void draw_x(int x, int y)
{
	int row, col;
	for(row = x; row < x + CELL_SIZE; row++)
	{
		for(col = y; col < y + CELL_SIZE; col++)
		{
			if((row + col) % 2 == 0)
				grid[col][row] = '#';
		}
	}
}

void player1_move(void)
{
	
}
