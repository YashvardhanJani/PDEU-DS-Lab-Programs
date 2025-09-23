// Write a program in C to implement pointers to structures.

#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int roll;
    float pr;
};

int main() {

    struct Student s1;

    printf("\nEnter Student Name: ");
    fgets(s1.name, sizeof(s1.name), stdin);
    s1.name[strcspn(s1.name, "\n")] = 0;

    printf("Enter Roll Number: ");
    scanf("%d", &s1.roll);

    printf("Enter Percentile(PR): ");
    scanf("%f", &s1.pr);

    // Declare a pointer to structure
    struct Student *ptr;

    // Assign address of s1 to ptr
    ptr = &s1;

    // Access structure members using the pointer
    printf("\nAccessing members using pointer to structure:\n");
    printf("Name  : %s\n", ptr->name);
    printf("Roll  : %d\n", ptr->roll);
    printf("Marks : %.2f\n\n", ptr->pr);

    return 0;
}