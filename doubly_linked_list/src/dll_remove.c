/***************************************************************************//**
    @file   dll_remove.c

    @brief  Removes a node from the list to which it belongs
*******************************************************************************/
#include "doubly_linked_list.h"

/*******************************************************************************
    dll_remove
*//**
    @brief  Removes a node from the list to which it belongs
    @param  elem    The list node to remove
*******************************************************************************/
void
dll_remove(dll_node elem)
{
    if (NULL_NODE != elem)
    {
        if (NULL_NODE != elem->next)
        {
            elem->next->prev = elem->prev;
        }

        if (NULL_NODE != elem->prev)
        {
            elem->prev->next = elem->next;
        }
    }
}

