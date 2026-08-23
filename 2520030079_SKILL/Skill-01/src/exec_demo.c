#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;

    printf("Parent process PID: %d\n", getpid());

    pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    }

    if (pid == 0) {
        printf("Child process PID: %d\n", getpid());
        printf("Child executing ls command using exec()\n");

        execl("/bin/ls", "ls", "-l", NULL);

        perror("exec failed");
        return 1;
    }

    printf("Parent continues execution\n");

    return 0;
}
