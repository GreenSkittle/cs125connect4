#include "header.h"
void drawmodBoard(int boardmatrix[ROWS][COLUMNS], int column, int player){
    int k, j;
    // Does board need modifying or just printing?
    if (column != -1 && player != -1){
        for (k = ROWS - 1; k >= 0; k--){
            if (boardmatrix[k][column] == 0){
                // Simulate a piece for that player falling into place.
                boardmatrix[k][column] = player; 
                break;
            }
        }
    }
    // Print Legend
    // goal is to see printf("  a  b  c  d  e  f  g\n");
    printf("  ");
    for (k = 0; k <= COLUMNS - 1; k++){
        printf("%c  ", k + 97);
    }
    printf("\n");
    // Print in color each element
    for (k = 0; k <= ROWS - 1; k++){
        printf("\n ");
        for (j = 0; j <= COLUMNS - 1; j++){
            switch (boardmatrix[k][j]){
                case 0:
                    printf("\033[0m");
                    printf("| |");
                    break;
                case 1:
                    printf("\033[0m|\033[0;31mO\033[0m|");
                    break;
                case 2:
                    printf("\033[0m|\033[0;33mO\033[0m|");
                    break;
            }
        }
    }
    // Print the end-cap
    printf("\n |--");
    for (j = 1; j <= COLUMNS - 2; j++){
        printf("---");
    }
    printf("--|\n []");
    for (j=1; j <= COLUMNS - 2; j++){
        printf("   "); // Three spaces
    }
    printf("  []\n");
}
