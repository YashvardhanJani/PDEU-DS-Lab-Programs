// Write a program in C that obtains the minimum and maximum element from the array. Modify this program to give the second largest and second smallest element of the array.

#include<stdio.h>

void min_max_second(int arr[], int n)
{
    int max1,max2,min1,min2 = 0;
    if(arr[0]>arr[1]) {
        max1 = min2 = arr[0];
        min1 = max2 = arr[1];
    } else {
        max1 = min2 = arr[1];
        max2 = min1 = arr[0];
    }
    
    for(int i=2;i<n;i++) {
        if(arr[i]>max1) {
            max2 = max1;
            max1 = arr[i];
        }
        else if(arr[i]>max2) max2 = arr[i];

        if(arr[i]<min1) {
            min2 = min1;
            min1 = arr[i];
        }
        else if(arr[i]<min2) min2 = arr[i];
    }

    printf("\nMaximum element: %d", max1);
    printf("\nMinimum element: %d", min1);
    printf("\nSecond maximum element: %d", max2);
    printf("\nSecond minimum element: %d", min2);
}

int main()
{
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements in array: ");
    for(int i=0;i<n;i++) scanf("%d", &arr[i]);

    min_max_second(arr, n);

    return 0;
}