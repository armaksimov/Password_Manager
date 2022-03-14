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
	strncat(encrypted, "~", 1);

	for (int i = 0; i < userLength; i++) {
		char prev = *(app->username + i) - 1;
		char next = *(app->username + i) + 1;
		strncat(encrypted, &prev, 1);
		strncat(encrypted, &next, 1);
	}
	strncat(encrypted, "~", 1);
	for (int i = 0; i < length; i++) {
		char prev = *(app->password + i) - 1;
		char next = *(app->password + i) + 1;
		strncat(encrypted, &prev, 1);
		strncat(encrypted, &next, 1);
	}

	return encrypted;
}

void decrypt(pApplication app) {
	char* decryptedUsername = (char*)calloc(USERNAME_LENGTH, sizeof(char)); 
	char* decryptedPassword = (char*)calloc(PASSWORD_LENGTH, sizeof(char));
	int usernameLength = strlen(app->username);
	int passwordLength = strlen(app->password);
	for (int i = 0, j = 0; i < usernameLength - 1; i += 2, j++) {
		char decrypted = (app->username[i] + app->username[i + 1]) / 2;
		strncat(decryptedUsername, &decrypted, 1);
	}
	for (int i = 0, j = 0; i < passwordLength; i += 2, j++) {
		char decrypted = (app->password[i] + app->password[i + 1]) / 2;
		strncat(decryptedPassword, &decrypted, 1);
	}
	strncpy(app->username, decryptedUsername, USERNAME_LENGTH);
	strncpy(app->password, decryptedPassword, PASSWORD_LENGTH);
}