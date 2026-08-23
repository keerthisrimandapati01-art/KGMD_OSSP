#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main()
{
    pid_t pid;

    printf("Before fork():\n");
    printf("Process PID  = %d\n", getpid());
    printf("Parent PPID  = %d\n\n", getppid());

    pid = fork();

    if (pid < 0)
    {
        perror("fork failed");
        return 1;
    }

    if (pid == 0)
    {
        // Child process
        printf("\n--- CHILD PROCESS ---\n");
        printf("Child PID  = %d\n", getpid());
        printf("Child PPID = %d\n", getppid());
        printf("Child is running...\n");

        // Keep child running so its state can be observed
        sleep(60);

        printf("Child process terminating...\n");
        exit(0);
    }    else
    {
        // Parent process
        printf("\n--- PARENT PROCESS ---\n");
        printf("Parent PID  = %d\n", getpid());
        printf("Parent PPID = %d\n", getppid());
        printf("Child PID   = %d\n", pid);
        printf("Parent is waiting/sleeping...\n");

        sleep(20);

        printf("Parent process terminating...\n");
    }

    return 0;
}
