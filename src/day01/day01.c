#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "day01.h"

char * day01_part_one(char * input) {
    int length = strlen(input);
    int floor = 0;

    for(int i = 0; i < length; i++) {
        floor += ('(' == input[i]) ? 1 : -1;
    }

    char * buffer = malloc(15);
    sprintf(buffer, "%d", floor);
    return buffer;
}

char * day01_part_two(char * input) {
    int floor = 0;
    int counter = 0;
    
    while(-1 < floor) {
        floor += ('(' == input[counter]) ? 1 : -1;
        counter++;
    }

    char * buffer = malloc(15);
    sprintf(buffer, "%d", counter);
    return buffer;
}
