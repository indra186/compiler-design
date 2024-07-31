#include <stdio.h>

void add_line_numbers(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char line[1024];
    int line_number = 1;

    while (fgets(line, sizeof(line), file)) {
        printf("%4d: %s", line_number++, line);
    }

    fclose(file);
}

int main() {
    const char *filename = "sample.c";
    add_line_numbers(filename);
    return 0;
}
