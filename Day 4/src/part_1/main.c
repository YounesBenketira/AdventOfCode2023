#include <stdio.h>

int main() {
    FILE *file = fopen("../test_input.txt", "r");

	if (file == NULL) {
		perror("Failed to open file");
		return 0;
	}

    char buffer[256]; 
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        for (int i = 0; buffer[i] != '\n' && buffer[i] != '\0'; i++ ) {
            printf("%c", buffer[i]);
        }
        printf("\n");
    }

    printf("Done");
        
    return 0;
}
