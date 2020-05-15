CC = gcc

all: gameOfLife

gameOfLife: main.o game.o
	$(CC) main.o game.o -o gameOfLife -lSDL2main -lSDL2  -lSDL2_ttf

main.o: main.c
	$(CC) -c main.c 

# drawer.o: drawer.c drawer.h game.h
# 	$(CC) -c drawer.c

game.o: game.c game.h
	$(CC) -c game.c


clean: 
	rm gameOfLife *.o

doc:
	@doxygen

dist:
	@tar -Jcvf version1.tar.xz makefile doxygen  README.md

distclean:
	@rm -r doc
	@rm -r *.tar.xz


