#include <stdio.h>
int main()
{
    int a[50];
    int size, i, num, pos;
    printf("Enter size of sorted array : ");
    scanf("%d", &size);
    printf("Enter sorted elements :\n");
    for(i = 0; i < size; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("entered elements are :\n");
    for(i = 0;i < size;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n");
    printf("Enter element to insert: ");
    scanf("%d", &num);
    if(size >= 50)
    {
        printf("Array is full. Cannot insert.\n");
        return 0;
    }
    for(i = 0; i < size; i++)
    {
        if(a[i] > num)
            break;
    }
    pos = i;
    for(i = size; i > pos; i--)
    {
        a[i] = a[i - 1];
    }
    a[pos] = num;
    size++;
    printf("Array after insertion :\n");
    for(i = 0; i < size; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
    return 0;
}