/*  [Practical Exam - 2025 : Set 03]
Create a linked list of n numbers entered by the user. While building the list, insert each number
either at the beginning or at the end of the linked list as per your convenience.

After the list is created. read two integers A and B from the user
1. If both A and B are present in the linked list, compute A + B and append this sum at
the end of the list by creating a new node.
2. If exactly one of the two numbers is present, append the present number at the end of
the list.
3. If neither A not B is present, append 0 at the end of the list.

For Example:
Enter list: 1 → 2 → 3 → 4 → 5
Enter two numbers: 2 and 5 (Both present, so add 2 + 5 = 7 at the end)
Output: 1 → 2 → 3 → 4 → 5 → 7
Enter two numbers: 7 and 2 (Only 2 is present, so add 2 at the end)
Output: 1 → 2 → 3 → 4 → 5 → 2
Enter two numbers: 7 and 9 (Both are not present, so add 0 at the end)
Output: 1 → 2 → 3 → 4 → 5 → 0
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
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

int main() {
    struct Node* head = NULL;
    int n, value;
    int A, B;
    int foundA = 0, foundB = 0;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter list elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head = insertEnd(head, value);
    }

    printf("Linked List: ");
    display(head);

    printf("Enter two numbers A and B: ");
    scanf("%d %d", &A, &B);

    // Check presence of A and B
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == A)
            foundA = 1;
        if (temp->data == B)
            foundB = 1;
        temp = temp->next;
    }

    // Apply conditions
    if (foundA && foundB) {
        head = insertEnd(head, A + B);
    }
    else if (foundA) {
        head = insertEnd(head, A);
    }
    else if (foundB) {
        head = insertEnd(head, B);
    }
    else {
        head = insertEnd(head, 0);
    }

    printf("Updated Linked List: ");
    display(head);

    return 0;
}