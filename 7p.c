#include <stdio.h>

int n, m, p[10], w[10]; // Global vars: items, capacity, prices, weights

void greedy_knapsack() {
    float max, profit = 0;
    int i, j, k = 0;

    printf("Items included is:\n");
    
    // Discrete Knapsack Loop
    for (i = 0; i < n; i++) {
        max = 0;
        
        // Find the item with the highest Price/Weight ratio
        for (j = 0; j < n; j++) {
            if ((float)p[j] / w[j] > max) {
                k = j;
                max = (float)p[j] / w[j];
            }
        }

        // Check if the best item fits completely
        if (w[k] <= m) {
            printf("Item %d\n", k);
            m = m - w[k];    // Decrease capacity
            profit += p[k];  // Add to profit
            p[k] = 0;        // Mark item as used
        } else {
            break; // Item doesn't fit, stop discrete knapsack
        }
    }
    
    printf("Total profit is %f\n", profit);
    
    // Continuous (Fractional) Knapsack Step
    // Calculate the exact fraction of the item 'k' that broke the loop
    printf("Continuous knapsack also include item %d with position : %f\n", k, (float)m / w[k]);
    profit = profit + ((float)m / w[k]) * p[k];
    
    printf("Continuous knapsack profit is = %f\n", profit);
}

int main() {
    // Note: Array indexing starts from 0 in this program
    printf("Enter number of items: ");
    scanf("%d", &n);
    
    printf("Enter weights of items: ");
    for (int i = 0; i < n; i++) scanf("%d", &w[i]);
    
    printf("Enter prices of items: ");
    for (int i = 0; i < n; i++) scanf("%d", &p[i]);
    
    printf("Enter capacity of knapsack: ");
    scanf("%d", &m);
    
    greedy_knapsack();
    
    return 0;
}