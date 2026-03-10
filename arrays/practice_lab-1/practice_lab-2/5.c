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

struct node *reverse_list(struct node *head)
{
    struct node *p = NULL;
    struct node *c = head;
    struct node *n = NULL;
    while(c != NULL)
    {
        n = c -> next;
        c -> next = p;
        p = c;
        c = n;
    }
    head = p;
    return head;
}

int main()
{
    struct node *head = NULL;
    head = create();
    display(head);
    head = reverse_list(head);
    printf("reversed list.\n");
    display(head);
    return 0;
}