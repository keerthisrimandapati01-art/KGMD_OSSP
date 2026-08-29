#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 500
#define MAX_OUTPUT 1000

void expand_variables(char *input, char *output) {
    int i = 0, j = 0;

    while (input[i] != '\0' && j < MAX_OUTPUT - 1) {

        if (input[i] == '$') {
            i++;

            /* Handle ${VARIABLE} format */
            if (input[i] == '{') {
                i++;

                char variable[100];
                int k = 0;

                while (input[i] != '\0' &&
                       input[i] != '}' &&
                       k < 99) {
                    variable[k++] = input[i++];
                }

                variable[k] = '\0';

                if (input[i] == '}')
                    i++;

                char *value = getenv(variable);

                if (value != NULL) {
                    int len = strlen(value);

                    if (j + len < MAX_OUTPUT - 1) {
                        strcpy(&output[j], value);
                        j += len;
                    }
                } else {
                    printf("Warning: Variable '%s' is undefined.\n",
                           variable);
                }
            }

            /* Handle $VARIABLE format */
            else {
                char variable[100];
                int k = 0;

                while ((input[i] >= 'A' && input[i] <= 'Z') ||
                       (input[i] >= 'a' && input[i] <= 'z') ||
                       (input[i] >= '0' && input[i] <= '9') ||
                       input[i] == '_') {

                    if (k < 99)
                        variable[k++] = input[i];

                    i++;
                }

                variable[k] = '\0';

                char *value = getenv(variable);

                if (value != NULL) {
                    int len = strlen(value);

                    if (j + len < MAX_OUTPUT - 1) {
                        strcpy(&output[j], value);
                        j += len;
                    }
                } else if (variable[0] != '\0') {
                    printf("Warning: Variable '%s' is undefined.\n",
                           variable);
                }
            }
        } else {
            output[j++] = input[i++];
        }
    }

    output[j] = '\0';
}

int main() {
    char input[MAX_INPUT];
    char output[MAX_OUTPUT];

    printf("Enter a string with variables: ");
    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = '\0';

    expand_variables(input, output);

    printf("Expanded string: %s\n", output);

    return 0;
}
