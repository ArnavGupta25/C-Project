#include "commands.h"

void execute_commands(char *command)
{
    char *cmd = strtok(command, " ");
    char *arg = strtok(NULL, " ");

    char *args[100];
    int argc = 0;
    while (arg != NULL)
    {
        args[argc++] = arg;
        arg = strtok(NULL, " ");
    }

    // Ensure args array is null-terminated
    args[argc] = NULL;

    if (strcmp(cmd, "pwd") == 0)
    {
        pwd_command();
    }
    else if (strcmp(cmd, "clear") == 0)
    {
        clear_command();
    }
    else if (strcmp(cmd, "ls") == 0)
    {
        ls_command(argc > 0 ? args[0] : NULL);
    }
    else if (strcmp(cmd, "mkdir") == 0)
    {
        mkdir_command(argc > 0 ? args[0] : NULL);
    }
    else if (strcmp(cmd, "rmdir") == 0)
    {
        rmdir_command(argc > 0 ? args[0] : NULL);
    }
    else if (strcmp(cmd, "cd") == 0)
    {
        cd_command(argc > 0 ? args[0] : NULL);
    }
    else if (strcmp(cmd, "rm") == 0)
    {
        rm_command(argc, args);
    }

    else if (strcmp(cmd, "touch") == 0)
    {
        touch_command(argc > 0 ? args[0] : NULL);
    }
    else if (strcmp(cmd, "man") == 0)
    {
        man_command(argc > 0 ? args[0] : NULL);
    }
    else if (strcmp(cmd, "cat") == 0)
    {
        cat_command(argc, args);
    }
    else if (strcmp(cmd, "echo") == 0)
    {
        echo_command(argc, args);
    }
    else if (strcmp(cmd, "grep") == 0)
    {
        grep_command(argc, args);
    }
    else
    {
        printf("Command not recognized.\n");
    }
}
