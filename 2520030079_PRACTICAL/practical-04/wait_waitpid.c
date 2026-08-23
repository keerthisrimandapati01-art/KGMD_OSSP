#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t child1, child2;
    int status;

    printf("Parent PID = %d\n", getpid());

    // Create first child
    child1 = fork();

    if (child1 < 0)
    {
        perror("fork failed");
        exit(1);
    }

    if (child1 == 0)
    {
        printf("Child 1: PID = %d, PPID = %d\n", getpid(), getppid());
        sleep(3);
        printf("Child 1 terminating...\n");
        exit(10);
    }

    // Create second child
    child2 = fork();

    if (child2 < 0)
    {
        perror("fork failed");
        exit(1);
    }

    if (child2 == 0)
    {
        printf("Child 2: PID = %d, PPID = %d\n", getpid(), getppid());
        sleep(1);
        printf("Child 2 terminating...\n");
        exit(20);
    }

    // Parent waits for any child
    printf("\nParent using wait()...\n");
    pid_t finished = wait(&status);

    if (WIFEXITED(status))
    {
        printf("wait(): Child PID %d terminated with exit status %d\n",
               finished, WEXITSTATUS(status));
    }

    // Parent waits specifically for child1
    printf("\nParent using waitpid() for Child 1...\n");
    waitpid(child1, &status, 0);

    if (WIFEXITED(status))
    {
        printf("waitpid(): Child PID %d terminated with exit status %d\n",
               child1, WEXITSTATUS(status));
    }

    printf("\nParent process terminating...\n");

    return 0;
}
