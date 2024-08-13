#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "hashmap_2.h"

/*
* Parses file and maps all symbols in a line to an array of their indicies
*/
void populateNumberMap(Map *numberMap, FILE *file) {
    char buffer[256];
    int lineNumber = 0;
    while(fgets(buffer, sizeof(buffer), file) != NULL) {
        for (int i = 0; buffer[i] != '\n' && buffer[i] != '\0'; i++ ) {
            if (!isdigit(buffer[i])) {
                continue;
            }
            
            /* Get full number & the index of the last digit */
            char *end;
            int number = strtol(&buffer[i], &end, 10);
            int endIndex = end - buffer - 1;
           
            insert(numberMap, number, i, endIndex, lineNumber);
            
            i = endIndex;            
        }
      
        lineNumber++;
    }
}

void main() {
	FILE *file = fopen("input_test.txt", "r");

	if (file == NULL) {
		perror("Failed to open file");
		return;
	}

    Map numberMap;
    initMap(&numberMap);
    
    populateNumberMap(&numberMap, file);
    
    int numsInLineSize = 0;
    int *numbersInLineZero = getNumbersInLine(&numberMap, 0, &numsInLineSize);

    for (int i = 0; i < numsInLineSize; i++) {
        if (numbersInLineZero[i] == 0) continue;
        printf("%d ", numbersInLineZero[i]);        
    }
    printf("\n");
    
    free(numbersInLineZero);

    fseek(file, 0, SEEK_SET);

    //int sum = calculateSum(symbolMap, file);
    fclose(file);
    printf("DONE, Answer: %i\n", 0);
	return;
}

