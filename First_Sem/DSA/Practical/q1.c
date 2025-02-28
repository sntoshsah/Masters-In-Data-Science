
#include <stdio.h>
#include <stdlib.h>


int main() {
    int n, i;
    float sum = 0, avg;
    int *numbers;

    // Getting user input for the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Allocating memory using malloc()
    numbers = (int *)malloc(n * sizeof(int));
    if (numbers == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Taking input values
    printf("Enter %d numbers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    // Calculating sum
    for (i = 0; i < n; i++) {
        sum += numbers[i];
    }
    avg = sum / n;

    // Printing sum and average
    printf("Sum = %.2f\n", sum);
    printf("Average = %.2f\n", avg);

    // Demonstrating realloc() by asking the user if they want to add more numbers
    int extra;
    printf("Enter additional numbers count to add: ");
    scanf("%d", &extra);

    if (extra > 0) {
        numbers = (int *)realloc(numbers, (n + extra) * sizeof(int));
        if (numbers == NULL) {
            printf("Memory reallocation failed!\n");
            return 1;
        }

        printf("Enter %d more numbers:\n", extra);
        for (i = n; i < n + extra; i++) {
            scanf("%d", &numbers[i]);
        }

        // Recalculating sum and average
        sum = 0;
        for (i = 0; i < n + extra; i++) {
            sum += numbers[i];
        }
        avg = sum / (n + extra);

        // Printing updated sum and average
        printf("Updated Sum = %.2f\n", sum);
        printf("Updated Average = %.2f\n", avg);
    }

    // Freeing allocated memory
    free(numbers);
    
    return 0;
}
