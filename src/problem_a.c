#include "problem_a.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

uint16_t count = 0;
uint16_t* students;
char* instructions;

void prepare() {
    students = (uint16_t*)calloc(count, sizeof(uint16_t));
    instructions = (char*)calloc(count, sizeof(char));
}

void run() {
    uint16_t curIndex = 0;
    uint16_t nonZeroCount = 0;

    while (count > 0) {
        curIndex += instructions[curIndex] == 'L' ? -1 : 1;
        nonZeroCount += students[curIndex] == 0 ? 1 : 0;
        students[curIndex] += 1;
        count -= 1;
    }

    printf("%d\n", nonZeroCount);
}

void clean() {
    free(students);
    free(instructions);
}

