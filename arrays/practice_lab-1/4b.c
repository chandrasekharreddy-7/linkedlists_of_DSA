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
    size--;
    printf("array after deleting at the end :\n");
    for(i = 0;i < size;i++)
    {
        printf("%d\t",a[i]);
    }
    return 0;
}