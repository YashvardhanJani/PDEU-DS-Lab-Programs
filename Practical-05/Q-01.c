// Implement a stack using an array and using a linked list.

#include <stdio.h>
#include <stdlib.h>

// ---------------- Stack using Array ----------------
typedef struct {
    int *arr;
    int top;
    int capacity;  // Max size of stack
} ArrayStack;

int isEmptyArray(ArrayStack *s){
    return (s->top == -1);
}

int isFullArray(ArrayStack *s){
    return (s->top == s->capacity - 1);
}

void pushArray(ArrayStack *s, int value){
    if (isFullArray(s)) {
        printf("Stack Overflow! Cannot push %d\n", value);
    } else {
        s->arr[++(s->top)] = value;
        printf("%d pushed to Array Stack.\n", value);
    }
}

int popArray(ArrayStack *s){
    if (isEmptyArray(s)) {
        printf("Stack Underflow! Cannot pop.\n");
        return -1;
    } else {
        return s->arr[(s->top)--];
    }
}

void printTopArray(ArrayStack *s){
    if (isEmptyArray(s)) {
        printf("Stack is empty. No top element exists.\n");
    } else {
        printf("Top element: %d\n", s->arr[s->top]);
    }
}

// ---------------- Stack using Linked List ----------------
typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *top;
} LinkedListStack;

int isEmptyList(LinkedListStack *s){
    return (s->top == NULL);
}

void pushList(LinkedListStack *s, int value){
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
    printf("%d pushed to Linked List Stack.\n", value);
}

int popList(LinkedListStack *s){
    if (isEmptyList(s)) {
        printf("Stack Underflow! Cannot pop.\n");
        return -1;
    }
    Node *temp = s->top;
    int val = temp->data;
    s->top = s->top->next;
    free(temp);
    return val;
}

void printTopList(LinkedListStack *s){
    if (isEmptyList(s)) {
        printf("Stack is empty. No top element exists.\n");
    } else {
        printf("Top element: %d\n", s->top->data);
    }
}

// ---------------- Main ----------------
int main()
{
    int choice, value, stackType;

    printf("Choose Stack Implementation:\n");
    printf("1. Array\n");
    printf("2. Linked List\n");
    printf("Enter choice: ");
    scanf("%d", &stackType);

    if (stackType == 1) {
        ArrayStack s;
        s.top = -1;

        printf("Enter the size of the array stack: ");
        scanf("%d", &s.capacity);

        s.arr = (int*) malloc(s.capacity * sizeof(int));
        if (s.arr == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }

        while(1){
            printf("\n--- Array Stack Menu ---\n");
            printf("1. Check if stack is empty\n");
            printf("2. Check if stack is full\n");
            printf("3. Push\n");
            printf("4. Pop\n");
            printf("5. Print Top\n");
            printf("6. Exit\n");
            printf("Enter your choice: ");
            scanf("%d",&choice);

            switch(choice) {
            case 1:
                if (isEmptyArray(&s)) printf("Stack is empty.\n");
                else printf("Stack is not empty.\n");
                break;
            case 2:
                if (isFullArray(&s)) printf("Stack is full.\n");
                else printf("Stack is not full.\n");
                break;
            case 3:
                printf("Enter value to push: ");
                scanf("%d", &value);
                pushArray(&s, value);
                break;
            case 4:
                value = popArray(&s);
                if (value != -1)
                    printf("Popped element: %d\n", value);
                break;
            case 5:
                printTopArray(&s);
                break;
            case 6:
                free(s.arr);
                exit(0); 
            default:
                printf("Invalid Choice!\n"); 
            }
        }
    } 
    else if (stackType == 2) {
        LinkedListStack s;
        s.top = NULL;

        while(1){
            printf("\n--- Linked List Stack Menu ---\n");
            printf("1. Check if stack is empty\n");
            printf("2. Push\n");
            printf("3. Pop\n");
            printf("4. Print Top\n");
            printf("5. Exit\n");
            printf("Enter your choice: ");
            scanf("%d",&choice);

            switch(choice) {
            case 1:
                if (isEmptyList(&s)) printf("Stack is empty.\n");
                else printf("Stack is not empty.\n");
                break;
            case 2:
                printf("Enter value to push: ");
                scanf("%d", &value);
                pushList(&s, value);
                break;
            case 3:
                value = popList(&s);
                if (value != -1)
                    printf("Popped element: %d\n", value);
                break;
            case 4:
                printTopList(&s);
                break;
            case 5:
                exit(0); 
            default:
                printf("Invalid Choice!\n"); 
            }
        }
    } 
    else {
        printf("Invalid stack type!\n");
    }

    return 0;
}