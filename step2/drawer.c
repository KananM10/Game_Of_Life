#include "drawer.h"

//-------------------------------------------------------------------------

void set_grid (grid g){
	delete_ecran();

	printf("Evoluation: %d\n", g.age);
	// moving_cursor_down(4);

	hide_cursor();

	for(int i= 0; i < g.nbrows; ++i){
		move_cursor_to(i+2,10);
		for(int j= 0; j < g.nbcols; ++j){
			( is_alive(i, j, g) ) ? set_color(redbg) : set_color(blackbg);
		}
	}

	reset();
	show_cursor();
	move_cursor_to(g.nbrows+5,0);

	return;
}

//-------------------------------------------------------------------------

void start_game(grid *g, grid *gc){
	set_grid(*gc);
	char c = getchar();
	while (c != 'q')
	{
		switch (c) {
            case '\n' :
            { 
                evoluation(g, gc);
                break;
            }
            default:
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