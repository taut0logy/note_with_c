#include <stdio.h>
#include <string.h>
#include "auth.h"
#include "entries.h"
#include "utils.h"

int main()
{
    int choice;
    char username[50];

    while (1)
    {
        CLEAR_SCREEN();
        printf("Welcome to the Personal Diary Application!\n");
        printf("1. Sign Up\n2. Log In\n3. Exit\n");
        printf("Choose an option: ");

        scanf("%d", &choice);

        if (choice == 1)
        {
            signUp();
            getchar();
            printf("Press Enter to continue...");
            getchar();
        }
        else if (choice == 2)
        {
            if (login(username))
            {
                while (1)
                {
                    CLEAR_SCREEN();
                    printf("Hello, %s!\n", username);
                    printf("1. Add Entry\n2. View Entries\n3. Delete Entries\n4. Logout\n");
                    printf("Choose an option: ");
                    
                    scanf("%d", &choice);

                    if (choice == 1)
                    {
                        addEntry(username);
                        getchar();
                        printf("Press Enter to continue...");
                        getchar();
                    }
                    else if (choice == 2)
                    {
                        viewEntries(username);
                        getchar();
                        printf("Press Enter to continue...");
                        getchar();
                    }
                    else if (choice == 3)
                    {
                        deleteEntries(username);
                        getchar();
                        printf("Press Enter to continue...");
                        getchar(); 
                    }
                    else if (choice == 4)
                    {
                        printf("Logging out...\n");
                        getchar();
                        getchar();
                        break;
                    }
                }
            }
            else
            {
                getchar();
                printf("Press Enter to continue...");
                getchar();
            }
        }
        else if (choice == 3)
        {
            printf("Exiting the application. Goodbye!\n");
            getchar();
            break;
        }
        else
        {
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
