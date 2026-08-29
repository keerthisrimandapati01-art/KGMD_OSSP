#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    char command[100];

    printf("Enter command: ");
    scanf("%99s", command);

    /* Check if command contains a path */
    if (strchr(command, '/') != NULL) {
        if (access(command, X_OK) == 0) {
            printf("Executable found: %s\n", command);
        } else {
            printf("Command not found or not executable.\n");
        }
        return 0;
    }

    /* Retrieve PATH variable */
    char *path = getenv("PATH");

    if (path == NULL) {
        printf("PATH variable not found.\n");
        return 1;
    }

    /* Make a copy because strtok modifies the string */
    char *path_copy = strdup(path);

    if (path_copy == NULL) {
        perror("strdup");
        return 1;
    }

    /* Parse PATH directories */
    char *directory = strtok(path_copy, ":");

    while (directory != NULL) {
        char full_path[512];

        snprintf(full_path, sizeof(full_path), "%s/%s",
                 directory, command);

        /* Check whether executable exists */
        if (access(full_path, X_OK) == 0) {
            printf("Executable found: %s\n", full_path);
            free(path_copy);
            return 0;
        }

        directory = strtok(NULL, ":");
    }

    printf("Command '%s' not found in PATH.\n", command);

    free(path_copy);
    return 0;
}
