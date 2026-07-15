#include <stdio.h>
#define INF 999
#define MAX 20

int parent[MAX];
int find(int x) {
    while (parent[x] != 0) {
        x = parent[x];
    }
    return x;
}

int main() {
    int n, cost[MAX][MAX];
    int i, j, edges = 0, sum = 0;
    
    printf("\nEnter the n value: ");
    scanf("%d", &n);
    
    printf("\nEnter the graph data: \n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }
    
    printf("\n Edge of spanning tree are: \n");
    while (edges < n - 1) {
        int min = INF, a = -1, b = -1;
        
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                    if (i != j && cost[i][j] < min && find(i) != find(j)) {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }
        
        parent[find(b)] = find(a);
        
        printf("%d -> %d\n", a, b);
        sum += min;
        edges++; 
    }
    
    printf("\n Cost of spanning tree is %d\n", sum);
    return 0;
}

