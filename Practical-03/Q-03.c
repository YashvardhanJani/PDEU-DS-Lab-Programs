// Write a program in C to perform swapping of two numbers by passing addresses of the variables to the functions.

#include<stdio.h>

int swap(int *ptr1, int *ptr2)
{
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int main()
{
    int a,b;
    printf("Enter value of 1st number: ");
    scanf("%d",&a);
    printf("Enter value of 2st number: ");
    scanf("%d",&b);

    printf("Before swap: a = %d, b = %d", a, b);

    swap(&a,&b);

    printf("\nAfter swap: a = %d, b = %d", a, b);    

    return 0;
}