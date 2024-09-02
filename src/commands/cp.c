#include "commands.h"

void cp_command(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: cp <source_file> <destination_file>\n");
        return;
    }

    FILE *source = fopen(argv[0], "r");
    if (source == NULL) {
        perror(argv[0]);
        return;
    }

    FILE *destination = fopen(argv[1], "w");
    if (destination == NULL) {
        perror(argv[1]);
        fclose(source);
        return;
    }

    char buffer[1024];
    size_t bytes;

    while ((bytes = fread(buffer, 1, sizeof(buffer), source)) > 0) {
        fwrite(buffer, 1, bytes, destination);
    }

    fclose(source);
    fclose(destination);

    printf("Copied %s to %s\n", argv[0], argv[1]);
}
