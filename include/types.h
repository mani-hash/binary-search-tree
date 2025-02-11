#ifndef TYPES_H
#define TYPES_H

/*
 * Struct to store each node of
 * binary search tree
 *
 */
typedef struct Node
{
    struct Node* parent;
    char nodeName;
    char* data;
    struct Node* left;
    struct Node* right;
} Node;

/*
 * Struct for the overall tree
 *
 */
typedef struct Tree
{
    Node* root;
} Tree;

#endif // TYPES_H