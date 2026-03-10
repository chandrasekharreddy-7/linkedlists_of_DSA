#include <stdio.h>
int main()
{
    int marks[50];
    int size, i;
    int left, right, temp;
    printf("Enter number of students: ");
    scanf("%d", &size);
    for(i = 0; i < size; i++)
    {
        printf("Enter marks of student %d: ", i + 1);
        scanf("%d", &marks[i]);
    }
    printf("\nOriginal marks list:\n");
    for(i = 0; i < size; i++)
    {
        printf("%d\t", marks[i]);
    }
    left = 0;
    right = size - 1;
    while(left < right)
    {
        temp = marks[left];
        marks[left] = marks[right];
        marks[right] = temp;

        left++;
        right--;
    }
    printf("\nReversed marks list:\n");
    for(i = 0; i < size; i++)
    {
        printf("%d\t", marks[i]);
    }
    return 0;
}