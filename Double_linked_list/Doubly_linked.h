/*
    In this private header, there are implementation of some methods of doubly linked list.
    these are 
        • Create a new doubly linked list 
        • Create a new enqueuable item 
        • Test whether an item is enqueued 
        • Test whether a list is empty 
        • Add an item to the head of a list 
        • Add an item to the tail of a list 
        • Add an item after a previously enqueued item 
        • Add an item before a previously enqueued item 
        • Dequeue an item from a list 
        • Dequeue the item at the head of a list
        • Dequeue the item at the tail of a list 
        • Get the item at the head of a list (without dequeing it) 
        • Get the item at the tail of a list 
        • Given an item, get the following item 
        • Given an item, get the previous item 
        • Get the name of a list 
        • Get the name of an item 
        • Destroy an item 
        • Empty a list 
        • Destroy a list
*/
#ifndef DOUBLY_H
#define DOUBLY_H
#include <stdio.h>
#include <stdlib.h>

typedef struct enq_item_s
{
    struct enq_item_s *flink;
    struct enq_item_s *blink;
    char               *name;
}ENQ_ITEM_t, *ENQ_ITEM_p_t;
typedef ENQ_ITEM_t ENQ_ANCHOR_t, *ENQ_ANCHOR_p_t;
ENQ_ITEM_p_t ENQ_create_item(const char *name, size_t size);
ENQ_ANCHOR_p_t ENQ_create_list(const char *name);
CDA_BOOL_t ENQ_is_item_enqed(ENQ_ITEM_p_t item);
#endif