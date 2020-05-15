#include "game.h"


//---------------------------------------------------------------------
void init_grid (grid* g){

	int i,j,n,s,alive;

	printf("Enter the size to be in the matrix, maximum 10: ");
	while(1){
		scanf("%d", &s);
		if(s > 0 && s <= 10)
			break;
		else
			printf("The size of the matrix should be between 0 and 10 included: \n");
	}
	
	allocate_grid(s,g);

	printf("Enter the number of alive cells in the matrix: ");
	
	while(1){
		scanf("%d", &alive);
		if(alive < (g->nbrows * g->nbcols))
			break;
		else
			printf("The number of living cells should be at most of size (number of all cells) of the grid\n");
	}

	for (n = 0; n < alive; ++n){
	
		while(1){
			i = rand() % (g->nbrows);
			j = rand() % (g->nbcols);

			if( !is_alive(i, j, *g) )
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

	g->cells = calloc(g->nbrows, sizeof(int*));
	if(g->cells != NULL){
        for(int i = 0; i < g->nbrows; ++i) {
            g->cells[i] = calloc(g->nbcols, sizeof(int));
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


