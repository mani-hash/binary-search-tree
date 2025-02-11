#include <stdio.h>
#include "types.h"
#include "findMax.h"

/*
 * Static declarations for functions
 */
static Node* findMaxNode(Node* node);

/*
 * Calculate maximum node of a binary search tree
 *
 * @param struct Node (pointer*)
 * @return struct Node (pointer*)
 */
static Node* findMaxNode(Node* node)
{
    if (node->right == NULL)
    {
        return node;
    }

    return findMaxNode(node->right);
}

/*
 * Expose findMaxNode functions
 *
 * @param struct Tree (pointer*)
 * @return struct Node (pointer*)
 */
Node* FindMax(Tree *tree)
{
    if (tree->root == NULL)
    {
        return NULL;
    }

    return findMaxNode(tree->root);
}

/*
 * Display maximum node of a binary search tree
 *
 * @param struct Node (pointer*)
 * @return void
 */
void displayMaximumNodeOfTree(Node* maxNode)
{
    printf("Maximum node of tree => \n");

    if (maxNode == NULL)
    {
        printf("\tThis tree is empty therefore there is no maximum node for this tree\n");
    }
    else
    {
        printf("\t- Node name: %c\n", maxNode->nodeName);
        printf("\t- Node data: %s\n", maxNode->data);
    }
}
