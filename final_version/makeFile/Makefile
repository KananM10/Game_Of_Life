CC = gcc

TARGET =  gameOfLife

SRC = src
INC = inc
BIN = bin

MODE = GRAPHICAL
TEXT_MODE = TEXT

ifeq ($(MODE), $(TEXT_MODE))
	SOURCE = main.c drawer.c game.c 
	CFLAGS = -Wall -I include -g -I$(INC)
else
	SOURCE = main_sdl.c game_sdl.c
	CFLAGS = -Wall -I include -g -lSDL2 -lSDL2main -lSDL2_ttf -I$(INC)
endif


OBJECT = $(patsubst %,$(BIN)/%,$(notdir $(SOURCE:.c=.o)))

#-----------------------------------------

$(BIN)/$(TARGET) : $(OBJECT)
	$(CC) $^ -o $@ $(CFLAGS)

$(BIN)/%.o : $(SRC)/%.c
	$(CC) $< -c -o $@ $(CFLAGS)


#------------------------------------------

all: clean $(BIN)/$(TARGET) 

run: 
	$(BIN)/$(TARGET)

clean:
	rm -f $(OBJECT) $(BIN)/$(TARGET)

doc:
	@doxygen

dist:
	@tar -Jcvf GameOfLife_KananMikayilov_ShoykyatSharafyabi.tar.xz Makefile Doxyfile src/ inc/

distclean:
	@rm -r *.tar.xz