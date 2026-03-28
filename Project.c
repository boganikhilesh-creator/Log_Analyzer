#include <stdio.h>
#include <string.h>

#define MAX_USERS 100

struct User {
    char name[50];
    int failed;
};

struct Account {
    char username[50];
    char password[50];
} accounts[] = {
    {"Koushik", "pass1"},
    {"Nikhilesh", "pass2"},
    {"Adesh", "admin123"}
};

int totalAccounts = 3;

int findUser(struct User users[], int count, char name[]) {
    for (int i = 0; i < count; i++) {
        if (strcmp(users[i].name, name) == 0)
            return i;
    }
    return -1;
}

int checkLogin(char uname[], char pwd[]) 
{
    for (int i = 0; i < totalAccounts; i++) 
    {

        if (strcmp(accounts[i].username, uname) == 0) 
        {

            if (strcmp(accounts[i].password, pwd) == 0)
                return 1;

            else
                return 2;
        }
    }

    return 0;
}

int main() {
    FILE *fp;

    fp = fopen("log.txt", "w");
    if (fp == NULL) {
        printf("Error creating log file!\n");
        return 1;
    }
    fclose(fp);

    char username[50], password[50];

    printf("Commands:\n");
    printf("Type 'stop' to analyze logs\n");
    printf("Type 'clear' to reset logs\n\n");

    while (1) {
        printf("Enter username: ");
        scanf("%s", username);

        if (strcmp(username, "stop") == 0)
            break;

        if (strcmp(username, "clear") == 0) {
            fp = fopen("log.txt", "w");
            fclose(fp);
            printf("Log cleared!\n");
            continue;
        }

        printf("Enter password: ");
        scanf("%s", password);

        fp = fopen("log.txt", "a");

        int result = checkLogin(username, password);

        if (result == 1) {
            printf("Login Success\n");
            fprintf(fp, "LOGIN SUCCESS %s\n", username);
        }
        else if (result == 2) {
            printf("Incorrect Password\n");
            fprintf(fp, "LOGIN FAILED %s\n", username);
        }
        else {
            printf("No such user exists\n");
            fprintf(fp, "LOGIN FAILED UNKNOWN_%s\n", username);
        }

        fclose(fp);
    }

    fp = fopen("log.txt", "r");

    struct User users[MAX_USERS];
    int userCount = 0;

    char line[100], status[20], user[50];

    while (fgets(line, sizeof(line), fp)) {
        sscanf(line, "LOGIN %s %s", status, user);

        int index = findUser(users, userCount, user);

        if (index == -1) {
            strcpy(users[userCount].name, user);
            users[userCount].failed = 0;
            index = userCount;
            userCount++;
        }

        if (strcmp(status, "FAILED") == 0) {
            users[index].failed++;
        }
    }

    fclose(fp);

    printf("\n===== LOGIN ANALYSIS REPORT =====\n");

    for (int i = 0; i < userCount; i++) {
        printf("User: %s | Failed Attempts: %d", users[i].name, users[i].failed);

        if (users[i].failed >= 3) {
            printf(" Suspicious Activity!");

            system("send_mail.py");
        }

        printf("\n");
    }

    return 0;
}