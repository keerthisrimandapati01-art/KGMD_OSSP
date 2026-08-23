#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>

#define BUFFER_SIZE 1024

void enable_raw_mode(struct termios *original) {
    struct termios raw;

    tcgetattr(STDIN_FILENO, original);
    raw = *original;

    raw.c_lflag &= ~(ICANON | ECHO);

    tcsetattr(STDIN_FILENO, TCSANOW, &raw);
}

void disable_raw_mode(struct termios *original) {
    tcsetattr(STDIN_FILENO, TCSANOW, original);
}

int read_input(char *buffer, int size) {
    int index = 0;
    char c;

    while (index < size - 1) {
        if (read(STDIN_FILENO, &c, 1) != 1) {
            return -1;
        }

        /* Enter key */
        if (c == '\n' || c == '\r') {
            buffer[index] = '\0';
            printf("\n");
            return index;
        }

        /* Backspace key */
        if (c == 127 || c == 8) {
            if (index > 0) {
                index--;
                printf("\b \b");
                fflush(stdout);
            }
            continue;
        }

        /* Normal character */
        if (c >= 32 && c <= 126) {
            buffer[index++] = c;
            putchar(c);
            fflush(stdout);
        }
    }

    buffer[index] = '\0';
    printf("\n");

    return index;
}

int main() {
    char input[BUFFER_SIZE];
    struct termios original;

    while (1) {
        printf("keerthi-shell> ");
        fflush(stdout);

        enable_raw_mode(&original);

        int length = read_input(input, BUFFER_SIZE);

        disable_raw_mode(&original);

        if (length < 0) {
            printf("\nInput error.\n");
            break;
        }

        if (strcmp(input, "exit") == 0) {
            printf("Goodbye!\n");
            break;
        }

        if (length > 0) {
            printf("You entered: %s\n", input);
        }
    }

    return 0;
}
