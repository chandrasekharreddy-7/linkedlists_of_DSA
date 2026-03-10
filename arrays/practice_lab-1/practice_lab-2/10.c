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

struct node *reverse_list(struct node *head)
{
    struct node *current = head;
    struct node *temp = NULL;
    if(head == NULL)
    {
        return NULL;

    }
    while(current != NULL)
    {
        temp = current -> prev;
        current -> prev = current -> next;
        current -> next = temp;
        current = current -> prev;
    }
    if(temp != NULL)
    {
        head = temp -> prev;
    }
    return head;
}

int main()
{
    struct node *head = NULL;
    head = create();
    printf("your current list:\n");
    display(head);
    head = reverse_list(head);
    printf("list after reversing the original list.\n");
    display(head);
    return 0;
}