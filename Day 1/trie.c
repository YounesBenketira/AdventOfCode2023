#include "trie.h"
#include <stdlib.h>

Node* createNode() {
    Node *newNode = (Node *) malloc(sizeof(Node));
    if (newNode) {
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            newNode->children[i] = NULL;
        }
        newNode->value = 0;
    }
    return newNode;
}

void addWord(Node *root, char *word, int value) {
    Node *current = root;
    while(*word) {
        int index = *word - 'a';
        if (current->children[index] == NULL) {
            current->children[index] = createNode();
        }
        current = current->children[index];
        word++;
    }
    current->value = value;
}

int getWordValue(Node *root, int i, char *buffer) {
        Node *current = root;

        while (buffer[i] != '\n') {
                int letterIndex = buffer[i] - 'a';

                if (letterIndex < 0 || letterIndex > ALPHABET_SIZE) {
                        return current->value;
                }

                if (current->children[letterIndex] != NULL) {
                        current = current->children[letterIndex];
                } else {
                        return current->value;
                }

                i++;
        }

        return current->value;
}

void freeTrie(Node *root) {
	if (root == NULL) {
		return;
	}

	for (int i = 0; i < ALPHABET_SIZE; i++) {
		if (root->children[i] != NULL) {
			freeTrie(root->children[i]);
		}
	}

	free(root);
}
