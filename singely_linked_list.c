#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *head=NULL;

void create(){
    struct Node *temp,*ptr;
    int x,ch;

    //creating nodes using do while
    do{
        temp=(struct Node*)malloc(sizeof(struct Node));

        printf("\nEnter the data\n");
        scanf("%d",&x);

        temp->data=x;
        temp->next=NULL;

        if(head==NULL){
            head=temp;
        }
        else{
            ptr=head;
            while(ptr->next!=NULL){
                ptr=ptr->next;
            }
            ptr->next=temp;
        }
        printf("Enter 1 if you want to create more Nodes else press key.");
        scanf("%d",&ch);
    }
    while(ch==1);
}

void display()
{
    struct Node *ptr=head;
    while(ptr!=NULL)
    {
        printf("%d --> is at address %p\n",ptr->data,&ptr->data); //displaying both data and address
        ptr=ptr->next;
    }
}



int main()
{

    create();
    display();
    return 0;

}