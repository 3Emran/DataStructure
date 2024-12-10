#include <stdio.h>
#define MAX_SIZE 10
//C program to implement binary tree using Array
char tree[MAX_SIZE];
void setRoot(char key) {
    if (tree[0] != '\0') {
        printf("Tree already has a root.\n");
    } else {
        tree[0] = key;                 //  0-n
    }
}
                                          //index=i
                                           //2*parent+1 = left child equatio
void setLeft(char key, int parent) {
    int leftIndex = (parent * 2) + 1;
    if (tree[parent] == '\0') {
        printf("Can't set child at %d, no parent found.\n", leftIndex);
    } else if (leftIndex >= MAX_SIZE) {
        printf("Left child index out of bounds.\n");
    } else {
        tree[leftIndex] = key;
    }
}
// Function to set the right child
void setRight(char key, int parent) {
    int rightIndex = (parent * 2) + 2;
    if (tree[parent] == '\0') {
        printf("Can't set child at %d, no parent found.\n", rightIndex);
    } else if (rightIndex >= MAX_SIZE) {
        printf("Right child index out of bounds.\n");
    } else {
        tree[rightIndex] = key;
    }
}
// Function to print the tree
void printTree() {
    printf("Tree structure: ");
    for (int i = 0; i < MAX_SIZE; i++) {
        if (tree[i] != '\0')
            printf("%c ", tree[i]);
        else
            printf("- ");
    }
    printf("\n");
}

int main() {

    setRoot('A');
    setLeft('B', 0);
    setRight('C', 0);
    setLeft('D', 1);
    setRight('E', 1);
    setRight('F', 2);
    printTree();
}
