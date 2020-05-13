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
