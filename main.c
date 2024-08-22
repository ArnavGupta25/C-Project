#include "commands.h"

int main() {
    char input[1024];

    while (1) {
        printf("Commands> ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            perror("fgets error");
            continue;
        }

        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "exit") == 0) {
            break;
        }

        execute_commands(input);
    }

    printf("Connection Terminated\n");
    return 0;
}