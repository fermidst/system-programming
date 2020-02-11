#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


struct State
{
    bool FirstCommandState;
    bool SecondCommandState;
    bool ThirdCommandState;
} State;

void *FirstCommand()
{
    printf("FirstCommand\n");
    State.FirstCommandState = true;
}

void *SecondCommand()
{
    printf("SecondCommand\n");
    State.SecondCommandState = true;
}


void *ThirdCommand()
{
    printf("ThirdCommand\n");
    State.ThirdCommandState = true;
}

void *(*func_ptr[3])() = { FirstCommand, SecondCommand, ThirdCommand };

int main()
{
    char cmdToExit[5];
    int *countOfApps;
    char firstArg[10];
    char secondArg[10];
    FILE *appSettings;

    appSettings = fopen("/Users/salodar/CLionProjects/lab2_third/appsettings.txt", "rt");

    if (appSettings == NULL) {
        printf("Error opening file");
        exit(1);
    }

    fscanf(appSettings, "%s\n", &firstArg);
    fscanf(appSettings, "\n%s", &secondArg);

    char *t1 = strtok(firstArg, ":");
    t1 = strtok(NULL, ":");
    char *t2 = strtok(secondArg, ":");
    t2 = strtok(NULL, ":");

    fclose(appSettings);

    countOfApps = atoi(t1);

    if (strcmp(t2, "q") == 0) {
        strcpy(cmdToExit, "quit");
    } else if (strcmp(t2, "x") == 0) {
        strcpy(cmdToExit, "exit");
    } else {
        printf("Error: second argument is not correct");
        return (1);
    }
    for (int i = 0; i < countOfApps; ++i) {
        (*func_ptr[i])();
    }

    char input[4];
    while (true) {
        scanf("%4s", input);

        if (strcmp(input, cmdToExit) == 0) {
            printf("Exit...\n");
            exit(0);
        } else {
            printf("Not correct command\n");
        }
    }
}
