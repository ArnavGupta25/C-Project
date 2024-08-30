#include "commands.h"

void man_command(const char *command)
{
    if (command == NULL || strcmp(command, "") == 0)
    {
        printf("Usage: man [command]\n");
        printf("Available commands:\n");
        printf("  pwd    - Print the current working directory.\n");
        printf("  clear  - Clear the terminal screen.\n");
        printf("  ls     - List files and directories in the current directory.\n");
        printf("  mkdir  - Create a new directory.\n");
        printf("  rmdir  - Remove an empty directory.\n");
        printf("  cd     - Change the current directory.\n");
        printf("  rm     - Remove a file.\n");
        printf("  touch  - Create a new file or update the timestamp of an existing file.\n");
        printf("  man    - Display the manual page for a command.\n");
        return;
    }

    if (strcmp(command, "pwd") == 0)
    {
        printf("pwd - Print the current working directory.\n");
    }
    else if (strcmp(command, "clear") == 0)
    {
        printf("clear - Clear the terminal screen.\n");
    }
    else if (strcmp(command, "ls") == 0)
    {
        printf("ls - List files and directories in the current directory.\n");
    }
    else if (strcmp(command, "mkdir") == 0)
    {
        printf("mkdir - Create a new directory.\n");
    }
    else if (strcmp(command, "rmdir") == 0)
    {
        printf("rmdir - Remove an empty directory.\n");
    }
    else if (strcmp(command, "cd") == 0)
    {
        printf("cd - Change the current directory.\n");
    }
    else if (strcmp(command, "rm") == 0)
    {
        printf("rm - Remove a file.\n");
    }
    else if (strcmp(command, "touch") == 0)
    {
        printf("touch - Create a new file or update the timestamp of an existing file.\n");
    }
    else
    {
        printf("No manual entry for %s\n", command);
    }
}
