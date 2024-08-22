#include "commands.h"

void clear_command() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}