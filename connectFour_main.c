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
void drawBoard(int boardmatrix[WIDTH][HEIGHT]);
void resetDisplay(void);
int testforwin(int boardmatrix[WIDTH][HEIGHT]);
// GLOBAL VARIABLES
char artboard[][] = {
}
int main(){
    int boardmatrix[WIDTH][HEIGHT] = {
    }
    int running = 1;
    
    while (running == 1){
        resetDisplay();
        testforwin();
        promptUser();
        checkValidity();
        modBoard();
        drawBoard();
        testforwin();
    }
    return 0;
}
