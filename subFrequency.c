#include "subFrequency.h"

bool isLowerLetter(char c){
	return c - 'a' >= 0 && c - 'a' <= 25;
}

bool isCapitalLetter(char c){
    	return c - 'A' >= 0 && c - 'A' <= 25;
}

char charToLower(char c){
    	if (isCapitalLetter(c)){
        	return c + 'a' - 'A';
        }
    	else{
        	return c;
        }
}

void newChildren(node **head, char c){
	if (head == NULL || *head == NULL){
        	return;
        }	
    	node *temp = NULL;
    	if ((*head)->children[c - 'a'] == NULL){
        	temp = resetNode();
        	temp->letter = c;
        	(*head)->children[c - 'a'] = temp;
    	}
    	else{
      	temp = (*head)->children[c - 'a'];
    	}
    	*head = temp;
}

node *resetNode(){
    	node *temp = (node *)malloc(sizeof(node));
    	temp->count = 0;
    	temp->isLeaf = false;
    	temp->letter = 0;
    	for (size_t i = 0; i < NUM_LETTERS; i++){
		temp->children[i] = NULL;
    	}
	return temp;
}

void clearNode(node *node){
    	for (int i = NUM_LETTERS - 1; i >= 0; i--){
        	if (node->children[i] != NULL){
            		clearNode(node->children[i]);
        	}
    	}
    	if (node != NULL){
        	free(node);
    	}
}

