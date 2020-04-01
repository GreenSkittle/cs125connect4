#ifndef HEADER_H
#define HEADER_H
// DEMO STRUCTURE
typedef struct game {
    int turnNumber;
    char board[];
    int winState;
} Game;
// FUNCTION PROTOTYPES
void drawmodBoard(int* boardptr, int column, int player);
void resetDisplay(void);
int testforwin(int* boardptr);
int promptUser(int player);
int checkValidity(int* boardptr, int column);
#endif
