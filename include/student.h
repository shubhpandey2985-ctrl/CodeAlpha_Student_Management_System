#ifndef STUDENT_H
#define STUDENT_H

#include <stddef.h>

typedef struct {
    int studentId;
    char name[50];
    int age;
    char gender[10];
    char course[50];
    float marks;
} Student;

void addStudent(void);
void displayStudents(void);
void searchStudent(void);
void updateStudent(void);
void deleteStudent(void);

#endif /* STUDENT_H */

