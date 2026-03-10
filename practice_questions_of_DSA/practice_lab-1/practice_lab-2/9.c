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

struct node *deleteatbeginning(struct node *head)
{
    if(head == NULL)
    {
        printf("list is empty\n");
        return head;
    }
    struct node *temp = head;
    head = head->next;
    if(head != NULL)
    {
        head->prev = NULL;
    }
    free(temp);
    return head;
}

struct node *deleteatposition(struct node *head,int pos)
{
    struct node *temp=head;
    int i=1;
    if(pos==1)
        return deleteatbeginning(head);
    while(i < pos && temp != NULL)
    {
        temp = temp->next;
        i++;
    }
    if(temp == NULL)
        return head;
    if(temp->next != NULL)
        temp->next->prev = temp->prev;
    if(temp->prev != NULL)
        temp->prev->next = temp->next;
    free(temp);
    return head;
}

struct node *deleteend(struct node *head)
{
    struct node *temp=head;
    if(head == NULL)
    {
        printf("list is empty\n");
        return head;
    }
    if(head->next == NULL)
    {
        free(head);
        return NULL;
    }
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
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
        printf("2. deletion at beginning.\n");
        printf("3. deletion at end.\n");
        printf("4. deletion at position.\n");
        printf("enter your option from (1 - 4) :");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("your current list!.\n");
            display(head);
            break;
            case 2:
            head = deleteatbeginning(head);
            printf("list after deletion at beginning.\n");
            display(head);
            break;
            case 3:
            head = deleteend(head);
            printf("list after deletion at end.\n");
            display(head);
            break;
            case 4:
            printf("enter position to delete :");
            scanf("%d",&pos);
            head = deleteatposition(head,pos);
            printf("list after deleting element at position %d\n",pos);
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