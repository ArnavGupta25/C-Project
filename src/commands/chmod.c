#include "commands.h"

// Function to convert symbolic permission string to mode_t (used for chmod)
mode_t symbolic_to_mode(const char *symbolic, mode_t current_mode)
{
    mode_t mode = current_mode;

    // Initialize masks for removals and additions
    mode_t remove_mask = 0;
    mode_t add_mask = 0;

    // Handle removals ('-')
    if (strstr(symbolic, "u-"))
    {
        if (strchr(symbolic, 'r'))
            remove_mask |= S_IRUSR; // Mask for read removal
        if (strchr(symbolic, 'w'))
            remove_mask |= S_IWUSR; // Mask for write removal
        if (strchr(symbolic, 'x'))
            remove_mask |= S_IXUSR; // Mask for execute removal
    }

    if (strstr(symbolic, "g-"))
    {
        if (strchr(symbolic, 'r'))
            remove_mask |= S_IRGRP; // Mask for read removal
        if (strchr(symbolic, 'w'))
            remove_mask |= S_IWGRP; // Mask for write removal
        if (strchr(symbolic, 'x'))
            remove_mask |= S_IXGRP; // Mask for execute removal
    }

    if (strstr(symbolic, "o-"))
    {
        if (strchr(symbolic, 'r'))
            remove_mask |= S_IROTH; // Mask for read removal
        if (strchr(symbolic, 'w'))
            remove_mask |= S_IWOTH; // Mask for write removal
        if (strchr(symbolic, 'x'))
            remove_mask |= S_IXOTH; // Mask for execute removal
    }

    // Apply removals
    mode &= ~remove_mask;

    // Handle additions ('+')
    if (strstr(symbolic, "u+"))
    {
        if (strchr(symbolic, 'r'))
            add_mask |= S_IRUSR; // Mask for read addition
        if (strchr(symbolic, 'w'))
            add_mask |= S_IWUSR; // Mask for write addition
        if (strchr(symbolic, 'x'))
            add_mask |= S_IXUSR; // Mask for execute addition
    }

    if (strstr(symbolic, "g+"))
    {
        if (strchr(symbolic, 'r'))
            add_mask |= S_IRGRP; // Mask for read addition
        if (strchr(symbolic, 'w'))
            add_mask |= S_IWGRP; // Mask for write addition
        if (strchr(symbolic, 'x'))
            add_mask |= S_IXGRP; // Mask for execute addition
    }

    if (strstr(symbolic, "o+"))
    {
        if (strchr(symbolic, 'r'))
            add_mask |= S_IROTH; // Mask for read addition
        if (strchr(symbolic, 'w'))
            add_mask |= S_IWOTH; // Mask for write addition
        if (strchr(symbolic, 'x'))
            add_mask |= S_IXOTH; // Mask for execute addition
    }

    // Apply additions
    mode |= add_mask;

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
