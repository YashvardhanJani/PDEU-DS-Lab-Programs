/*
Given an expression, write a program to examine whether the pairs and the orders of 
“{“, “}”, “(“, “)”, “[“, “]” are correct in the expression or not. 
Example:    Input: exp = “[( )]{ }{[( )( )]( )}”    Output: Balanced 
            Input: exp = “[( ])”                    Output: Not Balanced
*/

#include <stdio.h>
#include <string.h>

#define MAX 100

int isMatchingPair(char left, char right) {
    return (left == '(' && right == ')') ||
           (left == '{' && right == '}') ||
           (left == '[' && right == ']');
}

int isBalanced(char* expr) {
    char stack[MAX];
    int top = -1, i, len = strlen(expr);

    for (i = 0; i < len; i++) {
        char c = expr[i];
        if (c == '(' || c == '{' || c == '[')
            stack[++top] = c;
        else if (c == ')' || c == '}' || c == ']') {
            if (top == -1)
                return 0; // Unmatched closing
            if (!isMatchingPair(stack[top--], c))
                return 0; // Mismatched pair
        }
        // Ignore other characters (spaces, etc.)
    }
    return top == -1; // True if stack is empty
}

int main() {
    char expr1[] = "[( )]{ }{[( )( )]( )}";
    char expr2[] = "[( ])";

    printf("Input: %s\nOutput: %s\n", expr1, isBalanced(expr1) ? "Balanced" : "Not Balanced");
    printf("Input: %s\nOutput: %s\n", expr2, isBalanced(expr2) ? "Balanced" : "Not Balanced");
    return 0;
}