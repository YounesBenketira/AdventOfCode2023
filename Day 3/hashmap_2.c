#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

int* getAdjacentNumbers(Map *map, int lineNumber, int index, int *returnSize) {
    int *nums = malloc(MAX_NUM_COUNT_PER_LINE * sizeof(int));
    int length = 0;
    
    if (nums == NULL) {
        *returnSize = 0;
        return NULL;
    }
    
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (map->table[i].key == 0) {
            continue;
        }

        Entry entry = map->table[i];       
        bool isLineAdjacent = 
            entry.lineNumber >= lineNumber - 1 &&
            entry.lineNumber <= lineNumber + 1;
        bool isIndexAdjacent =
            entry.start - 1 <= index &&
            entry.end + 1 >= index;
 
        if (!isLineAdjacent || !isIndexAdjacent) {
            continue;
        }

        nums[length] = entry.key;
        length++;
    }
    
    if (length > 0) {
        nums = realloc(nums, length * sizeof(int));
    }

    *returnSize = length;
    return nums;
}

unsigned int hash(int key) {
    key = ((key >> 16) ^ key) * 0x45d9f3b;
    key = ((key >> 16) ^ key) * 0x45d9f3b;
    key = (key >> 16) ^ key;

    return key % TABLE_SIZE;
}

void insert(Map *map, int key, int start, int end, int lineNumber) {
    unsigned int index = hash(key);
    unsigned int originalIndex = index;

    /* Handle collisions by adding it to the next available index */
    while (map->table[index].isOccupied) {
        /* Check if table is full */
        index = (index + 1) % TABLE_SIZE;
        if (index == originalIndex) {
            printf("Error: Hash table is full\n");
            return;
        }
    }

    map->table[index].key = key;
    map->table[index].start = start;
    map->table[index].end = end;
    map->table[index].lineNumber = lineNumber;
    map->table[index].isOccupied = true;
}
