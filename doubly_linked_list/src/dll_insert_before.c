/***************************************************************************//**
    @file   dll_insert_before.c

    @brief  Inserts a node before another node
*******************************************************************************/
#include "doubly_linked_list.h"

/*******************************************************************************
    dll_insert_before
*//**
    @brief  Inserts one node after another
    @param  elem    List node having a node inserted before it
    @param  new     List node being inserted

    @return The frontmost node of the pair
*******************************************************************************/
dll_node
dll_insert_after(dll_node elem, dll_node new)
{
    new->prev = elem->prev;
    new->next = elem;
    elem->prev = new;
    return new;
}

