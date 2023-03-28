#include <unistd.h>

int _puts(char *str) {
    int len = 0;
    while (*str != '\0') {
        if (write(STDOUT_FILENO, str, 1) == -1) {
            return -1;
        }
        str++;
        len++;
    }
    if (write(STDOUT_FILENO, "\n", 1) == -1) {
        return -1;
    }
    return len;
}
