#include "game.h"

//---------------------------------------------------------------------
void init_grid (grid* g){

	int i,j,n,s,alive;

	printf("Enter the size to be in the matrix: ");
	scanf("%d", &s);
	
	allocate_grid(s,g);

	printf("Enter the number of alive cells in the matrix: ");
	scanf("%d", &alive);
	for (n = 0; n < alive; ++n){
	
		while(1){
			i = rand() % (g->nbrows);
			j = rand() % (g->nbcols);

			if( !is_alive(i, j, *g))
				break;
		}	
		set_alive(i,j,*g);
	}

	g->age = 0;
	return;
}

//---------------------------------------------------------------------

void allocate_grid(int size, grid*  g){
	g->nbrows = size;
	g->nbcols = size;
  	g->age = 0;

	g->cells = calloc(g->nbrows, 2*sizeof(int*));
	if(g->cells != NULL){
        for(int i = 0; i < g->nbrows; ++i) {
            g->cells[i] = calloc(g->nbcols, 2*sizeof(int));
            if (g->cells[i] == NULL) {
              printf("Impossible to allocate memory.\n");
              exit(0);
            }
        }
	}else{
        printf("Impossible to allocate memory.\n");
        exit(0);
	}
}

//---------------------------------------------------------------------

void free_grid(grid* g){
	for(int i = 0; i < g->nbrows; ++i){
		free(g->cells[i]);
	}
	free(g->cells);
}

//---------------------------------------------------------------------


void copy_grid(grid gs, grid gd){
	int i, j;
	for (i=0; i<gs.nbrows; ++i) {
		for (j=0; j<gs.nbcols; ++j) {
			gd.cells[i][j] = gs.cells[i][j];
		}
	}
	return;
}

//-----------------------------------------------------------------------------

int check_neighbours_circular(int i, int j, grid g){
	int v = 0, r = g.nbrows, c = g.nbcols;
	v+= is_alive(module(i-1,r),module(j-1,c),g); 	// left top
	v+= is_alive(module(i-1,r),module(j,c),g); 		// top same col
	v+= is_alive(module(i-1,r),module(j+1,c),g);	// right top
	v+= is_alive(module(i,r),module(j-1,c),g);		// same row left
	v+= is_alive(module(i,r),module(j+1,c),g);		// same row right
	v+= is_alive(module(i+1,r),module(j-1,c),g);	// bottom left
	v+= is_alive(module(i+1,r),module(j,c),g);		//bottom same col
	v+= is_alive(module(i+1,r),module(j+1,c),g);	//bottom right

	return v;
}

//---------------------------------------------------------------------

int check_neighbours_clipped(int i, int j, grid g){
	int v = 0, r = g.nbrows, c = g.nbcols;
	v += i > 0 && j > 0 && is_alive(i-1, j-1, g); 		// left top
	v += i > 0 && is_alive(i-1, j, g); 					// top same col
	v += i > 0 && j < c && is_alive(i-1, j+1, g); 		// right top
	v += j > 0 && is_alive(i, j-1, g); 					// same row left
	v += j < c && is_alive(i, j+1, g); 					// same row right
	v += i < r -1 && j > 0 && is_alive(i+1, j-1, g); 	// bottom left
	v += i < r -1 && is_alive(i+1, j, g); 				// bottom same col
	v += i < r -1 && j < c && is_alive(i+1, j+1, g); 	// bottom right
	return v;
}

//---------------------------------------------------------------------


void evoluation (grid *g, grid *gc, int (*check_neighbours)(int, int, grid)){
    copy_grid(*g,*gc); 
    int i,j,r = g->nbrows, c = g->nbcols, v;
    for (i = 0; i < r; i++){
  		for (j = 0; j < c; ++j){
		   
			v = check_neighbours(i, j, *gc);
			if (is_alive(i,j,*g)){ 
			  if ( v != 2 && v != 3 ) {
			  	set_dead(i, j, *g);
			  }
			}else if ( v == 3 ) {
			    set_alive(i, j, *g);
			}
        }
  	}
  gc->age++;
  return;
}

//---------------------------------------------------------------------

