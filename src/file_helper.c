#include "file_helper.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

uint32_t maxLength = 0;
char* buffer;
FILE* file;

void clearBuffer() {
    if (buffer != NULL) {
        free(buffer);
    }
}

int read(char* filePath, uint32_t lineMaxLength) {
    maxLength = lineMaxLength;
    file = fopen(filePath, "r");
    if (file == NULL) {
        return 1;
    }
    clearBuffer();
    buffer = (char*)calloc(maxLength, sizeof(char));

    return 0;
}

void closeFile() {
    if (file == NULL) {
        return;
    }

    clearBuffer();
    fclose(file);
}

char* nextLine() {
    if (file == NULL) {
        return NULL;
    }

    memset(buffer, '\0', maxLength);
    if (fgets(buffer, maxLength, file) == NULL) {
        return NULL;
    }

    return buffer;
}

char* getLine() {
    return buffer;
}
