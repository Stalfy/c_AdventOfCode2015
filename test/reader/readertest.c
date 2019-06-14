#include <assert.h>
#include <string.h>

#include "../../src/reader/reader.h"
#include "readertest.h"

void test_read_file() {
    char* result = read_file("a");
    assert(NULL == result);

    result = read_file("test/artifacts/readertest.txt");
    assert(0 == strcmp("test", result));
}
