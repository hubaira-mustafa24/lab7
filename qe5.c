#include <stdio.h>

int main() {
    // 1. Initialize the Marks Data: 2 classes, 3 students each, 3 subjects each
    // Dimensions: [class][student][subject]
    int marks[2][3][3];
    int studentTotals[2][3] = {0};

    printf("--- Class Performance Management System ---\n");
    printf("Enter marks for each student across 3 subjects for 2 classes:\n\n");

    // Take user input using three nested loops
    for (int c = 0; c < 2; c++) {
        printf("=== Class %d ===\n", c + 1);
        for (int s = 0; s < 3; s++) {
            printf("  -- Student %d --\n", s + 1);
            for (int sub = 0; sub < 3; sub++) {
                printf("    Enter marks for Subject %d: ", sub + 1);
                scanf("%d", &marks[c][s][sub]);
            }
        }
        printf("\n");
    }

    // 2. Calculate Total Marks per Student
    for (int c = 0; c < 2; c++) {
        for (int s = 0; s < 3; s++) {
            for (int sub = 0; sub < 3; sub++) {
                studentTotals[c][s] += marks[c][s][sub];
            }
        }
    }

    // 3. Identify the Class Topper for each class
    int classTopperIndex[2]; // Stores student index (0-2) for each class
    for (int c = 0; c < 2; c++) {
        int maxIndex = 0;
        int maxMarks = studentTotals[c][0];
        
        for (int s = 1; s < 3; s++) {
            if (studentTotals[c][s] > maxMarks) {
                maxMarks = studentTotals[c][s];
                maxIndex = s;
            }
        }
        classTopperIndex[c] = maxIndex;
    }

    // 4. Identify the Overall Topper across all classes
    int overallTopClass = 0;
    int overallTopStudent = 0;
    int maxOverallMarks = studentTotals[0][0];

    for (int c = 0; c < 2; c++) {
        for (int s = 0; s < 3; s++) {
            if (studentTotals[c][s] > maxOverallMarks) {
                maxOverallMarks = studentTotals[c][s];
                overallTopClass = c;
                overallTopStudent = s;
            }
        }
    }

    // 5. Display the Final Results
    printf("\n========================================\n");
    printf("      CLASS PERFORMANCE SUMMARY         \n");
    printf("========================================\n");

    // Display total marks for each student
    printf("\n--- Student Total Marks ---\n");
    for (int c = 0; c < 2; c++) {
        printf("Class %d:\n", c + 1);
        for (int s = 0; s < 3; s++) {
            printf("  - Student %d Total Marks: %d\n", s + 1, studentTotals[c][s]);
        }
    }

    // Display the topper of each class in the requested format
    printf("\n--- Class Toppers ---\n");
    for (int c = 0; c < 2; c++) {
        int topStudentNum = classTopperIndex[c] + 1;
        int topMarks = studentTotals[c][classTopperIndex[c]];
        printf("Top Performer of Class %d: Student %d with %d marks\n", 
               c + 1, topStudentNum, topMarks);
    }

    // Display the overall topper
    printf("\n--- Overall Topper ---\n");
    printf("Overall Top Performer: Student %d from Class %d with %d marks\n", 
           overallTopStudent + 1, overallTopClass + 1, maxOverallMarks);
    printf("========================================\n");

    return 0;
}