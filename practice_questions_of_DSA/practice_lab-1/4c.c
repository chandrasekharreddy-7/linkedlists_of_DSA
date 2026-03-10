#include <stdio.h>
int main()
{
    int a[50];
    int size,i,pos;
    printf("enter the size of array :");
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
    printf("enter position to delete the element :");
    scanf("%d",&pos);
    if (pos < 1 || pos > size)
    {
        printf("please enter correct position.");
        return 0;
    }
    for(i = pos-1;i < size-1;i++)
    {
        a[i] = a[i+1];
    }
    size--;
    printf("array after deleting at element '%d' :\n",pos);
    for(i = 0;i < size;i++)
    {
        printf("%d\t",a[i]);
    }
    return 0;
}