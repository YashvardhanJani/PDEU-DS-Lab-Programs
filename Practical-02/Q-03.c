// Create a structure Organization with organization name and organization ID as its data members. Next, create another structure Employee that is nested in structure Organization with employee ID, employee salary and employee name as its data members. Write a program in such a way that there are two organizations and each of these contains two employees. 

#include <stdio.h>

struct Employee {
    int empID;
    float salary;
    char name[50];
};

struct Organization {
    char orgName[50];
    int orgID;
    struct Employee emp[2]; 
};

int main() {
    struct Organization org[2]; 
    int i, j;

    // Input data for organizations and employees
    for (i = 0; i < 2; i++) {
        printf("\nEnter details for Organization %d:\n", i + 1);
        printf("Organization Name: ");
        scanf(" %[^\n]", org[i].orgName);
        printf("Organization ID: ");
        scanf("%d", &org[i].orgID);

        for (j = 0; j < 2; j++) {
            printf("\nEnter details for Employee %d of Organization %d:\n", j + 1, i + 1);
            printf("Employee Name: ");
            scanf(" %[^\n]", org[i].emp[j].name);
            printf("Employee ID: ");
            scanf("%d", &org[i].emp[j].empID);
            printf("Employee Salary: ");
            scanf("%f", &org[i].emp[j].salary);
        }
    }

    // Display all data
    printf("\n----- Organization and Employee Details -----\n");
    for (i = 0; i < 2; i++) {
        printf("\nOrganization %d:\n", i + 1);
        printf("Name: %s\n", org[i].orgName);
        printf("ID: %d\n", org[i].orgID);

        for (j = 0; j < 2; j++) {
            printf("\nEmployee %d:\n", j + 1);
            printf("Name: %s\n", org[i].emp[j].name);
            printf("ID: %d\n", org[i].emp[j].empID);
            printf("Salary: %.2f\n", org[i].emp[j].salary);
        }
    }

    return 0;
}