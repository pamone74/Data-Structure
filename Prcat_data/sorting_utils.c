#include "header.h"
void ft_swap(int *item1,int *item2)
{
    int temp = *item1;
    *item1 = *item2;
    *item2 = temp;
}
void bubble_sort(int *tab, int size)
{
    int i = 0;
    int flag = 0;
    while(i < size -1)
    {
        int j = 0;
        while(j < size - 1 - i)
        {
            if(tab[j] > tab[j + 1])
            {
                ft_swap(&tab[j], &tab[j + 1]);
                flag = 1;
            }
            j++;
        }
        if(!flag)
            break;
        i++;
    }
}
void selection_sort(int *tab, int size)
{
    int i = 0;
    while(i < size -1)
    {
        int min  = i;
        int j  = i + 1;
        while(j < size)
        {
            if(tab[j] < tab[min])
                min = j;
            j++; 
        }
        if(min != i)
        {
            ft_swap(&tab[min], &tab[i]);
        }
        i++;
    }
}
void insertio_sort(int *tab, int size)
{
    int i = 1;
    /*
        iterates from the first element till the end of the array ie(1 to N) where N is the size of the array
        We are starting from 1 because, inseriont sort iterates over unsorted list and shift the elements to be sorted in a right position
        The intial 1 position is considered to be unsorted array
    */
    while(i < size)
    {
        /*
            Create a temporary varaiable to store the value of element to shifted
            The  variable j will start from i - 1, because it is considered to be the sorted sub arrays
            So in the while loop, if j>=0 (will iterates untill we reach the first element)and the element[j] is greater than the temp
            If the above conditions are both true, the while loop block will be executed meaning that we shall be shifting the value[j] to right
                by tab[j + 1] = tab[j]; then j will be decremented:
            once the loop ends, the next tab[j + 1] will be updated by assigning the value of temp;
        */
        int temp = tab[i];
        int j = i - 1;
        while(j >= 0 && tab[j] > temp)
        {
            tab[j + 1] = tab[j];
            j--;
        }
        tab[j+ 1] = temp;
        i++;
    }
}

/*
    QUICK SORT:
        The quick sort is divide and conquer strategy, that uses pivot and sorting the elements into partitions: partion1 that will be the elemets
        lower than the pivot and the partition2 are the elements larger than pivot
        It takes two variables, start and end where the start is the startof the array and end is the end of the array
        If the element at start is less than or equals the pivot, it increments, if the elements and end is greater than the pivot, it derement
        IF the start is less than the end, we shall swap the value at start and the value at the end
        If the start is greater than the end we shall swap the pivot and the end: 

*/
int partition(int *tab, int start_arr, int end_array)
{
    int start = start_arr;
    int end = end_array;
    // Taking the first element of the array as the pivot;
    int pivot = tab[start];
    while (start < end)
    {
        while(tab[start] <= pivot)
            start ++;
        while(tab[end] > pivot)
            end --;
        if(start < end)
            ft_swap(&tab[start], &tab[end]);
    }
    // When we come out of the loop, it means that start is greater than the end, so we shall swap the pivot and the end
    ft_swap(&tab[end], &tab[start_arr]);
    /*
        if we swap the end and the pivot, our pivot will be at the end th position, for example:
            if the end is poiting to 7, and pivot is 13  {3 , 8 , 9,  10, 7, 15,63,78,52}
            The array after swaping the ivot and end wil be {7 , 8 , 9,  10, 13, 15,63,78,52};
            whereby 3 is our pivot and the elements on the left partion are less than 13, while the elements on the right side are greater than pivot
            Therefore we will return the end.
    */
return end;
    
}
void quick_sort(int *tab, int start, int end)
{
    if(start < end)
    {
        int locaton = partition(tab, start, end);
        // run the quick sort recursively for left partition and for right partiton
        quick_sort(tab, start, locaton -1 );
        quick_sort(tab, locaton  + 1, end );
    }
    
    
}
int main(void)
{
    int tab[10] = {1,0,2,5,9,4,8,9,6,2};
    quick_sort(tab, 0, 9);
    for(int i = 0; i < 10; i++)
    {
        printf("%d", tab[i]);
    }
}