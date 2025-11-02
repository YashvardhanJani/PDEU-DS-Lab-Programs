// Given a preorder traversal sequence of a Binary Search Tree, construct the corresponding Binary Search Tree. 

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Node* constructBST(int preorder[], int* preIndex, int key, int min, int max, int size) {
    if (*preIndex >= size)
        return NULL;

    struct Node* root = NULL;

    // If current key lies within valid range, it belongs to this subtree
    if (key > min && key < max) {
        root = newNode(key);
        (*preIndex)++;

        if (*preIndex < size) {
            // Construct left and right subtrees recursively
            root->left = constructBST(preorder, preIndex, preorder[*preIndex], min, key, size);
            root->right = constructBST(preorder, preIndex, preorder[*preIndex], key, max, size);
        }
    }

    return root;
}

void inorder(struct Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int preorder[n];
    printf("Enter preorder traversal sequence: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &preorder[i]);

    int preIndex = 0;
    struct Node* root = constructBST(preorder, &preIndex, preorder[0], INT_MIN, INT_MAX, n);

    printf("\nInorder traversal of constructed BST: ");
    inorder(root);
    printf("\n");

    return 0;
}