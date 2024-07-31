#ifndef HASHMAP_H
#define HASHMAP_H

#include <stdbool.h>

#define TABLE_SIZE 2048
#define MAX_ARRAY_SIZE 256

typedef struct {
    int key;
    int values[MAX_ARRAY_SIZE];
    int count;  // Number of elements in the array
    bool is_occupied;
} HashEntry;

typedef struct {
    HashEntry table[TABLE_SIZE];
} HashMap;

void init_hashmap(HashMap* map);
bool insert(HashMap* map, int key, int value);
int* get(HashMap* map, int key, int* size);
void remove_key(HashMap* map, int key);

#endif // HASHMAP_H
