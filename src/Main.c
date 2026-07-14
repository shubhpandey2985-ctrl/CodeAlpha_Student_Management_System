
#include <stdio.h>
#include "student.h"

static void displayMenu(void);

int main(void) {
    int choice = 0;

    while (1) {
        displayMenu();

        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            // consume invalid input
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF) {}
            continue;
        }
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) {}

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                updateStudent();
                break;
            case 5:
                deleteStudent();
                break;
            case 6:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid menu selection. Please choose 1-6.\n");
        }

        printf("\n");
    }
}

static void displayMenu(void) {
    printf("========================================\n");
    printf("      STUDENT MANAGEMENT SYSTEM\n");
    printf("========================================\n");
    printf("1. Add Student\n");
    printf("2. Display All Students\n");
    printf("3. Search Student\n");
    printf("4. Update Student\n");
    printf("5. Delete Student\n");
    printf("6. Exit\n");
    printf("========================================\n");
}

