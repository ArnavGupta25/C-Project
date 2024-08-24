#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

void pwd_command();
void clear_command();
void ls_command();
void mkdir_command(char *dir_name);
void rmdir_command(char *dir_name);
void execute_commands(char *command);