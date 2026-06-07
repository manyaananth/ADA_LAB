#include <stdio.h>

// Helper function: Returns the smaller of two numbers
int min(int a, int b) {
    return (a < b) ? a : b; 
}

// Core Function: Floyd's Algorithm
void floyd(int d[10][10], int n) {
    // Loop 1: 'k' acts as the intermediate vertex we are checking
    for (int k = 1; k <= n; k++) {
        // Loop 2: 'i' is the starting (source) vertex
        for (int i = 1; i <= n; i++) {
            // Loop 3: 'j' is the destination vertex
            for (int j = 1; j <= n; j++) {
                // Update the path if going from i -> k -> j is shorter than the direct path i -> j
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int main() {
    int n, cost[10][10];

    // Step 1: Read the number of vertices
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Step 2: Read the initial adjacency/cost matrix
    printf("Enter the cost matrix (use a large number like 999 for infinity):\n");
    // Note: We use 1 to n (instead of 0 to n-1) to match your original notes
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    // Step 3: Call the function to calculate shortest paths
    floyd(cost, n);

    // Step 4: Print the final optimized matrix
    printf("All-pairs shortest path matrix:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            // \t adds a tab space so the matrix aligns neatly like a grid
            printf("%d\t", cost[i][j]); 
        }
        printf("\n"); // Move to the next line for the next row
    }

    return 0;
}