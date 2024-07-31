#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 100

// List of C keywords
const char *keywords[] = {
    "auto", "break", "case", "char", "const", "continue", "default", "do", 
    "double", "else", "enum", "extern", "float", "for", "goto", "if", 
    "int", "long", "register", "return", "short", "signed", "sizeof", 
    "static", "struct", "switch", "typedef", "union", "unsigned", "void", 
    "volatile", "while"
};

int isKeyword(const char *word) {
    int numKeywords = sizeof(keywords) / sizeof(keywords[0]);
    for (int i = 0; i < numKeywords; i++) {
        if (strcmp(word, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int isIdentifier(const char *word) {
    if (!isalpha(word[0]) && word[0] != '_') {
        return 0;
    }
    for (int i = 1; word[i] != '\0'; i++) {
        if (!isalnum(word[i]) && word[i] != '_') {
            return 0;
        }
    }
    return 1;
}

void separateKeywordsAndIdentifiers(const char *sentence) {
    char word[MAX_WORD_LENGTH];
    int pos = 0;
    
    printf("Keywords: ");
    while (*sentence) {
        if (isspace(*sentence) || ispunct(*sentence)) {
            if (pos > 0) {
                word[pos] = '\0';
                if (isKeyword(word)) {
                    printf("%s ", word);
                }
                pos = 0;
            }
        } else {
            word[pos++] = *sentence;
        }
        sentence++;
    }
    if (pos > 0) {
        word[pos] = '\0';
        if (isKeyword(word)) {
            printf("%s ", word);
        }
    }
    
    printf("\nIdentifiers: ");
    sentence -= pos; // reset sentence pointer to start of last word
    pos = 0;
    while (*sentence) {
        if (isspace(*sentence) || ispunct(*sentence)) {
            if (pos > 0) {
                word[pos] = '\0';
                if (!isKeyword(word) && isIdentifier(word)) {
                    printf("%s ", word);
                }
                pos = 0;
            }
        } else {
            word[pos++] = *sentence;
        }
        sentence++;
    }
    if (pos > 0) {
        word[pos] = '\0';
        if (!isKeyword(word) && isIdentifier(word)) {
            printf("%s ", word);
        }
    }
}

int main() {
    char sentence[1000];
    
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);
    
    separateKeywordsAndIdentifiers(sentence);
    
    return 0;
}
