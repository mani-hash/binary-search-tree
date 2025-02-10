#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "graph.h"
#include "decipherFile.h"

static char* getWordFromBuffer();
static void freeGraphNode(Node *node);

FILE *file;
const char inputFile[] = "data/input.txt";
char wordBuffer[50];
int bufferIndex = 0; 
char characterBuffer;

static char* getWordFromBuffer()
{
    char* word = malloc((bufferIndex + 1) * sizeof(char));
    int wordIndex = 0;
    for (wordIndex = 0; wordIndex < bufferIndex; wordIndex++)
    {
        word[wordIndex] = wordBuffer[wordIndex];
    }

    word[wordIndex] = '\0';

    return word;
}

Tree* getDataFromFile()
{
    Tree* tree = initiateTree();

    file = fopen(inputFile, "r");
    if (file == NULL)
    {
        perror("Failed to open file \"input.txt\" in \"data/\" directory\n");
        exit(EXIT_FAILURE);
    }

    while ((characterBuffer = fgetc(file)) != EOF)
    {
        if (characterBuffer == ' ' || characterBuffer == '\n')
        {
            continue;
        }

        if (characterBuffer == ',' || characterBuffer == '.')
        {
            char* word = getWordFromBuffer();
            insertNode(tree, word);
            
            bufferIndex = 0;
        }
        else
        {
            wordBuffer[bufferIndex] = characterBuffer;
            bufferIndex++;
        }
    }

    return tree;
}

static void freeGraphNode(Node *node)
{
    if (node == NULL)
    {
        return;
    }

    if (node->left != NULL)
    {
        freeGraphNode(node->left);
    }
    else if (node->right != NULL)
    {
        freeGraphNode(node->right);
    }

    free(node->data);
    free(node);
}

void freeGraphData(Tree* tree)
{
    Node *currentNode = tree->root;

    freeGraphNode(currentNode);

    free(tree);
}