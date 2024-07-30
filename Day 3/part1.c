#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "hashmap.h"

/*
* Parses file and maps all symbols in a line to an array of their indicies
*/
void populateSymbolMap(HashMap *symbolMap, FILE *file) {
    char buffer[256];
    int lineNumber = 0;
    while(fgets(buffer, sizeof(buffer), file) != NULL) {
        for (int i = 0; buffer[i] != '\n' && buffer[i] != '\0'; i++ ) {
            if (isdigit(buffer[i]) || buffer[i] == '.') {
                continue;
            }

            insert(symbolMap, lineNumber, i);
        }

        lineNumber++;
    }
}

/**
* Finds numbers and adds them to the sum if eligible 
*/
int calculateSum(HashMap symbolMap, FILE *file) {
    char buffer[256];
    int lineNumber = 0;
    int sum = 0;
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        for (int i = 0; buffer[i] != '\n' && buffer[i] != '\0'; i++ ) {
            if (!isdigit(buffer[i])) {
                continue;
            }
            
            /* Get full number & the index of the last digit */
            char *end;
            int number = strtol(&buffer[i], &end, 10);
            int endIndex = end - buffer - 1;
           
            /* Parse from the line above to the line below for symbols that are adjacent */
            for (int j = lineNumber - 1; j <= lineNumber + 1; j++) {
                int symbolIndiciesArrayLength = 0;
                int *symbolIndiciesForLine = get(&symbolMap, j, &symbolIndiciesArrayLength);
                
                if (symbolIndiciesForLine == NULL) {
                    continue;
                }
                
                /* Loop through symbols in the line and determine if they are adjacent */
                for (int k = 0; k < symbolIndiciesArrayLength; k++) {
                    if (
                        symbolIndiciesForLine[k] >= i - 1 &&
                        symbolIndiciesForLine[k] <= endIndex + 1
                    ) {
                        sum += number;
                    }
                }
            } 
            
            i = endIndex + 1;
        }

        lineNumber++;
    }

    return sum;
}

void main() {
	FILE *file = fopen("input.txt", "r");

	if (file == NULL) {
		perror("Failed to open file");
		return;
	}

    HashMap symbolMap;
    init_hashmap(&symbolMap);
    
    populateSymbolMap(&symbolMap, file);
    
    fseek(file, 0, SEEK_SET);

    int sum = calculateSum(symbolMap, file);
    fclose(file);
    printf("DONE, Answer: %i\n", sum);
	return;
}

