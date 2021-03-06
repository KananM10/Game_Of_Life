#ifndef __GAME_H__
#define __GAME_H__

#include <stdlib.h>
#include <stdio.h>

typedef struct grid {
    int nbrows; 	  //number of rows
    int nbcols; 	 //number of cols
    int **cells; 	//table consist of cells
    int age; 	   //age of grid
} grid;


//allocate matrix with the size row * col and set all cells to dead
void allocate_grid (int size, grid* g);

//frees the grid
void free_grid(grid* g);


//initiates the grid
void init_grid(grid* g);


//set alive a certain cell in the grid
static inline void set_alive(int i, int j, grid g){g.cells[i][j] = 1;}

//checks if cells is alive
static inline int is_alive(int i, int j, grid g){return g.cells[i][j] == 1;}


//set dead a certain cell in the grid
static inline void set_dead(int i, int j, grid g){g.cells[i][j] = 0;}


//checks if cell is dead
static inline int is_dead(int i, int j, grid g){return g.cells[i][j] == 0;}


void copy_grid (grid gs, grid gd);

//Checks how many neighbours cell has
int check_neighbours(int i, int j, grid g);


//Updating cell (evoluation)
void evoluation (grid *g, grid *gc);

#endif
