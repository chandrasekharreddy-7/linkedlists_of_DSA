#include <stdio.h>
int main()
{
    int marks[50];
    int size, i, new_marks;
    printf("Enter number of students: ");
    scanf("%d", &size);
    if(size >= 50)
    {
        printf("Cannot insert. Array is full!\n");
        return 0;
    }
    for(i = 0; i < size; i++)
    {
        printf("Enter marks of student %d: ", i + 1);
        scanf("%d", &marks[i]);
    }
    printf("\nStudent marks are:\n");
    for(i = 0; i < size; i++)
    {
        printf("%d\t", marks[i]);
    }
    printf("\nEnter marks of new student: ");
    scanf("%d", &new_marks);
    marks[size] = new_marks;
    size++;
    printf("\nMarks after inserting new student:\n");
    for(i = 0; i < size; i++)
    {
        printf("%d\t", marks[i]);
    }
    return 0;
}