#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 40

struct student{
    int ID;
    int score;
};

//quick_sort
void sort(int first, int last, struct student *student);
//swap data in a & b
void swap(struct student *a,struct student *b);
//print all data in student[]
void print_student(struct student *student,int num); 

int main()
{
    int num;
    struct student student[MAX_SIZE]; 
    scanf(" %d", &num);
    for(int i = 0;i < num;i++)
    {
        //printf("Enter ID & score:");
        scanf(" %d %d", &student[i].ID, &student[i].score);
    }
    sort(0,num-1,student);
    print_student(student, num);
    return 0;
}

void sort(int left, int right, struct student *student)
{    
    if(left >= right)
    {
        return; 
    }

    /**
     * Quicksort
     * 1. set the rightmost place as pivot
     * 2. Put the value smaller than pivot's value on the left, the value bigger or equal on the right, and pivot in the middle
     * 3. Continue to do the same with the subarray by using recursion
     */

    int pivot = right;
    int i = left - 1;
    for (int j = left; j < right; j++) 
    {
        // Start from the leftmost by j to find if there is a value smaller than the pivot's value 
        // If there is, put it in order from the leftmost, that is, the position of i
        if (student[j].ID < student[pivot].ID) 
        {
            i++;
            swap(&student[i], &student[j]);
        }
    }
    //put pivot next to the last one smaller than its value
    i++;
    swap(&student[i], &student[pivot]);
    pivot = i;

    sort(left,pivot-1,student);
    sort(pivot+1,right,student);

    /* other method */
    /*
    int i = left;
    int j = right - 1;
    int pivot = right;

    while(i < j)
    {
        for( ; student[i].ID <= student[piovt].ID && i < j ; i++ );
        for( ; student[j].ID > student[piovt].ID && i < j ; j-- );
        if(i < j)
        {
            swap(&student[i],&student[j]);
        }
    }
    
    if(student[i].ID > student[pivot].ID) 
    {
        swap(&student[i],&student[right]);
        pivot = i;
    }
    else
    {
        swap(&student[i+1],&student[pivot]);
        pivot = i+1;
    }
    
    sort(left,pivot-1,student);
    sort(pivot+1,right,student);
    */
}

void swap(struct student *a,struct student *b)
{
    struct student temp = *a;
    *a = *b;
    *b = temp;
}

void print_student(struct student *student,int num)
{
    printf("ID\tscore\n");
    for(int i = 0;i < num;i++)
    {
        printf("%d\t%d\n",student[i].ID,student[i].score);
    }
}