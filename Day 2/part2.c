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
	while(fgets(buffer, sizeof(buffer), file) != NULL) {
		int maxDiceCountPerColor[3] = {0};
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
			int colorIndex = 0;
			switch(color) {
				case 'r':
					break;	
				case 'g':
					colorIndex = 1;
					break;
				case 'b':
					colorIndex = 2;
					break;
				default:
					perror("ERROR BAD COLOR");
					return 1;
			}
			
			if (maxDiceCountPerColor[colorIndex] < diceCount) {
				maxDiceCountPerColor[colorIndex] = diceCount;
			}
		}
		
		int power = maxDiceCountPerColor[0] * maxDiceCountPerColor[1] * maxDiceCountPerColor[2];
		sum += power;
	}
	
	fclose(file);

	printf("\nTotal = %i\n", sum);
	
	return 0;
}
