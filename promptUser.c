#include "header.h"
int promptUser(int player){
	char choice;
	int location;
	int quickcheck;
	switch (player){
		case 1:
			printf("\033[1;31m");
			printf("\nPlayer 1: ");
			printf("\033[0m");
			printf("Pick a spot A-%c:\n", COLUMNS + 64);
			quickcheck = scanf("\n%c", &choice);
			break;
		case 2:
			printf("\033[1;31m");
			printf("\nPlayer 2: ");
			printf("\033[0m");
			printf("Pick a spot A-%c:\n", COLUMNS + 64);
			quickcheck = scanf("\n%c", &choice);
			break;
		default: break;
	}
	// CAPITALS A-Z
	if(choice >= 65 && choice <= 90 && quickcheck == 1){
		location = choice - 65;
	}
	// LOWERCASE a-z
	else if(choice >= 97 && choice <= 122 && quickcheck == 1){
		location = choice - 97;
	}
	else {
		location = -1;
	}
	return location;
}
