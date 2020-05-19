#ifndef __DRAWER_H__
#define __DRAWER_H__

#include <stdio.h>
#include "../game/game.h"


//some functions to help run game in the terminal (ansi code)

static inline void clear_screen(){ printf("\033[2J"); }

static inline void hide_cursor(){ printf("\033[?25l"); }

static inline void show_cursor(){ printf("\033[?25h"); }

static inline void move_cursor_to(int x,int y){ printf("\033[%d;%dH", x+10, y); }

static inline void set_color(int c){ printf("\033[%dm  ", c); }

static inline void reset(){ printf("\033[0m"); }

static inline void delete_ecran(){ printf("\e[1;1H\e[2J"); }


/*
 * Setting grid in the terminal
 */
void set_grid (grid g, int mode);


/*
 * Function to start the game
 */
void start_game(grid *g, grid *gc);

#endif
