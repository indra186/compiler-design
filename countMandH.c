#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

void countMacrosAndHeaders(const char *filename, int *macroCount, int *headerCount) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];

    while (fgets(line, sizeof(line), file)) {
       
        if (strncmp(line, "#define", 7) == 0) {
            (*macroCount)++;
        }

        if (strncmp(line, "#include", 8) == 0) {
           
            char *includePart = line + 8; 
            while (*includePart == ' ' || *includePart == '\t') {
                includePart++;
            }
            if (*includePart == '<' || *includePart == '"') {
                (*headerCount)++;
            }
        }
    }

    fclose(file);
}

int main() {
    char filename[100];
    int macroCount = 0;
    int headerCount = 0;

    printf("Enter the name of the C source file: ");
    scanf("%s", filename);

    countMacrosAndHeaders(filename, &macroCount, &headerCount);

    printf("Number of macros defined: %d\n", macroCount);
    printf("Number of header files included: %d\n", headerCount);

    return 0;
}
