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
    @param  node    The node to destroy
*******************************************************************************/
void
ll_destroy_node(ll_node node)
{
    free(node);
}

