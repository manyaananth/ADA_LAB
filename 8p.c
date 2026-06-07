#include <stdio.h>

// Global Variables
int s[10];     // The original set of numbers
int set[10];   // Temporarily stores the numbers we picked
int d, n;      // Target sum (d) and Number of elements (n)
int count = 0; // How many numbers are currently in our 'set'
int flag = 0;  // Becomes 1 if we find at least one solution

// Helper function to print the valid subset
void display(int count) {
    printf("{ ");
    for (int i = 0; i < count; i++) {
        printf("%d ", set[i]);
    }
    printf("}\n");
}

// Core Backtracking Function
void subset(int sum, int i) {
    // 1. Success condition (FIXED typo: was sum = d)
    if (sum == d) {
        flag = 1;
        display(count);
        return;
    }
    
    // 2. Failure conditions: Overshot the target OR ran out of numbers
    if (sum > d || i >= n) {
        return;
    }
    
    // 3. INCLUDE the current number
    set[count] = s[i];
    count++;
    subset(sum + s[i], i + 1); // Explore further WITH this number
    
    // 4. SKIP the current number (Backtrack)
    count--; // Undo adding the item
    subset(sum, i + 1); // Explore further WITHOUT this number
}

int main() {
    printf("Enter number of elements in the set: ");
    scanf("%d", &n);
    
    printf("Enter the set of values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &s[i]);
    }
    
    printf("Enter the target sum: ");
    scanf("%d", &d);
    
    printf("The subsets are:\n");
    subset(0, 0); // Start with sum = 0 and index = 0
    
    // FIXED typo: was flag = 0
    if (flag == 0) {
        printf("There is no solution\n");
    }
    
    return 0;
}