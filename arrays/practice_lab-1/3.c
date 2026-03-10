#include <stdio.h>
int main()
{
    int a[50];
    int num,i,pos,size;
    printf("enter size of array :");
    scanf("%d",&size);
    if(size >= 50)
    {
        printf("Array is full. Cannot insert.\n");
        return 0;
    }
    for(i = 0;i < size;i++)
    {
        printf("enter element %d :",i+1);
        scanf("%d",&a[i]);
    }
    printf("entered elements are :\n");
    for(i = 0;i < size;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n");
    int choice = 1;
    while(choice == 1)
    {
        if (size > 50)
        {
            printf("Array is full. Cannot insert.\n");
            break;
        }
        num = 0;
        printf("enter element to insert :");
        scanf("%d",&num);
        printf("enter position to insert :");
        scanf("%d",&pos);
        if ((pos > size) || (pos < 1))
        {
            printf("please enter correct position.\n");
            return 0;
        }
        for(i = size-1;i >= pos-1;i--)
        {
            a[i+1] = a[i];
        }
        a[pos-1] = num;
        size++;
        printf("enter 1 to insert and 0 to exit :");
        scanf("%d",&choice);
    }
    for(i = 0;i < size;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n");
    return 0;
}