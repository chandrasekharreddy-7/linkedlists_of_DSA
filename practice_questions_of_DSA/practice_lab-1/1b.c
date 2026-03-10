#include <stdio.h>
int main()
{
    int a[50];
    int size,i,num,pos;
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
    printf("enter element to enter insert :");
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
    printf("array after insertion of '%d' at position %d :\n",num,pos);
    for(i = 0;i < size;i++)
    {
        printf("%d\t",a[i]);
    }
    return 0;
}