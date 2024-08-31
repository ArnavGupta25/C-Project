#include "commands.h"

void grep_command(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Usage: grep <pattern> <file1> [file2 ...]\n");
        return;
    }

    char *pattern = argv[0];

    for (int i = 1; i < argc; i++)
    {
        FILE *file = fopen(argv[i], "r");
        if (file == NULL)
        {
            perror(argv[i]);
            continue;
        }

        char line[1024];
        int found = 0;

        while (fgets(line, sizeof(line), file))
        {
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