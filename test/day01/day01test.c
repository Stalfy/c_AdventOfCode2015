#include <assert.h>
#include <string.h>

#include "../../src/day01/day01.h"
#include "day01test.h"

void test_day01_part_one() {
    char* result = day01_part_one();
    assert(0 == strcmp("one", result));
}

void test_day01_part_two() {
    char* result = day01_part_two();
    assert(0 == strcmp("two", result));
}
