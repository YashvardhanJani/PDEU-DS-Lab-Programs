/*
Given a stack, sort it using recursion. Use of any loop constructs like while, for, etc. is not allowed. We can only use the following functions on Stack S: 
a. isEmpty(S):   Tests whether stack is empty or not. 
b. push(S):   Adds new element to the stack. 
c. pop(S):   Removes top element from the stack. 
d. top(S):   Returns value of the top element. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Stack structure
typedef struct {
    int *arr;
    int top;
    int capacity;  // Max size of stack
} Stack;

int isEmpty(Stack* s) {
    return (s->top == -1);
}

int isFull(Stack* s) {
    return (s->top == s->capacity - 1);
}

void push(Stack* s, int val) {

    s->arr[++(s->top)] = val;
}

int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow!\n");
        return INT_MIN;
    }
    return s->arr[(s->top)--];
}

int top(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return INT_MIN;
    }
    return s->arr[s->top];
}

// Recursive function to insert element in sorted order
void insertSorted(Stack* s, int element) {
    if (isEmpty(s) || element > top(s)) {
        push(s, element);
        return;
    }
    int temp = pop(s);
    insertSorted(s, element);
    push(s, temp);
}

// Recursive function to sort stack
void sortStack(Stack* s) {
    if (!isEmpty(s)) {
        int temp = pop(s);
        sortStack(s);
        insertSorted(s, temp);
    }
}

// Function to print stack
void printStack(Stack* s) {
    if (isEmpty(s)) return;
    int x = pop(s);
    printf("%d ", x);
    printStack(s);
    push(s, x);
}


int main() {
    Stack s;
    s.top = -1;
    int choice, value;

    printf("Enter the size of the stack: ");
    scanf("%d", &s.capacity);

    if (s.capacity <= 0) {
        printf("Invalid stack size!\n");
        return 1;
    }

    // allocate memory dynamically for stack array
    s.arr = (int*) malloc(s.capacity * sizeof(int));
    if (s.arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter %d elements:\n", s.capacity);
    for (int i = 0; i < s.capacity; i++) {
        int val;
        scanf("%d", &val);
        push(&s, val);
    }

    printf("Original Stack: ");
    printStack(&s);
    printf("\n");

    sortStack(&s);

    printf("Sorted Stack: ");
    printStack(&s);
    printf("\n");

    while (1) {
        printf("\n---Stack Menu---\n");
        printf("1. Check if stack is empty\n");
        printf("2. Check if stack is full\n");
        printf("3. Push\n");
        printf("4. Pop\n");
        printf("5. Print Top\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (isEmpty(&s)) printf("Stack is empty.\n");
            else printf("Stack is not empty.\n");
            break;
        case 2:
            if (isFull(&s)) printf("Stack is full.\n");
            else printf("Stack is not full.\n");
            break;
        case 3:
            if (isFull(&s)) {
                printf("Stack Overflow!\n");
                break;
            }
            else {
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&s, value);
                printf("%d pushed to stack.\n", value);
            }    
            break;
        case 4:
            value = pop(&s);
            if (value != INT_MIN)
                printf("Popped element: %d\n", value);
            break;
        case 5:
            value = top(&s);
            if (value != INT_MIN)
                printf("Top element: %d\n", value);
            break;
        case 6:
            free(s.arr); // free allocated memory
            exit(0);
        default:
            printf("Invalid Choice!\n");
        }
    }

    return 0;
}