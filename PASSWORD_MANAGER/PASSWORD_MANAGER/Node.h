#pragma once
#include "Application.h"

typedef struct Node {
	pApplication data;
	struct Node* next;
} NODE, *pNode;

// This function is designed to create the pNode and allocate space for everything it consists of.
pNode createNode();

// This function is designed to create a pNode and initialize it with passed values.
pNode initNode(char* appName, char* username, char* password);

// This function is designed to link two pNodes
void linkNext(pNode n, pNode next);

// This function is designed to free allocated space for the Node.
void deleteNode(pNode n);