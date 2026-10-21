#include <stdio.h>

int main() {
    int grid[3][3];
    int isValid = 1; // Flag to track if the grid is valid (1 = True, 0 = False)

    printf("--- Sudoku Grid Validation System ---\n");
    printf("Enter values for the 3x3 Sudoku grid (0 for empty, 1-9 for filled):\n");

    // 1. Initialize the Sudoku Grid (Take user input)
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Enter value for cell [%d][%d]: ", i, j);
            scanf("%d", &grid[i][j]);
        }
    }

    // 2. Validate the Number Range (1-9 for filled cells, 0 allowed for empty cells)
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i][j] < 0 || grid[i][j] > 9) {
                isValid = 0; // Out of range
            }
        }
    }

    // 3. Check for Duplicate Numbers (comparing each filled cell with every other filled cell)
    if (isValid) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                // Ignore empty cells (0)
                if (grid[i][j] == 0) {
                    continue;
                }

                // Compare with all other cells
                for (int r = 0; r < 3; r++) {
                    for (int c = 0; c < 3; c++) {
                        // Skip comparing the exact same cell position
                        if (i == r && j == c) {
                            continue;
                        }

                        // If a duplicate of a non-zero number is found
                        if (grid[i][j] == grid[r][c]) {
                            isValid = 0;
                        }
                    }
                }
            }
        }
    }

    // 4. Display the Validation Result
    printf("\n----------------------------------------\n");
    if (isValid) {
        printf("Validation Result: Valid Grid\n");
    } else {
        printf("Validation Result: Invalid Grid\n");
    }
    printf("----------------------------------------\n");

    return 0;
}