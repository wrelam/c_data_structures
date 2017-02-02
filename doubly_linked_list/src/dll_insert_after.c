/***************************************************************************//**
    @file   dll_insert_after.c

    @brief  Inserts a node after another node
*******************************************************************************/
#include "doubly_linked_list.h"

/*******************************************************************************
    dll_insert_after
*//**
    @brief  Inserts one node after another
    @param  elem    List node having a node inserted after it
    @param  new     List node being inserted

    @return The frontmost node of the pair
*******************************************************************************/
dll_node
dll_insert_after(dll_node elem, dll_node new)
{
    new->prev = elem;
    new->next = elem->next;
    elem->next->prev = new;
    elem->next = new;
    return elem;
}

