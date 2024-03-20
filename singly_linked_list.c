#include <stdio.h>  
#include <stdlib.h>  
  
// Singly Linked List structure  
struct Node {  
    int data;  
    struct Node* next;  
};  
  
// Global head pointer  
struct Node* head = NULL;  
  
// Function to insert a node at the end of the list  
void insert(int value) {  
    // Create a new node  
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));  
    newNode->data = value;  
    newNode->next = NULL;  
  
    // Check if the list is empty  
    if (head == NULL) {  
        head = newNode;  
    } else {  
        // Traverse to the end of the list  
        struct Node* current = head;  
        while (current->next != NULL) {  
            current = current->next;  
        }  
        // Link the new node to the last node  
        current->next = newNode;  
    }  
}  
  
// Function to traverse and print the list  
void traverse() {  
    struct Node* current = head;  
    while (current != NULL) {  
        printf("%d ", current->data);  
        current = current->next;  
    }  
}  
  
int main() {  
    // Insert elements into the list  
    insert(4);  
    insert(1);  
    insert(3);  
    insert(8);  
  
    // Traverse and print the list  
    printf("List: ");  
    traverse();    
    return 0;  
}  

************
OUTPUT
***********
  
List: 4 1 3 8
