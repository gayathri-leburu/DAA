#include <stdio.h>
#include <stdlib.h>

struct rbNode {
    int data;
    struct rbNode *left, *right, *parent;
};

typedef struct rbNode rbNode;

rbNode* createNode(int data) {
    rbNode *newNode = (rbNode*)malloc(sizeof(rbNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    return newNode;
}

// Rotate left
void rotateLeft(rbNode **root, rbNode *x) {
    rbNode *y = x->right;
    x->right = y->left;
    if (y->left != NULL) {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == NULL) {
        *root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

// Rotate right
void rotateRight(rbNode **root, rbNode *x) {
    rbNode *y = x->left;
    x->left = y->right;
    if (y->right != NULL) {
        y->right->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == NULL) {
        *root = y;
    } else if (x == x->parent->right) {
        x->parent->right = y;
    } else {
        x->parent->left = y;
    }
    y->right = x;
    x->parent = y;
}

// Binary search tree insert
rbNode* insert(rbNode *root, rbNode *node) {
    if (root == NULL) return node;

    if (node->data < root->data) {
        root->left = insert(root->left, node);
        root->left->parent = root;
    } else if (node->data > root->data) {
        root->right = insert(root->right, node);
        root->right->parent = root;
    }
    return root;
}

// Function to find the minimum value node
rbNode* minValueNode(rbNode* node) {
    rbNode* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// BST delete
rbNode* deleteNode(rbNode *root, int data) {
    if (root == NULL) return root;

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        if (root->left == NULL) {
            rbNode *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            rbNode *temp = root->left;
            free(root);
            return temp;
        }

        rbNode *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Inorder traversal
void inorder(rbNode *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    rbNode *root = NULL;
    rbNode *temp;

    // Initial tree setup
    root = insert(root, createNode(30));
    root = insert(root, createNode(20));
    root = insert(root, createNode(40));
    root = insert(root, createNode(10));
    root = insert(root, createNode(25));
    root = insert(root, createNode(35));
    root = insert(root, createNode(50));

    printf("Initial tree (Inorder traversal): \n");
    inorder(root);

    printf("\n\nAfter deleting 20\n");
    root = deleteNode(root, 20);
    inorder(root);

    printf("\n\nAfter deleting 30\n");
    root = deleteNode(root, 30);
    inorder(root);
    
    printf("\n\nAfter inserting 80\n");
    root = insert(root, createNode(80));
    inorder(root);

    printf("\n\nAfter deleting 50\n");
    root = deleteNode(root, 50);
    inorder(root);

    // Test Rotate Right
    printf("\n\nTesting Rotate Right at node 30\n");
    rotateRight(&root, root); // Assuming root is currently 30
    inorder(root);
    printf("\nAfter Rotate Right, new root is: %d\n", root->data);

    // Reset tree for Rotate Left Test
    root = NULL;
    root = insert(root, createNode(20));
    root = insert(root, createNode(10));
    root = insert(root, createNode(30));
    root = insert(root, createNode(25));
    root = insert(root, createNode(40));
    root = insert(root, createNode(80));

    printf("\nReset tree for Rotate Left Test (Inorder traversal): \n");
    inorder(root);
    printf("\n\n");

    // Test Rotate Left
    printf("Testing Rotate Left at node 20\n");
    rotateLeft(&root, root); // Assuming root is currently 20
    inorder(root);
    printf("\nAfter Rotate Left, new root is: %d\n", root->data);

    return 0;
}


*********************************
OUTPUT
*********************************

Initial tree (Inorder traversal): 
10 20 25 30 35 40 50 

After deleting 20
10 25 30 35 40 50 

After deleting 30
10 25 35 40 50 

After inserting 80
10 25 35 40 50 80 

After deleting 50
10 25 35 40 80 

Testing Rotate Right at node 30
10 25 35 40 80 
After Rotate Right, new root is: 25

Reset tree for Rotate Left Test (Inorder traversal): 
10 20 25 30 40 80 

Testing Rotate Left at node 20
10 20 25 30 40 80 
After Rotate Left, new root is: 30
