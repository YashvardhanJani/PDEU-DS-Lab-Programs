/*  [Practical Exam - 2025 : Set 01]
Create a linked list of n numbers entered by the user. While building the list, insert each number
either at the beginning or at the end of the linked list as per your convenience.

After the list is created:
1. Take two numbers from the user.
2. Check whether both numbers exist in the linked list.
3. If both are present, swap their positions within the list and print the updated linked list.
4. If one or both numbers are missing, print "Swap Not Possible".

For Example:
Enter list: 1 → 2 → 3 → 4 → 5
Enter tWo numbers: 2 and 4
Output: 1 → 4 → 3 → 2 → 5
Enter two numbers: 2 and 7
Output: Swap Not Possible

Note: Do not simply swap the INFO part, you have to swap using the LINK part. That means
the link of2 should point to 5 (link of 4 earlier) and link of4 should point to 3 (link of 2 earlier).
Also, link of 1 (earlier pointing to 2) should point to 4 and link of 3 (earlier pointing to 4)
should point to 2.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

void display(struct Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL)
            printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

// Swap nodes by changing links
struct Node* swapNodes(struct Node* head, int x, int y) {
    if (x == y)
        return head;

    struct Node *prevX = NULL, *currX = head;
    struct Node *prevY = NULL, *currY = head;

    // Search for x
    while (currX != NULL && currX->data != x) {
        prevX = currX;
        currX = currX->next;
    }

    // Search for y
    while (currY != NULL && currY->data != y) {
        prevY = currY;
        currY = currY->next;
    }

    // If either not found
    if (currX == NULL || currY == NULL) {
        printf("Swap Not Possible\n");
        return head;
    }

    // If x is not head
    if (prevX != NULL)
        prevX->next = currY;
    else
        head = currY;

    // If y is not head
    if (prevY != NULL)
        prevY->next = currX;
    else
        head = currX;

    // Swap next pointers
    struct Node* temp = currX->next;
    currX->next = currY->next;
    currY->next = temp;

    return head;
}

int main() {
    struct Node* head = NULL;
    int n, value, x, y;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter list elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head = insertEnd(head, value);
    }

    printf("Linked List: ");
    display(head);

    printf("Enter two numbers to swap: ");
    scanf("%d %d", &x, &y);

    head = swapNodes(head, x, y);

    if (head != NULL) {
        printf("Updated Linked List: ");
        display(head);
    }

    return 0;
}