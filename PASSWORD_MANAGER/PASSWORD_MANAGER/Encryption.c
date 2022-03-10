#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Encryption.h"

char* encrypt(pApplication app) {
	int userLength = strlen(app->username);
	int length = strlen(app->password);
	char* encrypted = (char*)calloc((APPNAME_LENGTH + USERNAME_LENGTH + PASSWORD_LENGTH) * 2, sizeof(char));

	strncat(encrypted, app->appName, APPNAME_LENGTH);
	strncat(encrypted, '~', 1);

	for (int i = 0; i < userLength; i++) {
		strncat(encrypted, *(app->username + i) - 1, 1);
		strncat(encrypted, *(app->username + i) + 1, 1);
	}
	strncat(encrypted, '~', 1);
	for (int i = 0; i < length; i++) {
		strncat(encrypted, *(app->password + i) - 1, 1);
		strncat(encrypted, *(app->password + i) + 1, 1);
	}

	return encrypted;
}

void decrypt(pApplication app) {
	char* decryptedUsername = (char*)calloc(USERNAME_LENGTH, sizeof(char)); 
	char* decryptedPassword = (char*)calloc(PASSWORD_LENGTH, sizeof(char));
	int usernameLength = strlen(app->username);
	int passwordLength = strlen(app->password);
	for (int i = 0, j = 0; i < usernameLength - 1; i += 2, j++) {
		decryptedUsername[j] = (app->username[i] + app->username[i + 1]);
	}
	for (int i = 0, j = 0; i < passwordLength; i += 2, j++) {
		decryptedPassword[j] = (app->password[i] + app->password[i + 1]);
	}
}