#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <zconf.h>
#include <pthread.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wmissing-noreturn"

struct FunctionStatus
{
    bool f1;
    bool f2;
} functionStatus;

void *f1()
{
    printf("%p f1\n", f1);
}

void *f2()
{
    printf("%p f2\n", f2);
}

void startF1()
{
    functionStatus.f1 = true;
}

void startF2()
{
    functionStatus.f2 = true;
}

void *taskManager(bool hasLoop)
{
    while (true) {
        if (functionStatus.f1 == true) {
            f1();
            functionStatus.f1 = false;
        }
        if (functionStatus.f2 == true) {
            f2();
            functionStatus.f2 = false;
        }

        if (!hasLoop) { break; }
    }
}

void *CLI(bool hasLoop)
{
    while (true) {
        char input[4];
        scanf("%4s", input);

        if (strcmp(input, "f1") == 0) {
            startF1();
        } else if (strcmp(input, "f2") == 0) {
            startF2();
        } else if (strcmp(input, "exit") == 0) {
            exit(EXIT_SUCCESS);
        } else {
            printf("Not correct command.\n");
        }

        if (!hasLoop) { break; }
    }
}

void helpInfo()
{
    printf("Commands list : f1, f2, exit.\n");
}

int main()
{
    helpInfo();

    bool useThreads = true;

    if (useThreads == false) {
        while (true) {
            taskManager(false);
            CLI(false);
        }
    } else {
        pthread_t taskThreadId;
        pthread_create(&taskThreadId, NULL, taskManager, true);

        pthread_t cliThreadId;
        pthread_create(&cliThreadId, NULL, CLI, true);

        pthread_join(taskThreadId, NULL);
        pthread_join(cliThreadId, NULL);
    }
}

#pragma clang diagnostic pop