#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    int fd[2];
    pid_t pid;

    char message[] = "Hello from Parent";
    char buffer[100];

    // Create pipe
    if (pipe(fd) == -1)
    {
        perror("pipe");
        return 1;
    }

    // Create child process
    pid = fork();

    if (pid < 0)
    {
        perror("fork");
        return 1;
    }

    if (pid > 0)
    {
        // Parent process
        close(fd[0]);

        printf("Parent PID: %d\n", getpid());
        printf("Parent: Sending data...\n");

        write(fd[1], message, strlen(message) + 1);

        close(fd[1]);

        wait(NULL);
    }
    else
    {
        // Child process
        close(fd[1]);

        printf("Child PID: %d\n", getpid());

        read(fd[0], buffer, sizeof(buffer));

        printf("Child: Received data = %s\n", buffer);

        close(fd[0]);

        exit(0);
    }

    return 0;
}
