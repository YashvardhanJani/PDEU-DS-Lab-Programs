// Write a program in C to implement arrays of pointers and pointers to an arrays.

#include <stdio.h>

int main() {

    printf("\n----- Part 1: Arrays of Pointers -----\n");
    int var1 = 10;
    int var2 = 20;
    int var3 = 30;

    // array of pointers to integers
    int* arrs_of_ptrs[3] = {&var1, &var2, &var3};

    for (int i = 0; i < 3; i++) {
        printf("Value of var%d: %d\tAddress: %p\n", i + 1, *arrs_of_ptrs[i], arrs_of_ptrs[i]);
    }


    printf("\n----- Part 2: Pointers to an Arrays -----\n");
    int arr[3] = {5, 10, 15};

    // Declare pointer variable
    int (*ptrs_to_arrs)[3];
    ptrs_to_arrs = &arr;
	
  	for (int i = 0; i < 3; i++) {
      printf("Value: %d\tAddress: %p\n", (*ptrs_to_arrs)[i], (ptrs_to_arrs)[i]);
    }  

    printf("\n\n----- Pointer of an Array -----\n");

    int *ptr_of_arr = &arr[0];
    for (int i = 0; i < 3; i++) {
      printf("Value: %d\tAddress: %p\n",*(ptr_of_arr+i), (ptr_of_arr));
    }  
    printf("\n");
    return 0;
}