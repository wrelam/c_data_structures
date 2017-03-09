/***************************************************************************//**
    @file   tree_mary.c

    @brief  Implementation of an M-ary tree
*******************************************************************************/

#include "list_doubly.h"
#include "tree_mary.h"

void
mt_add_child(MTreeNode *node, MTreeNode *child)
{
    if ((NULL != node) &&
        (NULL != child))
    {
        dll_insert_back(&(node->children), &(child->parLink));
    }
}

void
mt_add_sibling(MTreeNode *node, MTreeNode *sibling)
{
    if ((NULL != node) &&
        (NULL != sibling))
    {
        dll_insert_after(node->sibLink, sibling->sibLink);
    }
}

