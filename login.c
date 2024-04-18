#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "sha256.h"

#define MAX_USERS 100
#define MAX_USERNAME_LENGTH 50
#define HASH_LENGTH 64 // SHA-256 produces 64-character hash

struct User
{
    char username[MAX_USERNAME_LENGTH];
    char passwordHash[HASH_LENGTH + 1]; // +1 for null terminator
};

void signUp(struct User users[], int *numUsers);
bool login(struct User users[], int numUsers);
void hashPassword(const char *password, char *hash);

int main()
{
    struct User users[MAX_USERS];
    int numUsers = 0;
    char choice;

    // Load existing user data from file
    FILE *file = fopen("userdata.txt", "r");
    if (file != NULL)
    {
        while (fscanf(file, "%s %s", users[numUsers].username, users[numUsers].passwordHash) != EOF)
        {
            numUsers++;
        }
        fclose(file);
    }

    do
    {
        printf("\n1. Sign Up\n2. Login\n3. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice)
        {
        case '1':
            signUp(users, &numUsers);
            break;
        case '2':
            if (login(users, numUsers))
            {
                printf("Login successful!\n");
            }
            else
            {
                printf("Login failed. Invalid username or password.\n");
            }
            break;
        case '3':
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != '3');

    // Save user data to file before exiting
    file = fopen("userdata.txt", "a");
    if (file != NULL)
    {
        for (int i = 0; i < numUsers; i++)
        {
            fprintf(file, "%s %s\n", users[i].username, users[i].passwordHash);
        }
        fclose(file);
    }

    return 0;
}

void signUp(struct User users[], int *numUsers)
{
    if (*numUsers >= MAX_USERS)
    {
        printf("Maximum number of users reached.\n");
        return;
    }

    printf("Enter username: ");
    scanf("%s", users[*numUsers].username);

    char password[MAX_USERNAME_LENGTH];
    printf("Enter password: ");
    scanf("%s", password);

    hashPassword(password, users[*numUsers].passwordHash);

    (*numUsers)++;
    printf("\nSign up successful!\n");
}

bool login(struct User users[], int numUsers)
{
    char username[MAX_USERNAME_LENGTH];
    printf("Enter username: ");
    scanf("%s", username);

    char password[MAX_USERNAME_LENGTH];
    printf("Enter password: ");
    scanf("%s", password);

    char hash[HASH_LENGTH + 1];
    hashPassword(password, hash);

    for (int i = 0; i < numUsers; i++)
    {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].passwordHash, hash) == 0)
        {
            return true;
        }
    }
    return false;
}

void hashPassword(const char *password, char *hash)
{
    SHA256_CTX ctx;
    sha256_init(&ctx);
    sha256_update(&ctx, (const uint8_t *)password, strlen(password));
    sha256_final(&ctx, (uint8_t *)hash);
    hash[HASH_LENGTH] = '\0'; // Null terminator
}

// gcc login.c sha256.c - o login
// ./login
