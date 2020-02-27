// function to draw the connect 4 board
// below is the function that must match the main file, including definitions
// makes use of the global artboard variable
// artboard is a pointer to the ascii art -  defined globally
void drawBoard(int boardmatrix[WIDTH][HEIGHT], char artboard[][]){
    int j,k;
    for (j=0;j<=HEIGHT;j++){
        for (k=0;k<=WIDTH;k++){
            artboard[2*(j+1)][2*(k+1)] = boardmatrix[j][k];
            printf(" %c",artboard[j][k]);
    
}
