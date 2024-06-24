#include <stdio.h>
#include <stdlib.h>

int isDigit(char c) {
	return c <= '9' && c >= '0';
}

int main() {
	FILE *file = fopen("input.txt", "r");

	if (file == NULL) {
		perror("Failed to open file");
		return 0;
	}	

	int sum = 0;
	char buffer[256];
	int gameNumber = 1;
	while(fgets(buffer, sizeof(buffer), file) != NULL) {
		int addGameNumber = 1;
		for (int i = 0; buffer[i] != '\n'; i++) {
			if (!isDigit(buffer[i]) || buffer[i+1] != ' ') continue;

			char diceCountStr[3] = {'\0'};
				
			if (isDigit(buffer[i - 1])) {
				diceCountStr[0] = buffer[i - 1];
				diceCountStr[1] = buffer[i];
			} else {
				diceCountStr[0] = buffer[i];
			}
						
			char color = buffer[i + 2];
			int diceCount  = atoi(diceCountStr);
	
			if (
				   color == 'r' && diceCount > 12 
				|| color == 'g' && diceCount > 13
				|| color == 'b' && diceCount > 14
			) {
				addGameNumber = 0;
				break;
			}
		}
		
		if (addGameNumber == 1) {
			sum += gameNumber;
		}
	
		gameNumber++;
	}
	
	fclose(file);

	printf("\nTotal = %i\n", sum);
	
	return 0;
}
