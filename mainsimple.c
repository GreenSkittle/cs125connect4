#include "header.h"
int main(void){
    int running = 1;
    int player = 1;
    int location = -1;
    int turncounter = 0;
    int valid = -1;
    int j, k;
    int boardmatrix[ROWS][COLUMNS] = {
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
    };
    FILE* demo = fopen("allGames.txt", "a");
    // Adjustable win-messages
    char redWins[] =	"\n The game has ended. Red player wins!\n";
    char yellowWins[] =	"\n The game has ended. Yellow player wins!\n";
    char tie[] =	    "\n The game has ended in a draw!\n";
    resetdisplay();
    drawmodBoard(boardmatrix, -1, -1);
    // Now following the flow chart diagram
    while (running == 1){
        if (testforwin(boardmatrix) != 0){
            break;
        }
        while (1){
            location = promptUser(player);
            valid = checkValidity(boardmatrix, location);
            if (valid == 1){
                break;
            }
            else {
                // Error message
                printf("\n\033[0;35m");
                printf("Invalid Position!");
                printf("\033[0m");
            }
        }
        resetdisplay();
        drawmodBoard(boardmatrix, location, player);
        turncounter++;
        // Switch player using a switch statement:
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
    // This section runs once at the very end of the game:
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
    printf("\n");
    // Perform FileIO using a similar function to drawmodboard.
        for (j = 0; j <= ROWS - 1; j++){
            fprintf(demo, "\n ");
            for (k = 0; k <= COLUMNS - 1; k++){
                switch (boardmatrix[j][k]){
                    case 0:
                        fprintf(demo, "| |");
                        break;
                    case 1:
                        fprintf(demo, "|%c|", 'X');
                        break;
                    case 2:
                        fprintf(demo, "|%c|", 'O');
                        break;
                }
            }
    }
    return 0;
}
