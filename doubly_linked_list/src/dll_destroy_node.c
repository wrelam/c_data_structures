/***************************************************************************//**
    @file   dll_destroy_node.c

    @brief  Destroys a node
*******************************************************************************/
#include <stdlib.h>

#include "doubly_linked_list.h"

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

