/***************************************************************************//**
    @file   ll_insert_at_end.c

    @brief  Inserts a node at the end of a list
*******************************************************************************/
#include "linked_list.h"

/*******************************************************************************
    ll_insert_at_end
*//**
    @brief  Inserts a node at the end of the list containing the given node
    @param  elem    Existing list node defining the list to append to
    @oaram  new     List node being inserted

    @return The node defined by elem
*******************************************************************************/
ll_node
ll_insert_at_end(ll_node elem, ll_node new)
{
    ll_node iter = elem;

    while (NULL_NODE != iter->next)
    {
        iter = iter->next;
    }

    iter->next = new;

    return elem;
}

