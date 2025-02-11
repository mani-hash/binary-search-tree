#include <stdio.h>
#include "types.h"
#include "findMin.h"

/*
 * Static declarations for functions
 */
static Node* findMinNode(Node* node);

/*
 * Calculate minimum node of a binary search tree
 *
 * @param struct Node (pointer*)
 * @return struct Node (pointer*)
 */
static Node* findMinNode(Node* node)
{
    if (node->left == NULL)
    {
        return node;
    }

    return findMinNode(node->left);
}

/*
 * Expose findMinNode functions
 *
 * @param struct Node (pointer*)
 * @return struct Node (pointer*)
 */
Node* FindMin(Tree* tree)
{
    if (tree->root == NULL)
    {
        return NULL;
    }

    return findMinNode(tree->root);
    
}

/*
 * Calculate minimum node of a binary search tree
 *
 * @param struct Node (pointer*)
 * @return void
 */
void displayMinimumNodeOfTree(Node* minNode)
{
    printf("Minimum node of tree => \n");

    if (minNode == NULL)
    {
        printf("\tThis tree is empty therefore there is no minimum node for this tree\n");
    }
    else
    {
        printf("\t- Node name: %c\n", minNode->nodeName);
        printf("\t- Node data: %s\n", minNode->data);
    }
}