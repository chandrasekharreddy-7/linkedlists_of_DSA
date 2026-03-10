#include <stdio.h>
int main()
{
    int marks[50];
    int size, i, j = 0;
    printf("Enter number of students: ");
    scanf("%d", &size);
    for(i = 0; i < size; i++)
    {
        printf("Enter marks of student %d: ", i + 1);
        scanf("%d", &marks[i]);
    }
    printf("\nOriginal marks:\n");
    for(i = 0; i < size; i++)
    {
        printf("%d\t", marks[i]);
    }
    for(i = 0; i < size; i++)
    {
        if(marks[i] >= 40)
        {
            marks[j] = marks[i];
            j++;
        }
    }
    if(j == size)
    {
        printf("\nNo failed students to delete.\n");
    }
    else
    {
        size = j;

        printf("\nMarks after deleting failed students:\n");
        for(i = 0; i < size; i++)
        {
            printf("%d\t", marks[i]);
        }
    }
    return 0;
}