void display_grid ( grid g , SDL_Renderer *g_renderer, SDL_Texture *textTexture, SDL_Texture *textTexture1, SDL_Texture *textTexture2, SDL_Texture *textTexture3, int mode) {
	

	char *string1 = '\0';
	if(mode)
		string1 = "Mode: circular";
	else
		string1 = "Mode: clipped";

	char string[16];
	sprintf(string, "Evoluation: %d", g.age);

	TTF_Init();
    TTF_Font *font = TTF_OpenFont("ArialMT.ttf", 25);
    SDL_Color textColor = { 131, 148, 150};
   
   //--------------------------------------------------------------------------------------------------
    SDL_Surface *textSurface = TTF_RenderText_Solid(font, "To evoluate push n", textColor);
    textTexture = SDL_CreateTextureFromSurface(g_renderer, textSurface);

    SDL_Rect textRect;
    textRect.x = 420;
    textRect.y = 10;
    textRect.w = textSurface->w;
    textRect.h = textSurface->h;

    SDL_FreeSurface(textSurface);

    //-----------------------------------------------------------------------------------------------
    SDL_Surface *textSurface1 = TTF_RenderText_Solid(font, string, textColor);
    textTexture1 = SDL_CreateTextureFromSurface(g_renderer, textSurface1);

    SDL_Rect textRect1;
    textRect1.x = 420;
    textRect1.y = 40;
    textRect1.w = textSurface1->w;
    textRect1.h = textSurface1->h;

    SDL_FreeSurface(textSurface1);

    //---------------------------------------------------------------------------------------------
    SDL_Surface *textSurface2 = TTF_RenderText_Solid(font, "To change mode push c", textColor);
    textTexture2 = SDL_CreateTextureFromSurface(g_renderer, textSurface2);

    SDL_Rect textRect2;
    textRect2.x = 420;
    textRect2.y = 70;
    textRect2.w = textSurface2->w;
    textRect2.h = textSurface2->h;

    SDL_FreeSurface(textSurface2);


    //------------------------------------------------------------------------------------------------
    SDL_Surface *textSurface3 = TTF_RenderText_Solid(font, string1, textColor);
    textTexture3 = SDL_CreateTextureFromSurface(g_renderer, textSurface3);

    SDL_Rect textRect3;
    textRect3.x = 420;
    textRect3.y = 100;
    textRect3.w = textSurface3->w;
    textRect3.h = textSurface3->h;

    SDL_FreeSurface(textSurface3);

    //----------------------------------------------------------------------------------------------
    TTF_Quit();

    
    /* Set draw colour to white */
    SDL_SetRenderDrawColor(g_renderer, 0, 43, 54, SDL_ALPHA_OPAQUE);
    
    int CELL_SIZE = 400 / g.nbrows;

    /* clear the screen */
    SDL_RenderClear(g_renderer);

    /* Set draw colour to black */
    SDL_SetRenderDrawColor(g_renderer, 34, 108, 128, SDL_ALPHA_OPAQUE);

    /* Draw row lines */
    for(int i=0; i<=g.nbrows; i++) {
        SDL_RenderDrawLine(g_renderer, 
            
                0, CELL_SIZE*i,          /* x1, y1 */
                400, CELL_SIZE*i /* x2, y2 */
        );
    }

    /* Draw column lines */
    for(int i=0; i<=g.nbcols; i++) {            
        SDL_RenderDrawLine(g_renderer,                 
                CELL_SIZE*i, 0,           /* x1, y1 */                
                CELL_SIZE*i, 400  /* x2, y2 */
        );
    }

    /* Set draw colour to blue */
    SDL_SetRenderDrawColor(g_renderer, 220, 50, 47, SDL_ALPHA_OPAQUE);

    /* Render the game of life */
    for( int x=0; x<g.nbrows; x++ ) {
        for( int y=0; y<g.nbcols; y++) {
            if(is_alive(x, y, g)) {
                SDL_Rect r = {
                    x*CELL_SIZE, /*   x    */
                    y*CELL_SIZE, /*   y    */
                    CELL_SIZE-1,   /* width  */
                    CELL_SIZE-1    /* height */
                };
                SDL_RenderFillRect(g_renderer, &r);
            }
        }
    }
    SDL_RenderCopy(g_renderer, textTexture, NULL, &textRect);
    SDL_RenderCopy(g_renderer, textTexture1, NULL, &textRect1);
    SDL_RenderCopy(g_renderer, textTexture2, NULL, &textRect2);
    SDL_RenderCopy(g_renderer, textTexture3, NULL, &textRect3);

    SDL_RenderPresent(g_renderer);
}