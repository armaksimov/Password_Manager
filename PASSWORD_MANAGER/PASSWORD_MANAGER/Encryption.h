#pragma once
#include "LinkedList.h"

// This function is designe to encrypt the username & password before writing to the file.
char* encrypt(pApplication app);

// This function is desgned to decrypt the username & password read from the text file.
void decrypt(pApplication app);