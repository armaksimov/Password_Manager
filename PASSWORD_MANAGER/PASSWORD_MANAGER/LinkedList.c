#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

pLinkedList createLinkedList() {
	pLinkedList l = (pLinkedList)malloc(sizeof(pLinkedList));
	if (!l) {
		fprintf(stderr, "Error allocating memory.\n");
		exit(-1);
	}

	l->size = 0;
	l->list = (pNode*)malloc(l->size * sizeof(pNode));
	if (!l->list) {
		fprintf(stderr, "Error allocating memory.\n");
		exit(-1);
	}

	return l;
}

void add(pLinkedList list, char* appName, char* username, char* password) {
	/// <summary>
	///		This function`s purpose is to create a new pNode, initialize with the list of passed values and then add it to the linked list
	/// </summary>
	/// <param name="list">
	///		The passed parameter called list is a linked list (instance of pLinkedList) to which a new node (instance of pNode) will be added
	/// </param>
	/// <param name="appName"; param name="username"; param name="password">
	///		The passed parameters called appName, username, password are the values with which the data of the new node will be initialized
	/// </param>

	list->size++;
	list->list = (pNode*)realloc(list->list, (list->size * sizeof(pNode)));
	if (!list->list) {
		fprintf(stderr, "Error reallocating memory.\n");
		exit(-1);
	}

	*(list->list + list->size - 1) = initNode(appName, username, password);

	if (list->size > 1) {
		linkNext(*(list->list + list->size - 2), *(list->list + list->size - 1));
	}
}

pNode peek(pLinkedList list, int index) {
	return *(list->list + index);
}

pNode peekLast(pLinkedList list) {
	return peek(list, list->size - 1);
}

pNode peekFirst(pLinkedList list) {
	return peek(list, 0);
}

pApplication removeNode(pLinkedList list, int index) {
	pApplication app = (*(list->list + index))->data;

	for (int j = index + 1; j < getSize(list) - 1; j++) {
		*(list->list + index) = *(list->list + j);
		linkNext(*(list->list + index), *(list->list + j));
	}

	list->size--;
	deleteNode(*(list->list + list->size));
	list->list = (pNode*)realloc(list->list, (list->size * sizeof(pNode)));

	return app;
}

int search(pLinkedList list, char* appName, char* username) {
	for (int i = 0; i < getSize(list); i++) {
		if (strncmp((*(list->list + i))->data->appName, appName, APPNAME_LENGTH) == 0 && strncmp((*(list->list + i))->data->username, username, USERNAME_LENGTH) == 0) {
			return i;
		}
	}
	return -1;
}

DUPLICATE checkPassword(pLinkedList list, char* password) {
	for (int i = 0; i < getSize(list); i++) {
		if (strncmp((*(list->list + i))->data->password, password, APPNAME_LENGTH) == 0) {
			return DUPLICATES_PASSWORD;
		}
	}
	return NOT_A_DUPLICATE;
}

DUPLICATE checkDuplicates(pLinkedList list, char* appName, char* username, char* password) {
	int index = search(list, appName, username);

	if (index != -1) {
		pApplication app = (*(list->list + index))->data;

		if (app && strncmp(app->password, password, PASSWORD_LENGTH) == 0) {
			return DUPLICATES;
		}
		else if (app) {
			return DUPLICATES_APP_USERNAME;
		}
	}
	else {
		if (checkPassword(list, password) == DUPLICATES_PASSWORD) {
			return DUPLICATES_PASSWORD;
		}
		else {
			return NOT_A_DUPLICATE;
		}
	}
}

int getSize(pLinkedList list) {
	return list->size;
}

void clear(pLinkedList list) {
	for (int i = getSize(list); i > 0; i--) {
		deleteNode(*(list->list + i));
	}
	list->size = 0;
	list->list = (pNode*)realloc(list->list, (list->size * sizeof(pNode)));
}

void deleteList(pLinkedList list) {
	clear(list);

	free(list->list);
	list->list = NULL;

	free(list);
	list = NULL;
}