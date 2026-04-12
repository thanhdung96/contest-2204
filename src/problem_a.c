#include "problem_algo.h"
#include "file_helper.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const uint16_t MAX_LINE_LENGTH = 200;

uint16_t testCount = 0;
uint8_t* students;

int countStudentsPass();

int prepare() {
    int result = read("./tests/problem_a.txt", MAX_LINE_LENGTH);
    if (result != 0) {
        return 1;
    }
    
    testCount = atoi(nextLine());
    students = (uint8_t*)calloc(MAX_LINE_LENGTH, sizeof(uint8_t));

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
    free(students);
}

int countStudentsPass() {
    uint8_t studentCount = atoi(nextLine());
    char* instructions = nextLine();
    memset(students, '\0', MAX_LINE_LENGTH);
    uint8_t curIndex = 0;
    uint8_t nonZeroCount = 0;

    while (studentCount > 0) {
        curIndex += instructions[curIndex] == 'L' ? -1 : 1;
        nonZeroCount += students[curIndex] == 0 ? 1 : 0;
        students[curIndex] += 1;
        studentCount -= 1;
    }

    return nonZeroCount;
}
