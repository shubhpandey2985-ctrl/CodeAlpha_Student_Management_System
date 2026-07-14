#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include <stdio.h>

FILE *openFile(const char *filename, const char *mode);
int fileExists(const char *filename);

#endif /* FILE_HANDLER_H */

