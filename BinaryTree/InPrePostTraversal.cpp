#include <iostream>
#include "TreeNodeBasic.h"
#include "ArrayRepresentationOfBinaryTree.h"

void inorder_traversal_recursive (TreeNode* currentNode) {

    if (currentNode == nullptr) {
        return;
    }

    inorder_traversal_recursive(currentNode -> left); 
    std::cout<< currentNode -> val<<" "; 
    inorder_traversal_recursive(currentNode -> right);

}

void preorder_traversal_recursive (TreeNode* currentNode) {

    if (currentNode == nullptr) {
        return;
    }

    std::cout<< currentNode -> val<<" ";
    preorder_traversal_recursive(currentNode -> left); 
    preorder_traversal_recursive(currentNode -> right);

}

void postorder_traversal_recursive (TreeNode* currentNode) {

    if (currentNode == nullptr) {
        return;
    }

    postorder_traversal_recursive(currentNode -> left);  
    postorder_traversal_recursive(currentNode -> right);
    std::cout<< currentNode -> val<<" ";

}

int main() {

    // int arr [] = {20, 8, 22, 5, 3, 4, 25, nullptr, nullptr, 10 ,14};
    // treating -1 as nullptr
    int arr [] = {20, 8, 22, 5, 3, 4, 25, -1, -1, 10 ,14};

    int arrSize = (sizeof(arr)/sizeof(*arr));

    TreeNode* root = getRootForFilledTree(arr, arrSize);

    /*
    To run 
    g++ ArrayRepresentationOfBinaryTree.cpp InPrePostTraversal.cpp
    ./a.out
    */
    std::cout<<" \n START inorder \n";
    inorder_traversal_recursive(root);
    std::cout<<" \n END inorder \n";

    std::cout<<" \n START preorder \n";
    preorder_traversal_recursive(root);
    std::cout<<" \n END preorder \n";

    std::cout<<" \n START postorder \n";
    postorder_traversal_recursive(root);
    std::cout<<" \n END postorder \n";

    return 0;

}
