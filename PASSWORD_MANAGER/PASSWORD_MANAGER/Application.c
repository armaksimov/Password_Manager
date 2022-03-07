#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Application.h"

pApplication createApplication() {
	pApplication app = (pApplication)malloc(sizeof(pApplication));
	if (!app) {
		fprintf(stderr, "Error allocating memory.\n");
		exit(-1);
	}

	app->appName = (char*)calloc(APPNAME_LENGTH, sizeof(char));
	if (!app->appName) {
		fprintf(stderr, "Error allocating memory.\n");
		exit(-1);
	}

	app->username = (char*)calloc(USERNAME_LENGTH, sizeof(char));
	if (!app->username) {
		fprintf(stderr, "Error allocating memory.\n");
		exit(-1);
	}

	app->password = (char*)calloc(PASSWORD_LENGTH, sizeof(char));
	if (!app->password) {
		fprintf(stderr, "Error allocating memory.\n");
		exit(-1);
	}

	return app;
}


pApplication initApplication(char* appName, char* username, char* pass) {
	pApplication app = createApplication();

	app->appName = appName;
	app->username = username;
	app->password = pass;

	return app;
}


void setAppName(pApplication app, char* newAppName) {
	app->appName = newAppName;
}


void setUsername(pApplication app, char* newUsername) {
	app->username = newUsername;
}


void setPassword(pApplication app, char* newPassword) {
	app->password = newPassword;
}


char* generatePassword() {
	/// <summary>
	/// This function generates a password with random length from 10 to 15, which consists of ASCII table characters from 33 to 126.
	/// Once the password is created function checks its strength with checkPasswordStrength function and if the password isn`t strong enough function calls itself again.
	/// </summary>
	/// <returns>
	/// This function a password as an array of characters (string)
	/// </returns>
	 
	char* password = (char*)calloc(PASSWORD_LENGTH, sizeof(char));
	if (!password) {
		fprintf(stderr, "Error allocating memory.\n");
		exit(-1);
	}

	srand(time(NULL));

	int passwordLength = rand() % 5 + 10;

	for (int i = 0; i < passwordLength; i++) {
		*(password + i) = rand() % 94 + 33; // generates a number between 33 and 126
	}

	if (checkPasswordStrength(password) < 7) {
		generatePassword();
	}
	else {
		return password;
	}
	return NULL;
}


int checkPasswordStrength(char* pass) {
	/// <summary>
	/// This function analyzes if the passed password is strong enough on scale from 0 to 10
	///		1. If the password length is greater than or equal to 12 characters - password receives 2 points, if the password length is greater than or equal to 8 characters - password receives 1 point, otherwise no points for length are given.
	///		2. If number of capital letters in password is greater than 2 - password receives extra 2 points, if number of capital letters in password is less than 2, but greater than 0 - password receives 1 extra point, if none of the cases are satisfied - no extra points are given.
	///		3. If number of lowercase letters in password is greater than 2 - password receives extra 2 points, if number of lowercase letters in password is less than 2, but greater than 0 - password receives 1 extra point, if none of the cases are satisfied - no extra points are given.
	///		4. If number of digits in password is greater than 2 - password receives extra 2 points, if number of digits in password is less than 2, but greater than 0 - password receives 1 extra point, if none of the cases are satisfied - no extra points are given.
	///		5. If number of special characters in password is greater than 2 - password receives extra 2 points, if number of special characters in password is less than 2, but greater than 0 - password receives 1 extra point, if none of the cases are satisfied - no extra points are given.
	/// 
	///		So, maximum 10 points can be given.
	///		And, if the password receives:
	///			0 - 2 points - Very weak password
	///			3 - 4 points - Weak password
	///			5 - 6 points - Medium strength password
	///			7 - 8 points - Strong password
	///			9 - 10 points - Very strong password
	/// </summary>
	/// <param name="pass">
	///		This function receives a password to asses as an array of characters (string), called "pass". 
	/// </param>
	/// <returns>
	///		This function returns an integer called strengthLevel.
	/// </returns>

	int strengthLevel = 0, length = strlen(pass);
	int numOfLowercaseLetters = 0, numOfCapitalLetters = 0, numofSpecialChars = 0, numOfNumbers = 0;

	for (int i = 0; i < length; i++) {
		if (*(pass + i) >= 'a' && *(pass + i) <= 'z') {
			numOfLowercaseLetters++;
		}
		else if (*(pass + i) >= 'A' && *(pass + i) <= 'Z') {
			numOfCapitalLetters++;
		}
		else if (*(pass + i) >= '0' && *(pass + i) <= '9') {
			numOfNumbers++;
		}
		else {
			numofSpecialChars++;
		}
	}

	if (length >= 12) {
		strengthLevel = 2;
	}
	else if (length >= 8) {
		strengthLevel = 1;
	}

	if (numOfCapitalLetters > 2) {
		strengthLevel += 2;
	}
	else if (numOfCapitalLetters > 0) {
		strengthLevel += 1;
	}

	if (numOfLowercaseLetters > 2) {
		strengthLevel += 2;
	}
	else if (numOfLowercaseLetters > 0) {
		strengthLevel += 1;
	}

	if (numOfNumbers > 2) {
		strengthLevel += 2;
	}
	else if (numOfNumbers > 0) {
		strengthLevel += 1;
	}

	if (numofSpecialChars > 2) {
		strengthLevel += 2;
	}
	else if (numofSpecialChars > 0) {
		strengthLevel += 1;
	}

	return strengthLevel;
}


void deleteApplication(pApplication app) {
	free(app->appName);
	app->appName = NULL;

	free(app->username);
	app->username = NULL;

	free(app->password);
	app->password = NULL;

	free(app);
	app = NULL;
}