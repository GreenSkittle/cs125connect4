#ifndef HEADER_H
#define HEADER_H
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    // Configure the size here. Default is 6x7.
    // Minimum is 1x1 and Maximum is about 2.1 billion x 26.
    #define ROWS 6
    #define COLUMNS 7
    // Function prototypes:
    void drawmodBoard(int board[ROWS][COLUMNS], int column, int player);
    void resetdisplay(void);
    int testforwin(int board[ROWS][COLUMNS]);
    int promptUser(int player);
    int checkValidity(int board[ROWS][COLUMNS], int column);
#endif
