#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "graph.h"

/*
 * Static function declarations
 */
static Node* createNode(Node* parent, char* data);

/*
 * Initiates a tree data structure
 *
 * @return struct Tree (pointer*)
 */
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

/*
 * Creates a node for binary tree data structure
 *
 * @param Node (pointer*)
 * @param string (data)
 * @return struct Node (pointer*)
 */
static Node* createNode(Node* parent, char* data)
{
    // static variable to track function names
    static char nodeName = 'a';

    Node* node = malloc(sizeof(Node));

    if (node == NULL)
    {
        perror("There was an error allocating memory\n");
        exit(EXIT_FAILURE);
    }

    node->nodeName = nodeName;
    node->data = strdup(data); // duplicate the string
    node->parent = parent;
    node->left = NULL;
    node->right = NULL;

    nodeName += 1;

    return node;
}

/*
 * Inserts node into binary tree data structure
 *
 * @param struct Tree (pointer*)
 * @param data (string)
 * @return void
 */
void insertNode(Tree *tree, char* data)
{
    // Case when tree is empty
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

        if (comparison < 0) // Data is smaller than node's data
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
        else if (comparison > 0) // Data is greater than node's data
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