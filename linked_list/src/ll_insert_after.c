/***************************************************************************//**
    @file   ll_insert_after.c

    @brief  Inserts a node after another node
*******************************************************************************/
#include "linked_list.h"

/*******************************************************************************
    ll_insert_after
*//**
    @brief  Inserts one node after another
    @param  base    The node receiving a new next node
    @param  new     The node being inserted

    @return The base node
*******************************************************************************/
ll_node
ll_insert_after(ll_node base, ll_node new)
{
    new->next = base->next;
    base->next = new;
    return base;
}

