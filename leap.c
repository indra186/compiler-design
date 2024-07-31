#include <stdio.h>
#include <stdbool.h>


bool isLeapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}

bool isValidDate(int day, int month, int year) {
    // Check for valid year
    if (year < 1900 || year > 2100) {
        return false;
    }
    if (month < 1 || month > 12) {
        return false;
    }

    // Days in each month
    int daysInMonth[] = {31, 28 + isLeapYear(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (day < 1 || day > daysInMonth[month - 1]) {
        return false;
    }

    return true;
}

int main() {
    int day, month, year;

    printf("Enter the Date of Birth (DD/MM/YYYY): ");
    if (scanf("%d/%d/%d", &day, &month, &year) != 3) {
        printf("Invalid input format.\n");
        return 1;
    }

    if (isValidDate(day, month, year)) {
        printf("The date %02d/%02d/%04d is valid.\n", day, month, year);
    } else {
        printf("The date %02d/%02d/%04d is invalid.\n", day, month, year);
    }

    return 0;
}