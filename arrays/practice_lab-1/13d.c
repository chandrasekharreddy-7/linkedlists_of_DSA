#include <stdio.h>
int main()
{
    int marks[50];
    int size, i;
    int sum = 0;
    float average;
    printf("Enter number of students: ");
    scanf("%d", &size);
    if(size <= 0 || size > 50)
    {
        printf("Invalid number of students!\n");
        return 0;
    }
    for(i = 0; i < size; i++)
    {
        printf("Enter marks of student %d: ", i + 1);
        scanf("%d", &marks[i]);
        sum += marks[i];
    }
    average = (float)sum / size;
    printf("\nTotal marks = %d\n", sum);
    printf("Class average = %.2f\n", average);
    return 0;
}