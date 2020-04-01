connectFour: main.o /* all functions */

main.o: main.c header.h
	gcc -c main.c
