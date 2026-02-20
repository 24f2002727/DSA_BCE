
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;              
    struct node *prev;     // pointer to previous node 
    struct node *next;     // pointer to next node 
} Node;  //here typedef is converting thr variable name from struct node to only Node

/* Head of the doubly linked list */
Node *head = NULL;

// display
void display()
{
    Node *ptr = head;
    printf("List (head -> tail): ");
    while (ptr != NULL) {
        printf("%d", ptr->data);
        if (ptr->next) printf(" <-> ");
        ptr = ptr->next;
    }
    printf("\n");
}


void create()
{
    int x, ch;
    do {
        printf("Enter data: ");
        scanf("%d", &x);

        // create new node
        Node *temp = (Node*)malloc(sizeof(Node));
        
        temp->data = x;
        temp->prev = temp->next = NULL;

        // append to end
        if (head == NULL) 
        {
            head = temp;
        }
        else 
        {
            Node *ptr = head;
            while (ptr->next != NULL) ptr = ptr->next;
            //inserting and updating nodes
            ptr->next = temp;
            temp->prev = ptr;
        }

        printf("Enter 1 to add more nodes, 0 to stop: ");
        if (scanf("%d", &ch) != 1) ch = 0; //it is checking for any input if not ip update ch with 0
    } while (ch == 1);
}

// insertAtBeg: insert a new node at the beginning of the list
void insertAtBeg()
{
    int data;
    printf("Enter data to insert at beginning: ");
    scanf("%d", &data);

    Node *temp = (Node*)malloc(sizeof(Node));

    temp->data = data;
    temp->prev = NULL;
    temp->next = head;
    if (head != NULL) head->prev = temp;
    head = temp;
}

/* insertAtEnd: insert a new node at the end of the list */
void insertAtEnd()
{
    int data;
    printf("Enter data to insert at end: ");
    if (scanf("%d", &data) != 1) return;

    Node *temp = (Node*)malloc(sizeof(Node));
    if (temp == NULL) { printf("Memory allocation failed\n"); return; }
    temp->data = data;
    temp->next = NULL;

    if (head == NULL) {
        temp->prev = NULL;
        head = temp;
        return;
    }

    Node *ptr = head;
    while (ptr->next != NULL) ptr = ptr->next;
    ptr->next = temp;
    temp->prev = ptr;
}

/* insertAtMid: insert a new node after the node containing `target` value
   If target is not found, the function reports and does nothing. */
void insertAtMid()
{
    int target, data;
    printf("Enter target value to insert after: ");
    if (scanf("%d", &target) != 1) return;
    printf("Enter data to insert: ");
    if (scanf("%d", &data) != 1) return;

    Node *ptr = head;
    while (ptr != NULL && ptr->data != target) ptr = ptr->next;
    if (ptr == NULL) {
        printf("Target %d not found\n", target);
        return;
    }

    Node *temp = (Node*)malloc(sizeof(Node));
    if (temp == NULL) { printf("Memory allocation failed\n"); return; }
    temp->data = data;

    temp->next = ptr->next;
    temp->prev = ptr;
    if (ptr->next) ptr->next->prev = temp;
    ptr->next = temp;
}

/* deleteAtBeg: remove the first node (if any) and free its memory */
void deleteAtBeg()
{
    if (head == NULL) return;
    Node *temp = head;
    head = head->next;
    if (head) head->prev = NULL;
    free(temp);
}

/* deleteAtEnd: remove the last node (if any) and free its memory */
void deleteAtEnd()
{
    if (head == NULL) return;
    Node *ptr = head;
    while (ptr->next != NULL) ptr = ptr->next;
    // ptr is last node
    if (ptr->prev) ptr->prev->next = NULL;
    else head = NULL; // list became empty
    free(ptr);
}

/* deleteAtMid: delete the first node that contains `target` value */
void deleteAtMid()
{
    int target;
    printf("Enter value to delete: ");
    if (scanf("%d", &target) != 1) return;

    Node *ptr = head;
    while (ptr != NULL && ptr->data != target) ptr = ptr->next;
    if (ptr == NULL) { printf("Value %d not found\n", target); return; }

    if (ptr->prev) ptr->prev->next = ptr->next;
    else head = ptr->next; // deleting head
    if (ptr->next) ptr->next->prev = ptr->prev;
    free(ptr);
}

/* main: simple interactive menu to exercise the list operations */
int main()
{
    int choice;
    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Create (append)\n2. Display\n3. Insert at beginning\n4. Insert at end\n5. Insert after value\n6. Delete at beginning\n7. Delete at end\n8. Delete value\n9. Exit\");
        printf("\nEnter choice: ");
        if (scanf("%d", &choice) != 1) break;
        switch (choice) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: insertAtBeg(); break;
            case 4: insertAtEnd(); break;
            case 5: insertAtMid(); break;
            case 6: deleteAtBeg(); break;
            case 7: deleteAtEnd(); break;
            case 8: deleteAtMid(); break;
            case 9: printf("Exiting.\n"); return 0;
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}