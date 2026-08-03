#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    char command[100];

    printf("Enter a Linux command: ");
    scanf("%s", command);

    int pid = fork();

    // Fork failed
    if (pid < 0)
    {
        printf("Fork Failed!\n");
        return 1;
    }

    // Child Process
    if (pid == 0)
    {
        printf("\n----- Child Process -----\n");
        printf("Child PID : %d\n", getpid());

        execlp(command, command, NULL);

        printf("Invalid Command!\n");
        exit(1);
    }

    // Parent Process
    else
    {
        printf("\n----- Parent Process -----\n");
        printf("Parent PID : %d\n", getpid());
        printf("Child PID  : %d\n", pid);

        wait(NULL);

        printf("\nChild Process Completed Successfully.\n");
    }

    return 0;
}
