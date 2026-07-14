#include "file_handler.h"

FILE *openFile(const char *filename, const char *mode) {
    return fopen(filename, mode);
}

int fileExists(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) return 0;
    fclose(fp);
    return 1;
}

