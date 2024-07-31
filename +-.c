#include <stdio.h>

int main() {
    int num, count, positiveCount = 0, negativeCount = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &count);

    int numbers[count];

    printf("Enter %d numbers:\n", count);
    for (int i = 0; i < count; i++) {
        scanf("%d", &numbers[i]);
    }

    for (int i = 0; i < count; i++) {
        if (numbers[i] > 0) {
            positiveCount++;
        } else if (numbers[i] < 0) {
            negativeCount++;
        }
    }

    printf("Number of positive numbers: %d\n", positiveCount);
    printf("Number of negative numbers: %d\n", negativeCount);

    return 0;
}
