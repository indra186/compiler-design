#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

void extractConstants(FILE *file) {
    char line[MAX_LINE_LENGTH];
    char *token;
    const char delimiters[] = " ,;(){}[]\n\t";

    while (fgets(line, sizeof(line), file)) {
        // Check for #define constants
        if (strncmp(line, "#define", 7) == 0) {
            token = strtok(line, delimiters);
            while (token != NULL) {
                if (isdigit(token[0]) || (token[0] == '.' && isdigit(token[1]))) {
                    printf("%s\n", token);
                }
                token = strtok(NULL, delimiters);
            }
        }

        // Check for numeric constants in the code
        token = strtok(line, delimiters);
        while (token != NULL) {
            if (isdigit(token[0]) || (token[0] == '.' && isdigit(token[1]))) {
                printf("%s\n", token);
            }
            token = strtok(NULL, delimiters);
        }
    }
}

int main() {
    char filename[100];
    FILE *file;

    printf("Enter the name of the C source file: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file %s for reading.\n", filename);
        return 1;
    }

    printf("Constants in the file:\n");
    extractConstants(file);

    fclose(file);
    return 0;
}