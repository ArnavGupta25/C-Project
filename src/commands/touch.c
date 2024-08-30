#include "commands.h"

void touch_command(const char *filename)
{
    if (filename == NULL || strcmp(filename, "") == 0)
    {
        fprintf(stderr, "touch: missing file name\n");
        return;
    }

    int fd = open(filename, O_CREAT | O_WRONLY, 0644);
    if (fd < 0)
    {
        perror("touch");
        return;
    }

    if (close(fd) < 0)
    {
        perror("touch");
    }
    else
    {
        printf("Touched file: %s\n", filename);
    }
}