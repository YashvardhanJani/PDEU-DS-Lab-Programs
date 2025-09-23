/*
Convert the given infix expression into postfix expression using stack.
Example-    Input: 𝑎+𝑏∗(𝑐^𝑑−𝑒)^(𝑓+𝑔∗ℎ)−𝑖
            Output: 𝑎𝑏𝑐𝑑^𝑒−𝑓𝑔ℎ∗+^∗+𝑖−
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

int precedence(char op) {
    switch (op) {
        case '^': return 3;
        case '*': case '/': return 2;
        case '+': case '-': return 1;
        default: return 0;
    }
}

int isRightAssociative(char op) {
    return op == '^';
}

int isOperand(char ch) {
    return isalnum(ch);
}

void infixToPostfix(char* exp) {
    int len = strlen(exp), top = -1, j = 0;
    char result[MAX], stack[MAX];

    for (int i = 0; i < len; i++) {
        char c = exp[i];

        if (isOperand(c)) {
            result[j++] = c;
        }
        else if (c == '(') {
            stack[++top] = c;
        }
        else if (c == ')') {
            while (top != -1 && stack[top] != '(') {
                result[j++] = stack[top--];
            }
            top--; // Pop '('
        }
        else { // Operator
            while (top != -1 && stack[top] != '(' &&
                   (precedence(stack[top]) > precedence(c) ||
                   (precedence(stack[top]) == precedence(c) && !isRightAssociative(c)))) {
                result[j++] = stack[top--];
            }
            stack[++top] = c;
        }
    }
    while (top != -1) result[j++] = stack[top--];

    result[j] = '\0';
    printf("%s\n", result);
}

int main() {
    char exp[] = "a+b*(c^d-e)^(f+g*h)-i";
    printf("Original Exp: %s\n", exp);
    printf("After postfix: ");
    infixToPostfix(exp);
    return 0;
}