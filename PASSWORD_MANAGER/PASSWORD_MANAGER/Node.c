#include <stdio.h>
#include <stdlib.h>
#include "Node.h"

pNode createNode() {
	pNode n = (pNode)malloc(sizeof(pNode));
	if (!n) {
		fprintf(stderr, "Error allocating memory.\n");
		exit(-1);
	}

	n->data = NULL;
	n->next = NULL;

	return n;
}

pNode initNode(char* appName, char* username, char* password) {
	pNode node = createNode();

	node->data = initApplication(appName, username, password);
	node->next = NULL;

	return node;
}

void linkNext(pNode n, pNode next) {
	n->next = next;
}

void deleteNode(pNode n) {
	deleteApplication(n->data);

	n->next = NULL;

	n = NULL;
}