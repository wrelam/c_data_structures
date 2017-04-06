/***************************************************************************//**
    @file   tree_mary.h

    @brief  Interface to an M-ary tree implementation
*******************************************************************************/
#ifndef TREE_MARY_H
#define TREE_MARY_H

#include "list_doubly.h"

typedef struct MTreeNode
{
    dll_node link;
    struct MTreeNode *parent;
    dll_list children;
} MTreeNode;

typedef struct MTree
{
    MTreeNode *root;
} MTree;

void
mt_add_child(MTreeNode *node, MTreeNode *child);

void
mt_add_child_front(MTreeNode *node, MTreeNode *child);

void
mt_add_sibling(MTreeNode *node, MTreeNode *sibling);

void
mt_rem_child(MTreeNode *child);

#endif /* TREE_MARY_H */

