#include <stdio.h>
#include <ctype.h>
int startsWithVowel(char str[]) {
    char firstChar = tolower(str[0]);
    return firstChar == 'a' || firstChar == 'e' || firstChar == 'i' || firstChar == 'o' || firstChar == 'u';
}

int main() {
    char str[100];
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    if (str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }
    
    if (startsWithVowel(str)) {
        printf("The string starts with a vowel.\n");
    } else {
        printf("The string does not start with a vowel.\n");
    }
    
    return 0;
}
