// TITLE BLOCK
// LIBRARY
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include <time.h>
// CONFIGURATION
#define WIDTH 7
#define HEIGHT 6
// FUNCTION PROTOTYPES
void drawmodBoard(int boardmatrix[WIDTH][HEIGHT], column, player);
void resetDisplay(void);
int testforwin(int boardmatrix[WIDTH][HEIGHT]);
int promptUser(player);
int checkValidity(boardmatrix[WIDTH][HEIGHT], column);
// GLOBAL
// MAIN
int main(){
    int boardmatrix[WIDTH][HEIGHT] = {
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
    }
    int running = 1;
    int wincondition = -1;
    int location = -1;
    int turncounter = 0;
    int valid = 0;
    
    while (running == 1){
        resetDisplay();
        testforwin();
        
        while (1){
            location = promptUser(player);
            valid = checkValidity(boardmatrix, location);
            if (valid == 1){
                break;
            }
            else {
            }
        }
        
        drawmodBoard(boardmatrix);
        testforwin(boardmatrix);
    }
    return 0;
}
