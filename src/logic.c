#include <stdio.h>
#include "types.h"
#include "decipherFile.h"
#include "findHeight.h"
#include "findSize.h"
#include "findMin.h"
#include "findMax.h"

void run()
{
    Tree *tree = getDataFromFile();

    printf("Height of tree is %d\n", findHeightOfTree(tree));
    printf("Size of tree is %d\n", findSizeOfTree(tree));
    
    printf("\n");
    displayMinimumNodeOfTree(findMinimumNodeOfTree(tree));
    printf("\n");
    displayMaximumNodeOfTree(findMaximumNodeOfTree(tree));
    


    freeGraphData(tree);
}