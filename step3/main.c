#include "drawer.h"
#include "drawer.c"

#include "game.h"
#include "game.c"


int main() {

	grid g, gc;
	init_grid(&g);
	allocate_grid (g.nbrows, &gc);
	copy_grid(g, gc);

	start_game(&g, &gc);

	free_grid(&g);
	free_grid(&gc);
	return 0;
}
