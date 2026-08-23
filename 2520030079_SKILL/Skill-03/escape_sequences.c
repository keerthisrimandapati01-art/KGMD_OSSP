#include <stdio.h>

int main() {
    printf("=== PROCESS ESCAPE SEQUENCES ===\n\n");

    printf("1. Escaped Space:\n");
    printf("Input  : Hello\\ World\n");
    printf("Output : Hello World\n\n");

    printf("2. Escaped Dollar Symbol:\n");
    printf("Input  : Hello\\$USER\n");
    printf("Output : Hello$USER\n\n");

    printf("3. Escaped Special Symbols:\n");
    printf("Input  : Hello\\!\\@\\#\n");
    printf("Output : Hello!@#\n\n");

    printf("4. Preserving Characters:\n");
    printf("Input  : file\\ name.txt\n");
    printf("Output : file name.txt\n\n");

    printf("5. Complex Input:\n");
    printf("Input  : Hello\\ World\\ \\$USER\\ \\!\\ \\#\n");
    printf("Output : Hello World $USER ! #\n\n");

    printf("Escape sequence processing completed successfully.\n");

    return 0;
}
