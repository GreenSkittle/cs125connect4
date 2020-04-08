#ifndef HEADER_H
#define HEADER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
    // Configure the size here. Default is 6x7
    #define ROWS 6
    #define COLUMNS 7
    typedef struct game {
        int turnNumber;
        int board[ROWS][COLUMNS];
        int winState;
    } Game;
    // This structure can be used for FileIO
    // Function prototypes:
    void drawmodBoard(int board[ROWS][COLUMNS], int column, int player);
    void resetdisplay(void);
    int testforwin(int board[ROWS][COLUMNS]);
    int promptUser(int player);
    int checkValidity(int board[ROWS][COLUMNS], int column);
#endif
