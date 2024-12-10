#include <stdio.h>
#include <stdlib.h>

// Define the structure of a Node
struct Node {
    int data;
    struct Node* next;
};

// Function to delete the head node of the linked list
struct Node* deleteHead(struct Node* head) {
    if (head == NULL)
        return NULL; // If the list is empty, return NULL

    struct Node* temp = head; // Temporarily store the current head
    head = head->next;        // Move the head to the next node
    free(temp);               // Free the memory of the old head

    return head;              // Return the new head of the list
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to create a new node with given data
struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    if (node == NULL) {
        printf("Memory allocation failed\n");
        exit(1); // Exit if memory allocation fails
    }
    node->data = data;
    node->next = NULL;
    return node;
}

// Main function to demonstrate the linked list operations
int main() {
    // Create a linked list
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("Initial list: ");
    printList(head);

    // Delete the head node
    head = deleteHead(head);

    printf("List after deleting the head: ");
    printList(head);

    return 0;
}
