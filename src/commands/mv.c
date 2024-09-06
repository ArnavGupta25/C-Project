#include "commands.h"

void mv_command(int argc, char *argv[])
{
    // Check if there are enough arguments
    if (argc < 2)
    {
        printf("Usage: mv <source_file> <destination_file>\n");
        return;
    }
    // Try to open the destination file in read mode
    FILE *destFile = fopen(argv[1], "r");
    if (destFile == NULL)
    {
        // If the destination file does not exist, try to create it
        destFile = fopen(argv[1], "w");
        if (destFile == NULL)
        {
            printf("Failed to create destination file: %s\n", argv[1]);
            return;
        }
        fclose(destFile);
    }
    else
    {
        // Close the destination file if it already exists
        fclose(destFile);
    }

    // Rename (or move) the source file to the destination file
    if (rename(argv[0], argv[1]) == 0)
    {
        printf("Moved/Renamed %s to %s\n", argv[0], argv[1]);
    }
}
