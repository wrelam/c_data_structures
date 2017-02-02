/***************************************************************************//**
    @file   ll_insert_before.c

    @brief  Inserts a node before another node
*******************************************************************************/
#include "linked_list.h"

/*******************************************************************************
    ll_insert_before
*//**
    @brief  Inserts one node before another
    @param  elem    List node having a node inserted before it
    @param  new     List node being inserted

    @return The frontmost node of the pair
*******************************************************************************/
ll_node
ll_insert_before(ll_node elem, ll_node new)
{
    new->next = elem;
    return new;
}

