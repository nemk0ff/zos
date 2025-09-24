#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>

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