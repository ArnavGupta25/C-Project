#include "commands.h"

// Function to convert symbolic permission string to mode_t (used for chmod)
mode_t symbolic_to_mode(const char *symbolic, mode_t current_mode)
{
    mode_t mode = current_mode;
    const char *ptr = symbolic;

    while (*ptr) {
        // Determine which users we're changing
        mode_t who_mask = 0;
        while (*ptr && *ptr != '+' && *ptr != '-' && *ptr != '=') {
            switch (*ptr) {
                case 'u': who_mask |= S_IRWXU; break;
                case 'g': who_mask |= S_IRWXG; break;
                case 'o': who_mask |= S_IRWXO; break;
                case 'a': who_mask |= S_IRWXU | S_IRWXG | S_IRWXO; break;
            }
            ptr++;
        }

        if (who_mask == 0) {
            who_mask = S_IRWXU | S_IRWXG | S_IRWXO;  // Default to all if not specified
        }

        // Determine the operation
        char op = *ptr++;
        
        // Apply the changes
        mode_t change_mask = 0;
        while (*ptr && *ptr != ',') {
            switch (*ptr) {
                case 'r':
                    change_mask |= (S_IRUSR | S_IRGRP | S_IROTH) & who_mask;
                    break;
                case 'w':
                    change_mask |= (S_IWUSR | S_IWGRP | S_IWOTH) & who_mask;
                    break;
                case 'x':
                    change_mask |= (S_IXUSR | S_IXGRP | S_IXOTH) & who_mask;
                    break;
            }
            ptr++;
        }

        switch (op) {
            case '+': mode |= change_mask; break;
            case '-': mode &= ~change_mask; break;
            case '=': 
                mode &= ~who_mask;  // Clear all bits for specified users
                mode |= change_mask; // Set the specified bits
                break;
        }

        // Move to the next change group if there is one
        if (*ptr == ',') ptr++;
    }

    return mode;
}

void chmod_command(int argc, char *argv[])
{
    // Ensure at least two arguments are passed (permissions and at least one file)
    if (argc < 2)
    {
        fprintf(stderr, "Usage: chmod <permissions> <file1> [file2 ...]\n");
        return;
    }

    for (int i = 1; i < argc; i++)
    {
        struct stat file_stat;
        if (stat(argv[i], &file_stat) != 0)
        {
            perror("stat");
            continue;
        }

        mode_t new_mode;
        if (argv[0][0] >= '0' && argv[0][0] <= '9')
        {
            // Octal permissions
            new_mode = strtol(argv[0], NULL, 8);
        }
        else
        {
            // Symbolic permissions
            new_mode = symbolic_to_mode(argv[0], file_stat.st_mode);
        }

        // Apply the new permissions
        if (chmod(argv[i], new_mode) != 0)
        {
            perror("chmod");
        }
        else
        {
            printf("Permissions changed for %s\n", argv[i]);
        }
    }
}
