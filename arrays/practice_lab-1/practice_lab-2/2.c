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

struct node *nodecount(struct node *head)
{
    struct node *temp = head;
    int count = 0;
    if (head == NULL)
    {
        printf("list has no elements, so node count is 0");
        return head;
    }
    while (temp != NULL)
    {
        count++;
        temp = temp -> next;
    }
    printf("total no of nodes = %d\n",count);
    return head;
}
int main()
{
    struct node *head = NULL;
    head = create();
    display(head);
    nodecount(head);
}