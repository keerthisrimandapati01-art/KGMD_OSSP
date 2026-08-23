#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t child1, child2;

    printf("Parent PID: %d\n", getpid());

    child1 = fork();

    if (child1 < 0) {
        perror("fork failed");
        return 1;
    }

    if (child1 == 0) {
        printf("Child 1 PID: %d, Parent PID: %d\n",
               getpid(), getppid());
        sleep(10);
        return 0;
    }

    child2 = fork();

    if (child2 < 0) {
        perror("fork failed");
        return 1;
    }

    if (child2 == 0) {
        printf("Child 2 PID: %d, Parent PID: %d\n",
               getpid(), getppid());
        sleep(10);
        return 0;
    }

    printf("Parent created two children.\n");

    wait(NULL);
    wait(NULL);

    printf("Both child processes completed.\n");

    return 0;
}
