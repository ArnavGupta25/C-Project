#include "commands.h"

void mkdir_command(char *dir_name)
{
    if (dir_name == NULL)
    {
        printf("Error: No directory name provided.\n");
        return;
    }
    if (mkdir(dir_name, 0755) == -1)
    {
        perror("mkdir error");
    }
    else
    {
        printf("Directory '%s' created successfully.\n", dir_name);
    }
}