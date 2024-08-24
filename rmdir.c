#include "commands.h"

void rmdir_command(char *dir_name)
{
    if (dir_name == NULL)
    {
        printf("Error: No directory name provided.\n");
        return;
    }
    if (rmdir(dir_name) == -1)
    {
        perror("rmdir error");
    }
    else
    {
        printf("Directory '%s' removed successfully.\n", dir_name);
    }
}