#include "commands.h"

void rm_command(int argc, char *argv[])
{
    if (argc == 0)
    {
        fprintf(stderr, "Usage: rm <file1> [file2 ...]\n");
        return;
    }

    for (int i = 0; i < argc; i++)
    {
        if (argv[i] == NULL || strcmp(argv[i], "") == 0)
        {
            fprintf(stderr, "rm: missing file name\n");
            continue;
        }

        if (remove(argv[i]) != 0)
        {
            perror("rm");
        }
        else
        {
            printf("Removed file: %s\n", argv[i]);
        }
    }
}
