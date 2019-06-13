#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "day01.h"

char* day01_part_one(char* input) {
    int length = strlen(input);
    int counter = 0;

    for(int i = 0; i < length; i++) {
        counter += '(' == input[i] ? 1 : -1;
    }

    char* buffer = malloc(10);
    sprintf(buffer, "%d", counter);

    return buffer;
}

char* day01_part_two() {
    return "two";
}
