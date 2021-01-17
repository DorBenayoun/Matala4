#include "trie.h"

/**
 * buildTrie function , gets pointer to pointer , in order to change head without return it any call
 * @return int , the maximum length of word in the trie , used this param to create str.
**/
int newTrie(node **head){
    	node *next = *head;
    	char c;
    	int maxLength = 0, wordLength = 0;
    	while (scanf("%c", &c) != EOF){
        	char temp = charToLower(c);
        	if (temp == '\t' || temp == '\n' || temp == ' '){
            		if (wordLength > maxLength){
                		maxLength = wordLength;
            		}
            		wordLength = 0;
            		next->isLeaf = true;
            		next->count++;
            		next = *head;
        	}
        	else if (isLowerLetter(temp)){
            		newChildren(&next, temp);
            		wordLength++;
        	}
    	}
    	if (wordLength > maxLength){
        	maxLength = wordLength;
        }	
    	next->isLeaf = true;
    	next->count++;
    	(*head)->isLeaf = false;
    	
    	return maxLength;
}

/**
 * printTrie function , print on recursive way the trie by lexographic order . 
**/
void printTrie(const node *root, char str[], int level){
    	if (root->isLeaf){
        	str[level] = '\0';
        	printf("%s", str);
        	printf("\t%lu\n", root->count);
    	}
    	for (int i = 0; i < NUM_LETTERS; i++){
        	if (root->children[i]){
            		str[level] = i + 'a';
            		printTrie(root->children[i], str, level + 1);
        	}
    	}
}
/**
 * printTrieR function , print on recursive way the trie by oposite of lexographic order . 
**/
void printTrieb(const node *root, char str[], int level){
    	for (int i = NUM_LETTERS - 1; i >= 0; i--){
        	if (root->children[i]){
            		str[level] = i + 'a';
            		printTrieb(root->children[i], str, level + 1);
        	}
    	}
    	if (root->isLeaf){
        	str[level] = '\0';
        	printf("%s", str);
        	printf("\t%lu\n", root->count);
    	}
}
/**
 * freeTrie , recursive function to free allocation of nodes in the trie.
**/
void clearTrie(node *root){
    	if (root){
		clearNode(root);
    	}
}

