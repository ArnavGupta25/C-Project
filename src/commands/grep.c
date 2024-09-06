#include "commands.h"

void grep_command(int argc, char *argv[])
{
    // Check if the number of arguments is less than 2
    if (argc < 2)
    {
        fprintf(stderr, "Usage: grep <pattern> <file1> [file2 ...]\n");
        return;
    }

    // The first argument is the search pattern
    char *pattern = argv[0];

    // Iterate over each file provided as argument
    for (int i = 1; i < argc; i++)
    {
        // Open the current file in read mode
        FILE *file = fopen(argv[i], "r");
        if (file == NULL)
        {
            perror(argv[i]);
            continue;
        }

        // Buffer to read each line from the file
        char line[1024];
        int found = 0;

        while (fgets(line, sizeof(line), file))
        {
            // Check if the line contains the pattern
            if (strstr(line, pattern))
            {
                if (!found)
                {
                    printf("File: %s\n", argv[i]);
                    found = 1;
                }
                printf("%s", line);
            }
        }

        fclose(file);

        printf("\n");
    }
}