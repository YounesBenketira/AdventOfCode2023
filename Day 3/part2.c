#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "hashmap_2.h"

/*
* Parses file and inserts all numbers found into the numberMap with the start, end and lineNumbers
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

/*
* Parses the file and when a '*' character is found, gets the adjacent numbers then calculates ratio
* and adds it to sum
*/
int calculateSum(Map *map, FILE *file) {
    int lineNumber = 0;
    int sum = 0;
    char buffer[256];

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        for (int i = 0; buffer[i] != '\n' && buffer[i] != '\0'; i++) {
            if (buffer[i] != '*') {
                continue;
            }

            int adjacentNumbersLength = 0;
            int *adjacentNumbers = getAdjacentNumbers(map, lineNumber, i, &adjacentNumbersLength);

            if (adjacentNumbersLength != 2) {
                free(adjacentNumbers);
                continue;
            }
            
            int ratio = adjacentNumbers[0] * adjacentNumbers[1];
            sum += ratio;
            
            free(adjacentNumbers);
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

    /* Init Map */
    Map numberMap;
    initMap(&numberMap);
    
    /* Populate Map with numbers */
    populateNumberMap(&numberMap, file);
 
    /* Calculate Sum */
    fseek(file, 0, SEEK_SET); // reset file pointer
    int sum = calculateSum(&numberMap, file);
    
    /* Cleanup */
    fclose(file);
    
    printf("DONE, Answer: %i\n", sum);
	return;
}

