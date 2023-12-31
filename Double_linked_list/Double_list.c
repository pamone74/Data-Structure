/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Double_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamone <pamone@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:38:59 by pamone            #+#    #+#             */
/*   Updated: 2023/11/01 18:38:59 by pamone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Doubly_linked.h"
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
CDA_BOOL_t ENQ_is_list_empty(ENQ_ANCHOR_p_t list)
{
    // Will check if the head of the list is empty and return acording to the value of boolen. true or false
    return (list->name == NULL ? CDA_TRUE : CDA_FALSE);
}
// Add an item to the head list
ENQ_ITEM_p_t  ENQ_add_head(ENQ_ANCHOR_p_t list, ENQ_ITEM_p_t item)
{
    // Allocate the memory using malloc
    ENQ_ITEM_p_t mem = CDA_NEW(ENQ_ITEM_t);
    // Check if the list is empty, if it is true, create a new list and return
    if(ENQ_is_list_empty(list))
    {
        // Since we have ENQ_ITEM_p_t item, which is a struct, we need to extract the name member. if it was char *, we would not need extraction. we could have used mem->name = item
        mem->name = item->name;
        mem->blink = mem;
        mem->flink = mem;
        list = mem;
    }
    else
    {
        mem->flink = list;
        mem->name = item->name;
        list = mem;
    }
    return (ENQ_ITEM_p_t)list;
    
}
int main(void)
{
    // The test for ENQ_create_list and ENQ_create_item  is the same jut different numbers of parameters
    ENQ_ITEM_p_t test_create_list = ENQ_create_item("Study",6);
    printf("%s\n",test_create_list->name);
    //Test for the ENQ_is_list_empty
    printf("%d\n", ENQ_is_list_empty(test_create_list));
    // Testing for add-head
    ENQ_ITEM_p_t  pp = ENQ_create_item("amone", 6);
    ENQ_ITEM_p_t test_add_head = ENQ_add_head(test_create_list, pp);
    printf("%s\n", test_add_head->flink->name);
}













































































