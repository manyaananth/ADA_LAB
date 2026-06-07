#include <stdio.h>

int cost[10][10], n; // Global variables: adjacency matrix and number of vertices

void prim() {
    int vt[10] = {0}; // Keeps track of visited vertices (0 = unvisited, 1 = visited)
    int a = 0, b = 0, min, mincost = 0, ne = 0;
    
    vt[0] = 1; // Step 1: Always start by visiting the very first vertex (vertex 0)

    // Step 2: A minimum spanning tree will always have exactly (n - 1) edges
    while (ne < n - 1) {
        min = 999; // Reset minimum cost to a high number ("infinity") for each search

        // Step 3: Find the cheapest edge from a VISITED vertex to an UNVISITED vertex
        for (int i = 0; i < n; i++) {
            if (vt[i] == 1) { // If vertex 'i' is already visited
                for (int j = 0; j < n; j++) {
                    // If the edge is cheaper than our current 'min' AND vertex 'j' is unvisited
                    if (cost[i][j] < min && vt[j] == 0) {
                        min = cost[i][j];
                        a = i; // Remember starting vertex
                        b = j; // Remember ending vertex
                    }
                }
            }
        }

        // Step 4: Record the edge we found
        printf("Edge from vertex %d to vertex %d and the cost=%d\n", a, b, min);
        vt[b] = 1;      // Mark the newly reached vertex 'b' as visited
        ne++;           // Increase the edge count
        mincost += min; // Add the edge cost to our total
        
        // Step 5: Mark this edge as "used" by setting its cost to infinity (999) 
        // so we don't accidentally pick it again in the next loop.
        cost[a][b] = cost[b][a] = 999; 
    }
    
    printf("The minimum spanning tree cost is %d\n", mincost);
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    
    // Note: I removed the redundant second printf from your original manual to save you lines!
    printf("Enter the cost adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }
    
    prim(); // Run the algorithm
    return 0;
}
