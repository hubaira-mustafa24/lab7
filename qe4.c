#include <stdio.h>

int main() {
    // 1. Initialize the 3D Temperature Data (3 x 3 x 3 cube)
    // Dimensions: [layer (z)][x][y]
    float temp[3][3][3];
    float layerAverages[3] = {0.0};
    
    // Variables to track the maximum temperature point
    float maxTemp;
    int maxX = 0, maxY = 0, maxZ = 0;

    printf("--- Greenhouse Temperature Monitoring System ---\n");
    printf("Enter temperature values (in Celsius) for each point in the 3x3x3 greenhouse:\n\n");

    // Take user input for each point using three nested loops (z, x, y)
    for (int z = 0; z < 3; z++) {
        printf("--- Layer %d (Z = %d) ---\n", z + 1, z + 1);
        for (int x = 0; x < 3; x++) {
            for (int y = 0; y < 3; y++) {
                printf("Enter temperature for coordinate [%d][%d][%d]: ", x + 1, y + 1, z + 1);
                scanf("%f", &temp[z][x][y]);

                // Track max temperature during input initialization
                if (z == 0 && x == 0 && y == 0) {
                    maxTemp = temp[z][x][y];
                    maxX = x + 1;
                    maxY = y + 1;
                    maxZ = z + 1;
                } else if (temp[z][x][y] > maxTemp) {
                    maxTemp = temp[z][x][y];
                    maxX = x + 1;
                    maxY = y + 1;
                    maxZ = z + 1;
                }
            }
        }
        printf("\n");
    }

    // 2. Calculate Average Temperature per Layer (a 3x3 slice along the z-axis)
    for (int z = 0; z < 3; z++) {
        float layerSum = 0.0;
        for (int x = 0; x < 3; x++) {
            for (int y = 0; y < 3; y++) {
                layerSum += temp[z][x][y];
            }
        }
        layerAverages[z] = layerSum / 9.0; // Sum of 9 values divided by 9
    }

    // 3. Identify the Hottest Layer
    int hottestLayer = 0;
    float highestLayerAvg = layerAverages[0];
    for (int z = 1; z < 3; z++) {
        if (layerAverages[z] > highestLayerAvg) {
            highestLayerAvg = layerAverages[z];
            hottestLayer = z;
        }
    }

    // 4. Display the Final Results
    printf("\n========================================\n");
    printf("      GREENHOUSE MONITORING SUMMARY     \n");
    printf("========================================\n");

    // Display average temperature of each layer
    printf("\n--- Layer Average Temperatures ---\n");
    for (int z = 0; z < 3; z++) {
        printf("Layer %d Average Temperature : %.2f °C\n", z + 1, layerAverages[z]);
    }

    // Display the hottest layer
    printf("\n--- Hottest Layer Identification ---\n");
    printf("Hottest Layer               : Layer %d (Average: %.2f °C)\n", 
           hottestLayer + 1, highestLayerAvg);

    // Display maximum temperature value and coordinates
    printf("\n--- Maximum Temperature Point ---\n");
    printf("Highest Temperature         : %.2f °C\n", maxTemp);
    printf("Coordinates (X, Y, Z)       : (%d, %d, %d)\n", maxX, maxY, maxZ);
    printf("========================================\n");

    return 0;
}