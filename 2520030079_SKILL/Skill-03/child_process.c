#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    printf("=== CHILD PROCESS EXECUTION ===\n");

    pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    }

    if (pid == 0) {
        printf("\n--- CHILD PROCESS ---\n");
        printf("Child PID  = %d\n", getpid());
        printf("Parent PID = %d\n", getppid());
        printf("Executing ls command...\n");

        execlp("ls", "ls", "-l", NULL);

        perror("exec failed");
        exit(1);
    } else {
        printf("\n--- PARENT PROCESS ---\n");
        printf("Parent PID = %d\n", getpid());
        printf("Child PID  = %d\n", pid);
        printf("Parent waiting for child...\n");

        wait(NULL);

        printf("Child process completed.\n");
        printf("Parent process completed.\n");
    }

    return 0;
}
