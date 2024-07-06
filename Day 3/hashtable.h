#ifndef HASHTABLE_H
#define HASHTABLE_H

typedef struct {
	char* key;
	char* value;
	struct Entry* next;
} Entry;

typedef struct {
	Entry** entries;
} HashTable;

unsigned int hash(const char* key);
HashTable* create_table();
Entry* create_entry(const char* key, const char* value);
void ht_set(HashTable* table, const char* key, const char* value);
char* ht_get(HashTable* table, const char* key);
void free_table(HashTable* table);

#endif
