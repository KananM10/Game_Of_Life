#include "drawer.h"

//-------------------------------------------------------------------------

void set_grid (grid g, int mode){
	delete_ecran();

	if(mode) 
		printf("Mode circular\n");
	else 
		printf("Mode clipped\n");
	printf("Evoluation: %d\n", g.age);
	printf("To exit from program click q\n");
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
	int circular = 1;
	set_grid(*gc,circular);
	char c = getchar();
	int (*pt_neighbours)(int, int, grid) = check_neighbours_clipped;
	while (c != 'q') 
	{
		switch (c) {
            case '\n' :
            { 
                evoluation(g, gc, pt_neighbours);
                break;
            }
            
            case 'c':
            { 
                circular = !circular;
                if(circular) 
                	pt_neighbours = &check_neighbours_circular;
                else 
                	pt_neighbours = &check_neighbours_clipped;
                getchar ();
                break;
            }
            
            default :
            {
                printf("\n\e[1A");
                break;
            }
        }
		
        set_grid(*gc,circular);
        c = getchar();
    	
    }
	return;
}

//-------------------------------------------------------------------------