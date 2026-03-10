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

int main()
{
    struct node *head = NULL;
    head = create();
}