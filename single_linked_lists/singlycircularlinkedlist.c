#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *create()
{
    struct node *head = NULL,*newnode = NULL,*temp = NULL;
    int choice = 1;
    while (choice == 1)
    {
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter data :");
    scanf("%d",&newnode -> data);
    newnode -> next = NULL;
    if (head == NULL)
    {
        head = newnode;
        temp = newnode;
    }
    else
    {
        temp->next = newnode;
        temp = newnode;
    }
    printf("enter 0 to exit 1 to continue :");
    scanf("%d",&choice);
    }
    temp -> next = head;
    return head;
}

void display(struct node *head)
{
    struct node *temp = head;
    if(head == NULL)
    {
        printf("list is empty!");
        return;
    }
    printf("%d -> ",temp -> data);
    temp = temp -> next;
    while (temp != head)
    {
        printf("%d -> ",temp -> data);
        temp = temp -> next;
    }
    printf("back to head!\n");
}

struct node *insertatbeginning(struct node *head)
{
    struct node *newnode,*temp;

    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter data to insert at beginning :");
    scanf("%d",&newnode -> data);
    if(head == NULL)
    {
        newnode -> next = newnode;
        head  = newnode;
    }
    else
    {
        temp = head;
        while(temp -> next != head)
        {
            temp = temp -> next;
        }
        newnode -> next = head;
        temp -> next = newnode;
        head = newnode;
    }
    return head;
}

struct node *insertatposition(struct node *head,int pos)
{
    struct node *newnode, *temp;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("enter data: ");
    scanf("%d", &newnode->data);
    if (pos == 1)
    {
        temp = head;
    while(temp -> next != head)
    {
        temp = temp -> next;
    }
    newnode -> next = head;
    temp -> next = newnode;
    head = newnode;
    return head;
    }
    temp = head;
    int i = 1;
    while(i < pos-1)
    {
        temp = temp -> next;
        i++;
    }
    newnode -> next = temp -> next;
    temp -> next = newnode;
    return head;
}

struct node *insertionatend(struct node *head)
{
    struct node *temp,*newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter data to insert at end of the list :");
    scanf("%d",&newnode -> data);
    temp = head;
    if(head == NULL)
    {
        head = newnode;
        newnode -> next = head;
        return head;
    }
    if (temp -> next == head)
    {
        temp -> next = newnode;
        newnode -> next = head;
        return head;
    }
    while(temp -> next != head)
    {
        temp = temp -> next;
    }
    temp -> next = newnode;
    newnode -> next = head;
    return head;
}

struct node *deleteatbeginning(struct node *head)
{
    if(head == NULL)
    {
        printf("list is empty!.\n");
        return NULL;
    }
    struct node *temp = head;
    if(head->next == head)
    {
        free(head);
        return NULL;
    }
    while(temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = head->next;
    free(head);
    head = temp->next;
    return head;
}

struct node *deleteatposition(struct node *head, int pos)
{
    if (head == NULL)
        return NULL;
    int i;
    if (pos == 1)
    {
        struct node *temp = head;
        while (temp->next != head)
            temp = temp->next;
        if (head->next == head)
        {
            free(head);
            return NULL;
        }
        temp->next = head->next;
        free(head);
        head = temp->next;
        return head;
    }
    struct node *current = head;
    for (i = 1; i < pos - 1; i++)
        current = current->next;
    struct node *to_delete = current->next;
    current->next = to_delete->next;
    free(to_delete);
    return head;
}

struct node *deleteend(struct node *head) {
    struct node *temp, *prev;
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }
    if (head->next == head) {
        free(head);
        head = NULL;
        return head;
    }
    temp = head;
    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = head;
    free(temp);
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
            printf("your list is :\n");
            display(head);
            break;
            case 2:
            head = insertatbeginning(head);
            printf("element inserted sucessfully at the beginning.\n");
            display(head);
            break;
            case 3:
            printf("enter position to insert the element :");
            scanf("%d",&pos);
            head = insertatposition(head,pos);
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