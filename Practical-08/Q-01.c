// Write a program to insert an element, delete an element and search an element in the Binary Tree. 

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data, char side) {
    if(root == NULL) return NULL;

    if(side == 'L') {
        root->left = createNode(data);
    }
    else if(side == 'R') {
        root->right = createNode(data); 
    }
    else {
        printf("Enter valid side!\n");
    }
}    

void preorder(struct Node* root) {
    if(root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);

    }
}

int main() {
    struct Node* root = createNode(7);
    insert(root, 30, 'L');
    insert(root, 40, 'R');
    insert(root->left, 80, 'L');
    insert(root->left, 90, 'R');

    printf("Preorder: ");
    preorder(root);

    return 0;
}