/*
 * Program: Statistics Calculator (C Version)
 * Description:
 *   This program calculates the Mean, Median, and Mode of a list of integers.
 *   It follows a procedural programming style, using functions for each operation.
 *   User is asked to input the list of integers.
 *
 * Note: We manually sort and count elements as C lacks built-in helpers.
 */

#include <stdio.h>
#include <stdlib.h>

// Function to calculate mean
float calculateMean(int arr[], int size) {
    int sum = 0;

    // Sum all elements
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }

    // Return average
    return (float)sum / size;
}

// Helper function to sort array (Bubble Sort)
void sortArray(int arr[], int size) {
    int temp;
    
    // Simple bubble sort
    for (int i = 0; i < size-1; i++) {
        for (int j = 0; j < size-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap elements
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Function to calculate median
float calculateMedian(int arr[], int size) {
    // First sort the array
    sortArray(arr, size);

    if (size % 2 == 1) {
        // Odd number of elements — return middle
        return arr[size / 2];
    } else {
        // Even number — average of two middles
        return (arr[(size - 1) / 2] + arr[size / 2]) / 2.0;
    }
}

// Function to calculate mode(s)
void calculateMode(int arr[], int size) {
    int maxCount = 0;
    int i, j;

    printf("Mode: ");

    // Outer loop to pick elements
    for (i = 0; i < size; i++) {
        int count = 1;

        // Skip duplicates already checked
        int alreadyCounted = 0;
        for (int k = 0; k < i; k++) {
            if (arr[k] == arr[i]) {
                alreadyCounted = 1;
                break;
            }
        }

        if (alreadyCounted) continue;

        // Count frequency of arr[i]
        for (j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }

        // Print value if it matches current max count
        if (count > maxCount) {
            maxCount = count;
        }
    }

    // Second loop to actually print modes
    for (i = 0; i < size; i++) {
        int count = 1;
        int alreadyPrinted = 0;

        for (int k = 0; k < i; k++) {
            if (arr[k] == arr[i]) {
                alreadyPrinted = 1;
                break;
            }
        }

        if (alreadyPrinted) continue;

        for (j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }

        if (count == maxCount) {
            printf("%d ", arr[i]);
        }
    }

    printf("\n");
}

int main() {
    int size;

    // Ask user for number of elements
    printf("Enter the number of integers: ");
    scanf("%d", &size);

    // Dynamically allocate memory for array
    int* numbers = (int*) malloc(size * sizeof(int));

    if (numbers == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Get list of integers from user
    printf("Enter %d integers: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &numbers[i]);
    }

    // Calculate and display results
    printf("\nMean: %.2f\n", calculateMean(numbers, size));
    printf("Median: %.2f\n", calculateMedian(numbers, size));
    calculateMode(numbers, size);  // Mode can be multiple values

    // Free allocated memory
    free(numbers);

    return 0;
}
