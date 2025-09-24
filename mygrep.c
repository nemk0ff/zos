#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    char *data;
    size_t capacity;
    size_t size;
} String;

bool pattern_in_line(const char* pattern, const String* line) {
    size_t pattern_length = strlen(pattern);
    if (pattern_length > line->size) return false;
    for (size_t i = 0; i < line->size - pattern_length; i++) {
        if (strncmp(pattern, &(line->data[i]), pattern_length) == 0) return true;
    }
    return false;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Too few arguments\n");
        return 1;
    }
    if (argc > 3) {
        fprintf(stderr, "Too many arguments\n");
        return 1;
    }

    printf("Pattern: %s\n", argv[1]);
    if (argc == 3) {
        printf("File: %s\n", argv[2]);
    } else {
        printf("Reading from stdin\n");
    }

    return 0;
}