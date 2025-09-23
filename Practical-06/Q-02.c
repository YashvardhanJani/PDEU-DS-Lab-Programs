/*
Write a program to evaluate the following given postfix expressions: 
a. 2 3 1 ∗ + 9 −        Output: -4 
b. 2 2 + 2 / 5 ∗ 7 +    Output: 17
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

int stack[MAX], top = -1;

void push(int val) {
    stack[++top] = val;
}

int pop() {
    return stack[top--];
}

int evaluatePostfix(char* expr) {
    char *token = strtok(expr, " ");
    while (token != NULL) {
        if (isdigit(token[0])) {
            push(atoi(token));
        } else {
            int b = pop();
            int a = pop();
            switch(token[0]) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
            }
        }
        token = strtok(NULL, " ");
    }
    return pop();
}

int main() {
    char expr1[] = "2 3 1 * + 9 -";
    char expr2[] = "2 2 + 2 / 5 * 7 +";

    printf("Exp1: %s\n", expr1);
    printf("Result 1: %d\n", evaluatePostfix(expr1)); // Output: -4
    printf("Exp2: %s\n", expr2);
    printf("Result 2: %d\n", evaluatePostfix(expr2)); // Output: 17
    return 0;
}