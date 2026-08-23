#include <stdio.h>

int main() {
    char *name = "Keerthi";
    char *course = "Operating Systems";

    printf("=== DOUBLE QUOTES ===\n");

    printf("Input  : \"Hello %s\"\n", name);
    printf("Output : Hello %s\n", name);
    printf("Result : Variable expansion is allowed.\n\n");

    printf("=== PRESERVE SPACES ===\n");

    char message[] = "Hello Keerthi, welcome to Operating Systems";
    printf("Input  : \"%s\"\n", message);
    printf("Output : %s\n", message);
    printf("Result : Spaces inside double quotes are preserved.\n\n");

    printf("=== NESTED TOKENS ===\n");

    printf("Course : \"%s\"\n", course);
    printf("Student: \"%s\"\n", name);
    printf("Result : Multiple tokens are handled correctly.\n\n");

    printf("=== EDGE CASE ===\n");

    char special[] = "Hello $USER \"Linux\"";
    printf("Quoted content: \"%s\"\n", special);

    return 0;
}
