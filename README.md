The aim of this project is to create a Game of Life for Developement Technique course.

	The Game of Life is, in reality, a cellular automaton defined in 1970 by the English mathematician John Conway in order to try to solve a problem raised by a mathematician, father of computer science, John Von Neumann. 

	It is not strictly speaking a game: it does not require the intervention of a human player, except to fix the initial conditions of the game. It consists of a universe in which live cells evolve according to rules precise evolution. In the original version described by John Conway, the universe is defined on a two-dimensional grid, of variable size, where each cell is a cell that can take two different states: dead or alive. The transition from one state to another is guided by the following rules of evolution:

	• A dead cell at time t becomes alive at time t + 1 if and only if it has exactly 3 living 
		cells in its vicinity.

	• A living cell at time t remains alive at time t + 1 if and only if it has exactly 2
		or 3 living cells in its vicinity, otherwise it dies.

	• All other cells dies

	• The neighborhood used is the 8-neighborhood: for a given cell, its neighbors
		are the 8 cells that surround it


In this project, there are 5 directories, because the project was made by steps:

	• Step 1

	In this step the program just asks from user to enter the number of rows and columns to initiate a grid, and then asks for the number of alive cells, and then makes random cells alive. This step just creates random board, there is no evoluation. And user can compile the program by writing:

				make all
				./gameOfLife

	• Step 2

	In this step the program totally works in circular mode, and as in step 1 , user should enter ne size of grid and the number of cells, the game works in the terminal by using ansi code, and the game can evoluate by clicking enter key.  User can compile the program by writing:

		mkdir build && cd build/ && cmake .. && make && ./gameOfLife


	• Step 3

	In this step the clipped mode was created, and the program totally works in both modes, and as in previous steps, user should enter ne size of grid and the number of cells, the game works in the terminal by using ansi code, and the game can evoluate by clicking enter key and use can change the mode of the game by clicking to c key. User can compile the program by writing:

		mkdir build && cd build/ && cmake .. && make && ./gameOfLife

	• Step 4

	In this step the game was written in SDL mode, all previous game features work in this step, in new window will be running the game, while in the terminal the information about the game will be written. To evoluate user should click to n key, to change the mode user should click to c key, to quit user should just close the window. To compile and run this game user should write:

		mkdir build && cd build/ && cmake .. && make && ./gameOfLife
	

	• Final step is the main step of this project, where the final version of game with 2 modes (circular, clipped) are written in both terminal mode and sdl mode. Plus now user can choose: whether choose a specific files to generate the game and make it more interesting, or just enter the size of the grid and the number of alive cells which will create a random board. User can compile the program by writing:

		mkdir build && cd build/ && cmake .. && make

		But now user can also choose in which mode (terminal || SDL) it wants to run this game.

		To run it in the terminal:

			./gameOfLife

		To run it in the SDL mode:

			./gameOfLife_SDL
