#pragma once

#define APPNAME_LENGTH 40
#define USERNAME_LENGTH 40
#define PASSWORD_LENGTH 40

typedef struct Application {
	char* appName;
	char* username;
	char* password;
} APPLICATION, *pApplication;

// This function is designed to create the pApplication and allocate space for everything
pApplication createApplication();

// This function is designed to create a pApplication and initialize it with a passed values
pApplication initApplication(char* appName, char* username, char* pass);

// This function is designed to change the appName to a passed value
void setAppName(pApplication app, char* newAppName);

// This function is designed to change the username to a passed value
void setUsername(pApplication app, char* newUsername);

// This function is designed to change the password to a passed value
void setPassword(pApplication app, char* newPassword);

// This function is designed to generate a random password
char* generatePassword();

// This function is designed to check the strength of the passed password on the scale from 0 to 10
int checkPasswordStrength(char* pass);

// This function is designed to free the allocated space
void deleteApplication(pApplication app);