/* Study and implement the Binary Tree and perform following three types of traversals 
in a binary tree: 
a. Pre-order Traversal 
b. In-order Traversal 
c. Post-order Traversal */

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

void inorder(struct Node* root) {
    if(root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);

    }
}

void postorder(struct Node* root) {
    if(root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct Node* root = createNode(10);
    insert(root, 30, 'L');
    insert(root, 40, 'R');
    insert(root->left, 80, 'L');
    insert(root->left, 90, 'R');
    insert(root->right, 50, 'L');
    insert(root->right, 70, 'R');

    printf("Preorder: ");
    preorder(root);
    printf("\nInorder: ");
    inorder(root);
    printf("\nPostorder: ");
    postorder(root);

    return 0;
}