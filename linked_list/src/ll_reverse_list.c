/***************************************************************************//**
    @file   ll_reverse_list.c

    @brief  Reverses a linked list
*******************************************************************************/
#include "linked_list.h"

/*******************************************************************************
    ll_reverse_list
*//**
    @brief  Reverses a linked list
    @param  head    The head node of the list

    @return The new head of the list
*******************************************************************************/
ll_node
ll_reverse_list(ll_node head)
{
    ll_node tmp = NULL_NODE;
    ll_node prev = NULL_NODE;

    while (NULL != head)
    {
        tmp = head->next;
        head->next = prev;
        prev = head;
        head = tmp;
    }

    return prev;
}

