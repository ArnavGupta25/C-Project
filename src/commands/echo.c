#include "commands.h"

void echo_command(int argc, char *argv[])
{
    if (argc == 0)
    {
        printf("\n");
        return;
    }

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