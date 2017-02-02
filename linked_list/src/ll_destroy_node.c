/***************************************************************************//**
    @file   ll_destroy_node.c

    @brief  Destroys a node
*******************************************************************************/
#include <stdlib.h>

#include "linked_list.h"

/*******************************************************************************
    ll_destroy_node
*//**
    @brief  Destroys a given node
    @param  elem    List node being destroyed
*******************************************************************************/
void
ll_destroy_node(ll_node elem)
{
    free(elem);
}

