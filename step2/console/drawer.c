#include "drawer.h"

//-------------------------------------------------------------------------

void set_grid (grid g){
	delete_ecran();

	printf("To evoluate, please click enter. \n");
	printf("You are in the clipped mode of the game. \n\n");
	printf("Evoluation: %d\n", g.age);
	printf("To quit from the game push q. \n");
	hide_cursor();

	for(int i= 0; i < g.nbrows; ++i){
		move_cursor_to(i+2,10);
		for(int j= 0; j < g.nbcols; ++j){
			( is_alive(i, j, g) ) ? set_color(41) : set_color(40); //41 for red and 40 for black
		}
	}

	reset();
	show_cursor();
	move_cursor_to(g.nbrows+5,0);

	return;
}

//-------------------------------------------------------------------------

void start_game(grid *g, grid *gc){
	char c = getchar();
	while (c != 'q')
	{

        switch (c) {
            case '\n' :
            { 
                evoluation(g, gc);
                break;
            }
            
            default :
            {
                printf("\n\e[1A");
                break;
            }
        }
        
		
        set_grid(*gc);
        c = getchar();
    	
    }
	return;
}

//-------------------------------------------------------------------------