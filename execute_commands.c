#include "commands.h"

void execute_commands(char *command)
{
    if (strcmp(command, "pwd") == 0)
    {
        pwd_command();
    }
    else if (strcmp(command, "clear") == 0)
    {
        clear_command();
    }
    else
    {
        printf("Command not recognized.\n");
    }
}