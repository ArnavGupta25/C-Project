#include "commands.h"

void ls_command()
{
    struct dirent *de;

    DIR *dr = opendir(".");

    if (dr == NULL)
    {
        perror("Could not open current directory");
        return;
    }

    while ((de = readdir(dr)) != NULL)
    {
        printf("%s\n", de->d_name);
    }

    closedir(dr);
}
