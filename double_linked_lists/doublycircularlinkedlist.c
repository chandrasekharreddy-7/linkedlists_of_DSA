// double circular linked list
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
        if(head == NULL)
        {
            head = newnode;
            newnode->next = head;
            newnode->prev = head;
            temp = newnode;
        }
        else
        {
            newnode->next = head;
            newnode->prev = temp;
            temp->next = newnode;
            head->prev = newnode;
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
    printf("back to head <-> ");
    printf("%d -> ",temp->data);
    temp = temp->next;
    while(temp != head)
    {
        printf("%d <-> ",temp->data);
        temp = temp->next;
    }
    printf("back to head.\n");
}

struct node *insertatbeginning(struct node *head)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter data to insert at beginning :");
    scanf("%d",&newnode->data);
    if(head == NULL)
    {
        newnode->next = newnode;
        newnode->prev = newnode;
        head = newnode;
    }
    else
    {
        struct node *last = head->prev;
        newnode->next = head;
        newnode->prev = last;
        last->next = newnode;
        head->prev = newnode;
        head = newnode;
    }
    return head;
}

struct node *insertatposition(struct node *head,int pos)
{
    struct node *newnode,*temp;
    int i=1;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter data:");
    scanf("%d",&newnode->data);
    if(pos==1)
        return insertatbeginning(head);
    temp = head;
    while(i < pos-1)
    {
        temp = temp->next;
        i++;
    }
    newnode->next = temp->next;
    newnode->prev = temp;
    temp->next->prev = newnode;
    temp->next = newnode;
    return head;
}

struct node *insertionatend(struct node *head)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter data to insert at end of the list :");
    scanf("%d",&newnode->data);
    if(head == NULL)
    {
        newnode->next = newnode;
        newnode->prev = newnode;
        head = newnode;
    }
    else
    {
        struct node *last = head->prev;
        newnode->next = head;
        newnode->prev = last;
        last->next = newnode;
        head->prev = newnode;
    }
    return head;
}

struct node *deleteatbeginning(struct node *head)
{
    if(head == NULL)
    {
        printf("list is empty\n");
        return head;
    }
    if(head->next == head)
    {
        free(head);
        return NULL;
    }
    struct node *last = head->prev;
    struct node *temp = head;
    head = head->next;
    head->prev = last;
    last->next = head;
    free(temp);
    return head;
}

struct node *deleteatposition(struct node *head,int pos)
{
    int i=1;
    struct node *temp=head;
    if(pos==1)
        return deleteatbeginning(head);
    while(i < pos)
    {
        temp = temp->next;
        i++;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
    return head;
}

struct node *deleteend(struct node *head)
{
    if(head == NULL)
    {
        printf("list is empty\n");
        return head;
    }
    if(head->next == head)
    {
        free(head);
        return NULL;
    }
    struct node *last = head->prev;
    last->prev->next = head;
    head->prev = last->prev;
    free(last);
    return head;
}

int main()
{
    struct node *head = NULL;
    head = create();
    int num = 1;
    while(num == 1)
    {
        printf("your current list.\n");
        display(head);
        printf("enter your options from below :\n");
        printf("1. list display.\n");
        printf("2. insertion at beginning\n");
        printf("3. insertion at position\n");
        printf("4. insertion at end\n");
        printf("5. deletion at beginning\n");
        printf("6. deletion at position.\n");
        printf("7. delete at end.\n");
        int choice,pos,pos1;
        printf("enter your choice (1 - 7):");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            display(head);
            break;
            case 2:
            head = insertatbeginning(head);
            display(head);
            break;
            case 3:
            printf("enter position:");
            scanf("%d",&pos);
            head = insertatposition(head,pos);
            display(head);
            break;
            case 4:
            head = insertionatend(head);
            display(head);
            break;
            case 5:
            head = deleteatbeginning(head);
            display(head);
            break;
            case 6:
            printf("enter position:");
            scanf("%d",&pos1);
            head = deleteatposition(head,pos1);
            display(head);
            break;
            case 7:
            head = deleteend(head);
            display(head);
            break;
            default:
            printf("enter correct choice\n");
        }
        printf("enter 1 to repeat and 0 to exit:");
        scanf("%d",&num);
    }
    return 0;
}