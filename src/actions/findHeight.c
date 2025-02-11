#include <stdio.h>
#include "types.h"

/*
 * Static declarations for functions
 */
static int getMaxHeight(int height1, int height2);
static int calculateMaxHeight(Node *node);

/*
 * Calculate larger height
 * between left and right subtree
 *
 * @param int
 * @param int
 * @return int
 */
static int getMaxHeight(int height1, int height2)
{
    if (height1 > height2)
    {
        return height1;
    }

    return height2;
}

/*
 * Calculate maximum height in a tree
 *
 * @param struct Node (pointer*)
 * @return int
 */
static int calculateMaxHeight(Node *node)
{
    if (node == NULL)
    {
        return -1;
    }
    int leftHeight = calculateMaxHeight(node->left);
    int rightHeight = calculateMaxHeight(node->right);

    return getMaxHeight(leftHeight, rightHeight) + 1;
}

/*
 * Expose find height methods
 *
 * @param struct Tree (pointer*)
 * @return int
 */
int FindHeight(Tree *tree)
{
    return calculateMaxHeight(tree->root);
}