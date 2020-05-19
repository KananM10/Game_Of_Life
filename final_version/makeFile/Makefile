CC = gcc

TARGET1 =  gameOfLife
TARGET2 =  gameOfLife_SDL

SRC = src
INC = inc
BIN = bin

MODE = GRAPHICAL
TEXT_MODE = TEXT

SOURCE1 = main.c drawer.c game.c 
CFLAGS1 = -Wall -I include -g -I$(INC)

SOURCE2 = main_sdl.c game_sdl.c
CFLAGS2 = -Wall -I include -g -lSDL2 -lSDL2main -I$(INC)



OBJECT1 = $(patsubst %,$(BIN)/%,$(notdir $(SOURCE1:.c=.o)))
OBJECT2 = $(patsubst %,$(BIN)/%,$(notdir $(SOURCE2:.c=.o)))

#-----------------------------------------

$(BIN)/$(TARGET1) : $(OBJECT1)
	$(CC) $^ -o $@ $(CFLAGS1)

$(BIN)/$(TARGET2) : $(OBJECT2)
	$(CC) $^ -o $@ $(CFLAGS2)

$(BIN)/%.o : $(SRC)/%.c
	$(CC) $< -c -o $@ $(CFLAGS2)

$(BIN)/test: $(SRC)/ctest.c $(SRC)/game.c
	$(CC) $(SRC)/game.c $(SRC)/ctest.c -o $(BIN)/ctest -lcunit -I$(INC) -I/lib/include -L/lib/CUnit/lib


#------------------------------------------

all: clean $(BIN)/$(TARGET1) $(BIN)/$(TARGET2) $(BIN)/test

clean:
	rm -f $(OBJECT1) $(OBJECT2) $(BIN)/$(TARGET1) $(BIN)/$(TARGET2)

doc:
	@doxygen

dist:
	@tar -Jcvf GameOfLife_KananMikayilov_ShoykyatSharafyabi.tar.xz Makefile Doxyfile src/ inc/

distclean:
	@rm -r *.tar.xz