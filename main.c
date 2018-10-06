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

	while(isRunning)
	{
		// TODO Clear Screen and print_UI
		print_UI(player_table);
		player1_move();
		// TODO Check grid for winner
		// TODO Clear Screen and print_UI
		print_UI(player_table);
		player2_move();
		// TODO check grid for winner
	}
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
			if(row > x & row < (x+CELL_SIZE-1))
			{
				if(col == y)
					grid[col][row] = ' ';
				else if(col == (y+CELL_SIZE-1))
					grid[col][row] = ' ';
				else
					grid[col][row] = '#';
					
			}
			else if(col > y & col < (y + CELL_SIZE-1))
			{
				if(row == x)
					grid[col][row] = ' ';
				else if(row == (x + CELL_SIZE-1))
					grid[col][row] = ' ';
				else
					grid[col][row] = '#';
			}
			// Print out the corners
			else
			{
				grid[col][row] = '#';
			}
		}
	}
}

void player1_move(void)
{	
	char move[3] = {0};
	char v_move = 0;
	do
	{
		printf("\nP1 move: ");
		scanf("%2s", move);
		v_move = valid_move(move);
	} while(v_move == 0);
	// At this point we have a valid move
	switch(v_move){
		case 1:
			draw_x(TL_X,TL_Y);
			// TODO update grid status
			break;
		case 2:
			draw_x(TM_X,TM_Y);
			// TODO update grid status
			break;
		case 3:
			draw_x(TR_X,TR_Y);
			// TODO update grid status
			break;
		case 4:
			draw_x(ML_X,ML_Y);
			// TODO update grid status
			break;
		case 5:
			draw_x(MM_X,MM_Y);
			// TODO update grid status
			break;
		case 6:
			draw_x(MR_X,MR_Y);
			// TODO update grid status
			break;
		case 7:
			draw_x(BL_X,BL_Y);
			// TODO update grid status
			break;
		case 8:
			draw_x(BM_X,BM_Y);
			// TODO update grid status
			break;
		case 9:
			draw_x(BR_X,BR_Y);
			// TODO update grid status
			break;
		default:
			break;
	}
}

void player2_move(void)
{	
	char move[3] = {0};
	char v_move = 0;
	do
	{
		printf("\nP2 move: ");
		scanf("%2s", move);
		v_move = valid_move(move);
	} while(v_move == 0);
	// At this point we have a valid move
	switch(v_move){
		case 1:
			draw_o(TL_X,TL_Y);
			// TODO update grid status
			break;
		case 2:
			draw_o(TM_X,TM_Y);
			// TODO update grid status
			break;
		case 3:
			draw_o(TR_X,TR_Y);
			// TODO update grid status
			break;
		case 4:
			draw_o(ML_X,ML_Y);
			// TODO update grid status
			break;
		case 5:
			draw_o(MM_X,MM_Y);
			// TODO update grid status
			break;
		case 6:
			draw_o(MR_X,MR_Y);
			// TODO update grid status
			break;
		case 7:
			draw_o(BL_X,BL_Y);
			// TODO update grid status
			break;
		case 8:
			draw_o(BM_X,BM_Y);
			// TODO update grid status
			break;
		case 9:
			draw_o(BR_X,BR_Y);
			// TODO update grid status
			break;
		default:
			break;
	}
}

// Check 
char valid_move(char *move)
{
	char valid = 0;

	if(move[0] == 'T')
	{
		if(move[1] == 'L')
			valid = 1;
		if(move[1] == 'M')
			valid = 2;
		if(move[1] == 'R')
			valid = 3;
	}
	else if(move[0] == 'M')
	{
		if(move[1] == 'L')
			valid = 4;
		if(move[1] == 'M')
			valid = 5;
		if(move[1] == 'R')
			valid = 6;
	}
	else if(move[0] == 'B')
	{
		if(move[1] == 'L')
			valid = 7;
		if(move[1] == 'M')
			valid = 8;
		if(move[1] == 'R')
			valid = 9;
	}
	return valid;
}
