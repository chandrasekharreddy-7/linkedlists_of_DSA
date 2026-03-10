/*Search an element and insert another element next to it.*/
# include <stdio.h>
int main()
{
    int a[50];
    int size,i,num,j;
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
    printf("enter element to search and to insert after that :");
    scanf("%d",&num);
    printf("enter element to insert :");
    scanf("%d",&j);
    int found = 0;
    int index;
    for(i = 0;i < size;i++)
    {
        if(num == a[i])
        {
            index = i;
            found = 1;
            break;
        }
    }
    if(found == 0)
    {
        printf("element %d is not found!.\n",num);
        return 0;
    }
    for(i = size;i > index + 1;i--)
    {
        a[i] = a[i-1];
    }
    a[index+1] = j;
    size++;
    printf("array after inserting element %d after %d :\n",j,num);
    for(i = 0;i < size;i++)
    {
        printf("%d\t",a[i]);
    } 
    printf("\n");
    return 0;
}