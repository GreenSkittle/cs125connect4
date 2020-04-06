void drawmodBoard(int boardmatrix[ROWS][COLUMNS], column, player){
    int k, j;
    // DESIGN: int graphic[ROWS][COLUMNS]{};
    if (column !=-1 && player !=-1){
        for (k = ROWS-1; k >= 0; k--){
            if (boardmatrix[k][column] == 0){
                boardmatrix[k][column] = player;
                break;
            }
        }
    }
    // PRIMITIVE PRINTING
    for (k = 0; k <= ROWS-1; k++){
        printf("\n%s",boardmatrix[k]);
    }
    printf("\n");
}
