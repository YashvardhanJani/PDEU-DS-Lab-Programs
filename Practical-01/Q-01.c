// Write a program in C to perform linear and binary search.

#include<stdio.h>

// Linear Search
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) return i; // Return index if found
    }
    return -1; // Not found
}

// Binary Search (Array must be sorted)
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    
    while (low <= high) {
        int mid = (low + high) / 2;
        
        if (arr[mid] == key) {
            return mid; // Found
        }
        else if (arr[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1; // Not found
}

int main() {
    int n, key, result;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    
    printf("\nEnter %d elements (for Linear Search): ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter element to search: ");
    scanf("%d", &key);
    
    result = linearSearch(arr, n, key);

    if (result != -1) {
        printf("Element found at position %d (index %d) using Linear Search.\n", result + 1, result);
    }
    else {
        printf("Element not found.\n");
    } 

    printf("\nEnter %d elements (for Binary Search, enter in sorted order): ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter element to search: ");
    scanf("%d", &key);

    result = binarySearch(arr, n, key);
    
    if (result != -1) {
        printf("Element found at position %d (index %d) using Binary Search.\n", result + 1, result);
    }
    else {
        printf("Element not found.\n");
    }
    
    return 0;
}
