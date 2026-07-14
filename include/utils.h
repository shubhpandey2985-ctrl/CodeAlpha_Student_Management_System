#ifndef UTILS_H
#define UTILS_H

#include <stddef.h>

void clearInputLine(void);
void readLine(char *buf, size_t size);
int readInt(const char *prompt, int *out);
int readFloat(const char *prompt, float *out);
int readString(const char *prompt, char *out, size_t outSize);

#endif /* UTILS_H */


