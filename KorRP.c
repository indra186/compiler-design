#include <stdio.h>
#include <string.h>
#include <stdbool.h>
bool isKeyword(const char *word) {
    const char *keywords[] = {"int", "float", "char", "if", "else", "while", "for", "return"};
    size_t numKeywords = sizeof(keywords) / sizeof(keywords[0]);

    for (size_t i = 0; i < numKeywords; i++) {
        if (strcmp(word, keywords[i]) == 0) {
            return true;
        }
    }
    return false;
}
bool isRelationalOperator(const char *word) {
    const char *relationalOperators[] = {"<", ">", "<=", ">=", "==", "!="};
    size_t numOperators = sizeof(relationalOperators) / sizeof(relationalOperators[0]);

    for (size_t i = 0; i < numOperators; i++) {
        if (strcmp(word, relationalOperators[i]) == 0) {
            return true;
        }
    }
    return false;
}

int main() {
    char input[100];

    printf("Enter a word or relational operator: ");
    if (fgets(input, sizeof(input), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }
    input[strcspn(input, "\n")] = '\0';

    if (isKeyword(input)) {
        printf("\"%s\" is a keyword.\n", input);
    } else if (isRelationalOperator(input)) {
        printf("\"%s\" is a relational operator.\n", input);
    } else {
        printf("\"%s\" is neither a keyword nor a relational operator.\n", input);
    }

    return 0;
}
