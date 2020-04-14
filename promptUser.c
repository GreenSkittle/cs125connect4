#include "header.h"
int promptUser(int player){
    char string[255];
    char choice = "a";
    int location;
    int quickcheck;
    switch (player){
        case 1:
            printf("\033[1;31m");
            printf("\nPlayer 1: ");
            printf("\033[0m");
            printf("Pick a spot A-%c:\n", COLUMNS + 64);
            quickcheck = scanf("\n%s", string);
            choice = string[0]; // Take the first element of the string the user inputs
            break;
        case 2:
            printf("\033[1;33m");
            printf("\nPlayer 2: ");
            printf("\033[0m");
            printf("Pick a spot A-%c:\n", COLUMNS + 64);
            quickcheck = scanf("\n%s", string);
            choice = string[0]; // Take the first element of the string the user inputs
            break;
        default: break;
    }
    // Map ASCII to a number for capitals or lowercase
    if(choice >= 65 && choice <= 90 && quickcheck == 1){
        location = choice - 65;
    }
    else if(choice >= 97 && choice <= 122 && quickcheck == 1){
        location = choice - 97;
    }
    else {
        location = -1;
    }
    return location;
}
