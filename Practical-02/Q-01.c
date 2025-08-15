// Create a structure Student in C with student name, student roll number and student address as its data members. Create the variable of type student and print the values.

#include <stdio.h>
#include <string.h> // For strcpy

// Define structure
struct Student {
    char name[50];
    int rollNumber;
    char address[100];
} s1, s2, s3;

int main() {

    strcpy(s1.name, "Shyam");
    s1.rollNumber = 101;
    strcpy(s1.address, "Rajkot");


    strcpy(s2.name, "Ramesh");
    s2.rollNumber = 102;
    strcpy(s2.address, "Jamnagar");


    strcpy(s3.name, "Indrajeet");
    s3.rollNumber = 103;
    strcpy(s3.address, "Bhuj");

    printf("---- Student Details ----\n");
    printf("\nName: %s ; Roll Number: %d ; Address: %s\n", s1.name, s1.rollNumber, s1.address);
    printf("\nName: %s ; Roll Number: %d ; Address: %s\n", s2.name, s2.rollNumber, s2.address);
    printf("\nName: %s ; Roll Number: %d ; Address: %s\n\n", s3.name, s3.rollNumber, s3.address);

    return 0;
}
