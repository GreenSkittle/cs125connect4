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
    for (k = 0; k <= ROWS - 1; k++){
        printf("\n");
        for (j = 0; j <= COLUMNS - 1; j++){
            switch (boardmatrix[j][k]){
                case 0:
                    printf("\033[0m");
                    printf("| |");
                    break;
                case 1:
                    printf("\033[0;31m");
                    printf("|O|");
                    break;
                case 2:
                    printf("\033[0;33m");
                    printf("|O|");
                    break;
                default: break;
            }
        }
    }
    printf("\n");
}
