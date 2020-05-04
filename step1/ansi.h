#ifndef __ANSI_H__
#define __ANSI_H__

#include <stdlib.h>
#include <stdio.h>


//simple color values for background and fronground
int blackbg = 40;
int redbg   = 41;


//some functions to help run game in the terminal (ansi code)

void clear_screen(){ printf("\033[2J"); }

void hide_cursor(){ printf("\033[?25l"); }

void show_cursor(){ printf("\033[?25h"); }

void move_cursor_to(int y,int x){ printf("\033[%d;%dH", y + 5, x); }

void set_color(int c){ printf("\033[%dm  ", c); }

void reset(){ printf("\033[0m"); }

void delete_ecran(){ printf("\e[1;1H\e[2J"); }


#endif