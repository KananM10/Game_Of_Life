#include "drawer.h"
#include "drawer.c"

#include "game.h"
#include "game.c"


int main() {

	grid ga;
	init_grid(&ga);
	set_grid(ga);
	start_game(&ga);
	free_grid (&ga);
	return 0;
}
