#include <stdio.h>
#include <string.h>
#include "entries.h"

#define ENTRIES_FILE "entries.txt"

void addEntry(const char *username)
{
    char title[50], description[200];
    printf("Enter entry title: ");
    getchar(); // Consume leftover newline
    fgets(title, 50, stdin);
    strtok(title, "\n"); // Remove newline

    printf("Enter entry description: ");
    fgets(description, 200, stdin);
    strtok(description, "\n"); // Remove newline

    FILE *file = fopen(ENTRIES_FILE, "a");
    if (!file)
    {
        printf("Error opening entries file.\n");
        return;
    }
    fprintf(file, "%s: %s - %s\n", username, title, description);
    fclose(file);

    printf("Entry added successfully!\n");
}

void viewEntries(const char *username)
{
    char line[300];
    FILE *file = fopen(ENTRIES_FILE, "r");
    if (!file)
    {
        printf("Error opening entries file.\n");
        return;
    }

    printf("Your entries:\n");
    while (fgets(line, sizeof(line), file))
    {
        if (strstr(line, username) == line)
        {
            printf("%s", line);
        }
    }
    fclose(file);
}

void deleteEntries(const char *username)
{
    char line[300];
    FILE *file = fopen(ENTRIES_FILE, "r");
    FILE *temp = fopen("temp.txt", "w");
    if (!file || !temp)
    {
        printf("Error processing files.\n");
        return;
    }

    while (fgets(line, sizeof(line), file))
    {
        if (strstr(line, username) != line)
        { // Skip user's entries
            fputs(line, temp);
        }
    }

    fclose(file);
    fclose(temp);
    remove(ENTRIES_FILE);
    rename("temp.txt", ENTRIES_FILE);

    printf("All your entries have been deleted.\n");
}
