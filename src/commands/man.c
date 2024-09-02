#include "commands.h"

void man_command(const char *command)
{
    if (command == NULL || strcmp(command, "") == 0)
    {
        // Print the list of available commands
        printf("Available commands:\n");
        printf("  pwd    - Prints the current working directory\n");
        printf("  ls     - Lists the files and directories in the current directory\n");
        printf("  clear  - Clears the terminal screen.\n");
        printf("  mkdir  - Creates a new directory\n");
        printf("  rmdir  - Removes an empty directory\n");
        printf("  cd     - Changes the current directory\n");
        printf("  rm     - Removes one or more files.\n");
        printf("  touch  - Creates a new file or updates the timestamp of an existing file\n");
        printf("  man    - Displays help information for commands\n");
        printf("  cat    - Displays the contents of one or more files.\n");
        printf("  echo   - Displays a line of text\n");
        printf("  grep   - Searches for a pattern in files\n");
        printf("  cp     - Copies a file from source to destination.\n");
        printf("  mv     - Moves or renames a file.\n");
        printf("  exit   - Exits the shell\n");
    }
    else if (strcmp(command, "pwd") == 0)
    {
        printf("pwd: Prints the current working directory.\n");
        printf("Usage: pwd\n");
    }
    else if (strcmp(command, "ls") == 0)
    {
        printf("ls: Lists the files and directories in the current directory.\n");
        printf("Usage: ls [OPTION]\n");
        printf("Options:\n");
        printf("  -l    List in long format\n");
        printf("  -a    List all entries including those starting with a dot (hidden files)\n");
        printf("  -la   List in long format including all entries\n");
    }
    else if (strcmp(command, "clear") == 0)
    {
        printf("clear: Clears the terminal screen.\n");
        printf("Usage: clear\n");
    }
    else if (strcmp(command, "mkdir") == 0)
    {
        printf("mkdir: Creates a new directory.\n");
        printf("Usage: mkdir DIRECTORY_NAME\n");
    }
    else if (strcmp(command, "rmdir") == 0)
    {
        printf("rmdir: Removes an empty directory.\n");
        printf("Usage: rmdir DIRECTORY_NAME\n");
    }
    else if (strcmp(command, "cd") == 0)
    {
        printf("cd: Changes the current directory.\n");
        printf("Usage: cd DIRECTORY_NAME\n");
    }
    else if (strcmp(command, "rm") == 0)
    {
        printf("rm: Removes one or more files.\n");
        printf("Usage: rm FILE_NAME [FILE_NAME ...]\n");
    }

    else if (strcmp(command, "touch") == 0)
    {
        printf("touch: Creates a new file or updates the timestamp of an existing file.\n");
        printf("Usage: touch FILE_NAME\n");
    }
    else if (strcmp(command, "man") == 0)
    {
        printf("man: Displays help information for commands.\n");
        printf("Usage: man [COMMAND]\n");
        printf("If no command is specified, it displays a list of available commands.\n");
    }
    else if (strcmp(command, "cat") == 0)
    {
        printf("Concatenates and displays the contents of the specified files.\n");
        printf("Usage: cat <file1> [file2 ...]\n");
    }
    else if (strcmp(command, "echo") == 0)
    {
        printf("echo: Displays a line of text.\n");
        printf("Usage: echo [STRING...]\n");
    }
    else if (strcmp(command, "grep") == 0)
    {
        printf("grep: Searches for a pattern in files.\n");
        printf("Usage: grep PATTERN <file1> [file2 ...]\n");
    }
    else if (strcmp(command, "cp") == 0)
    {
        printf("cp: Copies a file from source to destination.\n");
        printf("Usage: cp <source_file> <destination_file>\n");
    }
    else if (strcmp(command, "mv") == 0)
    {
        printf("mv: Moves or renames a file.\n");
        printf("Usage: mv <source_file> <destination_file>\n");
    }
    else
    {
        printf("No manual entry for %s\n", command);
    }
}