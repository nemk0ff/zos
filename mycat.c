#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

typedef struct {
    bool n;
    bool b;
    bool E;
} Flags;
const char flag_string[] = "nbE";

typedef struct {
    Flags flags;
    size_t line_number;
} Context;

int main(int argc, char** argv) {
    if (argc < 2) {
        fprintf(stderr, "Too few arguments\n");
        exit(1);
    }
    Context ctx = {.flags = {0}, .line_number=1};
    int opt;

    while ((opt = getopt(argc, argv, flag_string)) != -1) {
        switch (opt) {
            case 'n':
                ctx.flags.n = true;
                break;
            case 'b':
                ctx.flags.b = true;
                break;
            case 'E':
                ctx.flags.E = true;
                break;

            case '?':
            default:
                exit(1);
                break;
        }
    }

// Пока просто выводим имена файлов для демонстрации
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') continue;
        printf("File: %s\n", argv[i]);
    }
}