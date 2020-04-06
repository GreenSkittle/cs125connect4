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
int main(void){
	// SETUP
    Game demo[ROWS*COLUMNS+1];
    int running = 1;
	int player = 1;
    int location = -1;
    int turncounter = 0;
    int valid = -1;
	int boardmatrix[ROWS][COLUMNS] = {
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
	};
	// POINTERS
	FILE* lastdemo = fopen("lastGame.txt","w");
    FILE* alldemos = fopen("allGames.txt","a");
	// CUSTOMIZABLE STRINGS
	char redWins[] =	"\n\tThe game has ended. Red wins!\n";
	char yellowWins[] =	"\n\tThe game has ended. Yellow wins!\n";
	char tie[] =	"\n\tThe game has ended in a draw!\n";
    // BEGIN
    resetDisplay();
    while (running == 1){
        if (testforwin(boardmatrix[ROWS][COLUMNS]) != 0){
			break;
		}
        // PROMPT AND CHECK
        while (1){
            location = promptUser(player);
            valid = checkValidity(boardmatrix[ROWS][COLUMNS], location);
            if (valid == 1){
                break;
            }
            else {
            }
        }
        // GAME ACTIONS AND DEMO
        drawmodBoard(boardmatrix[ROWS][COLUMNS], player, column);
        fprintf("\n"); /* write to both files */
		turncounter++;
		switch (player) {
			case 1: 
				player = 2;
				break;
			case 2: 
				player = 1;
				break;
            default:
                player = 1;
                break;
		}
    }
    // AFTER GAME
	switch (testforwin(boardmatrix[ROWS][COLUMNS])){
		case 1: 
			printf("%s",redWins);
			break;
		case 2: 
			printf("%s",yellowWins);
			break;
		default: //need fix here
			printf("%s",tie);
	}
	fclose("lastdemo");
    fclose("alldemos");
    return 0;
}
// END MAIN
