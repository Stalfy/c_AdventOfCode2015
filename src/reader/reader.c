#include <stdio.h>
#include <stdlib.h>

#include "reader.h"

char* read_file(char* filename) {
    FILE *file = fopen(filename, "r");
    if(NULL == file) {
        printf("Invalid file name.\n");
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long characters = ftell(file);
    rewind(file);

    char* content = malloc(characters * sizeof(char));
    for(long i = 0; i < characters - 1; i++) {
        content[i] = fgetc(file);
    }

    content[characters - 1] = '\0';
    fclose(file);

    return content;
}
