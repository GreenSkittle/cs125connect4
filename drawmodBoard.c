#include "header.h"
void drawmodBoard(int boardmatrix[ROWS][COLUMNS], int column, int player){
    int k, j;
    if (column != -1 && player != -1){
        for (k = ROWS - 1; k >= 0; k--){
            if (boardmatrix[k][column] == 0){
                boardmatrix[k][column] = player;
                break;
            }
        }
    }
    // PRIMITIVE PRINTING
    for (k = 0; k <= ROWS - 1; k++){
        printf("\n");
        for (j = 0; j <= COLUMNS - 1; j++){
            printf(" %d", boardmatrix[k][j]);
        }
    }
    printf("\n");
}
