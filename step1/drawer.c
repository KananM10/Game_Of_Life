#include "drawer.h"

//-------------------------------------------------------------------------

void set_grid (grid g){
	delete_ecran();

	printf("Testing the random board, no evoluation:\n");
	printf("To quit from the game push q. \n");
	hide_cursor();

	for(int i= 0; i<g.nbrows; ++i){
		move_cursor_to(i+2,10);
		for(int j= 0; j<g.nbcols; ++j){
			(is_alive(i, j, g)) ? set_color(41) : set_color(40); //41 for red color and 40 for black color
		}
	}

	reset();
	show_cursor();
	move_cursor_to(g.nbrows+5,0);

	return;
}

//-------------------------------------------------------------------------

void start_game(grid *ga){
	char c = getchar();
	while (c != 'q'){
		switch (c) {
            case 'n' :
    		{   
                break;
            }
            
            default :
            {
                printf("\n\e[1A");
                break;
            }
        }
        set_grid(*ga);
        c = getchar();
    }
	return;
}

//-------------------------------------------------------------------------