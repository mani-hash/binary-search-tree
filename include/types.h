#ifndef TYPES_H
#define TYPES_H

typedef struct Node
{
    struct Node* parent;
    char nodeName;
    char* data;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct Tree
{
    Node* root;
} Tree;

#endif // TYPES_H