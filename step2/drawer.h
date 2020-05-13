#ifndef __DRAWER_H__
#define __DRAWER_H__

#include <stdio.h>
#include "game.h"
#include "ansi.h"


//Setting grid in the terminal
void set_grid (grid g);


//Function to start the game
void start_game(grid *g, grid *gc);

#endif
