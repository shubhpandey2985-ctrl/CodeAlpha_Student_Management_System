#include "student.h"

#include "file_handler.h"
#include "utils.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifdef _WIN32
#include <direct.h>
#endif

#define DATA_FILE "data/students.dat"


#define TEMP_FILE "data/students_tmp.dat"

static void ensureDataDir(void) {
#ifdef _WIN32
    // Best-effort create folder on Windows
    (void)_mkdir("data");
#else
    // Best-effort create folder on POSIX
    (void)mkdir("data", 0755);
#endif
}


static int studentIdExists(int id) {
    if (!fileExists(DATA_FILE)) return 0;

    FILE *fp = openFile(DATA_FILE, "rb");
    if (!fp) return 0;

    Student s;
    while (fread(&s, sizeof(Student), 1, fp) == 1) {
        if (s.studentId == id) {
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);
    return 0;
}

void addStudent(void) {
    ensureDataDir();

    Student s;

    printf("--- Add Student ---\n");

    while (1) {
        if (!readInt("Student ID (unique int): ", &s.studentId)) {
            printf("Invalid Student ID. Please enter an integer.\n");
            continue;
        }
        if (studentIdExists(s.studentId)) {
            printf("Duplicate Student ID. A student with ID %d already exists.\n", s.studentId);
            continue;
        }
        break;
    }

    while (!readString("Student Name: ", s.name, sizeof(s.name))) {
        printf("Name cannot be empty. Try again.\n");
    }

    while (1) {
        if (!readInt("Age (int): ", &s.age)) {
            printf("Invalid age. Please enter an integer.\n");
            continue;
        }
        if (s.age < 0) {
            printf("Age cannot be negative.\n");
            continue;
        }
        break;
    }

    while (!readString("Gender: ", s.gender, sizeof(s.gender))) {
        printf("Gender cannot be empty. Try again.\n");
    }

    while (!readString("Course: ", s.course, sizeof(s.course))) {
        printf("Course cannot be empty. Try again.\n");
    }

    while (1) {
        if (!readFloat("Marks (float): ", &s.marks)) {
            printf("Invalid marks. Please enter a number.\n");
            continue;
        }
        break;
    }

    FILE *fp = openFile(DATA_FILE, "ab");
    if (!fp) {
        printf("Error: Could not open data file for writing.\n");
        return;
    }

    if (fwrite(&s, sizeof(Student), 1, fp) != 1) {
        printf("Error: Failed to write student record.\n");
    } else {
        printf("Student added successfully.\n");
    }

    fclose(fp);
}

void displayStudents(void) {
    printf("--- Display All Students ---\n");

    FILE *fp = openFile(DATA_FILE, "rb");
    if (!fp) {
        printf("No students found (data file missing).\n");
        return;
    }

    Student s;
    int found = 0;

    printf("\n%-10s %-20s %-5s %-10s %-25s %-10s\n", "ID", "Name", "Age", "Gender", "Course", "Marks");
    printf("----------------------------------------------------------------------------------------------\n");

    while (fread(&s, sizeof(Student), 1, fp) == 1) {
        found = 1;
        printf("%-10d %-20s %-5d %-10s %-25s %-10.2f\n",
               s.studentId, s.name, s.age, s.gender, s.course, s.marks);
    }

    if (!found) {
        printf("No students stored.\n");
    }

    fclose(fp);
}

void searchStudent(void) {
    int id = 0;

    printf("--- Search Student ---\n");
    if (!readInt("Enter Student ID to search: ", &id)) {
        printf("Invalid ID input.\n");
        return;
    }

    FILE *fp = openFile(DATA_FILE, "rb");
    if (!fp) {
        printf("Student record not found.\n");
        return;
    }

    Student s;
    while (fread(&s, sizeof(Student), 1, fp) == 1) {
        if (s.studentId == id) {
            printf("\nStudent record found:\n");
            printf("ID: %d\n", s.studentId);
            printf("Name: %s\n", s.name);
            printf("Age: %d\n", s.age);
            printf("Gender: %s\n", s.gender);
            printf("Course: %s\n", s.course);
            printf("Marks: %.2f\n", s.marks);
            fclose(fp);
            return;
        }
    }

    fclose(fp);
    printf("Student record not found.\n");
}

void updateStudent(void) {
    ensureDataDir();

    int id = 0;

    printf("--- Update Student ---\n");
    if (!readInt("Enter Student ID to update: ", &id)) {
        printf("Invalid ID input.\n");
        return;
    }

    FILE *fp = openFile(DATA_FILE, "rb");
    if (!fp) {
        printf("Student record not found.\n");
        return;
    }

    FILE *tmp = openFile(TEMP_FILE, "wb");
    if (!tmp) {
        printf("Error: Could not create temporary file.\n");
        fclose(fp);
        return;
    }

    Student s;
    int updated = 0;

    while (fread(&s, sizeof(Student), 1, fp) == 1) {
        if (s.studentId == id) {
            printf("Student found. Enter new details.\n");

            // Keep ID immutable
            s.studentId = id;

            while (!readString("Student Name: ", s.name, sizeof(s.name))) {
                printf("Name cannot be empty. Try again.\n");
            }

            while (1) {
                if (!readInt("Age: ", &s.age)) {
                    printf("Invalid age. Please enter an integer.\n");
                    continue;
                }
                if (s.age < 0) {
                    printf("Age cannot be negative.\n");
                    continue;
                }
                break;
            }

            while (!readString("Gender: ", s.gender, sizeof(s.gender))) {
                printf("Gender cannot be empty. Try again.\n");
            }

            while (!readString("Course: ", s.course, sizeof(s.course))) {
                printf("Course cannot be empty. Try again.\n");
            }

            while (1) {
                if (!readFloat("Marks: ", &s.marks)) {
                    printf("Invalid marks. Please enter a number.\n");
                    continue;
                }
                break;
            }

            updated = 1;
        }

        if (fwrite(&s, sizeof(Student), 1, tmp) != 1) {
            printf("Error: Failed to write to temporary file.\n");
            fclose(fp);
            fclose(tmp);
            remove(TEMP_FILE);
            return;
        }
    }

    fclose(fp);
    fclose(tmp);

    if (!updated) {
        remove(TEMP_FILE);
        printf("Student record not found.\n");
        return;
    }

    if (remove(DATA_FILE) != 0) {
        printf("Error: Could not remove old data file.\n");
        return;
    }

    if (rename(TEMP_FILE, DATA_FILE) != 0) {
        printf("Error: Could not rename temporary file to data file.\n");
        return;
    }

    printf("Student updated successfully.\n");
}

void deleteStudent(void) {
    ensureDataDir();

    int id = 0;

    printf("--- Delete Student ---\n");
    if (!readInt("Enter Student ID to delete: ", &id)) {
        printf("Invalid ID input.\n");
        return;
    }

    FILE *fp = openFile(DATA_FILE, "rb");
    if (!fp) {
        printf("Student record not found.\n");
        return;
    }

    FILE *tmp = openFile(TEMP_FILE, "wb");
    if (!tmp) {
        printf("Error: Could not create temporary file.\n");
        fclose(fp);
        return;
    }

    Student s;
    int deleted = 0;

    while (fread(&s, sizeof(Student), 1, fp) == 1) {
        if (s.studentId == id) {
            deleted = 1;
            continue; // skip record
        }

        if (fwrite(&s, sizeof(Student), 1, tmp) != 1) {
            printf("Error: Failed to write to temporary file.\n");
            fclose(fp);
            fclose(tmp);
            remove(TEMP_FILE);
            return;
        }
    }

    fclose(fp);
    fclose(tmp);

    if (!deleted) {
        remove(TEMP_FILE);
        printf("Student record not found.\n");
        return;
    }

    if (remove(DATA_FILE) != 0) {
        printf("Error: Could not remove old data file.\n");
        return;
    }

    if (rename(TEMP_FILE, DATA_FILE) != 0) {
        printf("Error: Could not rename temporary file to data file.\n");
        return;
    }

    printf("Student deleted successfully.\n");
}

