#include <stdio.h>
int main()
{
    int a[50];
    int size,i,num;
    printf("enter size of array: ");
    scanf("%d", &size);
    for(i = 0; i < size; i++)
    {
        printf("enter element %d: ", i + 1);
        scanf("%d", &a[i]);
    }
    printf("entered elements are:\n");
    for(i = 0; i < size; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
    printf("enter element to count no of times it repeated :");
    scanf("%d",&num);
    int count = 0;
    for(i = 0;i < size;i++)
    {
        if(num == a[i])
        {
            count++;
        }
    }
    if(count == 0)
    {
        printf("element %d not found in the array.\n",num);
        return 0;
    }
    else
    {
        printf("%d is repeated for %d times.",num,count);
    }
    return 0;
}