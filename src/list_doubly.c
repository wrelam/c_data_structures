/***************************************************************************//**
    @file   list_doubly.c

    @brief  Implementation of a doubly linked list
*******************************************************************************/
#include <stdlib.h>

#include "list_doubly.h"

/*******************************************************************************
    dll_create_node
*//**
    @brief  Allocates and returns an initialized node

    @return A new doubly linked list node
    @retval NULL_NODE   Failed to allocate new node
*******************************************************************************/
dll_node
dll_create_node(void)
{
    dll_node new = calloc(1, sizeof(struct dll_node));

    if (NULL != new)
    {
        new->next = NULL_NODE;
        new->prev = NULL_NODE;
        new->data = NULL;
    }

    return new;
}


/*******************************************************************************
    dll_destroy_node
*//**
    @brief  Destroys a given node
    @param  elem    List node being destroyed
*******************************************************************************/
void
dll_destroy_node(dll_node elem)
{
    free(elem);
}


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


/*******************************************************************************
    dll_insert_before
*//**
    @brief  Inserts one node after another
    @param  elem    List node having a node inserted before it
    @param  new     List node being inserted

    @return The frontmost node of the pair
*******************************************************************************/
dll_node
dll_insert_before(dll_node elem, dll_node new)
{
    new->prev = elem->prev;
    new->next = elem;
    elem->prev = new;
    return new;
}


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

