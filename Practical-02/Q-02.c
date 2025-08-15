// Modify the above program to implement arrays of structure. Create an array of 5 students and print their values.

#include <stdio.h>
#include <string.h> // for strcspn to remove newline

// Define structure
struct Student {
    char name[50];
    int rollNumber;
    char address[100];
};

int main() {
    struct Student s[5]; // Array of 5 students

    // Input student details
    for (int i = 0; i < 5; i++) {
        printf("\nEnter student %d name: ", i + 1);
        fgets(s[i].name, sizeof(s[i].name), stdin);
        s[i].name[strcspn(s[i].name, "\n")] = 0; // remove newline

        printf("Enter roll number: ");
        scanf("%d", &s[i].rollNumber);
        getchar(); // consume leftover newline

        printf("Enter address: ");
        fgets(s[i].address, sizeof(s[i].address), stdin);
        s[i].address[strcspn(s[i].address, "\n")] = 0; // remove newline
    }

    // Output student details
    printf("\n---- Student Details ----\n");
    for (int i = 0; i < 5; i++) {
        printf("\nStudent %d Name: %s\n", i + 1, s[i].name);
        printf("Roll Number: %d\n", s[i].rollNumber);
        printf("Address: %s\n", s[i].address);
    }

    return 0;
}