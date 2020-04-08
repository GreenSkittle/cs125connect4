#include "header.h"
int testforwin(int board[ROWS][COLUMNS]){
    int result = 0, j, k, hasWon = 0, fullboard = 1;
    // We assume the board is full, and then if any spots are open, redact that claim.
    for (k = 0; k <= COLUMNS - 1; k++){
        if (board[0][k] == 0){
            fullboard = 0;
        }
    }
    // There are 4 patterns in which someone can win.
    // We have 8 statements, because there are two players.
    // There is also some error correction in case the index points outside the matrix.
    for (j = 0; j <= ROWS - 1; j++){
        if (hasWon == 1){
            break;
        }
        for (k = 0; k <= COLUMNS - 1; k++){
            if (board[j][k] == 1 && board[j+1][k] == 1 && board[j+2][k] == 1 && board[j+3][k] == 1 && j+3 <= ROWS - 1){
                result = 1;
                hasWon = 1;
                break;
            }
            else if (board[j][k] == 2 && board[j+1][k] == 2 && board[j+2][k] == 2 && board[j+3][k] == 2 && j+3 <= ROWS - 1){
                result = 2;
                hasWon = 1;
                break;
                
            }
            else if (board[j][k] == 1 && board[j][k+1] == 1 && board[j][k+2] == 1 && board[j][k+3] == 1 && k+3 <= COLUMNS - 1){
                result = 1;
                hasWon = 1;
                break;
            }
            else if (board[j][k] == 2 && board[j][k+1] == 2 && board[j][k+2] == 2 && board[j][k+3] == 2 && k+3 <= COLUMNS - 1){
                result = 2;
                hasWon = 1;
                break;
            }
            else if (board[j][k] == 1 && board[j+1][k+1] == 1 && board[j+2][k+2] == 1 && board[j+3][k+3] == 1 && j+3 <= ROWS - 1 && k+3 <= COLUMNS - 1){
                result = 1;
                hasWon = 1;
                break;
            }
            else if (board[j][k] == 2 && board[j+1][k+1] == 2 && board[j+2][k+2] == 2 && board[j+3][k+3] == 2 && j+3 <= ROWS - 1 && k+3 <= COLUMNS - 1){
                result = 2;
                hasWon = 1;
                break;
            }
            else if (board[j][k] == 1 && board[j-1][k+1] == 1 && board[j-2][k+2] == 1 && board[j-3][k+3] == 1 && j-3 >= 0 && k+3 <= COLUMNS - 1){
                result = 1;
                hasWon = 1;
                break;
            }
            else if (board[j][k] == 2 && board[j-1][k+1] == 2 && board[j-2][k+2] == 2 && board[j-3][k+3] == 2 && j-3 >= 0 && k+3 <= COLUMNS - 1){
                result = 2;
                hasWon = 1;
                break;
            }
        }
    }
    // The very last (and most difficult) thing to test is if there is a tie:
    if (hasWon == 0 && fullboard == 1){
        result = 3;
    }
    return result;
}
