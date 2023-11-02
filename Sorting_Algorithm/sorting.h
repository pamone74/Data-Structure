#ifndef SORT_H
#define SORT_H
#include "sorting_macros.h"
#include <stdio.h>
#include <stdlib.h>
static int count = 0;
void Buble_sort(int *tab, SORT_UINT8_t size);
void SORT_SWAP(int *item1, int *item2);
void Selection_sort(int *tab, int size);
void merge_sort(int *tab, int lower, int upper);
#endif