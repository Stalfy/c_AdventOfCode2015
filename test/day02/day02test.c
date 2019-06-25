#include <assert.h>
#include <string.h>

#include "../../src/day02/day02.h"
#include "day02test.h"

void test_day02_part_one() {
    char * result = day02_part_one("2x3x4");
    assert(0 == strcmp("58", result));

    result = day02_part_one("1x1x10");
    assert(0 == strcmp("43", result));

    result = day02_part_one("2x3x4\n1x1x10");
    assert(0 == strcmp("101", result));
}

void test_day02_part_two() {
    char * result = day02_part_two("2x3x4");
    assert(0 == strcmp("34", result));

    result = day02_part_two("1x1x10");
    assert(0 == strcmp("14", result));

    result = day02_part_two("2x3x4\n1x1x10");
    assert(0 == strcmp("48", result));
}
