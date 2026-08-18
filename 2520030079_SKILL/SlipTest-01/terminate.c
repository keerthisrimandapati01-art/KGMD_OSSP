#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    printf("Process started.\n");
    printf("Process PID = %d\n", getpid());

    printf("Process is going to terminate...\n");

    exit(0);

    printf("This statement will not execute.\n");

    return 0;
}
