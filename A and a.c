#include <stdio.h>
#include <ctype.h>

void countVowelsAndConsonants(const char *sentence, int *vowelCount, int *consonantCount) {
    *vowelCount = 0;
    *consonantCount = 0;
    char ch;
    while ((ch = *sentence++) != '\0') {
        if (isalpha(ch)) {
            ch = tolower(ch);
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                (*vowelCount)++;
            } else {
                (*consonantCount)++;
            }
        }
    }
}

int main() {
    char sentence[1000];
    int vowelCount, consonantCount;

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    countVowelsAndConsonants(sentence, &vowelCount, &consonantCount);

    printf("Number of vowels: %d\n", vowelCount);
    printf("Number of consonants: %d\n", consonantCount);

    return 0;
}
