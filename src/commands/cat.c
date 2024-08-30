#include "commands.h"

void cat_command(int argc, char *argv[]) {
    if (argc == 0) {
        fprintf(stderr, "Usage: cat <file1> [file2 ...]\n");
        return;
    }

    for (int i = 0; i < argc; i++) {
        FILE *file = fopen(argv[i], "r");
        if (file == NULL) {
            perror(argv[i]);
            continue;
        }

        char ch;
        while ((ch = fgetc(file)) != EOF) {
            putchar(ch);
        }
        fclose(file);

        // Print a newline after each file's content if it's not the last file
        if (i < argc - 1) {
            printf("\n");
        }
    }

    // Ensure that we move to a new line after all files are processed
    printf("\n");
}