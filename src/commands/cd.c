#include "commands.h"

void cd_command(const char *path)
{
    // Check if the path is NULL or an empty string
    if (path == NULL || strcmp(path, "") == 0)
    {
        fprintf(stderr, "cd: missing directory name\n");
        return;
    }

    if (chdir(path) != 0)
    {
        perror("cd");
        return;
    }

    char *cwd = (char *)malloc(1024 * sizeof(char)); // Allocate 1024 bytes

    if (cwd == NULL) // Check if malloc succeeded
    {
        perror("malloc failed");
        return;
    }

    // Get the current working directory and check for errors
    if (getcwd(cwd, 1024) != NULL)
    {
        if (strcmp(path, "..") == 0)
        {
            printf("Changed directory to parent: %s\n", cwd);
        }
        else
        {
            printf("Changed directory to: %s\n", cwd);
        }
    }
    else
    {
        perror("getcwd() error");
    }

    free(cwd);
}