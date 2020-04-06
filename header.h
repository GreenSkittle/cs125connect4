#ifndef HEADER_H
#define HEADER_H
    #define ROWS 6
    #define COLUMNS 7
    // DEMO STRUCTURE
    typedef struct game {
        int turnNumber;
        char board[ROWS][COLUMNS];
        int winState;
    } Game;
    // FUNCTION PROTOTYPES
    void drawmodBoard(int board[ROWS][COLUMNS], int column, int player);
    void resetDisplay(void);
    int testforwin(int board[ROWS][COLUMNS);
    int promptUser(int player);
    int checkValidity(int board[ROWS][COLUMNS, int column);
#endif
