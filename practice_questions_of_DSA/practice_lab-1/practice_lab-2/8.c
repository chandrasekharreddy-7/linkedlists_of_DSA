#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *create()
{
    struct node *head = NULL,*newnode = NULL,*temp = NULL;
    int choice = 1;
    while(choice == 1)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("enter data :");
        scanf("%d",&newnode->data);
        newnode->next = NULL;
        newnode->prev = NULL;
        if(head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
        printf("enter 0 to exit 1 to continue :");
        scanf("%d",&choice);
    }
    return head;
}

void display(struct node *head)
{
    struct node *temp = head;
    if(head == NULL)
    {
        printf("list is empty!\n");
        return;
    }
    printf("NULL <-> ");
    while(temp != NULL)
    {
        printf("%d <-> ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct node *insertatbeginning(struct node *head)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter data to insert at beginning :");
    scanf("%d",&newnode->data);
    newnode->prev = NULL;
    newnode->next = head;
    if(head != NULL)
    {
        head->prev = newnode;
    }
    head = newnode;
    return head;
}

struct node *insertionatend(struct node *head)
{
    struct node *newnode,*temp=head;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter data to insert at end of the list :");
    scanf("%d",&newnode->data);
    newnode->next = NULL;
    if(head == NULL)
    {
        newnode->prev = NULL;
        head = newnode;
        return head;
    }
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
    return head;
}

struct node *insertatposition(struct node *head,int pos)
{
    struct node *newnode,*temp=head;
    int i=1;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter data:");
    scanf("%d",&newnode->data);
    if(pos==1)
        return insertatbeginning(head);
    if(head==NULL)
    {
        printf("list is empty\n");
        return head;
    }
    while(i<pos-1 && temp->next!=NULL)
    {
        temp=temp->next;
        i++;
    }
    newnode->next=temp->next;
    newnode->prev=temp;
    if(temp->next!=NULL)
    {
        temp->next->prev=newnode;
    }
    temp->next=newnode;
    return head;
}

int main()
{
    struct node *head = NULL;
    head = create();
    int choice,num = 1,pos;
    while(num == 1)
    {
        printf("enter your options from below.\n");
        printf("1. display of doubly linked list.\n");
        printf("2. insertion at beginning.\n");
        printf("3. insertion at end.\n");
        printf("4. insertion at position.\n");
        printf("enter your option from (1 - 4) :");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("your current list!.\n");
            display(head);
            break;
            case 2:
            head = insertatbeginning(head);
            printf("list after insertion at beginning.\n");
            display(head);
            break;
            case 3:
            head = insertionatend(head);
            printf("list after insertion at end.\n");
            display(head);
            break;
            case 4:
            printf("enter position to insert :");
            scanf("%d",&pos);
            head = insertatposition(head,pos);
            printf("list after inserting element at position %d\n",pos);
            display(head);
            break;
            default:
            printf("please enter correct choice.\n");
        }
        printf("enter 1 to continue and 0 to exit :");
        scanf("%d",&num);
        if (num != 1)
        {
            printf("program ended sucessfully!.\n");
        }
    }
    return 0;
}