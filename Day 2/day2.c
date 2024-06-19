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
		int counts[3] = {0};
		for (int i = 0; buffer[i] != '\n'; i++) {
			char diceCount[3] = {'\0'};
			if (isDigit(buffer[i]) && buffer[i + 1] == ' ') {
				char color = buffer[i + 2];
				int num = buffer[i] - '0';
				
				if (isDigit(buffer[i - 1])) {
					diceCount[0] = buffer[i - 1];
					diceCount[1] = buffer[i];
				} else {
					diceCount[0] = buffer[i];
				}
				
				int index = -1;
				switch(color) {
					case 'r':
						index = 0;
						break;
					case 'b':
						index = 1;
						break;
					case 'g':
						index = 2;
						break;
					default:
						printf("Invalid color %c", color);
						break;
				}

				counts[index] += atoi(diceCount);

				// printf("%d %c ", atoi(diceCount), color);
			} 
		}

		printf("%d red, %d blue, %d green \n", counts[0], counts[1], counts[2]);
		
		// 0:R, 1:G, 2:B
		if (counts[0] <= 12 && counts[1] <= 13 && counts[2] <= 14) {
			printf("\nGame %i is valid\n", gameNumber);
			sum += gameNumber;
		}
		
		printf("\n");
		gameNumber++;
	}
	
	printf("\nTotal = %i\n", sum);
	fclose(file);

	return 0;
}
