// TITLE BLOCK
// LIBRARIES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include <time.h>
// CONFIGURATION
#define ROWS 6
#define COLUMNS 7
#define REDPLAYER 1
#define YELLOWPLAYER 2
// FUNCTION PROTOTYPES
void drawmodBoard(int* boardptr, int column, int player);
void resetDisplay(void);
int testforwin(int* boardptr);
int promptUser(int player);
int checkValidity(int* boardptr, int column);
// GLOBAL
// MAIN
int main(void){
	// VARIABLES
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
	// POINTER
	int* boardptr = &boardmatrix;
	// STRINGS
	char redWins[] =	"\n\tThe game has ended. Red wins!\n";
	char yellowWins[] =	"\n\tThe game has ended. Yellow wins!\n";
	char tie[] =		"\n\tThe game has ended in a draw!";
	// BEGIN
    resetDisplay(void);
    while (running == 1){
        if (testforwin(*boardptr) !=0){
			break;
		}
	// PROMPT AND CHECK
        while (1){
            location = promptUser(player);
            valid = checkValidity(*boardptr, location);
            if (valid == 1){
                break;
            }
            else {
            }
        }
    // DO ACTIONS
        drawmodBoard(*boardptr);
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
	switch (testforwin(*boardptr)){
		case 1: 
			printf("%s",redWins);
			break;
		case 2: 
			printf("%s",yellowWins);
			break;
		default: 
			printf("%s",tie);
	}
    return 0;
}
// END MAIN
