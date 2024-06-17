#ifndef TRIE_H
#define TRIE_H

#include <stdlib.h>

#define ALPHABET_SIZE 26

typedef struct Node {
    struct Node *children[ALPHABET_SIZE];
    int value;
} Node;

Node* createNode();
void addWord(Node *root, char *word, int value);
int getWordValue(Node *root, int i, char *buffer);
void freeTrie(Node *root);

#endif // TRIE_H

