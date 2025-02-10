#include <stdio.h>
#include "types.h"
#include "findMax.h"

static Node* findMaxNode(Node* node);

static Node* findMaxNode(Node* node)
{
    if (node->right == NULL)
    {
        return node;
    }

    return findMaxNode(node->right);
}

Node* findMaximumNodeOfTree(Tree *tree)
{
    if (tree->root == NULL)
    {
        return NULL;
    }

    return findMaxNode(tree->root);
}

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
