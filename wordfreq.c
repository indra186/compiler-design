#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1000

void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}
int count_word_frequency(const char *sentence, const char *word) {
    char sentence_copy[MAX_LEN];
    char *token;
    int count = 0;
    strncpy(sentence_copy, sentence, MAX_LEN - 1);
    sentence_copy[MAX_LEN - 1] = '\0';
    to_lowercase(sentence_copy);
    char word_copy[MAX_LEN];
    strncpy(word_copy, word, MAX_LEN - 1);
    word_copy[MAX_LEN - 1] = '\0';
    to_lowercase(word_copy);

    token = strtok(sentence_copy, " \t\n");
    while (token != NULL) {
        if (strcmp(token, word_copy) == 0) {
            count++;
        }
        token = strtok(NULL, " \t\n");
    }

    return count;
}

int main() {
    char sentence[MAX_LEN];
    char word[MAX_LEN];

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    size_t len = strlen(sentence);
    if (len > 0 && sentence[len - 1] == '\n') {
        sentence[len - 1] = '\0';
    }

    printf("Enter the word to search for: ");
    fgets(word, sizeof(word), stdin);

    len = strlen(word);
    if (len > 0 && word[len - 1] == '\n') {
        word[len - 1] = '\0';
    }

    int frequency = count_word_frequency(sentence, word);
    printf("The word '%s' appears %d times in the sentence.\n", word, frequency);

    return 0;
}
