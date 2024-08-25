#ifndef HASHMAP_2_H
#define HASHMAP_2_H

#include <stdbool.h>

#define TABLE_SIZE 2048
#define MAX_NUM_COUNT_PER_LINE 256

typedef struct {
    int key;
    int start; 
    int end;
    int lineNumber;
    bool isOccupied;
} Entry;

typedef struct {
    Entry table[TABLE_SIZE];
} Map;

void initMap(Map *map);
int* getAdjacentNumbers(Map *map, int lineNumber, int index, int *returnSize);
void insert(Map *map, int key, int start, int end, int lineNumber);

#endif 
