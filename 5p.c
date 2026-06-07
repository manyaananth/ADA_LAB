#include <stdio.h>

// Global variables
int cost[10][10], n, colsum[10];

// Helper function to calculate the in-degree (column sum) of each vertex
void cal_colsum() {
    for (int j = 0; j < n; j++) {
        colsum[j] = 0; // Reset sum for this column
        for (int i = 0; i < n; i++) {
            colsum[j] += cost[i][j]; // Add up the 1s in the column
        }
    }
}

// Core algorithm function
void source_removal() {
    int select[10] = {0}; // Array to track printed vertices (0 = unprinted, 1 = printed)
    
    printf("Topological order of vertices:\n");
    
    // We must output 'n' vertices, so we loop 'n' times
    for (int i = 0; i < n; i++) {
        cal_colsum(); // Recalculate in-degrees based on the current matrix state
        
        // Find the first available vertex with 0 in-degree
        for (int j = 0; j < n; j++) {
            if (colsum[j] == 0 && select[j] == 0) {
                printf("%d ", j); // Print the vertex
                select[j] = 1;    // Mark as printed so we don't print it again
                
                // Simulate "removing" the vertex by deleting all its outgoing edges
                for (int k = 0; k < n; k++) {
                    cost[j][k] = 0; // Set its entire row to 0
                }
                
                break; // Break the inner loop to recalculate colsums for the next step
            }
        }
    }
    printf("\n");
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    
    printf("Enter the adjacency matrix (use 1 for edge, 0 for no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }
    
    source_removal(); // Run the algorithm
    
    return 0;
}