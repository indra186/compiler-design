#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1000

void separateNumbersAndWords(const char *sentence) {
    char word[MAX_LEN];
    int pos = 0;
    
    printf("Words: ");
    while (*sentence) {
        if (isspace(*sentence) || ispunct(*sentence)) {
            if (pos > 0) {
                word[pos] = '\0';
                if (isdigit(word[0])) {
                    // It's a number, skip
                } else {
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
        if (!isdigit(word[0])) {
            printf("%s ", word);
        }
    }
    
    printf("\nNumbers: ");
    sentence -= pos; // reset sentence pointer to start of last word
    pos = 0;
    while (*sentence) {
        if (isspace(*sentence) || ispunct(*sentence)) {
            if (pos > 0) {
                word[pos] = '\0';
                if (isdigit(word[0])) {
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
        if (isdigit(word[0])) {
            printf("%s ", word);
        }
    }
}

int main() {
    char sentence[MAX_LEN];

    printf("Enter a statement: ");
    fgets(sentence, sizeof(sentence), stdin);

    separateNumbersAndWords(sentence);

    return 0;
}
