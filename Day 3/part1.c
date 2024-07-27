#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void main() {
	FILE *file = fopen("input.txt", "r");

	if (file == NULL) {
		perror("Failed to open file");
		return;
	}

    int lineNumber = 1;
	char buffer[256];
	while(fgets(buffer, sizeof(buffer), file) != NULL) {
		char *current = &buffer[0];
        
        for (int i = 0; buffer[i] != '\n' && buffer[i] != '\0'; ) {
            if (isdigit(buffer[i])) {
                char *end;
                int number = strtol(&buffer[i], &end, 10);
                int end_index = end - buffer - 1;

                printf("Number: %i   Start: %i   End: %i\n", number, i, end_index);
                
                i = end_index + 1;
            } else {
                

                i++;
            }
        } 

        lineNumber++;
	}

    fclose(file);

	printf("DONE\n");
	return;
}
