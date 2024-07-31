#include <stdio.h>
#include <string.h>
#include <ctype.h>

int is_valid_mobile_number(const char *number) {
    
    if (strlen(number) != 10) {
        return 0; 
    }
    
    
    for (int i = 0; i < 10; i++) {
        if (!isdigit(number[i])) {
            return 0; 
        }
    }
    
    return 1; 
}

int main() {
    char mobile_number[20];
    
    printf("Enter a mobile number: ");
    scanf("%19s", mobile_number);
    
    if (is_valid_mobile_number(mobile_number)) {
        printf("The mobile number '%s' is valid.\n", mobile_number);
    } else {
        printf("The mobile number '%s' is not valid.\n", mobile_number);
    }
    
    return 0;
}
