#include "problem_a.h"
#include "file_helper.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

const uint16_t MAX_LINE_LENGTH = 200;

uint16_t testCount = 0;

int countStudentsPass();

int prepare() {
    int result = read("./tests/problem_a.txt", MAX_LINE_LENGTH);
    if (result != 0) {
        return 1;
    }
    
    testCount = atoi(nextLine());

    return 0;
}

int run() {
    while (testCount > 0) {
        printf("%d ", countStudentsPass());
        testCount -= 1;
    }

    return 0;
}

void clean() {
    closeFile();
}

int countStudentsPass() {
    uint8_t studentCount = atoi(nextLine());
    char* instructions = nextLine();
    uint8_t* students = (uint8_t*)calloc(studentCount, sizeof(uint8_t));
    uint8_t curIndex = 0;
    uint8_t nonZeroCount = 0;

    while (studentCount > 0) {
        curIndex += instructions[curIndex] == 'L' ? -1 : 1;
        nonZeroCount += students[curIndex] == 0 ? 1 : 0;
        students[curIndex] += 1;
        studentCount -= 1;
    }

    free(students);

    return nonZeroCount;
}

