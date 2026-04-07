#include "file_helper.h"
#include <stdio.h>
#include <stdlib.h>

unsigned int maxLength = 0;
char* buffer;
FILE* file;

void clearBuffer() {
    if (buffer != NULL) {
        free(buffer);
    }
}

int read(char* filePath, unsigned int lineMaxLength) {
    maxLength = lineMaxLength;
    file = fopen(filePath, "r");
    if (file == NULL) {
        return 1;
    }

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

    clearBuffer();
    buffer = (char*)calloc(maxLength, sizeof(char));
    if (fgets(buffer, maxLength, file) == NULL) {
        return NULL;
    }

    return buffer;
}

char* getLine() {
    return buffer;
}
