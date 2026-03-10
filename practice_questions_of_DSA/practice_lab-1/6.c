#include <stdio.h>
int main()
{
    int a[50];
    int size, i, num, j = 0;
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
        if(a[i] != num)
        {
            a[j] = a[i];
            j++;
        }
    }
    if(j == size)
    {
        printf("Element not found.\n");
        return 0;
    }
    size = j;
    printf("Array after deleting all occurrences of %d:\n", num);
    for(i = 0; i < size; i++)
    {
        printf("%d\t", a[i]);
    }
    return 0;
}
