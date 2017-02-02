/***************************************************************************//**
    @file   dll_insert_at_end.c

    @brief  Inserts a node at the end of the list
*******************************************************************************/
#include "doubly_linked_list.h"

/*******************************************************************************
    dll_insert_at_end
*//**
    @brief  Inserts a node at the end of a list
    @param  elem    Existing node in the list to be appended to
    @param  new     List node being inserted

    @see    dll_insert_after()

    @return The node defined by elem
*******************************************************************************/
dll_node
dll_insert_at_end(dll_node elem, dll_node new)
{
    dll_node iter = elem;

    while (NULL_NODE != iter->next)
    {
        iter = iter->next;
    }

    dll_insert_after(iter, new);

    return elem;
}

