#include <stdio.h>
#include "types.h"
#include "findSize.h"

/*
 * Static declarations for functions
 */
static int calculateTotalSize(Node *node);

/*
 * Calculate total size of a binary search tree
 *
 * @param struct Node (pointer*)
 * @return int
 */
static int calculateTotalSize(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }

    return calculateTotalSize(node->left) + calculateTotalSize(node->right) + 1;
}

/*
 * Expose calculate total size functions
 *
 * @param struct Tree (pointer*)
 * @return int
 */
int FindSize(Tree *tree)
{
    return calculateTotalSize(tree->root);
}