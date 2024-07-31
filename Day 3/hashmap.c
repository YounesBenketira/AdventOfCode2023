#include "hashmap.h"
#include <string.h>

void init_hashmap(HashMap* map) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        map->table[i].is_occupied = false;
        map->table[i].count = 0;
    }
}

static int hash(int key) {
    return key % TABLE_SIZE;
}

bool insert(HashMap* map, int key, int value) {
    int index = hash(key);
    
    while (map->table[index].is_occupied) {
        if (map->table[index].key == key) {
            // Key exists, append to the array if there's space
            if (map->table[index].count < MAX_ARRAY_SIZE) {
                map->table[index].values[map->table[index].count++] = value;
                return true;
            } else {
                return false;  // Array is full
            }
        }
        index = (index + 1) % TABLE_SIZE;
    }
    
    // Insert new key-value pair
    map->table[index].key = key;
    map->table[index].values[0] = value;
    map->table[index].count = 1;
    map->table[index].is_occupied = true;
    return true;
}

int* get(HashMap* map, int key, int* size) {
    int index = hash(key);
    
    while (map->table[index].is_occupied) {
        if (map->table[index].key == key) {
            *size = map->table[index].count;
            return map->table[index].values;
        }
        index = (index + 1) % TABLE_SIZE;
    }
    
    // Key not found
    *size = 0;
    return NULL;
}

void remove_key(HashMap* map, int key) {
    int index = hash(key);
    
    while (map->table[index].is_occupied) {
        if (map->table[index].key == key) {
            map->table[index].is_occupied = false;
            map->table[index].count = 0;
            return;
        }
        index = (index + 1) % TABLE_SIZE;
    }
}
