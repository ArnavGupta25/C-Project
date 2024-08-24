#include "commands.h"

void execute_commands(char *command)
{
    char *cmd = strtok(command, " ");
    char *arg = strtok(NULL, " ");

    if (strcmp(command, "pwd") == 0)
    {
        pwd_command();
    }
    else if (strcmp(command, "clear") == 0)
    {
        clear_command();
    }
    else if (strcmp(command, "ls") == 0)
    {
        ls_command();
    }
    else if (strcmp(cmd, "mkdir") == 0)
    {
        mkdir_command(arg);
    }
    else if (strcmp(cmd, "rmdir") == 0)
    {
        rmdir_command(arg);
    }
    else
    {
        printf("Command not recognized.\n");
    }
}