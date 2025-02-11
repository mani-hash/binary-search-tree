#include <stdio.h>
#include "types.h"

static int getMaxHeight(int height1, int height2);
static int calculateMaxHeight(Node *node);

static int getMaxHeight(int height1, int height2)
{
    if (height1 > height2)
    {
        return height1;
    }

    return height2;
}

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

int FindHeight(Tree *tree)
{
    return calculateMaxHeight(tree->root);
}