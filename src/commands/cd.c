#include "commands.h"

void cd_command(const char *path)
{
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

    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL)
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
}