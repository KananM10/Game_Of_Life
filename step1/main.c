#include "drawer.h"
#include "game.h"


int main() {

	grid ga;
	init_grid(&ga);
	set_grid(ga);
	start_game(&ga);
	free_grid (&ga);
	return 0;
}
