#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node* create()
{
    struct node *head = NULL, *newnode = NULL, *temp = NULL;
    int choice = 1;

    while(choice == 1)
    {
        newnode = (struct node*)malloc(sizeof(struct node));

        printf("enter the data: ");
        scanf("%d", &newnode->data);

        newnode->next = NULL;

        if(head == NULL)
        {
            head = newnode;
            temp = head;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }

        printf("enter 1 to continue and 0 to exit: ");
        scanf("%d", &choice);
    }

    return head;
}

struct node* display(struct node *head)
{
    int count = 0;
    struct node *x = head;

    if(head == NULL)
    {
        printf("list is empty\n");
        return head;
    }

    while(x != NULL)
    {
        printf("%d -> ", x->data);
        x = x->next;
        count++;
    }

    printf("NULL\n");
    printf("no of nodes = %d\n", count);

    return head;
}

struct node *insertionatbeginning(struct node *head)
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("enter the data to insert at first :");
    scanf("%d",&newnode->data);
    newnode->next = head;
    head = newnode;
    return head;
}

struct node *insertionatposition(struct node *head,int pos)
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

struct node* insertionatend(struct node *head)
{
    struct node *newnode, *temp = head;

    newnode = (struct node*)malloc(sizeof(struct node));

    printf("\nEnter new data to add at last: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;

    if(head == NULL)
    {
        return newnode;
    }

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newnode;

    return head;
}

struct node *deleteatbeginning(struct node *head)
{
    struct node *temp;
    if (head == NULL)
    {
        printf("list is empty!.");
        return head;
    }
    else
    {
        temp = head;
        head = head -> next;
        free(temp);
    }
    return head;
}

struct node *deleteatposition(struct node *head,int pos)
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

struct node *deleteend(struct node *head)
{
    struct node *temp;
    temp = head;
    if (head == NULL)
    {
        printf("list is empty!.\n");
        return head;
    }
    else
    {
        while(temp->next->next != NULL)
        {
            temp = temp -> next;
        }
        temp->next = NULL;
        free(temp->next);
    }
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
        printf("8. reversing of the original list.\n");
        int choice,pos,pos1;
        printf("enter your choice (1 - 8):");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("your list is :\n");
            display(head);
            break;
            case 2:
            head = insertionatbeginning(head);
            printf("element inserted sucessfully at the beginning.\n");
            display(head);
            break;
            case 3:
            printf("enter position to insert the element :");
            scanf("%d",&pos);
            head = insertionatposition(head,pos);
            printf("list after insertion at position %d\n",pos);
            display(head);
            break;
            case 4:
            head = insertionatend(head);
            printf("list after insertiong element at the end :\n");
            display(head);
            break;
            case 5:
            head = deleteatbeginning(head);
            printf("list after deleting element at beginning:\n");
            display(head);
            break;
            case 6:
            printf("enter position to delete the node :");
            scanf("%d",&pos1);
            head = deleteatposition(head,pos1);
            printf("list after deleting element at position %d :\n",pos1);
            display(head);
            break;
            case 7:
            head = deleteend(head);
            printf("list after deleting element at the end\n");
            display(head);
            break;
            case 8:
            head = reverse_list(head);
            printf("list after reversing original list!.\n");
            display(head);
            break;
            default:
            printf("please enter correct choice.\n");
        }
        printf("enter 1 to repeat and 0 to exit :");
        scanf("%d",&num);
        if(num != 1)
        {
            printf("program ended succesfully!.\n");
        }
    }
    return 0;
}