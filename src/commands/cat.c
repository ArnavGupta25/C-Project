#include "commands.h"


void cat_command(int argc, char *argv[]) {

    // Check if no files are passed as arguments
    if (argc == 0) {
        fprintf(stderr, "Usage: cat <file1> [file2 ...]\n");
        return;
    }

    // Loop through each file provided in the argument list
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

        if (i < argc - 1) {
            printf("\n");
        }
    }

    printf("\n");
}