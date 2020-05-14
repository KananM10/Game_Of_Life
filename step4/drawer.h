#ifndef __DRAWER_H__
#define __DRAWER_H__

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <SDL2/SDL.h>
#include "game.h"


int initialize_display (SDL_Renderer *g_renderer, SDL_Window   *g_window );

//-------------------------------------------------------------------------

void display_grid ( grid g , SDL_Renderer *g_renderer);

//-------------------------------------------------------------------------

// void handle_events( grid *g, grid *gc, SDL_Renderer *g_renderer);

//-------------------------------------------------------------------------

void terminate_display(SDL_Renderer *g_renderer, SDL_Window   *g_window );

#endif
