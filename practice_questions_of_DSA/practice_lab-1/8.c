#include <stdio.h>
int main()
{
    int a[50];
    int pos,size,i;
    printf("enter size of array :");
    scanf("%d",&size);
    if(size > 50)
    {
        printf("memory full!");
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
    printf("enter position upto reverse the elements :");
    scanf("%d",&pos);
    if(pos > size || pos <= 1)
    {
        if(pos == 1)
        {
            printf("minimum two elements required to reverse.\n");
            return 0;
        }
        else
        {
        return printf("please enter correct position");
        }
    }
    for(i = 0;i < pos/2;i++)
    {
        int temp = a[i];
        a[i] = a[pos-1-i];
        a[pos-1-i] = temp;
    }
    printf("array after reversing elements upto %d position.\n",pos);
    for(i = 0;i < size;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n");
    return 0;
}