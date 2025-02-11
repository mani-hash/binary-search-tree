#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "graph.h"

static Node* createNode(Node* parent, char* data);

Tree* initiateTree()
{
    Tree* tree = malloc(sizeof(Tree));

    if (tree ==  NULL)
    {
        perror("There was an error allocating memory\n");
        exit(EXIT_FAILURE);
    }

    tree->root = NULL;

    return tree;
}

static Node* createNode(Node* parent, char* data)
{
    static char nodeName = 'a';

    Node* node = malloc(sizeof(Node));

    if (node == NULL)
    {
        perror("There was an error allocating memory\n");
        exit(EXIT_FAILURE);
    }

    node->nodeName = nodeName;
    node->data = data;
    node->parent = parent;
    node->left = NULL;
    node->right = NULL;

    nodeName += 1;

    return node;
}

void insertNode(Tree *tree, char* data)
{
    
    if (tree->root == NULL)
    {
        Node *node = createNode(NULL, data);
        tree->root = node;

        return;
    }

    Node *currentNode = tree->root;

    while (currentNode != NULL)
    {
        int comparison =  strcmp(data, currentNode->data);

        if (comparison < 0)
        {
            if (currentNode->left == NULL)
            {
                Node *node = createNode(currentNode, data);
                currentNode->left = node;
                break;
            }
            else
            {
                currentNode = currentNode->left;
            }
        }
        else if (comparison > 0)
        {
            if (currentNode->right == NULL)
            {
                Node *node = createNode(currentNode, data);
                currentNode->right = node;
                break;
            }
            else
            {
                currentNode = currentNode->right;
            }
        }
    }
}