#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
bool isLeapYear(int year) {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

bool isValidDate(int day, int month, int year) {
if (year < 1900 || year > 2100) {
        return false;
    }

    if (month < 1 || month > 12) {
        return false;
    }
    int daysInMonth[] = {31, 28 + isLeapYear(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (day < 1 || day > daysInMonth[month - 1]) {
        return false;
    }

    return true;
}

int main() {
    char input[11]; 
    int day, month, year;

    printf("Enter the Date of Birth (DD/MM/YYYY): ");
    if (fgets(input, sizeof(input), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }
    input[strcspn(input, "\n")] = '\0';
    if (sscanf(input, "%2d/%2d/%4d", &day, &month, &year) != 3) {
        printf("Invalid input format. Please use DD/MM/YYYY format.\n");
        return 1;
    }

    if (isValidDate(day, month, year)) {
        printf("The date %02d/%02d/%04d is valid.\n", day, month, year);
    } else {
        printf("The date %02d/%02d/%04d is invalid.\n", day, month, year);
    }

    return 0;
}
