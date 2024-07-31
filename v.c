#include <stdio.h>
#include <ctype.h>

int main() {
    char sentence[1000];
    int vowels = 0, consonants = 0;


    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    for (int i = 0; sentence[i] != '\0'; i++) {
        char ch = tolower(sentence[i]);

       
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            vowels++;
        }
       
        else if ((ch >= 'a' && ch <= 'z')) {
            consonants++;
        }
    }

    printf("Number of vowels: %d\n", vowels);
    printf("Number of consonants: %d\n", consonants);

    return 0;
}
