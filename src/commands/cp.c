#include "commands.h"

void cp_command(int argc, char *argv[]) {
    // Check if the number of arguments is less than 2
    if (argc < 2) {
        fprintf(stderr, "Usage: cp <source_file> <destination_file>\n");
        return;
    }

    // Open the source file in read mode
    FILE *source = fopen(argv[0], "r");
    if (source == NULL) {
        // Print an error message if the source file cannot be opened
        perror(argv[0]);
        return;
    }

    // Open the destination file in write mode
    FILE *destination = fopen(argv[1], "w");
    if (destination == NULL) {
        // Print an error message if the destination file cannot be opened
        perror(argv[1]);
        // Close the source file before returning
        fclose(source);
        return;
    }

    // Buffer to hold data while copying
    char buffer[1024];
    size_t bytes;

    // Read data from the source file and write it to the destination file
    while ((bytes = fread(buffer, 1, sizeof(buffer), source)) > 0) {
        fwrite(buffer, 1, bytes, destination);
    }

    // Close both files
    fclose(source);
    fclose(destination);

    printf("Copied %s to %s\n", argv[0], argv[1]);
}
