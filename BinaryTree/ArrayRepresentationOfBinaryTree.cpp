// TODO() -> Learn about header files and organize, something like below 
#include "TreeNodeBasic.h"

int main() {

    // it will go something like this
    // we are given an array...
    // which represents binary tree...
    // (maybe later add check for validity...or..)

    // from array representation we'll 
    // convert it to what they call 
    // dynamic node representation (the one with struct/class called Node
    // with left and right child, I guess the most used in problems etc...)

    // from that Node representation, we'll try to convert it back to 
    // array...a cute full circle...

    // int arr [] = {20, 8, 22, 5, 3, 4, 25, nullptr, nullptr, 10 ,14};
    // treating -1 and nullptr
    int arr [] = {20, 8, 22, 5, 3, 4, 25, -1, -1, 10 ,14};


    TreeNode* root = getRootForFilledTree(arr);



    return 0;
}

TreeNode* getRootForFilledTree(int* arr) {
    
    // I guess this needs a digression...let's see later..
    // such as when denominator gets null or 0 or other validity checks for
    // the input arr
    int arrSize = (sizeof(arr)/sizeof(*arr));
    

}
