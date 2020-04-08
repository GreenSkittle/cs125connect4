#include "header.h"
int main(void){
	// SETUP
    Game demo[ROWS*COLUMNS+1];
    int running = 1;
	int player = 1;
    int location = -1;
    int turncounter = 0;
    int valid = -1;
    int j, k, m;
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
	char tie[] =	    "\n\tThe game has ended in a draw!\n";
    // BEGIN
    resetdisplay();
    drawmodBoard(boardmatrix, -1, -1);
    while (running == 1){
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
        // GAME ACTIONS AND DEMO
        drawmodBoard(boardmatrix, player, location);
        demo[turncounter].turnNumber = turncounter;
        for (j = 0; j <= ROWS - 1; j++){
            for (k= 0; k <= COLUMNS - 1; k++){
                demo[turncounter].board[j][k] = boardmatrix[j][k];
            }
        }  
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
    demo[turncounter].turnNumber = turncounter;
    for (j = 0; j <= ROWS - 1; j++){
        for (k= 0; k <= COLUMNS - 1; k++){
            demo[turncounter].board[j][k] = boardmatrix[j][k];
        }
    }  
    demo[turncounter].winState = testforwin(boardmatrix);
    for (j = 0; j <= turncounter; j++){
        fprintf(alldemos,"\nTurn: %d",demo[j].turnNumber);
        for (k = 0; k <= ROWS - 1; k++){
            printf("\n");
            for (m = 0; m <= COLUMNS - 1; m++){
                fprintf(alldemos," %d",demo[j].board[k][m]);
            }
        }
    }
    fprintf(alldemos,"\nWinner: player %d!\n", demo[turncounter].winState);
    fclose(alldemos);
    return 0;
}
