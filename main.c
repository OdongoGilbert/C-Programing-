#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

// Define a structure to represent a student
struct Student {
    char name[50];
    char regNumber[10];
    int grades[5];
    float average;
};

int main() {
    // Create an array to store information for 5 students
    struct Student students[5];

    // Input information for 5 students
    for (int i = 0; i < 5; i++) {
        printf("Enter name for student %d: ", i + 1);
        scanf("%s", students[i].name);

        printf("Enter registration number for student %d: ", i + 1);
        scanf("%s", students[i].regNumber);

        printf("Enter grades for 5 units for student %d:\n", i + 1);
        for (int j = 0; j < 5; j++) {
            printf("Grade for Unit %d: ", j + 1);
            scanf("%d", &students[i].grades[j]);
        }
    }

    // Calculate the average grade for each student
    for (int i = 0; i < 5; i++) {
        int sum = 0;
        for (int j = 0; j < 5; j++) {
            sum += students[i].grades[j];
        }
        students[i].average = (float)sum / 5;
    }

    // Find and display the highest and lowest grades
    int highest = students[0].grades[0];
    int lowest = students[0].grades[0];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (students[i].grades[j] > highest) {
                highest = students[i].grades[j];
            }
            if (students[i].grades[j] < lowest) {
                lowest = students[i].grades[j];
            }
        }
    }
    printf("Highest Grade: %d\n", highest);
    printf("Lowest Grade: %d\n", lowest);

    // Search for a specific student's grade by registration number
    char searchRegNumber[10];
    printf("Enter a registration number to search for a student: ");
    scanf("%s", searchRegNumber);
    for (int i = 0; i < 5; i++) {
        if (strcmp(students[i].regNumber, searchRegNumber) == 0) {
            printf("Student found!\n");
            printf("Name: %s\n", students[i].name);
            printf("Registration Number: %s\n", students[i].regNumber);
            printf("Grades for 5 units:\n");
            for (int j = 0; j < 5; j++) {
                printf("Unit %d: %d\n", j + 1, students[i].grades[j]);
            }
            printf("Average Grade: %.2f\n", students[i].average);
            break;
        }
    }

    return 0;
}

