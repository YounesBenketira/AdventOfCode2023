#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "hashmap.h"

void main() {
	FILE *file = fopen("input.txt", "r");

	if (file == NULL) {
		perror("Failed to open file");
		return;
	}

    int lineNumber = 0;
	char buffer[256];
    HashMap symbolMap;
    init_hashmap(&symbolMap);
	while(fgets(buffer, sizeof(buffer), file) != NULL) {
        for (int i = 0; buffer[i] != '\n' && buffer[i] != '\0'; ) {
            if (!isdigit(buffer[i])) {
                if (buffer[i] != '.') {
                    // printf( "Inserting %i value into %i line number ", i, lineNumber);
                    insert(&symbolMap, lineNumber, i);
                }
                  
                i++;
                continue;   
            }

            char *end;
            int number = strtol(&buffer[i], &end, 10);
            int end_index = end - buffer - 1;

            printf("Number: %i   Start: %i   End: %i\n", number, i, end_index);
            
            for (int j = lineNumber - 1; j < lineNumber + 1; j++) {
                int size = 0;
                int *symbolsInLine = get(&symbolMap, j, &size);
                if (symbolsInLine == NULL) {
                    continue;   
                }

                printf("\nPrinting 0 to %i\n", size);
                for(int k = 0; k < size; k++) {
                    printf("%i ", symbolsInLine[k]);
                }             
            }

            i = end_index + 1;
        }

        lineNumber++;
    }
        

    fclose(file);
	printf("DONE\n");

	return;
}
