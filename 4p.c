#include <stdio.h>
int cost[10][10], n, dist[10], parent[10];

void printPath(int v) {
    if (parent[v] == -1) {
        printf("%d", v); 
        return;
    }
    printPath(parent[v]); 
    printf(" -> %d", v);  
}
void dijkstra(int source) {
    int visited[10] = {0}; 
    int min, w;

    for (int i = 0; i < n; i++) {
        dist[i] = 999;
        parent[i] = -1;
    }
    dist[source] = 0; 

    for (int i = 0; i < n; i++) {
        min = 999;
        w = -1;

        for (int j = 0; j < n; j++) {
            if (visited[j] == 0 && dist[j] < min) {
                min = dist[j];
                w = j;
            }
        }

        if (w == -1) break;
        visited[w] = 1; 

        for (int j = 0; j < n; j++) {
            if (visited[j] == 0 && cost[w][j] != 999) {
                if (dist[w] + cost[w][j] < dist[j]) {
                    dist[j] = dist[w] + cost[w][j]; 
                    parent[j] = w;                  
                }
            }
        }
    }
}

int main() {
    int source;
    
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    
    printf("Enter the cost matrix (use 999 for infinity):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }


    printf("Enter the source vertex: ");
    scanf("%d", &source);
    
    dijkstra(source);
    
    printf("\nShortest distances from source vertex %d:\n", source);
    for (int i = 0; i < n; i++) {
        if (dist[i] == 999) {
            printf("To vertex %d: unreachable\n", i);
        } else {
            printf("To vertex %d: cost = %d  |  Path: ", i, dist[i]);
            printPath(i);
            printf("\n");
        }
    }
    
    return 0;
}
