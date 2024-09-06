#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

void pwd_command();
void clear_command();
void ls_command();
void mkdir_command(char *dir_name);
void rmdir_command(char *dir_name);
void cd_command(const char *path);
void rm_command(int argc, char *argv[]);
void touch_command(const char *filename);
void man_command(const char *command);
void cat_command(int argc, char *argv[]);
void echo_command(int argc, char *argv[]);
void grep_command(int argc, char *argv[]);
void cp_command(int argc, char *argv[]);
void mv_command(int argc, char *argv[]);
void chmod_command(int argc, char *argv[]);
void date_command(void);
void execute_commands(char *command);