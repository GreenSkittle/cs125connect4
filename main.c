// CONFIGURATION HEADER
#include "header.h"
int main(void){
	// SETUP
    Game demo[ROWS*COLUMNS+1];
    int running = 1;
	int player = 1;
    int location = -1;
    int turncounter = 0;
    int valid = -1;
    int j,k;
	int boardmatrix[ROWS][COLUMNS] = {
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
	};
	// POINTERS
    FILE* alldemos = fopen("allGames.txt","a");
	// CUSTOMIZABLE STRINGS
	char redWins[] =	"\n\tThe game has ended. Red wins!\n";
	char yellowWins[] =	"\n\tThe game has ended. Yellow wins!\n";
	char tie[] =	"\n\tThe game has ended in a draw!\n";
    // BEGIN
    resetdisplay();
    drawmodBoard(boardmatrix[ROWS][COLUMNS], -1, -1);
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
                printf("\n\033[0;35m");
                printf("Invalid Position!");
                printf("\033[0m");
            }
        }
        // GAME ACTIONS AND DEMO
        drawmodBoard(boardmatrix[ROWS][COLUMNS], player, location);
        demo[turncounter].turnNumber = turncounter;
        demo[turncounter].board[ROWS][COLUMNS] = boardmatrix;
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
		case 3:
			printf("%s",tie);
            break;
	}
    demo[turncounter].turnNumber = turncounter;
    demo[turncounter].board[ROWS][COLUMNS] = boardmatrix;
    demo[turncounter].winState = testforwin(boardmatrix[ROWS][COLUMNS]);
    for (j = 0; j <= turncounter; j++){
        fprintf(alldemos,"\nTurn: %d",demo[j].turnNumber);
        for (k = 0; k <= ROWS-1; k++){
            fprintf(alldemos,"\n%s",demo[j].board[k]);
        }
    }
    fprintf(alldemos,"\nWinner: player %d.\n", demo[turncounter].winState);
    fclose(alldemos);
    return 0;
}
