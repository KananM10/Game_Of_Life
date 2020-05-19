#include "game_sdl.h"


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

void init_grid_from_file (char * filename, grid* g){
    FILE * pfile;
    pfile = fopen(filename, "r");
    // assert (pfile != NULL);

    int i,j,n,size,alive;

    fscanf(pfile, "%d", & size);


    allocate_grid(size,g);

    fscanf(pfile, "%d", & alive);
    for (n=0; n< alive; ++n){
        fscanf(pfile, "%d", & i);
        fscanf(pfile, "%d", & j);
        set_alive(i,j,*g);
    }
    
    fclose (pfile);

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


void copy_grid (grid gs, grid gd){
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

void display_grid ( grid g , SDL_Renderer *g_renderer, int mode) {
	
   

    printf("\e[1;1H\e[2J"); // delete_ecran
    printf("\033[31m");
    printf("\033[%d;%dH", 2, 0); //move_cursor_to
    printf("Evoluation: %d\n", g.age);
    if(mode) printf("Mode circular\n\n");
    else  printf("Mode clipped\n");
    printf("To evoluate please click n. \n");
    printf("To change mode click c\n");
    printf("To exit from program click q\n");
    printf("\033[?25l"); // hide_cursor


       
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
            
                10, CELL_SIZE*i+10,          /* x1, y1 */
                410, CELL_SIZE*i+10/* x2, y2 */
        );
    }

    /* Draw column lines */
    for(int i=0; i<=g.nbcols; i++) {            
        SDL_RenderDrawLine(g_renderer,                 
                CELL_SIZE*i+10, 10,    /* x1, y1 */                
                CELL_SIZE*i+10, 410  /* x2, y2 */
        );
    }
    /* Set draw colour to blue */
    SDL_SetRenderDrawColor(g_renderer, 220, 50, 47, SDL_ALPHA_OPAQUE);

    /* Render the game of life */
    for( int y=0; y<g.nbrows; y++ ) {
        for( int x=0; x<g.nbcols; x++) {
            if(is_alive(y, x, g)) {
                SDL_Rect r = {
                    x*CELL_SIZE+11, /*   x    */
                    y*CELL_SIZE+11, /*   y    */
                    CELL_SIZE-1,   /* width  */
                    CELL_SIZE-1    /* height */
                };
                SDL_RenderFillRect(g_renderer, &r);
            }
        }
    }

    SDL_RenderPresent(g_renderer);

    printf("\033[0m"); // reset
    printf("\033[?25h"); // show_cursor
    printf("\033[%d;%dH", g.nbrows+5, 0); //move_cursor_to
}