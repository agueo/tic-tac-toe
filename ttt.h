#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H
#include <stdio.h>
#include <stdlib.h>

#define LENGTH 17
#define WIDTH 17
#define V_WALL '|'
#define H_WALL '-'
#define JOINT '+'
#define X_O '#'
#define CELL_SIZE 5

// Coordinates of Top row
#define TL_X 0
#define TL_Y 0
#define TM_X 6
#define TM_Y 0
#define TR_X 12
#define TR_Y 0

// Coordinates of Middle row
#define ML_X 0
#define ML_Y 6
#define MM_X 6
#define MM_Y 6
#define MR_X 12
#define MR_Y 6

// Coordinates of Bottom row
#define BL_X 0
#define BL_Y 12
#define BM_X 6
#define BM_Y 12
#define BR_X 12
#define BR_Y 12

typedef struct players
{
	char *p1_name;
	int p1_points;
	char *p2_name;
	int p2_points;
} players_t;

// Might use an array for this;
typedef struct _grid
{
	int tl;
	int tm;
	int tr;
	int ml;
	int mm;
	int mr;
	int bl;
	int bm;
	int br;
} grid_stat;

// display functions
char init_game(players_t *pt);
void print_grid(void);
void print_UI(players_t *pt);

// player functions
void player1_move(void);
void player2_move(void);
char valid_move(char *);


// grid manipulation
void draw_x(int x, int y);
void draw_o(int x, int y);
void clear_board(void);
int check_board(void);
void update_points(int p, int player);

#endif
