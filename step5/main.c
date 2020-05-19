#include "./console/drawer.h"
#include "./game/game.h"


int main() {

	grid g, gc;
	char c;
	int n;
	char filename[20];

	printf("With user inputting own size of the grid, the game will produce the board with random alive cells\nThus, the game could be boring and could finish fast\n");
	printf("For this reason, we added new mode, now you could enter filename where we made our configurations for this game\nso it could be more interesting\n Do you want to enter your own configuration? (Y/N) ");

	scanf("%c", &c);
	if(c == 'Y' || c == 'y'){
		init_grid(&g);
	}else{
		printf("Then add please the filename num, which is between 0 and 10 (not included) \n");
		while(1){
			scanf("%d", &n);
			if(n > 0 && n < 10)
				break;
		}

		sprintf(filename, "../grids/grid%d.txt", n);
		printf("%s\n",filename);
		init_grid_from_file(filename,&g);
	}

	allocate_grid (g.nbrows, &gc);
	copy_grid(g, gc);

	start_game(&g, &gc);

	free_grid(&g);
	free_grid(&gc);
	return 0;
}
