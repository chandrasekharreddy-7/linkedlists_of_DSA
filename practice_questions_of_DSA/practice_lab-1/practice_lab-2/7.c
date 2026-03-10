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

void forward_traversal(struct node *head)
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

void backward_traversal(struct node *head)
{
    struct node *temp = head;
    if(head == NULL)
    {
        printf("list is empty!\n");
        return;
    }
    while(temp -> next != NULL)
    {
        temp = temp -> next;
    }
    printf("NULL <-> ");
    while(temp != NULL)
    {
        printf("%d <-> ",temp -> data);
        temp = temp -> prev;
    }
    printf("NULL\n");
}

int main()
{
    struct node *head = NULL;
    head = create();
    int num = 1,choice;
    while(num == 1)
    {
        printf("enter your options from below.\n");
        printf("1. forward traversal.\n");
        printf("2. backward traversal.\n");
        printf("enter your choice from above options(1 / 2) :");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("forward traversal.\n");
            forward_traversal(head);
            break;
            case 2:
            printf("backward traversal.\n");
            backward_traversal(head);
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