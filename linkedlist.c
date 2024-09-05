#include <stdio.h>
#include <stdlib.h>

//define linked list data structure
struct Node {
    int data;
    struct Node* next;
};

// function to insert element at the beginning
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// function to print the list
void printlist(struct Node* node){
    while  (node != NULL) {
        printf("%d", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    struct node* head = NULL;
    insertAtBeginning(&head,10);
    insertAtBeginning(&head,20);

    printlist(head);

    return 0;
}