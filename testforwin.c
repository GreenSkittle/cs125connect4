#include "header.h"
int testforwin(int board[ROWS][COLUMNS]){
    int result, j, k, fullboard;
    fullboard = 1;
    for (k = 0; k <= COLUMNS - 1; k++){
        if (board[0][k] == 0){
            fullboard = 0;
        }
    }
    for (j = 0; j <= ROWS - 1; j++){
        for (k = 0; k <= COLUMNS - 1; k++){
            if (board[j][k] == 1 && board[j+1][k] == 1 && board[j+2][k] == 1 && board[j+3][k] == 1){
                result = 1;
            }
            else if (board[j][k] == 2 && board[j+1][k] == 2 && board[j+2][k] == 2 && board[j+3][k] == 2){
                result = 2;
            }
            else if (board[j][k] == 1 && board[j][k+1] == 1 && board[j][k+2] == 1 && board[j][k+3] == 1){
                result = 1;
            }
            else if (board[j][k] == 2 && board[j][k+1] == 2 && board[j][k+2] == 2 && board[j][k+3] == 2){
                result = 2;
            }
            else if (board[j][k] == 1 && board[j+1][k+1] == 1 && board[j+2][k+2] == 1 && board[j+3][k+3] == 1){
                result = 1;
            }
            else if (board[j][k] == 2 && board[j+1][k+1] == 2 && board[j+2][k+2] == 2 && board[j+3][k+3] == 2){
                result = 2;
            }
            else if (board[j][k] == 1 && board[j-1][k+1] == 1 && board[j-2][k+2] == 1 && board[j-3][k+3] == 1){
                result = 1;
            }
            else if (board[j][k] == 2 && board[j-1][k+1] == 2 && board[j-2][k+2] == 2 && board[j-3][k+3] == 2){
                result = 2;
            }
            else if (fullboard == 1){
                result = 3;
            }
        }
    }
    return result;
}
