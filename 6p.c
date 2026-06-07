#include <stdio.h>

int n, m, p[10], w[10];

// Helper to find the maximum of two numbers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Core DP Algorithm
void knapsack_DP() {
    int v[10][10], i, j;
    
    // Build the DP table
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= m; j++) {
            if (i == 0 || j == 0) {
                v[i][j] = 0; // Base case: 0 items or 0 capacity
            } 
            else if (j < w[i]) {
                v[i][j] = v[i - 1][j]; // Item doesn't fit, carry down the best previous profit
            } 
            else {
                // Item fits: find max between leaving it vs taking it
                v[i][j] = max(v[i - 1][j], v[i - 1][j - w[i]] + p[i]);
            }
        }
    }
    
    // Print the entire DP table
    printf("DP Table:\n");
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= m; j++) {
            printf("%d\t", v[i][j]);
        }
        printf("\n");
    }
    
    // Traceback to find the exact items
    printf("Items included in the knapsack:\n");
    while (n > 0) {
        if (v[n][m] != v[n - 1][m]) {
            printf("Item %d\n", n);
            m = m - w[n]; // Reduce capacity
        }
        n--; // Move to previous item
    }
}

int main() {
    printf("Enter number of items: ");
    scanf("%d", &n);
    
    // Notice we start arrays at index 1 so Item 1 corresponds to w[1] and p[1]
    printf("Enter weights of items: ");
    for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
    
    printf("Enter prices of items: ");
    for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
    
    printf("Enter capacity of knapsack: ");
    scanf("%d", &m);
    
    knapsack_DP();
    
    return 0;
}