#include "header.h"
int checkValidity(int wholeboard[ROWS][COLUMNS], int column){
    int result = 0;
    if (column >= 0 && column < COLUMNS && wholeboard[0][column] == 0){
        // Ensure the chosen place exists and is open
        result = 1;
    }
    return result;
}
