#include "commands.h"

void echo_command(int argc, char *argv[])
{
    // If no arguments are provided, print a new line
    if (argc == 0)
    {
        printf("\n");
        return;
    }

    // Loop through each argument and print it
    for (int i = 0; i < argc; i++)
    {
        printf("%s", argv[i]);
        if (i < argc - 1)
        {
            printf(" ");
        }
    }

    printf("\n");
}