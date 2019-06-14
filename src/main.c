#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#include "reader/reader.h"
#include "day01/day01.h"

char* (* part_one)();
char* (* part_two)();

void display_result(char* part, char* result, struct timeval tvs, struct timeval tve);

int main(int argc, char* argv[]) {
    int puzzle;
    char * input;
    char * input_filename;
    char * result;
    struct timeval tvs;
    struct timeval tve;

    if(2 != argc) {
        return EXIT_FAILURE;
    }

    puzzle = atoi(argv[1]);

    input_filename = malloc(18);
    sprintf(input_filename, "./input/day%02d.txt", puzzle);

    input = read_file(input_filename);

    part_one = day01_part_one;
    part_two = day01_part_two;

    gettimeofday(&tvs, NULL);
    result = part_one(input);
    gettimeofday(&tve, NULL);
    display_result("one", result, tvs, tve);

    printf("\n");

    gettimeofday(&tvs, NULL);
    result = part_two();
    gettimeofday(&tve, NULL);
    display_result("two", result, tvs, tve);


    return EXIT_SUCCESS;
}

void display_result(char* part, char* result, struct timeval tvs, struct timeval tve) {
    long s = tvs.tv_sec * 1000000 + tvs.tv_usec;
    long e = tve.tv_sec * 1000000 + tve.tv_usec;
    long delta = e - s;

    printf("Result of part %s: %s.\n", part, result);
    printf("Resolution time: %9.6f seconds.\n", delta / 1000000.0);
}
