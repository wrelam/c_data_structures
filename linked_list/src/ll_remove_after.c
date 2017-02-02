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
    /* No nodes exist after the given node */
    if (NULL == elem->next)
    {
        return elem;
    }

    ll_node del = elem->next;
    elem->next = elem->next->next;
    del->next = NULL;
    ll_destroy_node(del);

    return elem;
}
