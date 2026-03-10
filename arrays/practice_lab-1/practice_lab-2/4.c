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

struct node *deleteatfirst(struct node *head)
{
    struct node *temp;
    if (head == NULL)
    {
        printf("lsit is empty!");
        return head;
    }
    else
    {
        temp = head;
        head = head -> next;
        free(temp);
        return head;
    }
}

struct node *deletionatposition(struct node *head,int pos)
{
    struct node *temp,*prev;
    int i;
    if (head == NULL)
    {
        printf("List is empty!.");
        return head;
    }
    if (pos == 1)
    {
        temp = head;
        head = head -> next;
        free(temp);
        return head;
    }
    temp = head;
    for(i = 1;i < pos;i++)
    {
        prev = temp;
        temp = temp -> next;
    }
    prev->next = temp->next;
    free(temp);
    return head;
}

struct node *deletionatlast(struct node *head)
{
    struct node *temp = head;
    if(head == NULL)
    {
        printf("List is empty");
        return head;
    }
    while(temp->next->next != NULL)
    {
        temp = temp -> next;
    }
    temp->next = NULL;
    free(temp->next);
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
        printf("2. deletion at begginning\n");
        printf("3. deletion at position\n");
        printf("4. deletion at last.\n");
        int num;
        printf("enter your options from above :");
        scanf("%d",&num);
        switch(num)
        {
            case 1:
            display(head);
            break;
            case 2:
            head = deleteatfirst(head);
            printf("list after insertion at first\n");
            display(head);
            break;
            case 3:
            int pos;
            printf("enter position to delete the element :");
            scanf("%d",&pos);
            head = deletionatposition(head,pos);
            printf("list after deleting at position %d\n",pos);
            display(head);
            break;
            case 4:
            head = deletionatlast(head);
            printf("list after deletion at last.\n");
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