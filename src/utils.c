#include "utils.h"

#include <stdio.h>
#include <string.h>

void clearInputLine(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        /* discard */
    }
}

void readLine(char *buf, size_t size) {
    if (fgets(buf, (int)size, stdin) == NULL) {
        if (size > 0) buf[0] = '\0';
        return;
    }

    size_t len = strlen(buf);
    if (len > 0 && buf[len - 1] == '\n') {
        buf[len - 1] = '\0';
    }
}

int readInt(const char *prompt, int *out) {
    printf("%s", prompt);
    if (scanf("%d", out) != 1) {
        clearInputLine();
        return 0;
    }
    clearInputLine();
    return 1;
}

int readFloat(const char *prompt, float *out) {
    printf("%s", prompt);
    if (scanf("%f", out) != 1) {
        clearInputLine();
        return 0;
    }
    clearInputLine();
    return 1;
}

int readString(const char *prompt, char *out, size_t outSize) {
    printf("%s", prompt);
    readLine(out, outSize);
    return out[0] != '\0';
}

