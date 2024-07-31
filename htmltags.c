#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void extractTags(FILE *file) {
    char ch;
    int inTag = 0;

    while ((ch = fgetc(file)) != EOF) {
        if (ch == '<') {
            inTag = 1;
            printf("%c", ch);
        } else if (ch == '>') {
            if (inTag) {
                printf("%c\n", ch);
                inTag = 0;
            }
        } else if (inTag) {
            printf("%c", ch);
        }
    }
}

int main() {
    char filename[100];
    FILE *file;

    printf("Enter the name of the HTML file: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file %s for reading.\n", filename);
        return 1;
    }

    printf("HTML tags in the file:\n");
    extractTags(file);

    fclose(file);
    return 0;
}
