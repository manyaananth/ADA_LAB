#include <stdio.h>

// Core Function: Warshall's Algorithm
void warshall(int a[10][10], int n) {
    // k is the intermediate vertex
    for (int k = 1; k <= n; k++) {
        // i is the starting vertex
        for (int i = 1; i <= n; i++) {
            // j is the ending vertex
            for (int j = 1; j <= n; j++) {
                // Path exists if direct path exists OR (path to 'k' AND path from 'k' exists)
                a[i][j] = a[i][j] || (a[i][k] && a[k][j]);
            }
        }
    }
}

int main() {
    int n, adj[10][10];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (0s and 1s):\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    warshall(adj, n);

    printf("Transitive closure of the given graph is:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d\t", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}