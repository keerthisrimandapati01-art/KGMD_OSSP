#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

#define MAX_HISTORY 10
#define BUFFER_SIZE 100

char *history[MAX_HISTORY];
int history_count = 0;
int history_pos = -1;

void disable_raw_mode(struct termios *old)
{
    tcsetattr(STDIN_FILENO, TCSAFLUSH, old);
}

void enable_raw_mode(struct termios *old)
{
    struct termios raw;

    tcgetattr(STDIN_FILENO, old);
    raw = *old;

    raw.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

void add_history(const char *command)
{
    if (strlen(command) == 0)
        return;

    if (history_count == MAX_HISTORY)
    {
        free(history[0]);

        for (int i = 1; i < MAX_HISTORY; i++)
            history[i - 1] = history[i];

        history_count--;
    }

    history[history_count] = malloc(strlen(command) + 1);

    if (history[history_count] == NULL)
    {
        perror("malloc");
        exit(1);
    }

    strcpy(history[history_count], command);
    history_count++;
}

void clear_line()
{
    printf("\r\033[K");
    fflush(stdout);
}

void display_history()
{
    printf("\n\nCommand History:\n");

    for (int i = 0; i < history_count; i++)
        printf("%d: %s\n", i + 1, history[i]);
}

void free_history()
{
    for (int i = 0; i < history_count; i++)
        free(history[i]);
}

int main()
{
    struct termios old;
    char buffer[BUFFER_SIZE];
    int length = 0;

    enable_raw_mode(&old);

    printf("Command History Demo\n");
    printf("Type commands and press Enter.\n");
    printf("Use UP/DOWN arrows to recall commands.\n");
    printf("Type 'history' to display history.\n");
    printf("Type 'exit' to quit.\n\n");

    while (1)
    {
        printf("> ");
        fflush(stdout);

        length = 0;
        buffer[0] = '\0';
        history_pos = history_count;

        while (1)
        {
            char c;

            if (read(STDIN_FILENO, &c, 1) != 1)
                continue;

            /* Enter */
            if (c == '\n' || c == '\r')
            {
                buffer[length] = '\0';
                printf("\n");

                if (strcmp(buffer, "exit") == 0)
                {
                    disable_raw_mode(&old);
                    free_history();
                    printf("Exiting...\n");
                    return 0;
                }

                if (strcmp(buffer, "history") == 0)
                {
                    display_history();
                }
                else
                {
                    add_history(buffer);
                    printf("Command stored: %s\n", buffer);
                }

                break;
            }

            /* Backspace */
            else if (c == 127 || c == 8)
            {
                if (length > 0)
                {
                    length--;
                    buffer[length] = '\0';

                    printf("\b \b");
                    fflush(stdout);
                }
            }

            /* Escape sequence */
            else if (c == 27)
            {
                char seq[2];

                if (read(STDIN_FILENO, &seq[0], 1) != 1)
                    continue;

                if (read(STDIN_FILENO, &seq[1], 1) != 1)
                    continue;

                /* UP arrow: ESC [ A */
                if (seq[0] == '[' && seq[1] == 'A')
                {
                    if (history_count > 0 && history_pos > 0)
                    {
                        history_pos--;

                        strcpy(buffer, history[history_pos]);
                        length = strlen(buffer);

                        clear_line();
                        printf("> %s", buffer);
                        fflush(stdout);
                    }
                }

                /* DOWN arrow: ESC [ B */
                else if (seq[0] == '[' && seq[1] == 'B')
                {
                    if (history_pos < history_count - 1)
                    {
                        history_pos++;

                        strcpy(buffer, history[history_pos]);
                        length = strlen(buffer);

                        clear_line();
                        printf("> %s", buffer);
                        fflush(stdout);
                    }
                    else
                    {
                        history_pos = history_count;
                        buffer[0] = '\0';
                        length = 0;

                        clear_line();
                        printf("> ");
                        fflush(stdout);
                    }
                }
            }

            /* Normal character */
            else if (c >= 32 && c <= 126)
            {
                if (length < BUFFER_SIZE - 1)
                {
                    buffer[length++] = c;
                    buffer[length] = '\0';

                    putchar(c);
                    fflush(stdout);
                }
            }
        }
    }

    disable_raw_mode(&old);
    free_history();

    return 0;
}
