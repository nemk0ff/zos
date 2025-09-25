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

size_t to_round_divider(size_t number, size_t divider) {
    size_t d = number/divider;
    size_t r = number - d*divider;
    if (r==0) return number;
    return (d+1)*divider;
}

void get_line(FILE fd, String str) {
#define START_LENGTH 64

    if (str->capacity == 0) {
        str->data = malloc(sizeof(char) * START_LENGTH);
        str->capacity = START_LENGTH;
    }
    str->size = 0;

    char ch = fgetc(fd);
    while (ch != '\n' && ch != EOF) {
        if (ch != '\r') {
            if (str->size + 1 == str->capacity)  {
                size_t required_size = to_round_divider(str->capacity*1.5, 64);
                char* newdata = malloc(sizeof(char) * required_size);
                memcpy(newdata, str->data, str->size);
                free(str->data);
                str->data = newdata;
                str->capacity = required_size;
            }
            str->data[str->size++] = ch;
        }
        ch = fgetc(fd);
    }
    str->data[str->size] = '\0';
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