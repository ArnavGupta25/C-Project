#include "commands.h"

void rm_command(int argc, char *argv[])
{
    // Check if no arguments are provided
    if (argc == 0)
    {
        fprintf(stderr, "Usage: rm <file1> [file2 ...]\n");
        return;
    }

    // Iterate over each file name provided as an argument
    for (int i = 0; i < argc; i++)
    {   
        // Check if the file name is NULL or an empty string
        if (argv[i] == NULL || strcmp(argv[i], "") == 0)
        {
            fprintf(stderr, "rm: missing file name\n");
            continue;
        }

        // Attempt to remove the file
        if (remove(argv[i]) != 0)
        {   
            // Print an error message if the file removal fails
            perror("rm");
        }
        else
        {
            printf("Removed file: %s\n", argv[i]);
        }
    }
}
