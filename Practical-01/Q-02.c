// Write a program in C to perform bubble sort, insertion sort and selection sort. Take the array size and array elements from user.

#include<stdio.h>

void bubble_sort(int arr[], int n)
{
    for(int i=n-1;i>=1;i--){
        int didSwap = 0;          // Optimization if array is sorted
        for(int j=0;j<=i-1;j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
                didSwap = 1;
            }
        }
        if(didSwap == 0) break;   // overcome unnecessary looping
    }
}

void insertion_sort(int arr[], int n)
{
    for(int i=0;i<=n-1;i++){
        int j = i;
        while(j>0 && arr[j-1]>arr[j]){
            int temp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
}

void selection_sort(int arr[], int n)
{
    for(int i=0;i<=n-2;i++){
        int min = i;
        for(int j=i;j<=n-1;j++){
            if(arr[j]<arr[min]){
                min = j;
            }
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

int main()
{
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements in array: ");
    for(int i=0;i<n;i++) scanf("%d", &arr[i]);

    bubble_sort(arr, n);
    printf("\nAfter Using Bubble Sort: ");
    for(int i=0;i<n;i++) printf("%d ",arr[i]);

    insertion_sort(arr, n);
    printf("\nAfter Using Insertion Sort: ");
    for(int i=0;i<n;i++) printf("%d ",arr[i]);

    selection_sort(arr, n);
    printf("\nAfter using Selection Sort: ");
    for(int i=0;i<n;i++) printf("%d ",arr[i]);

    return 0;
}