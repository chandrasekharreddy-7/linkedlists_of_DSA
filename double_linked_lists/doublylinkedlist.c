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

struct node *insertatposition(struct node *head,int pos)
{
    struct node *newnode,*temp=head;
    int i=1;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter data:");
    scanf("%d",&newnode->data);
    if(pos==1)
    {
        return insertatbeginning(head);
    }
    while(i < pos-1 && temp->next != NULL)
    {
        temp = temp->next;
        i++;
    }
    newnode->next = temp->next;
    newnode->prev = temp;
    if(temp->next != NULL)
    {
        temp->next->prev = newnode;
    }
    temp->next = newnode;
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

struct node *reverse(struct node *head)
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
        printf("8. reversing of list.\n");
        int choice,pos,pos1;
        printf("enter your choice (1 - 8):");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("entered current list:\n");
            display(head);
            break;
            case 2:
            head = insertatbeginning(head);
            printf("list after inserting at beginning of the list.\n");
            display(head);
            break;
            case 3:
            printf("enter position:");
            scanf("%d",&pos);
            head = insertatposition(head,pos);
            printf("list after insertion at position %d\n",pos);
            display(head);
            break;
            case 4:
            head = insertionatend(head);
            printf("list after insertion at the end.\n");
            display(head);
            break;
            case 5:
            head = deleteatbeginning(head);
            printf("list after deleting element at the beginning.\n");
            display(head);
            break;
            case 6:
            printf("enter position:");
            scanf("%d",&pos1);
            head = deleteatposition(head,pos1);
            printf("list after deleting element at position %d\n",pos1);
            display(head);
            break;
            case 7:
            head = deleteend(head);
            printf("list after deleting element at the end.\n");
            display(head);
            break;
            case 8:
            head = reverse(head);
            printf("list after reversing.\n");
            display(head);
            break;
            default:
            printf("enter correct choice\n");
        }
        printf("enter 1 to repeat and 0 to exit:");
        scanf("%d",&num);
        if(num != 1)
        {
            printf("program ended succesfully!");
        }
    }
    return 0;
}