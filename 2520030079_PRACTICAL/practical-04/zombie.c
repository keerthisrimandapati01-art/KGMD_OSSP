#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t pid;

    printf("Parent PID = %d\n", getpid());

    pid = fork();

    if (pid < 0)
    {
        perror("fork failed");
        return 1;
    }

    if (pid == 0)
    {
        printf("Child PID = %d\n", getpid());
        printf("Child is terminating...\n");
        exit(0);
    }
    else
    {
        printf("Parent PID = %d\n", getpid());
        printf("Child PID = %d\n", pid);
        printf("Parent is waiting for child...\n");

wait(NULL);

printf("Child process collected. Zombie eliminated.\n");
printf("Parent terminating...\n");
    }

    return 0;
}

