#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *create()
{
    struct node *head = NULL,*newnode = NULL,*temp = NULL;
    int choice = 1;
    while(choice == 1)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("enter the data :");
        scanf("%d",&newnode->data);
        newnode -> next = NULL;
        if(head == NULL)
        {
            head = newnode;
            temp = head;
        }
        else
        {
            temp -> next = newnode;
            temp = newnode;
        }
        printf("enter 0 to exit and 1 to continue :");
        scanf("%d",&choice);
    }
    return head;
}

struct node *display(struct node *head)
{
    struct node *temp = head;
    if (head == NULL)
    {
        printf("the list is empty.");
        return head;
    }
    while (temp != NULL)
    {
        printf("%d -> ",temp -> data);
        temp = temp -> next;
    }
    printf("NULL\n");
    return head;
}


struct node *insertionatfirst(struct node *head)
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("enter the data to insert at first :");
    scanf("%d",&newnode->data);
    newnode->next = head;
    head = newnode;
    return head;
}

struct node *insertionatposition(struct node *head, int pos)
{
    struct node *newnode,*temp;
    int i;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter data to insert :");
    scanf("%d",&newnode->data);
    newnode->next = NULL;
    if (pos == 1)
    {
        newnode -> next = head;
        head = newnode;
        return head;
    }
    temp = head;
    for(i = 1;i < pos-1 && temp != NULL;i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Invalid position!\n");
        return head;
    }
    newnode -> next = temp->next;
    temp->next = newnode;
    return head;
}

struct node * insertionatlast(struct node *head)
{
    struct node *newnode,*temp;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("enter element to insert at last :");
    scanf("%d",&newnode -> data);
    newnode -> next = NULL;
    temp = head;
    if (head == NULL)
    {
        head = newnode;
        return head;
    }
    while (temp -> next != NULL)
    {
        temp = temp -> next;
    }
    temp -> next = newnode;
    return head;
}


int main()
{
    struct node *head = NULL;
    head = create();
    int choice = 1;
    while (choice == 1)
    {
        printf("you have to choose options below.\n");
        printf("1. single linked list display.\n");
        printf("2. insert at begginning\n");
        printf("3. insertion at position\n");
        printf("4. insertion at last.\n");
        int num;
        printf("enter your options from above :");
        scanf("%d",&num);
        switch(num)
        {
            case 1:
            display(head);
            break;
            case 2:
            head = insertionatfirst(head);
            printf("list after insertion at first\n");
            display(head);
            break;
            case 3:
            int pos;
            printf("enter position to insert the element :");
            scanf("%d",&pos);
            head = insertionatposition(head,pos);
            printf("list after inserting at position %d\n",pos);
            display(head);
            break;
            case 4:
            head = insertionatlast(head);
            printf("list after insertion at last.\n");
            display(head);
            break;
        }
        printf("enter 0 to stop and 1 to continue :");
        scanf("%d",&choice);
        if(choice != 1)
        {
            printf("you have succesfully exited the program.\n");
        }
    }
}