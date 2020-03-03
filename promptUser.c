// TITLE BLOCK
#define COLUMNS 7
int promptUser(int player){
char choice;
int location;
switch (player){
	case 1:
		printf("\033[1;31m");
		printf("\nPlayer 1: ");
		printf("\033[0m");
		printf("Pick a spot A-G:\n");
		scanf("%c",&choice);
		break;
	case 2:
		printf("\033[1;31m");
		printf("\nPlayer 2: ");
		printf("\033[0m");
		printf("Pick a spot A-G:\n");
		scanf("%c",&choice);
		break;
	default: break;
}
if(location >= 65 && location <= 90){
	location = (int) choice - 65;
}
else if(location >= 97 && location <= 122){
	location = (int) choice - 97;
}
else {
	location = -1;
}
return location;
}
