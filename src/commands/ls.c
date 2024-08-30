#include "commands.h"

void print_file_info(const char *name)
{
    struct stat fileStat;
    if (stat(name, &fileStat) < 0)
    {
        perror("stat");
        return;
    }

    // Print file type and permissions
    printf((S_ISDIR(fileStat.st_mode)) ? "d" : "-");
    printf((fileStat.st_mode & S_IRUSR) ? "r" : "-");
    printf((fileStat.st_mode & S_IWUSR) ? "w" : "-");
    printf((fileStat.st_mode & S_IXUSR) ? "x" : "-");
    printf((fileStat.st_mode & S_IRGRP) ? "r" : "-");
    printf((fileStat.st_mode & S_IWGRP) ? "w" : "-");
    printf((fileStat.st_mode & S_IXGRP) ? "x" : "-");
    printf((fileStat.st_mode & S_IROTH) ? "r" : "-");
    printf((fileStat.st_mode & S_IWOTH) ? "w" : "-");
    printf((fileStat.st_mode & S_IXOTH) ? "x" : "-");

    // Print number of links
    printf(" %lu", fileStat.st_nlink);

    // Print owner and group
    printf(" %s %s", getpwuid(fileStat.st_uid)->pw_name, getgrgid(fileStat.st_gid)->gr_name);

    // Print file size
    printf(" %5ld", fileStat.st_size);

    // Print modified time
    char timeBuf[80];
    strftime(timeBuf, sizeof(timeBuf), "%b %d %H:%M", localtime(&fileStat.st_mtime));
    printf(" %s", timeBuf);

    // Print file name
    printf(" %s\n", name);
}

void ls_command(const char *option)
{
    DIR *d;
    struct dirent *dir;
    d = opendir(".");
    if (d == NULL)
    {
        perror("opendir");
        return;
    }

    int show_all = 0;
    int long_format = 0;

    if (option != NULL)
    {
        if (strcmp(option, "-a") == 0)
        {
            show_all = 1;
        }
        else if (strcmp(option, "-l") == 0)
        {
            long_format = 1;
        }
        else if (strcmp(option, "-la") == 0 || strcmp(option, "-al") == 0)
        {
            show_all = 1;
            long_format = 1;
        }
        else
        {
            printf("Unknown option: %s\n", option);
            closedir(d);
            return;
        }
    }

    while ((dir = readdir(d)) != NULL)
    {
        if (!show_all && dir->d_name[0] == '.')
        {
            continue;
        }

        if (long_format)
        {
            print_file_info(dir->d_name);
        }
        else
        {
            printf("%s  ", dir->d_name);
        }
    }
    if (!long_format)
    {
        printf("\n");
    }

    closedir(d);
}