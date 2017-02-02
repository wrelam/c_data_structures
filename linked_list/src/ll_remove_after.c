/***************************************************************************//**
    @file   ll_remove_after.c

    @brief  Removes the node following a node
*******************************************************************************/
#include "linked_list.h"

/*******************************************************************************
    ll_remove_after
*//**
    @brief  Removes the node following the given node
    @param  elem    List node having the node after it removed

    @return The provided node
*******************************************************************************/
ll_node
ll_remove_after(ll_node elem)
{
    ll_node del = NULL_NODE;

    /* No nodes exist after the given node */
    if (NULL_NODE != elem->next)
    {
        del = elem->next;
        elem->next = elem->next->next;
        del->next = NULL_NODE;
        ll_destroy_node(del);
        del = NULL_NODE;
    }

    return elem;
}
