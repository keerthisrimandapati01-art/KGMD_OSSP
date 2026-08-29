#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_INPUT 100

typedef void (*builtin_func)(char *);

void builtin_cd(char *args)
{
    if (args == NULL || strlen(args) == 0) {
        printf("cd: missing argument\n");
        return;
    }

    if (chdir(args) == 0)
        printf("Changed directory to: %s\n", args);
    else
        perror("cd");
}

void builtin_pwd(char *args)
{
    char cwd[1024];

    (void)args;

    if (getcwd(cwd, sizeof(cwd)) != NULL)
        printf("Current directory: %s\n", cwd);
    else
        perror("pwd");
}

void builtin_echo(char *args)
{
    (void)printf("%s\n", args ? args : "");
}

void builtin_exit(char *args)
{
    (void)args;
    printf("Exiting shell...\n");
    exit(0);
}

typedef struct {
    const char *name;
    builtin_func function;
} Builtin;

Builtin builtins[] = {
    {"cd", builtin_cd},
    {"pwd", builtin_pwd},
    {"echo", builtin_echo},
    {"exit", builtin_exit}
};

#define NUM_BUILTINS (sizeof(builtins) / sizeof(builtins[0]))

int main(void)
{
    char input[MAX_INPUT];

    printf("Simple Built-in Command Shell\n");

    while (1) {
        printf("myshell> ");
        fflush(stdout);

        if (fgets(input, sizeof(input), stdin) == NULL)
            break;

        input[strcspn(input, "\n")] = '\0';

        if (strlen(input) == 0)
            continue;

        char *command = strtok(input, " ");
        char *args = strtok(NULL, "");

        int found = 0;

        for (size_t i = 0; i < NUM_BUILTINS; i++) {
            if (strcmp(command, builtins[i].name) == 0) {
                builtins[i].function(args);
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("Command '%s' is not a built-in command.\n", command);
        }
    }

    return 0;
}
