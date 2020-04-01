// Note: no error handling for column neede because checkValidity already catches if board is full.
// based on  a pointer to the board.

void drawmodBoard(int* pointy, column, player){
    int boardmatrix[ROWS][COLUMNS] = *pointy;
    int k;
    for (k = ROWS;k >= 0;k--){
        if (boardmatrix[k][column] == 0){
            boardmatrix[k][column] = player;
            break;
        }
    }
    /* now print it here */
}
