#include <stdio.h>
#include "types.h"
#include "findSize.h"

static int calculateTotalSize(Node *node);

static int calculateTotalSize(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }

    return calculateTotalSize(node->left) + calculateTotalSize(node->right) + 1;
}

int FindSize(Tree *tree)
{
    return calculateTotalSize(tree->root);
}