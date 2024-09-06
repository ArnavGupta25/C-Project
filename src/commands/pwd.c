#include "commands.h"

void pwd_command()
{
    // Buffer to hold the current working directory path
    char cwd[1024];
    // Get the current working directory
    if (getcwd(cwd, sizeof(cwd)) != NULL)
    {
        printf("%s\n", cwd);
    }
    else
    {
        perror("getcwd() error");
    }
}
