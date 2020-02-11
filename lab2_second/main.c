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

int main(int argc, char **argv)
{
    char cmdToExit[5];
    int countOfApps;

    if (argc > 3 || argc < 1) {
        printf("Error: found %d arguments. Needs exactly 2", argc - 1);
        return (1);
    }

    countOfApps = atoi(argv[1]);

    if (countOfApps > 3 || countOfApps < 1) {
        printf("Error: first argument is not correct");
        return (1);
    }

    if (strcmp(argv[2], "-q") == 0) {
        strcpy(cmdToExit, "quit");
    } else if (strcmp(argv[2], "-x") == 0) {
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


