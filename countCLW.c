#include <stdio.h>
#include <ctype.h>

#define IN 1  
#define OUT 0 

void count_file_stats(const char *filename, int *char_count, int *line_count, int *word_count) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    int c;
    int state = OUT;

    *char_count = 0;
    *line_count = 0;
    *word_count = 0;

    while ((c = fgetc(file)) != EOF) {
        (*char_count)++;

        if (c == '\n') {
            (*line_count)++;
        }

        if (isspace(c)) {
            state = OUT;
        } else if (state == OUT) {
            state = IN;
            (*word_count)++;
        }
    }

    fclose(file);
}

int main() {
    const char *filename = "sample.txt";

    int char_count, line_count, word_count;
    count_file_stats(filename, &char_count, &line_count, &word_count);

    printf("Number of characters: %d\n", char_count);
    printf("Number of lines: %d\n", line_count);
    printf("Number of words: %d\n", word_count);

    return 0;
}
