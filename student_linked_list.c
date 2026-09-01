#include <stdlib.h>
#include <stdio.h>

typedef struct Student {
    char* name;
    int roll_no;
    int mob_no;
    struct Student* next;
} student_t;

student_t* first_student = NULL;

void create_student(char name[], int roll_no, int mob_no) {
    student_t student_raw = {name, roll_no, mob_no, NULL};

    student_t* student = malloc(sizeof(student_raw));
    *student = student_raw;

    if (first_student == NULL) {
        first_student = student;
        return;
    }

    student_t* temp = first_student;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = student;
}

int insert_student(char name[], int roll_no, int mob_no, int position) {
    student_t student_raw = {name, roll_no, mob_no, NULL};

    student_t* student = malloc(sizeof(student_raw));
    *student = student_raw;

    if (position == 1) {
        student->next = first_student;
        first_student = student;
        return 1;
    }

    student_t* temp = first_student;

    for (int i = 2; i < position; i++) {
        if (!temp->next) return -1;

        temp = temp->next;
    }

    student->next = temp->next;
    temp->next = student;
    return 1;
}

void reverse_students() {
    student_t* prev = NULL;
    student_t* current = first_student;
    student_t* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    first_student = prev;      
}

int delete_student(int roll_no) {
    if (first_student == NULL) return -1;

    student_t* temp = first_student;

    if (first_student->roll_no == roll_no) {
        first_student = temp->next;
        free(temp);
        return 1;
    }

    while (1) {
        if (temp->next == NULL) return -1;

        if (temp->next->roll_no == roll_no) {
            student_t* delete = temp->next;
            temp->next = delete->next;
            free(delete);
            return 1;
        }

        temp = temp->next;
    }
}

void display_students() {
    printf("------------- DISPLAYING STUDENTS -----------\n");

    student_t* temp = first_student;

    while (temp != NULL) {
        printf("Name: %s\n", temp->name);
        printf("Roll Number: %d\n", temp->roll_no);
        printf("Mobile Number: %d\n", temp->mob_no);
        printf("---------------------------\n");

        temp = temp->next;
    }
}

int main() {
    create_student("Ramesh", 1, 119191);
    create_student("Suresh", 2, 1231234);
    create_student("Hrigved", 3, 134134);

    display_students();
    insert_student("Ayush", 5, 15123, 2);
    display_students();
    delete_student(3);
    display_students();
    reverse_students();
    display_students();
}