#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "hashmap_2.h"

void initMap(Map *map) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        map->table[i].key = 0;
        map->table[i].start = 0;
        map->table[i].end = 0;
        map->table[i].lineNumber = 0;
        map->table[i].isOccupied = false; 
    }
}

Entry* get(Map *map, int key) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (map->table[i].key != key) {
            continue;
        }

        return &(map->table[i]);
    }

    return NULL;
}

int* getNumbersInLine(Map *map, int lineNumber, int *returnSize) {
    int *nums = malloc(MAX_NUM_COUNT_PER_LINE * sizeof(int));
    int size = 0;

    if (nums == NULL) {
        *returnSize = 0;
        return NULL;
    }

    for (int i = 0; i < TABLE_SIZE; i++) {
        if (
            map->table[i].key == 0 ||
            map->table[i].lineNumber != lineNumber
        ) {
            continue;
        }

        nums[size] = map->table[i].key;
        
        size++;
        if (size >= MAX_NUM_COUNT_PER_LINE) break;
    }

    /*
    for (int i = 0; i < size; i++) {
        if (nums[i] == 0) continue;
        printf("%d ", nums[i]);        
    }
    printf("\n");
    */

    *returnSize = size;
    return nums;
}

unsigned int hash(int key) {
    key = ((key >> 16) ^ key) * 0x45d9f3b;
    key = ((key >> 16) ^ key) * 0x45d9f3b;
    key = (key >> 16) ^ key;

    return key % TABLE_SIZE;
}

void insert(Map *map, int key, int start, int end, int lineNumber) {
    int index = hash(key);

    printf("Inserting %i [%i] [%i]\n", key, lineNumber, index);
    if (map->table[index].isOccupied) {
        printf("Collision Happened, unhandled\n");
    }

    map->table[index].key = key;
    map->table[index].start = start;
    map->table[index].end = end;
    map->table[index].lineNumber = lineNumber;
    map->table[index].isOccupied = true;
}
