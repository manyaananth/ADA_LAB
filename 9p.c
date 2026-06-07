#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to sort the array using Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        
        // Find the minimum element in the unsorted portion
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        
        // Swap the found minimum element with the first unsorted element
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

// Function to populate the array with random numbers
void generateRandomNumbers(int arr[], int n) {
    srand(time(0));
    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % 10000; // Generate numbers from 0 to 9999
    }
}

int main() {
    int n;
    
    printf("Enter the number of elements to sort: ");
    scanf("%d", &n);
    
    if (n <= 5000) {
        printf("Please enter a value greater than 5000.\n");
        return 1;
    }
    
    // Dynamically allocate memory for the array to handle large values of 'n'
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    
    // Fill the array
    generateRandomNumbers(arr, n);
    
    // Time the sorting algorithm
    clock_t start = clock();
    selectionSort(arr, n);
    clock_t end = clock();
    
    // Calculate total time taken in seconds
    double timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
    
    printf("Time taken to sort %d elements: %f seconds\n", n, timeTaken);
    
    // Free the dynamically allocated memory
    free(arr);
    
    return 0;
}