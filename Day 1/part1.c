#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE *file = fopen("input.txt", "r");
	
	if (file == NULL) {
		perror("Error opening file");
        	return 1;
	}

	char buffer[256];
	int sum = 0;
	while (fgets(buffer, sizeof(buffer), file) != NULL) {
		int first = -1;
		int second = -1;
		for(int i = 0; buffer[i] != '\0'; i++) {
			if (buffer[i] >= '0' && buffer[i] <= '9') {
				int digit = buffer[i] - '0';
				if(first == -1) {
					first = digit;
				} else {
					second = digit;
				}
			}
		}

		char numsAsStr[3] = "";
		if (first != -1) {
			if (second == -1) {
				sprintf(numsAsStr, "%d%d", first, first);
			} else {
				sprintf(numsAsStr, "%d%d", first, second);
			}
			int lineTotal = atoi(numsAsStr);
			sum += lineTotal;
		}
	}

	printf("Total = %d\n", sum);
	
	fclose(file);
	return 0;
}
