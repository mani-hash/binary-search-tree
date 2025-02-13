#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "graph.h"
#include "decipherFile.h"

/*
 * Static declarations for functions
 */
static char* getWordFromBuffer();
static void freeGraphNode(Node *node);

FILE *file;
const char inputFile[] = "data/input.txt";
char wordBuffer[50]; // temporary buffer array to store words
int bufferIndex = 0; // buffer index to get count of letters read for one valid word
char characterBuffer; // buffer to store each character read from file

/*
 * Convert the characters in the buffer to a string
 *
 * @return word (string)
 */
static char* getWordFromBuffer()
{
    char* word = malloc((bufferIndex + 1) * sizeof(char));

    if (word == NULL)
    {
        perror("There was an error allocating memory\n");
        exit(EXIT_FAILURE);
    }

    int wordIndex = 0;
    for (wordIndex = 0; wordIndex < bufferIndex; wordIndex++)
    {
        word[wordIndex] = wordBuffer[wordIndex];
    }

    word[wordIndex] = '\0';

    return word;
}

/*
 * Fetch data from file and build tree data structure
 *
 * @return struct Tree (pointer*)
 */
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
        // skip spaces
        if (characterBuffer == ' ')
        {
            continue;
        }

        if (characterBuffer == ',' || characterBuffer == '.' || characterBuffer == '\n')
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

    fclose(file);

    return tree;
}

/*
 * Free dynamically allocated nodes
 *
 * @param struct Node (pointer*)
 * @return void
 */
static void freeGraphNode(Node *node)
{
    if (node == NULL)
    {
        return;
    }

    freeGraphNode(node->left);
    freeGraphNode(node->right);

    free(node->data);
    free(node);
}

/*
 * Free all dynamically allocated structures
 *
 * Parent function that encapsulates
 * all the logic execution to free all dynamic structures
 * in the graph
 * 
 * @param struct Tree (pointer*)
 * @return void
 */
void freeGraphData(Tree* tree)
{
    Node *currentNode = tree->root;

    freeGraphNode(currentNode);

    free(tree);
}