/***************************************************************************//**
    @file   ll_insert_after.c

    @brief  Inserts a node after another node
*******************************************************************************/
#include "linked_list.h"

/*******************************************************************************
    ll_insert_after
*//**
    @brief  Inserts one node after another
    @param  elem    List node having a node inserted after it
    @param  new     List node being inserted

    @return The frontmost node of the pair
*******************************************************************************/
ll_node
ll_insert_after(ll_node elem, ll_node new)
{
    new->next = elem->next;
    elem->next = new;
    return elem;
}

