#include <stdio.h>
#include <math.h>
#include "mirrorTree.h"
#include "types.h"

static void swapNodes(Node* node);
static void printNodes(Node* node, int level);

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

void MirrorImage(Tree* tree)
{
    if (tree->root == NULL)
    {
        return;
    }

    swapNodes(tree->root);
}

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

void displayTree(Tree *tree)
{
    printNodes(tree->root, 0);
}