#pragma once
#include "Node.h"

typedef struct linkedList {
	int size;
	pNode* list;
} LINKED_LIST, * pLinkedList;

typedef enum DUPLICATE { DUPLICATES, DUPLICATES_APP_USERNAME, DUPLICATES_PASSWORD, NOT_A_DUPLICATE } DUPLICATE;

// This function is designed to create the pLinkedList and allocate space for everything it consists of.
pLinkedList createLinkedList();

// This function is designed to create a new pNode, initialize it and add to the end of the linked list.
void add(pLinkedList list, char* appName, char* username, char* password);

// This function is designed to return the member (pNode) from the linked list (instance of pLinkedList) by its number in the list.
pNode peek(pLinkedList list, int index);

// This function is designed to return the last member (pNode) from the linked list (instance of pLinkedList).
pNode peekLast(pLinkedList list);

// This function is designed to return the first member (pNode) from the linked list (instance of pLinkedList).
pNode peekFirst(pLinkedList list);

// This function is designed to delete the node by passed index and return it for further printing.
pApplication removeNode(pLinkedList list, int index);

// This function is designed to find the member (pNode) in the linked list (instance of pLinkedList) by the app name and return its position in the list.
int search(pLinkedList list, char* appName, char* username);

// This function is designed to check if the password repeats in any of applications in the list.
DUPLICATE checkPassword(pLinkedList list, char* password);

// This function is designed to check if the list has any duplicates of entered data.
DUPLICATE checkDuplicates(pLinkedList list, char* appName, char* username, char* password);

// This function returns the size of the linked list.
int getSize(pLinkedList list);

// This function is designed to encrypt the contents of the linked list and write everyting to the file
void writeToFile(char* fileName, pLinkedList list);

// This function is designed to read the contents of the text file and decrpt them
pLinkedList readFromFile(char* fileName);

// This function is designed to remove every member of the linked list.
void clear(pLinkedList list);

// This function is designed to delete the linked list and all its members.
void deleteList(pLinkedList list);