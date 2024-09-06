#include "commands.h"

void mkdir_command(char *dir_name)
{
    // Check if the directory name is NULL
    if (dir_name == NULL)
    {
        printf("Error: No directory name provided.\n");
        return;
    }
    // Attempt to create the directory with permissions set to 0755
    if (mkdir(dir_name, 0755) == -1)
    {
        perror("mkdir error");
    }
    else
    {
        // Print a success message if the directory is created successfully
        printf("Directory '%s' created successfully.\n", dir_name);
    }
}