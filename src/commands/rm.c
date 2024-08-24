#include "commands.h"

void rm_command(const char *filename)
{
    if (filename == NULL || strcmp(filename, "") == 0)
    {
        fprintf(stderr, "rm: missing file name\n");
        return;
    }

    if (remove(filename) != 0)
    {
        perror("rm");
    }
    else
    {
        printf("Removed file: %s\n", filename);
    }
}