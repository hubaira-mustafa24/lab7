#include <stdio.h>

int main() {
    // 1. Initialize the Sales Data: 4 salesmen x 5 products
    float sales[4][5];
    float salesmanTotals[4] = {0};
    float productTotals[5] = {0};

    printf("--- Store Sales Management System ---\n");
    printf("Enter sales figures (in rupees) for each salesman across 5 products:\n\n");

    // Taking user input for each salesman and product
    for (int i = 0; i < 4; i++) {
        printf("--- Salesman %d ---\n", i + 1);
        for (int j = 0; j < 5; j++) {
            printf("Enter sales for Product %d: Rs. ", j + 1);
            scanf("%f", &sales[i][j]);
        }
        printf("\n");
    }

    // 2. Calculate Total Sales per Salesman
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            salesmanTotals[i] += sales[i][j];
        }
    }

    // 3. Calculate Total Sales per Product
    for (int j = 0; j < 5; j++) {
        for (int i = 0; i < 4; i++) {
            productTotals[j] += sales[i][j];
        }
    }

    // 4. Identify the Most Expensive (Highest Revenue) Product
    int maxProductIndex = 0;
    float maxProductSales = productTotals[0];
    for (int j = 1; j < 5; j++) {
        if (productTotals[j] > maxProductSales) {
            maxProductSales = productTotals[j];
            maxProductIndex = j;
        }
    }

    // 5. Apply Bonus for High Performers (> Rs. 10,000) & Prepare Final Amounts
    float finalAmounts[4];
    int bonusApplied[4] = {0}; // 0 = No bonus, 1 = Bonus applied

    for (int i = 0; i < 4; i++) {
        finalAmounts[i] = salesmanTotals[i];
        if (salesmanTotals[i] > 10000.0) {
            finalAmounts[i] += salesmanTotals[i] * 0.10; // Add 10% bonus
            bonusApplied[i] = 1;
        }
    }

    // 6. Display the Final Summary
    printf("\n========================================\n");
    printf("          STORE SALES SUMMARY           \n");
    printf("========================================\n");

    // Display total sales per salesman and final amounts with bonus status
    printf("\n--- Salesmen Performance ---\n");
    for (int i = 0; i < 4; i++) {
        printf("Salesman %d:\n", i + 1);
        printf("  - Initial Total Sales : Rs. %.2f\n", salesmanTotals[i]);
        if (bonusApplied[i]) {
            printf("  - Status              : High Performer! (10%% Bonus Applied)\n");
            printf("  - Final Amount        : Rs. %.2f\n", finalAmounts[i]);
        } else {
            printf("  - Status              : No Bonus (Sales <= Rs. 10,000)\n");
            printf("  - Final Amount        : Rs. %.2f\n", finalAmounts[i]);
        }
    }

    // Display total sales per product
    printf("\n--- Product Revenue Totals ---\n");
    for (int j = 0; j < 5; j++) {
        printf("Product %d Total Sales: Rs. %.2f\n", j + 1, productTotals[j]);
    }

    // Display most expensive/highest revenue product
    printf("\n--- Top Revenue Product ---\n");
    printf("Most Expensive Product : Product %d (Total Revenue: Rs. %.2f)\n", 
           maxProductIndex + 1, maxProductSales);
    printf("========================================\n");

    return 0;
}