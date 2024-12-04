#include <stdio.h>
#include <string.h>
#include "auth.h"

#define USERS_FILE "users.txt"

int signUp()
{
    char username[50], password[50];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    FILE *file = fopen(USERS_FILE, "a");
    if (!file)
    {
        printf("Error opening users file.\n");
        return 0;
    }
    fprintf(file, "%s %s\n", username, password);
    fclose(file);

    printf("Sign-up successful!\n");
    return 1;
}

int login(char *username)
{
    char password[50], fileUser[50], filePass[50];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    FILE *file = fopen(USERS_FILE, "r");
    if (!file)
    {
        printf("Error opening users file.\n");
        return 0;
    }

    while (fscanf(file, "%s %s", fileUser, filePass) != EOF)
    {
        if(strcmp(username, fileUser) == 0)
        {
            if (strcmp(password, filePass) == 0)
            {
                fclose(file);
                printf("Login successful!\n");
                return 1;
            }
            else 
            {
                fclose(file);
                printf("Wrong Password.\n");
                return 0;
            }
        }
    }
    fclose(file);
    printf("Invalid username.\n");
    return 0;
}
