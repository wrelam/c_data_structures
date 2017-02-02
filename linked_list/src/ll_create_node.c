/***************************************************************************//**
    @file   ll_create_node.c

    @brief  Creates a new linked list node
*******************************************************************************/
#include <stdlib.h>

#include "linked_list.h"

/*******************************************************************************
    ll_create_node
*//**
    @brief  Allocates and returns an initialized node

    @return A new linked list node
    @retval NULL_NODE   Failed to allocate new node
*******************************************************************************/
ll_node
ll_create_node(void)
{
    return (ll_node) calloc(1, sizeof(struct ll_node));
}

