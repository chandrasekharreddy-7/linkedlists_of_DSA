#include <stdio.h>
int main()
{
    int a[50];
    int size, i;
    int *start, *end;
    printf("Enter size of array: ");
    scanf("%d", &size);
    for(i = 0; i < size; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &a[i]);
    }
    printf("Original array:\n");
    for(i = 0; i < size; i++)
    {
        printf("%d\t", a[i]);
    }
    start = a;
    end = a + size - 1;
    while(start < end)
    {
        int temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
    printf("\nReversed array:\n");
    for(i = 0; i < size; i++)
    {
        printf("%d\t", a[i]);
    }
    return 0;
}