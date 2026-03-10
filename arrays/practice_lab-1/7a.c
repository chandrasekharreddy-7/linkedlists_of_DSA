#include <stdio.h>
int main()
{
    int a[50];
    int size,i,temp;
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
    for(i = 0;i < size/2;i++)
    {
        temp = a[i];
        a[i] = a[size-1-i];
        a[size-1-i] = temp;
    }
    printf("array after reversing with temp third variable :\n");
    for(i = 0;i < size;i++)
    {
        printf("%d\t",a[i]);
    }
    return 0;
}