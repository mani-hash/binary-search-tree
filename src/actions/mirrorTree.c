#include <stdio.h>
#include <math.h>
#include "mirrorTree.h"
#include "types.h"

/*
 * Static declarations for functions
 */
static void swapNodes(Node* node);
static void printNodes(Node* node, int level);

/*
 * Swap nodes in a binary search tree
 *
 * This function contains the logic to
 * create mirror image of a binary search tree
 * 
 * @param struct Node (pointer*)
 * @return void
 */
static void swapNodes(Node* node)
{
    if (node == NULL)
    {
        return;
    }

    Node *temp = node->left;
    node->left = node->right;
    node->right = temp;

    swapNodes(node->left);
    swapNodes(node->right);
}

/*
 * Expose mirror logic
 *
 * @param struct Tree (pointer*)
 * @return void
 */
void MirrorImage(Tree* tree)
{
    if (tree->root == NULL)
    {
        return;
    }

    swapNodes(tree->root);
}

/*
 * Print the binary search tree
 *
 * @param struct Node (pointer*)
 * @param level (int)
 * @return void
 */
static void printNodes(Node* node, int level)
{
    if (node == NULL)
    {
        return;
    }

    for (int spaceIndex = 0; spaceIndex < (4 * level); spaceIndex++)
    {
        printf(" ");
    }

    // Prefix for the node
    if (node->parent == NULL)
    {
        printf("Root:");
    }
    else if (node->parent->left == node)
    {
        printf("- Left:");
    }
    else if (node->parent->right == node)
    {
        printf("- Right:");
    }

    printf(" %c => %s\n", node->nodeName, node->data);

    printNodes(node->left, level + 1);
    printNodes(node->right, level + 1);


}

/*
 * Expose display functions
 *
 * @param struct Tree (pointer*)
 * @return void
 */
void displayTree(Tree *tree)
{
    printNodes(tree->root, 0);
}