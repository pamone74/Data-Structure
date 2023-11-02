#include "sorting.h"
static int count1 = 0;
/*
    Bubble sort:
        The bubble sort algorithm moves sequentially through a list of data structures
        dividing into a sorted and unsorted part. A bubble sort starts at the end of the list, comopares adjacent elements ans swaps them if the right element is less than the left hand element. 
        With succesive passes through the list, each member percolates or bubbles to its sorted posotion at the beginning of the list. 

*/
void SORT_SWAP(SORT_UINT8_t *item1, SORT_UINT8_t *item2)
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