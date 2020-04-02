// LIBRARIES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include <time.h>
// HEADER
#include "header.h"
// CONFIGURATION
#define ROWS 6
#define COLUMNS 7
#define REDPLAYER 1
#define YELLOWPLAYER 2
int main(void){
	// SETUP
    Game demo[ROWS*COLUMNS+1];
    int running = 1;
	int player = 1;
    int location = -1;
    int turncounter = 0;
    int valid;
	int boardmatrix[ROWS][COLUMNS] = {
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
	}
	// POINTERS
	int* boardptr = &boardmatrix;
	FILE* demo = fopen("lastGame","a");
	// CUSTOMIZABLE STRINGS
	char redWins[] =	"\n\tThe game has ended. Red wins!\n";
	char yellowWins[] =	"\n\tThe game has ended. Yellow wins!\n";
	char tie[] =	"\n\tThe game has ended in a draw!";
    // BEGIN
    resetDisplay();
    while (running == 1){
        if (testforwin(boardptr) != 0){
			break;
		}
        // PROMPT AND CHECK
        while (1){
            location = promptUser(player);
            valid = checkValidity(boardptr, location);
            if (valid == 1){
                break;
            }
            else {
            }
        }
        // GAME ACTIONS
        drawmodBoard(boardptr, player, column);
        fprintf("\n");
		turncounter++;
		switch (player) {
			case 1: 
				player = 2;
				break;
			case 2: 
				player = 1;
				break;
		}
    }
    // AFTER GAME
	switch (testforwin(boardptr)){
		case 1: 
			printf("%s",redWins);
			break;
		case 2: 
			printf("%s",yellowWins);
			break;
		default: 
			printf("%s",tie);
	}
	fclose("demo");
    return 0;
}
// END MAIN
