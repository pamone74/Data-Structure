#include "sorting.h"
/*
    Bubble sort:
        The bubble sort algorithm moves sequentially through a list of data structures
        dividing into a sorted and unsorted part. A bubble sort starts at the end of the list, comopares adjacent elements ans swaps them if the right element is less than the left hand element. 
        With succesive passes through the list, each member percolates or bubbles to its sorted posotion at the beginning of the list. 

*/
void SORT_SWAP(int *item1, int *item2)
{
    SORT_UINT8_t temp = *item1;
    *item1 = *item2;
    *item2 = temp;
}
/*
    The Buble_sort() takes an array of integer, and sort it in space
    There are few variables used:
        size  ->  this is the size of the array
        flag  ->  This is a control mechanism for avoiding iteration if 
                  the array is already sorted.
        
*/
void Buble_sort(int *tab, SORT_UINT8_t size)
{
    SORT_UINT8_t flag = 0;
    SORT_UINT8_t i = 0;
    while(i < size - 1)
    {
        SORT_UINT8_t j = 0;
        // size-i-1 this is for the control staruture to iterates only over unsorted item leaving out the sorted ones.
        while(j < size - i - 1)
        {
            if(tab[j] > tab[j + 1])
            {
               SORT_SWAP(&tab[j], &tab[j+1]);
               flag = 1;
            }
            j ++;
        }
        i++;
        if(flag == 0)
            break;
    }

}

/*
    Select Sort:
        A selection sort looks a lot like a bubble sort. It moves iteratively through a list of data structures, dividing the list into a sorted and an unsorted part
        The pseudocode looks like this: 
        numElements = number of structures to be sorted 
        for ( inx = 0 ; inx < numElements - 1 ; ++inx ) 
        least = inx 
        for ( jnx = inx + 1 ; jnx < numElements ; ++jnx ) 
        if ( element( least ) > element( jnx ) ) 
        least = jnx 
        swap( element( least ), element( inx ) ) 
*/

void Selection_sort(int *tab, int size)
{
    int i = 0;
    
    while(i < size -1)
    {
        int min = i;
        int j = i + 1;
        while(j < size)
        {
            if(tab[j] < tab[min])
                min = j;
            j++;
        }
        if(min != i)
            SORT_SWAP(&tab[i], &tab[min]);
        i++;
    }
}
void merge(int * tab, int lower, int mid_point, int upper)
{
    int i = lower;
    int j = mid_point;
    int k = upper;
    int tab_b[256];
    while(i <= mid_point && j <= upper)
    {
        if(tab[i] <= tab[j])
        { 
            tab_b[k++] = tab[i++];
        }
        else
            tab_b[k++] = tab[j++];
    }
    if(i < mid_point)
    {   while (j <= upper)
            tab_b[k++] = tab[j++];
    }
    else
    {
        while(i <= mid_point)
            tab_b[k++] = tab[i++];
    }
    
    for(k = lower; k < upper; k++)
    {
        tab[k] = tab_b[k];
    }
       
}
/*
    The merge sort:
        This is divide and conquor, divide the list into sublist the merge 
        each item one by one into the list
    
*/
void merge_sort(int *tab, int lower, int upper)
{
    if(lower <= upper)
    {
            int mid_point = (lower + upper)/2;
            //This call recursively from the start of  array to the mid_point
            merge_sort(tab, lower, mid_point); 
            //This call recursively from the mid_point of  array to the end (upper)
            merge_sort(tab, mid_point + 1, upper); 
            merge(tab, lower, mid_point, upper);
    }


}






















































