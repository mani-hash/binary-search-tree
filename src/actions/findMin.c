#include <stdio.h>
#include "types.h"
#include "findMin.h"

static Node* findMinNode(Node* node);

static Node* findMinNode(Node* node)
{
    if (node->left == NULL)
    {
        return node;
    }

    return findMinNode(node->left);
}

Node* findMinimumNodeOfTree(Tree* tree)
{
    if (tree->root == NULL)
    {
        return NULL;
    }

    return findMinNode(tree->root);
    
}

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