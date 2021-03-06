#include "./game_sdl/game_sdl.h"


int main() {

	grid g, gc;
    char c;
    int n;
    char filename[20];    
    init_grid(&g);
    
	allocate_grid (g.nbrows, &gc);
	copy_grid(g, gc);

	// start_game(&g, &gc);
    SDL_Renderer *g_renderer = NULL; /* for drawing to the screen */
    SDL_Window   *g_window   = NULL; /* the window given to us by the OS */
    int circular = 1;
    int (*pt_neighbours)(int, int, grid) = check_neighbours_clipped;

	if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        fprintf(stderr,"Problem can not init SDL2 \n");
        return 0;
    }

    g_window = SDL_CreateWindow("Game Of Life",
                                          SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                          420, 420, SDL_WINDOW_SHOWN|SDL_WINDOW_ALLOW_HIGHDPI);
    g_renderer = SDL_CreateRenderer(g_window, -1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
    assert (g_renderer != NULL);

    int quit = 0;
    while (!quit)
    {
        SDL_Event event;
        while (!quit && SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                {
                    quit = 1;
                    break;
                }
                
                case SDL_KEYDOWN:
                {
                    
                    switch(event.key.keysym.sym){
                        case SDLK_c:
                        {
                            circular = !circular;
                            if(circular) pt_neighbours = &check_neighbours_circular;
                            else pt_neighbours = &check_neighbours_clipped;
                            break;
                        } 
                        case SDLK_n:
                        {
                            evoluation(&g, &gc, pt_neighbours);
                            break;
                        }
                    }
                    break;

                }
            }
        }

        display_grid(gc, g_renderer, circular );

        // SDL_RenderPresent(g_renderer);
    }


        
	free_grid(&g);
	free_grid(&gc);

    /* clean up when we're done */
    SDL_DestroyRenderer(g_renderer);
    SDL_DestroyWindow(g_window);
    SDL_Quit();
    
    return 0;
}
