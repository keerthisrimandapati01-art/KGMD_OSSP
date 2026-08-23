#include <stdio.h>
#include <string.h>

int main() {
    char *name = "Keerthi";

    char single_quoted[] = "'Hello $name'";

    printf("=== SINGLE QUOTES ===\n");
    printf("Input  : 'Hello $name'\n");
    printf("Output : %s\n", single_quoted);
    printf("Result : Variable is NOT expanded.\n\n");

    printf("=== DOUBLE QUOTES FOR COMPARISON ===\n");
    printf("Input  : \"Hello %s\"\n", name);
    printf("Output : Hello %s\n", name);
    printf("Result : Variable value can be inserted.\n\n");

    printf("=== EDGE CASE ===\n");
    char spaces[] = "'Hello World from Linux'";
    printf("Quoted string with spaces: %s\n", spaces);

    return 0;
}
