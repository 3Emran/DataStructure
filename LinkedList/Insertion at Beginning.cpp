/*
In this operation, we are adding an element at the beginning of the list.
Algorithm
1. START
2. Create a node to store the data
3. Check if the list is empty
4. If the list is empty, add the data to the node and
   assign the head pointer to it.
5. If the list is not empty, add the data to a node and link to the
   current head. Assign the head to the newly added node.
6. END */
#include <iostream>
#include <string>
using namespace std;
struct node{
    int data;
    struct node *next;
};
struct node *head = NULL;
struct node *current = NULL;

//Display the list
void printList(){
    struct node *p = head;
    cout << "\n[";

    //
    while(p != NULL){
        cout << " " << p->data << "";
        p = p->next;
    }
    cout << "]";
}
void insertionAtbegin(int data){
    //create a link
    struct node *link = (struct node*) malloc(sizeof (struct node));
    link->data = data;
    // point it to old first node
   link->next = head;

   //point first to new first node
   head = link;
}
int main(){
    insertionAtbegin(12);
    insertionAtbegin(22);
    insertionAtbegin(30);
    insertionAtbegin(44);
    insertionAtbegin(50);
    cout << "Link List: ";
    //print list
    printList();
}
