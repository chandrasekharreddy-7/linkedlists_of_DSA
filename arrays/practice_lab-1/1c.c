#include <stdio.h>
int main()
{
    int a[50];
    int size,i,num;
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
    printf("enter element to enter insert at last :");
    scanf("%d",&num);
    a[size] = num;
    size++;
    printf("array after insertion of '%d' at end :\n",num);
    for(i = 0;i < size;i++)
    {
        printf("%d\t",a[i]);
    }
    return 0;
}