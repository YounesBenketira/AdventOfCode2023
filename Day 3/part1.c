#include <stdio.h>

int isDigit(char c) {
	return c <= '9' && c >= '0';
}

void main() {
	FILE *file = fopen("input.txt", "r");

	if (file == NULL) {
		perror("Failed to open file");
		return;
	}

	char buffer[256];
	while(fgets(buffer, sizeof(buffer), file) != NULL) {
		char numTracker = 's'; 
		for(int i = 0; buffer[i] != '\n'; i++) {
			if (	
		}
		printf("%s\n", buffer);
	}

	printf("DONE\n");
	return;
}
