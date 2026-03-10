#include <stdio.h>
int main()
{
    int a[50];
    int num, i, size, pos = -1;
    printf("Enter size of array: ");
    scanf("%d", &size);
    for(i = 0; i < size; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &a[i]);
    }
    printf("Entered elements are:\n");
    for(i = 0; i < size; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\nEnter element to delete: ");
    scanf("%d", &num);
    for(i = 0; i < size; i++)
    {
        if(a[i] == num)
        {
            pos = i;
            break; 
        }
    }
    if(pos == -1)
    {
        printf("Element not found.\n");
        return 0;
    }
    for(i = pos; i < size - 1; i++)
    {
        a[i] = a[i + 1];
    }
    size--;
    printf("Array after deleting %d:\n", num);
    for(i = 0; i < size; i++)
    {
        printf("%d\t", a[i]);
    }
    return 0;
}