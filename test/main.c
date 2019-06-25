#include <stdio.h>
#include <stdlib.h>

#include "reader/readertest.h"
#include "day01/day01test.h"
#include "day02/day02test.h"

int main() {
    test_read_file();

    test_day01_part_one();
    test_day01_part_two();

    test_day02_part_one();
    test_day02_part_two();

    return EXIT_SUCCESS;
}
