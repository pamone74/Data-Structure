#include "Doubly_linked.h"
#include "../cdap.h"
ENQ_ANCHOR_p_t ENQ_create_list(const char *name)
{
    // Returns the address of the list
    // The caller is resposible for freeing the memory occupied by the when invoked in main function
    // The list name is occupied into a private buffer which is freed when the list is destroyed
    ENQ_ANCHOR_p_t list = CDA_NEW( ENQ_ANCHOR_t);
    list->flink = list; 
    // Using list now is equivalen to null because it is empty at this point
    list->blink = list;
    list->name = CDA_NEW_STR_IF( name );
    return list;
}

// Create Item
/*
    Creating new item is actuall the same as creating new list
    Allocate the space for the item, the initialize it to the unenqueued state.
    The only difference between them is that, this one allocate mem of specified amount of bytes.
*/
ENQ_ITEM_p_t ENQ_create_item(const char *name, size_t size)
{
    ENQ_ITEM_p_t item = (ENQ_ITEM_p_t)CDA_malloc(size);
    CDA_ASSERT(size >= sizeof(ENQ_ITEM_t)/sizeof(ENQ_ITEM_p_t));
    item->flink = item;
    item->blink = item;
    item->name = CDA_NEW_STR_IF(name);
    return item;
}
//  Test Whether an Item is Enqueued 

CDA_BOOL_t ENQ_is_item_enqed(ENQ_ITEM_p_t item)
{
    CDA_BOOL_t rcode = (item->flink==item ? CDA_TRUE : CDA_FALSE);
    return rcode;
}
int main(void)
{
    // The test for ENQ_create_list and ENQ_create_item  is the same jut different numbers of parameters
    ENQ_ITEM_p_t test_create_list = ENQ_create_item("Study",6);
    printf("%s",test_create_list->name);
}













































































