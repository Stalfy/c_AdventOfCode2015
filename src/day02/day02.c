#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "day02.h"

#define NEWLINE_ASCII 10

#define LENGTH 0
#define WIDTH  1
#define HEIGHT 2

int count_lines(char * input);
void parse_dimensions(int * arr, char * dimensions);
void parse_input(int ** dimensions, int entries, char * input);
int get_required_area(int entries, int ** dimensions);

char * day02_part_one(char * input) {
    int entries = count_lines(input);

    int ** dimensions = malloc(entries * sizeof(int *));
    parse_input(dimensions, entries, input);

    int required_area = get_required_area(entries, dimensions);

    char * buffer = malloc(15);
    sprintf(buffer, "%d", required_area);
    return buffer;
}

char * day02_part_two(char * input) {
    char * buffer = malloc(15);
    sprintf(buffer, "%d", 0);
    return buffer;
}

int count_lines(char * input) {
    int length = strlen(input);
    int counters[256] = { 0 };

    for(int i = 0; i < length; i++) {
        short value = input[i];
        counters[value]++;
    }

    return counters[NEWLINE_ASCII] + 1;
}

void parse_dimensions(int * arr, char * entry) {
    char * rest;

    char * str = malloc(strlen(entry));
    sprintf(str, "%s", entry);

    char * token = strtok_r(str, "x", &rest);
    arr[LENGTH] = atoi(token);

    token = strtok_r(NULL, "x", &rest);
    arr[WIDTH] = atoi(token);

    token = strtok_r(NULL, "x", &rest);
    arr[HEIGHT] = atoi(token);
}

void parse_input(int ** dimensions, int entries, char * input) {
    char * rest;

    char * str = malloc(strlen(input));
    sprintf(str, "%s", input);
    
    char * token = strtok_r(str, "\n", &rest);

    dimensions[0] = malloc(3 * sizeof(int));
    parse_dimensions(dimensions[0], token);

    for (int i = 1; i < entries; i++) {
        token = strtok_r(NULL, "\n", &rest);

        dimensions[i] = malloc(3 * sizeof(int));
        parse_dimensions(dimensions[i], token);
    }
}

int get_required_area(int entries, int ** dimensions) {
    int accumulator = 0;
    int extra;
    int lw;
    int wh;
    int hl;

    for(int i = 0; i < entries; i++) {
        lw = dimensions[i][LENGTH] * dimensions[i][WIDTH];
        wh = dimensions[i][WIDTH] * dimensions[i][HEIGHT];
        hl = dimensions[i][HEIGHT] * dimensions[i][LENGTH];

        extra = lw < wh ? lw : wh;
        extra = extra < hl ? extra : hl;

        accumulator += 2 * lw + 2 * wh + 2 * hl + extra;
    }

    return accumulator;
}
