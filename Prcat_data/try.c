#include "header.h"
/*
This is to try just the sort alogirthms, buble sort, selcetion sort, insertin sort, 

*/
void ft_swap(int *item1, int *item2)
{
    int temp = *item1;
    *item1 = *item2;
    *item2 = temp;
}
void bubble_sort(int *tab, int size)
{
    int flag = 0;
    int i  = 0;
    while(i < size - 1)
    {
        int j = 0;
        while(j < size -1 - i)
        {
            if(tab[j + 1] < tab[j])
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
// selection sort

void selction_sort(int *tab, int size)
{
    int i = 0;
    while(i < size)
    {
        int min = i;
        int j   = i + 1;
        while(j < size)
        {
            if(tab[j] < tab[i])
                min = j;
            j++;    
        }
        ft_swap(&tab[min], &tab[i]);
        i++;

    }
}
// insertion sort:

void insertion_sort(int *tab, int size)
{
    int i = 1;
    while(i < size)
    {
        int temp = tab[i];
        int j = i - 1;
        while(j >= 0 && tab[j] > temp)
        {
            tab[j + 1]  = tab[j];
            j--;
        }
        tab[j + 1] = temp;
        i++;
    }
}

// Implemtation of the quick_sort algorithm
int partition(int *tab, int start_arr, int end_array)
{
    int start = start_arr;
    int end = end_array;
    int pivot = tab[start];
    while(start < end)
    {
        while(tab[start] <= pivot)
            start ++;
        while(tab[end] > pivot)
            end --;
        if(start < end)
            ft_swap(&tab[start], &tab[end]);
    }
    ft_swap(&tab[end], &tab[start_arr]);
    return end;
}
void quick_sort(int *tab, int start, int end)
{
    if(start < end)
    {
        int position = partition(tab, start, end);
        quick_sort(tab, start, position - 1);
        quick_sort(tab, position + 1, end);
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