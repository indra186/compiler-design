#include <stdio.h>
#include <ctype.h> // for tolower() function

#define MAX_LEN 1000

int main() {
    char str[MAX_LEN];
    char firstChar;

    // Prompt the user to enter a string
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Check if the first character is a vowel
    firstChar = str[0];
    firstChar = tolower(firstChar); // Convert to lowercase for comparison

    if (firstChar == 'a' || firstChar == 'e' || firstChar == 'i' || firstChar == 'o' || firstChar == 'u') {
        printf("Accepted string: %s", str);
    } else {
        printf("The string does not start with a vowel.\n");
    }

    return 0;
}
