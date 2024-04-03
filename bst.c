#include <stdio.h>
#include <stdlib.h>

// Definition of a tree node
struct TreeNode {
    int value;
    struct TreeNode *left, *right;
};

// Function to create a new node
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new node
struct TreeNode* insert(struct TreeNode* node, int value) {
    if (node == NULL) return createNode(value);

    if (value < node->value)
        node->left = insert(node->left, value);
    else if (value > node->value)
        node->right = insert(node->right, value);

    return node;
}

// Function to search for a value in the tree
struct TreeNode* search(struct TreeNode* root, int value) {
    if (root == NULL || root->value == value)
        return root;

    if (root->value < value)
        return search(root->right, value);

    return search(root->left, value);
}

// Function to find the node with the minimum value
struct TreeNode* minValueNode(struct TreeNode* node) {
    struct TreeNode* current = node;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}

// Function to delete a node
struct TreeNode* deleteNode(struct TreeNode* root, int value) {
    if (root == NULL) return root;

    if (value < root->value)
        root->left = deleteNode(root->left, value);
    else if (value > root->value)
        root->right = deleteNode(root->right, value);
    else {
        if (root->left == NULL) {
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        struct TreeNode* temp = minValueNode(root->right);
        root->value = temp->value;
        root->right = deleteNode(root->right, temp->value);
    }
    return root;
}

// Function to traverse through BST
void inorder(struct TreeNode* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->value);
        inorder(root->right);
    }
}

// Main function to demonstrate tree operations
int main() {
    struct TreeNode* root = NULL;
    root = insert(root, 5);
    insert(root, 3);
    insert(root, 2);
    insert(root, 4);
    insert(root, 7);
    insert(root, 6);
    insert(root, 8);

    printf("Given tree: \n");
    inorder(root);

    printf("\n\nDelete 2\n");
    root = deleteNode(root, 2);
    printf("After deleting 2: \n");
    inorder(root);

    printf("\n\nDelete 3\n");
    root = deleteNode(root, 3);
    printf("After deleting 3: \n");
    inorder(root);

    printf("\n\nDelete 5\n");
    root = deleteNode(root, 5);
    printf("After deleting 5: \n");
    inorder(root);

    // Search test
    int searchVal = 4;
    struct TreeNode* res = search(root, searchVal);
    printf("\n\nSearch element %d", searchVal);
    if (res != NULL)
        printf("\n\nElement %d found in tree", searchVal);
    else
        printf("\n\nElement %d not found in tree", searchVal);

    return 0;
}


************************************
OUTPUT
************************************
Given tree: 
2 3 4 5 6 7 8 

Delete 2
After deleting 2: 
3 4 5 6 7 8 

Delete 3
After deleting 3: 
4 5 6 7 8 

Delete 5
After deleting 5: 
4 6 7 8 

Search element 4

Element 4 found in tree

