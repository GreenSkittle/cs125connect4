#include "header.h"
int main(void){
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
	char redWins[] =	"\n The game has ended. Player 1 wins!\n";
	char yellowWins[] =	"\n The game has ended. Player 2 wins!\n";
	char tie[] =	    "\n The game has ended in a draw!\n";
	resetdisplay();
    while (running == 1){
        drawmodBoard(boardmatrix, -1, -1);
        if (testforwin(boardmatrix) != 0){
			break;
		}
        // PROMPT AND CHECK
        while (1){
            location = promptUser(player);
            valid = checkValidity(boardmatrix, location);
            if (valid == 1){
                break;
            }
            else {
                printf("\n\033[0;35m");
                printf("Invalid Position!");
                printf("\033[0m");
            }
        }
        // GAME ACTIONS
        drawmodBoard(boardmatrix, location, player);
		turncounter++;
		switch (player){
			case 1: 
				player = 2;
				break;
			case 2: 
				player = 1;
				break;
            default:
                player = 1;
		}
    }
    // AFTER GAME
	resetdisplay();
	drawmodBoard(boardmatrix, -1, -1);
	switch (testforwin(boardmatrix)){
		case 1: 
			printf("%s", redWins);
			break;
		case 2: 
			printf("%s", yellowWins);
			break;
		case 3:
			printf("%s", tie);
            break;
	}
    return 0;
}
