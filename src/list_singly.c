/***************************************************************************//**
    @file   list_singly.c

    @brief  Implementation of a singly linked list
*******************************************************************************/
#include <stdlib.h>

#include "list_singly.h"

/*******************************************************************************
    ll_create_node
*//**
    @brief  Allocates and returns an initialized node

    @return A new linked list node
    @retval NULL_NODE   Failed to allocate new node
*******************************************************************************/
sll_node
ll_create_node(void)
{
    sll_node new = calloc(1, sizeof(struct sll_node));

    if (NULL != new)
    {
        new->next = NULL_NODE;
        new->data = NULL;
    }

    return new;
}


/*******************************************************************************
    ll_destroy_node
*//**
    @brief  Destroys a given node
    @param  elem    List node being destroyed
*******************************************************************************/
void
ll_destroy_node(sll_node elem)
{
    free(elem);
}


/*******************************************************************************
    ll_insert_after
*//**
    @brief  Inserts one node after another
    @param  elem    List node having a node inserted after it
    @param  new     List node being inserted

    @return The frontmost node of the pair
*******************************************************************************/
sll_node
ll_insert_after(sll_node elem, sll_node new)
{
    new->next = elem->next;
    elem->next = new;
    return elem;
}


/*******************************************************************************
    ll_insert_at_end
*//**
    @brief  Inserts a node at the end of the list containing the given node
    @param  elem    Existing list node defining the list to append to
    @oaram  new     List node being inserted

    @return The node defined by elem
*******************************************************************************/
sll_node
ll_insert_at_end(sll_node elem, sll_node new)
{
    sll_node iter = elem;

    while (NULL_NODE != iter->next)
    {
        iter = iter->next;
    }

    iter->next = new;

    return elem;
}


/*******************************************************************************
    ll_insert_before
*//**
    @brief  Inserts one node before another
    @param  elem    List node having a node inserted before it
    @param  new     List node being inserted

    @return The frontmost node of the pair
*******************************************************************************/
sll_node
ll_insert_before(sll_node elem, sll_node new)
{
    new->next = elem;
    return new;
}


/*******************************************************************************
    ll_remove_after
*//**
    @brief  Removes the node following the given node
    @param  elem    List node having the node after it removed

    @return The provided node
*******************************************************************************/
sll_node
ll_remove_after(sll_node elem)
{
    sll_node del = NULL_NODE;

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


/*******************************************************************************
    ll_reverse_list
*//**
    @brief  Reverses a linked list
    @param  head    The head node of the list

    @return The new head of the list
*******************************************************************************/
sll_node
ll_reverse_list(sll_node head)
{
    sll_node tmp = NULL_NODE;
    sll_node prev = NULL_NODE;

    while (NULL_NODE != head)
    {
        tmp = head->next;
        head->next = prev;
        prev = head;
        head = tmp;
    }

    return prev;
}

