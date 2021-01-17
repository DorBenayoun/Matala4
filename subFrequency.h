#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

#define NUM_LETTERS 26

typedef struct node
{
    char letter;
    long unsigned int count;
    struct node *children[NUM_LETTERS];
    bool isLeaf;
} node;

bool isLowerLetter(char c);
bool isCapitalLetter(char c);
char charToLower(char c);
void newChildren(node **head, char c);
node *resetNode();
void clearNode(node *node);
