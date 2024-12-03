#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_PATH "/home/younes/Documents/Code/Personal/AdventOfCode2023/Day 4/src/test_input.txt"

/**
*
*/
int read_file_contents(const char* filepath) {
    FILE *file = fopen(filepath, "r");
    
    if (file == NULL) {
        fprintf(stderr, "Error: Unable to open file %s\n", filepath);
        
        return -1;
    }

    char buffer[256];
    int line_count = 0;

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("Line %d: %s", ++line_count, buffer);
    }

    fclose(file);

    return line_count;
}

int main() {
    int result = read_file_contents(FILE_PATH);

    if (result < 0) {
        return EXIT_FAILURE;
    }

    printf("Total lines read: %d\n", result);

    return EXIT_SUCCESS;
}
