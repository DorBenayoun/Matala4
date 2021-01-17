#include "trie.h"

int main(int n, char *stra[]){
    	node *head = resetNode();
    	int maxWord = newTrie(&head);
    	int level = 0;
    	char strb[maxWord];

    	if (n == 1){
        	printTrie(head, strb, level);
    	}
    	else if (n == 2){
        	if (strcmp(stra[1], "r") == 0){
            		printTrieb(head, strb, level);
        	}
    	}
    	clearTrie(head);
   	return 0;
}
