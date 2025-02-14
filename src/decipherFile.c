#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include "types.h"
#include "graph.h"
#include "decipherFile.h"

/*
 * Static declarations for functions
 */

static void freeGraphNode(Node *node);

FILE *file;
const char inputFile[] = "data/input.txt";
char *line = NULL; // line buffer
size_t lineLength = 0; // monitor length of line
ssize_t read; // number of lines read

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

    while ((read = getline(&line, &lineLength, file)) != -1)
    {
        // skip newlines
        if (*line == '\n')
        {
            continue;
        }

        // remove newline characters
        if (line[read - 1] == '\n')
        {
            line[read - 1] = '\0';
        }

        insertNode(tree, line);
    }

    free(line);

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