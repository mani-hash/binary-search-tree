#include <stdio.h>
#include "types.h"
#include "decipherFile.h"
#include "findHeight.h"

void run()
{
    Tree *tree = getDataFromFile();

    printf("Height of tree is %d\n", findHeightOfTree(tree));

    freeGraphData(tree);
}