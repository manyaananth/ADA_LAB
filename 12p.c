#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> // For the abs() function

#define N 4  // Change this to 8 for a standard 8x8 chessboard

int board[N]; // Our 1D array to store column positions for each row

// Helper function to print the chessboard visually
void printSolution() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // If the column 'j' matches the saved column for row 'i'
            if (board[i] == j)
                printf("Q "); // Print Queen
            else
                printf(". "); // Print empty space
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if placing a queen at (row, col) is safe
bool isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
        // Check for same column OR same diagonal
        if (board[i] == col || abs(board[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

// Core Backtracking function
void solveNQueens(int row) {
    // If we have placed queens in all N rows, print the board
    if (row == N) {
        printSolution();
        return;
    }

    // Try placing a queen in all columns one by one
    for (int col = 0; col < N; col++) {
        if (isSafe(row, col)) {
            board[row] = col;       // Place queen
            solveNQueens(row + 1);  // Move to the next row
        }
    }
}

int main() {
    printf("Solutions for %d-Queens problem:\n\n", N);
    
    // Start trying to place queens from row 0
    solveNQueens(0); 
    
    return 0;
}