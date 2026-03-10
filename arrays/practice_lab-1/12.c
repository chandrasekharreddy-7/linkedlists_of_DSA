#include <stdio.h>
int main()
{
    int a[50];
    int size, i;
    int max1, max2;
    printf("Enter size of array: ");
    scanf("%d", &size);
    if(size < 2)
    {
        printf("Need at least 2 elements.\n");
        return 0;
    }
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
    if(a[0] > a[1])
    {
        max1 = a[0];
        max2 = a[1];
    }
    else
    {
        max1 = a[1];
        max2 = a[0];
    }
    for(i = 2; i < size; i++)
    {
        if(a[i] > max1)
        {
            max2 = max1;
            max1 = a[i];
        }
        else if(a[i] > max2 && a[i] != max1)
        {
            max2 = a[i];
        }
    }
    printf("\n1st maximum = %d\n", max1);
    printf("2nd maximum = %d\n", max2);
    return 0;
}
