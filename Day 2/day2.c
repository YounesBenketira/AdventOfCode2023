#include <stdio.h>

int isDigit(char c) {
	return c <= '9' && c >= '0';
}

int main() {
	FILE *file = fopen("input.txt", "r");

	if (file == NULL) {
		perror("Failed to open file");
		return 0;
	}	

	char buffer[256];
	int gameNumber = 1;
	while(fgets(buffer, sizeof(buffer), file) != NULL) {
		int *counts[3] = {0};
		char *number[3] = {'\0'};
		for (int i = 0; buffer[i] != '\n'; i++) {
			// 1. Number found
			// 2. Space found after number
			// 3. Increment count of color
			if (isDigit(buffer[i]) && buffer[i + 1] == ' ') {
				char color = buffer[i + 2];
				int num = buffer[i] - '0';
				
				int index = -1;
				if (color == 'r') {
					index = 0;	
				} 
				else if (color == 'b') {
					index = 1;
				}
				else if (color == 'g') {
					index = 2;
				}
				else {
					printf("BAD COLOR FOUND %c", color);
					return 0;
				}

				counts[index] += num;

				printf("%d %c  ", num, color);
			} 
		}
		printf("\n");
		gameNumber++;
	}

	fclose(file);

	return 0;
}
