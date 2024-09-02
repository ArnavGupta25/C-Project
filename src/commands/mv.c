#include "commands.h"

void mv_command(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: mv <source_file> <destination_file>\n");
        return;
    }

    FILE *destFile = fopen(argv[1], "r");
    if (destFile == NULL) {
        destFile = fopen(argv[1], "w");
        if (destFile == NULL) {
            printf("Failed to create destination file: %s\n", argv[1]);
            return;
        }
        fclose(destFile);
    } else {
        fclose(destFile);
    }
    
    if (rename(argv[0], argv[1]) == 0) {
        printf("Moved/Renamed %s to %s\n", argv[0], argv[1]);
    }
}
