/***************************************************************************//**
    @file   dll_create_node.c

    @brief  Creates a new doubly linked list node
*******************************************************************************/
#include <stdlib.h>

#include "doubly_linked_list.h"

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

