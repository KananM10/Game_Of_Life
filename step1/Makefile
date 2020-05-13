CC = gcc


all: clean gameOfLife

gameOfLife: main.c
	$(CC) main.c -o gameOfLife

clean: 
	rm -f gameOfLife

doc:
	@doxygen

dist:
	@tar -Jcvf version1.tar.xz makefile doxygen  README.md

distclean:
	@rm -r doc
	@rm -r *.tar.xz
