#include "commands.h"

void touch_command(const char *filename)
{
    // Check if the filename is NULL or an empty string
    if (filename == NULL || strcmp(filename, "") == 0)
    {
        fprintf(stderr, "touch: missing file name\n");
        return;
    }

    // Attempt to open the file with O_CREAT flag to create it if it does not exist
    // O_WRONLY flag to open it in write-only mode, with permissions set to 0644
    int fd = open(filename, O_CREAT | O_WRONLY, 0644);
    if (fd < 0)
    {
        perror("touch");
        return;
    }

    // Close the file descriptor after creation or update
    if (close(fd) < 0)
    {
        perror("touch");
    }
    else
    {
        printf("Touched file: %s\n", filename);
    }
}