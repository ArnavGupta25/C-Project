#include "commands.h"

mode_t symbolic_to_mode(const char *symbolic) {
    mode_t mode = 0;

    // User permissions
    if (strchr(symbolic, 'r')) mode |= S_IRUSR;
    if (strchr(symbolic, 'w')) mode |= S_IWUSR;
    if (strchr(symbolic, 'x')) mode |= S_IXUSR;

    // Group permissions
    if (strchr(symbolic, 'r') && strchr(symbolic, 'g')) mode |= S_IRGRP;
    if (strchr(symbolic, 'w') && strchr(symbolic, 'g')) mode |= S_IWGRP;
    if (strchr(symbolic, 'x') && strchr(symbolic, 'g')) mode |= S_IXGRP;

    // Others permissions
    if (strchr(symbolic, 'r') && strchr(symbolic, 'o')) mode |= S_IROTH;
    if (strchr(symbolic, 'w') && strchr(symbolic, 'o')) mode |= S_IWOTH;
    if (strchr(symbolic, 'x') && strchr(symbolic, 'o')) mode |= S_IXOTH;

    return mode;
}

void chmod_command(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: chmod <permissions> <file1> [file2 ...]\n");
        return;
    }

    mode_t mode;
    if (argv[0][0] >= '0' && argv[0][0] <= '9') {
        mode = strtol(argv[0], NULL, 8); 
    } else {
        mode = symbolic_to_mode(argv[0]);
    }

    for (int i = 1; i < argc; i++) {
        if (chmod(argv[i], mode) != 0) {
            perror("chmod");
        } else {
            printf("Permissions changed for %s\n", argv[i]);
        }
    }
}
