// CHECK if guards needed #ifdef etc
/* 

gemini  - Add include guards to the top of the file. 
This prevents errors if the header is 
included more than once in the same "compilation unit".

*/

#ifndef ARRAY_REPRESENTATION_OF_BINARY_TREE_H

#define ARRAY_REPRESENTATION_OF_BINARY_TREE_H
#include "TreeNodeBasic.h"

TreeNode* getRootForFilledTree(int* arr, int arrSize);

#endif