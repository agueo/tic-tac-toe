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

int grid_status[GRID_SIZE] = {0};

int main(void)
{
	players_t *player_table = (players_t *) calloc(1,sizeof(players_t));
	char isRunning;

	isRunning = init_game(player_table);
	int p_turn = 0;

	while(isRunning)
	{
		print_UI(player_table);
		player1_move();
		p_turn = PLAYER1;
		if(check_winner(PLAYER1))
			if(!update_points(PLAYER1, player_table))
				break;

		print_UI(player_table);
		player2_move();
		p_turn = PLAYER2;
		if(check_winner(PLAYER2))
			if(!update_points(PLAYER2, player_table))
				break;
	}
	print_UI(player_table);
	if(p_turn == PLAYER1)
		printf("%s WON!\n",player_table->p1_name);
	else if(p_turn == PLAYER2)
		printf("%s WON!\n",player_table->p2_name);

	free(player_table);
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
	update_board(PLAYER1, v_move);
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
	update_board(PLAYER2, v_move);
}

int check_board(int pos)
{
	return grid_status[pos] == 0 ? 1 : 0;
}

void update_board(int player, int pos)
{
	grid_status[pos] = player;
}

// Check that move is valid
char valid_move(char *move)
{
	char valid = 0;

	if(move[0] == 'T')
	{
		if(move[1] == 'L')
			valid = 1;
		else if(move[1] == 'M')
			valid = 2;
		else if(move[1] == 'R')
			valid = 3;
	}
	else if(move[0] == 'M')
	{
		if(move[1] == 'L')
			valid = 4;
		else if(move[1] == 'M')
			valid = 5;
		else if(move[1] == 'R')
			valid = 6;
	}
	else if(move[0] == 'B')
	{
		if(move[1] == 'L')
			valid = 7;
		else if(move[1] == 'M')
			valid = 8;
		else if(move[1] == 'R')
			valid = 9;
	}

	if(!check_board(valid))
		valid = 0;

	return valid;
}

char check_winner(int player)
{
	char winner = 0;
	if((grid_status[1] & grid_status[2] & grid_status[3]) & player)
		winner = 1;
	else if((grid_status[4] & grid_status[5] & grid_status[6]) & player)
		winner = 1;
	else if((grid_status[7] & grid_status[8] & grid_status[9]) & player)
		winner = 1;
	else if((grid_status[1] & grid_status[4] & grid_status[7]) & player)
		winner = 1;
	else if((grid_status[2] & grid_status[5] & grid_status[8]) & player)
		winner = 1;
	else if((grid_status[3] & grid_status[6] & grid_status[9]) & player)
		winner = 1;
	else if((grid_status[1] & grid_status[5] & grid_status[9]) & player)
		winner = 1;
	else if((grid_status[3] & grid_status[5] & grid_status[7]) & player)
		winner = 1;
	else
		winner = 0;
	return winner;

}

char update_points(int player, players_t *ptable)
{
	if(player == PLAYER1)
		ptable->p1_points++;
	else if(player == PLAYER2)
		ptable->p2_points++;
	return 0;
}
