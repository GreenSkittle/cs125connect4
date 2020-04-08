#include "header.h"
int testforwin(int board[ROWS][COLUMNS]){
    int result, j, k, fullboard = 0;
    int padboard[ROWS+8][COLUMNS+8] = {
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    };
    for (k = 0; k <= COLUMNS - 1; k++){
        if (board[0][k] == 0){
            break;
        }
        else {
            fullboard = 1;
        }
    }
    for (j = 0; j <= ROWS - 1; j++){
        for (k = 0; k <= COLUMNS - 1; k++){
            padboard[j+4][k+4] = board[j][k];
        }
    }
    for (j = 0; j <= ROWS - 1; j++){
        for (k = 0; k <= COLUMNS - 1; k++){
            if (padboard[k+4][j+4] == 1 && padboard[k+4][j+5] == 1 && padboard[k+4][j+6] == 1 && padboard[k+4][j+7] == 1){
                result = 1;
            }
            else if (padboard[k+4][j+4] == 2 && padboard[k+4][j+5] == 2 && padboard[k+4][j+6] == 2 && padboard[k+4][j+7] == 2){
                result = 2;
            }
            else if (padboard[k+4][j+4] == 1 && padboard[k+5][j+4] == 1 && padboard[k+6][j+4] == 1 && padboard[k+7][j+4] == 1){
                result = 1;
            }
            else if (padboard[k+4][j+4] == 2 && padboard[k+5][j+4] == 2 && padboard[k+6][j+4] == 2 && padboard[k+7][j+4] == 2){
                result = 2;
            }
            else if (padboard[k+4][j+4] == 1 && padboard[k+5][j+5] == 1 && padboard[k+6][j+6] == 1 && padboard[k+7][j+7] == 1){
                result = 1;
            }
            else if (padboard[k+4][j+4] == 2 && padboard[k+5][j+5] == 2 && padboard[k+6][j+6] == 2 && padboard[k+7][j+7] == 2){
                result = 2;
            }
            else if (padboard[k+4][j+4] == 1 && padboard[k+3][j+5] == 1 && padboard[k+2][j+6] == 1 && padboard[k+1][j+7] == 1){
                result = 1;
            }
            else if (padboard[k+4][j+4] == 2 && padboard[k+3][j+5] == 2 && padboard[k+2][j+6] == 2 && padboard[k+1][j+7] == 2){
                result = 2;
            }
            else if (fullboard == 1){
                result = 3;
            }
        }
    }
    return result;
}
