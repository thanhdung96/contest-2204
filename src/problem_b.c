#include "problem_algo.h"
#include "file_helper.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const uint8_t MAX_ELEMENT_SIZE = 6;
const uint32_t MAX_LINE_ELEMENTS = 1e5;
const uint32_t MAX_LINE_LENGTH = MAX_LINE_ELEMENTS * MAX_ELEMENT_SIZE + 10;

uint16_t testCount = 0;
uint32_t* valuesArray;

uint32_t rightMax(const uint32_t* numberOfElements);
void parseLine(const uint32_t* numberOfElements, char* rawArray);

int prepare() {
    int result = read("./tests/problem_b.txt", MAX_LINE_LENGTH);
    if (result != 0) {
        return 1;
    }
    
    testCount = atoi(nextLine());
    valuesArray = (uint32_t*)calloc(MAX_LINE_ELEMENTS, (sizeof(uint32_t)));

    return 0;
}

int run() {
    uint32_t numberOfElements;
    while (testCount > 0) {
        numberOfElements = strtoul(nextLine(), NULL, 10);
        printf("%d ", rightMax(&numberOfElements));
        testCount -= 1;
    }

    return 0;
}

uint32_t rightMax(const uint32_t* numberOfElements) {
    uint32_t count = 1;
    char* rawArray = nextLine();
    parseLine(numberOfElements, rawArray);
    uint32_t currentMax = valuesArray[0];

    for (uint32_t curIndex = 1; curIndex < *numberOfElements; curIndex += 1) {
        if (valuesArray[curIndex] >= currentMax) {
            currentMax = valuesArray[curIndex];
            count += 1;
        }
    }
    
    // reset mem
    memset(valuesArray, 0, *numberOfElements);

    return count;
}

inline void parseLine(const uint32_t* numberOfElements, char* rawArray) {
    char* element = strtok(rawArray, " ");
    valuesArray[0] = strtoul(element, NULL, 10);

    for (uint32_t curIndex = 1; curIndex < *numberOfElements; curIndex += 1) {
        element = strtok(NULL, " ");
        valuesArray[curIndex] = strtoul(element, NULL, 10);
    }
}

void clean() {
    closeFile();
    free(valuesArray);
}
