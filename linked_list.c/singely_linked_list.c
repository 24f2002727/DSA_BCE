#include<stdio.h>
#include<stdlib.h>

// making a user defined data type which stores data and address of next location
struct Node{
    int data;
    struct Node *next;
};

// initialising the head of the linked list
struct Node *head = NULL;

// creating a linked list
void create(){
    struct Node *temp, *ptr;
    int x, ch;

    // creating nodes using do while
    do{
        temp = (struct Node*)malloc(sizeof(struct Node));
        //checking memory alocation by system
        if(temp == NULL){
            printf("Memory allocation failed\n");
            return;
        }

        printf("\nEnter the data\n");
        scanf("%d", &x);

        temp->data = x;
        temp->next = NULL;

        if(head == NULL){
            head = temp;
        }
        else{
            ptr = head;
            while(ptr->next != NULL){
                ptr = ptr->next;
            }
            ptr->next = temp;
        }
        printf("Enter 1 if you want to create more Nodes else press any other key: ");
        scanf("%d", &ch);
    } while(ch == 1);
}

// display fn of linked list
void display()
{
    struct Node *ptr = head;
    while(ptr != NULL)
    {
        printf("%d --> is at address %p\n", ptr->data, (void*)&ptr->data); // displaying both data and address
        ptr = ptr->next;
    }
}

// insert at beginning
void insertAtBeg()
{
    int data;
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    if(temp == NULL){
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter the data to insert at beginning: ");
    scanf("%d", &data);

    temp->data = data;
    temp->next = head;
    head = temp;
}

// insert after a node with given value
void insertAtMid()
{
    int target, data;
    struct Node *temp, *ptr;
    temp = (struct Node *)malloc(sizeof(struct Node));
    if(temp == NULL){
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter the data to insert: ");
    scanf("%d", &data);
    printf("Enter the target node data after which to insert: ");
    scanf("%d", &target);

    temp->data = data;

    // traversing to the given node
    ptr = head;
    while(ptr != NULL && ptr->data != target){
        ptr = ptr->next;
    }
    if(ptr == NULL){
        printf("Target node not found\n");
        free(temp);
        return;
    }
    temp->next = ptr->next;
    ptr->next = temp;
}

// insert at end
void insertAtEnd()
{
    int data;
    struct Node *temp, *ptr;
    temp = (struct Node *)malloc(sizeof(struct Node));
    if(temp == NULL){
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter the data to insert at end: ");
    scanf("%d", &data);

    temp->data = data;
    temp->next = NULL;

    if(head == NULL){
        head = temp;
        return;
    }

    // traversing to the last node
    ptr = head;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = temp;
}

// deletion of node at beginning
void deleteAtBeg()
{
    struct Node * ptr;
    if(head == NULL) return;
    ptr = head;
    head = head->next;
    free(ptr);
    ptr = NULL;
}

// deletion of node with given data
void deleteAtMid()
{
    int data;
    struct Node * ptr, *prev;
    if(head == NULL) return;
    printf("Enter data of node to delete: ");
    scanf("%d", &data);

    ptr = head;
    prev = NULL;
    while(ptr != NULL && ptr->data != data){
        prev = ptr;
        ptr = ptr->next;
    }
    if(ptr == NULL){
        printf("Node with value %d not found\n", data);
        return;
    }
    if(prev == NULL){
        head = ptr->next;
    } else {
        prev->next = ptr->next;
    }
    free(ptr);
    ptr = NULL;
}

// deletion at end
void deleteAtEnd()
{
    struct Node * ptr, *prev;
    if(head == NULL) return;
    if(head->next == NULL){
        free(head);
        head = NULL;
        return;
    }
    ptr = head;
    prev = NULL;
    while(ptr->next != NULL){
        prev = ptr;
        ptr = ptr->next;
    }
    prev->next = NULL;
    free(ptr);
    ptr = NULL;
}


int main()
{
    create();
    display();
    return 0;
}