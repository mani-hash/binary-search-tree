#include <stdio.h>
#include "types.h"
#include "decipherFile.h"
#include "findHeight.h"
#include "findSize.h"
#include "findMin.h"
#include "findMax.h"
#include "mirrorTree.h"

/*
 * Main run logic
 *
 * Contains all the run logic to be
 * executed in the lifecycle of the
 * program
 * 
 * @return void
 */
void run()
{
    Tree *tree = getDataFromFile();

    printf("Height of tree is %d\n", FindHeight(tree));
    printf("Size of tree is %d\n", FindSize(tree));
    
    printf("\n");
    displayMinimumNodeOfTree(FindMin(tree));
    printf("\n");
    displayMaximumNodeOfTree(FindMax(tree));
    printf("\n");

    MirrorImage(tree);

    printf("Mirrored Image of tree: \n\n");
    displayTree(tree);

    freeGraphData(tree);
}