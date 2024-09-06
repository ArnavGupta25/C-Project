#include "commands.h"

void date_command(void) {
    time_t t;
    struct tm *tm_info;

    // Get the current time
    time(&t);
    tm_info = localtime(&t);

    // Print the formatted date and time
    printf("Current date and time: %s", asctime(tm_info));
}
