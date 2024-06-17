#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "trie.h"
 
bool isDigit(char c) {
	return c <= '9' && c >= '0';
}

int main() {
	/* INITIALIZE TRIE */
	Node *root = createNode();
		
	char *numbers[9] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	for (int i = 0; i < 9; i++) {
		addWord(root, numbers[i], i + 1);
	}

	/* PARSE FILE */
	FILE *file = fopen("input.txt", "r");
	
	int sum = 0;	
	char buffer[256];
	while (fgets(buffer, sizeof(buffer), file) != NULL) {	
		char lineTotal[3] = {0};
		for (int i = 0; buffer[i] != '\0'; i++) {
			char value = '\0';
				
			if (isDigit(buffer[i])) {
				value = buffer[i];
			} else {
				int num = getWordValue(root, i, buffer);
				if (num > 0) {
					value = '0' + num;
				}
			}
		
			if (value != '\0') {
				if (lineTotal[0] == 0) {
					lineTotal[0] = value;
				} else {
					lineTotal[1] = value;
				}
			}
		}
		
		// If only ONE number found, use it for both digits (i.e 1 -> 11)		
		if (lineTotal[0] > 0 && lineTotal[1] == 0) {
			lineTotal[1] = lineTotal[0];
		}
		
		sum += atoi(lineTotal);
	}
		
	fclose(file);
	freeTrie(root);

	printf("Total = %d\n", sum);
	return 0;
}
